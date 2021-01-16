#include <stdio.h>
#include "../include/a.h"
#include "../include/b.h"

int main(int argc, char *argv[])
{
    int max = 0;
    int min = 0;   
    char Array[]="Hello World.";

    max = GetMaxNum(1, 4);
    min = GetMinNum(1, 4);

    printf("%s.\r\n", Array);
    printf("Max is %d Min is %d.\r\n", max, min);

    return 0;
}
