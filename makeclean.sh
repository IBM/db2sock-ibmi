#!/QOpenSys/usr/bin/ksh

if [ ! -d /QSYS.LIB ]; then
  if [ "x$CHROOT" = "x" ]; then 
    echo "env var CHROOT not set"
    exit
  fi
fi
echo "== CHROOT ($CHROOT) =="

if [ "x$ILELIB" = "x" ]; then 
  ILELIB="DB2JSON"
fi
echo "== ILELIB ($ILELIB) =="

echo "=== clean up $ILELIB/*MODULE ==="
dltmod --lib $ILELIB --mod DB2JSON
dltmod --lib $ILELIB --mod DB2PROC
dltmod --lib $ILELIB --mod DB2PROCJ
dltmod --lib $ILELIB --mod DB2PROCJR
dltmod --lib $ILELIB --mod DB2USER
dltmod --lib $ILELIB --mod HAMELA01
dltmod --lib $ILELIB --mod HAMELA02
dltmod --lib $ILELIB --mod HAMELA03
dltmod --lib $ILELIB --mod HAMELA04
dltmod --lib $ILELIB --mod HAMELA05
dltmod --lib $ILELIB --mod HAMELA06
dltmod --lib $ILELIB --mod HELLO
dltmod --lib $ILELIB --mod HELLOSRV
dltmod --lib $ILELIB --mod IBYREFP1
dltmod --lib $ILELIB --mod IBYREFP2
dltmod --lib $ILELIB --mod IBYREFP3
dltmod --lib $ILELIB --mod IBYREFP4
dltmod --lib $ILELIB --mod IBYREFP5
dltmod --lib $ILELIB --mod IBYREFS1
dltmod --lib $ILELIB --mod IBYREFS2
dltmod --lib $ILELIB --mod IBYREFS3
dltmod --lib $ILELIB --mod IBYREFS4
dltmod --lib $ILELIB --mod IBYREFS5
dltmod --lib $ILELIB --mod IBYVALS1
dltmod --lib $ILELIB --mod IBYVALS2
dltmod --lib $ILELIB --mod IBYVALS3
dltmod --lib $ILELIB --mod IBYVALS4
dltmod --lib $ILELIB --mod IBYVALS5
dltmod --lib $ILELIB --mod IBYVALS6
dltmod --lib $ILELIB --mod IBYVALS7
dltmod --lib $ILELIB --mod IBYVALS8
dltmod --lib $ILELIB --mod PASEJSDMP
dltmod --lib $ILELIB --mod PASEJSON
dltmod --lib $ILELIB --mod PASETO400
dltmod --lib $ILELIB --mod PASETODMP
dltmod --lib $ILELIB --mod PASETOILE
dltmod --lib $ILELIB --mod PASETOOL
dltmod --lib $ILELIB --mod RAINBANK
dltmod --lib $ILELIB --mod RAINBOW
dltmod --lib $ILELIB --mod RAINSRV


