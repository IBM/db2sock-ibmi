#ifndef _PASECLIJSON_H
#define _PASECLIJSON_H

int json_parse_hash(char * jsoni, void **out_name, void **out_value);
void json_output(int flag, char *outrun, int outlen, char *argv[]);

#endif /* _PASECLIJSON_H */

