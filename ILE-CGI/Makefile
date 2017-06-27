### Compile (Makefile)
### > export CHROOT=/path/chroot
### > make cgi
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

### *PGM CGI
CGI400PGM  = db2json.pgm
CGI400OBJS = db2json.mod

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help:
	@echo "------------------------------------------------------------"
	@echo "'$(MAKE) xxx' where xxx = cgi, mylib"
	@echo "'> export CHROOT=/path/chroot'"
	@echo "'> make cgi'  where ILELIB=DB2JSON"
	@echo "'-- or --"
	@echo "'> export CHROOT=/path/chroot'"
	@echo "'> make ILELIB=ANYLIB mylib'"
	@echo "------------------------------------------------------------"
### tells make all things to do (ordered)
cgi:
	@$(MAKE) ILELIB=DB2JSON go
mylib:
	@$(MAKE) go
go: mkinc removeo $(CGI400PGM)

.SUFFIXES: .mod .c
### CRTRPGMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- CGI400PGM (ILE c)
$(CGI400PGM): $(CGI400OBJS)
	$(CCPGM) --pgm $(CGI400PGM) --lib $(ILELIB) --mod $(CGI400OBJS) --option "BNDSRVPGM(QHTTPSVR/QZSRCORE)"


mkinc:
	@echo "#ifndef _ICONF_H" > iconf.h
	@echo "#define _ICONF_H" >> iconf.h
	@echo "#define DB2_MAX_JSON_OUT 512000" >> iconf.h
	@echo "#define DB2_ARG0_PGM \"/QOpenSys/usr/lib/start32\"" >> iconf.h
	@echo "#define DB2_ENV_PATH \"PATH=$(INSTALLBIN):/usr/bin\"" >> iconf.h
	@echo "#define DB2_ENV_LIBPATH \"LIBPATH=$(CHROOT)$(INSTALLDIR):$(INSTALLDIR):/usr/lib\"" >> iconf.h
	@echo "#define DB2_ENV_ATTACH \"PASE_THREAD_ATTACH=Y\"" >> iconf.h
	@echo "#define DB2_ENV_TRACE \"TRACE=off\"" >> iconf.h
	@echo "#define DB2_FILE_LIBDB400 \"libdb400.a(shr.o)\"" >> iconf.h
	@echo "#define DB2_SYM_SQL400JSON \"SQL400Json\"" >> iconf.h
	@echo "#endif /* _ICONF_HH */" >> iconf.h
clean:
	rm -f $(CGI400PGM)
	rm -f *.mod
removeo:
	rm -f *.mod

