# description: Generate xlcmakefile
# command:     python genmake.py
import glob
test_pgms = glob.glob("test*.c")
test_pgms.sort()

test_var_all = 'all: cpy $(SHRLIB)'
test_var_dcl = ""
test_var_32 = ""
test_var_64 = ""
test_var_go = ""
for name in test_pgms:
  noext = name.split(".")
  line = noext[0]
  test = line.split("test")
  parts = test[1].split("_")
  nbr = parts[0]

  test_var_all += ' $(' + 'TEST' + nbr + 'PGM)'

  test_var_dcl += '### TEST' + nbr + "\n"
  test_var_dcl += 'TEST' + nbr + 'PGM32      = ' + line + '_32' + "\n"
  test_var_dcl += 'TEST' + nbr + 'LIBOBJS32  = ' + line + '.o' + "\n"
  test_var_dcl += 'TEST' + nbr + 'LIBDEPS32  = $(LIBDEPALL) -llang400' + "\n"
  test_var_dcl += 'TEST' + nbr + 'PGM64      = ' + line + '_64' + "\n"
  test_var_dcl += 'TEST' + nbr + 'LIBOBJS64  = $(TEST' + nbr + 'LIBOBJS32)' + "\n"
  test_var_dcl += 'TEST' + nbr + 'LIBDEPS64  = $(LIBDEPALL) -llang400' + "\n"

  test_var_64 += 'TEST' + nbr + 'PGM        = $(TEST' + nbr + 'PGM64)' + "\n"
  test_var_64 += 'TEST' + nbr + 'LIBOBJS    = $(TEST' + nbr + 'LIBOBJS64)' + "\n"
  test_var_64 += 'TEST' + nbr + 'LIBDEPS    = $(TEST' + nbr + 'LIBDEPS64)' + "\n"

  test_var_32 += 'TEST' + nbr + 'PGM        = $(TEST' + nbr + 'PGM32)' + "\n"
  test_var_32 += 'TEST' + nbr + 'LIBOBJS    = $(TEST' + nbr + 'LIBOBJS32)' + "\n"
  test_var_32 += 'TEST' + nbr + 'LIBDEPS    = $(TEST' + nbr + 'LIBDEPS32)' + "\n"

  test_var_go += '### -- ' + line + '_32/64' + "\n"
  test_var_go += '$(TEST' + nbr + 'PGM32): $(TEST' + nbr + 'LIBOBJS)' + "\n"
  test_var_go += '	$(CC) $(CCFLAGS) $(TEST' + nbr + 'LIBOBJS) $(TEST' + nbr + 'LIBDEPS) -o $(TEST' + nbr + 'PGM32)' + "\n"
  test_var_go += '$(TEST' + nbr + 'PGM64): $(TEST' + nbr + 'LIBOBJS)' + "\n"
  test_var_go += '	$(CC) $(CCFLAGS) $(TEST' + nbr + 'LIBOBJS) $(TEST' + nbr + 'LIBDEPS) -o $(TEST' + nbr + 'PGM64)' + "\n"

test_var_all += "\n"

test_make  = '### make' + "\n"
test_make += '### make TGT64=64' + "\n"
test_make += 'CC                 = cc' + "\n"
test_make += 'CCFLAGS32          = -g' + "\n"
test_make += 'CCFLAGS64          = $(CCFLAGS32) -q64' + "\n"
test_make += 'AR                 = ar' + "\n"
test_make += 'AROPT              = -X32_64' + "\n"
test_make += 'INCLUDEPATH        = -I. -I/usr/include -I..' + "\n"
test_make += 'LIBDEPALL          = -L. -lpthreads -liconv -ldl -lpthread -ldb400' + "\n"
test_make += '' + "\n"
test_make += '###  shared lib' + "\n"
test_make += 'LIBOBJS            = LangCommon.o' + "\n"
test_make += 'LIBEXPS            = -bE:liblang400.exp' + "\n"
test_make += 'LIBSHR32           = liblang400.a' + "\n"
test_make += 'LIBOBJ32           = shr.o' + "\n"
test_make += 'LIBDEPS32          = $(LIBDEPALL) -bM:SRE -bnoentry' + "\n"
test_make += 'LIBSHR64           = liblang400_64.a' + "\n"
test_make += 'LIBOBJ64           = shr_64.o' + "\n"
test_make += 'LIBDEPS64          = $(LIBDEPS32)' + "\n"
test_make += '' + "\n"
test_make += test_var_dcl
test_make += '' + "\n"
test_make += '### make TGT64=64' + "\n"
test_make += 'ifdef TGT64' + "\n"
test_make += 'CCFLAGS            = $(CCFLAGS64)' + "\n"
test_make += 'SHRLIB             = $(LIBSHR32)' + "\n"
test_make += 'SHROBJ             = $(LIBOBJ64)' + "\n"
test_make += 'LIBDEPS            = $(LIBDEPS64)' + "\n"
test_make += test_var_64
test_make += '### make (32)' + "\n"
test_make += 'else' + "\n"
test_make += 'CCFLAGS            = $(CCFLAGS32)' + "\n"
test_make += 'SHRLIB             = $(LIBSHR32)' + "\n"
test_make += 'SHROBJ             = $(LIBOBJ32)' + "\n"
test_make += 'LIBDEPS            = $(LIBDEPS32)' + "\n"
test_make += test_var_32
test_make += 'endif' + "\n"
test_make += '' + "\n"
test_make += '### tells make all things to do (ordered)' + "\n"
test_make += test_var_all
test_make += '' + "\n"
test_make += '### generic rules' + "\n"
test_make += '### (note: .c.o compiles all c parts in OBJS list)' + "\n"
test_make += '.SUFFIXES: .o .c' + "\n"
test_make += '.c.o:' + "\n"
test_make += '	$(CC) $(CCFLAGS) $(INCLUDEPATH) -c $<' + "\n"
test_make += '' + "\n"
test_make += '### -- Build the shared lib(s).' + "\n"
test_make += '$(SHROBJ): $(LIBOBJS)' + "\n"
test_make += '	$(CC) $(CCFLAGS) $(LIBOBJS) $(LIBEXPS) $(LIBDEPS) -o$(SHROBJ)' + "\n"
test_make += '$(SHRLIB): $(SHROBJ)' + "\n"
test_make += '	$(AR) $(AROPT) ruv $(SHRLIB) $(SHROBJ)' + "\n"
test_make += '' + "\n"
test_make += test_var_go
test_make += '' + "\n"
test_make += 'cpy:' + "\n"
test_make += '	cp ../libdb400.a .' + "\n"
test_make += '' + "\n"
with open("xlcmakefile", "w") as text_file:
    text_file.write(test_make)

