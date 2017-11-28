### Compile (Makefile)
### > make TGT32
### > make TGT64
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

### fastcgi protocol
FCGI               = ./fcgi-2.4.1-SNAP-0311112127

CC                 = gcc
CCFLAGS32          = -g -lg -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
CCFLAGS64          = $(CCFLAGS32) -maix64
AR                 = ar
AROPT              = -X32_64
INCLUDEPATH        = -isystem /QOpenSys/usr/include -I. -I.. -I$(FCGI)/include
LIBDEPALL          = -L$(INSTALLDIR) -ldb400 -L/QOpenSys/usr/lib -nostdlib -lpthreads -lc -liconv -ldl -lpthread

### DB2FCGI
DB2FCGIPGM32      = db2jsonfcgi
DB2FCGILIBOBJS32  = db2jsonfcgi.o fcgiapp.o os_unix.o fcgi_stdio.o
DB2FCGILIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL)
DB2FCGIPGM64      = db2jsonfcgi_64
DB2FCGILIBOBJS64  = /QOpenSys/usr/lib/crt0_64.o $(DB2FCGILIBOBJS32)
DB2FCGILIBDEPS64  = $(LIBDEPALL)
### DB2NGIX
DB2NGIXPGM32      = db2jsonngix
DB2NGIXLIBOBJS32  = cgi-fcgi.o fcgiapp.o os_unix.o fcgi_stdio.o
DB2NGIXLIBDEPS32  = /QOpenSys/usr/lib/crt0.o $(LIBDEPALL)
DB2NGIXPGM64      = db2jsonngix_64
DB2NGIXLIBOBJS64  = /QOpenSys/usr/lib/crt0_64.o $(DB2NGIXLIBOBJS32)
DB2NGIXLIBDEPS64  = $(LIBDEPALL)

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakpase helppase
tgt64:
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" DB2FCGIPGM="$(DB2FCGIPGM64)" DB2FCGILIBOBJS="$(DB2FCGILIBOBJS64)" DB2FCGILIBDEPS="$(DB2FCGILIBDEPS64)" TGT64="64" go
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" DB2NGIXPGM="$(DB2NGIXPGM64)" DB2NGIXLIBOBJS="$(DB2NGIXLIBOBJS64)" DB2NGIXLIBDEPS="$(DB2NGIXLIBDEPS64)" TGT64="64" go
tgt32:
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" DB2FCGIPGM="$(DB2FCGIPGM32)" DB2FCGILIBOBJS="$(DB2FCGILIBOBJS32)" DB2FCGILIBDEPS="$(DB2FCGILIBDEPS32)" go
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" DB2NGIXPGM="$(DB2NGIXPGM32)" DB2NGIXLIBOBJS="$(DB2NGIXLIBOBJS32)" DB2NGIXLIBDEPS="$(DB2NGIXLIBDEPS32)" go
go: speakpase cpy removeo $(DB2FCGIPGM) $(DB2NGIXPGM)

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
### -- db2jsonngix_32/64
$(DB2NGIXPGM32): $(DB2NGIXLIBOBJS)
	$(CC) $(CCFLAGS) $(DB2NGIXLIBOBJS) $(DB2NGIXLIBDEPS) -o $(DB2NGIXPGM32)
$(DB2NGIXPGM64): $(DB2NGIXLIBOBJS)
	$(CC) $(CCFLAGS) $(DB2NGIXLIBOBJS) $(DB2NGIXLIBDEPS) -o $(DB2NGIXPGM64)

speakpase:
	@echo "------------------------------------------------------------"
	@echo "PASE $(DB2FCGIPGM32) or $(DB2FCGIPGM64) provides fastcgi toolkit interface (apache, nginx)."
	@echo "PASE $(DB2NGIXPGM32) or $(DB2NGIXPGM64) provides fastcgi start (nginx)."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(DB2FCGIPGM) $(DB2NGIXPGM)"
helppase:
	@echo "> $(MAKE) tgt32"
	@echo "> $(MAKE) tgt64"
	@echo "> $(MAKE) install"
	@echo "> $(MAKE) tgt32 tgt64 install"
	@echo "------------------------------------------------------------"
cpy:
	tar -xf fcgi.tar
	cp $(FCGI)/libfcgi/fcgiapp.c .
	cp $(FCGI)/libfcgi/fcgiapp.c .
	cp $(FCGI)/libfcgi/os_unix.c .
	cp $(FCGI)/libfcgi/fcgi_stdio.c .
	cp $(FCGI)/cgi-fcgi/cgi-fcgi.c .
removeo:
	rm -f *.o
install:
	cp ./$(DB2FCGIPGM32) $(INSTALLDIR)/.
	cp ./$(DB2FCGIPGM64) $(INSTALLDIR)/.
	cp ./$(DB2NGIXPGM32) $(INSTALLDIR)/.
	cp ./$(DB2NGIXPGM64) $(INSTALLDIR)/.

