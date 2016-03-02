     H AlwNull(*UsrCtl)
     H BNDDIR('QC2LE')

      /copy ios_h
      /copy iconv_h
      /copy ipase_h

       // *************************************************
       // templates
       // *************************************************
       dcl-ds PaseAlloc_t qualified template; 
         ilePtr POINTER; 
         pasePtr UNS(20);
         sz INT(10);
       end-ds;
       dcl-ds JsonAlloc_t qualified template;
         injson UNS(10); 
         inlen INT(10); 
         outjson UNS(10);
         outlen INT(10); 
         sig1 INT(5);
         sig2 INT(5);
         sig3 INT(5);
         sig4 INT(5);
         ret INT(10);
       end-ds;

       // *************************************************
       // global
       // *************************************************
       DCL-C DB2_ARG0_PGM CONST('/usr/lib/start32');
       DCL-C DB2_ENV1_PATH CONST('PATH=/usr/bin');
       DCL-C DB2_ENV2_LIBPATH CONST('LIBPATH=/usr/lib');
       DCL-C DB2_ENV3_ATTACH CONST('PASE_THREAD_ATTACH=Y');
       DCL-C DB2_PATH_LIBDB400 CONST('/QOpenSys/QIBM/ProdData/+
       OPS/PaseCliAsync/');
       DCL-C DB2_FILE_LIBDB400 CONST('libdb400.a(shr.o)');
       DCL-C DB2_SYM_SQL400JSON CONST('SQL400Json');
       dcl-c NULLTERM const(x'00');
       dcl-c CRLF const(x'15');
       dcl-c LF const(x'25');
       DCL-C DB2_MAX_JSON_OUT CONST(512000);

       dcl-s sLibDB400 UNS(20);
       dcl-s SQL400Json POINTER inz(*NULL);

       dcl-s webPaseAllocFlag int(10);
       dcl-s jsonPaseAllocFlag int(10);
       dcl-ds webPaseAlloc likeds(PaseAlloc_t);
       dcl-ds jsonPaseAlloc likeds(PaseAlloc_t);
       dcl-ds jsonPaseCall likeds(JsonAlloc_t);

       dcl-pr error37;
         reason char(4096) value;
       end-pr;

       dcl-pr header1208;
       end-pr;

       dcl-pr error1208;
         reason char(4096) value;
       end-pr;

       dcl-pr allocPaseBlock POINTER;
         sz int(10) value;
       end-pr;

       dcl-pr libdb400Pase32;
       end-pr;

       dcl-pr ap_unescape_url INT(10) EXTPROC('ap_unescape_url');
         url POINTER VALUE options(*string);
       end-pr;

       // *************************************************
       // main
       // *************************************************
       dcl-s isBinary char(20) inz('BINARY');
       dcl-s pos int(10) inz(0);
       dcl-s rCopy POINTER inz(*NULL);
       dcl-s cMode char(20) inz('BINARY');
       dcl-s cMethod char(20) inz(*BLANKS);
       dcl-s cContent char(20) inz(*BLANKS);
       dcl-s pContent POINTER inz(*NULL);
       dcl-s szContent int(10) inz(0);
       dcl-s rTot int(10) inz(0);
       dcl-s rSz int(10) inz(0);
       dcl-s rc int(10) inz(0);
       dcl-s newIlePtr POINTER inz(*NULL);
       dcl-s newPasePtr UNS(20) inz(0);
       DCL-S outPtr POINTER INZ(*NULL);
       DCL-S outLen INT(10) INZ(0);
       DCL-S outSqlRc INT(10) inz(0);

       // must CGIConvMode BINARY
       rCopy = getenv('CGI_MODE');
       if rCopy <> *NULL;
         cMode = %str(rCopy:strlen(rCopy));
         pos = %scan(%trim(isBinary):cMode);
         if pos = 0;
           rCopy = *NULL;
         endif;
       endif;
       if rCopy = *NULL;
         error37('Require CGIConvMode BINARY');
         return;
       endif;

       // set-up pase (if needed)
       libdb400Pase32();

       // web request (json input)
       rCopy = getenv('REQUEST_METHOD');
       if rCopy <> *NULL;
         cMethod = %str(rCopy:strlen(rCopy));
       endif;
       if cMethod='POST';
         rCopy = getenv('CONTENT_LENGTH');
         cContent = %str(rCopy:strlen(rCopy));
         szContent= %int(cContent);
         pContent = allocPaseBlock(szContent);
         if szContent > 0;
           // -----
           // read from stdin (Apache)
           rTot = 0;
           rSz = 1;
           dou rTot >= szContent or rSz <= 0;
             rSz = readIFS(0:pContent+rTot:szContent-rTot);
             rTot += rSz;
           enddo;
         endif;
       elseif cMethod='GET';
         rCopy = getenv('QUERY_STRING');
         szContent= strlen(rCopy);
         pContent = allocPaseBlock(szContent);
         if szContent > 0;
           cpybytes(pContent:rCopy:szContent);
         endif;
       endif;
       if szContent > 0;
         rc = ap_unescape_url(pContent);
       endif;

       // SQLRETURN SQL400Json(
       //  SQLCHAR * injson,
       //  SQLINTEGER inlen,
       //  SQLCHAR * outjson,
       //  SQLINTEGER outlen
       // )
       if jsonPaseAllocFlag = 0;
         newIlePtr = Qp2malloc(DB2_MAX_JSON_OUT:%addr(newPasePtr));
         jsonPaseAlloc.ilePtr = newIlePtr;
         jsonPaseAlloc.pasePtr = newPasePtr;
         jsonPaseAlloc.sz = DB2_MAX_JSON_OUT;
         jsonPaseAllocFlag = 1;
       endif;
       jsonPaseCall.injson = webPaseAlloc.pasePtr;
       jsonPaseCall.inlen = webPaseAlloc.sz;
       jsonPaseCall.outjson = jsonPaseAlloc.pasePtr;
       jsonPaseCall.outlen = jsonPaseAlloc.sz;
       jsonPaseCall.sig1 = QP2_ARG_PTR32;
       jsonPaseCall.sig2 = QP2_ARG_WORD;
       jsonPaseCall.sig3 = QP2_ARG_PTR32;
       jsonPaseCall.sig4 = QP2_ARG_WORD;
       jsonPaseCall.ret = QP2_RESULT_WORD;
       if SQL400Json <> *NULL;
         rc = Qp2CallPase(SQL400Json:
                          %addr(jsonPaseCall.injson):
                          %ADDR(jsonPaseCall.sig1):
                          jsonPaseCall.ret:
                          %addr(outSqlRc));
         if rc = QP2CALLPASE_NORMAL;
           header1208();
           outPtr = jsonPaseAlloc.ilePtr;
           outLen = strlen(outPtr);
           rc = writeIFS(1:outPtr:outLen);
         elseif rc = QP2CALLPASE_TERMINATING;
           error1208('SQL400Json call error, PASE terminating');
           sLibDB400 = 0;
           jsonPaseAllocFlag = 0;
           webPaseAllocFlag = 0;
         else;
           error1208('SQL400Json call error');
         endif;
       else;
         error1208('SQL400Json was not found in libdb400.a');
       endif;
       return;

       // *************************************************
       // output error
       // return (na)
       // *************************************************
       dcl-proc error37;
         dcl-pi *N;
          reason char(4096) value;
         end-pi;
         dcl-s talk char(4096) inz(*BLANKS);
         dcl-s rc int(20) inz(0);
         DCL-S outPtr POINTER INZ(*NULL);
         DCL-S outLen INT(10) INZ(0);

         talk = *BLANKS;
         talk =
           'Content-type: text/plain' + CRLF
         + CRLF
         + NULLTERM;
         outPtr = %addr(talk);
         outLen = strlen(outPtr);
         rc = writeIFS(1:outPtr:outLen);

         talk = *BLANKS;
         talk =
           '{"ok":false,"reason":"'+%trim(reason)+'"}'
         + CRLF
         + NULLTERM;
         outPtr = %addr(talk);
         outLen = strlen(outPtr);
         rc = writeIFS(1:outPtr:outLen);

       end-proc; 


       // *************************************************
       // output error
       // return (na)
       // *************************************************
       dcl-proc header1208;
         dcl-pi *N;
         end-pi;
         dcl-s talk char(4096) inz(*BLANKS);
         dcl-s rc int(20) inz(0);
         DCL-S outPtr POINTER INZ(*NULL);
         DCL-S outLen INT(10) INZ(0);
         dcl-s talk1208 char(4096) inz(*BLANKS);
         DCL-S buffPtr POINTER INZ(*NULL);
         DCL-S buffLen INT(10) INZ(0);
         DCL-S fromCCSID INT(10) INZ(37);
         DCL-S toCCSID INT(10) INZ(1208);

         talk = *BLANKS;
         talk =
           'Content-type: application/json; charset=utf-8' + LF
         + LF
         + NULLTERM;
         buffPtr = %addr(talk);
         buffLen = strlen(buffPtr);
         outPtr = %addr(talk1208);
         outLen = %size(talk1208);
         memset(outPtr:0:outLen);
         rc = convCCSID(fromCCSID:toCCSID:buffPtr:buffLen:outPtr:outLen);
         outLen = strlen(outPtr);
         rc = writeIFS(1:outPtr:outLen);

       end-proc; 


       // *************************************************
       // output error
       // return (na)
       // *************************************************
       dcl-proc error1208;
         dcl-pi *N;
          reason char(4096) value;
         end-pi;
         dcl-s talk char(4096) inz(*BLANKS);
         dcl-s rc int(20) inz(0);
         DCL-S outPtr POINTER INZ(*NULL);
         DCL-S outLen INT(10) INZ(0);
         dcl-s talk1208 char(4096) inz(*BLANKS);
         DCL-S buffPtr POINTER INZ(*NULL);
         DCL-S buffLen INT(10) INZ(0);
         DCL-S fromCCSID INT(10) INZ(37);
         DCL-S toCCSID INT(10) INZ(1208);

         header1208();

         talk = *BLANKS;
         talk =
           '{"ok":false,"reason":"'+%trim(reason)+'"}'
         + LF
         + NULLTERM;
         buffPtr = %addr(talk);
         buffLen = strlen(buffPtr);
         outPtr = %addr(talk1208);
         outLen = %size(talk1208);
         memset(outPtr:0:outLen);
         rc = convCCSID(fromCCSID:toCCSID:buffPtr:buffLen:outPtr:outLen);
         outLen = strlen(outPtr);
         rc = writeIFS(1:outPtr:outLen);

       end-proc; 


       // *************************************************
       // alloc pase block
       // return (ilePTR to PASE memory)
       // *************************************************
       dcl-proc allocPaseBlock;
         dcl-pi *N POINTER;
           sz int(10) value;
         end-pi;
         dcl-s newIlePtr POINTER inz(*NULL);
         dcl-s newPasePtr UNS(20) inz(0);

         newIlePtr = webPaseAlloc.ilePtr;
         if webPaseAllocFlag = 0
         or (sz > 0 and webPaseAlloc.sz < sz);
           if webPaseAllocFlag > 0;
             dealloc(en) newIlePtr;
             newIlePtr = *NULL;
           endif;
           newIlePtr = Qp2malloc(sz:%addr(newPasePtr));
           webPaseAlloc.ilePtr = newIlePtr;
           webPaseAlloc.pasePtr = newPasePtr;
           webPaseAlloc.sz = sz;
           webPaseAllocFlag = 1;
         endif;
         if webPaseAlloc.sz > 0;
           memset(newIlePtr:0:webPaseAlloc.sz);
         endif;

         return newIlePtr;
       end-proc;


       // *************************************************
       // PHP API -- start 32bit
       // *************************************************
       dcl-proc libdb400Pase32;
         dcl-pi *N;
         end-pi;
         DCL-S rcb IND INZ(*OFF);
         dcl-s pgm CHAR(65500) inz(*BLANKS);
         dcl-s arg CHAR(65500) dim(8) inz(*BLANKS);
         dcl-s env CHAR(65500) dim(8) inz(*BLANKS);
         dcl-s myPaseCCSID INT(10) inz(819);
         dcl-s apilib CHAR(1024) inz(*BLANKS);
         dcl-s apiname CHAR(1024) inz(*BLANKS);

         pgm = DB2_ARG0_PGM;

         env(1) = DB2_ENV1_PATH;
         env(2) = DB2_ENV2_LIBPATH;
         env(3) = DB2_ENV3_ATTACH;

         rcb = PaseStart32(pgm:arg:env:myPaseCCSID);
         if rcb = *ON;
           if sLibDB400 = 0;
             apilib = 
               DB2_PATH_LIBDB400 
             + DB2_FILE_LIBDB400 
             + NULLTERM;
             sLibDB400 = Qp2dlopen(%addr(apilib)
                         :X'00040002':0);
             if sLibDB400 > 0;
               apiname = 
                 DB2_SYM_SQL400JSON
               + NULLTERM;
               SQL400Json = Qp2dlsym(sLibDB400
                            :%ADDR(apiname):0:*NULL);
             endif;
           endif;
         endif;

       end-proc; 



