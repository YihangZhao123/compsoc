include ../../vep_0/share/make_common.mk

USER_LIBS :=
USER_CFLAGS :=
USER_LINK_FLAGS :=

SOURCES +=  $(wildcard ../multi_fifo2/*.c)  $(wildcard ../multi_fifo2/tile0/*.c) \
			$(wildcard ../multi_fifo2/tile0/sdfactor/*.c)   $(wildcard ../multi_fifo2/tile0/sdfchannel/*.c) \
			$(wildcard ../multi_fifo2/datatype/*.c)  $(wildcard ../multi_fifo2/circular_fifo_lib/*.c) 



HEADERS +=  $(wildcard ../multi_fifo2/*.h)  $(wildcard ../multi_fifo2/tile0/*.h) \
			$(wildcard ../multi_fifo2/tile0/sdfactor/*.h)   $(wildcard ../multi_fifo2/tile0/sdfchannel/*.h)\
			$(wildcard ../multi_fifo2/datatype/*.h)  $(wildcard ../multi_fifo2/circular_fifo_lib/*.h)


include ../../vep_0/share/make_tile.mk
