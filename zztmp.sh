#!/bin/sh
rm /tmp/*
gcc -g -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast -isystem /QOpenSys/usr/include -I. -c system400.c
gcc -g -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast system400.o /QOpenSys/usr/lib/crt0.o -L. -ldb400 -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread -o system400

