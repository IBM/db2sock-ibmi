### Compile (Makefile)
### > export CHROOT=/path/chroot
### > make proc
### > make ILELIB=ANYLIB mylib
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
SP400USRVPGM = db2user.srvpgm
SP400UOBJS   = db2user.mod

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help:
	@echo "------------------------------------------------------------"
	@echo "'$(MAKE) xxx' where xxx = proc, mylib"
	@echo "'> export CHROOT=/path/chroot'"
	@echo "'> make proc'  where ILELIB=DB2JSON"
	@echo "'-- or --"
	@echo "'> export CHROOT=/path/chroot'"
	@echo "'> make ILELIB=ANYLIB mylib'"
	@echo "------------------------------------------------------------"
### tells make all things to do (ordered)
proc:
	@$(MAKE) ILELIB=DB2JSON go
mylib:
	@$(MAKE) go
go: mkinc removeo $(SP400USRVPGM)

.SUFFIXES: .mod .c
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- SP400SRVPGM (ILE c)
$(SP400USRVPGM): $(SP400UOBJS)
	$(CCSRVPGM) --pgm $(SP400USRVPGM) --lib $(ILELIB) --mod $(SP400UOBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"


mkinc:
	@echo "#ifndef _ICONF_H" > iconf.h
	@echo "#define _ICONF_H" >> iconf.h
	@echo "#define ILELIB \"$(ILELIB)\"" >> iconf.h
	@echo "#endif /* _ICONF_HH */" >> iconf.h
### -- create
clean:
	rm -f $(SP400USRVPGM)
	rm -f *.mod
removeo:
	rm -f *.mod

