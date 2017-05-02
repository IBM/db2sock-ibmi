#!/bin/sh
# -------
#
# > ./make.sh library [...]
#
# examples:
#   full build
#   > export INIMODE=TEST
#   > export INIRPGLIB=DB2JSON
#   > export INICHROOT=/QOpenSys/zend7
#   > export INIPATH=/QOpenSys/usr/bin
#   > export INILIBPATH=/QOpenSys/usr/lib
#   > ./make.sh
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
echo "# settings"
echo "# -------"
if [[ -z "$INIMODE" ]]
then
  INIMODE='TEST'
fi
INIMODE=$(echo $INIMODE | tr [a-z] [A-Z])
echo "INIMODE=$INIMODE (export INIMODE=TEST)"
export "INIMODE=$INIMODE"

if [[ -z "$INIRPGLIB" ]]
then
  INIRPGLIB='DB2JSON'
fi
INIRPGLIB=$(echo $INIRPGLIB | tr [a-z] [A-Z])
echo "INIRPGLIB=$INIRPGLIB (export INIRPGLIB=DB2JSON)"
export "INIRPGLIB=$INIRPGLIB"

if [[ -z "$INICHROOT" ]]
then
  INICHROOT='/QOpenSys/zend7'
fi
echo "INICHROOT=$INICHROOT (export INICHROOT=/QOpenSys/zend7)"
export "INICHROOT=$INICHROOT"

if [[ -z "$INIPATH" ]]
then
  INIPATH='/QOpenSys/usr/bin'
fi
echo "INIPATH=$INIPATH (export INIPATH=/QOpenSys/usr/bin)"
export "INIPATH=$INIPATH"

if [[ -z "$INILIBPATH" ]]
then
  INILIBPATH='/QOpenSys/usr/lib'
fi
echo "INILIBPATH=$INILIBPATH (export INILIBPATH=/QOpenSys/usr/lib)"
export "INILIBPATH=$INILIBPATH"

BLDPWD=$(pwd)
BLDFULL=$INICHROOT$BLDPWD
echo "BLDFULL=$BLDFULL"
export "BLDFULL=$BLDFULL"

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

