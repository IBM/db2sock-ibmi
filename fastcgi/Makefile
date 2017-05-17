### make
### make TGT64=64
### gcc options
### -v            - verbose compile
### -Wl,-bnoquiet - verbose linker
### -shared       - shared object
### -maix64       - 64bit
### -isystem      - compile PASE system headers
### -nostdlib     - remove libgcc_s.a and crtcxa_s.o

FCGI               = ./fcgi-2.4.1-SNAP-0311112127

CC                 = gcc
CCFLAGS32          = -g -lg -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
CCFLAGS64          = $(CCFLAGS32) -maix64
AR                 = ar
AROPT              = -X32_64
INCLUDEPATH        = -isystem /QOpenSys/usr/include -I. -I.. -I$(FCGI)/include
LIBDEPALL          = -L. -ldb400 -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread

### DB2FCGI
DB2FCGIPGM32      = db2jsonfcgi
DB2FCGILIBOBJS32  = db2jsonfcgi.o fcgiapp.o os_unix.o fcgi_stdio.o
DB2FCGILIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL)
DB2FCGIPGM64      = db2jsonfcgi_64
DB2FCGILIBOBJS64  = /QOpenSys/usr/lib/crt0_64.o $(DB2FCGILIBOBJS32)
DB2FCGILIBDEPS64  = $(LIBDEPALL)

### make TGT64=64
ifdef TGT64
CCFLAGS            = $(CCFLAGS64)
DB2FCGIPGM         = $(DB2FCGIPGM64)
DB2FCGILIBOBJS     = $(DB2FCGILIBOBJS64)
DB2FCGILIBDEPS     = $(DB2FCGILIBDEPS64)
### make (32)
else
CCFLAGS            = $(CCFLAGS32)
DB2FCGIPGM         = $(DB2FCGIPGM32)
DB2FCGILIBOBJS     = $(DB2FCGILIBOBJS32)
DB2FCGILIBDEPS     = $(DB2FCGILIBDEPS32)
endif

### tells make all things to do (ordered)
all: cpy removeo $(DB2FCGIPGM)

### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<

### -- db2jsonfcgi_32/64
$(DB2FCGIPGM32): $(DB2FCGILIBOBJS)
	$(CC) $(CCFLAGS) $(DB2FCGILIBOBJS) $(DB2FCGILIBDEPS) -o $(DB2FCGIPGM32)
$(DB2FCGIPGM64): $(DB2FCGILIBOBJS)
	$(CC) $(CCFLAGS) $(DB2FCGILIBOBJS) $(DB2FCGILIBDEPS) -o $(DB2FCGIPGM64)

cpy:
	cp ../libdb400.a .
	cp $(FCGI)/libfcgi/fcgiapp.c .
	cp $(FCGI)/libfcgi/fcgiapp.c .
	cp $(FCGI)/libfcgi/os_unix.c .
	cp $(FCGI)/libfcgi/fcgi_stdio.c .
removeo:
	rm -f *.o

