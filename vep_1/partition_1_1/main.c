#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xil_printf.h>
#include <platform.h>
#include "../multi_fifo1/tile2/subsystem_tile2.h"
#include "../multi_fifo1/datatype/datatype_definition.h"
#include "../multi_fifo1/circular_fifo_lib/circular_fifo_lib.h"


#define X 5
#define Y 5
UInt16 dimX_global=X;
UInt16 dimY_global=Y;


double c[Y][X];
double *d[Y];

ArrayXOfArrayXOfDoubleType system_img_sink_global;
int main ( void )
{


    for(int i=0;i<Y;++i){
        for(int j=0;j<X;++j){
            c[i][j]=0;
        }
    }
    for(int i=0;i<Y;++i){
          d[i]=c+i;
    }    

    system_img_sink_global=d;

    init_tile2();
    subsystem_tile2();   
 
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