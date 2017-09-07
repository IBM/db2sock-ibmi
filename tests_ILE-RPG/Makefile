### Compile (Makefile)
### > export CHROOT=/path/chroot
### > make test
### > make ILELIB=ANYLIB mylib
### Assumes borgi command and utilities
### https://bitbucket.org/litmis/borgi
###

###  install
INSTALLBIN   = /QOpenSys/usr/bin
INSTALLDIR   = /QOpenSys/usr/lib

### ILE
CCC          = crtrpgmod
CCPGM        = crtpgm
CCSRVPGM     = crtsrvpgm
CCSQL		 = db2script

### *PGM CGI
HELLOPGM     = hello.pgm
HELLOOBJS    = hello.mod
HELLOSRVPGM  = hellosrv.srvpgm
HELLOSRVOBJS = hellosrv.mod
RAINBOWPGM   = rainbow.pgm
RAINBOWOBJS  = rainbow.mod

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help:
	@echo "------------------------------------------------------------"
	@echo "'$(MAKE) xxx' where xxx = rpg, mylib"
	@echo "'> export CHROOT=/path/chroot'"
	@echo "'> make test'  where ILELIB=DB2JSON"
	@echo "'-- or --"
	@echo "'> export CHROOT=/path/chroot'"
	@echo "'> make ILELIB=ANYLIB mylib'"
	@echo "------------------------------------------------------------"
### tells make all things to do (ordered)
rpg:
	@$(MAKE) ILELIB=DB2JSON go
mylib:
	@$(MAKE) go
go: removeo $(HELLOPGM) $(HELLOSRVPGM) $(RAINBOWPGM) 

.SUFFIXES: .mod .rpgle
### CRTRPGMOD
.rpgle.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- HELLOPGM (ILE RPG)
$(HELLOPGM): $(HELLOOBJS)
	$(CCPGM) --pgm $(HELLOPGM) --lib $(ILELIB) --mod $(HELLOOBJS)
### -- HELLOSRVPGM (ILE RPG)
$(HELLOSRVPGM): $(HELLOSRVOBJS)
	$(CCSRVPGM) --pgm $(HELLOSRVPGM) --lib $(ILELIB) --mod $(HELLOSRVBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"
### -- RAINBOWPGM (ILE RPG)
$(RAINBOWPGM): $(RAINBOWOBJS)
	$(CCPGM) --pgm $(RAINBOWPGM) --lib $(ILELIB) --mod $(RAINBOWOBJS)

removeo:
	rm -f *.mod

