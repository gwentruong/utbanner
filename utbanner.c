#include <stdio.h>

void a(void);

int main(void)
{
    a();
    return 0;
}

void a(void)
{
    printf("  AAA   \n"
           " AAAAA  \n"
           "AA   AA \n"
           "AAAAAAA \n"
           "AA   AA \n");
}
