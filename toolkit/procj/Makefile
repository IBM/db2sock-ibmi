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
CCCSQL      = crtsqlci
CCRPGSQL	  = crtsqlrpgi
CCPGM       = crtpgm
CCSRVPGM    = crtsrvpgm
CCSQL		    = db2script

### *PGM proc
SP400SRVPGM  = db2procj.srvpgm
SP400OBJS    = db2procj.mod
SP400SRVPGM1 = db2procjr.srvpgm
SP400OBJS1   = db2procjr.modsql
SQLTPL       = crtsql.cmd
SQLRPL       = DB2JSON $(ILELIB)

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakile helpile
proc: speakile mkinc removeo $(SP400SRVPGM1) $(SP400SRVPGM) crtsqlproc

.SUFFIXES: .mod .c .modsql .rpglesql
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- SP400SRVPGM (ILE c)
$(SP400SRVPGM): $(SP400OBJS)
	$(CCSRVPGM) --pgm $(SP400SRVPGM) --lib $(ILELIB) --mod $(SP400OBJS) --option "BNDSRVPGM($(ILELIB)/JSON400 $(ILELIB)/TKIT400) EXPORT(*ALL) ACTGRP(*CALLER)"
### CRTSQLRPGI
.rpglesql.modsql:
	$(CCRPGSQL) --lib $(ILELIB) --option "DBGVIEW(*SOURCE)" --src $<
### -- SP400SRVPGM1 (ILE rpg)
$(SP400SRVPGM1): $(SP400OBJS1)
	$(CCSRVPGM) --pgm $(SP400SRVPGM1) --lib $(ILELIB) --mod $(SP400OBJS1) --option "BNDSRVPGM($(ILELIB)/JSON400 $(ILELIB)/TKIT400) EXPORT(*ALL) ACTGRP(*CALLER)"

speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE $(SP400SRVPGM) native stored procedure toolkit call in/out parm."
	@echo "ILE $(SP400SRVPGM1) native stored procedure toolkit call result set."
	@echo "$(CCSQL) creates stored procedure $(ILELIB).DB2PROCJ(clob) in/out parm."
	@echo "$(CCSQL) creates stored procedure $(ILELIB).DB2PROCJR(clob) result set."
	@echo "$(CCSQL) creates stored procedure $(ILELIB).DB2PROCJH(clob) result set plus EOL hack (DEADBEEF)."
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
	@echo "#endif /* _ICONF_HH */" >> iconf.h
### -- create stored procedures (iPLUG512K, etc.)
crtsqlproc:
	$(CCSQL) -f $(SQLTPL) -r $(SQLRPL)
clean:
	rm -f $(SP400SRVPGM)
	rm -f *.mod
	rm -f *.modsql
removeo:
	rm -f *.mod
	rm -f *.modsql

