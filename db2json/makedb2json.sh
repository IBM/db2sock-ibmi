#!/bin/sh
### RPG PTF required ###
# TGTCCSID(37)
# V7R1 - SI62954
# V7R2 - SI62956 (SI52690)
# V7R3 - SI62958
#
RPGLIB="DB2JSON"
RPGFILES='iconv ipase db2json'
system "CRTLIB LIB($RPGLIB) TYPE(*PROD) TEXT('DB2 JSON')"
for i in $RPGFILES ; do
  echo '===================================='
  echo "==> $RPGLIB/$i ..."
  RES=$(system "CRTRPGMOD MODULE($RPGLIB/$i) SRCSTMF('$i.rpgle') DBGVIEW(*SOURCE) OUTPUT(*PRINT) REPLACE(*YES) TGTCCSID(37)")
  OK=$(echo "$RES" | grep -c "00 highest severity")
  if (($OK==0))
  then
    echo "$RES"
    echo "==> $RPGLIB/$i -- $OK of 00 highest severity"
    BAD=$(echo "$RES" | grep "*RNF")
    echo '===================================='
    echo '===================================='
    echo "$BAD"
    echo '===================================='
    echo '===================================='
    exit
  else
    echo "==> $RPGLIB/$i -- 00 highest severity"
  fi
  echo '===================================='
done
RPGPGM="CRTPGM PGM($RPGLIB/$RPGLIB) MODULE("
for i in $RPGFILES ; do
  RPGPGM="$RPGPGM $RPGLIB/$i"
done
RPGPGM="$RPGPGM) BNDSRVPGM(QHTTPSVR/QZSRCORE)"
echo "$RPGPGM\n";
system "$RPGPGM"

