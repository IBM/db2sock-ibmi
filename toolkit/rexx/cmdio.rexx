/* HOW:
STRREXPRC SRCMBR(CMDIO) SRCFILE(DB2JSON/QSRCREXX) 
PARM('id RTVJOBA CCSID(?N) USRLIBL(?) SYSLIBL(?)')
*/
parse upper arg linein
/* substitution chars */
V = ""
V = keysub(linein)
/* create output */
'DLTF FILE(QTEMP/OUT'||V.id||')'
'CRTSRCPF FILE(QTEMP/OUT'||V.id||') RCDLEN(80) MBR(OUT'||V.id||')'
'CLRPFM FILE(QTEMP/OUT'||V.id||') MBR(OUT'||V.id||')'
'OVRDBF FILE(STDOUT) TOFILE(QTEMP/OUT'||V.id||') MBR(OUT'||V.id||')'
/* run the command */
line = V.dat
line
if RC <> 0 
then do
  say '            DEADBEE:error'
  say '            DEADBEEF'||RC
  say '            DEADBEE:REXXEOF'
  say '            DEADBEEF'||RC
  exit
end
/* output to QTEMP/OUTREXX */
if V.cnt > 0 
then do
  do i = 1 to V.cnt
    ret = keyparm(line,i,V.i)
  end
end
else do
  say '            DEADBEE:error'
  say '            DEADBEEF'||line
  say '            DEADBEE:REXXEOF'
  say '            DEADBEEF'||RC
  exit
end
say '            DEADBEE:REXXEOF'
say '            DEADBEEF'||RC
exit
keyparm:
  arg line,idx,data
  /* "&V" */
  vname = "(&V."||idx
  name = "nada"
  /* icmd parm1(&V.1) parm2(&V.2) */
  /*                        x     */
  pe = pos(vname,line)
  if pe > 0 
  then do
    /* icmd parm1(&V.1) parm2 */
    /*                      x */
    all = strip(left(line,pe-1))
    /* icmd parm1(&V.1) parm2 */
    /*                 x      */
    pe = LastPos(" ",all)
    if pe > 0 
    then do
      /* parm2 */
      name = strip(substr(all,pe))
    end
  end
  if name <> "nada" 
  then do
    pe = 40
    gooy = "            DEADBEE:"
    goop = "            DEADBEEF"
    say gooy||name
    mydata = strip(data)
    len = length(mydata)
    do while (len > 0)
      out = goop||left(mydata,pe)
      say out
      mydata = substr(mydata,pe+1)
      len = length(mydata)
    end
  end
return 0
keysub:
  arg stringin
  PARSE VAR stringin conn string
  V.id = conn
  V.cnt = 0
  V.dat = ""
  old = "?"
  out= ""
  new = "&V."
  i = 0
  DO WHILE POS(old,string) > 0
    PARSE VAR string prepart (old) string
    i = i + 1
    V.cnt = i
    aleft = left(string,1)
    V.i = " "
    if aleft <> ")" 
    then do
      V.i = 0
      string = substr(string,2)
    end
    out=out||prepart||new||i
  END
  V.dat = out||string
return V
