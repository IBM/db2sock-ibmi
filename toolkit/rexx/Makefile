### Compile (Makefile)
### > export CHROOT=/path/chroot
### > make rexx
### > make ILELIB=ANYLIB mylib
### Assumes borgi command and utilities
### https://bitbucket.org/litmis/borgi
###

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakile helpile
rexx: speakile cpyrexx

speakile:
	@echo "------------------------------------------------------------"
	@echo "ILE $(CGI400PGM) CMD rexx toolkit call."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
	@echo "build $(CGI400PGM)"
helpile:
	@echo "> export CHROOT=/path/chroot"
	@echo "> export ILELIB=DB2JSON"
	@echo "> $(MAKE) rexx"
	@echo "------------------------------------------------------------"
cpyrexx:
	dltf --lib $(ILELIB) --file QREXSRC
	crtsrcpf --lib $(ILELIB) --file QREXSRC --option "RCDLEN(92) MBR(*NONE) TEXT('rexx')"
	cpyfrmstmf --from cmdio.rexx --to /qsys.lib/$(ILELIB).lib/QREXSRC.file/CMDIO.mbr --option "STMFCCSID(819) DBFCCSID(37)"

