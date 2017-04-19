#ifndef _PASECLIDEVCONSOLE_H
#define _PASECLIDEVCONSOLE_H

/* dump to stdout (tty)
 * dev_console_dump - dump printf memory, rest to empty
 * dev_console      - dump printf("fomat", data, ...) 
 */
extern void dev_console_dump();
extern void dev_console(const char * format, ...);

#endif /* _PASECLIDEVCONSOLE_H */

