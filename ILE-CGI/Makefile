### ./make_libdb400.sh
### gmake options (see make_libdb400.sh)
### - gmake -f Makefile
### ILE c compiles
### - INILIB      - ILE Library (see make_libdb400.sh)
### - INICHROOT   - chroot base path (see make_libdb400.sh)

### ILE
### CCRPG       = ./CRTRPGMOD
CCC         = ./CRTCMOD
CCPGM       = ./CRTPGM

### *PGM CGI - $(INILIB)/DB2JSON
CGI400PGM  = db2json.pgm
CGI400MOD  = $(INILIB)/db2json
CGI400OBJS = db2json.mod
CGI400MODS = $(INILIB)/db2json

### tells make all things to do (order)
$(info ==================)
$(info chroot base path INICHROOT=$(INICHROOT) (see make_libdb400.sh))
ifdef INILIB
$(info ILE library INILIB=$(INILIB) (see make_libdb400.sh))
else
$(error missing ILE library INILIB (see make_libdb400.sh))
endif
$(info ==================)
all: clean removeo cpy talkcgi $(CGI400PGM)

### ILE
### .SUFFIXES: .mod .rpgle
### .rpgle.mod:
### 	$(CCRPG) $(INILIB) $<
.SUFFIXES: .mod .c
.c.mod:
	$(CCC) $(INILIB) $<

### -- CGI400PGM (ILE c)
$(CGI400PGM): $(CGI400OBJS)
	$(CCPGM) $(CGI400MOD) $(CGI400MODS)

talkcgi:
	$(info ==================)
	$(info ILE CGI $(INILIB)/$(CGI400PGM))
	$(info ==================)
clean:
	rm -f $(CGI400PGM)
cpy:
	cp ../libdb400.a .
	cp ../system400 .
removeo:
	rm -f *.mod

