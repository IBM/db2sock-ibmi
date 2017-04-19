#ifndef _PASECLIDEVFILE_H
#define _PASECLIDEVFILE_H

#define PRINTF_FILE_MAX 2048

/* dump to file ("/tmp/libdb400_trace_"+getpid())
 * dev_file_dump - dump printf memory, rest to empty
 * dev_file      - dump printf("fomat", data, ...) 
 */
extern void dev_file_dump();
extern void dev_file(const char * format, ...);

#endif /* _PASECLIDEVFILE_H */

