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
LIBOBJSALL   = PaseCliLibDB400_gen.o PaseCliAsync_gen.o PaseCliILE_gen.o PaseCliInit.o \
               PaseCliDev.o PaseCliDevConsole.o PaseCliDevFile.o PaseCliPrintf.o PaseCliDump_gen.o \
               SQL400Cmd.o SQL400Connect.o SQL400Convert.o SQL400Stmt2Hdbc.o SQL400Version.o \
               SQL400Json.o
LIBEXPS      = -Wl,-bE:libdb400.exp
LIBOBJS32    = $(LIBOBJSALL)
SHRLIB32     = libdb400.a
SHROBJ32     = shr.o
LIBDEPALL    = -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread -shared -Wl,-brtl
LIBDEPS32    = $(LIBDEPALL)
SHRLIB64     = libdb400_64.a
LIBOBJS64    = $(LIBOBJSALL)
SHROBJ64     = shr_64.o
LIBDEPS64    = -maix64 $(LIBDEPALL)

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakpase helppase
tgt64:
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" SHRLIB="$(SHRLIB32)" SHROBJ="$(SHROBJ64)" LIBDEPS="$(LIBDEPS64)" LIBOBJS="$(LIBOBJS64)" TGT64="64" go
tgt32:
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" SHRLIB="$(SHRLIB32)" SHROBJ="$(SHROBJ32)" LIBDEPS="$(LIBDEPS32)" LIBOBJS="$(LIBOBJS32)" go
go: speakpase removeo $(SHRLIB)

### PASE
### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<

### -- Build the shared lib(s).
$(SHROBJ): $(LIBOBJS)
	$(CC) $(LIBOBJS) $(LIBEXPS) $(LIBDEPS) -o $(SHROBJ) 
$(SHRLIB): $(SHROBJ)
	$(AR) $(AROPT) ruv $(SHRLIB) $(SHROBJ)

speakpase:
	@echo "------------------------------------------------------------"
	@echo "PASE $(SHRLIB32) provides CLI interface to IBM i DB2."
	@echo "Also expands CLI to include custom APIs SQL400(name)."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(SHRLIB32) $(SHROBJ)"
helppase:
	@echo "> $(MAKE) tgt32"
	@echo "> $(MAKE) tgt64"
	@echo "> $(MAKE) install"
	@echo "> $(MAKE) tgt32 tgt64 install"
	@echo "------------------------------------------------------------"
clean:
	rm -f *.a
	rm -f *.o
removeo:
	rm -f *.o
install:
	cp ./$(SHRLIB32) $(INSTALLDIR)/.

