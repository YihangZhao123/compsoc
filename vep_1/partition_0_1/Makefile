include ../../vep_0/share/make_common.mk

USER_LIBS :=
USER_CFLAGS :=
USER_LINK_FLAGS :=

SOURCES +=  $(wildcard ../single_fifo1/single/*.c)  $(wildcard ../single_fifo1/single/tile/*.c) \
			$(wildcard ../single_fifo1/single/tile/sdfactor/*.c)   $(wildcard ../single_fifo1/single/tile/sdfchannel/*.c) \
			$(wildcard ../single_fifo1/single/datatype/*.c)  $(wildcard ../single_fifo1/single/circular_fifo_lib/*.c) 



HEADERS +=  $(wildcard ../single_fifo1/single/*.h)  $(wildcard ../single_fifo1/single/tile/*.h) \
			$(wildcard ../single_fifo1/single/tile/sdfactor/*.h)   $(wildcard ../single_fifo1/single/tile/sdfchannel/*.h)\
			$(wildcard ../single_fifo1/single/datatype/*.h)  $(wildcard ../single_fifo1/single/circular_fifo_lib/*.h)


include ../../vep_0/share/make_tile.mk
