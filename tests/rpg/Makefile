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
RAINSRVPGM   = rainsrv.srvpgm
RAINSRVOBJS  = rainsrv.mod
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
HAMELA06PGM  = hamela06.pgm
HAMELA06OBJS = hamela06.mod
HAMELA07PGM  = hamela07.pgm
HAMELA07OBJS = hamela07.mod
RAINBANKPGM  = rainbank.pgm
RAINBANKOBJS = rainbank.mod
BRIAN01PGM  = brian01.pgm
BRIAN01OBJS = brian01.mod
DANNY01PGM  = danny01.pgm
DANNY01OBJS = danny01.mod
DANNY02PGM  = danny02.pgm
DANNY02OBJS = danny02.mod
DANNY03PGM  = danny03.pgm
DANNY03OBJS = danny03.mod
DANNY04PGM  = danny04.pgm
DANNY04OBJS = danny04.mod
SLOW01PGM  = iamslow.pgm
SLOW01OBJS = iamslow.mod

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakile helpile
rpg: removeo $(HELLOPGM) $(HELLOSRVPGM) $(RAINBOWPGM) $(RAINSRVPGM) \
  $(HAMELA01PGM) $(HAMELA02PGM) $(HAMELA03PGM) $(HAMELA04PGM) \
  $(HAMELA05PGM) $(HAMELA06PGM) $(HAMELA07PGM) \
  $(BRIAN01PGM) \
  $(DANNY01PGM) $(DANNY02PGM) $(DANNY03PGM) $(DANNY04PGM) \
  $(RAINBANKPGM) $(SLOW01PGM)

.SUFFIXES: .mod .rpgle
### CRTRPGMOD
.rpgle.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- HELLOPGM (ILE RPG)
$(HELLOPGM): $(HELLOOBJS)
	$(CCPGM) --pgm $(HELLOPGM) --lib $(ILELIB) --mod $(HELLOOBJS)
### -- HELLOSRVPGM (ILE RPG)
$(HELLOSRVPGM): $(HELLOSRVOBJS)
	$(CCSRVPGM) --pgm $(HELLOSRVPGM) --lib $(ILELIB) --mod $(HELLOSRVOBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"
### -- RAINBOWPGM (ILE RPG)
$(RAINBOWPGM): $(RAINBOWOBJS)
	$(CCPGM) --pgm $(RAINBOWPGM) --lib $(ILELIB) --mod $(RAINBOWOBJS)
### -- RAINSRVPGM (ILE RPG)
$(RAINSRVPGM): $(RAINSRVOBJS)
	$(CCSRVPGM) --pgm $(RAINSRVPGM) --lib $(ILELIB) --mod $(RAINSRVOBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"
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
### -- HAMELA06PGM (ILE RPG)
$(HAMELA06PGM): $(HAMELA06OBJS)
	$(CCPGM) --pgm $(HAMELA06PGM) --lib $(ILELIB) --mod $(HAMELA06OBJS)
### -- HAMELA07PGM (ILE RPG)
$(HAMELA07PGM): $(HAMELA07OBJS)
	$(CCPGM) --pgm $(HAMELA07PGM) --lib $(ILELIB) --mod $(HAMELA07OBJS)
### -- RAINBANKPGM (ILE RPG)
$(RAINBANKPGM): $(RAINBANKOBJS)
	$(CCPGM) --pgm $(RAINBANKPGM) --lib $(ILELIB) --mod $(RAINBANKOBJS)
### -- BRIAN01PGM (ILE RPG)
$(BRIAN01PGM): $(BRIAN01OBJS)
	$(CCPGM) --pgm $(BRIAN01PGM) --lib $(ILELIB) --mod $(BRIAN01OBJS)
### -- DANNY01PGM (ILE RPG)
$(DANNY01PGM): $(DANNY01OBJS)
	$(CCPGM) --pgm $(DANNY01PGM) --lib $(ILELIB) --mod $(DANNY01OBJS)
### -- DANNY02PGM (ILE RPG)
$(DANNY02PGM): $(DANNY02OBJS)
	$(CCPGM) --pgm $(DANNY02PGM) --lib $(ILELIB) --mod $(DANNY02OBJS)
### -- DANNY03PGM (ILE RPG)
$(DANNY03PGM): $(DANNY03OBJS)
	$(CCPGM) --pgm $(DANNY03PGM) --lib $(ILELIB) --mod $(DANNY03OBJS)
### -- DANNY04PGM (ILE RPG)
$(DANNY04PGM): $(DANNY04OBJS)
	$(CCPGM) --pgm $(DANNY04PGM) --lib $(ILELIB) --mod $(DANNY04OBJS)
### -- SLOW01PGM (ILE RPG)
$(SLOW01PGM): $(SLOW01OBJS)
	$(CCPGM) --pgm $(SLOW01PGM) --lib $(ILELIB) --mod $(SLOW01OBJS)

speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE RPG tests for toolkit."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
helpile:
	@echo "> export CHROOT=/path/chroot"
	@echo "> export ILELIB=DB2JSON"
	@echo "> $(MAKE) rpg"
	@echo "------------------------------------------------------------"
removeo:
	rm -f *.mod

