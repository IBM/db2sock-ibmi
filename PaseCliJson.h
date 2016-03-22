#ifndef _PASECLIJSON_H
#define _PASECLIJSON_H

/*
Example: prepare execute
{
 "sql": {
   "connect": {
     "database": null,
     "user": null,
     "password": null,
     "qualify": "myconn"
   },
   "prepare": "select * from qiws.qcustcdt",
   "execute": [{"parm":null},{"parm":null}],
   "fetch": "*"
 }
}

Example: tables
{
 "sql": {
   "connect": {
     "database": null,
     "user": null,
     "password": null,
     "qualify": "myconn"
   },
   "tables": {
     "schema": "qiws",
     "name": "qcustcdt",
     "type": "BASE TABLE"
   },
   "fetch": "*"
 }
}
*/

int json_parse_hash(char * jsoni, void **out_name, void **out_value);
void json_output(int flag, char *outrun, int outlen, char *argv[]);

#endif /* _PASECLIJSON_H */

