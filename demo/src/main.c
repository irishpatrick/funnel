#include <stdio.h>
#include <stdlib.h>
#include "../../src/funnel.h"

int main(int argc, char** argv)
{
    printf("hello world\n");

    FUNNEL demo = funnel_open("D:\\Github\\funnel\\test.csv");
    if (demo == NULL)
    {
        printf("cannot open funnel\n");
        return 1;
    }

    int i;
    int j;
    for (i = 0; i < 1024; ++i)
    {
        for (j = 0; j < 1024; ++j)
        {
            funnel_push_int(demo, i * j);
        }
        funnel_write(demo, "\n");
    }

    funnel_close(demo);

    return 0;
}