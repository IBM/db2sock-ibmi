int json_sql(int i, int argc, char *name[], char *value[], SQLCHAR * outjson, SQLINTEGER outlen)
{
  SQLHANDLE hstmt = 0;
  SQLSMALLINT pccol = 0;
  SQLINTEGER start_row = 0;
  SQL400ParamStruct call_parms[100];
  SQL400DescStruct desc_parms[100];
  SQL400ParamStruct call_cols[100];
  SQL400DescStruct desc_cols[100];
  SQLINTEGER indPtr[100];
  SQLPOINTER data_cols[100];
  char * error_fmt = "{\"json\":{\"ok\":false,\"reason\":\"unsupported json input\"}}";
  char * error_prep = "{\"prepare\":{\"ok\":false,\"reason\":\"prepare invalid\",\"sqlcode\":-99999,\"sqlmsg\":\"driver error\"}}";
  char * error_exec = "{\"execute\":{\"ok\":false,\"reason\":\"execute invalid\",\"sqlcode\":-99999,\"sqlmsg\":\"driver error\"}}";
  char * good_beg = "{";
  char * good_end = "}";
  char * good_prep = "\"prepare\":{\"ok\":true}";
  char * good_exec = "\"execute\":{\"ok\":true}";
  char * good_fetch_beg = "{\"fetch\":{\"ok\":true";
  char * good_fetch_end = "}";
  char * good_rows_array_beg = "{\"row\":[";
  char * good_rows_array_end = "]";

  /* good out assumed */
  strcat(outjson,good_beg);

  /* clear */
  memset(outjson,0,outlen);
  memset(db,0,sizeof(db));
  memset(uid,0,sizeof(uid));
  memset(pwd,0,sizeof(pwd));
  memset(sql,0,sizeof(sql));
  memset(parm,0,sizeof(parm));
  memset(call_parms,0,sizeof(call_parms));
  memset(desc_parms,0,sizeof(desc_parms));
  memset(call_cols,0,sizeof(call_cols));
  memset(desc_cols,0,sizeof(desc_cols));
  memset(indPtr,0,sizeof(indPtr));
  memset(data_cols,0,sizeof(data_cols));


  /* 1208 */
  sqlrc = SQLOverrideCCSID400( 1208 );
  sqlrc = SQL400AddAttr(SQL_HANDLE_ENV, SQL_ATTR_SERVER_MODE, &yes, 0, SQL400_ONERR_CONT, SQL400_FLAG_IMMED, (SQLPOINTER)&pophenv);
  sqlrc = SQL400Environment( &henv, (SQLPOINTER)&pophenv);

  /* do work */
  for (i=0; i < argc; i++) {
    /* keyword index json_sql_keys[] */
    i = json_sql_key(name[i]);
    switch (i) {
    case 0: /* connect */
      break;
    case 1: /* prepare */
      break;
    case 2: /* execute */
      break;
    case 3: /* fetch */
      break;
    default:
      break;
    }
  }


    switch(j[i]) {
    case 'c':
      /* "connect"(:)"*LOCAL,DB2,NICE2DB2" */
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      /* "connect":"(*)LOCAL,DB2,NICE2DB2" */
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      /* "connect":"*LOCAL,(D)B2,NICE2DB2" */
      k = i;
      i = json_comma(i,&j[i]) + 1;
      if (!i) break;
      strncpy(db,&j[k],i-k-1);
      /* "connect":"*LOCAL,DB2,(N)ICE2DB2" */
      k = i;
      i = json_comma(i,&j[i]) + 1;
      if (!i) break;
      strncpy(uid,&j[k],i-k-1);
      /* "connect":"*LOCAL,DB2,NICE2DB2"() */
      k = i;
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      strncpy(pwd,&j[k],i-k-1);
      /* connect */
      sqlrc = SQL400Connect(henv, (SQLCHAR *) &db, (SQLCHAR *) &uid, (SQLCHAR *) &pwd, &hdbc, (SQLPOINTER)&pophdbc);
      if (sqlrc == SQL_ERROR) {
        strcpy(outjson,error_conn);
        return SQL_ERROR;
      }
      strcat(outjson,good_conn);
      break;
    case 'p':
      /* "prepare"(:)"select * from qiws.qcustcdt where lstnam like ?" */
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      /* "prepare":"(s)elect * from qiws.qcustcdt where lstnam like ?" */
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      /* "prepare":"(s)elect * from qiws.qcustcdt where lstnam like ?"() */
      k = i;
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      strncpy(sql,&j[k],i-k-1);
      /* prepare */
      sqlrc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);
      sqlrc = SQLPrepare(hstmt, (SQLCHAR *) &sql, strlen((SQLCHAR *) &sql));
      if (sqlrc == SQL_ERROR) {
        strcpy(outjson,error_prep);
        return SQL_ERROR;
      }
      strcat(outjson,good_prep);
      break;
    case 'e':
      /* "execute"(:)"Hen%" */
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      /* "execute":"(H)en%" */
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      /* "execute":"Hen%"() */
      k = i;
      i = json_quote(i,&j[i]) + 1;
      if (!i) break;
      strncpy(parm,&j[k],i-k-1);
      p = (char *)&parm;
      for (c=0, k=0; p[c]; c++) {
        if (p[c] == '"' || p[c] == ',') {
          p[c] = '\0';
          indPtr[a] = c - k;
          sqlrc = SQL400AddCVar(a+1, SQL_PARAM_INPUT, SQL_C_CHAR, (SQLPOINTER) &p[k], &indPtr[a], (SQLPOINTER) &call_parms );
          a++;
          k = c + 1; 
        }
      }
      sqlrc = SQL400Execute(hstmt, (SQLPOINTER)&call_parms, (SQLPOINTER)&desc_parms);
      if (sqlrc == SQL_ERROR) {
        strcpy(outjson,error_exec);
        return SQL_ERROR;
      }
      strcat(outjson,good_exec);
      break;
    case 'f':
      strcat(outjson,good_fetch_beg);
      k = i;
      i = 0;
      c = 0;
      sqlrc = SQLNumResultCols(hstmt, (SQLSMALLINT *)&pccol );
      for (i=0;i<pccol;i++) {
        sqlrc = SQL400AddDesc(hstmt, i + 1, SQL400_DESC_COL, (SQLPOINTER)&desc_cols);
        data_cols[i] = (SQLPOINTER) malloc(1024);
        indPtr[i] = 1024;
        sqlrc = SQL400AddCVar(i + 1, 0, SQL_C_CHAR, (SQLPOINTER)data_cols[i], &indPtr[i], (SQLPOINTER) &call_cols);
      }
      sqlrc == SQL_SUCCESS;
      while (sqlrc == SQL_SUCCESS) {
        for (i=0;i<pccol;i++) {
          memset(data_cols[i],0,1024);
        }
        sqlrc = SQL400Fetch(hstmt, start_row, (SQLPOINTER)&call_cols, (SQLPOINTER)&desc_cols);
        if (sqlrc == SQL_SUCCESS) {
          if (!c) {
            strcat(outjson,good_rows_array_beg);
            strcat(outjson,good_beg);
          } else {
            strcat(outjson,",");
            strcat(outjson,good_beg);
          }
          for (i=0;i<pccol;i++) {
            strcat(outjson,"\"");
            strcat(outjson,desc_cols[i].szColName);
            strcat(outjson,"\":\"");
            strcat(outjson,data_cols[i]);
            strcat(outjson,"\"");
            if (i < pccol - 1) {
              strcat(outjson,",");
            }
          }
          strcat(outjson,good_end);
          c++;
        }
        if (c) {
          strcat(outjson,good_rows_array_end);
        }
      }
      strcat(outjson,good_fetch_end);
      i = 0;
      break;
    default:
      i = 0;
      break;
    }
    if (!i) break;
  }
  if (!i) {
    strcpy(outjson,error_fmt);
    return SQL_ERROR;
  } else {
    strcat(outjson,good_end);
  }



  /* good out assumed */
  strcat(outjson,good_end);
}

