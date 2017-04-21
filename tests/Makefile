### make
### make TGT64=64
### gcc options
### -v            - verbose compile
### -Wl,-bnoquiet - verbose linker
### -shared       - shared object
### -maix64       - 64bit
### -isystem      - compile PASE system headers
### -nostdlib     - remove libgcc_s.a and crtcxa_s.o
CC                 = gcc
CCFLAGS32          = -g -lg -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
CCFLAGS64          = $(CCFLAGS32) -maix64
AR                 = ar
AROPT              = -X32_64
INCLUDEPATH        = -isystem /QOpenSys/usr/include -I. -I..
LIBDEPALL          = -L. -ldb400 -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread

### TEST0000
TEST0000PGM32      = test0000_resource_array_32
TEST0000LIBOBJS32  = test0000_resource_array.o
TEST0000LIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL)
TEST0000PGM64      = test0000_resource_array_64
TEST0000LIBOBJS64  = $(TEST0000LIBOBJS32)
TEST0000LIBDEPS64  = /QOpenSys/usr/lib/crt0_64.o $(LIBDEPALL)
### TEST0001
TEST0001PGM32      = test0001_error_32
TEST0001LIBOBJS32  = test0001_error.o
TEST0001LIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL)
TEST0001PGM64      = test0001_error_64
TEST0001LIBOBJS64  = $(TEST0001LIBOBJS32)
TEST0001LIBDEPS64  = /QOpenSys/usr/lib/crt0_64.o $(LIBDEPALL)

### make TGT64=64
ifdef TGT64
CCFLAGS            = $(CCFLAGS64)
SHRLIB             = $(LIBSHR32)
SHROBJ             = $(LIBOBJ64)
LIBDEPS            = $(LIBDEPS64)
TEST0000PGM        = $(TEST0000PGM64)
TEST0000LIBOBJS    = $(TEST0000LIBOBJS64)
TEST0000LIBDEPS    = $(TEST0000LIBDEPS64)
TEST0001PGM        = $(TEST0001PGM64)
TEST0001LIBOBJS    = $(TEST0001LIBOBJS64)
TEST0001LIBDEPS    = $(TEST0001LIBDEPS64)
### make (32)
else
CCFLAGS            = $(CCFLAGS32)
SHRLIB             = $(LIBSHR32)
SHROBJ             = $(LIBOBJ32)
LIBDEPS            = $(LIBDEPS32)
TEST0000PGM        = $(TEST0000PGM32)
TEST0000LIBOBJS    = $(TEST0000LIBOBJS32)
TEST0000LIBDEPS    = $(TEST0000LIBDEPS32)
TEST0001PGM        = $(TEST0001PGM32)
TEST0001LIBOBJS    = $(TEST0001LIBOBJS32)
TEST0001LIBDEPS    = $(TEST0001LIBDEPS32)
endif

### tells make all things to do (ordered)
all: cpy $(SHRLIB) $(TEST0000PGM) $(TEST0001PGM)

### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<

### -- test0000_resource_array_32/64
$(TEST0000PGM32): $(TEST0000LIBOBJS)
	$(CC) $(CCFLAGS) $(TEST0000LIBOBJS) $(TEST0000LIBDEPS) -o $(TEST0000PGM32)
$(TEST0000PGM64): $(TEST0000LIBOBJS)
	$(CC) $(CCFLAGS) $(TEST0000LIBOBJS) $(TEST0000LIBDEPS) -o $(TEST0000PGM64)
### -- test0001_error_32/64
$(TEST0001PGM32): $(TEST0001LIBOBJS)
	$(CC) $(CCFLAGS) $(TEST0001LIBOBJS) $(TEST0001LIBDEPS) -o $(TEST0001PGM32)
$(TEST0001PGM64): $(TEST0001LIBOBJS)
	$(CC) $(CCFLAGS) $(TEST0001LIBOBJS) $(TEST0001LIBDEPS) -o $(TEST0001PGM64)

cpy:
	cp ../libdb400.a .

