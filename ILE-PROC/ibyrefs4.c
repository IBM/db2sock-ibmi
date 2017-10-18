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

bighole_t iCallFctByRef96(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95)
    );
}

bighole_t iCallFctByRef97(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96)
    );
}

bighole_t iCallFctByRef98(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97)
    );
}

bighole_t iCallFctByRef99(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98)
    );
}

bighole_t iCallFctByRef100(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99)
    );
}

bighole_t iCallFctByRef101(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100)
    );
}

bighole_t iCallFctByRef102(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101)
    );
}

bighole_t iCallFctByRef103(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102)
    );
}

bighole_t iCallFctByRef104(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103)
    );
}

bighole_t iCallFctByRef105(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104)
    );
}

bighole_t iCallFctByRef106(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105)
    );
}

bighole_t iCallFctByRef107(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106)
    );
}

bighole_t iCallFctByRef108(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107)
    );
}

bighole_t iCallFctByRef109(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108)
    );
}

bighole_t iCallFctByRef110(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109)
    );
}

bighole_t iCallFctByRef111(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110)
    );
}

bighole_t iCallFctByRef112(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111)
    );
}

bighole_t iCallFctByRef113(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112)
    );
}

bighole_t iCallFctByRef114(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113)
    );
}

bighole_t iCallFctByRef115(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114)
    );
}

bighole_t iCallFctByRef116(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115)
    );
}

bighole_t iCallFctByRef117(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116)
    );
}

bighole_t iCallFctByRef118(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117)
    );
}

bighole_t iCallFctByRef119(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118)
    );
}

bighole_t iCallFctByRef120(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119)
    );
}

bighole_t iCallFctByRef121(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120)
    );
}

bighole_t iCallFctByRef122(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120), iNextPtr(layout, 121)
    );
}

bighole_t iCallFctByRef123(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120), iNextPtr(layout, 121), iNextPtr(layout, 122)
    );
}

bighole_t iCallFctByRef124(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120), iNextPtr(layout, 121), iNextPtr(layout, 122), iNextPtr(layout, 123)
    );
}

bighole_t iCallFctByRef125(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120), iNextPtr(layout, 121), iNextPtr(layout, 122), iNextPtr(layout, 123), iNextPtr(layout, 124)
    );
}

bighole_t iCallFctByRef126(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120), iNextPtr(layout, 121), iNextPtr(layout, 122), iNextPtr(layout, 123), iNextPtr(layout, 124), iNextPtr(layout, 125)
    );
}

bighole_t iCallFctByRef127(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  os_fct_pattern_t * os_fct_ptr = iNextFunc(layout, myPgm, myLib, myFunc, lenFunc);
  return os_fct_ptr(
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
    iNextPtr(layout, 91), iNextPtr(layout, 92), iNextPtr(layout, 93), iNextPtr(layout, 94), iNextPtr(layout, 95), iNextPtr(layout, 96), iNextPtr(layout, 97), 
    iNextPtr(layout, 98), iNextPtr(layout, 99), iNextPtr(layout, 100), iNextPtr(layout, 101), iNextPtr(layout, 102), iNextPtr(layout, 103), iNextPtr(layout, 104), 
    iNextPtr(layout, 105), iNextPtr(layout, 106), iNextPtr(layout, 107), iNextPtr(layout, 108), iNextPtr(layout, 109), iNextPtr(layout, 110), iNextPtr(layout, 111), 
    iNextPtr(layout, 112), iNextPtr(layout, 113), iNextPtr(layout, 114), iNextPtr(layout, 115), iNextPtr(layout, 116), iNextPtr(layout, 117), iNextPtr(layout, 118), 
    iNextPtr(layout, 119), iNextPtr(layout, 120), iNextPtr(layout, 121), iNextPtr(layout, 122), iNextPtr(layout, 123), iNextPtr(layout, 124), iNextPtr(layout, 125), 
    iNextPtr(layout, 126)
    );
}

bighole_t iCallFctByRefSub4(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  switch(layout->argc) {
  case 96:
    return iCallFctByRef96(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 97:
    return iCallFctByRef97(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 98:
    return iCallFctByRef98(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 99:
    return iCallFctByRef99(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 100:
    return iCallFctByRef100(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 101:
    return iCallFctByRef101(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 102:
    return iCallFctByRef102(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 103:
    return iCallFctByRef103(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 104:
    return iCallFctByRef104(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 105:
    return iCallFctByRef105(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 106:
    return iCallFctByRef106(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 107:
    return iCallFctByRef107(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 108:
    return iCallFctByRef108(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 109:
    return iCallFctByRef109(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 110:
    return iCallFctByRef110(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 111:
    return iCallFctByRef111(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 112:
    return iCallFctByRef112(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 113:
    return iCallFctByRef113(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 114:
    return iCallFctByRef114(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 115:
    return iCallFctByRef115(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 116:
    return iCallFctByRef116(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 117:
    return iCallFctByRef117(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 118:
    return iCallFctByRef118(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 119:
    return iCallFctByRef119(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 120:
    return iCallFctByRef120(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 121:
    return iCallFctByRef121(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 122:
    return iCallFctByRef122(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 123:
    return iCallFctByRef123(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 124:
    return iCallFctByRef124(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 125:
    return iCallFctByRef125(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 126:
    return iCallFctByRef126(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 127:
    return iCallFctByRef127(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  default:
    break;
  }
}
