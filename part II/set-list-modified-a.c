extern void abort(void);

void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {abort();} } }
extern int __VERIFIER_nondet_int();
extern void __VERIFIER_assume(int);

// function used to implement a set with an array. Check for the presence of 'value' in the array 'list'.
int is_present( int list [ ] , int size , int value ) {
  int i;
  for ( i = 0 ; i < size ; i++ ) {
    if ( list[ i ] == value ) return 1;
  }
  return 0;
}

int main( ) {

  int size = 4;

  int n = 0;
  int list[ size ];

  int v;

  // insert elements in the list
  int element = 1;
  for ( v = 0 ; v < size ; v++ ) {
    if (is_present(list, n, element) == 0) {
      list[n] = element;
      n++;
    }
  }

  
  // Check that each element is unique
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      __VERIFIER_assert(list[i] != list[j]);
    }
  }
return 0;
}
