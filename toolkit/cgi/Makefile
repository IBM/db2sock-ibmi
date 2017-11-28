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
help: speakile helpile
cgi: speakile mkinc removeo $(CGI400PGM)

.SUFFIXES: .mod .c
### CRTCMOD
.c.mod:
	$(CCC) --lib $(ILELIB) -g --src $<
### -- CGI400PGM (ILE c)
$(CGI400PGM): $(CGI400OBJS)
	$(CCPGM) --pgm $(CGI400PGM) --lib $(ILELIB) --mod $(CGI400OBJS) --option "BNDSRVPGM($(ILELIB)/JSON400 $(ILELIB)/TKIT400)"

speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE $(CGI400PGM) CGI toolkit call."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(CGI400PGM)"
helpile:
	@echo "> export CHROOT=/path/chroot"
	@echo "> export ILELIB=DB2JSON"
	@echo "> $(MAKE) cgi"
	@echo "------------------------------------------------------------"
mkinc:
	@echo "#ifndef _ICONF_H" > iconf.h
	@echo "#define _ICONF_H" >> iconf.h
	@echo "#define ILELIB \"$(ILELIB)\"" >> iconf.h
	@echo "#endif /* _ICONF_HH */" >> iconf.h
clean:
	rm -f $(CGI400PGM)
	rm -f *.mod
removeo:
	rm -f *.mod

