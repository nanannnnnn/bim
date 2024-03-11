#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<ctype.h>
#include<stdbool.h>
#include<stdint.h>
#include<float.h>
#include<math.h>
#include<string.h>
#include<assert.h>
#include<time.h>
#include<sys/time.h>
#include<ncurses.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)
#define MIN(x, y) (x) < (y) ? (x) : (y)

#define P(x) \
  fprintf(stderr, "(%s:%d) %s = (long)%ld (double)%f (addr)%p \n", \ __FILE__, __LINE__, #x, (long)(x), (double)(x), (void*)((intptr_t)x)); 
