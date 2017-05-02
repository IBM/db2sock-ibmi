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
### RPG compiles
### - INIRPGLIB   - RPG Library (see make_libdb400.sh)
### - INICHROOT   - chroot base path (see make_libdb400.sh)
$(info ==================)
$(info chroot base path INICHROOT=$(INICHROOT) (see make_libdb400.sh))
ifdef INIRPGLIB
$(info RPG library INIRPGLIB=$(INIRPGLIB) (see make_libdb400.sh))
else
$(error missing RPG library INIRPGLIB (see make_libdb400.sh))
endif
$(info ==================)


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


### RPG
CCRPG       = ./CRTRPGMOD
CCPGM       = ./CRTPGM

### RPG *PGM CGI - $(INIRPGLIB)/DB2JSON
CGI400PGM  = db2json.pgm
CGI400MOD  = $(INIRPGLIB)/db2json
CGI400OBJS = db2json.mod iconv.mod ipase.mod
CGI400MODS = $(INIRPGLIB)/db2json $(INIRPGLIB)/iconv $(INIRPGLIB)/ipase


### tells make all things to do (ordered)
ifdef TGT64
all: removeo talklib $(SHRLIB) talkcgi $(CGI400PGM)
else
all: clean removeo talklib $(SHRLIB) talksys $(SYSTEM400) 
endif

### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<
.SUFFIXES: .mod .rpgle
.rpgle.mod:
	$(CCRPG) $(INIRPGLIB) $<

### -- Build the shared lib(s).
$(SHROBJ): $(LIBOBJS)
	$(CC) $(LIBOBJS) $(LIBEXPS) $(LIBDEPS) -o$(SHROBJ) 
$(SHRLIB): $(SHROBJ)
	$(AR) $(AROPT) ruv $(SHRLIB) $(SHROBJ)

### -- SYSTEM400
$(SYSTEM40032): $(SYSTEM400LIBOBJS)
	$(CC) $(CCFLAGS) $(SYSTEM400LIBOBJS) $(SYSTEM400LIBDEPS) -o $(SYSTEM40032)

### -- CGI400PGM (RPG)
$(CGI400PGM): $(CGI400OBJS)
	$(CCPGM) $(CGI400MOD) $(CGI400MODS)

talklib:
	$(info ==================)
	$(info PASE db2 driver $(SHRLIB) ( $(SHROBJ) ) )
	$(info ==================)
talksys:
	$(info ==================)
	$(info PASE utility $(SYSTEM40032))
	$(info ==================)
talkcgi:
	$(info ==================)
	$(info RPG CGI $(INIRPGLIB)/$(CGI400PGM))
	$(info ==================)
clean:
	rm -f $(SHRLIB)
	rm -f $(CGI400PGM)
removeo:
	rm -f *.o
	rm -f *.mod

