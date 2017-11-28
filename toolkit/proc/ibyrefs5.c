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
#include "../PaseTool.h"
#include "iconf.h" /* see Makefile */
#include "ibyref.h"

bighole_t iCallFctByRef128(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127)
    );
}

bighole_t iCallFctByRef129(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128)
    );
}

bighole_t iCallFctByRef130(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129)
    );
}

bighole_t iCallFctByRef131(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130)
    );
}

bighole_t iCallFctByRef132(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131)
    );
}

bighole_t iCallFctByRef133(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132)
    );
}

bighole_t iCallFctByRef134(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133)
    );
}

bighole_t iCallFctByRef135(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134)
    );
}

bighole_t iCallFctByRef136(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135)
    );
}

bighole_t iCallFctByRef137(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136)
    );
}

bighole_t iCallFctByRef138(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137)
    );
}

bighole_t iCallFctByRef139(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138)
    );
}

bighole_t iCallFctByRef140(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139)
    );
}

bighole_t iCallFctByRef141(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140)
    );
}

bighole_t iCallFctByRef142(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141)
    );
}

bighole_t iCallFctByRef143(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142)
    );
}

bighole_t iCallFctByRef144(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143)
    );
}

bighole_t iCallFctByRef145(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144)
    );
}

bighole_t iCallFctByRef146(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145)
    );
}

bighole_t iCallFctByRef147(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146)
    );
}

bighole_t iCallFctByRef148(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147)
    );
}

bighole_t iCallFctByRef149(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148)
    );
}

bighole_t iCallFctByRef150(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149)
    );
}

bighole_t iCallFctByRef151(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150)
    );
}

bighole_t iCallFctByRef152(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151)
    );
}

bighole_t iCallFctByRef153(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152)
    );
}

bighole_t iCallFctByRef154(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152), iNextPtr(layout, 153)
    );
}

bighole_t iCallFctByRef155(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152), iNextPtr(layout, 153), 
    iNextPtr(layout, 154)
    );
}

bighole_t iCallFctByRef156(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152), iNextPtr(layout, 153), 
    iNextPtr(layout, 154), iNextPtr(layout, 155)
    );
}

bighole_t iCallFctByRef157(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152), iNextPtr(layout, 153), 
    iNextPtr(layout, 154), iNextPtr(layout, 155), iNextPtr(layout, 156)
    );
}

bighole_t iCallFctByRef158(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152), iNextPtr(layout, 153), 
    iNextPtr(layout, 154), iNextPtr(layout, 155), iNextPtr(layout, 156), iNextPtr(layout, 157)
    );
}

bighole_t iCallFctByRef159(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
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
    iNextPtr(layout, 126), iNextPtr(layout, 127), iNextPtr(layout, 128), iNextPtr(layout, 129), iNextPtr(layout, 130), iNextPtr(layout, 131), iNextPtr(layout, 132), 
    iNextPtr(layout, 133), iNextPtr(layout, 134), iNextPtr(layout, 135), iNextPtr(layout, 136), iNextPtr(layout, 137), iNextPtr(layout, 138), iNextPtr(layout, 139), 
    iNextPtr(layout, 140), iNextPtr(layout, 141), iNextPtr(layout, 142), iNextPtr(layout, 143), iNextPtr(layout, 144), iNextPtr(layout, 145), iNextPtr(layout, 146), 
    iNextPtr(layout, 147), iNextPtr(layout, 148), iNextPtr(layout, 149), iNextPtr(layout, 150), iNextPtr(layout, 151), iNextPtr(layout, 152), iNextPtr(layout, 153), 
    iNextPtr(layout, 154), iNextPtr(layout, 155), iNextPtr(layout, 156), iNextPtr(layout, 157), iNextPtr(layout, 158)
    );
}

bighole_t iCallFctByRefSub5(ile_pgm_call_t* layout, char * myPgm, char * myLib, char * myFunc, int lenFunc)
{
  switch(layout->argc) {
  case 128:
    return iCallFctByRef128(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 129:
    return iCallFctByRef129(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 130:
    return iCallFctByRef130(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 131:
    return iCallFctByRef131(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 132:
    return iCallFctByRef132(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 133:
    return iCallFctByRef133(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 134:
    return iCallFctByRef134(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 135:
    return iCallFctByRef135(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 136:
    return iCallFctByRef136(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 137:
    return iCallFctByRef137(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 138:
    return iCallFctByRef138(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 139:
    return iCallFctByRef139(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 140:
    return iCallFctByRef140(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 141:
    return iCallFctByRef141(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 142:
    return iCallFctByRef142(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 143:
    return iCallFctByRef143(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 144:
    return iCallFctByRef144(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 145:
    return iCallFctByRef145(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 146:
    return iCallFctByRef146(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 147:
    return iCallFctByRef147(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 148:
    return iCallFctByRef148(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 149:
    return iCallFctByRef149(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 150:
    return iCallFctByRef150(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 151:
    return iCallFctByRef151(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 152:
    return iCallFctByRef152(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 153:
    return iCallFctByRef153(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 154:
    return iCallFctByRef154(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 155:
    return iCallFctByRef155(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 156:
    return iCallFctByRef156(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 157:
    return iCallFctByRef157(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 158:
    return iCallFctByRef158(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  case 159:
    return iCallFctByRef159(layout, myPgm, myLib, myFunc, lenFunc);
    break;
  default:
    break;
  }
}
