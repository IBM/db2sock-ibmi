### Compile (Makefile)
### > make tgt32
### > make tgt64
### > make install
### > make tgt32 tgt64 install
### gcc options (Makefile)
### -v            - verbose compile
### -Wl,-bnoquiet - verbose linker
### -shared       - shared object
### -maix64       - 64bit
### -isystem      - compile PASE system headers
### -nostdlib     - remove libgcc_s.a and crtcxa_s.o
### ar options (Makefile)
### -X32_64       - 32bit or 64bit 

###  install
INSTALLDIR   = /QOpenSys/usr/lib

CC          = gcc
CCFLAGS32   = -g -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
CCFLAGS64   = $(CCFLAGS32) -maix64 -DTGT64
AR          = ar
AROPT       = -X32_64
INCLUDEPATH = -isystem /QOpenSys/usr/include -I. -I..

###  shared lib
LIBOBJSALL   = PaseHkDmp.o PaseHack.o
LIBEXPS      = -Wl,-bE:libhack400.exp
LIBOBJS32    = $(LIBOBJSALL)
SHRLIB32     = libhack400.a
SHROBJ32     = shr.o
LIBDEPALL    = -L/QOpenSys/usr/lib -nostdlib -ldb400 -ltkit400 -lpthreads -lc -liconv -ldl -lpthread -shared -Wl,-brtl
LIBDEPS32    = $(LIBDEPALL)
SHRLIB64     = libhack400_64.a
LIBOBJS64    = $(LIBOBJSALL)
SHROBJ64     = shr_64.o
LIBDEPS64    = -maix64 $(LIBDEPALL)

### ILE
CCC         = crtcmod
CCPGM       = crtpgm
CCSRVPGM    = crtsrvpgm

### *PGM proc
SP400SRVPGM  = hack400.srvpgm
SP400OBJS    = PaseHkDmp.mod PaseHack.mod

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakpase helppase speakile helpile
tgt64:
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" SHRLIB="$(SHRLIB32)" SHROBJ="$(SHROBJ64)" LIBDEPS="$(LIBDEPS64)" LIBOBJS="$(LIBOBJS64)" TGT64="64" go
tgt32:
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" SHRLIB="$(SHRLIB32)" SHROBJ="$(SHROBJ32)" LIBDEPS="$(LIBDEPS32)" LIBOBJS="$(LIBOBJS32)" go
proc: speakile removeo $(SP400SRVPGM)
go: speakpase removeo $(SHRLIB)

### PASE
### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .mod .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --option "OPTION(*SHOWINC)" --src $<
### -- SP400SRVPGM (ILE c)
$(SP400SRVPGM): $(SP400OBJS)
	$(CCSRVPGM) --pgm $(SP400SRVPGM) --lib $(ILELIB) --mod $(SP400OBJS) --option "BNDSRVPGM($(ILELIB)/TKIT400) EXPORT(*ALL) ACTGRP(*CALLER)"

### -- Build the shared lib(s).
$(SHROBJ): $(LIBOBJS)
	$(CC) $(LIBOBJS) $(LIBEXPS) $(LIBDEPS) -o $(SHROBJ) 
$(SHRLIB): $(SHROBJ)
	$(AR) $(AROPT) ruv $(SHRLIB) $(SHROBJ)

speakpase:
	@echo "------------------------------------------------------------"
	@echo "PASE $(SHRLIB32) provides parser hack toolkit interface."
	@echo "Enables script calls to IBM i *PGM, *SRVPGM, *CMD, DB2, etc."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(SHRLIB32) $(SHROBJ)"
helppase:
	@echo "> $(MAKE) tgt32"
	@echo "> $(MAKE) tgt64"
	@echo "> $(MAKE) install"
	@echo "> $(MAKE) tgt32 tgt64 install"
	@echo "------------------------------------------------------------"
speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE $(SP400SRVPGM) provides ILE port of PASE $(SHRLIB32)."
	@echo "Used for toolkit native ILE stored proc, ILE cgi, etc."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(SP400SRVPGM)"
helpile:
	@echo "> export CHROOT=/path/chroot"
	@echo "> export ILELIB=DB2HACK"
	@echo "> $(MAKE) proc"
	@echo "------------------------------------------------------------"
clean:
	rm -f *.a
	rm -f *.o
	rm -f *.mod
removeo:
	rm -f *.o
	rm -f *.mod
install:
	cp ./$(SHRLIB32) $(INSTALLDIR)/.

