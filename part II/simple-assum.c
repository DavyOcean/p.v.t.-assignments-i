#include <assert.h>

int multiplyBy3(int y)
{
  int x = 3;
  
  int res = 0;
  int i = x;
  while(i != 0){
    res += y;
    i--;
  }
  assert(res == x*y);
}

int multiply(int x, int y)
{ 
  // Assumptions about the inputs
  __CPROVER_assume(x >= 0 && x <= 10);
  __CPROVER_assume(y >= 0 && y <= 10);

  int res = 0;
  int i = x;
  while(i != 0){
    res += y;
    i--;
  }
  assert(res == x*y);
}
