extern void abort(void);

void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {abort();} } }
extern int __VERIFIER_nondet_int();
extern void __VERIFIER_assume(int);

// function used to check for the presence of 'value' in the array 'list'.
int is_present(int list[], int size, int value) {
    int i;
    for (i = 0; i < size; i++) {
        if (list[i] == value) return i; // Return index if found
    }
    return -1; // Return -1 if not found
}

// Main function to implement a multiset
int main() {
    int size = 4;
    int list[size];
    int counter[size];
    int n = 0; // Number of unique elements in the list

    for (int v = 0; v < size; v++) {
        int element = __VERIFIER_nondet_int(); // Arbitrary input element

        int pos = is_present(list, n, element);
        if (pos == -1) { // If element is not present
            list[n] = element;
            counter[n] = 1;
            n++;
        } else { // If element is already present
            counter[pos]++;
        }
    }

    // Verify that the sum of all counters equals the total number of inserted elements
    int sum_counters = 0;
    for (int i = 0; i < n; i++) {
        sum_counters += counter[i];
    }

    __VERIFIER_assert(sum_counters == size);

    return 0;
}
