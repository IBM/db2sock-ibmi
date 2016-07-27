#!/bin/sh
rm *.o
gmake -f Makefile
rm *.o
gmake -f Makefile TGT64=64
rm *.o

