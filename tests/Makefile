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

###  shared lib
LIBOBJS            = LangCommon.o
LIBEXPS            = -shared -Wl,-bE:liblang400.exp
LIBSHR32           = liblang400.a
LIBOBJ32           = shr.o
LIBDEPS32          = $(LIBDEPALL) -Wl,-brtl -Wl,-bnoquiet
LIBSHR64           = liblang400_64.a
LIBOBJ64           = shr_64.o
LIBDEPS64          = $(LIBDEPS32) -Wl,-brtl -Wl,-bnoquiet -maix64

### TEST0000
TEST0000PGM32      = test0000_theory_db2_resources_32
TEST0000LIBOBJS32  = test0000_theory_db2_resources.o
TEST0000LIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL) -llang400
TEST0000PGM64      = test0000_theory_db2_resources_64
TEST0000LIBOBJS64  = $(TEST0000LIBOBJS32)
TEST0000LIBDEPS64  = /QOpenSys/usr/lib/crt0_64.o $(LIBDEPALL) -llang400

### make TGT64=64
ifdef TGT64
CCFLAGS            = $(CCFLAGS64)
SHRLIB             = $(LIBSHR32)
SHROBJ             = $(LIBOBJ64)
LIBDEPS            = $(LIBDEPS64)
TEST0000PGM        = $(TEST0000PGM64)
TEST0000LIBOBJS    = $(TEST0000LIBOBJS64)
TEST0000LIBDEPS    = $(TEST0000LIBDEPS64)
### make (32)
else
CCFLAGS            = $(CCFLAGS32)
SHRLIB             = $(LIBSHR32)
SHROBJ             = $(LIBOBJ32)
LIBDEPS            = $(LIBDEPS32)
TEST0000PGM        = $(TEST0000PGM32)
TEST0000LIBOBJS    = $(TEST0000LIBOBJS32)
TEST0000LIBDEPS    = $(TEST0000LIBDEPS32)
endif

### tells make all things to do (ordered)
all: cpy $(SHRLIB) $(TEST0000PGM)

### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<

### -- Build the shared lib(s).
$(SHROBJ): $(LIBOBJS)
	$(CC) $(CCFLAGS) $(LIBOBJS) $(LIBEXPS) $(LIBDEPS) -o$(SHROBJ)
$(SHRLIB): $(SHROBJ)
	$(AR) $(AROPT) ruv $(SHRLIB) $(SHROBJ)

### -- test0000_theory_db2_resources_32/64
$(TEST0000PGM32): $(TEST0000LIBOBJS)
	$(CC) $(CCFLAGS) $(TEST0000LIBOBJS) $(TEST0000LIBDEPS) -o $(TEST0000PGM32)
$(TEST0000PGM64): $(TEST0000LIBOBJS)
	$(CC) $(CCFLAGS) $(TEST0000LIBOBJS) $(TEST0000LIBDEPS) -o $(TEST0000PGM64)

cpy:
	cp ../libdb400.a .

