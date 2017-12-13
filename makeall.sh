#!/QOpenSys/usr/bin/ksh

echo "====================================================="
echo "====================================================="
if [ ! -d /QSYS.LIB ]; then
  if [ "x$CHROOT" = "x" ]; then 
    echo "env var CHROOT not set  (export CHROOT=/QOpenSys/db2sock)"
    exit
  fi
fi
echo "== CHROOT ($CHROOT) =="


if [ "x$ILELIB" = "x" ]; then 
    echo "ILELIB not set  (export ILELIB=DB2JSON)"
    exit
fi
echo "== ILELIB ($ILELIB) =="

if [ ! -f /QOpenSys/usr/bin/crtrpgmod ]; then
    echo "borgi utility /QOpenSys/usr/bin/crtrpgmod not found"
    echo "project borgi required for ILE Makefile compiles"
    echo "( download src https://bitbucket.org/litmis/borgi )"
    echo "( pre-compiled http://yips.idevcloud.com/wiki/index.php/Databases/Borgi )"
    exit
fi
echo "== project borgi ok /QOpenSys/usr/bin/crtrpgmod (https://bitbucket.org/litmis/borgi) =="

echo "====================================================="
echo "====================================================="
echo "== db2 libdb400.a ==="
cd db2
make tgt32 tgt64 install
cd ..

echo "====================================================="
echo "====================================================="
echo "== toolkit/rexx $ILELIB/QREXSRC.CMDIO (optional) ==="
cd toolkit/rexx
make rexx
cd ../..


echo "====================================================="
echo "====================================================="
echo "== toolkit/proc $ILELIB/db2proc.srvpgm (optional) ==="
cd toolkit/proc
make proc
cd ../..

echo "====================================================="
echo "====================================================="
echo "== toolkit/proc-user  $ILELIB/db2user.srvpgm (optional) ==="
cd toolkit/proc-user
make proc
cd ../..

echo "====================================================="
echo "====================================================="
echo "== toolkit libtkit400.a (optional) ==="
cd toolkit
make tgt32 tgt64 install
make proc
cd ..

echo "====================================================="
echo "====================================================="
echo "== toolkit/parser-json libjson400.a (optional) ==="
cd toolkit/parser-json
make tgt32 tgt64 install
make proc
cd ../..

echo "====================================================="
echo "====================================================="
echo "== toolkit/procj  $ILELIB/db2procj.srvpgm (optional) ==="
cd toolkit/procj
make proc
cd ../..

echo "====================================================="
echo "====================================================="
echo "== toolkit/fastcgi db2jsonfcgi (optional) ==="
cd toolkit/fastcgi
make tgt32 tgt64 install
cd ../..

echo "====================================================="
echo "====================================================="
echo "== toolkit/cgi  $ILELIB/db2json.pgm (optional) ==="
cd toolkit/cgi
make cgi
cd ../..

echo "====================================================="
echo "====================================================="
echo "== tests/c (optional) ==="
cd tests/c
make tgt32 tgt64 install
cd ../..

echo "====================================================="
echo "====================================================="
echo "== tests/rpg (optional) ==="
cd tests/rpg
make rpg
cd ../..


