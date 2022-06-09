#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xil_printf.h>
#include <platform.h>
#include "../single_fifo2/single/tile/subsystem.h"
#include "../single_fifo2/single/datatype/datatype_definition.h"
#include "../single_fifo2/single/circular_fifo_lib/circular_fifo_lib.h"

int main(){
    
   init_subsystem();

   extern circular_fifo fifo_s_in;
   for(int i=0;i<5;++i){
       int a[4];
       a[0]=4*i+1;
       a[1]=4*i+2;
       a[2]=4*i+3;
       a[3]=4*i+4;
       write_fifo(&fifo_s_in,a,4);
   }
    subsystem();
    return 0;
}