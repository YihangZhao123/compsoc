#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xil_printf.h>
#include <platform.h>
#include "../multi_fifo1/tile1/subsystem_tile1.h"
#include "../multi_fifo1/datatype/datatype_definition.h"
#include "../multi_fifo1/circular_fifo_lib/circular_fifo_lib.h"


#define X 5
#define Y 5
UInt16 dimX_global=X;
UInt16 dimY_global=Y;
double a[Y][X];
double *b[Y];

double c[Y][X];
double *d[Y];
ArrayXOfArrayXOfDoubleType system_img_source_global;
ArrayXOfArrayXOfDoubleType system_img_sink_global;
int main(){
    int e=0;
    for(int i=0;i<Y;++i){
        for(int j=0;j<X;++j){
            a[i][j]=e;
            ++e;
            c[i][j]=0;
        }
    }

    for(int i=0;i<Y;++i){
          b[i]=a+i;
    }
    system_img_source_global=b;





        init_tile1();
        subsystem_tile1();
    
    // printf("\n");
    // for(int i=0;i<dimY_global;++i){
    //     for(int j=0;j<dimX_global;++j){
    //         printf("%f, ", c[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}

void mytest(){

 		extern UInt16 dimX_global;
		extern UInt16 dimY_global;
		extern ArrayXOfArrayXOfDoubleType system_img_sink_global;
		xil_printf("------------------------->\n");
		for(int i=0;i<dimY_global;++i){
			for(int j=0;j<dimX_global;++j){
				xil_printf("%d, ", (UInt16)system_img_sink_global[i][j]);
			}
			xil_printf("\n");
		}   
}