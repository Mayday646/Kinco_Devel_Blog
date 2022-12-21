#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
程序要求：
*/
 typedef enum
{
	ER_OK = 0,
	ER_OTHER,
	ER_TIMEOUT,
	ER_INVALID,

}E_ERROR_CODE;
int main(int argc, char *argv[])
{
    E_ERROR_CODE DATE= ER_INVALID;
    printf("%d ",DATE);
}
//Date:2022/12/21/16:29