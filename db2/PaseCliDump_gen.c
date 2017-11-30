#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>
#include <sqlcli1.h>
#include <as400_types.h>
#include <as400_protos.h>
#include "PaseCliInit.h"
#include "PaseCliAsync.h"
#include "PaseCliDev.h"
#include "PaseCliPrintf.h"


void dump_SQLAllocConnect(SQLRETURN sqlrc,  SQLHENV  henv, SQLHDBC * phdbc ) {
  if (dev_go(sqlrc,"sqlallocconnect")) {
    char mykey[256];
    printf_key(mykey,"SQLAllocConnect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC*","phdbc",phdbc,phdbc);
    printf_hexdump(mykey,phdbc,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLAllocEnv(SQLRETURN sqlrc,  SQLHENV * phenv ) {
  if (dev_go(sqlrc,"sqlallocenv")) {
    char mykey[256];
    printf_key(mykey,"SQLAllocEnv");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV*","phenv",phenv,phenv);
    printf_hexdump(mykey,phenv,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLAllocHandle(SQLRETURN sqlrc,  SQLSMALLINT  htype, SQLINTEGER  ihnd, SQLINTEGER * ohnd ) {
  if (dev_go(sqlrc,"sqlallochandle")) {
    char mykey[256];
    printf_key(mykey,"SQLAllocHandle");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","htype",htype,htype);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","ihnd",ihnd,ihnd);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLAllocStmt(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLHSTMT * phstmt ) {
  if (dev_go(sqlrc,"sqlallocstmt")) {
    char mykey[256];
    printf_key(mykey,"SQLAllocStmt");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT*","phstmt",phstmt,phstmt);
    printf_hexdump(mykey,phstmt,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLBindCol(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlbindcol")) {
    char mykey[256];
    printf_key(mykey,"SQLBindCol");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iType",iType,iType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbValue",rgbValue,rgbValue);
    printf_hexdump(mykey,rgbValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbValueMax",cbValueMax,cbValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLBindFileToCol(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * sLen, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlbindfiletocol")) {
    char mykey[256];
    printf_key(mykey,"SQLBindFileToCol");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","fName",fName,fName);
    printf_hexdump(mykey,fName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fNameLen",fNameLen,fNameLen);
    printf_hexdump(mykey,fNameLen,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","fOptions",fOptions,fOptions);
    printf_hexdump(mykey,fOptions,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fValueMax",fValueMax,fValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","sLen",sLen,sLen);
    printf_hexdump(mykey,sLen,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLBindFileToParam(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  iType, SQLCHAR * fName, SQLSMALLINT * fNameLen, SQLINTEGER * fOptions, SQLSMALLINT  fValueMax, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlbindfiletoparam")) {
    char mykey[256];
    printf_key(mykey,"SQLBindFileToParam");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","ipar",ipar,ipar);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iType",iType,iType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","fName",fName,fName);
    printf_hexdump(mykey,fName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fNameLen",fNameLen,fNameLen);
    printf_hexdump(mykey,fNameLen,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","fOptions",fOptions,fOptions);
    printf_hexdump(mykey,fOptions,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fValueMax",fValueMax,fValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLBindParam(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  iparm, SQLSMALLINT  iType, SQLSMALLINT  pType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlbindparam")) {
    char mykey[256];
    printf_key(mykey,"SQLBindParam");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iparm",iparm,iparm);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iType",iType,iType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","pType",pType,pType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","pLen",pLen,pLen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","pScale",pScale,pScale);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pData",pData,pData);
    printf_hexdump(mykey,pData,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLBindParameter(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fParamType, SQLSMALLINT  fCType, SQLSMALLINT  fSQLType, SQLINTEGER  pLen, SQLSMALLINT  pScale, SQLPOINTER  pData, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlbindparameter")) {
    char mykey[256];
    printf_key(mykey,"SQLBindParameter");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","ipar",ipar,ipar);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fParamType",fParamType,fParamType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fCType",fCType,fCType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fSQLType",fSQLType,fSQLType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","pLen",pLen,pLen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","pScale",pScale,pScale);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pData",pData,pData);
    printf_hexdump(mykey,pData,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbValueMax",cbValueMax,cbValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLCancel(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sqlcancel")) {
    char mykey[256];
    printf_key(mykey,"SQLCancel");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLCloseCursor(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sqlclosecursor")) {
    char mykey[256];
    printf_key(mykey,"SQLCloseCursor");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColAttribute(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc ) {
  if (dev_go(sqlrc,"sqlcolattribute")) {
    char mykey[256];
    printf_key(mykey,"SQLColAttribute");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDescType",fDescType,fDescType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbDesc",rgbDesc,rgbDesc);
    printf_hexdump(mykey,rgbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDescMax",cbDescMax,cbDescMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbDesc",pcbDesc,pcbDesc);
    printf_hexdump(mykey,pcbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pfDesc",pfDesc,pfDesc);
    printf_hexdump(mykey,pfDesc,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColAttributeW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLPOINTER  rgbDesc, SQLSMALLINT  cbDescMax, SQLSMALLINT * pcbDesc, SQLPOINTER  pfDesc ) {
  if (dev_go(sqlrc,"sqlcolattributew")) {
    char mykey[256];
    printf_key(mykey,"SQLColAttributeW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDescType",fDescType,fDescType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbDesc",rgbDesc,rgbDesc);
    printf_hexdump(mykey,rgbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDescMax",cbDescMax,cbDescMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbDesc",pcbDesc,pcbDesc);
    printf_hexdump(mykey,pcbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pfDesc",pfDesc,pfDesc);
    printf_hexdump(mykey,pfDesc,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColAttributes(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc ) {
  if (dev_go(sqlrc,"sqlcolattributes")) {
    char mykey[256];
    printf_key(mykey,"SQLColAttributes");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDescType",fDescType,fDescType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","rgbDesc",rgbDesc,rgbDesc);
    printf_hexdump(mykey,rgbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbDescMax",cbDescMax,cbDescMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbDesc",pcbDesc,pcbDesc);
    printf_hexdump(mykey,pcbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pfDesc",pfDesc,pfDesc);
    printf_hexdump(mykey,pfDesc,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColAttributesW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fDescType, SQLWCHAR * rgbDesc, SQLINTEGER  cbDescMax, SQLINTEGER * pcbDesc, SQLINTEGER * pfDesc ) {
  if (dev_go(sqlrc,"sqlcolattributesw")) {
    char mykey[256];
    printf_key(mykey,"SQLColAttributesW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDescType",fDescType,fDescType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","rgbDesc",rgbDesc,rgbDesc);
    printf_hexdump(mykey,rgbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbDescMax",cbDescMax,cbDescMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbDesc",pcbDesc,pcbDesc);
    printf_hexdump(mykey,pcbDesc,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pfDesc",pfDesc,pfDesc);
    printf_hexdump(mykey,pfDesc,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColumnPrivileges(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  if (dev_go(sqlrc,"sqlcolumnprivileges")) {
    char mykey[256];
    printf_key(mykey,"SQLColumnPrivileges");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szColumnName",szColumnName,szColumnName);
    printf_hexdump(mykey,szColumnName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColumnName",cbColumnName,cbColumnName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColumnPrivilegesW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  if (dev_go(sqlrc,"sqlcolumnprivilegesw")) {
    char mykey[256];
    printf_key(mykey,"SQLColumnPrivilegesW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szColumnName",szColumnName,szColumnName);
    printf_hexdump(mykey,szColumnName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColumnName",cbColumnName,cbColumnName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColumns(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  if (dev_go(sqlrc,"sqlcolumns")) {
    char mykey[256];
    printf_key(mykey,"SQLColumns");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szColumnName",szColumnName,szColumnName);
    printf_hexdump(mykey,szColumnName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColumnName",cbColumnName,cbColumnName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLColumnsW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  if (dev_go(sqlrc,"sqlcolumnsw")) {
    char mykey[256];
    printf_key(mykey,"SQLColumnsW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szColumnName",szColumnName,szColumnName);
    printf_hexdump(mykey,szColumnName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColumnName",cbColumnName,cbColumnName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLConnect(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLCHAR * szDSN, SQLSMALLINT  cbDSN, SQLCHAR * szUID, SQLSMALLINT  cbUID, SQLCHAR * szAuthStr, SQLSMALLINT  cbAuthStr ) {
  if (dev_go(sqlrc,"sqlconnect")) {
    char mykey[256];
    printf_key(mykey,"SQLConnect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szDSN",szDSN,szDSN);
    printf_hexdump(mykey,szDSN,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDSN",cbDSN,cbDSN);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szUID",szUID,szUID);
    printf_hexdump(mykey,szUID,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbUID",cbUID,cbUID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szAuthStr",szAuthStr,szAuthStr);
    printf_hexdump(mykey,szAuthStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbAuthStr",cbAuthStr,cbAuthStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLConnectW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLWCHAR * szDSN, SQLSMALLINT  cbDSN, SQLWCHAR * szUID, SQLSMALLINT  cbUID, SQLWCHAR * szAuthStr, SQLSMALLINT  cbAuthStr ) {
  if (dev_go(sqlrc,"sqlconnectw")) {
    char mykey[256];
    printf_key(mykey,"SQLConnectW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szDSN",szDSN,szDSN);
    printf_hexdump(mykey,szDSN,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDSN",cbDSN,cbDSN);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szUID",szUID,szUID);
    printf_hexdump(mykey,szUID,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbUID",cbUID,cbUID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szAuthStr",szAuthStr,szAuthStr);
    printf_hexdump(mykey,szAuthStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbAuthStr",cbAuthStr,cbAuthStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLCopyDesc(SQLRETURN sqlrc,  SQLHDESC  sDesc, SQLHDESC  tDesc ) {
  if (dev_go(sqlrc,"sqlcopydesc")) {
    char mykey[256];
    printf_key(mykey,"SQLCopyDesc");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","sDesc",sDesc,sDesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","tDesc",tDesc,tDesc);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,tDesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDataSources(SQLRETURN sqlrc,  SQLHENV  henv, SQLSMALLINT  fDirection, SQLCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription ) {
  if (dev_go(sqlrc,"sqldatasources")) {
    char mykey[256];
    printf_key(mykey,"SQLDataSources");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDirection",fDirection,fDirection);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szDSN",szDSN,szDSN);
    printf_hexdump(mykey,szDSN,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDSNMax",cbDSNMax,cbDSNMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbDSN",pcbDSN,pcbDSN);
    printf_hexdump(mykey,pcbDSN,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szDescription",szDescription,szDescription);
    printf_hexdump(mykey,szDescription,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDescriptionMax",cbDescriptionMax,cbDescriptionMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbDescription",pcbDescription,pcbDescription);
    printf_hexdump(mykey,pcbDescription,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDataSourcesW(SQLRETURN sqlrc,  SQLHENV  henv, SQLSMALLINT  fDirection, SQLWCHAR * szDSN, SQLSMALLINT  cbDSNMax, SQLSMALLINT * pcbDSN, SQLWCHAR * szDescription, SQLSMALLINT  cbDescriptionMax, SQLSMALLINT * pcbDescription ) {
  if (dev_go(sqlrc,"sqldatasourcesw")) {
    char mykey[256];
    printf_key(mykey,"SQLDataSourcesW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDirection",fDirection,fDirection);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szDSN",szDSN,szDSN);
    printf_hexdump(mykey,szDSN,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDSNMax",cbDSNMax,cbDSNMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbDSN",pcbDSN,pcbDSN);
    printf_hexdump(mykey,pcbDSN,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szDescription",szDescription,szDescription);
    printf_hexdump(mykey,szDescription,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbDescriptionMax",cbDescriptionMax,cbDescriptionMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbDescription",pcbDescription,pcbDescription);
    printf_hexdump(mykey,pcbDescription,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDescribeCol(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  if (dev_go(sqlrc,"sqldescribecol")) {
    char mykey[256];
    printf_key(mykey,"SQLDescribeCol");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szColName",szColName,szColName);
    printf_hexdump(mykey,szColName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColNameMax",cbColNameMax,cbColNameMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbColName",pcbColName,pcbColName);
    printf_hexdump(mykey,pcbColName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfSqlType",pfSqlType,pfSqlType);
    printf_hexdump(mykey,pfSqlType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbColDef",pcbColDef,pcbColDef);
    printf_hexdump(mykey,pcbColDef,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pibScale",pibScale,pibScale);
    printf_hexdump(mykey,pibScale,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfNullable",pfNullable,pfNullable);
    printf_hexdump(mykey,pfNullable,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDescribeColW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLWCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  if (dev_go(sqlrc,"sqldescribecolw")) {
    char mykey[256];
    printf_key(mykey,"SQLDescribeColW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szColName",szColName,szColName);
    printf_hexdump(mykey,szColName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColNameMax",cbColNameMax,cbColNameMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbColName",pcbColName,pcbColName);
    printf_hexdump(mykey,pcbColName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfSqlType",pfSqlType,pfSqlType);
    printf_hexdump(mykey,pfSqlType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbColDef",pcbColDef,pcbColDef);
    printf_hexdump(mykey,pcbColDef,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pibScale",pibScale,pibScale);
    printf_hexdump(mykey,pibScale,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfNullable",pfNullable,pfNullable);
    printf_hexdump(mykey,pfNullable,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDescribeParam(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  if (dev_go(sqlrc,"sqldescribeparam")) {
    char mykey[256];
    printf_key(mykey,"SQLDescribeParam");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","ipar",ipar,ipar);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfSqlType",pfSqlType,pfSqlType);
    printf_hexdump(mykey,pfSqlType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbColDef",pcbColDef,pcbColDef);
    printf_hexdump(mykey,pcbColDef,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pibScale",pibScale,pibScale);
    printf_hexdump(mykey,pibScale,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfNullable",pfNullable,pfNullable);
    printf_hexdump(mykey,pfNullable,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDisconnect(SQLRETURN sqlrc,  SQLHDBC  hdbc ) {
  if (dev_go(sqlrc,"sqldisconnect")) {
    char mykey[256];
    printf_key(mykey,"SQLDisconnect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDriverConnect(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion ) {
  if (dev_go(sqlrc,"sqldriverconnect")) {
    char mykey[256];
    printf_key(mykey,"SQLDriverConnect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","hwnd",hwnd,hwnd);
    printf_hexdump(mykey,hwnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szConnStrIn",szConnStrIn,szConnStrIn);
    printf_hexdump(mykey,szConnStrIn,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbConnStrin",cbConnStrin,cbConnStrin);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szConnStrOut",szConnStrOut,szConnStrOut);
    printf_hexdump(mykey,szConnStrOut,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbConnStrOutMax",cbConnStrOutMax,cbConnStrOutMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbConnStrOut",pcbConnStrOut,pcbConnStrOut);
    printf_hexdump(mykey,pcbConnStrOut,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDriverCompletion",fDriverCompletion,fDriverCompletion);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLDriverConnectW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  hwnd, SQLWCHAR * szConnStrIn, SQLSMALLINT  cbConnStrin, SQLWCHAR * szConnStrOut, SQLSMALLINT  cbConnStrOutMax, SQLSMALLINT * pcbConnStrOut, SQLSMALLINT  fDriverCompletion ) {
  if (dev_go(sqlrc,"sqldriverconnectw")) {
    char mykey[256];
    printf_key(mykey,"SQLDriverConnectW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","hwnd",hwnd,hwnd);
    printf_hexdump(mykey,hwnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szConnStrIn",szConnStrIn,szConnStrIn);
    printf_hexdump(mykey,szConnStrIn,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbConnStrin",cbConnStrin,cbConnStrin);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szConnStrOut",szConnStrOut,szConnStrOut);
    printf_hexdump(mykey,szConnStrOut,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbConnStrOutMax",cbConnStrOutMax,cbConnStrOutMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbConnStrOut",pcbConnStrOut,pcbConnStrOut);
    printf_hexdump(mykey,pcbConnStrOut,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fDriverCompletion",fDriverCompletion,fDriverCompletion);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLEndTran(SQLRETURN sqlrc,  SQLSMALLINT  htype, SQLHENV  henv, SQLSMALLINT  ctype ) {
  if (dev_go(sqlrc,"sqlendtran")) {
    char mykey[256];
    printf_key(mykey,"SQLEndTran");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","htype",htype,htype);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","ctype",ctype,ctype);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLError(SQLRETURN sqlrc,  SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg ) {
  if (dev_go(sqlrc,"sqlerror")) {
    char mykey[256];
    printf_key(mykey,"SQLError");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlState",szSqlState,szSqlState);
    printf_hexdump(mykey,szSqlState,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pfNativeError",pfNativeError,pfNativeError);
    printf_hexdump(mykey,pfNativeError,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szErrorMsg",szErrorMsg,szErrorMsg);
    printf_hexdump(mykey,szErrorMsg,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbErrorMsgMax",cbErrorMsgMax,cbErrorMsgMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbErrorMsg",pcbErrorMsg,pcbErrorMsg);
    printf_hexdump(mykey,pcbErrorMsg,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLErrorW(SQLRETURN sqlrc,  SQLHENV  henv, SQLHDBC  hdbc, SQLHSTMT  hstmt, SQLWCHAR * szSqlState, SQLINTEGER * pfNativeError, SQLWCHAR * szErrorMsg, SQLSMALLINT  cbErrorMsgMax, SQLSMALLINT * pcbErrorMsg ) {
  if (dev_go(sqlrc,"sqlerrorw")) {
    char mykey[256];
    printf_key(mykey,"SQLErrorW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szSqlState",szSqlState,szSqlState);
    printf_hexdump(mykey,szSqlState,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pfNativeError",pfNativeError,pfNativeError);
    printf_hexdump(mykey,pfNativeError,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szErrorMsg",szErrorMsg,szErrorMsg);
    printf_hexdump(mykey,szErrorMsg,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbErrorMsgMax",cbErrorMsgMax,cbErrorMsgMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbErrorMsg",pcbErrorMsg,pcbErrorMsg);
    printf_hexdump(mykey,pcbErrorMsg,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLExecDirect(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  if (dev_go(sqlrc,"sqlexecdirect")) {
    char mykey[256];
    printf_key(mykey,"SQLExecDirect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStr",cbSqlStr,cbSqlStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLExecDirectW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  if (dev_go(sqlrc,"sqlexecdirectw")) {
    char mykey[256];
    printf_key(mykey,"SQLExecDirectW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStr",cbSqlStr,cbSqlStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLExecute(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sqlexecute")) {
    char mykey[256];
    printf_key(mykey,"SQLExecute");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLExtendedFetch(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset, SQLINTEGER * pcrow, SQLSMALLINT * rgfRowStatus ) {
  if (dev_go(sqlrc,"sqlextendedfetch")) {
    char mykey[256];
    printf_key(mykey,"SQLExtendedFetch");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOrient",fOrient,fOrient);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fOffset",fOffset,fOffset);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcrow",pcrow,pcrow);
    printf_hexdump(mykey,pcrow,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","rgfRowStatus",rgfRowStatus,rgfRowStatus);
    printf_hexdump(mykey,rgfRowStatus,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLFetch(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sqlfetch")) {
    char mykey[256];
    printf_key(mykey,"SQLFetch");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLFetchScroll(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOrient, SQLINTEGER  fOffset ) {
  if (dev_go(sqlrc,"sqlfetchscroll")) {
    char mykey[256];
    printf_key(mykey,"SQLFetchScroll");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOrient",fOrient,fOrient);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fOffset",fOffset,fOffset);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLForeignKeys(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLCHAR * szFkTableName, SQLSMALLINT  cbFkTableName ) {
  if (dev_go(sqlrc,"sqlforeignkeys")) {
    char mykey[256];
    printf_key(mykey,"SQLForeignKeys");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szPkTableQualifier",szPkTableQualifier,szPkTableQualifier);
    printf_hexdump(mykey,szPkTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbPkTableQualifier",cbPkTableQualifier,cbPkTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szPkTableOwner",szPkTableOwner,szPkTableOwner);
    printf_hexdump(mykey,szPkTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbPkTableOwner",cbPkTableOwner,cbPkTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szPkTableName",szPkTableName,szPkTableName);
    printf_hexdump(mykey,szPkTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbPkTableName",cbPkTableName,cbPkTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szFkTableQualifier",szFkTableQualifier,szFkTableQualifier);
    printf_hexdump(mykey,szFkTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbFkTableQualifier",cbFkTableQualifier,cbFkTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szFkTableOwner",szFkTableOwner,szFkTableOwner);
    printf_hexdump(mykey,szFkTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbFkTableOwner",cbFkTableOwner,cbFkTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szFkTableName",szFkTableName,szFkTableName);
    printf_hexdump(mykey,szFkTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbFkTableName",cbFkTableName,cbFkTableName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLForeignKeysW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szPkTableQualifier, SQLSMALLINT  cbPkTableQualifier, SQLWCHAR * szPkTableOwner, SQLSMALLINT  cbPkTableOwner, SQLWCHAR * szPkTableName, SQLSMALLINT  cbPkTableName, SQLWCHAR * szFkTableQualifier, SQLSMALLINT  cbFkTableQualifier, SQLWCHAR * szFkTableOwner, SQLSMALLINT  cbFkTableOwner, SQLWCHAR * szFkTableName, SQLSMALLINT  cbFkTableName ) {
  if (dev_go(sqlrc,"sqlforeignkeysw")) {
    char mykey[256];
    printf_key(mykey,"SQLForeignKeysW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szPkTableQualifier",szPkTableQualifier,szPkTableQualifier);
    printf_hexdump(mykey,szPkTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbPkTableQualifier",cbPkTableQualifier,cbPkTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szPkTableOwner",szPkTableOwner,szPkTableOwner);
    printf_hexdump(mykey,szPkTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbPkTableOwner",cbPkTableOwner,cbPkTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szPkTableName",szPkTableName,szPkTableName);
    printf_hexdump(mykey,szPkTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbPkTableName",cbPkTableName,cbPkTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szFkTableQualifier",szFkTableQualifier,szFkTableQualifier);
    printf_hexdump(mykey,szFkTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbFkTableQualifier",cbFkTableQualifier,cbFkTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szFkTableOwner",szFkTableOwner,szFkTableOwner);
    printf_hexdump(mykey,szFkTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbFkTableOwner",cbFkTableOwner,cbFkTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szFkTableName",szFkTableName,szFkTableName);
    printf_hexdump(mykey,szFkTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbFkTableName",cbFkTableName,cbFkTableName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLFreeConnect(SQLRETURN sqlrc,  SQLHDBC  hdbc ) {
  if (dev_go(sqlrc,"sqlfreeconnect")) {
    char mykey[256];
    printf_key(mykey,"SQLFreeConnect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLFreeEnv(SQLRETURN sqlrc,  SQLHENV  henv ) {
  if (dev_go(sqlrc,"sqlfreeenv")) {
    char mykey[256];
    printf_key(mykey,"SQLFreeEnv");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLFreeStmt(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOption ) {
  if (dev_go(sqlrc,"sqlfreestmt")) {
    char mykey[256];
    printf_key(mykey,"SQLFreeStmt");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLFreeHandle(SQLRETURN sqlrc,  SQLSMALLINT  htype, SQLINTEGER  hndl ) {
  if (dev_go(sqlrc,"sqlfreehandle")) {
    char mykey[256];
    printf_key(mykey,"SQLFreeHandle");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","htype",htype,htype);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","hndl",hndl,hndl);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetCol(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen ) {
  if (dev_go(sqlrc,"sqlgetcol")) {
    char mykey[256];
    printf_key(mykey,"SQLGetCol");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","itype",itype,itype);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","tval",tval,tval);
    printf_hexdump(mykey,tval,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","blen",blen,blen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","olen",olen,olen);
    printf_hexdump(mykey,olen,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetColW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  itype, SQLPOINTER  tval, SQLINTEGER  blen, SQLINTEGER * olen ) {
  if (dev_go(sqlrc,"sqlgetcolw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetColW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","itype",itype,itype);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","tval",tval,tval);
    printf_hexdump(mykey,tval,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","blen",blen,blen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","olen",olen,olen);
    printf_hexdump(mykey,olen,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetConnectAttr(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen ) {
  if (dev_go(sqlrc,"sqlgetconnectattr")) {
    char mykey[256];
    printf_key(mykey,"SQLGetConnectAttr");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","attr",attr,attr);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","oval",oval,oval);
    printf_hexdump(mykey,oval,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","ilen",ilen,ilen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","olen",olen,olen);
    printf_hexdump(mykey,olen,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetConnectAttrW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLINTEGER  attr, SQLPOINTER  oval, SQLINTEGER  ilen, SQLINTEGER * olen ) {
  if (dev_go(sqlrc,"sqlgetconnectattrw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetConnectAttrW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","attr",attr,attr);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","oval",oval,oval);
    printf_hexdump(mykey,oval,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","ilen",ilen,ilen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","olen",olen,olen);
    printf_hexdump(mykey,olen,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetConnectOption(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval ) {
  if (dev_go(sqlrc,"sqlgetconnectoption")) {
    char mykey[256];
    printf_key(mykey,"SQLGetConnectOption");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iopt",iopt,iopt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","oval",oval,oval);
    printf_hexdump(mykey,oval,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetConnectOptionW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  iopt, SQLPOINTER  oval ) {
  if (dev_go(sqlrc,"sqlgetconnectoptionw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetConnectOptionW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iopt",iopt,iopt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","oval",oval,oval);
    printf_hexdump(mykey,oval,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetCursorName(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor ) {
  if (dev_go(sqlrc,"sqlgetcursorname")) {
    char mykey[256];
    printf_key(mykey,"SQLGetCursorName");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szCursor",szCursor,szCursor);
    printf_hexdump(mykey,szCursor,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbCursorMax",cbCursorMax,cbCursorMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbCursor",pcbCursor,pcbCursor);
    printf_hexdump(mykey,pcbCursor,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetCursorNameW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursorMax, SQLSMALLINT * pcbCursor ) {
  if (dev_go(sqlrc,"sqlgetcursornamew")) {
    char mykey[256];
    printf_key(mykey,"SQLGetCursorNameW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szCursor",szCursor,szCursor);
    printf_hexdump(mykey,szCursor,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbCursorMax",cbCursorMax,cbCursorMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbCursor",pcbCursor,pcbCursor);
    printf_hexdump(mykey,pcbCursor,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetData(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  fCType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlgetdata")) {
    char mykey[256];
    printf_key(mykey,"SQLGetData");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fCType",fCType,fCType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbValue",rgbValue,rgbValue);
    printf_hexdump(mykey,rgbValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbValueMax",cbValueMax,cbValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDescField(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength ) {
  if (dev_go(sqlrc,"sqlgetdescfield")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDescField");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fieldID",fieldID,fieldID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","fValue",fValue,fValue);
    printf_hexdump(mykey,fValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fLength",fLength,fLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","stLength",stLength,stLength);
    printf_hexdump(mykey,stLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDescFieldW(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fieldID, SQLPOINTER  fValue, SQLINTEGER  fLength, SQLINTEGER * stLength ) {
  if (dev_go(sqlrc,"sqlgetdescfieldw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDescFieldW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fieldID",fieldID,fieldID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","fValue",fValue,fValue);
    printf_hexdump(mykey,fValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fLength",fLength,fLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","stLength",stLength,stLength);
    printf_hexdump(mykey,stLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDescRec(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull ) {
  if (dev_go(sqlrc,"sqlgetdescrec")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDescRec");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","fname",fname,fname);
    printf_hexdump(mykey,fname,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","bufLen",bufLen,bufLen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sLength",sLength,sLength);
    printf_hexdump(mykey,sLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sType",sType,sType);
    printf_hexdump(mykey,sType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sbType",sbType,sbType);
    printf_hexdump(mykey,sbType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","fLength",fLength,fLength);
    printf_hexdump(mykey,fLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fprec",fprec,fprec);
    printf_hexdump(mykey,fprec,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fscale",fscale,fscale);
    printf_hexdump(mykey,fscale,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fnull",fnull,fnull);
    printf_hexdump(mykey,fnull,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDescRecW(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLWCHAR * fname, SQLSMALLINT  bufLen, SQLSMALLINT * sLength, SQLSMALLINT * sType, SQLSMALLINT * sbType, SQLINTEGER * fLength, SQLSMALLINT * fprec, SQLSMALLINT * fscale, SQLSMALLINT * fnull ) {
  if (dev_go(sqlrc,"sqlgetdescrecw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDescRecW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","fname",fname,fname);
    printf_hexdump(mykey,fname,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","bufLen",bufLen,bufLen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sLength",sLength,sLength);
    printf_hexdump(mykey,sLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sType",sType,sType);
    printf_hexdump(mykey,sType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sbType",sbType,sbType);
    printf_hexdump(mykey,sbType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","fLength",fLength,fLength);
    printf_hexdump(mykey,fLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fprec",fprec,fprec);
    printf_hexdump(mykey,fprec,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fscale",fscale,fscale);
    printf_hexdump(mykey,fscale,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","fnull",fnull,fnull);
    printf_hexdump(mykey,fnull,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDiagField(SQLRETURN sqlrc,  SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength ) {
  if (dev_go(sqlrc,"sqlgetdiagfield")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDiagField");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","hType",hType,hType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","hndl",hndl,hndl);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","diagID",diagID,diagID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","dValue",dValue,dValue);
    printf_hexdump(mykey,dValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","bLength",bLength,bLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sLength",sLength,sLength);
    printf_hexdump(mykey,sLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDiagFieldW(SQLRETURN sqlrc,  SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLSMALLINT  diagID, SQLPOINTER  dValue, SQLSMALLINT  bLength, SQLSMALLINT * sLength ) {
  if (dev_go(sqlrc,"sqlgetdiagfieldw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDiagFieldW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","hType",hType,hType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","hndl",hndl,hndl);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","diagID",diagID,diagID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","dValue",dValue,dValue);
    printf_hexdump(mykey,dValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","bLength",bLength,bLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","sLength",sLength,sLength);
    printf_hexdump(mykey,sLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDiagRec(SQLRETURN sqlrc,  SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLCHAR * SQLstate, SQLINTEGER * SQLcode, SQLCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength ) {
  if (dev_go(sqlrc,"sqlgetdiagrec")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDiagRec");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","hType",hType,hType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","hndl",hndl,hndl);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","SQLstate",SQLstate,SQLstate);
    printf_hexdump(mykey,SQLstate,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","SQLcode",SQLcode,SQLcode);
    printf_hexdump(mykey,SQLcode,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","msgText",msgText,msgText);
    printf_hexdump(mykey,msgText,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","bLength",bLength,bLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","SLength",SLength,SLength);
    printf_hexdump(mykey,SLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetDiagRecW(SQLRETURN sqlrc,  SQLSMALLINT  hType, SQLINTEGER  hndl, SQLSMALLINT  rcdNum, SQLWCHAR * SQLstate, SQLINTEGER * SQLcode, SQLWCHAR * msgText, SQLSMALLINT  bLength, SQLSMALLINT * SLength ) {
  if (dev_go(sqlrc,"sqlgetdiagrecw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetDiagRecW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","hType",hType,hType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","hndl",hndl,hndl);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","SQLstate",SQLstate,SQLstate);
    printf_hexdump(mykey,SQLstate,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","SQLcode",SQLcode,SQLcode);
    printf_hexdump(mykey,SQLcode,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","msgText",msgText,msgText);
    printf_hexdump(mykey,msgText,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","bLength",bLength,bLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","SLength",SLength,SLength);
    printf_hexdump(mykey,SLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetEnvAttr(SQLRETURN sqlrc,  SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParamMax, SQLINTEGER * pcbParam ) {
  if (dev_go(sqlrc,"sqlgetenvattr")) {
    char mykey[256];
    printf_key(mykey,"SQLGetEnvAttr");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","hEnv",hEnv,hEnv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fAttribute",fAttribute,fAttribute);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pParam",pParam,pParam);
    printf_hexdump(mykey,pParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbParamMax",cbParamMax,cbParamMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbParam",pcbParam,pcbParam);
    printf_hexdump(mykey,pcbParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetFunctions(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  fFunction, SQLSMALLINT * pfExists ) {
  if (dev_go(sqlrc,"sqlgetfunctions")) {
    char mykey[256];
    printf_key(mykey,"SQLGetFunctions");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fFunction",fFunction,fFunction);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfExists",pfExists,pfExists);
    printf_hexdump(mykey,pfExists,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetInfo(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue ) {
  if (dev_go(sqlrc,"sqlgetinfo")) {
    char mykey[256];
    printf_key(mykey,"SQLGetInfo");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fInfoType",fInfoType,fInfoType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbInfoValue",rgbInfoValue,rgbInfoValue);
    printf_hexdump(mykey,rgbInfoValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbInfoValueMax",cbInfoValueMax,cbInfoValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbInfoValue",pcbInfoValue,pcbInfoValue);
    printf_hexdump(mykey,pcbInfoValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetInfoW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  fInfoType, SQLPOINTER  rgbInfoValue, SQLSMALLINT  cbInfoValueMax, SQLSMALLINT * pcbInfoValue ) {
  if (dev_go(sqlrc,"sqlgetinfow")) {
    char mykey[256];
    printf_key(mykey,"SQLGetInfoW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fInfoType",fInfoType,fInfoType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbInfoValue",rgbInfoValue,rgbInfoValue);
    printf_hexdump(mykey,rgbInfoValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbInfoValueMax",cbInfoValueMax,cbInfoValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbInfoValue",pcbInfoValue,pcbInfoValue);
    printf_hexdump(mykey,pcbInfoValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetLength(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  locator, SQLINTEGER * sLength, SQLINTEGER * ind ) {
  if (dev_go(sqlrc,"sqlgetlength")) {
    char mykey[256];
    printf_key(mykey,"SQLGetLength");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","locType",locType,locType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","locator",locator,locator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","sLength",sLength,sLength);
    printf_hexdump(mykey,sLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ind",ind,ind);
    printf_hexdump(mykey,ind,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetPosition(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind ) {
  if (dev_go(sqlrc,"sqlgetposition")) {
    char mykey[256];
    printf_key(mykey,"SQLGetPosition");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","locType",locType,locType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srceLocator",srceLocator,srceLocator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srchLocator",srchLocator,srchLocator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","srchLiteral",srchLiteral,srchLiteral);
    printf_hexdump(mykey,srchLiteral,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srchLiteralLen",srchLiteralLen,srchLiteralLen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fPosition",fPosition,fPosition);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","located",located,located);
    printf_hexdump(mykey,located,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ind",ind,ind);
    printf_hexdump(mykey,ind,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetPositionW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  srchLocator, SQLWCHAR * srchLiteral, SQLINTEGER  srchLiteralLen, SQLINTEGER  fPosition, SQLINTEGER * located, SQLINTEGER * ind ) {
  if (dev_go(sqlrc,"sqlgetpositionw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetPositionW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","locType",locType,locType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srceLocator",srceLocator,srceLocator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srchLocator",srchLocator,srchLocator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","srchLiteral",srchLiteral,srchLiteral);
    printf_hexdump(mykey,srchLiteral,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srchLiteralLen",srchLiteralLen,srchLiteralLen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fPosition",fPosition,fPosition);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","located",located,located);
    printf_hexdump(mykey,located,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ind",ind,ind);
    printf_hexdump(mykey,ind,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetStmtAttr(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength ) {
  if (dev_go(sqlrc,"sqlgetstmtattr")) {
    char mykey[256];
    printf_key(mykey,"SQLGetStmtAttr");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fAttr",fAttr,fAttr);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pvParam",pvParam,pvParam);
    printf_hexdump(mykey,pvParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","bLength",bLength,bLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","SLength",SLength,SLength);
    printf_hexdump(mykey,SLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetStmtAttrW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pvParam, SQLINTEGER  bLength, SQLINTEGER * SLength ) {
  if (dev_go(sqlrc,"sqlgetstmtattrw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetStmtAttrW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fAttr",fAttr,fAttr);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pvParam",pvParam,pvParam);
    printf_hexdump(mykey,pvParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","bLength",bLength,bLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","SLength",SLength,SLength);
    printf_hexdump(mykey,SLength,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetStmtOption(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam ) {
  if (dev_go(sqlrc,"sqlgetstmtoption")) {
    char mykey[256];
    printf_key(mykey,"SQLGetStmtOption");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pvParam",pvParam,pvParam);
    printf_hexdump(mykey,pvParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetStmtOptionW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  pvParam ) {
  if (dev_go(sqlrc,"sqlgetstmtoptionw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetStmtOptionW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pvParam",pvParam,pvParam);
    printf_hexdump(mykey,pvParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetSubString(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind ) {
  if (dev_go(sqlrc,"sqlgetsubstring")) {
    char mykey[256];
    printf_key(mykey,"SQLGetSubString");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","locType",locType,locType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srceLocator",srceLocator,srceLocator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fPosition",fPosition,fPosition);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","length",length,length);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","tType",tType,tType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbValue",rgbValue,rgbValue);
    printf_hexdump(mykey,rgbValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbValueMax",cbValueMax,cbValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","StringLength",StringLength,StringLength);
    printf_hexdump(mykey,StringLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ind",ind,ind);
    printf_hexdump(mykey,ind,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetSubStringW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  locType, SQLINTEGER  srceLocator, SQLINTEGER  fPosition, SQLINTEGER  length, SQLSMALLINT  tType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * StringLength, SQLINTEGER * ind ) {
  if (dev_go(sqlrc,"sqlgetsubstringw")) {
    char mykey[256];
    printf_key(mykey,"SQLGetSubStringW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","locType",locType,locType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","srceLocator",srceLocator,srceLocator);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fPosition",fPosition,fPosition);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","length",length,length);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","tType",tType,tType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbValue",rgbValue,rgbValue);
    printf_hexdump(mykey,rgbValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbValueMax",cbValueMax,cbValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","StringLength",StringLength,StringLength);
    printf_hexdump(mykey,StringLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ind",ind,ind);
    printf_hexdump(mykey,ind,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetTypeInfo(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fSqlType ) {
  if (dev_go(sqlrc,"sqlgettypeinfo")) {
    char mykey[256];
    printf_key(mykey,"SQLGetTypeInfo");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fSqlType",fSqlType,fSqlType);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLGetTypeInfoW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fSqlType ) {
  if (dev_go(sqlrc,"sqlgettypeinfow")) {
    char mykey[256];
    printf_key(mykey,"SQLGetTypeInfoW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fSqlType",fSqlType,fSqlType);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLLanguages(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sqllanguages")) {
    char mykey[256];
    printf_key(mykey,"SQLLanguages");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLMoreResults(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sqlmoreresults")) {
    char mykey[256];
    printf_key(mykey,"SQLMoreResults");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLNativeSql(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr ) {
  if (dev_go(sqlrc,"sqlnativesql")) {
    char mykey[256];
    printf_key(mykey,"SQLNativeSql");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlStrIn",szSqlStrIn,szSqlStrIn);
    printf_hexdump(mykey,szSqlStrIn,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStrIn",cbSqlStrIn,cbSqlStrIn);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStrMax",cbSqlStrMax,cbSqlStrMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbSqlStr",pcbSqlStr,pcbSqlStr);
    printf_hexdump(mykey,pcbSqlStr,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLNativeSqlW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLWCHAR * szSqlStrIn, SQLINTEGER  cbSqlStrIn, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStrMax, SQLINTEGER * pcbSqlStr ) {
  if (dev_go(sqlrc,"sqlnativesqlw")) {
    char mykey[256];
    printf_key(mykey,"SQLNativeSqlW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szSqlStrIn",szSqlStrIn,szSqlStrIn);
    printf_hexdump(mykey,szSqlStrIn,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStrIn",cbSqlStrIn,cbSqlStrIn);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStrMax",cbSqlStrMax,cbSqlStrMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbSqlStr",pcbSqlStr,pcbSqlStr);
    printf_hexdump(mykey,pcbSqlStr,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLNextResult(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLHSTMT  hstmt2 ) {
  if (dev_go(sqlrc,"sqlnextresult")) {
    char mykey[256];
    printf_key(mykey,"SQLNextResult");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt2",hstmt2,hstmt2);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt2);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLNumParams(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT * pcpar ) {
  if (dev_go(sqlrc,"sqlnumparams")) {
    char mykey[256];
    printf_key(mykey,"SQLNumParams");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcpar",pcpar,pcpar);
    printf_hexdump(mykey,pcpar,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLNumResultCols(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT * pccol ) {
  if (dev_go(sqlrc,"sqlnumresultcols")) {
    char mykey[256];
    printf_key(mykey,"SQLNumResultCols");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pccol",pccol,pccol);
    printf_hexdump(mykey,pccol,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLParamData(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLPOINTER * Value ) {
  if (dev_go(sqlrc,"sqlparamdata")) {
    char mykey[256];
    printf_key(mykey,"SQLParamData");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER*","Value",Value,Value);
    printf_hexdump(mykey,Value,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLParamOptions(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER  crow, SQLINTEGER * pirow ) {
  if (dev_go(sqlrc,"sqlparamoptions")) {
    char mykey[256];
    printf_key(mykey,"SQLParamOptions");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","crow",crow,crow);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pirow",pirow,pirow);
    printf_hexdump(mykey,pirow,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLPrepare(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  if (dev_go(sqlrc,"sqlprepare")) {
    char mykey[256];
    printf_key(mykey,"SQLPrepare");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStr",cbSqlStr,cbSqlStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLPrepareW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  if (dev_go(sqlrc,"sqlpreparew")) {
    char mykey[256];
    printf_key(mykey,"SQLPrepareW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStr",cbSqlStr,cbSqlStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLPrimaryKeys(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  if (dev_go(sqlrc,"sqlprimarykeys")) {
    char mykey[256];
    printf_key(mykey,"SQLPrimaryKeys");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLPrimaryKeysW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  if (dev_go(sqlrc,"sqlprimarykeysw")) {
    char mykey[256];
    printf_key(mykey,"SQLPrimaryKeysW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLProcedureColumns(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName, SQLCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  if (dev_go(sqlrc,"sqlprocedurecolumns")) {
    char mykey[256];
    printf_key(mykey,"SQLProcedureColumns");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szProcQualifier",szProcQualifier,szProcQualifier);
    printf_hexdump(mykey,szProcQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcQualifier",cbProcQualifier,cbProcQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szProcOwner",szProcOwner,szProcOwner);
    printf_hexdump(mykey,szProcOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcOwner",cbProcOwner,cbProcOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szProcName",szProcName,szProcName);
    printf_hexdump(mykey,szProcName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcName",cbProcName,cbProcName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szColumnName",szColumnName,szColumnName);
    printf_hexdump(mykey,szColumnName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColumnName",cbColumnName,cbColumnName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLProcedureColumnsW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName, SQLWCHAR * szColumnName, SQLSMALLINT  cbColumnName ) {
  if (dev_go(sqlrc,"sqlprocedurecolumnsw")) {
    char mykey[256];
    printf_key(mykey,"SQLProcedureColumnsW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szProcQualifier",szProcQualifier,szProcQualifier);
    printf_hexdump(mykey,szProcQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcQualifier",cbProcQualifier,cbProcQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szProcOwner",szProcOwner,szProcOwner);
    printf_hexdump(mykey,szProcOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcOwner",cbProcOwner,cbProcOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szProcName",szProcName,szProcName);
    printf_hexdump(mykey,szProcName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcName",cbProcName,cbProcName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szColumnName",szColumnName,szColumnName);
    printf_hexdump(mykey,szColumnName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColumnName",cbColumnName,cbColumnName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLProcedures(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLCHAR * szProcName, SQLSMALLINT  cbProcName ) {
  if (dev_go(sqlrc,"sqlprocedures")) {
    char mykey[256];
    printf_key(mykey,"SQLProcedures");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szProcQualifier",szProcQualifier,szProcQualifier);
    printf_hexdump(mykey,szProcQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcQualifier",cbProcQualifier,cbProcQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szProcOwner",szProcOwner,szProcOwner);
    printf_hexdump(mykey,szProcOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcOwner",cbProcOwner,cbProcOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szProcName",szProcName,szProcName);
    printf_hexdump(mykey,szProcName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcName",cbProcName,cbProcName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLProceduresW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szProcQualifier, SQLSMALLINT  cbProcQualifier, SQLWCHAR * szProcOwner, SQLSMALLINT  cbProcOwner, SQLWCHAR * szProcName, SQLSMALLINT  cbProcName ) {
  if (dev_go(sqlrc,"sqlproceduresw")) {
    char mykey[256];
    printf_key(mykey,"SQLProceduresW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szProcQualifier",szProcQualifier,szProcQualifier);
    printf_hexdump(mykey,szProcQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcQualifier",cbProcQualifier,cbProcQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szProcOwner",szProcOwner,szProcOwner);
    printf_hexdump(mykey,szProcOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcOwner",cbProcOwner,cbProcOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szProcName",szProcName,szProcName);
    printf_hexdump(mykey,szProcName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbProcName",cbProcName,cbProcName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLPutData(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen ) {
  if (dev_go(sqlrc,"sqlputdata")) {
    char mykey[256];
    printf_key(mykey,"SQLPutData");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","Data",Data,Data);
    printf_hexdump(mykey,Data,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","SLen",SLen,SLen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLReleaseEnv(SQLRETURN sqlrc,  SQLHENV  henv ) {
  if (dev_go(sqlrc,"sqlreleaseenv")) {
    char mykey[256];
    printf_key(mykey,"SQLReleaseEnv");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLRowCount(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER * pcrow ) {
  if (dev_go(sqlrc,"sqlrowcount")) {
    char mykey[256];
    printf_key(mykey,"SQLRowCount");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcrow",pcrow,pcrow);
    printf_hexdump(mykey,pcrow,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetConnectAttr(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) {
  if (dev_go(sqlrc,"sqlsetconnectattr")) {
    char mykey[256];
    printf_key(mykey,"SQLSetConnectAttr");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","attrib",attrib,attrib);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","vParam",vParam,vParam);
    printf_hexdump(mykey,vParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetConnectAttrW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLINTEGER  attrib, SQLPOINTER  vParam, SQLINTEGER  inlen ) {
  if (dev_go(sqlrc,"sqlsetconnectattrw")) {
    char mykey[256];
    printf_key(mykey,"SQLSetConnectAttrW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","attrib",attrib,attrib);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","vParam",vParam,vParam);
    printf_hexdump(mykey,vParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetConnectOption(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  if (dev_go(sqlrc,"sqlsetconnectoption")) {
    char mykey[256];
    printf_key(mykey,"SQLSetConnectOption");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","vParam",vParam,vParam);
    printf_hexdump(mykey,vParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetConnectOptionW(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  if (dev_go(sqlrc,"sqlsetconnectoptionw")) {
    char mykey[256];
    printf_key(mykey,"SQLSetConnectOptionW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","vParam",vParam,vParam);
    printf_hexdump(mykey,vParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetCursorName(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szCursor, SQLSMALLINT  cbCursor ) {
  if (dev_go(sqlrc,"sqlsetcursorname")) {
    char mykey[256];
    printf_key(mykey,"SQLSetCursorName");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szCursor",szCursor,szCursor);
    printf_hexdump(mykey,szCursor,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbCursor",cbCursor,cbCursor);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetCursorNameW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szCursor, SQLSMALLINT  cbCursor ) {
  if (dev_go(sqlrc,"sqlsetcursornamew")) {
    char mykey[256];
    printf_key(mykey,"SQLSetCursorNameW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szCursor",szCursor,szCursor);
    printf_hexdump(mykey,szCursor,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbCursor",cbCursor,cbCursor);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetDescField(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen ) {
  if (dev_go(sqlrc,"sqlsetdescfield")) {
    char mykey[256];
    printf_key(mykey,"SQLSetDescField");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fID",fID,fID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","Value",Value,Value);
    printf_hexdump(mykey,Value,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","buffLen",buffLen,buffLen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetDescFieldW(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  fID, SQLPOINTER  Value, SQLINTEGER  buffLen ) {
  if (dev_go(sqlrc,"sqlsetdescfieldw")) {
    char mykey[256];
    printf_key(mykey,"SQLSetDescFieldW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fID",fID,fID);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","Value",Value,Value);
    printf_hexdump(mykey,Value,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","buffLen",buffLen,buffLen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetDescRec(SQLRETURN sqlrc,  SQLHDESC  hdesc, SQLSMALLINT  rcdNum, SQLSMALLINT  Type, SQLSMALLINT  subType, SQLINTEGER  fLength, SQLSMALLINT  fPrec, SQLSMALLINT  fScale, SQLPOINTER  Value, SQLINTEGER * sLength, SQLINTEGER * indic ) {
  if (dev_go(sqlrc,"sqlsetdescrec")) {
    char mykey[256];
    printf_key(mykey,"SQLSetDescRec");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDESC","hdesc",hdesc,hdesc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","rcdNum",rcdNum,rcdNum);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","Type",Type,Type);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","subType",subType,subType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fLength",fLength,fLength);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fPrec",fPrec,fPrec);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fScale",fScale,fScale);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","Value",Value,Value);
    printf_hexdump(mykey,Value,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","sLength",sLength,sLength);
    printf_hexdump(mykey,sLength,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","indic",indic,indic);
    printf_hexdump(mykey,indic,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DESC,hdesc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetEnvAttr(SQLRETURN sqlrc,  SQLHENV  hEnv, SQLINTEGER  fAttribute, SQLPOINTER  pParam, SQLINTEGER  cbParam ) {
  if (dev_go(sqlrc,"sqlsetenvattr")) {
    char mykey[256];
    printf_key(mykey,"SQLSetEnvAttr");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","hEnv",hEnv,hEnv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fAttribute",fAttribute,fAttribute);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pParam",pParam,pParam);
    printf_hexdump(mykey,pParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbParam",cbParam,cbParam);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetParam(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  ipar, SQLSMALLINT  fCType, SQLSMALLINT  fSqlType, SQLINTEGER  cbColDef, SQLSMALLINT  ibScale, SQLPOINTER  rgbValue, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sqlsetparam")) {
    char mykey[256];
    printf_key(mykey,"SQLSetParam");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","ipar",ipar,ipar);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fCType",fCType,fCType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fSqlType",fSqlType,fSqlType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbColDef",cbColDef,cbColDef);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","ibScale",ibScale,ibScale);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbValue",rgbValue,rgbValue);
    printf_hexdump(mykey,rgbValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetStmtAttr(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) {
  if (dev_go(sqlrc,"sqlsetstmtattr")) {
    char mykey[256];
    printf_key(mykey,"SQLSetStmtAttr");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fAttr",fAttr,fAttr);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pParam",pParam,pParam);
    printf_hexdump(mykey,pParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","vParam",vParam,vParam);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetStmtAttrW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER  fAttr, SQLPOINTER  pParam, SQLINTEGER  vParam ) {
  if (dev_go(sqlrc,"sqlsetstmtattrw")) {
    char mykey[256];
    printf_key(mykey,"SQLSetStmtAttrW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","fAttr",fAttr,fAttr);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","pParam",pParam,pParam);
    printf_hexdump(mykey,pParam,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","vParam",vParam,vParam);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetStmtOption(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  if (dev_go(sqlrc,"sqlsetstmtoption")) {
    char mykey[256];
    printf_key(mykey,"SQLSetStmtOption");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","vParam",vParam,vParam);
    printf_hexdump(mykey,vParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSetStmtOptionW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fOption, SQLPOINTER  vParam ) {
  if (dev_go(sqlrc,"sqlsetstmtoptionw")) {
    char mykey[256];
    printf_key(mykey,"SQLSetStmtOptionW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fOption",fOption,fOption);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","vParam",vParam,vParam);
    printf_hexdump(mykey,vParam,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSpecialColumns(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable ) {
  if (dev_go(sqlrc,"sqlspecialcolumns")) {
    char mykey[256];
    printf_key(mykey,"SQLSpecialColumns");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fColType",fColType,fColType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQual",szTableQual,szTableQual);
    printf_hexdump(mykey,szTableQual,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQual",cbTableQual,cbTableQual);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fScope",fScope,fScope);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fNullable",fNullable,fNullable);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLSpecialColumnsW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  fColType, SQLWCHAR * szTableQual, SQLSMALLINT  cbTableQual, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fScope, SQLSMALLINT  fNullable ) {
  if (dev_go(sqlrc,"sqlspecialcolumnsw")) {
    char mykey[256];
    printf_key(mykey,"SQLSpecialColumnsW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fColType",fColType,fColType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQual",szTableQual,szTableQual);
    printf_hexdump(mykey,szTableQual,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQual",cbTableQual,cbTableQual);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fScope",fScope,fScope);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fNullable",fNullable,fNullable);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLStartTran(SQLRETURN sqlrc,  SQLSMALLINT  htype, SQLHENV  henv, SQLINTEGER  mode, SQLINTEGER  clevel ) {
  if (dev_go(sqlrc,"sqlstarttran")) {
    char mykey[256];
    printf_key(mykey,"SQLStartTran");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","htype",htype,htype);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","mode",mode,mode);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","clevel",clevel,clevel);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLStatistics(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres ) {
  if (dev_go(sqlrc,"sqlstatistics")) {
    char mykey[256];
    printf_key(mykey,"SQLStatistics");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fUnique",fUnique,fUnique);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fres",fres,fres);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLStatisticsW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLSMALLINT  fUnique, SQLSMALLINT  fres ) {
  if (dev_go(sqlrc,"sqlstatisticsw")) {
    char mykey[256];
    printf_key(mykey,"SQLStatisticsW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fUnique",fUnique,fUnique);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fres",fres,fres);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLTablePrivileges(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  if (dev_go(sqlrc,"sqltableprivileges")) {
    char mykey[256];
    printf_key(mykey,"SQLTablePrivileges");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLTablePrivilegesW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName ) {
  if (dev_go(sqlrc,"sqltableprivilegesw")) {
    char mykey[256];
    printf_key(mykey,"SQLTablePrivilegesW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLTables(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLCHAR * szTableName, SQLSMALLINT  cbTableName, SQLCHAR * szTableType, SQLSMALLINT  cbTableType ) {
  if (dev_go(sqlrc,"sqltables")) {
    char mykey[256];
    printf_key(mykey,"SQLTables");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szTableType",szTableType,szTableType);
    printf_hexdump(mykey,szTableType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableType",cbTableType,cbTableType);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLTablesW(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLWCHAR * szTableQualifier, SQLSMALLINT  cbTableQualifier, SQLWCHAR * szTableOwner, SQLSMALLINT  cbTableOwner, SQLWCHAR * szTableName, SQLSMALLINT  cbTableName, SQLWCHAR * szTableType, SQLSMALLINT  cbTableType ) {
  if (dev_go(sqlrc,"sqltablesw")) {
    char mykey[256];
    printf_key(mykey,"SQLTablesW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableQualifier",szTableQualifier,szTableQualifier);
    printf_hexdump(mykey,szTableQualifier,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableQualifier",cbTableQualifier,cbTableQualifier);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableOwner",szTableOwner,szTableOwner);
    printf_hexdump(mykey,szTableOwner,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableOwner",cbTableOwner,cbTableOwner);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableName",szTableName,szTableName);
    printf_hexdump(mykey,szTableName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableName",cbTableName,cbTableName);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","szTableType",szTableType,szTableType);
    printf_hexdump(mykey,szTableType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbTableType",cbTableType,cbTableType);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLTransact(SQLRETURN sqlrc,  SQLHENV  henv, SQLHDBC  hdbc, SQLSMALLINT  fType ) {
  if (dev_go(sqlrc,"sqltransact")) {
    char mykey[256];
    printf_key(mykey,"SQLTransact");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHENV","henv",henv,henv);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","fType",fType,fType);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400Version(SQLRETURN sqlrc,  SQLPOINTER  outversion, SQLINTEGER  outlen ) {
  if (dev_go(sqlrc,"sql400version")) {
    char mykey[256];
    printf_key(mykey,"SQL400Version");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outversion",outversion,outversion);
    printf_hexdump(mykey,outversion,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQLOverrideCCSID400(SQLRETURN sqlrc,  SQLINTEGER  newCCSID ) {
  if (dev_go(sqlrc,"sqloverrideccsid400")) {
    char mykey[256];
    printf_key(mykey,"SQLOverrideCCSID400");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","newCCSID",newCCSID,newCCSID);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400Stmt2Hdbc(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLINTEGER * ohnd ) {
  if (dev_go(sqlrc,"sql400stmt2hdbc")) {
    char mykey[256];
    printf_key(mykey,"SQL400Stmt2Hdbc");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400Connect(SQLRETURN sqlrc,  SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400connect")) {
    char mykey[256];
    printf_key(mykey,"SQL400Connect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ConnectW(SQLRETURN sqlrc,  SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400connectw")) {
    char mykey[256];
    printf_key(mykey,"SQL400ConnectW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400pConnect(SQLRETURN sqlrc,  SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400pconnect")) {
    char mykey[256];
    printf_key(mykey,"SQL400pConnect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","qual",qual,qual);
    printf_hexdump(mykey,qual,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400pConnectW(SQLRETURN sqlrc,  SQLWCHAR * db, SQLWCHAR * uid, SQLWCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400pconnectw")) {
    char mykey[256];
    printf_key(mykey,"SQL400pConnectW");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLWCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","qual",qual,qual);
    printf_hexdump(mykey,qual,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ConnectUtf8(SQLRETURN sqlrc,  SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400connectutf8")) {
    char mykey[256];
    printf_key(mykey,"SQL400ConnectUtf8");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","accsid",accsid,accsid);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400pConnectUtf8(SQLRETURN sqlrc,  SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400pconnectutf8")) {
    char mykey[256];
    printf_key(mykey,"SQL400pConnectUtf8");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","accsid",accsid,accsid);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","qual",qual,qual);
    printf_hexdump(mykey,qual,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ConnectUtf16(SQLRETURN sqlrc,  SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400connectutf16")) {
    char mykey[256];
    printf_key(mykey,"SQL400ConnectUtf16");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","accsid",accsid,accsid);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400pConnectUtf16(SQLRETURN sqlrc,  SQLINTEGER  accsid, SQLCHAR * db, SQLCHAR * uid, SQLCHAR * pwd, SQLCHAR * qual, SQLINTEGER * ohnd, SQLINTEGER  acommit, SQLCHAR * alibl, SQLCHAR * acurlib ) {
  if (dev_go(sqlrc,"sql400pconnectutf16")) {
    char mykey[256];
    printf_key(mykey,"SQL400pConnectUtf16");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","accsid",accsid,accsid);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","db",db,db);
    printf_hexdump(mykey,db,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","uid",uid,uid);
    printf_hexdump(mykey,uid,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","pwd",pwd,pwd);
    printf_hexdump(mykey,pwd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","qual",qual,qual);
    printf_hexdump(mykey,qual,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","ohnd",ohnd,ohnd);
    printf_hexdump(mykey,ohnd,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","acommit",acommit,acommit);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","alibl",alibl,alibl);
    printf_hexdump(mykey,alibl,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","acurlib",acurlib,acurlib);
    printf_hexdump(mykey,acurlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400Close(SQLRETURN sqlrc,  SQLHDBC  hdbc ) {
  if (dev_go(sqlrc,"sql400close")) {
    char mykey[256];
    printf_key(mykey,"SQL400Close");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400pClose(SQLRETURN sqlrc,  SQLHDBC  hdbc ) {
  if (dev_go(sqlrc,"sql400pclose")) {
    char mykey[256];
    printf_key(mykey,"SQL400pClose");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400CloseAllStmts(SQLRETURN sqlrc,  SQLHDBC  hdbc ) {
  if (dev_go(sqlrc,"sql400closeallstmts")) {
    char mykey[256];
    printf_key(mykey,"SQL400CloseAllStmts");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400Cmd(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLCHAR * cmd ) {
  if (dev_go(sqlrc,"sql400cmd")) {
    char mykey[256];
    printf_key(mykey,"SQL400Cmd");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","cmd",cmd,cmd);
    printf_hexdump(mykey,cmd,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ChgLibl(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLCHAR * libl ) {
  if (dev_go(sqlrc,"sql400chglibl")) {
    char mykey[256];
    printf_key(mykey,"SQL400ChgLibl");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","libl",libl,libl);
    printf_hexdump(mykey,libl,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ChgCurLib(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLCHAR * curlib ) {
  if (dev_go(sqlrc,"sql400chgcurlib")) {
    char mykey[256];
    printf_key(mykey,"SQL400ChgCurLib");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","curlib",curlib,curlib);
    printf_hexdump(mykey,curlib,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ToUtf8(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  if (dev_go(sqlrc,"sql400toutf8")) {
    char mykey[256];
    printf_key(mykey,"SQL400ToUtf8");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inccsid",inccsid,inccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400FromUtf8(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  if (dev_go(sqlrc,"sql400fromutf8")) {
    char mykey[256];
    printf_key(mykey,"SQL400FromUtf8");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outccsid",outccsid,outccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400ToUtf16(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  if (dev_go(sqlrc,"sql400toutf16")) {
    char mykey[256];
    printf_key(mykey,"SQL400ToUtf16");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inccsid",inccsid,inccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400FromUtf16(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  if (dev_go(sqlrc,"sql400fromutf16")) {
    char mykey[256];
    printf_key(mykey,"SQL400FromUtf16");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outccsid",outccsid,outccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400IgnoreNullToUtf8(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  if (dev_go(sqlrc,"sql400ignorenulltoutf8")) {
    char mykey[256];
    printf_key(mykey,"SQL400IgnoreNullToUtf8");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inccsid",inccsid,inccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400IgnoreNullFromUtf8(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  if (dev_go(sqlrc,"sql400ignorenullfromutf8")) {
    char mykey[256];
    printf_key(mykey,"SQL400IgnoreNullFromUtf8");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outccsid",outccsid,outccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400IgnoreNullToUtf16(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  inccsid ) {
  if (dev_go(sqlrc,"sql400ignorenulltoutf16")) {
    char mykey[256];
    printf_key(mykey,"SQL400IgnoreNullToUtf16");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inccsid",inccsid,inccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400IgnoreNullFromUtf16(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLPOINTER  inparm, SQLINTEGER  inlen, SQLPOINTER  outparm, SQLINTEGER  outlen, SQLINTEGER  outccsid ) {
  if (dev_go(sqlrc,"sql400ignorenullfromutf16")) {
    char mykey[256];
    printf_key(mykey,"SQL400IgnoreNullFromUtf16");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","inparm",inparm,inparm);
    printf_hexdump(mykey,inparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","outparm",outparm,outparm);
    printf_hexdump(mykey,outparm,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outccsid",outccsid,outccsid);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400Json(SQLRETURN sqlrc,  SQLHDBC  hdbc, SQLCHAR * injson, SQLINTEGER  inlen, SQLCHAR * outjson, SQLINTEGER  outlen ) {
  if (dev_go(sqlrc,"sql400json")) {
    char mykey[256];
    printf_key(mykey,"SQL400Json");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHDBC","hdbc",hdbc,hdbc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","injson",injson,injson);
    printf_hexdump(mykey,injson,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","inlen",inlen,inlen);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","outjson",outjson,outjson);
    printf_hexdump(mykey,outjson,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","outlen",outlen,outlen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_DBC,hdbc);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackExecDirect(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  if (dev_go(sqlrc,"sql400hackexecdirect")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackExecDirect");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStr",cbSqlStr,cbSqlStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackPrepare(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLCHAR * szSqlStr, SQLINTEGER  cbSqlStr ) {
  if (dev_go(sqlrc,"sql400hackprepare")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackPrepare");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szSqlStr",szSqlStr,szSqlStr);
    printf_hexdump(mykey,szSqlStr,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbSqlStr",cbSqlStr,cbSqlStr);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackExecute(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sql400hackexecute")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackExecute");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackFetch(SQLRETURN sqlrc,  SQLHSTMT  hstmt ) {
  if (dev_go(sqlrc,"sql400hackfetch")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackFetch");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackDescribeCol(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLCHAR * szColName, SQLSMALLINT  cbColNameMax, SQLSMALLINT * pcbColName, SQLSMALLINT * pfSqlType, SQLINTEGER * pcbColDef, SQLSMALLINT * pibScale, SQLSMALLINT * pfNullable ) {
  if (dev_go(sqlrc,"sql400hackdescribecol")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackDescribeCol");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLCHAR*","szColName",szColName,szColName);
    printf_hexdump(mykey,szColName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","cbColNameMax",cbColNameMax,cbColNameMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pcbColName",pcbColName,pcbColName);
    printf_hexdump(mykey,pcbColName,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfSqlType",pfSqlType,pfSqlType);
    printf_hexdump(mykey,pfSqlType,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbColDef",pcbColDef,pcbColDef);
    printf_hexdump(mykey,pcbColDef,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pibScale",pibScale,pibScale);
    printf_hexdump(mykey,pibScale,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT*","pfNullable",pfNullable,pfNullable);
    printf_hexdump(mykey,pfNullable,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackBindCol(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLSMALLINT  icol, SQLSMALLINT  iType, SQLPOINTER  rgbValue, SQLINTEGER  cbValueMax, SQLINTEGER * pcbValue ) {
  if (dev_go(sqlrc,"sql400hackbindcol")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackBindCol");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","icol",icol,icol);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLSMALLINT","iType",iType,iType);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","rgbValue",rgbValue,rgbValue);
    printf_hexdump(mykey,rgbValue,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","cbValueMax",cbValueMax,cbValueMax);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER*","pcbValue",pcbValue,pcbValue);
    printf_hexdump(mykey,pcbValue,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackParamData(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLPOINTER * Value ) {
  if (dev_go(sqlrc,"sql400hackparamdata")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackParamData");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER*","Value",Value,Value);
    printf_hexdump(mykey,Value,80);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
void dump_SQL400HackPutData(SQLRETURN sqlrc,  SQLHSTMT  hstmt, SQLPOINTER  Data, SQLINTEGER  SLen ) {
  if (dev_go(sqlrc,"sql400hackputdata")) {
    char mykey[256];
    printf_key(mykey,"SQL400HackPutData");
    printf_clear();
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 1);
    printf_stack(mykey);
    printf_sqlrc_status((char *)&mykey, sqlrc);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLHSTMT","hstmt",hstmt,hstmt);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLPOINTER","Data",Data,Data);
    printf_hexdump(mykey,Data,80);
    printf_format("%s.parm %s %s 0x%p (%d)\n",mykey,"SQLINTEGER","SLen",SLen,SLen);
    printf_sqlrc_head_foot((char *)&mykey, sqlrc, 0);
    dev_dump();
    if (sqlrc < SQL_SUCCESS) {
      printf_sql_diag(SQL_HANDLE_STMT,hstmt);
      printf_force_SIGQUIT((char *)&mykey);
    }
  }
}
