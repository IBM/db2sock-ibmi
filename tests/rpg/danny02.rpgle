     H AlwNull(*UsrCtl)

       dcl-ds inputDS qualified;
         in1 varchar(5:2);
         in2 varchar(5:2);
       end-ds;

       dcl-pr Main extpgm;
         inCount int(10);
         input likeds(inputDS) dim(20);
         outCount int(10);
         outputA int(10) dim(20);
         last char(20);
       end-pr;

       dcl-pi Main;
         inCount int(10);
         input likeds(inputDS) dim(20);
         outCount int(10);
         outputA int(10) dim(20);
         last char(20);
       end-pi;

       dcl-s i int(10);
       outCount = inCount;
       for i = 1 to 20;
         if i <= outCount;
           outputA(i) = i;
         else;
           outputA(i) = 0;
         endif;
       endfor;
       last = '"quoted" text';
       return;  

