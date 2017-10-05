# description: Generate db2proc.h
# command:     python gen.py

# ===============================================
# header by ref
# ===============================================
byref_proto_h = ""
byref_proto_h += '#define ICALL_MAX_RETURN 3000000' + "\n"
byref_proto_h += 'typedef struct bighole_struct {' + "\n"
byref_proto_h += '  char hole[ICALL_MAX_RETURN];' + "\n"
byref_proto_h += '} bighole_t;' + "\n"

# ===============================================
# pgm c includes
# ===============================================
file_incl_c = '#include <miptrnam.h>'  + "\n"
file_incl_c += '#include <miptrnam.h>'  + "\n"
file_incl_c += '#include <mih/rslvsp.h>'  + "\n"
file_incl_c += '#include <mih/miobjtyp.h>'  + "\n"
file_incl_c += '#include <leawi.h>'  + "\n"
file_incl_c += '#include <qleawi.h>'  + "\n"
file_incl_c += '#include <stdlib.h>'  + "\n"
file_incl_c += '#include <sys/types.h>'  + "\n"
file_incl_c += '#include <stdio.h>'  + "\n"
file_incl_c += '#include <unistd.h>'  + "\n"
file_incl_c += '#include <string.h>'  + "\n"
file_incl_c += '#include <qtqiconv.h>'  + "\n"
file_incl_c += '#include <qp2user.h>'  + "\n"
file_incl_c += '#include <except.h>'  + "\n"
file_incl_c += '#include "../toolkit-base/PaseTool.h"' + "\n"
file_incl_c += '#include "iconf.h" /* see Makefile */' + "\n"

# ===============================================
# pgm by ref
# ===============================================

x_beg = 0
x_end = 32
for z in range(1, 6):
  strz = str(z)
  pgm_c_byref = ""
  for x in range(x_beg, x_end):
    strx = str(x)
    pgm_c_byref += "\n"
    pgm_c_byref += '#pragma datamodel(p128)'  + "\n"
    pgm_c_byref += 'typedef void (os_pgm_'+strx+'_t)'  + "\n" 
    pgm_c_byref += '('  + "\n"
    isSpace = 1
    for i in range(1, x+1):
      isSpace = 0
      stri = str(i)
      pgm_c_byref += 'char * p'+stri
      if i < x:
        pgm_c_byref += ', '
      if i % 7 == 0:
        isSpace = 1
        pgm_c_byref += "\n"
    if isSpace == 0:
      pgm_c_byref += "\n"
    pgm_c_byref += ');'  + "\n"
    pgm_c_byref += '#pragma linkage(os_pgm_'+strx+'_t,OS)'  + "\n"
    pgm_c_byref += '#pragma datamodel(pop)'  + "\n"
    pgm_c_byref += 'void iCallPgmByRef'+strx+'(ile_pgm_call_t* layout, char * myPgm, char * myLib);'  + "\n"
  for x in range(x_beg, x_end):
    strx = str(x)
    pgm_c_byref += "\n"
    pgm_c_byref += 'void iCallPgmByRef'+strx+'(ile_pgm_call_t* layout, char * myPgm, char * myLib)'  + "\n"
    pgm_c_byref += '{'  + "\n"
    pgm_c_byref += '  os_pgm_'+strx+'_t *os_pfct_ptr = rslvsp(_Program, myPgm, myLib, _AUTH_OBJ_MGMT);'  + "\n"
    pgm_c_byref += '  os_pfct_ptr('  + "\n"
    pgm_c_byref += '    '
    isSpace = 1
    for i in range(1, x+1):
      isSpace = 0
      stri = str(i-1)
      pgm_c_byref += 'layout->argv['+stri+']'
      if i < x:
        pgm_c_byref += ', '
      if i % 7 == 0:
        isSpace = 1
        pgm_c_byref += "\n    "
    if isSpace == 0:
      pgm_c_byref += "\n"
      pgm_c_byref += '    );'  + "\n"
    else:
      pgm_c_byref += ');'  + "\n"
    pgm_c_byref += '}'  + "\n"
  pgm_c_byref += "\n"
  pgm_c_byref += 'void iCallPgmByRefSub'+strz+'(ile_pgm_call_t* layout, char * myPgm, char * myLib)'  + "\n"
  byref_proto_h += 'void iCallPgmByRefSub'+strz+'(ile_pgm_call_t* layout, char * myPgm, char * myLib);'  + "\n"
  pgm_c_byref += '{'  + "\n"
  pgm_c_byref += '  switch(layout->argc) {'  + "\n"
  for i in range(x_beg, x_end):
    stri = str(i)
    pgm_c_byref += '  case '+stri+':'  + "\n"
    pgm_c_byref += '    iCallPgmByRef'+stri+'(layout, myPgm, myLib);'  + "\n"
    pgm_c_byref += '    break;'  + "\n"
  pgm_c_byref += '  default:'  + "\n"
  pgm_c_byref += '    break;'  + "\n"
  pgm_c_byref += '  }'  + "\n"
  pgm_c_byref += '}'  + "\n"
  # write
  file_ibyref_c = file_incl_c
  file_ibyref_c += '#include "ibyref.h"' + "\n"
  file_ibyref_c += pgm_c_byref
  with open("ibyrefp"+strz+".c", "w") as text_file:
    text_file.write(file_ibyref_c)
  x_beg += 32
  x_end += 32
  
 
# ===============================================
# srvpgm by ref
# ===============================================
x_beg = 0
x_end = 32
for z in range(1, 6):
  strz = str(z)
  srvpgm_c_byref = ""
  for x in range(x_beg, x_end):
    strx = str(x)
    srvpgm_c_byref += "\n"
    srvpgm_c_byref += 'typedef bighole_t (os_fct_'+strx+'_t)' + "\n"
    srvpgm_c_byref += '(' + "\n"
    isSpace = 1
    for i in range(1, x+1):
      isSpace = 0
      stri = str(i)
      srvpgm_c_byref += 'char * p'+stri
      if i < x:
        srvpgm_c_byref += ', '
      if i % 7 == 0:
        isSpace = 1
        srvpgm_c_byref += "\n"
    if isSpace == 0:
      srvpgm_c_byref += "\n"
    srvpgm_c_byref += ');' + "\n"
  for x in range(x_beg, x_end):
    strx = str(x)
    srvpgm_c_byref += "\n"
    srvpgm_c_byref += 'bighole_t iCallFctByRef'+strx+'(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)' + "\n"
    srvpgm_c_byref += '{' + "\n"
    srvpgm_c_byref += '  void *os_pfct_ptr = NULL;' + "\n"
    srvpgm_c_byref += '  os_fct_'+strx+'_t *os_fct_ptr = NULL;' + "\n"
    srvpgm_c_byref += '  _SYSPTR os_pgm_ptr = NULL;' + "\n"
    srvpgm_c_byref += '  unsigned long long os_act_mark = 0;' + "\n"
    srvpgm_c_byref += '  int os_obj_type = 0;' + "\n"
    srvpgm_c_byref += '  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);' + "\n"
    srvpgm_c_byref += '  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);' + "\n"
    srvpgm_c_byref += '  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);' + "\n"
    srvpgm_c_byref += '  return os_fct_ptr(' + "\n"
    srvpgm_c_byref += '    '
    isSpace = 1
    for i in range(1, x+1):
      isSpace = 0
      stri = str(i-1)
      srvpgm_c_byref += 'layout->argv['+stri+']'
      if i < x:
        srvpgm_c_byref += ', '
      if i % 7 == 0:
        isSpace = 1
        srvpgm_c_byref += "\n    "
    if isSpace == 0:
      srvpgm_c_byref += "\n"
      srvpgm_c_byref += '    );'  + "\n"
    else:
      srvpgm_c_byref += ');'  + "\n"
    srvpgm_c_byref += '}' + "\n"
  srvpgm_c_byref += "\n"
  srvpgm_c_byref += 'bighole_t iCallFctByRefSub'+strz+'(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)' + "\n"
  byref_proto_h += 'bighole_t iCallFctByRefSub'+strz+'(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc);' + "\n"
  srvpgm_c_byref += '{'  + "\n"
  srvpgm_c_byref += '  bighole_t bighole;'  + "\n"
  srvpgm_c_byref += '  switch(layout->argc) {'  + "\n"
  for i in range(x_beg, x_end):
    stri = str(i)
    srvpgm_c_byref += '  case '+stri+':'  + "\n"
    srvpgm_c_byref += '    bighole = iCallFctByRef'+stri+'(layout, myPgm, myLib, myFunc, lenFunc);' + "\n"
    srvpgm_c_byref += '    break;'  + "\n"
  srvpgm_c_byref += '  default:'  + "\n"
  srvpgm_c_byref += '    break;'  + "\n"
  srvpgm_c_byref += '  }'  + "\n"
  srvpgm_c_byref += '  return bighole;'  + "\n"
  srvpgm_c_byref += '}'  + "\n"
  file_ibyref_c = file_incl_c
  file_ibyref_c += '#include "ibyref.h"' + "\n"
  file_ibyref_c += srvpgm_c_byref
  with open("ibyrefs"+strz+".c", "w") as text_file:
    text_file.write(file_ibyref_c)
  x_beg += 32
  x_end += 32

# ===============================================
# header by ref
# ===============================================
file_ibref_h = '#ifndef _I_BY_REF_H' + "\n"
file_ibref_h += '#define _I_BY_REF_H' + "\n"
file_ibref_h += byref_proto_h
file_ibref_h += '#endif /*_I_BY_REF_H*/' + "\n"
with open("ibyref.h", "w") as text_file:
  text_file.write(file_ibref_h)

