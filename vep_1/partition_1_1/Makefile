include ../../vep_0/share/make_common.mk

USER_LIBS :=
USER_CFLAGS :=
USER_LINK_FLAGS :=
SOURCES +=  $(wildcard ../multi_fifo1/*.c)  $(wildcard ../multi_fifo1/tile2/*.c) \
			$(wildcard ../multi_fifo1/tile2/sdfactor/*.c)   $(wildcard ../multi_fifo1/tile2/sdfchannel/*.c) \
			$(wildcard ../multi_fifo1/datatype/*.c)  $(wildcard ../multi_fifo1/circular_fifo_lib/*.c) 



HEADERS +=  $(wildcard ../multi_fifo1/*.h)  $(wildcard ../multi_fifo1/tile2/*.h) \
			$(wildcard ../multi_fifo1/tile2/sdfactor/*.h)   $(wildcard ../multi_fifo1/tile2/sdfchannel/*.h)\
			$(wildcard ../multi_fifo1/datatype/*.h)  $(wildcard ../multi_fifo1/circular_fifo_lib/*.h)
include ../../vep_0/share/make_tile.mk
