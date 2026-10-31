#include <stdio.h>

void test_list(void);
void test_dynarray(void);

int main(void) {
    test_list();
    test_dynarray();
    puts("All tests passed");
    return 0;
}