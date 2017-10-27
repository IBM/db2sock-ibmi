#ifndef _PASETODMP_H
#define _PASETODMP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iconv.h>
#include <stdarg.h>
#include "PaseTool.h"

void tool_dump_key(char *mykey, int idx, int lvl, int key, char * val);
void tool_dump_mykey(char * akey, char *func);
void tool_dump_val(char * mykey, char * aval, int alen, char * val);
void tool_dump_lvl_key_val(char * mykey, int idx, int lvl, int key, char * val);
void tool_graph(int sqlrc, char *func, tool_struct_t * tool);
void tool_dump(int flag, int sqlrc, char *func, int idx, int lvl, int key,  char * val);
void tool_dump_attr(int sqlrc, char *func, int idx, int lvl, int key,  char * val);
void tool_dump_beg(int sqlrc, char *func, int idx, int lvl, int key,  char * val);
void tool_dump_end(int sqlrc, char *func, int idx, int lvl, int key,  char * val);
void tool_dump_hex_chunks(char * mykey, char *start, int size);
void tool_pgm_dump(int sqlrc, char *func, int step, tool_key_pgm_struct_t * tpgm);

#endif /* _PASETODMP_H */


