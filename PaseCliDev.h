#ifndef _PASECLIDEV_H
#define _PASECLIDEV_H

extern void dev_dump();
extern int dev_go(int sqlrc, char * name);
extern int dev_sql_error(short int hType, int hndl);

#endif /* _PASECLIDEV_H */

