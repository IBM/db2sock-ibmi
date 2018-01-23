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
CCSQL		    = db2script

### *PGM proc
SP400SRVPGM  = db2proc.srvpgm
SP400OBJS    = db2proc.mod \
	ibyrefp1.mod ibyrefp2.mod ibyrefp3.mod ibyrefp4.mod ibyrefp5.mod \
	ibyrefs1.mod ibyrefs2.mod ibyrefs3.mod ibyrefs4.mod ibyrefs5.mod \
	ibyvals1.mod ibyvals2.mod ibyvals3.mod ibyvals4.mod ibyvals5.mod ibyvals6.mod ibyvals7.mod ibyvals8.mod
SQLTPL       = crtsql.cmd
SQLRPL       = DB2JSON $(ILELIB)

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakile helpile
proc: speakile mkinc removeo $(SP400SRVPGM) crtsqlproc

.SUFFIXES: .mod .c
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --option "OPTION(*SHOWINC)" --src $<
### -- SP400SRVPGM (ILE c)
$(SP400SRVPGM): $(SP400OBJS)
	$(CCSRVPGM) --pgm $(SP400SRVPGM) --lib $(ILELIB) --mod $(SP400OBJS) --option "EXPORT(*ALL) ACTGRP(*CALLER)"

speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE $(SP400SRVPGM) native stored procedure toolkit call."
	@echo "$(CCSQL) creates stored procedure $(ILELIB).DB2PROC(blob)."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(SP400SRVPGM)"
	@echo "stored procedure $(CCSQL) -f $(SQLTPL) -r $(SQLRPL)"
helpile:
	@echo "> export CHROOT=/path/chroot"
	@echo "> export ILELIB=DB2JSON"
	@echo "> $(MAKE) proc"
	@echo "------------------------------------------------------------"
mkinc:
	@echo "#ifndef _ICONF_H" > iconf.h
	@echo "#define _ICONF_H" >> iconf.h
	@echo "#define ILELIB \"$(ILELIB)\"" >> iconf.h
	@echo "#endif /* _ICONF_H */" >> iconf.h
### -- create stored procedures (iPLUG512K, etc.)
crtsqlproc:
	$(CCSQL) -f $(SQLTPL) -r $(SQLRPL)
clean:
	rm -f $(SP400SRVPGM)
	rm -f *.mod
removeo:
	rm -f *.mod

