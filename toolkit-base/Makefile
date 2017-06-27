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
LIBOBJSALL   =  PaseTool.o
LIBEXPS      = -Wl,-bE:libtkit400.exp
LIBOBJS32    = $(LIBOBJSALL)
SHRLIB32     = libtkit400.a
SHROBJ32     = shr.o
LIBDEPALL    = -L/QOpenSys/usr/lib -nostdlib -ldb400 -lpthreads -lc -liconv -ldl -lpthread -shared -Wl,-brtl
LIBDEPS32    = $(LIBDEPALL)
SHRLIB64     = libtkit400_64.a
LIBOBJS64    = $(LIBOBJSALL)
SHROBJ64     = shr_64.o
LIBDEPS64    = -maix64 $(LIBDEPALL)

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help:
	@echo "------------------------------------------------------------"
	@echo "'$(MAKE) xxx' where xxx = tgt32, tgt64, install"
	@echo "'> make tgt32'"
	@echo "'> make tgt64'"
	@echo "'> make install'"
	@echo "'> make tgt32 tgt64 install'"
	@echo "------------------------------------------------------------"

### tells make all things to do (ordered)
tgt64:
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" SHRLIB="$(SHRLIB32)" SHROBJ="$(SHROBJ64)" LIBDEPS="$(LIBDEPS64)" LIBOBJS="$(LIBOBJS64)" TGT64="64" go
tgt32:
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" SHRLIB="$(SHRLIB32)" SHROBJ="$(SHROBJ32)" LIBDEPS="$(LIBDEPS32)" LIBOBJS="$(LIBOBJS32)" go
go: removeo $(SHRLIB)

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

clean:
	rm -f $(SHRLIB)
	rm -f *.o
removeo:
	rm -f *.o
install:
	cp ./$(SHRLIB32) $(INSTALLDIR)/.

