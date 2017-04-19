#ifndef _PASECLIPRINTF_H
#define _PASECLIPRINTF_H

#define PRINTF_BUFFER_MAX 8192
#define PRINTF_HEXDUMP_MAX 80
#define PRINTF_SCAN_MAX 1024

/* output key */
void printf_key(char *mykey, char *text);

/* accumulated print buffer address (string) */
extern char * printf_buffer();

/* clear accumulated print buffer */
extern void printf_clear();

/* print formating (memory buffer accumulate) */
extern void printf_format(const char * format, ...);
extern void printf_hexdump(char * prefix, void *string, unsigned int len);
extern void printf_stack(char * prefix);

/* print formating user script langauge only (memory buffer accumulate) */
extern void printf_script( char * pmsg );
extern void printf_script_include( char * pmsg );
extern void printf_script_exclude( char * pmsg );
extern void printf_script_clear();

/* special buffer printf not using internal buffer */
extern void sprintf_format(char *buff, const char * format, ...);
extern void printf_dbx_init();


#endif /* _PASECLIPRINTF_H */

