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
CCSQL		     = db2script

### *PGM CGI
HELLOPGM     = hello.pgm
HELLOOBJS    = hello.mod
HELLOSRVPGM  = hellosrv.srvpgm
HELLOSRVOBJS = hellosrv.mod
RAINBOWPGM   = rainbow.pgm
RAINBOWOBJS  = rainbow.mod
HAMELA01PGM  = hamela01.pgm
HAMELA01OBJS = hamela01.mod
HAMELA02PGM  = hamela02.pgm
HAMELA02OBJS = hamela02.mod
HAMELA03PGM  = hamela03.pgm
HAMELA03OBJS = hamela03.mod
HAMELA04PGM  = hamela04.pgm
HAMELA04OBJS = hamela04.mod
HAMELA05PGM  = hamela05.pgm
HAMELA05OBJS = hamela05.mod

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
go: removeo $(HELLOPGM) $(HELLOSRVPGM) $(RAINBOWPGM) \
  $(HAMELA01PGM) $(HAMELA02PGM) $(HAMELA03PGM) $(HAMELA04PGM) \
  $(HAMELA05PGM)

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
### -- HAMELA01PGM (ILE RPG)
$(HAMELA01PGM): $(HAMELA01OBJS)
	$(CCPGM) --pgm $(HAMELA01PGM) --lib $(ILELIB) --mod $(HAMELA01OBJS)
### -- HAMELA02PGM (ILE RPG)
$(HAMELA02PGM): $(HAMELA02OBJS)
	$(CCPGM) --pgm $(HAMELA02PGM) --lib $(ILELIB) --mod $(HAMELA02OBJS)
### -- HAMELA03PGM (ILE RPG)
$(HAMELA03PGM): $(HAMELA03OBJS)
	$(CCPGM) --pgm $(HAMELA03PGM) --lib $(ILELIB) --mod $(HAMELA03OBJS)
### -- HAMELA04PGM (ILE RPG)
$(HAMELA04PGM): $(HAMELA04OBJS)
	$(CCPGM) --pgm $(HAMELA04PGM) --lib $(ILELIB) --mod $(HAMELA04OBJS)
### -- HAMELA04PGM (ILE RPG)
$(HAMELA05PGM): $(HAMELA05OBJS)
	$(CCPGM) --pgm $(HAMELA05PGM) --lib $(ILELIB) --mod $(HAMELA05OBJS)

removeo:
	rm -f *.mod

