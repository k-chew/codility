#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct binary {
  int length;
  int *code;
};

// getBinary(n) converts a number into binary code
//    where each bit is one entry of an integer array
//    from LEAST to most significant
struct binary *getBinary(int n) {
  struct binary *b = malloc(sizeof(struct binary));
  b->length = 0;
  b->code = malloc(sizeof(int));
  int bit = 0;
  while (n > 0) {
    // insert bit
    bit = n % 2;
    b->code[b->length] = bit;
    
    n /= 2;
    ++b->length;
    b->code = realloc(b->code, sizeof(int) * (b->length + 1));
  }
  return b;
}


// hammingDistance(x, y) counts the number of differing bits in two numbers
// requires: x, y > 0
int hammingDistance(int x, int y) {
  assert(x > 0 && y > 0);
  int retval = 0;
  struct binary *xBinary = getBinary(x);
  struct binary *yBinary = getBinary(y);
  
  int max;
  // get maximum code length
  if (xBinary->length > yBinary->length) {
    max = xBinary->length;
  } else {
    max = yBinary->length;
  }
  
  // compare each bit
  int i = 0;
  while (i < max) {
    // first we check if we've "gone through" one byte and not the other
    // (that is, the finished byte consists only of 0s from here on out)
    if (i >= xBinary->length) {
      if (yBinary->code[i] != 0) {
        ++retval;
      }
    } else if (i >= yBinary->length) {
      if (xBinary->code[i] != 0) {
        ++retval;
      }
    // otherwise, we compare the bits with each other as they may be 0s or 1s
    } else {
      if (xBinary->code[i] != yBinary->code[i]) {
        ++retval;
      }
    }
    ++i;
  }
  
  free(xBinary->code);
  free(xBinary);
  free(yBinary->code);
  free(yBinary);
  return retval;
}

int main(void) {
  assert(hammingDistance(3, 1) == 1);
  assert(hammingDistance(4, 1) == 2);
  assert(hammingDistance(1, 1) == 1);
}
