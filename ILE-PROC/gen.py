# description: Generate db2proc.h
# command:     python gen.py

byall_header = "ibyref.h"

byref_max_files = 6
byref_max_funcs = 32
byref_prefix_pgm = "ibyrefp"
byref_prefix_srvpgm = "ibyrefs"

byval_max_args = 8
byval_prefix_srvpgm = "ibyvals"

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
x_end = byref_max_funcs
for z in range(1, byref_max_files):
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
  file_ibyref_c += '#include "' + byall_header + '"' + "\n"
  file_ibyref_c += pgm_c_byref
  with open(byref_prefix_pgm+strz+".c", "w") as text_file:
    text_file.write(file_ibyref_c)
  x_beg += byref_max_funcs
  x_end += byref_max_funcs
  
 
# ===============================================
# srvpgm by ref
# ===============================================
x_beg = 0
x_end = byref_max_funcs
for z in range(1, byref_max_files):
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
  srvpgm_c_byref += '  switch(layout->argc) {'  + "\n"
  for i in range(x_beg, x_end):
    stri = str(i)
    srvpgm_c_byref += '  case '+stri+':'  + "\n"
    srvpgm_c_byref += '    return iCallFctByRef'+stri+'(layout, myPgm, myLib, myFunc, lenFunc);' + "\n"
    srvpgm_c_byref += '    break;'  + "\n"
  srvpgm_c_byref += '  default:'  + "\n"
  srvpgm_c_byref += '    break;'  + "\n"
  srvpgm_c_byref += '  }'  + "\n"
  srvpgm_c_byref += '}'  + "\n"
  file_ibyref_c = file_incl_c
  file_ibyref_c += '#include "' + byall_header + '"' + "\n"
  file_ibyref_c += srvpgm_c_byref
  with open(byref_prefix_srvpgm+strz+".c", "w") as text_file:
    text_file.write(file_ibyref_c)
  x_beg += byref_max_funcs
  x_end += byref_max_funcs


# ===============================================
# srvpgm by value
# ===============================================
def func_by_val(pattern):
  srvpgm_c_byval = ""
  srvpgm_c_byval += "\n"
  srvpgm_c_byval += 'bighole_t iCallFctByVal'+pattern+'(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)' + "\n"
  srvpgm_c_byval += '{' + "\n"
  srvpgm_c_byval += '  void *os_pfct_ptr = NULL;' + "\n"
  # proto
  srvpgm_c_byval += '  typedef bighole_t (os_fct_'+pattern+'_t)();' + "\n"
  # end proto
  srvpgm_c_byval += '  os_fct_'+pattern+'_t *os_fct_ptr = NULL;' + "\n"
  srvpgm_c_byval += '  _SYSPTR os_pgm_ptr = NULL;' + "\n"
  srvpgm_c_byval += '  unsigned long long os_act_mark = 0;' + "\n"
  srvpgm_c_byval += '  int os_obj_type = 0;' + "\n"
  srvpgm_c_byval += '  int argc = 0;' + "\n"
  srvpgm_c_byval += '  int one_len = 0; /* all value elements must be same size (yuck) */' + "\n"
  # variable
  isVal = 0
  i = 0
  for c in list(pattern):
    strp = str(i)
    if c == '0':
      srvpgm_c_byval += '  char * ptr'+strp+' = NULL;' + "\n"
    else:
      srvpgm_c_byval += '  fool16_t * val16t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool15_t * val15t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool14_t * val14t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool13_t * val13t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool12_t * val12t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool11_t * val11t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool10_t * val10t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool9_t * val9t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool8_t * val8t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool7_t * val7t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool6_t * val6t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool5_t * val5t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool4_t * val4t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool3_t * val3t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool2_t * val2t'+strp+' = NULL;' + "\n"
      srvpgm_c_byval += '  fool1_t * val1t'+strp+' = NULL;' + "\n"
      isVal = 1
    i += 1
  srvpgm_c_byval += '  os_pgm_ptr = rslvsp(WLI_SRVPGM, myPgm, myLib, _AUTH_OBJ_MGMT);' + "\n"
  srvpgm_c_byval += '  os_act_mark = QleActBndPgmLong(&os_pgm_ptr, NULL, NULL, NULL, NULL);' + "\n"
  srvpgm_c_byval += '  os_fct_ptr = QleGetExpLong(&os_act_mark, 0, &lenFunc, myFunc, (void **)&os_pfct_ptr, &os_obj_type, NULL);' + "\n"
  # assign
  argc = 0
  i = 0
  for c in list(pattern):
    strp = str(i)
    if c == '0':
      strc = str(argc)
      srvpgm_c_byval += '  ptr'+strp+' = layout->argv[iNextArgv(layout, '+strc+')];' + "\n"
      argc += 1
    else:
      srvpgm_c_byval += '  one_len = layout->arg_len['+strp+'];' + "\n"
      srvpgm_c_byval += '  val1t'+strp+'  = (fool1_t *) ((char *)layout + layout->arg_pos['+strp+']);' + "\n"
      srvpgm_c_byval += '  val2t'+strp+'  = (fool2_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val3t'+strp+'  = (fool3_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val4t'+strp+'  = (fool4_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val9t'+strp+'  = (fool9_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val5t'+strp+'  = (fool5_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val6t'+strp+'  = (fool6_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val7t'+strp+'  = (fool7_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val8t'+strp+'  = (fool8_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val9t'+strp+'  = (fool9_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val10t'+strp+' = (fool10_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val11t'+strp+' = (fool11_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val12t'+strp+' = (fool12_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val13t'+strp+' = (fool13_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val14t'+strp+' = (fool14_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val15t'+strp+' = (fool15_t *) val1t'+strp+';' + "\n"
      srvpgm_c_byval += '  val16t'+strp+' = (fool16_t *) val1t'+strp+';' + "\n"
    i += 1
  # function call (all by ref)
  if isVal == 0:
    srvpgm_c_byval += '  return os_fct_ptr(' + "\n"
    srvpgm_c_byval += '    '
    isSpace = 1
    i = 1
    x = len(pattern)
    for c in list(pattern):
      isSpace = 0
      stri = str(i-1)
      if c == '0':
        srvpgm_c_byval += 'ptr'+stri
      else:
        srvpgm_c_byval += '*val'+strw+'t'+stri
      if i < x:
        srvpgm_c_byval += ', '
      if i % 7 == 0:
        isSpace = 1
        srvpgm_c_byval += "\n    "
      i += 1
    if isSpace == 0:
      srvpgm_c_byval += "\n"
      srvpgm_c_byval += '    );'  + "\n"
    else:
      srvpgm_c_byval += ');'  + "\n"
    # end function call
    srvpgm_c_byval += '}' + "\n"
    return srvpgm_c_byval
  # function call (at least one by val)
  srvpgm_c_byval += '  switch(one_len) {' + "\n"
  for w in range(1,17):
    strw = str(w)
    srvpgm_c_byval += '  case '+strw+': return os_fct_ptr(' + "\n"
    srvpgm_c_byval += '    '
    isSpace = 1
    i = 1
    x = len(pattern)
    for c in list(pattern):
      isSpace = 0
      stri = str(i-1)
      if c == '0':
        srvpgm_c_byval += 'ptr'+stri
      else:
        srvpgm_c_byval += '*val'+strw+'t'+stri
      if i < x:
        srvpgm_c_byval += ', '
      if i % 7 == 0:
        isSpace = 1
        srvpgm_c_byval += "\n    "
      i += 1
    if isSpace == 0:
      srvpgm_c_byval += "\n"
      srvpgm_c_byval += '    );'  + "\n"
    else:
      srvpgm_c_byval += ');'  + "\n"
  srvpgm_c_byval += '  }' + "\n"
  # end function call
  srvpgm_c_byval += '}' + "\n"
  return srvpgm_c_byval

def case_by_val(pattern):
  srvpgm_c_byval = ""
  srvpgm_c_byval += '  if (!strcmp(pattern,"'+pattern+'")) {'  + "\n"
  srvpgm_c_byval += '    return iCallFctByVal'+pattern+'(layout, myPgm, myLib, myFunc, lenFunc);' + "\n"
  srvpgm_c_byval += '  }'  + "\n"
  return srvpgm_c_byval


# pattern generator
def perms(n, what):
  p = ""
  if not n:
    return p
  for i in xrange(2**n):
    s = bin(i)[2:]
    s = "0" * (n-len(s)) + s
    # print s
    if "func" in what:
      p += func_by_val(s)
    elif "case" in what:
      p += case_by_val(s)
  return p

# call
byval_proto_h = ""
byval_proto_h += 'typedef struct fool16 {char hole[16]; } fool16_t;' + "\n"
byval_proto_h += 'typedef struct fool15 {char hole[15]; } fool15_t;' + "\n"
byval_proto_h += 'typedef struct fool14 {char hole[14]; } fool14_t;' + "\n"
byval_proto_h += 'typedef struct fool13 {char hole[13]; } fool13_t;' + "\n"
byval_proto_h += 'typedef struct fool12 {char hole[12]; } fool12_t;' + "\n"
byval_proto_h += 'typedef struct fool11 {char hole[11]; } fool11_t;' + "\n"
byval_proto_h += 'typedef struct fool10 {char hole[10]; } fool10_t;' + "\n"
byval_proto_h += 'typedef struct fool9 {char hole[9]; } fool9_t;' + "\n"
byval_proto_h += 'typedef struct fool8 {char hole[8]; } fool8_t;' + "\n"
byval_proto_h += 'typedef struct fool7 {char hole[7]; } fool7_t;' + "\n"
byval_proto_h += 'typedef struct fool6 {char hole[6]; } fool6_t;' + "\n"
byval_proto_h += 'typedef struct fool5 {char hole[5]; } fool5_t;' + "\n"
byval_proto_h += 'typedef struct fool4 {char hole[4]; } fool4_t;' + "\n"
byval_proto_h += 'typedef struct fool3 {char hole[3]; } fool3_t;' + "\n"
byval_proto_h += 'typedef struct fool2 {char hole[2]; } fool2_t;' + "\n"
byval_proto_h += 'typedef struct fool1 {char hole[1]; } fool1_t;' + "\n"
byval_proto_h += 'static int iNextArgv(ile_pgm_call_t* layout, int argc)'  + "\n"
byval_proto_h += '{'  + "\n"
byval_proto_h += '  int i = 0;'  + "\n"
byval_proto_h += '  int j = 0;'  + "\n"
byval_proto_h += '  for (i=0; i < ILE_PGM_MAX_ARGS; i++) {'  + "\n"
byval_proto_h += '    if (layout->argv[i]) {'  + "\n"
byval_proto_h += '      if (j == argc) {'  + "\n"
byval_proto_h += '        return i;'  + "\n"
byval_proto_h += '      }'  + "\n"
byval_proto_h += '      j++;'  + "\n"
byval_proto_h += '    }'  + "\n"
byval_proto_h += '  }'  + "\n"
byval_proto_h += '  return 0;'  + "\n"
byval_proto_h += '}'  + "\n"
for z in range(1,byval_max_args+1):
  strz = str(z)
  myfile = byval_prefix_srvpgm + strz + ".c"
  byval_proto_h += 'bighole_t iCallFctByValSub'+strz+'(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern);' + "\n"
  srvpgm_c_byval = "";
  srvpgm_c_byval += perms(z, "func");
  srvpgm_c_byval += "\n"
  srvpgm_c_byval += 'bighole_t iCallFctByValSub'+strz+'(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc, char * pattern)' + "\n"
  srvpgm_c_byval += '{'  + "\n"
  srvpgm_c_byval += perms(z, "case");
  srvpgm_c_byval += '}'  + "\n"
  # print srvpgm_c_byval
  file_ibyval_c = file_incl_c
  file_ibyval_c += '#include "' + byall_header + '"' + "\n"
  file_ibyval_c += srvpgm_c_byval
  with open(myfile, "w") as text_file:
    text_file.write(file_ibyval_c)
      

# ===============================================
# header by ref
# ===============================================
file_ibref_h = '#ifndef _I_BY_REF_H' + "\n"
file_ibref_h += '#define _I_BY_REF_H' + "\n"
file_ibref_h += byref_proto_h
file_ibref_h += byval_proto_h
file_ibref_h += '#endif /*_I_BY_REF_H*/' + "\n"
with open(byall_header, "w") as text_file:
  text_file.write(file_ibref_h)

