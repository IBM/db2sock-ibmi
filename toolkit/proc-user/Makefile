### Compile (Makefile)
### > export CHROOT=/path/chroot
### > make proc
### > make ILELIB=ANYLIB proc
### Assumes borgi command and utilities
### https://bitbucket.org/litmis/borgi
###

###  install
INSTALLBIN   = /QOpenSys/usr/bin
INSTALLDIR   = /QOpenSys/usr/lib

### ILE
CCC         = crtcmod
CCPGM       = crtpgm
CCSRVPGM    = crtsrvpgm

### *PGM proc
SP400SRVPGM = db2user.srvpgm
SP400OBJS   = db2user.mod

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakile helpile
proc: speakile mkinc removeo $(SP400SRVPGM)

.SUFFIXES: .mod .c
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- SP400SRVPGM (ILE c)
$(SP400SRVPGM): $(SP400OBJS)
	$(CCSRVPGM) --pgm $(SP400SRVPGM) --lib $(ILELIB) --mod $(SP400OBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"


speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE $(SP400SRVPGM) customer custom native toolkit call."
	@echo "Auto-loaded dynamically by proc/db2proc (see code example)."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(SP400SRVPGM)"
helpile:
	@echo "> export CHROOT=/path/chroot"
	@echo "> export ILELIB=DB2JSON"
	@echo "> $(MAKE) proc"
	@echo "------------------------------------------------------------"
mkinc:
	@echo "#ifndef _ICONF_H" > iconf.h
	@echo "#define _ICONF_H" >> iconf.h
	@echo "#define ILELIB \"$(ILELIB)\"" >> iconf.h
	@echo "#endif /* _ICONF_HH */" >> iconf.h
### -- create
clean:
	rm -f $(SP400SRVPGM)
	rm -f *.mod
removeo:
	rm -f *.mod

