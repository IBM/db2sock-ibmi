#!/bin/sh
# -------
# examples:
# 1) compile from chroot
#   > export INICHROOT=/QOpenSys/zend7
#   > export INIRPGLIB=DB2JSON
#   > export INITARGET=/QOpenSys/usr/lib
#   > ./make_libdb400.sh
# 2) compile from root
#   > export INIRPGLIB=DB2JSON
#   > export INITARGET=/QOpenSys/usr/lib
#   > ./make_libdb400.sh
#
### RPG PTF required ###
# TGTCCSID(37)
# V7R1 - SI62954
# V7R2 - SI62956 (SI52690)
# V7R3 - SI62958

# -------
# settings
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

if [[ -z "$INIRPGLIB" ]]
then
  echo "***Error: INIRPGLIB missing, using default (export INIRPGLIB=library)" 
  INIRPGLIB='DB2JSON'
fi
INIRPGLIB=$(echo $INIRPGLIB | tr [a-z] [A-Z])
echo "INIRPGLIB=$INIRPGLIB (export INIRPGLIB=DB2JSON)"
export "INIRPGLIB=$INIRPGLIB"

if [[ -z "$INITARGET" ]]
then
  echo "***Error: INITARGET missing, using default (export INITARGET=/QOpenSys/usr/lib)" 
  INITARGET='/QOpenSys/usr/lib'
fi
echo "INITARGET=$INITARGET (export INITARGET=/QOpenSys/usr/lib)"
export "INITARGET=$INITARGET"


# -------
# build iconf_h.rpgle
# -------
echo "      /if defined(ICONF_H)" > iconf_h.rpgle
echo "      /eof" >> iconf_h.rpgle
echo "      /endif" >> iconf_h.rpgle
echo "      /define ICONF_H" >> iconf_h.rpgle
echo "        " >> iconf_h.rpgle
if [[ -z "$INICHROOT" ]]
then
  echo "       DCL-C DB2_PATH_LIBDB400 CONST('+" >> iconf_h.rpgle
  echo "       $INITARGET');" >> iconf_h.rpgle
else
  echo "       DCL-C DB2_PATH_LIBDB400 CONST('$INICHROOT/+" >> iconf_h.rpgle
  echo "       $INITARGET');" >> iconf_h.rpgle
fi
echo "       DCL-C DB2_ENV4_TRACE CONST('TRACE=off');" >> iconf_h.rpgle

# -------
# build libdb400.a(shr.o)
# -------
gmake -f Makefile

# -------
# build libdb400.a()
# -------
gmake -f Makefile TGT64=64

echo "# -------"
echo "# install libdb400.a"
echo "# (Device busy, means copy fails)"
echo "# -------"
echo "cp libdb400.a tests/."
cp libdb400.a tests/.
echo "cp libdb400.a $INITARGET/."
cp libdb400.a $INITARGET/.


