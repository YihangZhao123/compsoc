#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xil_printf.h>
#include <platform.h>
#include "../multi_fifo1/tile1/subsystem_tile1.h"
#include "../multi_fifo1/datatype/datatype_definition.h"
#include "../multi_fifo1/circular_fifo_lib/circular_fifo_lib.h"


int main(){
    init_tile1();
    subsystem_tile1();
    return 0;
}