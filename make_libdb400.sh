#!/bin/sh
# -------
# examples:
# 1) compile from chroot
#   > export INICHROOT=/QOpenSys/zend7
#   > export INILIB=DB2JSON
#   > export INITARGET=/QOpenSys/usr/lib
#   > ./make_libdb400.sh
# 2) compile from root
#   > export INILIB=DB2JSON
#   > export INITARGET=/QOpenSys/usr/lib
#   > ./make_libdb400.sh
# Subset compile:
#   > ./make_libdb400.sh ile 400 test
#   > ./make_libdb400.sh ile 400
#   > ./make_libdb400.sh test
#
#
### RPG PTF required ###
# TGTCCSID(37)
# V7R1 - SI62954
# V7R2 - SI62956 (SI52690)
# V7R3 - SI62958

# -------
# main
# -------
SELECT=""
opr="error"
for arg in "$@"
{
  SELECT="$SELECT $arg"
}
if [[ -z "$SELECT" ]]
then
  SELECT="400 ile test"
fi
echo "# -------"
echo "# compile $SELECT"
echo "# -------"

# -------
# settings (env vars)
# -------
echo "# -------"
echo "# environment variable settings"
echo "# -------"
DIRECTORY="/QSYS.LIB"
if [ -d "$DIRECTORY" ]
then
  echo "compile root (not chroot)"
  unset INICHROOT
else
  echo "$DIRECTORY missing (chroot)"
  if [[ -z "$INICHROOT" ]]
  then
    echo "***Error: INICHROOT missing, using default (export INICHROOT=/QOpenSys/path)" 
    INICHROOT='/QOpenSys/zend7'
  fi
  echo "INICHROOT=$INICHROOT (export INICHROOT=/QOpenSys/zend7)"
  export "INICHROOT=$INICHROOT"
fi

if [[ -z "$INILIB" ]]
then
  echo "***Error: INILIB missing, using default (export INILIB=library)" 
  INILIB='DB2JSON'
fi
INILIB=$(echo $INILIB | tr [a-z] [A-Z])
echo "INILIB=$INILIB (export INILIB=DB2JSON)"
export "INILIB=$INILIB"

if [[ -z "$INITARGET" ]]
then
  echo "***Error: INITARGET missing, using default (export INITARGET=/QOpenSys/usr/lib)" 
  INITARGET='/QOpenSys/usr/lib'
fi
echo "INITARGET=$INITARGET (export INITARGET=/QOpenSys/usr/lib)"
export "INITARGET=$INITARGET"

# -------
# build libdb400.a(shr.o/shr_64.o)
# -------
case "$SELECT" in
  *400*)
    echo "# -------"
    echo "# build libdb400.a(shr.o/shr_64.o)"
    echo "# -------"
    gmake -f Makefile
    gmake -f Makefile TGT64=64
    echo "# -------"
    echo "# install libdb400.a"
    echo "# (Device busy, means copy fails)"
    echo "# -------"
    echo "cp libdb400.a $INITARGET/."
    cp libdb400.a $INITARGET/.
  ;;      
esac

# -------
# build tests
# -------
case "$SELECT" in
  *test*)
    echo "# -------"
    echo "# build tests"
    echo "# -------"
    cd tests
    gmake -f Makefile
    gmake -f Makefile TGT64=64
    cd ..
  ;;      
esac

# -------
# build ILE-CGI
# -------
case "$SELECT" in
  *ile*)
    echo "# -------"
    echo "# build ILE-CGI"
    echo "# -------"
    cd ILE-CGI
    pwd
    echo "#ifndef _ICONF_H" > iconf.h
    echo "#define _ICONF_H" >> iconf.h
    if [[ -z "$INICHROOT" ]]
    then
      echo "#define DB2_FILE_LIBDB400 \"$INITARGET/libdb400.a(shr.o)\"" >> iconf.h
    else
      echo "#define DB2_FILE_LIBDB400 \"$INICHROOT$INITARGET/libdb400.a(shr.o)\"" >> iconf.h
    fi
    echo "#define DB2_SYM_SQL400JSON \"SQL400Json\"" >> iconf.h
    echo "#define DB2_ENV_TRACE \"TRACE=off\"" >> iconf.h
    echo "#endif /* _ICONF_HH */" >> iconf.h
    gmake -f Makefile
    cd ..
  ;;      
esac

