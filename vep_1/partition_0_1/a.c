#include "a.h"



void foo(){

    char *a="memcpy test\n";
    char b[20];

    memcpy(b,a,strlen(a)+1);
    for(int i=0; i <strlen(a);++i){
        xil_printf("%d",a[i]);
    }
        xil_printf("\n");
    for(int i=0; i <strlen(b);++i){
        xil_printf("%d",b[i]);
    }
    xil_printf("\n");
    xil_printf("in foo\n");
}