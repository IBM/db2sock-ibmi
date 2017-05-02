#!/bin/sh
# -------
# examples:
# 1) compile from chroot
#   > export INIRPGLIB=DB2JSON
#   > export INICHROOT=/QOpenSys/zend7
#   > ./make_libdb400.sh
# 2) compile from root
#   > export INIRPGLIB=DB2JSON
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
  if [[ -z "$INICHROOT" ]]
  then
    echo "***Error: missing (export INICHROOT=/QOpenSys/path)" 
    INICHROOT='/QOpenSys/zend7'
  fi
  echo "INICHROOT=$INICHROOT (export INICHROOT=/QOpenSys/zend7)"
  export "INICHROOT=$INICHROOT"
fi

if [[ -z "$INIRPGLIB" ]]
then
  echo "***Error: missing (export INIRPGLIB=library)" 
  INIRPGLIB='DB2JSON'
fi
INIRPGLIB=$(echo $INIRPGLIB | tr [a-z] [A-Z])
echo "INIRPGLIB=$INIRPGLIB (export INIRPGLIB=DB2JSON)"
export "INIRPGLIB=$INIRPGLIB"

# -------"
# build libdb400.a(shr.o)"
# -------"
gmake -f Makefile

# -------"
# build libdb400.a()"
# -------"
gmake -f Makefile TGT64=64

echo "# -------"
echo "# install libdb400.a"
echo "# -------"
echo "cp libdb400.a tests/."
cp libdb400.a tests/.
echo "cp libdb400.a $INILIBPATH."
cp libdb400.a $INILIBPATH/.

