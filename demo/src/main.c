#include <stdio.h>
#include <stdlib.h>
#include "../../src/funnel.h"

int main(int argc, char** argv)
{
    printf("hello world\n");

    FUNNEL* demo = funnel_open("D:\\Github\\funnel\\test.csv");
    if (demo == NULL)
    {
        printf("cannot open funnel\n");
        return 1;
    }

    funnel_write(demo, "1,2,3,4,5,6,7,8,9,0\n");
    funnel_push_int_row(demo, 10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0);

    funnel_close(demo);

    return 0;
}