### Compile (Makefile)
### > make tgt32
### > make tgt64
### > make install
### > make tgt32 tgt64 install
### gcc options (Makefile)
### -v            - verbose compile
### -Wl,-bnoquiet - verbose linker
### -shared       - shared object
### -maix64       - 64bit
### -isystem      - compile PASE system headers
### -nostdlib     - remove libgcc_s.a and crtcxa_s.o
### ar options (Makefile)
### -X32_64       - 32bit or 64bit

###  install
INSTALLDIR   = /QOpenSys/usr/lib
 
CC          = gcc
CCFLAGS32   = -g -Wno-int-to-pointer-cast -Wno-pointer-to-int-cast
CCFLAGS64   = $(CCFLAGS32) -maix64 -DTGT64
AR          = ar
AROPT       = -X32_64
INCLUDEPATH = -isystem /QOpenSys/usr/include -I. -I.. -I../../db2/. -I../../toolkit/.

###  shared lib
LIBCRT32     = /QOpenSys/usr/lib/crt0.o
LIBCRT64     = /QOpenSys/usr/lib/crt0_64.o
LIBDEPSALL   = -L/QOpenSys/usr/lib -nostdlib -ldb400 -lpthreads -lc -liconv -ldl -lpthread
LIBDEPS32    = $(LIBDEPSALL) $(LIBCRT32)
LIBDEPS64    = $(LIBDEPSALL) $(LIBCRT64) -maix64

### tests
TEST0000     = test0000_resource_array
TEST0001     = test0001_error
TEST0011     = test0011_resource_array_async_callback
TEST0012     = test0012_resource_array_async_join
TEST0020     = test0020_db2_non_utf
TEST0100     = test0100_outjson_garbage_buffer
TEST1000     = test1000_sql400json
TEST1010     = test1010_jsonloop
TEST2000     = test2000_sql400json_async
TEST3000     = test3000_sql400json_memory
TEST4000     = test4000_sql400json_procj
TEST5000     = test5000_sql400json_procjr
TEST6000     = test6000_sql400json_procb
TEST7000     = test7000_sql400json_procbr
TEST9999     = test9999_driver_version

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help
help: speakpase helppase
tgt64:
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" LIBDEPS="$(LIBDEPS64)" BIT="64" go
tgt32:
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" LIBDEPS="$(LIBDEPS32)" BIT="32" go
go: speakpase $(TEST0000)$(BIT) \
	$(TEST0011)$(BIT) \
	$(TEST0012)$(BIT) \
	$(TEST0020)$(BIT) \
	$(TEST0100)$(BIT) \
	$(TEST1000)$(BIT) \
	$(TEST1010)$(BIT) \
	$(TEST2000)$(BIT) \
	$(TEST3000)$(BIT) \
	$(TEST4000)$(BIT) \
	$(TEST5000)$(BIT) \
	$(TEST6000)$(BIT) \
	$(TEST7000)$(BIT) \
	$(TEST9999)$(BIT) \
	clean

### generic rules
### (note: .c.o compiles all c parts in OBJS list)
.SUFFIXES: .o .c
.c.o:
	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<

### -- tests
$(TEST0000)$(BIT): $(TEST0000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0000).o -o $(TEST0000)$(BIT)
$(TEST0011)$(BIT): $(TEST0011).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0011).o -o $(TEST0011)$(BIT)
$(TEST0012)$(BIT): $(TEST0012).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0012).o -o $(TEST0012)$(BIT)
$(TEST0020)$(BIT): $(TEST0020).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0020).o -o $(TEST0020)$(BIT)
$(TEST0100)$(BIT): $(TEST0100).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0100).o -o $(TEST0100)$(BIT)
$(TEST1000)$(BIT): $(TEST1000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1000).o -o $(TEST1000)$(BIT)
$(TEST1010)$(BIT): $(TEST1010).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1010).o -o $(TEST1010)$(BIT)
$(TEST2000)$(BIT): $(TEST2000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST2000).o -o $(TEST2000)$(BIT)
$(TEST3000)$(BIT): $(TEST3000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST3000).o -o $(TEST3000)$(BIT)
$(TEST4000)$(BIT): $(TEST4000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST4000).o -o $(TEST4000)$(BIT)
$(TEST5000)$(BIT): $(TEST5000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST5000).o -o $(TEST5000)$(BIT)
$(TEST6000)$(BIT): $(TEST6000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST6000).o -o $(TEST6000)$(BIT)
$(TEST7000)$(BIT): $(TEST7000).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST7000).o -o $(TEST7000)$(BIT)
$(TEST9999)$(BIT): $(TEST9999).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST9999).o -o $(TEST9999)$(BIT)

speakpase:
	@echo "------------------------------------------------------------"
	@echo "PASE c tests for db2 and toolkit $(BIT)."
	@echo "CHROOT $(CHROOT)"
	@echo "ILELIB $(ILELIB)"
helppase:
	@echo "> $(MAKE) tgt32"
	@echo "> $(MAKE) tgt64"
	@echo "> $(MAKE) tgt32 tgt64"
	@echo "------------------------------------------------------------"
clean:
	rm -f *.o

