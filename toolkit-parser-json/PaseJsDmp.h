#ifndef _PASEJSDMP_H
#define _PASEJSDMP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "../toolkit-base/PaseTool.h"

void json_dump_key(char *mykey, int lvl, int key, char * val);
void json_dump_mykey(char * akey, char *func);
void json_dump_val(char * mykey, char * aval, int alen, char * val);
void json_dump_lvl_key_val(char * mykey, int lvl, int key, char * val);
void json_graph(char *func, int *ikey, char **ival, int *ilvl);
void json_dump_one(char *func, int lvl, int key, char * val);
void json_dump_null(char *func, char * val);

#endif /* _PASEJSDMP_H */

