#include <miptrnam.h>
#include <miptrnam.h>
#include <mih/rslvsp.h>
#include <mih/miobjtyp.h>
#include <leawi.h>
#include <qleawi.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <qtqiconv.h>
#include <qp2user.h>
#include <except.h>
#include "../toolkit-base/PaseTool.h"
#include "iconf.h" /* see Makefile */
#include "ibyref.h"

void iCallPgmByRef64(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63)
    );
}

void iCallPgmByRef65(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64)
    );
}

void iCallPgmByRef66(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65)
    );
}

void iCallPgmByRef67(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66)
    );
}

void iCallPgmByRef68(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67)
    );
}

void iCallPgmByRef69(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68)
    );
}

void iCallPgmByRef70(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69)
    );
}

void iCallPgmByRef71(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70)
    );
}

void iCallPgmByRef72(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71)
    );
}

void iCallPgmByRef73(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72)
    );
}

void iCallPgmByRef74(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73)
    );
}

void iCallPgmByRef75(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74)
    );
}

void iCallPgmByRef76(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75)
    );
}

void iCallPgmByRef77(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76)
    );
}

void iCallPgmByRef78(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77)
    );
}

void iCallPgmByRef79(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78)
    );
}

void iCallPgmByRef80(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79)
    );
}

void iCallPgmByRef81(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80)
    );
}

void iCallPgmByRef82(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81)
    );
}

void iCallPgmByRef83(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82)
    );
}

void iCallPgmByRef84(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83)
    );
}

void iCallPgmByRef85(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84)
    );
}

void iCallPgmByRef86(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85)
    );
}

void iCallPgmByRef87(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86)
    );
}

void iCallPgmByRef88(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87)
    );
}

void iCallPgmByRef89(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88)
    );
}

void iCallPgmByRef90(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88), iNextPtr(layout, 89)
    );
}

void iCallPgmByRef91(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88), iNextPtr(layout, 89), iNextPtr(layout, 90)
    );
}

void iCallPgmByRef92(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88), iNextPtr(layout, 89), iNextPtr(layout, 90), 
    iNextPtr(layout, 91)
    );
}

void iCallPgmByRef93(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88), iNextPtr(layout, 89), iNextPtr(layout, 90), 
    iNextPtr(layout, 91), iNextPtr(layout, 92)
    );
}

void iCallPgmByRef94(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88), iNextPtr(layout, 89), iNextPtr(layout, 90), 
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93)
    );
}

void iCallPgmByRef95(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  os_pgm_pattern_t *os_pfct_ptr = iNextPgm(layout, myPgm, myLib);
  os_pfct_ptr(
    iNextPtr(layout, 0), iNextPtr(layout, 1), iNextPtr(layout, 2), iNextPtr(layout, 3), iNextPtr(layout, 4), iNextPtr(layout, 5), iNextPtr(layout, 6), 
    iNextPtr(layout, 7), iNextPtr(layout, 8), iNextPtr(layout, 9), iNextPtr(layout, 10), iNextPtr(layout, 11), iNextPtr(layout, 12), iNextPtr(layout, 13), 
    iNextPtr(layout, 14), iNextPtr(layout, 15), iNextPtr(layout, 16), iNextPtr(layout, 17), iNextPtr(layout, 18), iNextPtr(layout, 19), iNextPtr(layout, 20), 
    iNextPtr(layout, 21), iNextPtr(layout, 22), iNextPtr(layout, 23), iNextPtr(layout, 24), iNextPtr(layout, 25), iNextPtr(layout, 26), iNextPtr(layout, 27), 
    iNextPtr(layout, 28), iNextPtr(layout, 29), iNextPtr(layout, 30), iNextPtr(layout, 31), iNextPtr(layout, 32), iNextPtr(layout, 33), iNextPtr(layout, 34), 
    iNextPtr(layout, 35), iNextPtr(layout, 36), iNextPtr(layout, 37), iNextPtr(layout, 38), iNextPtr(layout, 39), iNextPtr(layout, 40), iNextPtr(layout, 41), 
    iNextPtr(layout, 42), iNextPtr(layout, 43), iNextPtr(layout, 44), iNextPtr(layout, 45), iNextPtr(layout, 46), iNextPtr(layout, 47), iNextPtr(layout, 48), 
    iNextPtr(layout, 49), iNextPtr(layout, 50), iNextPtr(layout, 51), iNextPtr(layout, 52), iNextPtr(layout, 53), iNextPtr(layout, 54), iNextPtr(layout, 55), 
    iNextPtr(layout, 56), iNextPtr(layout, 57), iNextPtr(layout, 58), iNextPtr(layout, 59), iNextPtr(layout, 60), iNextPtr(layout, 61), iNextPtr(layout, 62), 
    iNextPtr(layout, 63), iNextPtr(layout, 64), iNextPtr(layout, 65), iNextPtr(layout, 66), iNextPtr(layout, 67), iNextPtr(layout, 68), iNextPtr(layout, 69), 
    iNextPtr(layout, 70), iNextPtr(layout, 71), iNextPtr(layout, 72), iNextPtr(layout, 73), iNextPtr(layout, 74), iNextPtr(layout, 75), iNextPtr(layout, 76), 
    iNextPtr(layout, 77), iNextPtr(layout, 78), iNextPtr(layout, 79), iNextPtr(layout, 80), iNextPtr(layout, 81), iNextPtr(layout, 82), iNextPtr(layout, 83), 
    iNextPtr(layout, 84), iNextPtr(layout, 85), iNextPtr(layout, 86), iNextPtr(layout, 87), iNextPtr(layout, 88), iNextPtr(layout, 89), iNextPtr(layout, 90), 
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94)
    );
}

void iCallPgmByRefSub3(ile_pgm_call_t* layout, char * myPgm, char * myLib)
{
  switch(layout->argc) {
  case 64:
    iCallPgmByRef64(layout, myPgm, myLib);
    break;
  case 65:
    iCallPgmByRef65(layout, myPgm, myLib);
    break;
  case 66:
    iCallPgmByRef66(layout, myPgm, myLib);
    break;
  case 67:
    iCallPgmByRef67(layout, myPgm, myLib);
    break;
  case 68:
    iCallPgmByRef68(layout, myPgm, myLib);
    break;
  case 69:
    iCallPgmByRef69(layout, myPgm, myLib);
    break;
  case 70:
    iCallPgmByRef70(layout, myPgm, myLib);
    break;
  case 71:
    iCallPgmByRef71(layout, myPgm, myLib);
    break;
  case 72:
    iCallPgmByRef72(layout, myPgm, myLib);
    break;
  case 73:
    iCallPgmByRef73(layout, myPgm, myLib);
    break;
  case 74:
    iCallPgmByRef74(layout, myPgm, myLib);
    break;
  case 75:
    iCallPgmByRef75(layout, myPgm, myLib);
    break;
  case 76:
    iCallPgmByRef76(layout, myPgm, myLib);
    break;
  case 77:
    iCallPgmByRef77(layout, myPgm, myLib);
    break;
  case 78:
    iCallPgmByRef78(layout, myPgm, myLib);
    break;
  case 79:
    iCallPgmByRef79(layout, myPgm, myLib);
    break;
  case 80:
    iCallPgmByRef80(layout, myPgm, myLib);
    break;
  case 81:
    iCallPgmByRef81(layout, myPgm, myLib);
    break;
  case 82:
    iCallPgmByRef82(layout, myPgm, myLib);
    break;
  case 83:
    iCallPgmByRef83(layout, myPgm, myLib);
    break;
  case 84:
    iCallPgmByRef84(layout, myPgm, myLib);
    break;
  case 85:
    iCallPgmByRef85(layout, myPgm, myLib);
    break;
  case 86:
    iCallPgmByRef86(layout, myPgm, myLib);
    break;
  case 87:
    iCallPgmByRef87(layout, myPgm, myLib);
    break;
  case 88:
    iCallPgmByRef88(layout, myPgm, myLib);
    break;
  case 89:
    iCallPgmByRef89(layout, myPgm, myLib);
    break;
  case 90:
    iCallPgmByRef90(layout, myPgm, myLib);
    break;
  case 91:
    iCallPgmByRef91(layout, myPgm, myLib);
    break;
  case 92:
    iCallPgmByRef92(layout, myPgm, myLib);
    break;
  case 93:
    iCallPgmByRef93(layout, myPgm, myLib);
    break;
  case 94:
    iCallPgmByRef94(layout, myPgm, myLib);
    break;
  case 95:
    iCallPgmByRef95(layout, myPgm, myLib);
    break;
  default:
    break;
  }
}
