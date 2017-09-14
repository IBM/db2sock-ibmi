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
INCLUDEPATH = -isystem /QOpenSys/usr/include -I. -I.. -I../toolkit-base/.

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
TEST1001     = test1001_json_select
TEST1011     = test1011_json_select_no_data_found
TEST1021     = test1021_json_null_data
TEST1200     = test1200_json_cmd
TEST1250     = test1250_json_pgm_rainbow
TEST1300     = test1300_json_pgm_hello
TEST1310     = test1310_json_srvpgm_hello
TEST1320     = test1320_json_srvpgm_hello_again
TEST1330     = test1330_json_srvpgm_hello_ds

### tells make all things to do (order)
# do this if given an invalid target
.DEFAULT:
	@$(MAKE) help

help:
	@echo "------------------------------------------------------------"
	@echo "'$(MAKE) xxx' where xxx = tgt32, tgt64, install"
	@echo "'> make tgt32'"
	@echo "'> make tgt64'"
	@echo "'> make install'"
	@echo "'> make tgt32 tgt64 install'"
	@echo "------------------------------------------------------------"

### tells make all things to do (ordered)
tgt64:
	@$(MAKE) CCFLAGS="$(CCFLAGS64)" LIBDEPS="$(LIBDEPS64)" BIT="64" go

tgt32:
	@$(MAKE) CCFLAGS="$(CCFLAGS32)" LIBDEPS="$(LIBDEPS32)" BIT="32" go

### tells make all things to do (ordered)
### go: $(TEST0000)$(BIT) \
### 	$(TEST0011)$(BIT) \
### 	$(TEST0012)$(BIT) \
### 	$(TEST1001)$(BIT) \
### 	$(TEST1011)$(BIT) \
### 	$(TEST1021)$(BIT) \
### 	$(TEST1200)$(BIT) \
### 	clean
go: $(TEST0000)$(BIT) \
	$(TEST0011)$(BIT) \
	$(TEST0012)$(BIT) \
	$(TEST1250)$(BIT) \
 	$(TEST1300)$(BIT) \
 	$(TEST1310)$(BIT) \
 	$(TEST1320)$(BIT) \
 	$(TEST1330)$(BIT) \
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
$(TEST0011)$(BIT): $(TEST0011).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0011).o -o $(TEST0011)$(BIT)
$(TEST0012)$(BIT): $(TEST0012).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST0012).o -o $(TEST0012)$(BIT)
$(TEST1001)$(BIT): $(TEST1001).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1001).o -o $(TEST1001)$(BIT)
$(TEST1011)$(BIT): $(TEST1011).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1011).o -o $(TEST1011)$(BIT)
$(TEST1021)$(BIT): $(TEST1021).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1021).o -o $(TEST1021)$(BIT)
$(TEST1200)$(BIT): $(TEST1200).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1200).o -o $(TEST1200)$(BIT)
$(TEST1250)$(BIT): $(TEST1250).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1250).o -o $(TEST1250)$(BIT)
$(TEST1300)$(BIT): $(TEST1300).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1300).o -o $(TEST1300)$(BIT)
$(TEST1310)$(BIT): $(TEST1310).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1310).o -o $(TEST1310)$(BIT)
$(TEST1320)$(BIT): $(TEST1320).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1320).o -o $(TEST1320)$(BIT)
$(TEST1330)$(BIT): $(TEST1330).o
	$(CC) $(CCFLAGS) $(LIBDEPS) $(TEST1330).o -o $(TEST1330)$(BIT)

clean:
	rm -f *.o

