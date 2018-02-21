
# description: Generate PaseCliAsync_gen.c
# command:     python gen.py
PaseSqlCli_file = "./gen_cli_template.c"

# ===============================================
# utilities
# ===============================================

def parse_sizeme( st ):
   sz = '4'
   if 'SMALL' in st:
     sz = '2'
   elif '*' in st:
     sz = '4'     
   return sz

def parse_star( line ):
  v1 = ""
  v2 = ""
  v3 = ""
  # SQLRETURN * SQLFlinstone
  # 0           1
  split1 = line.split('*')
  if len(split1) > 1:
    v1 = split1[0]
    v2 = "*"
    v3 = split1[1]
  else:
    # SQLRETURN SQLRubble
    # 0         1
    split1 = line.split()
    v1 = split1[0]
    v2 = ""
    v3 = split1[1]
  return [v1.strip(),v2,v3.strip()]


def parse_method( line ):
  # SQLRETURN SQLPrimaryKeys(...)
  # ===func=================1
  split1 = line.split("(")
  func = split1[0]
  # (SQLHSTMT	    hstmt, SQLCHAR *	    szTableQualifier, ...)
  # 1================================argv========================2
  split2 = split1[1].split(")")
  argv = split2[0]
  # SQLRETURN SQLRubble
  # 0         1
  # SQLRETURN * SQLFlinstone
  # 0         1 2
  funcs = parse_star(func)
  # SQLHSTMT	    hstmt, SQLCHAR *	    szTableQualifier, ...
  #                      3                                  3
  split3 = argv.split(",")
  args = []
  for arg in split3:
    # SQLHSTMT hstmt
    # 0        1
    # SQLCHAR * szTableQualifier
    # 0       1 2
    args.append(parse_star(arg))
  return [funcs,args]

# ===============================================
# special processing CLI interfaces (unique gen)
# ===============================================


# SQLRETURN SQLAllocEnv ( SQLHENV * phenv );
def PaseCliAsync_c_main_SQLAllocEnv(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  if (sqlrc == SQL_SUCCESS) {" + "\n"
  c_main += "    init_table_ctor(*phenv, *phenv);" + "\n"
  c_main += "    custom_SQLSetEnvCCSID(*phenv, myccsid);" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLAllocConnect ( SQLHENV  henv, SQLHDBC * phdbc );
def PaseCliAsync_c_main_SQLAllocConnect(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  if (sqlrc == SQL_SUCCESS) {" + "\n"
  c_main += "    init_table_ctor(*phdbc, *phdbc);" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLAllocStmt ( SQLHDBC  hdbc, SQLHSTMT * phstmt );
def PaseCliAsync_c_main_SQLAllocStmt(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  if (sqlrc == SQL_SUCCESS) {" + "\n"
  c_main += "    init_table_ctor(*phstmt, hdbc);" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLAllocHandle ( SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd );
def PaseCliAsync_c_main_SQLAllocHandle(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  switch (htype) {" + "\n"
  c_main += "  case SQL_HANDLE_ENV:" + "\n"
  c_main += "    if (sqlrc == SQL_SUCCESS) {" + "\n"
  c_main += "      init_table_ctor(*ohnd, *ohnd);" + "\n"
  c_main += "      custom_SQLSetEnvCCSID(*ohnd, myccsid);" + "\n"
  c_main += "    }" + "\n"
  c_main += "    break;" + "\n"
  c_main += "  case SQL_HANDLE_DBC:" + "\n"
  c_main += "    if (sqlrc == SQL_SUCCESS) {" + "\n"
  c_main += "      init_table_ctor(*ohnd, *ohnd);" + "\n"
  c_main += "    }" + "\n"
  c_main += "    break;" + "\n"
  c_main += "  case SQL_HANDLE_STMT:" + "\n"
  c_main += "  case SQL_HANDLE_DESC:" + "\n"
  c_main += "    if (sqlrc == SQL_SUCCESS) {" + "\n"
  c_main += "      init_table_ctor(*ohnd, ihnd);" + "\n"
  c_main += "    }" + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLFreeEnv ( SQLHENV  henv );
def PaseCliAsync_c_main_SQLFreeEnv(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLFreeConnect ( SQLHDBC  hdbc );
def PaseCliAsync_c_main_SQLFreeConnect(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  int active = init_table_hash_active(hdbc, 0);" + "\n"
  c_main += "  /* persistent connect only close with SQL400pClose */" + "\n"
  c_main += "  if (active) {" + "\n"
  c_main += "    return SQL_ERROR;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_table_dtor(hdbc);" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLFreeStmt ( SQLHSTMT  hstmt, SQLSMALLINT  fOption );
def PaseCliAsync_c_main_SQLFreeStmt(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_table_dtor(hstmt);" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLFreeHandle ( SQLSMALLINT  htype, SQLINTEGER  hndl );
def PaseCliAsync_c_main_SQLFreeHandle(ile_or_custom_call, call_name, normal_db400_args):
  c_main = ""
  c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  c_main += "  int persistent = init_table_hash_active(hndl, 0);" + "\n"
  c_main += "  /* persistent connect only close with SQL400pClose */" + "\n"
  c_main += "  switch (htype) {" + "\n"
  c_main += "  case SQL_HANDLE_DBC:" + "\n"
  c_main += "    if (persistent) {" + "\n"
  c_main += "      return SQL_ERROR;" + "\n"
  c_main += "    }" + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_lock();" + "\n"
  c_main += "  switch(myccsid) {" + "\n"
  c_main += '  case 1208: /* UTF-8 */' + "\n"
  c_main += '  case 1200: /* UTF-16 */' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += '  default:' + "\n"
  c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  switch (htype) {" + "\n"
  c_main += "  case SQL_HANDLE_ENV:" + "\n"
  c_main += "    break;" + "\n"
  c_main += "  default:" + "\n"
  c_main += "    init_table_dtor(hndl);" + "\n"
  c_main += "    break;" + "\n"
  c_main += "  }" + "\n"
  c_main += "  init_unlock();" + "\n"
  # dump trace
  c_main += "  if (init_cli_trace()) {" + "\n"
  c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
  c_main += "  }" + "\n"
  return c_main

# SQLRETURN SQLDisconnect( SQLHDBC  hdbc )
def SQLDisconnect_check_persistent(hdbc_code, return_code, set_code):
  c_main = ""
  c_main += "  int persistent = init_table_hash_active(" + hdbc_code + ", 0);" + "\n"
  c_main += "  /* persistent connect only close with SQL400pClose */" + "\n"
  c_main += "  if (persistent) {" + "\n"
  c_main += "    " + set_code + "\n"
  c_main += "    " + return_code + "\n"
  c_main += "  }" + "\n"
  return c_main

# ===============================================
# non-utf (old libdb400.a)
# ===============================================
# SQL400IgnoreNullAnyToAny(hdbc, inparm, inlen, outparm, outlen, inccsid, outccsid)
# SQL400IgnoreNullAnyFromAny(hdbc, inparm, inlen, outparm, outlen, inccsid, outccsid)
def non_utf_copy_in():
  c_main = ""
  c_main += 'int non_utf_copy_in_hdbc(SQLHDBC	hdbc, SQLCHAR **tmp, SQLCHAR **src, SQLINTEGER srclen, SQLINTEGER maxlen) {' + "\n"
  c_main += '  SQLRETURN sqlrc1 = SQL_SUCCESS;' + "\n"
  c_main += '  int inccsid = init_CCSID400(0);' + "\n"
  c_main += '  int outccsid = init_job_CCSID400();' + "\n"
  c_main += '  SQLCHAR * inparm = *src;' + "\n"
  c_main += '  SQLINTEGER inlen = srclen;' + "\n"
  c_main += '  SQLCHAR * outparm = (SQLCHAR *) NULL;' + "\n"
  c_main += '  SQLINTEGER outlen = 0;' + "\n"
  c_main += '  if (inparm) {' + "\n"
  c_main += '    if (srclen == SQL_NTS) {' + "\n"
  c_main += '      inlen = strlen(inparm);' + "\n"
  c_main += '    }' + "\n"
  c_main += '    outlen = maxlen;' + "\n"
  c_main += '    outparm = (SQLCHAR *) malloc(outlen);' + "\n"
  c_main += '    memset(outparm,0,outlen);' + "\n"    
  c_main += '    sqlrc1 = SQL400IgnoreNullAnyToAny(hdbc, inparm, inlen,  outparm, outlen, inccsid, outccsid);' + "\n"
  c_main += '    outlen = strlen(outparm);' + "\n"    
  c_main += '  }' + "\n"
  c_main += '  *tmp = *src;' + "\n"    
  c_main += '  if (*src) {' + "\n"
  c_main += '    *src = outparm;' + "\n"    
  c_main += '  }' + "\n"
  c_main += '  return outlen;' + "\n"
  c_main += '}' + "\n"
  c_main += 'int non_utf_copy_in_hstmt(SQLHSTMT hstmt, SQLCHAR **tmp, SQLCHAR **src, SQLINTEGER srclen, SQLINTEGER maxlen) {' + "\n"
  c_main += '  SQLHDBC hdbc = init_table_stmt_2_conn(hstmt);' + "\n"
  c_main += '  return non_utf_copy_in_hdbc(hdbc, tmp, src, srclen, maxlen);' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_copy_in_free():
  c_main = ""
  c_main += 'void non_utf_copy_in_free(SQLCHAR **tmp, SQLCHAR **src) {' + "\n"
  c_main += '  char * trash = *src;' + "\n"
  c_main += '  *src = *tmp;' + "\n"
  c_main += '  if (trash) {' + "\n"
  c_main += '    free(trash);' + "\n"
  c_main += '    *tmp = NULL;' + "\n"
  c_main += '  }' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_copy_out():
  c_main = ""
  c_main += 'int non_utf_copy_out_hdbc(SQLHDBC	hdbc, SQLRETURN sqlrc, SQLCHAR *src, SQLINTEGER srclen) {' + "\n"
  c_main += '  SQLRETURN sqlrc1 = SQL_SUCCESS;' + "\n"
  c_main += '  int inccsid = init_CCSID400(0);' + "\n"
  c_main += '  int outccsid = init_job_CCSID400();' + "\n"
  c_main += '  SQLCHAR * inparm = src;' + "\n"
  c_main += '  SQLINTEGER inlen = srclen;' + "\n"
  c_main += '  SQLCHAR * outparm = (SQLCHAR *) NULL;' + "\n"
  c_main += '  SQLINTEGER outlen = 0;' + "\n"
  c_main += '  if (inparm && (inlen != SQL_NULL_DATA) && (sqlrc == SQL_SUCCESS || sqlrc == SQL_SUCCESS_WITH_INFO)) {' + "\n"
  c_main += '    outlen = inlen + 1;' + "\n"
  c_main += '    outparm = (SQLCHAR *) malloc(outlen);' + "\n"
  c_main += '    memset(outparm,0,outlen);' + "\n"    
  c_main += '    sqlrc1 = SQL400IgnoreNullAnyFromAny(hdbc, inparm, inlen,  outparm, outlen, inccsid, outccsid);' + "\n"
  c_main += '    outlen = strlen(outparm);' + "\n"    
  c_main += '    memcpy(inparm,outparm,inlen);' + "\n"    
  c_main += '    free(outparm);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return outlen;' + "\n"
  c_main += '}' + "\n"
  c_main += 'int non_utf_copy_out_hstmt(SQLHSTMT hstmt, SQLRETURN sqlrc, SQLCHAR *src, SQLINTEGER srclen) {' + "\n"
  c_main += '  SQLHDBC hdbc = init_table_stmt_2_conn(hstmt);' + "\n"
  c_main += '  return non_utf_copy_out_hdbc(hdbc, sqlrc, src, srclen);' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLColAttributes(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (fDescType == SQL_DESC_NAME) {' + "\n"
  c_main += '    outsz = non_utf_copy_out_hstmt(hstmt, sqlrc, (SQLCHAR *)rgbDesc, (SQLINTEGER)cbDescMax);' + "\n"
  c_main += '    if (pcbDesc) *pcbDesc = outsz;' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLColumnPrivileges(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp4 = NULL;' + "\n"
  c_main += '  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbColumnName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName, (SQLINTEGER)cbColumnName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLColumns(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp4 = NULL;' + "\n"
  c_main += '  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbColumnName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName, (SQLINTEGER)cbColumnName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLConnect(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  cbDSN = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&szDSN, (SQLINTEGER)cbDSN, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbUID = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp2, (SQLCHAR **)&szUID, (SQLINTEGER)cbUID, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbAuthStr = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp3, (SQLCHAR **)&szAuthStr, (SQLINTEGER)cbAuthStr, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szDSN);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szUID);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szAuthStr);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLDataSources(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER tmpsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  tmpsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szDSN, (SQLINTEGER)cbDSNMax);' + "\n"
  c_main += '  tmpsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szDescription, (SQLINTEGER)cbDescriptionMax);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLDescribeCol(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szColName, (SQLINTEGER)cbColNameMax);' + "\n"
  c_main += '  if (pcbColName) *pcbColName = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLDriverConnect(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  cbConnStrin = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&szConnStrIn, (SQLINTEGER)cbConnStrin, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szConnStrIn);' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szConnStrOut, (SQLINTEGER)cbConnStrOutMax);' + "\n"
  c_main += '  if (pcbConnStrOut) *pcbConnStrOut = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLError(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += '  SQLINTEGER maxsz = SQL_SQLSTATE_SIZE + 1;' + "\n"
  c_main += '  SQLINTEGER tmpsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  tmpsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szSqlState, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szErrorMsg, (SQLINTEGER)cbErrorMsgMax);' + "\n"
  c_main += '  if (pcbErrorMsg) *pcbErrorMsg = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLExecDirect(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  cbSqlStr = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr, (SQLINTEGER)cbSqlStr, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main
 
def non_utf_SQLForeignKeys(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp4 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp5 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp6 = NULL;' + "\n"
  c_main += '  cbPkTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szPkTableQualifier, (SQLINTEGER)cbPkTableQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbPkTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szPkTableOwner, (SQLINTEGER)cbPkTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbPkTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szPkTableName, (SQLINTEGER)cbPkTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbFkTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szFkTableQualifier, (SQLINTEGER)cbFkTableQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbFkTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp5, (SQLCHAR **)&szFkTableOwner, (SQLINTEGER)cbFkTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbFkTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp6, (SQLCHAR **)&szFkTableName, (SQLINTEGER)cbFkTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szPkTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szPkTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szPkTableName);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szFkTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp5, (SQLCHAR **)&szFkTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp6, (SQLCHAR **)&szFkTableName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetConnectAttr(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (attr == SQL_ATTR_DBC_DEFAULT_LIB || attr == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    outsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)oval, (SQLINTEGER)ilen);' + "\n"
  c_main += '    if (olen) *olen = outsz;' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetConnectOption(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = DFTCOLSIZE;' + "\n"
  c_main += '  SQLINTEGER tmpsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (iopt == SQL_ATTR_DBC_DEFAULT_LIB) {' + "\n"
  c_main += '    tmpsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)oval, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetCursorName(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)szCursor, (SQLINTEGER)cbCursorMax);' + "\n"
  c_main += '  if (pcbCursor) *pcbCursor = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetDescField(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (fieldID == SQL_DESC_NAME) {' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)fValue, (SQLINTEGER)fLength);' + "\n"
  c_main += '  if (stLength) *stLength = outsz;' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetDescRec(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)fname, (SQLINTEGER)bufLen);' + "\n"
  c_main += '  if (sLength) *sLength = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetDiagField(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (diagID == SQL_DIAG_SQLSTATE || diagID == SQL_DIAG_MESSAGE_TEXT || diagID == SQL_DIAG_SERVER_NAME) {' + "\n"
  c_main += '    if (hType == SQL_HANDLE_DBC) {' + "\n"
  c_main += '      outsz = non_utf_copy_out_hdbc(hndl, sqlrc, (SQLCHAR *)dValue, (SQLINTEGER)bLength);' + "\n"
  c_main += '    } else {' + "\n"
  c_main += '      outsz = non_utf_copy_out_hstmt(hndl, sqlrc, (SQLCHAR *)dValue, (SQLINTEGER)bLength);' + "\n"
  c_main += '    }' + "\n"
  c_main += '    if (sLength) *sLength = outsz;' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetDiagRec(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += '  SQLINTEGER maxsz = SQL_SQLSTATE_SIZE + 1;' + "\n"
  c_main += '  SQLINTEGER tmpsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (hType == SQL_HANDLE_DBC) {' + "\n"
  c_main += '    tmpsz = non_utf_copy_out_hdbc(hndl, sqlrc, (SQLCHAR *)SQLstate, (SQLINTEGER)maxsz);' + "\n"
  c_main += '    outsz = non_utf_copy_out_hdbc(hndl, sqlrc, (SQLCHAR *)msgText, (SQLINTEGER)bLength);' + "\n"
  c_main += '  } else {' + "\n"
  c_main += '    tmpsz = non_utf_copy_out_hstmt(hndl, sqlrc, (SQLCHAR *)SQLstate, (SQLINTEGER)maxsz);' + "\n"
  c_main += '    outsz = non_utf_copy_out_hstmt(hndl, sqlrc, (SQLCHAR *)msgText, (SQLINTEGER)bLength);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  if (SLength) *SLength = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetEnvAttr(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (fAttribute == SQL_ATTR_DEFAULT_LIB || fAttribute == SQL_ATTR_ESCAPE_CHAR) {' + "\n"
  c_main += '    outsz = non_utf_copy_out_hdbc(0, sqlrc, (SQLCHAR *)pParam, (SQLINTEGER)cbParamMax);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  if (pcbParam) *pcbParam = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetInfo(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (fInfoType == SQL_DBMS_NAME' + "\n"
  c_main += '   || fInfoType == SQL_DBMS_VER' + "\n"
  c_main += '   || fInfoType == SQL_PROCEDURES' + "\n"
  c_main += '   || fInfoType == SQL_DATA_SOURCE_NAME' + "\n"
  c_main += '   || fInfoType == SQL_COLUMN_ALIAS' + "\n"
  c_main += '   || fInfoType == SQL_DATA_SOURCE_READ_ONLY' + "\n"
  c_main += '   || fInfoType == SQL_MULTIPLE_ACTIVE_TXN' + "\n"
  c_main += '   || fInfoType == SQL_DRIVER_NAME' + "\n"
  c_main += '   || fInfoType == SQL_IDENTIFIER_QUOTE_CHAR' + "\n"
  c_main += '   || fInfoType == SQL_PROCEDURE_TERM' + "\n"
  c_main += '   || fInfoType == SQL_QUALIFIER_TERM' + "\n"
  c_main += '   || fInfoType == SQL_QUALIFIER_NAME_SEPARATOR' + "\n"
  c_main += '   || fInfoType == SQL_OWNER_TERM' + "\n"
  c_main += '   || fInfoType == SQL_DRIVER_ODBC_VER' + "\n"
  c_main += '   || fInfoType == SQL_ORDER_BY_COLUMNS_IN_SELECT' + "\n"
  c_main += '   || fInfoType == SQL_SEARCH_PATTERN_ESCAPE' + "\n"
  c_main += '   || fInfoType == SQL_OUTER_JOINS' + "\n"
  c_main += '   || fInfoType == SQL_LIKE_ESCAPE_CLAUSE' + "\n"
  c_main += '   || fInfoType == SQL_CATALOG_NAME' + "\n"
  c_main += '   || fInfoType == SQL_DESCRIBE_PARAMETER' + "\n"
  c_main += '  ) {' + "\n"
  c_main += '    outsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)rgbInfoValue, (SQLINTEGER)cbInfoValueMax);' + "\n"
  c_main += '    if (pcbInfoValue) *pcbInfoValue = outsz;' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLGetPosition(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  srchLiteralLen = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&srchLiteral, (SQLINTEGER)srchLiteralLen, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&srchLiteral);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLNativeSql(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER outsz = 0;' + "\n"
  c_main += '  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  cbSqlStrIn = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStrIn, (SQLINTEGER)cbSqlStrIn, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStrIn);' + "\n"
  c_main += '  outsz = non_utf_copy_out_hdbc(hdbc, sqlrc, (SQLCHAR *)szSqlStr, (SQLINTEGER)cbSqlStrMax);' + "\n"
  c_main += '  if (pcbSqlStr) *pcbSqlStr = outsz;' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLParamData(call_name, normal_db400_args):
  c_main = ""
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLPrepare(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  cbSqlStr = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr, (SQLINTEGER)cbSqlStr, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szSqlStr);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLPrimaryKeys(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLProcedureColumns(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp4 = NULL;' + "\n"
  c_main += '  cbProcQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier, (SQLINTEGER)cbProcQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbProcOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner, (SQLINTEGER)cbProcOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbProcName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName, (SQLINTEGER)cbProcName, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbColumnName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName, (SQLINTEGER)cbColumnName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szColumnName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLProcedures(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  cbProcQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier, (SQLINTEGER)cbProcQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbProcOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner, (SQLINTEGER)cbProcOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbProcName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName, (SQLINTEGER)cbProcName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szProcQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szProcOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szProcName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLSetConnectAttr(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  if (attrib == SQL_ATTR_DBC_DEFAULT_LIB || attrib == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    inlen = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&vParam, (SQLINTEGER)inlen, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  }' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (attrib == SQL_ATTR_DBC_DEFAULT_LIB || attrib == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&vParam);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLSetConnectOption(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLINTEGER tmpsz = 0;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  if (fOption == SQL_ATTR_DBC_DEFAULT_LIB || fOption == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    tmpsz = non_utf_copy_in_hdbc(hdbc, (SQLCHAR **)&tmp1, (SQLCHAR **)&vParam, (SQLINTEGER)SQL_NTS, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  }' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (fOption == SQL_ATTR_DBC_DEFAULT_LIB || fOption == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&vParam);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLSetCursorName(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  cbCursor = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szCursor, (SQLINTEGER)cbCursor, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szCursor);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLSetEnvAttr(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXINTVAL_REASONABLE;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  if (fAttribute == SQL_ATTR_DBC_DEFAULT_LIB || fAttribute == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    cbParam = non_utf_copy_in_hdbc(0, (SQLCHAR **)&tmp1, (SQLCHAR **)&pParam, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  }' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  if (fAttribute == SQL_ATTR_DBC_DEFAULT_LIB || fAttribute == SQL_ATTR_SAVEPOINT_NAME) {' + "\n"
  c_main += '    non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&pParam);' + "\n"
  c_main += '  }' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLSpecialColumns(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  cbTableQual = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQual, (SQLINTEGER)cbTableQual, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQual);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLStatistics(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)cbTableQualifier, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)cbTableOwner, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)cbTableName, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLTablePrivileges(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

def non_utf_SQLTables(call_name, normal_db400_args):
  c_main = ""
  c_main += '  SQLINTEGER maxsz = SQL_MAXSMALLVAL;' + "\n"
  c_main += '  SQLCHAR * tmp1 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp2 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp3 = NULL;' + "\n"
  c_main += '  SQLCHAR * tmp4 = NULL;' + "\n"
  c_main += '  cbTableQualifier = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableOwner = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableName = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += '  cbTableType = non_utf_copy_in_hstmt(hstmt, (SQLCHAR **)&tmp4, (SQLCHAR **)&szTableType, (SQLINTEGER)maxsz, (SQLINTEGER)maxsz);' + "\n"
  c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp1, (SQLCHAR **)&szTableQualifier);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp2, (SQLCHAR **)&szTableOwner);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp3, (SQLCHAR **)&szTableName);' + "\n"
  c_main += '  non_utf_copy_in_free((SQLCHAR **)&tmp4, (SQLCHAR **)&szTableType);' + "\n"
  c_main += '  return sqlrc;' + "\n"
  c_main += '}' + "\n"
  return c_main

# ===============================================
# special ILE CLI APIs
# ===============================================
# SQLRETURN ILE_SQLParamData( SQLHSTMT  hstmt, SQLPOINTER * Value )
def ILE_SQLParamData_copy_var():
  c_main = ""
  c_main += '  /* returnPtr - API returns ILE SP pointer buffer (alias of PASE ptr) */ ' + "\n"
  c_main += '  char returnBuffer[ sizeof(ILEpointer ) + 16 ];' + "\n"
  c_main += '  ILEpointer	*returnPtr = (ILEpointer *)ROUND_QUAD(returnBuffer);' + "\n"
  return c_main
def ILE_SQLParamData_copy_in():
  c_main = ""
  c_main += '  /* returnPtr - ILE SP pointer buffer return area */ ' + "\n"
  c_main += '  if (Value) {' + "\n"
  c_main += '    arglist->Value.s.addr = (ulong) returnPtr;' + "\n"
  c_main += '  }' + "\n"
  return c_main
def ILE_SQLParamData_copy_out():
  c_main = ""
  c_main += '  /* returnPtr - ILE SP to PASE pointer */ ' + "\n"
  c_main += '  if (Value) {' + "\n"
  c_main += '    if (arglist->base.result.s_int32.r_int32 == SQL_NEED_DATA) {' + "\n"
  c_main += '      *Value = _CVTSPP(returnPtr);' + "\n"
  c_main += '    }' + "\n"
  c_main += '  }' + "\n"
  return c_main
# SQLRETURN ILE_SQLGetDescField( SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, 
# SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength )
def ILE_SQLGetDescField_copy_var():
  c_main = ""
  c_main += '  /* returnPtr - API returns ILE SP pointer buffer (alias of PASE ptr)' + "\n"
  c_main += '   * Return ILE SP likely outside PASE mapable addr space.' + "\n"
  c_main += '   * However, _CVTSPP is safe. The result is zero (null)' + "\n"
  c_main += '   * if the input is a 16-byte null pointer or a tagged space pointer ' + "\n"
  c_main += '   * that does not contain the teraspace address' + "\n"
  c_main += '   * equivalent of some valid IBM PASE for i memory address.' + "\n"
  c_main += '   * (I suspect options never used in years of PASE.' + "\n"
  c_main += '   * Rochester CLI team was notified).' + "\n"
  c_main += '   */' + "\n"
  c_main += '  char returnBuffer[ sizeof(ILEpointer ) + 16 ];' + "\n"
  c_main += '  ILEpointer	*returnPtr = (ILEpointer *)ROUND_QUAD(returnBuffer);' + "\n"
  return c_main
def ILE_SQLGetDescField_copy_in():
  c_main = ""
  c_main += '  /* returnPtr - ILE SP pointer buffer return area */ ' + "\n"
  c_main += '  if (fValue) {' + "\n"
  c_main += '    if (fieldID == SQL_DESC_DATA_PTR' + "\n"
  c_main += '     || fieldID == SQL_DESC_LENGTH_PTR' + "\n"
  c_main += '     || fieldID == SQL_DESC_INDICATOR_PTR)' + "\n"
  c_main += '    {' + "\n"
  c_main += '      arglist->fValue.s.addr = (ulong) returnPtr;' + "\n"
  c_main += '    }' + "\n"
  c_main += '  }' + "\n"
  return c_main
def ILE_SQLGetDescField_copy_out():
  c_main = ""
  c_main += '  /* returnPtr - ILE SP to PASE pointer */ ' + "\n"
  c_main += '  if (fValue) {' + "\n"
  c_main += '    if (fieldID == SQL_DESC_DATA_PTR' + "\n"
  c_main += '     || fieldID == SQL_DESC_LENGTH_PTR' + "\n"
  c_main += '     || fieldID == SQL_DESC_INDICATOR_PTR)' + "\n"
  c_main += '    {' + "\n"
  c_main += '      *((void **)fValue) = _CVTSPP(returnPtr);' + "\n"
  c_main += '    }' + "\n"
  c_main += '  }' + "\n"
  return c_main


# ===============================================
# pre-process CLI gen_cli_template.c
# (future ... if wide interface or not)
# ===============================================
pre = open(PaseSqlCli_file,"r")
ile_wide_api = {'nothing': 'nothing'}
for line in pre:

  # start of SQL function ..
  # SQLRETURN SQLxxx(
  if "SQLRETURN SQL" in line:
   # parse function
   lesss = line.split("(")
   parts = lesss[0].split(" ")
   funcs = parts[1]
   # forget
   if "400" in funcs:
     continue
   # wide api
   if "W" in funcs:
     line_no_W = funcs.split("W")
     assoc_name = line_no_W[0]
     ile_wide_api[assoc_name] = funcs
     # if call_name in ile_wide_api.values():
     # print("ile_wide_api['" + assoc_name + "'] = '" + funcs + "'")

# ===============================================
# process CLI gen_cli_template.c
# ===============================================
f = open(PaseSqlCli_file,"r")
g = False
c400 = True
c400_CCSID = False
c400_not_wide = True
ile_or_custom_call = ""
ile_or_libdb400_call = ""
line_func = ""
libdb400_exp=""
PaseCliLibDB400_h_proto = ""
PaseCliLibDB400_c_symbol = ""
PaseCliLibDB400_c_main = ""
PaseCliAsync_h_struct = ""
PaseCliAsync_h_proto_async = ""
PaseCliAsync_h_proto_join = ""
PaseCliAsync_c_main = ""
PaseCliAny_h_proto = ""
PaseCliOnly400_h_proto = ""
PaseCliILE_h_proto = ""
PaseCliILE_c_symbol = ""
PaseCliCustom_h_proto = ""
PaseCliILE_h_struct = ""
PaseCliILE_c_main = ""
PaseCliDump_h_proto = ""
PaseCliDump_c_main = ""
for line in f:

  # start of SQL function ..
  # SQLRETURN SQLxxx(
  if "SQLRETURN SQL" in line:
    g = True
    line_func = ""
  if g:
    # throw out change flags and comments 
    # SQLRETURN SQLPrimaryKeys ... /* @08A*/
    #                              0
    line_no_comment = line.split("/")
    split0 = line_no_comment[0]
    line_func += split0
    # end of function ..args..)
    if not ")" in split0:
      continue
    else:
      g = False
  else:   
    continue

  # ---------------
  # parse function
  # ---------------
  parts = parse_method(line_func)
  funcs = parts[0]
  args = parts[1]
  # SQLRETURN SQLPrimaryKeys
  # 0         (1 or 2)
  call_retv = funcs[0] + funcs[1]
  call_name = funcs[2]
  struct_name = call_name + "Struct"
  struct_ile_name = call_name + "IleCallStruct"
  struct_ile_sig = call_name + "IleSigStruct"
  struct_ile_flag = call_name + "Loaded"
  struct_ile_buf = call_name + "Buf"
  struct_ile_ptr = call_name + "Ptr"

  # ---------------
  # custom function (super api)
  # ---------------
  c400_not_wide = True
  c400_CCSID = False
  c400 = True
  ile_or_custom_call = "custom_"
  ile_or_libdb400_call = "libdb400_"
  if "SQLOverrideCCSID400" in call_name:
    c400_CCSID = True
  if "SQL400" in call_name:
    c400 = False
  if c400:
    ile_or_custom_call = "ILE_"
  if "W" in call_name:
    ile_or_libdb400_call = "ILE_"
    c400_not_wide = False

  # ---------------
  # arguments (params)
  # ---------------
  idx = 0
  comma = ","
  semi = ";"
  argtype1st = ""
  argname1st = ""
  normal_call_types = ""
  normal_call_args = ""
  normal_db400_args = ""
  async_struct_types = " SQLRETURN sqlrc;"
  async_call_args = ""
  async_db400_args = ""
  async_copyin_args = ""
  ILE_struct_sigs = ""
  ILE_struct_types = "ILEarglist_base base;"
  ILE_copyin_args = ""
  dump_args = ""
  dump_sigs = ""
  for arg in args:
    idx += 1
    if idx == len(args):
      comma = ""
    # SQLHSTMT hstmt
    # 0        1
    # SQLCHAR * szTableQualifier
    # 0       1 2
    argfull = ' '.join(arg)
    argsig = arg[0] + arg[1]
    argname = arg[2]
    if idx == 1:
     argtype1st = arg[0];
     argname1st = arg[2];
    sigile = ''
    ilefull = argfull
    if arg[1] == '*':
      sigile = 'ARG_MEMPTR'
      ilefull = 'ILEpointer' + ' ' + arg[2]
    elif arg[0] == 'PTR':
      sigile = 'ARG_MEMPTR'
      ilefull = 'ILEpointer' + ' ' + arg[2]
    elif arg[0] == 'SQLHWND':
      sigile = 'ARG_MEMPTR'
      ilefull = 'ILEpointer' + ' ' + arg[2]
    elif arg[0] == 'SQLPOINTER':
      sigile = 'ARG_MEMPTR'
      ilefull = 'ILEpointer' + ' ' + arg[2]
    elif arg[0] == 'SQLCHAR':
      sigile = 'ARG_UINT8'
    elif arg[0] == 'SQLWCHAR':
      sigile = 'ARG_UINT8'
    elif arg[0] == 'SQLSMALLINT':
      sigile = 'ARG_INT16'
    elif arg[0] == 'SQLUSMALLINT':
      sigile = 'ARG_UINT16'
    elif arg[0] == 'SQLSMALLINT':
      sigile = 'ARG_INT16'
    elif arg[0] == 'SQLINTEGER':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLUINTEGER':
      sigile = 'ARG_UINT32'
    elif arg[0] == 'SQLDOUBLE':
      sigile = 'ARG_FLOAT64'
    elif arg[0] == 'SQLREAL':
      sigile = 'ARG_FLOAT32'
    elif arg[0] == 'HENV':
      sigile = 'ARG_INT32'
    elif arg[0] == 'HDBC':
      sigile = 'ARG_INT32'
    elif arg[0] == 'HSTMT':
      sigile = 'ARG_INT32'
    elif arg[0] == 'HDESC':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLHANDLE':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLHENV':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLHDBC':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLHSTMT':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLHDESC':
      sigile = 'ARG_INT32'
    elif arg[0] == 'RETCODE':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SQLRETURN':
      sigile = 'ARG_INT32'
    elif arg[0] == 'SFLOAT':
      sigile = 'ARG_FLOAT32'

    # each SQL function override
    # SQLRETURN SQLPrimaryKeys( SQLHSTMT hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT cbTableQualifier, ...
    #                           -------------------------------------------------------------------------
    normal_call_args += ' ' + argfull + comma
    # each SQL function call libdb400
    # sqlrc = libdb400_SQLPrimaryKeys( hstmt, szTableQualifier, cbTableQualifier, ...
    #                                  ------------------------------------------
    normal_db400_args += ' ' + argname + comma
    # SQLRETURN (*libdb400_SQLPrimaryKeys)(SQLHSTMT,SQLCHAR*,SQLSMALLINT, ...
    #                                      ------------------------------
    normal_call_types += ' ' + argsig + comma
    # Dump args and sigs
    #
    dump_args += ' ' + argname
    dump_sigs += ' ' + argsig

    # ILE call structure
    ILE_struct_types += ' ' + ilefull + semi
    # ILE call signature
    ILE_struct_sigs += ' ' + sigile + comma
    # ILE copyin params
    if sigile == 'ARG_MEMPTR':
      ILE_copyin_args += '  arglist->' + argname + '.s.addr = (ulong) ' + argname + ";" + "\n"
    else:
      ILE_copyin_args += '  arglist->' + argname + ' = (' + argsig + ') ' + argname + ";" + "\n"

    # each SQL async struct
    # typedef struct SQLPrimaryKeysStruct { SQLRETURN sqlrc; SQLHSTMT hstmt;  ...
    #                                       --------------------------------
    async_struct_types += ' ' + argfull + semi
    # each SQL asyn call libdb400
    # myptr->sqlrc = libdb400_SQLPrimaryKeys( myptr->hstmt, myptr->szTableQualifier, myptr->cbTableQualifier, ...
    #                                  ------------------------------------------
    async_db400_args += ' myptr->' + argname + comma
    # each SQL asyn copyin parms
    # myptr->hstmt = hstmt;
    # myptr->szTableQualifier = szTableQualifier; 
    # myptr->cbTableQualifier = cbTableQualifier; 
    # ...
    #                                  ------------------------------------------
    async_copyin_args += '  myptr->' + argname + " = " + argname + ";" + "\n"



  # ===============================================
  # standard dumping function
  # ===============================================
  PaseCliDump_h_proto  += "void dump_" + call_name + '(SQLRETURN sqlrc, ' + normal_call_args + ' );' + "\n"
  PaseCliDump_c_main += "void dump_" + call_name + '(SQLRETURN sqlrc, ' + normal_call_args + ' ) {' + "\n"
  PaseCliDump_c_main += '  if (dev_go(sqlrc,"'+call_name.lower()+'")) {' + "\n"
  PaseCliDump_c_main += '    char mykey[256];' + "\n"
  PaseCliDump_c_main += '    printf_key(mykey,"' + call_name + '");' + "\n"
  PaseCliDump_c_main += '    printf_clear();' + "\n"
  PaseCliDump_c_main += '    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);' + "\n"
  PaseCliDump_c_main += '    printf_stack(mykey);' + "\n"
  PaseCliDump_c_main += '    printf_sqlrc_status((char *)&mykey, sqlrc);' + "\n"
  args = dump_args.split()
  sigs = dump_sigs.split()
  dump_handle = ''
  dump_type = ''
  i = 0
  for arg in args:
    sig = sigs[i]
    PaseCliDump_c_main += '    printf_format("%s.parm %s %s 0x%p (%d)\\n",mykey,"'+sig+'","'+arg+'",'+arg+','+arg+');' + "\n"
    if '*' in sig or 'SQLPOINTER' in sig:
      PaseCliDump_c_main += '    printf_hexdump(mykey,'+arg+',80);' + "\n"
    elif 'SQLHDBC' in sig:
      dump_handle = arg
      dump_type = 'SQL_HANDLE_DBC'
    elif 'SQLHSTMT' in sig:
      dump_handle = arg
      dump_type = 'SQL_HANDLE_STMT'
    elif 'SQLHDESC' in sig:
      dump_handle = arg
      dump_type = 'SQL_HANDLE_DESC'
    i += 1
  PaseCliDump_c_main += '    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);' + "\n"
  PaseCliDump_c_main += '    dev_dump();'  + "\n"
  PaseCliDump_c_main += '    if (sqlrc < SQL_SUCCESS) {' + "\n" 
  if 'SQL' in dump_type:
    PaseCliDump_c_main += '      printf_sql_diag('+dump_type +','+dump_handle+');' + "\n" 
  PaseCliDump_c_main += '      printf_force_SIGQUIT((char *)&mykey);' + "\n"
  PaseCliDump_c_main += '    }' + "\n" 
  PaseCliDump_c_main += '  }' + "\n" 
  PaseCliDump_c_main += '}' + "\n" 



  # ===============================================
  # non-async SQL interfaces with lock added
  # ===============================================

  if c400:
    # each SQL400 function special (header)
    # SQLRETURN SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options )
    #
    PaseCliAny_h_proto += " * " + call_retv + ' ' + call_name + '(' + normal_call_args + ' );' + "\n"

    # ===============================================
    # libdb400 call (here adc tony)
    # ===============================================
    # SQLRETURN custom_SQLOverrideCCSID400( SQLINTEGER  newCCSID )
    if c400_CCSID:
      PaseCliCustom_h_proto += call_retv + ' ' + "custom_" + call_name + '(' + normal_call_args + ' );' + "\n"
    else:
      # old libdb400.a (non-utf)
      PaseCliLibDB400_h_proto  += call_retv + ' libdb400_' + call_name + '(' + normal_call_args + ' );' + "\n"
      # main
      PaseCliLibDB400_c_main += call_retv + ' libdb400_' + call_name + '(' + normal_call_args + ' ) {' + "\n"
      PaseCliLibDB400_c_main += '  SQLRETURN sqlrc = SQL_SUCCESS;' + "\n"
      if 'W' in call_name:
        PaseCliLibDB400_c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliLibDB400_c_main += "  return sqlrc;" + "\n"
        PaseCliLibDB400_c_main += '}' + "\n"
      else:
        if 'SQLColAttributes' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLColAttributes(call_name, normal_db400_args)
        elif 'SQLColumnPrivileges' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLColumnPrivileges(call_name, normal_db400_args)
        elif 'SQLColumns' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLColumns(call_name, normal_db400_args)
        elif 'SQLConnect' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLConnect(call_name, normal_db400_args)
        elif 'SQLDataSources' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLDataSources(call_name, normal_db400_args)
        elif 'SQLDescribeCol' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLDescribeCol(call_name, normal_db400_args)
        elif 'SQLDriverConnect' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLDriverConnect(call_name, normal_db400_args)
        elif 'SQLError' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLError(call_name, normal_db400_args)
        elif 'SQLExecDirect' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLExecDirect(call_name, normal_db400_args)
        elif 'SQLForeignKeys' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLForeignKeys(call_name, normal_db400_args)
        elif 'SQLGetConnectAttr' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetConnectAttr(call_name, normal_db400_args)
        elif 'SQLGetConnectOption' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetConnectOption(call_name, normal_db400_args)
        elif 'SQLGetCursorName' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetCursorName(call_name, normal_db400_args)
        elif 'SQLGetDescField' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetDescField(call_name, normal_db400_args)
        elif 'SQLGetDescRec' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetDescRec(call_name, normal_db400_args)
        elif 'SQLGetDiagField' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetDiagField(call_name, normal_db400_args)
        elif 'SQLGetDiagRec' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetDiagRec(call_name, normal_db400_args)
        elif 'SQLGetEnvAttr' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetEnvAttr(call_name, normal_db400_args)
        elif 'SQLGetInfo' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetInfo(call_name, normal_db400_args)
        elif 'SQLGetPosition' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLGetPosition(call_name, normal_db400_args)
        elif 'SQLNativeSql' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLNativeSql(call_name, normal_db400_args)
        elif 'SQLParamData' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLParamData(call_name, normal_db400_args)
        elif 'SQLPrepare' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLPrepare(call_name, normal_db400_args)
        elif 'SQLPrimaryKeys' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLPrimaryKeys(call_name, normal_db400_args)
        elif 'SQLProcedureColumns' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLProcedureColumns(call_name, normal_db400_args)
        elif 'SQLProcedures' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLProcedures(call_name, normal_db400_args)
        elif 'SQLSetConnectAttr' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLSetConnectAttr(call_name, normal_db400_args)
        elif 'SQLSetConnectOption' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLSetConnectOption(call_name, normal_db400_args)
        elif 'SQLSetCursorName' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLSetCursorName(call_name, normal_db400_args)
        elif 'SQLSetEnvAttr' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLSetEnvAttr(call_name, normal_db400_args)
        elif 'SQLSpecialColumns' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLSpecialColumns(call_name, normal_db400_args)
        elif 'SQLStatistics' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLStatistics(call_name, normal_db400_args)
        elif 'SQLTablePrivileges' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLTablePrivileges(call_name, normal_db400_args)
        elif 'SQLTables' in call_name:
          PaseCliLibDB400_c_main += non_utf_SQLTables(call_name, normal_db400_args)
        else:
          PaseCliLibDB400_c_main += "  sqlrc = ILE_" + call_name + '(' + normal_db400_args + ' );' + "\n"
          PaseCliLibDB400_c_main += "  return sqlrc;" + "\n"
          PaseCliLibDB400_c_main += '}' + "\n"
      libdb400_exp += "libdb400_" + call_name + "\n"

  else:
    # each SQL400 function special (header)
    # SQLRETURN SQL400Environment( SQLINTEGER * ohnd, SQLPOINTER  options )
    #
    PaseCliOnly400_h_proto += call_retv + ' ' + call_name + '(' + normal_call_args + ' );' + "\n"
    PaseCliCustom_h_proto += call_retv + ' ' + "custom_" + call_name + '(' + normal_call_args + ' );' + "\n"

  # export special libdb400.a
  libdb400_exp += call_name + "\n"

  # each SQL function override
  # SQLRETURN SQLAllocEnv( SQLHENV * phenv )
  # { 
  # }
  if c400_CCSID:
    PaseCliAsync_c_main += 'int SQLOverrideCCSID400(int newCCSID)' + "\n"
  else:
    PaseCliAsync_c_main += call_retv + ' ' + call_name + '(' + normal_call_args + ' )' + "\n"
  PaseCliAsync_c_main += "{" + "\n"
  PaseCliAsync_c_main += "  SQLRETURN sqlrc = SQL_SUCCESS;" + "\n"
  # special handling routines
  if call_name == "SQLAllocEnv":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLAllocEnv(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLAllocConnect":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLAllocConnect(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLAllocStmt":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLAllocStmt(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLAllocHandle":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLAllocHandle(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLFreeEnv":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLFreeEnv(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLFreeConnect":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLFreeConnect(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLFreeStmt":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLFreeStmt(ile_or_custom_call, call_name, normal_db400_args)
  elif call_name == "SQLFreeHandle":
    PaseCliAsync_c_main += PaseCliAsync_c_main_SQLFreeHandle(ile_or_custom_call, call_name, normal_db400_args)
  # SQLRETURN SQLOverrideCCSID400( SQLINTEGER  newCCSID )
  elif c400_CCSID:
    PaseCliAsync_c_main += "  sqlrc = custom_" + call_name + '(' + normal_db400_args + ' );' + "\n"
  # all other CLI APIs 
  else:
    # normal cli function
    PaseCliAsync_c_main += "  int myccsid = init_CCSID400(0);" + "\n"
    if call_name == "SQLDisconnect":
      PaseCliAsync_c_main += SQLDisconnect_check_persistent("hdbc","return SQL_ERROR;", "/* return now */")
    if argtype1st == "SQLHENV":
      if ile_or_custom_call == "custom_":
        PaseCliAsync_c_main += "  sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
      else:
        PaseCliAsync_c_main += "  switch(myccsid) {" + "\n"
        PaseCliAsync_c_main += '  case 1208: /* UTF-8 */' + "\n"
        PaseCliAsync_c_main += '  case 1200: /* UTF-16 */' + "\n"
        PaseCliAsync_c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += '  default:' + "\n"
        PaseCliAsync_c_main += "    sqlrc = libdb400_" + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += "  }" + "\n"
      # dump trace
      PaseCliAsync_c_main += "  if (init_cli_trace()) {" + "\n"
      PaseCliAsync_c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
      PaseCliAsync_c_main += "  }" + "\n"
    elif argtype1st == "SQLHDBC":
      PaseCliAsync_c_main += "  init_table_lock(" + argname1st + ", 0);" + "\n"
      if ile_or_custom_call == "custom_":
        PaseCliAsync_c_main += "  sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
      else:
        PaseCliAsync_c_main += "  switch(myccsid) {" + "\n"
        PaseCliAsync_c_main += '  case 1208: /* UTF-8 */' + "\n"
        PaseCliAsync_c_main += '  case 1200: /* UTF-16 */' + "\n"
        PaseCliAsync_c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += '  default:' + "\n"
        PaseCliAsync_c_main += "    sqlrc = libdb400_" + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += "  }" + "\n"
      # dump trace
      PaseCliAsync_c_main += "  if (init_cli_trace()) {" + "\n"
      PaseCliAsync_c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
      PaseCliAsync_c_main += "  }" + "\n"
      PaseCliAsync_c_main += "  init_table_unlock(" + argname1st + ", 0);" + "\n"
    elif argtype1st == "SQLHSTMT":
      PaseCliAsync_c_main += "  init_table_lock(" + argname1st + ", 1);" + "\n"
      if ile_or_custom_call == "custom_":
        PaseCliAsync_c_main += "  sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
      else:
        PaseCliAsync_c_main += "  switch(myccsid) {" + "\n"
        PaseCliAsync_c_main += '  case 1208: /* UTF-8 */' + "\n"
        PaseCliAsync_c_main += '  case 1200: /* UTF-16 */' + "\n"
        PaseCliAsync_c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += '  default:' + "\n"
        PaseCliAsync_c_main += "    sqlrc = libdb400_" + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += "  }" + "\n"
      # dump trace
      PaseCliAsync_c_main += "  if (init_cli_trace()) {" + "\n"
      PaseCliAsync_c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
      PaseCliAsync_c_main += "  }" + "\n"
      PaseCliAsync_c_main += "  init_table_unlock(" + argname1st + ", 1);" + "\n"
    elif argtype1st == "SQLHDESC":
      PaseCliAsync_c_main += "  init_table_lock(" + argname1st + ", 1);" + "\n"
      if ile_or_custom_call == "custom_":
        PaseCliAsync_c_main += "  sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
      else:
        PaseCliAsync_c_main += "  switch(myccsid) {" + "\n"
        PaseCliAsync_c_main += '  case 1208: /* UTF-8 */' + "\n"
        PaseCliAsync_c_main += '  case 1200: /* UTF-16 */' + "\n"
        PaseCliAsync_c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += '  default:' + "\n"
        PaseCliAsync_c_main += "    sqlrc = libdb400_" + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += "  }" + "\n"
      # dump trace
      PaseCliAsync_c_main += "  if (init_cli_trace()) {" + "\n"
      PaseCliAsync_c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
      PaseCliAsync_c_main += "  }" + "\n"
      PaseCliAsync_c_main += "  init_table_unlock(" + argname1st + ", 1);" + "\n"
    else:
      if ile_or_custom_call == "custom_":
        PaseCliAsync_c_main += "  sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
      else:
        PaseCliAsync_c_main += "  switch(myccsid) {" + "\n"
        PaseCliAsync_c_main += '  case 1208: /* UTF-8 */' + "\n"
        PaseCliAsync_c_main += '  case 1200: /* UTF-16 */' + "\n"
        PaseCliAsync_c_main += "    sqlrc = " + ile_or_custom_call + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += '  default:' + "\n"
        PaseCliAsync_c_main += "    sqlrc = libdb400_" + call_name + '(' + normal_db400_args + ' );' + "\n"
        PaseCliAsync_c_main += "    break;" + "\n"
        PaseCliAsync_c_main += "  }" + "\n"
      # dump trace
      PaseCliAsync_c_main += "  if (init_cli_trace()) {" + "\n"
      PaseCliAsync_c_main += "    dump_" + call_name + '(sqlrc, ' + normal_db400_args + ' );' + "\n"
      PaseCliAsync_c_main += "  }" + "\n"
  # common code
  PaseCliAsync_c_main += "  return sqlrc;" + "\n"
  PaseCliAsync_c_main += "}" + "\n"


  # ===============================================
  # ILE call
  # ===============================================
  if c400 and c400_CCSID == False:
    PaseCliILE_h_proto += call_retv + ' ILE_' + call_name + '(' + normal_call_args + ' );' + "\n"

    PaseCliILE_h_struct += 'typedef struct ' + struct_ile_name + ' {' + ILE_struct_types + ' } ' + struct_ile_name + ';'  + "\n";

    PaseCliILE_c_symbol  += 'SQLINTEGER ' + struct_ile_flag + ';' + "\n"
    PaseCliILE_c_symbol  += 'SQLCHAR ' + struct_ile_buf + '[132];' + "\n"

    PaseCliILE_c_main += call_retv + ' ILE_' + call_name + '(' + normal_call_args + ' )' + "\n"
    PaseCliILE_c_main += '{' + "\n"
    PaseCliILE_c_main += '  int rc = 0;' + "\n"
    PaseCliILE_c_main += '  SQLRETURN sqlrc = SQL_SUCCESS;' + "\n"
    if 'SQLParamData' in call_name:
      PaseCliILE_c_main += ILE_SQLParamData_copy_var()
    if 'SQLGetDescField' in call_name:
      PaseCliILE_c_main += ILE_SQLGetDescField_copy_var()
    PaseCliILE_c_main += '  int actMark = 0;' + "\n"
    PaseCliILE_c_main += '  char * ileSymPtr = (char *) NULL;' + "\n"
    PaseCliILE_c_main += '  ' + struct_ile_name + ' * arglist = (' + struct_ile_name + ' *) NULL;' + "\n"
    PaseCliILE_c_main += '  char buffer[ sizeof(' + struct_ile_name + ') + 16 ];' + "\n"
    PaseCliILE_c_main += '  static arg_type_t ' + struct_ile_sig + '[] = {' + ILE_struct_sigs + ', ARG_END };'  + "\n";
    PaseCliILE_c_main += '  arglist = (' + struct_ile_name + ' *)ROUND_QUAD(buffer);' + "\n"
    PaseCliILE_c_main += '  ileSymPtr = (char *)ROUND_QUAD(&' + struct_ile_buf + ');' +  "\n"
    PaseCliILE_c_main += '  memset(buffer,0,sizeof(buffer));' +  "\n"
    PaseCliILE_c_main += '  actMark = init_cli_srvpgm();' +  "\n"
    PaseCliILE_c_main += '  if (!'+ struct_ile_flag +') {' +  "\n"
    PaseCliILE_c_main += '    rc = _ILESYM((ILEpointer *)ileSymPtr, actMark, "' + call_name + '");' +  "\n"
    PaseCliILE_c_main += '    if (rc < 0) {' + "\n"
    PaseCliILE_c_main += '      return SQL_ERROR;' + "\n"
    PaseCliILE_c_main += '    }' + "\n"
    PaseCliILE_c_main += '    ' + struct_ile_flag + ' = 1;' +  "\n"
    PaseCliILE_c_main += '  }' + "\n"
    PaseCliILE_c_main += ILE_copyin_args
    if 'SQLParamData' in call_name:
      PaseCliILE_c_main += ILE_SQLParamData_copy_in()
    if 'SQLGetDescField' in call_name:
      PaseCliILE_c_main += ILE_SQLGetDescField_copy_in()
    PaseCliILE_c_main += '  rc = _ILECALL((ILEpointer *)ileSymPtr, &arglist->base, ' + struct_ile_sig + ', RESULT_INT32);' +  "\n"
    PaseCliILE_c_main += '  if (rc != ILECALL_NOERROR) {' + "\n"
    PaseCliILE_c_main += '    return SQL_ERROR;' + "\n"
    PaseCliILE_c_main += '  }' + "\n"
    if 'SQLParamData' in call_name:
      PaseCliILE_c_main += ILE_SQLParamData_copy_out()
    if 'SQLGetDescField' in call_name:
      PaseCliILE_c_main += ILE_SQLGetDescField_copy_out()
    PaseCliILE_c_main += '  return arglist->base.result.s_int32.r_int32;' + "\n"
    PaseCliILE_c_main += '}' + "\n"


  # ===============================================
  # NO async SQL interfaces with thread
  # ===============================================
  if call_name == "SQLAllocEnv":
    continue
  elif call_name == "SQLAllocConnect":
    continue
  elif call_name == "SQLAllocStmt":
    continue
  elif call_name == "SQLAllocHandle":
    continue
  elif call_name == "SQLFreeEnv":
    continue
  elif call_name == "SQLFreeConnect":
    continue
  elif call_name == "SQLFreeStmt":
    continue
  elif call_name == "SQLFreeHandle":
    continue
  elif c400_CCSID:
    continue

  # ===============================================
  # async SQL interfaces with thread
  # ===============================================
  async_call_args = normal_call_args + ', void * callback'
  async_struct_types += ' void * callback;'
  async_copyin_args += '  myptr->callback = callback;' + "\n"

  # each SQL function async (header)
  # SQLRETURN SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, ... , void * callback )
  # void (*callback)(SQLSpecialColumnsStruct* )
  # SQLSpecialColumnsStruct * SQLSpecialColumnsJoin (pthread_t tid, SQLINTEGER flag)
  #
  tmp_PaseCliAsync_comment = '/* void ' + call_name + 'Callback(' + struct_name + '* ); */'
  PaseCliAsync_h_proto_async += 'pthread_t ' + call_name + 'Async (' + async_call_args + ' );' + "\n"
  PaseCliAsync_h_proto_join +=  tmp_PaseCliAsync_comment + "\n"
  PaseCliAsync_h_proto_join += struct_name + ' * ' + call_name + 'Join (pthread_t tid, SQLINTEGER flag);' + "\n"

  # export special libdb400.a
  libdb400_exp += call_name + 'Async' + "\n"
  libdb400_exp += call_name + 'Join' + "\n"
  if c400:
    libdb400_exp += 'ILE_' + call_name + "\n"


  # each SQL function async
  # typedef struct SQLAllocEnvStruct {
  #   SQLRETURN sqlrc;
  #   SQLHENV * phenv;
  # } SQLAllocEnvStruct;
  #
  #
  PaseCliAsync_h_struct += 'typedef struct ' + struct_name + ' {' + async_struct_types + ' } ' + struct_name + ';'  + "\n";


  # each SQL function async
  # void * SQLAllocEnvThread(void *ptr)
  # {
  #   void (*callback)(SQLSpecialColumnsStruct* )
  # }
  PaseCliAsync_c_main += 'void * ' + call_name + 'Thread (void *ptr)' + "\n"
  PaseCliAsync_c_main += "{" + "\n"
  PaseCliAsync_c_main += '  SQLRETURN sqlrc = SQL_SUCCESS;' + "\n"
  PaseCliAsync_c_main += "  int myccsid = init_CCSID400(0);" + "\n"
  PaseCliAsync_c_main += '  ' + struct_name + ' * myptr = (' + struct_name + ' *) ptr;' + "\n"
  if call_name == "SQLDisconnect":
    PaseCliAsync_c_main += SQLDisconnect_check_persistent("myptr->hdbc","pthread_exit((void *)myptr);","myptr->sqlrc = SQL_ERROR;")
  if argtype1st == "SQLHENV":
    PaseCliAsync_c_main += "  /* not lock */" + "\n"
  elif argtype1st == "SQLHDBC":
    PaseCliAsync_c_main += "  init_table_lock(myptr->" + argname1st + ", 0);" + "\n"
  elif argtype1st == "SQLHSTMT":
    PaseCliAsync_c_main += "  init_table_lock(myptr->" + argname1st + ", 1);" + "\n"
  elif argtype1st == "SQLHDESC":
    PaseCliAsync_c_main += "  init_table_lock(myptr->" + argname1st + ", 1);" + "\n"
  if ile_or_custom_call == "custom_":
    PaseCliAsync_c_main += "  myptr->sqlrc = " + ile_or_custom_call + call_name + '(' + async_db400_args + ' );' + "\n"
  else:
    # CLI call
    PaseCliAsync_c_main += "  switch(myccsid) {" + "\n"
    PaseCliAsync_c_main += '  case 1208: /* UTF-8 */' + "\n"
    PaseCliAsync_c_main += '  case 1200: /* UTF-16 */' + "\n"
    PaseCliAsync_c_main += "    myptr->sqlrc = " + ile_or_custom_call + call_name + '(' + async_db400_args + ' );' + "\n"
    PaseCliAsync_c_main += "    break;" + "\n"
    PaseCliAsync_c_main += '  default:' + "\n"
    PaseCliAsync_c_main += "    myptr->sqlrc = libdb400_" + call_name + '(' + async_db400_args + ' );' + "\n"
    PaseCliAsync_c_main += "    break;" + "\n"
    PaseCliAsync_c_main += "  }" + "\n"
  # dump trace
  PaseCliAsync_c_main += "  if (init_cli_trace()) {" + "\n"
  PaseCliAsync_c_main += "    dump_" + call_name + '(myptr->sqlrc, ' + async_db400_args + ' );' + "\n"
  PaseCliAsync_c_main += "  }" + "\n"
  if argtype1st == "SQLHENV":
    PaseCliAsync_c_main += "  /* not lock */" + "\n"
  elif argtype1st == "SQLHDBC":
    PaseCliAsync_c_main += "  init_table_unlock(myptr->" + argname1st + ", 0);" + "\n"
  elif argtype1st == "SQLHSTMT":
    PaseCliAsync_c_main += "  init_table_unlock(myptr->" + argname1st + ", 1);" + "\n"
  elif argtype1st == "SQLHDESC":
    PaseCliAsync_c_main += "  init_table_unlock(myptr->" + argname1st + ", 1);" + "\n"
  PaseCliAsync_c_main += '  ' + tmp_PaseCliAsync_comment + "\n"
  PaseCliAsync_c_main += '  if (myptr->callback) {' + "\n"
  PaseCliAsync_c_main += '    void (*ptrFunc)(' + struct_name + '* ) = myptr->callback;' + "\n"
  PaseCliAsync_c_main += '    ptrFunc( myptr );' + "\n"
  PaseCliAsync_c_main += "  }" + "\n"
  PaseCliAsync_c_main += "  pthread_exit((void *)myptr);" + "\n"
  PaseCliAsync_c_main += "}" + "\n"

  # each SQL function async
  # pthread_t SQLSpecialColumnsAsync ( SQLHSTMT  hstmt, SQLSMALLINT  fColType, ... , void * callback )
  # { 
  # }
  PaseCliAsync_c_main += 'pthread_t ' + call_name + 'Async (' + async_call_args + ' )' + "\n"
  PaseCliAsync_c_main += '{' + "\n"
  PaseCliAsync_c_main += '  int rc = 0;' + "\n"
  PaseCliAsync_c_main += '  pthread_t tid = 0;' + "\n"
  PaseCliAsync_c_main += '  ' + struct_name + ' * myptr = (' + struct_name + ' *) malloc(sizeof(' + struct_name + '));' + "\n"
  PaseCliAsync_c_main += '  myptr->sqlrc = SQL_SUCCESS;' + "\n"
  PaseCliAsync_c_main += async_copyin_args
  PaseCliAsync_c_main += '  rc = pthread_create(&tid, NULL, '+ call_name + 'Thread, (void *)myptr);' + "\n"
  PaseCliAsync_c_main += '  return tid;' + "\n"
  PaseCliAsync_c_main += '}' + "\n"

  # each SQL function async
  # SQLSpecialColumnsStruct * SQLSpecialColumnsJoin (pthread_t tid, SQLINTEGER flag)
  # { 
  # }
  PaseCliAsync_c_main += struct_name + ' * ' + call_name + 'Join (pthread_t tid, SQLINTEGER flag)' + "\n"
  PaseCliAsync_c_main += "{" + "\n"
  PaseCliAsync_c_main += "  " + struct_name + " * myptr = (" + struct_name + " *) NULL;" + "\n"
  PaseCliAsync_c_main += "  int active = 0;" + "\n"
  if argtype1st == "SQLHENV":
    PaseCliAsync_c_main += "  /* not lock */" + "\n"
  elif argtype1st == "SQLHDBC":
    PaseCliAsync_c_main += "  active = init_table_in_progress(tid, 0);" + "\n"
  elif argtype1st == "SQLHSTMT":
    PaseCliAsync_c_main += "  active = init_table_in_progress(tid, 1);" + "\n"
  elif argtype1st == "SQLHDESC":
    PaseCliAsync_c_main += "  active = init_table_in_progress(tid, 1);" + "\n"
  PaseCliAsync_c_main += "  if (flag == SQL400_FLAG_JOIN_WAIT || !active) {" + "\n"
  PaseCliAsync_c_main += "    pthread_join(tid,(void**)&myptr);" + "\n"
  PaseCliAsync_c_main += "  } else {" + "\n"
  PaseCliAsync_c_main += "    return (" + struct_name + " *) NULL;" + "\n"
  PaseCliAsync_c_main += "  }" + "\n"
  PaseCliAsync_c_main += "  return myptr;" + "\n"
  PaseCliAsync_c_main += "}" + "\n"


# ===============================================
# write files
# ===============================================

# pase includes
file_pase_incl = ""
file_pase_incl += "#include <stdio.h>" + "\n"
file_pase_incl += "#include <stdlib.h>" + "\n"
file_pase_incl += "#include <unistd.h>" + "\n"
file_pase_incl += "#include <dlfcn.h>" + "\n"
file_pase_incl += "#include <sqlcli1.h>" + "\n"
file_pase_incl += "#include <as400_types.h>" + "\n"
file_pase_incl += "#include <as400_protos.h>" + "\n"

# new libdb400 includes
file_local_incl = ""
file_local_incl += '#include "PaseCliInit.h"' + "\n"
file_local_incl += '#include "PaseCliAsync.h"' + "\n"


# write PaseCliILE_gen.c
file_PaseCliILE_c = ""
file_PaseCliILE_c += file_pase_incl
file_PaseCliILE_c += file_local_incl
file_PaseCliILE_c += "" + "\n"
file_PaseCliILE_c += '  /* gcc compiler' + "\n"
file_PaseCliILE_c += '   * as400_types.h (edit change required)' + "\n"
file_PaseCliILE_c += '   * #if defined( __GNUC__ )' + "\n"
file_PaseCliILE_c += '   *   long double align __attribute__((aligned(16)));' + "\n"
file_PaseCliILE_c += '   * #else ' + "\n"
file_PaseCliILE_c += '   *   long double;' + "\n"
file_PaseCliILE_c += '   * #endif ' + "\n"
file_PaseCliILE_c += '   * ' + "\n"
file_PaseCliILE_c += '   * Use we also need cast ulong to match size of pointer 32/64 ' + "\n"
file_PaseCliILE_c += '   *   arglist->ohnd.s.addr = (ulong) ohnd;' + "\n"
file_PaseCliILE_c += '   */' + "\n"
file_PaseCliILE_c += "" + "\n"
file_PaseCliILE_c += '#define ROUND_QUAD(x) (((size_t)(x) + 0xf) & ~0xf)' + "\n"
file_PaseCliILE_c += "" + "\n"
file_PaseCliILE_c += PaseCliILE_c_symbol
file_PaseCliILE_c += "" + "\n"
file_PaseCliILE_c += "/* ILE call structures               */" + "\n"
file_PaseCliILE_c += "" + "\n"
file_PaseCliILE_c += PaseCliILE_h_struct + "\n"
file_PaseCliILE_c += "" + "\n"
file_PaseCliILE_c += PaseCliILE_c_main
file_PaseCliILE_c += "" + "\n"
with open("PaseCliILE_gen.c", "w") as text_file:
    text_file.write(file_PaseCliILE_c)

# write PaseCliLibDB400_gen.c
file_PaseCliLibDB400_c = ""
file_PaseCliLibDB400_c += file_pase_incl
file_PaseCliLibDB400_c += file_local_incl
file_PaseCliLibDB400_c += "" + "\n"
file_PaseCliLibDB400_c += "#define DFTCOLSIZE 18" + "\n"
file_PaseCliLibDB400_c += "#define SQL_MAXINTVAL_REASONABLE 131072" + "\n"
file_PaseCliLibDB400_c += "" + "\n"
file_PaseCliLibDB400_c += PaseCliLibDB400_c_symbol
file_PaseCliLibDB400_c += "" + "\n"
file_PaseCliLibDB400_c += non_utf_copy_in()
file_PaseCliLibDB400_c += non_utf_copy_in_free()
file_PaseCliLibDB400_c += non_utf_copy_out()
file_PaseCliLibDB400_c += "" + "\n"
file_PaseCliLibDB400_c += PaseCliLibDB400_c_main
file_PaseCliLibDB400_c += "" + "\n"
with open("PaseCliLibDB400_gen.c", "w") as text_file:
    text_file.write(file_PaseCliLibDB400_c)

# write PaseCliAsync_gen.c
file_PaseCliAsync_c = ""
file_PaseCliAsync_c += file_pase_incl
file_PaseCliAsync_c += file_local_incl
file_PaseCliAsync_c += "" + "\n"
file_PaseCliAsync_c += "" + "\n"
file_PaseCliAsync_c += PaseCliAsync_c_main
with open("PaseCliAsync_gen.c", "w") as text_file:
    text_file.write(file_PaseCliAsync_c)

# write PaseCliDump_gen.c
file_PaseCliDump_c = ""
file_PaseCliDump_c += file_pase_incl
file_PaseCliDump_c += file_local_incl
file_PaseCliDump_c += '#include "PaseCliDev.h"' + "\n"
file_PaseCliDump_c += '#include "PaseCliPrintf.h"' + "\n"
file_PaseCliDump_c += "" + "\n"
file_PaseCliDump_c += "" + "\n"
file_PaseCliDump_c += PaseCliDump_c_main
with open("PaseCliDump_gen.c", "w") as text_file:
    text_file.write(file_PaseCliDump_c)

# write PaseCliAsync.h
file_PaseCliAsync_h = ""
file_PaseCliAsync_h += '#ifndef _PASECLIASYNC_H' + "\n"
file_PaseCliAsync_h += '#define _PASECLIASYNC_H' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += file_pase_incl
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '#ifdef __cplusplus' + "\n"
file_PaseCliAsync_h += 'extern "C" {' + "\n"
file_PaseCliAsync_h += '#endif' + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * Using the driver' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "/* " + "\n"
file_PaseCliAsync_h += ' * SQL400Environment -- set the mode of driver' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * === UTF-8 mode, most popular AIX/PASE/Linux ===' + "\n"
file_PaseCliAsync_h += ' * SQLOverrideCCSID400(1208) -- UTF-8 mode, CLI normal/async direct ILE call' + "\n"
file_PaseCliAsync_h += ' * -->SQLExecDirect(Async)-->ILE_SQLExecDirect-->DB2' + "\n"
file_PaseCliAsync_h += ' * -->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * === UTF-8 mode, most popular Windows/Java ===' + "\n"
file_PaseCliAsync_h += ' * SQLOverrideCCSID400(1200) -- UTF-16 mode, CLI normal/async direct ILE call' + "\n"
file_PaseCliAsync_h += ' * -->SQLExecDirect(Async)-->ILE_SQLExecDirectW-->DB2' + "\n"
file_PaseCliAsync_h += ' * -->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * === PASE default (original libdb400.a) ===' + "\n"
file_PaseCliAsync_h += ' * SQLOverrideCCSID400(other) -- PASE ccsid, CLI API calls PASE libdb400.a' + "\n"
file_PaseCliAsync_h += ' * -->SQLExecDirect(Async)-->PASE libdb400.a(SQLExecDirect)-->DB2' + "\n"
file_PaseCliAsync_h += ' * -->SQLExecDirectW(Async)-->ILE_SQLExecDirectW-->DB2 (*)' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * PASE ccsid setting occurs before any other CLI operations' + "\n"
file_PaseCliAsync_h += ' * at the environment level. Therefore the driver mode is' + "\n"
file_PaseCliAsync_h += ' * established (restricted, if you choose). ' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * 1) non-Unicode interfaces (call old libdb400.a, messy stuff):' + "\n"
file_PaseCliAsync_h += ' *   int ccsid = 819;' + "\n"
file_PaseCliAsync_h += ' *   env attr SQL400_ATTR_PASE_CCSID &ccsid -- set pase ccsid' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * 2) UTF8 interfaces (call direct to ILE DB2):' + "\n"
file_PaseCliAsync_h += ' *   int ccsid = 1208;' + "\n"
file_PaseCliAsync_h += ' *   env attr SQL400_ATTR_PASE_CCSID &ccsid -- set pase ccsid' + "\n"
file_PaseCliAsync_h += ' *   if ccsid == 1208:' + "\n"
file_PaseCliAsync_h += ' *     env attr SQL_ATTR_UTF8 &true -- no conversion required by PASE' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * 3) UTF16 wide interfaces (call direct to ILE DB2):' + "\n"
file_PaseCliAsync_h += ' *   **** NEVER set PASE_CCSID or ATTR_UTF8 in UTF-16 mode. ****' + "\n"
file_PaseCliAsync_h += ' *   So, database exotic ebcdic column and PASE binds c type as WVARCHAR/WCHAR output is UTF16?' + "\n"
file_PaseCliAsync_h += ' *   Yes, the database will do the conversion from EBCDIC to UTF16 for data bound as WVARCHAR/WCHAR.' + "\n"
file_PaseCliAsync_h += ' *   not sure about DBCLOB -- I want to guess that is bound as UTF-16, not 100% sure.' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * IF your data not UTF-8 or UTF-16, interfaces to convert (experimental).' + "\n"
file_PaseCliAsync_h += ' *   SQL400ToUtf8    -- use before passing to CLI normal interfaces' + "\n"
file_PaseCliAsync_h += ' *   SQL400FromUtf8  -- use return output normal CLI (if needed)' + "\n"
file_PaseCliAsync_h += ' *   SQL400ToUtf16   -- use before passing to CLI wide interfaces' + "\n"
file_PaseCliAsync_h += ' *   SQL400FromUtf16 -- use return output wide CLI (if needed)' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += " * A choice of exported APIs (SQLExecDirect one of many):" + "\n"
file_PaseCliAsync_h += " * " + "\n"
file_PaseCliAsync_h += ' * === CLI APIs UTF-8 or APIWs UTF-16  ===' + "\n"
file_PaseCliAsync_h += ' * === choose async and/or normal wait ===' + "\n" 
file_PaseCliAsync_h += ' * SQLRETURN SQLExecDirect(..);' + "\n"
file_PaseCliAsync_h += ' * SQLRETURN SQLExecDirectW(..);' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * == callback or reap/join with async ===' + "\n"
file_PaseCliAsync_h += ' * pthread_t SQLExecDirectAsync(..);' + "\n"
file_PaseCliAsync_h += ' * pthread_t SQLExecDirectWAsync(..);' + "\n"
file_PaseCliAsync_h += ' * void SQLExecDirectCallback(SQLExecDirectStruct* );' + "\n"
file_PaseCliAsync_h += ' * SQLExecDirectStruct * SQLExecDirectJoin (pthread_t tid, SQLINTEGER flag);' + "\n"
file_PaseCliAsync_h += ' * void SQLExecDirectWCallback(SQLExecDirectWStruct* );' + "\n"
file_PaseCliAsync_h += ' * SQLExecDirectWStruct * SQLExecDirectWJoin (pthread_t tid, SQLINTEGER flag);' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * === bypass all, call PASE libdb400.a directly  (not recommended) ===' + "\n"
file_PaseCliAsync_h += ' * SQLRETURN libdb400_SQLExecDirect(..);' + "\n"
file_PaseCliAsync_h += ' * SQLRETURN libdb400_SQLExecDirectW(..); (*)' + "\n"
file_PaseCliAsync_h += ' * ' + "\n"
file_PaseCliAsync_h += ' * === bypass all, call ILE directly (not recommended) ===' + "\n"
file_PaseCliAsync_h += ' * SQLRETURN ILE_SQLExecDirect(..);' + "\n"
file_PaseCliAsync_h += ' * SQLRETURN ILE_SQLExecDirectW(..);' + "\n"
file_PaseCliAsync_h += " * " + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * CUSTOM interfaces' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* Use:' + "\n"
file_PaseCliAsync_h += ' *   SQL400Environment ( ..., SQLPOINTER  options )' + "\n"
file_PaseCliAsync_h += ' *   SQL400Connect ( ..., SQLPOINTER  options )' + "\n"
file_PaseCliAsync_h += ' *   SQL400SetAttr ( ..., SQLPOINTER  options )' + "\n"
file_PaseCliAsync_h += ' * CTOR:' + "\n"
file_PaseCliAsync_h += ' *   SQL400AddAttr' + "\n"
file_PaseCliAsync_h += ' * Struct:' + "\n"
file_PaseCliAsync_h += ' *   SQL400AttrStruct' + "\n"
file_PaseCliAsync_h += ' *     e - EnvAttr' + "\n"
file_PaseCliAsync_h += ' *     c - ConnectAttr' + "\n"
file_PaseCliAsync_h += ' *     s - StmtAttr' + "\n"
file_PaseCliAsync_h += ' *     o - StmtOption' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += '/* CLI hidden attributes */' + "\n"
file_PaseCliAsync_h += '#define SQL400_ATTR_PASE_CCSID 10011' + "\n"
file_PaseCliAsync_h += '#define SQL400_ATTR_CONN_JDBC 10201' + "\n"
file_PaseCliAsync_h += '/* stop or not on attribute failure */' + "\n"
file_PaseCliAsync_h += '#define SQL400_ONERR_CONT 1' + "\n"
file_PaseCliAsync_h += '#define SQL400_ONERR_STOP 2' + "\n"
file_PaseCliAsync_h += '/* normal attributes */' + "\n"
file_PaseCliAsync_h += '#define SQL400_FLAG_IMMED 0' + "\n"
file_PaseCliAsync_h += '/* post connect attributes */' + "\n"
file_PaseCliAsync_h += '#define SQL400_FLAG_POST_CONNECT 1' + "\n"
file_PaseCliAsync_h += '#define SQL400_ATTR_CONN_CHGCURLIB 424201' + "\n"
file_PaseCliAsync_h += '#define SQL400_ATTR_CONN_CHGLIBL 424202' + "\n"
file_PaseCliAsync_h += 'typedef struct SQL400AttrStruct {' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER scope;   /*      - scope  - SQL_HANDLE_ENV|DBC|SRTMT|DESC */' + "\n"
file_PaseCliAsync_h += ' SQLHANDLE  hndl;    /* ecso - hndl   - CLI handle                    */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER attrib;  /* ecso - attrib - CLI attribute                 */' + "\n"
file_PaseCliAsync_h += ' SQLPOINTER vParam;  /* ecso - vParam - ptr to CLI value              */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER inlen;   /* ecs  - inlen  - len CLI value (string)        */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER sqlrc;   /*      - sqlrc  - sql return code               */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER onerr;   /*      - onerr  - SQL400_ONERR_xxx              */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER flag;    /*      - flag   - SQL400_FLAG_xxx               */' + "\n"
file_PaseCliAsync_h += '} SQL400AttrStruct;' + "\n"
file_PaseCliAsync_h += '/* Use:' + "\n"
file_PaseCliAsync_h += ' *   SQL400Execute( ..., SQLPOINTER parms, SQLPOINTER desc_parms)' + "\n"
file_PaseCliAsync_h += ' *   SQL400Fetch (..., SQLPOINTER desc_cols)' + "\n"
file_PaseCliAsync_h += ' * CTOR:' + "\n"
file_PaseCliAsync_h += ' *   SQL400Describe' + "\n"
file_PaseCliAsync_h += ' *   SQL400AddCVar' + "\n"
file_PaseCliAsync_h += ' * Struct:' + "\n"
file_PaseCliAsync_h += ' *   SQL400ParamStruct' + "\n"
file_PaseCliAsync_h += ' *   SQL400DescribeStruct' + "\n"
file_PaseCliAsync_h += ' *     p - SQLDescribeParam' + "\n"
file_PaseCliAsync_h += ' *     c - SQLDescribeCol' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += '#define SQL400_DESC_PARM 0' + "\n"
file_PaseCliAsync_h += '#define SQL400_DESC_COL  1' + "\n"
file_PaseCliAsync_h += '#define SQL400_PARM_IO_FILE 42' + "\n"
file_PaseCliAsync_h += 'typedef struct SQL400ParamStruct {' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT icol;            /* icol         - param number      (in)  */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT inOutType;       /* inOutType    - sql C in/out flag (in)  */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT pfSqlCType;      /* pfSqlCType   - sql C data type   (in)  */' + "\n"
file_PaseCliAsync_h += ' SQLPOINTER  pfSqlCValue;     /* pfSqlCValue  - sql C ptr to data (out) */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER * indPtr;         /* indPtr       - sql strlen/ind    (out) */' + "\n"
file_PaseCliAsync_h += '} SQL400ParamStruct;' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += 'typedef struct SQL400DescStruct {' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT itype;           /*    - itype        - descr col/parm  (out) */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT icol;            /* pc - icol         - column number   (in)  */' + "\n"
file_PaseCliAsync_h += ' SQLCHAR *   szColName;       /*  c - szColName    - column name ptr (out) */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT cbColNameMax;    /*  c - cbColNameMax - name max len    (in)  */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT pcbColName;      /*  c - pcbColName   - name size len   (out) */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT pfSqlType;       /* pc - pfSqlType    - sql data type   (out) */' + "\n"
file_PaseCliAsync_h += ' SQLINTEGER  pcbColDef;       /* pc - pcbColDef    - sql size column (out) */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT pibScale;        /* pc - pibScale     - decimal digits  (out) */' + "\n"
file_PaseCliAsync_h += ' SQLSMALLINT pfNullable;      /* pc - pfNullable   - null allowed    (out) */' + "\n"
file_PaseCliAsync_h += ' SQLCHAR     bfColName[1024]; /*  c - bfColName    - column name buf (out) */' + "\n"
file_PaseCliAsync_h += '} SQL400DescStruct;' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "/* special SQL400 aggregate functions */" + "\n"
file_PaseCliAsync_h += "/* do common work for language driver */" + "\n"
file_PaseCliAsync_h += "/* composite calls to CLI also async  */" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliOnly400_h_proto
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * NORMAL CLI interfaces' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "/* === sqlcli.h -- normal CLI interfaces (copy) === " + "\n"
file_PaseCliAsync_h += PaseCliAny_h_proto
file_PaseCliAsync_h += " * === sqlcli.h === */" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * ASYNC CLI interfaces' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "/* choose either callback or join    */" + "\n"
file_PaseCliAsync_h += "/* following structures returned     */" + "\n"
file_PaseCliAsync_h += "/* caller must free return structure */" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliAsync_h_struct + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "/* join async thread                    */" + "\n"
file_PaseCliAsync_h += "/* flag:                                */" + "\n"
file_PaseCliAsync_h += "/*   SQL400_FLAG_JOIN_WAIT              */" + "\n"
file_PaseCliAsync_h += "/*     - block until complete           */" + "\n"
file_PaseCliAsync_h += "/*   SQL400_FLAG_JOIN_NO_WAIT           */" + "\n"
file_PaseCliAsync_h += "/*     - no block, NULL still executing */" + "\n"
file_PaseCliAsync_h += '#define SQL400_FLAG_JOIN_WAIT 0' + "\n"
file_PaseCliAsync_h += '#define SQL400_FLAG_JOIN_NO_WAIT 1' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliAsync_h_proto_join
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "/* start an async call to DB2 CLI */" + "\n"
file_PaseCliAsync_h += "/* choose either callback or join */" + "\n"
file_PaseCliAsync_h += "/* for results returned.          */" + "\n"
file_PaseCliAsync_h += "/* sqlrc returned in structure.   */" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliAsync_h_proto_async
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * ILE CLI interfaces' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliILE_h_proto
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * LIBDB400.A CLI interfaces (PASE old CLI driver)' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliLibDB400_h_proto
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * trace dump' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliDump_h_proto
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '/* ===================================================' + "\n"
file_PaseCliAsync_h += ' * INTERNAL USE' + "\n"
file_PaseCliAsync_h += ' * ===================================================' + "\n"
file_PaseCliAsync_h += ' */' + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += PaseCliCustom_h_proto
file_PaseCliAsync_h += "SQLRETURN custom_SQLSetEnvCCSID( SQLHANDLE env, int myccsid);" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += "" + "\n"
file_PaseCliAsync_h += '#ifdef __cplusplus ' + "\n"
file_PaseCliAsync_h += '}' + "\n"
file_PaseCliAsync_h += '#endif /* __cplusplus */' + "\n"
file_PaseCliAsync_h += '#endif /* _PASECLIASYNC_H */' + "\n"
with open("PaseCliAsync.h", "w") as text_file:
    text_file.write(file_PaseCliAsync_h)


# write libdb400.exp
file_libdb400_exp = ""
file_libdb400_exp += "#!libdb400.a(shr.o)" + "\n"
file_libdb400_exp += "" + "\n"
file_libdb400_exp += "" + "\n"
file_libdb400_exp += libdb400_exp
file_libdb400_exp += "" + "\n"
file_libdb400_exp += "" + "\n"
file_libdb400_exp += "dev_dump" + "\n"
file_libdb400_exp += "dev_go" + "\n"
file_libdb400_exp += "printf_key" + "\n"
file_libdb400_exp += "printf_buffer" + "\n"
file_libdb400_exp += "printf_clear" + "\n"
file_libdb400_exp += "printf_format" + "\n"
file_libdb400_exp += "printf_hexdump" + "\n"
file_libdb400_exp += "printf_stack" + "\n"
file_libdb400_exp += "printf_script" + "\n"
file_libdb400_exp += "printf_script_include" + "\n"
file_libdb400_exp += "printf_script_exclude" + "\n"
file_libdb400_exp += "printf_script_clear" + "\n"
file_libdb400_exp += "printf_force_SIGQUIT" + "\n"
file_libdb400_exp += "printf_sqlrc_status" + "\n"
file_libdb400_exp += "printf_sqlrc_head_foot" + "\n"
file_libdb400_exp += "sprintf_format" + "\n"
file_libdb400_exp += "" + "\n"
file_libdb400_exp += "" + "\n"
with open("libdb400.exp", "w") as text_file:
    text_file.write(file_libdb400_exp)

