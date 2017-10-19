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
CCSQL		    = db2script

### *PGM proc
SP400SRVPGM  = db2procj.srvpgm
SP400OBJS    = db2procj.mod
SQLTPL       = crtsql.cmd
SQLRPL       = DB2JSON $(ILELIB)

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
go: mkinc removeo $(SP400SRVPGM) crtsqlproc

.SUFFIXES: .mod .c
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- SP400SRVPGM (ILE c)
$(SP400SRVPGM): $(SP400OBJS)
	$(CCSRVPGM) --pgm $(SP400SRVPGM) --lib $(ILELIB) --mod $(SP400OBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"


mkinc:
	@echo "#ifndef _ICONF_H" > iconf.h
	@echo "#define _ICONF_H" >> iconf.h
	@echo "#define ILELIB \"$(ILELIB)\"" >> iconf.h
	@echo "#endif /* _ICONF_HH */" >> iconf.h
### -- create stored procedures (iPLUG512K, etc.)
crtsqlproc:
	$(CCSQL) -f $(SQLTPL) -r $(SQLRPL)
clean:
	rm -f $(SP400SRVPGM)
	rm -f *.mod
removeo:
	rm -f *.mod

