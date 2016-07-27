#!/bin/sh
rm libdb400.a
gmake -f Makefile
gmake -f Makefile TGT64=64
echo "cp libdb400.a tests/."
cp libdb400.a tests/.

