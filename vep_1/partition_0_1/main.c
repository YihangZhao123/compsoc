#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xil_printf.h>
#include <platform.h>
#include "../single_fifo1/single/tile/subsystem.h"
#include "../single_fifo1/single/datatype/datatype_definition.h"
#include "../single_fifo1/single/circular_fifo_lib/circular_fifo_lib.h"


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

    for(int i=0;i<Y;++i){
          d[i]=c+i;
    }    


    system_img_sink_global=d;

        init_subsystem();
        subsystem();
    
    // printf("\n");
    // for(int i=0;i<dimY_global;++i){
    //     for(int j=0;j<dimX_global;++j){
    //         printf("%f, ", c[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}

void test(){

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