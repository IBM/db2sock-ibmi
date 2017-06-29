#!/QOpenSys/usr/bin/ksh

echo "== CHROOT ($CHROOT) ="

echo "== libdb400.a ==="
make tgt32 tgt64 install

echo "== db2proc.srvpgm (optional) ==="
cd ILE-PROC
make proc
cd ..

echo "== libtkit400.a (optional) ==="
cd toolkit-base
make tgt32 tgt64 install
cd ..

echo "== libjson400.a (optional) ==="
cd toolkit-parser-json
make tgt32 tgt64 install
cd ..

echo "== db2jsonfcgi (optional) ==="
cd fastcgi
make tgt32 tgt64 install
cd ..

echo "== db2json.pgm (optional) ==="
cd ILE-CGI
make cgi
cd ..

echo "== tests_c (optional) ==="
cd tests_c
make tgt32 tgt64 install
cd ..

echo "== tests_ILE-RPG (optional) ==="
cd tests_ILE-RPG
make rpg
cd ..

