#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <xil_printf.h>
#include <platform.h>
#include "a.h"
#include "circular_fifo_lib.h"
int main ( void )
{

  foo();
  xil_printf("Hello world\n");

  int buffer [11];
  circular_fifo fifo;
  init_fifo(&fifo,buffer,11,sizeof(int));


  int src[10]={1,2,3,4,5,6,7,8,9,0};
  write_fifo(&fifo,src,10);

  PRINT(&fifo);

  int dst[20];

  read_fifo(&fifo,dst,15);

  PRINT(&fifo);


  
  return 0;
}
