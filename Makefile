### ./make_libdb400.sh
### gmake options (see make_libdb400.sh)
### - gmake -f Makefile
### - gmake -f Makefile TGT64=64
### gcc options (Makefile)
### -v            - verbose compile
### -Wl,-bnoquiet - verbose linker
### -shared       - shared object
### -maix64       - 64bit
### -isystem      - compile PASE system headers
### -nostdlib     - remove libgcc_s.a and crtcxa_s.o
### ILE c compiles
### - INILIB      - ILE Library (see make_libdb400.sh)
### - INICHROOT   - chroot base path (see make_libdb400.sh)
CC          = gcc
# CCFLAGS32   = -v verbose
CCFLAGS32   = -g -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
CCFLAGS64   = $(CCFLAGS32) -maix64 -DTGT64
AR          = ar
AROPT       = -X32_64
INCLUDEPATH = -isystem /QOpenSys/usr/include -I.

###  shared lib
LIBOBJS      = PaseCliLibDB400_gen.o PaseCliAsync_gen.o PaseCliILE_gen.o PaseCliInit.o PaseCliCustom.o \
               PaseCliDev.o PaseCliDevConsole.o PaseCliDevFile.o PaseCliPrintf.o PaseCliDump_gen.o \
               PaseCliJson.o
LIBEXPS      = -Wl,-bE:libdb400.exp
SHRLIB32     = libdb400.a
SHROBJ32     = shr.o
LIBDEPS32    = -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread -shared -Wl,-brtl
SHRLIB64     = libdb400_64.a
SHROBJ64     = shr_64.o
LIBDEPS64    = $(LIBDEPS32) -maix64

### make TGT64=64
ifdef TGT64
CCFLAGS      = $(CCFLAGS64)
SHRLIB       = $(SHRLIB32)
SHROBJ       = $(SHROBJ64)
LIBDEPS      = $(LIBDEPS64)
### make
else
CCFLAGS      = $(CCFLAGS32)
SHRLIB       = $(SHRLIB32)
SHROBJ       = $(SHROBJ32)
LIBDEPS      = $(LIBDEPS32)
endif

### SYSTEM400
SYSTEM40032         = system400
SYSTEM400LIBOBJS32  = system400.o
SYSTEM400LIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL)
LIBDEPALL           = -L. -ldb400 -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread

SYSTEM400        = $(SYSTEM40032)
SYSTEM400LIBOBJS = $(SYSTEM400LIBOBJS32)
SYSTEM400LIBDEPS = $(SYSTEM400LIBDEPS32)

### tells make all things to do (ordered)
ifdef TGT64
all: removeo talklib $(SHRLIB)
else
$(info ==================)
$(info chroot base path INICHROOT=$(INICHROOT) (see make_libdb400.sh))
ifdef INILIB
$(info ILE library INILIB=$(INILIB) (see make_libdb400.sh))
else
$(error missing ILE library INILIB (see make_libdb400.sh))
endif
$(info ==================)
all: clean removeo talklib $(SHRLIB) talksys $(SYSTEM400) 
endif

### PASE
### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<

### -- Build the shared lib(s).
$(SHROBJ): $(LIBOBJS)
	$(CC) $(LIBOBJS) $(LIBEXPS) $(LIBDEPS) -o$(SHROBJ) 
$(SHRLIB): $(SHROBJ)
	$(AR) $(AROPT) ruv $(SHRLIB) $(SHROBJ)

### -- SYSTEM400
$(SYSTEM40032): $(SYSTEM400LIBOBJS)
	$(CC) $(CCFLAGS) $(SYSTEM400LIBOBJS) $(SYSTEM400LIBDEPS) -o $(SYSTEM40032)

talklib:
	$(info ==================)
	$(info PASE db2 driver $(SHRLIB) ( $(SHROBJ) ) )
	$(info ==================)
talksys:
	$(info ==================)
	$(info PASE utility $(SYSTEM40032))
	$(info ==================)
clean:
	rm -f $(SHRLIB)
removeo:
	rm -f *.o

