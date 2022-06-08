# skip system vep_0 which is treated special
VEPS := $(wildcard vep_[1-9]*)
TOOLS := ./tools
TOOLSSRC := $(wildcard $(MONITORING)/*.[ch])

all: make-vep_0 tools $(foreach v, $(VEPS), make-$v)

# monitoring tools depend on precompiled vep_0/libchannel
# doesn't need a dependency
tools $(TOOLS)/generate-json: $(TOOLSSRC)
	make -C $(TOOLS)

make-%: %
	make -C $^

tdm: $(TOOLS)/generate-json
	@if [ -f $(TOOLS)/vep-config.txt ] ; then \
	$(TOOLS)/generate-json $(TOOLS)/vep-config.txt -json -tdm > /dev/null ; \
	else \
	echo 'warning: showing memory map with all veps (without ./run.sh -xv option)' ; \
	rm -f $(TOOLS)/vep-config.make ; \
	grep -v -H '^#' vep_[1-9]*/vep-config.txt | sed -e 's+vep_\([0-9][0-9]*\)/vep-config.txt:+vep \1 +g' -e 's/#.*$$//g' > $(TOOLS)/vep-config.make ; \
	$(TOOLS)/generate-json $(TOOLS)/vep-config.make -json -tdm > /dev/null ; \
	rm -f $(TOOLS)/vep-config.make ; \
	fi

mm memmap: $(TOOLS)/generate-json
	@if [ -f $(TOOLS)/vep-config.txt ] ; then \
	$(TOOLS)/generate-json $(TOOLS)/vep-config.txt -json -mm > /dev/null ; \
	else \
	echo 'warning: showing memory map with all veps (without ./run.sh -xv option)' ; \
	echo 'memory map as specified in the vep_*/vep-config.txt files, as seen by all partitions' ; \
	grep -v -H '^#' vep_[1-9]*/vep-config.txt | sed -e 's+vep_\([0-9][0-9]*\)/vep-config.txt:+vep \1 +g' -e 's/#.*$$//g' > $(TOOLS)/vep-config.make ; \
	$(TOOLS)/generate-json $(TOOLS)/vep-config.make -json -mm > /dev/null ; \
	rm -f $(TOOLS)/vep-config.make ; \
	fi

mmp memmap-physical: $(TOOLS)/generate-json
	@if [ -f $(TOOLS)/vep-config.txt ] ; then \
	grep -v '^#' vep_*/vep-config.txt | grep have | sed -e 's/#.*$$//g' -e 's+vep_\([0-9][0-9]*\)/vep-config.txt:+vep \1 +g' -e 's/vep \([0-9]\) in \(mem..\) have \(.*\) memory starting at \(.*\)$$/\2 from \4 range \3 for vep \1/g' -e 's/  / /g' -e 's/K/ K/g' | sort | sed -e 's/ K/K/g' ; \
	else \
	echo 'warning: showing memory map with default vep-config.txt with all veps (not generated by run.sh)' ; \
	echo 'memory map as specified in the vep_*/vep-config.txt files, without remapping, sorted by memory' ; \
	grep -v -H '^#' vep_[1-9]*/vep-config.txt | grep have | sed -e 's/#.*$$//g' -e 's+vep_\([0-9][0-9]*\)/vep-config.txt:+vep \1 +g' -e 's/vep \([0-9]\) in \(mem..\) have \(.*\) memory starting at \(.*\)$$/\2 from \4 range \3 for vep \1/g' -e 's/  / /g' -e 's/K/ K/g' | sort | sed -e 's/ K/K/g' ; \
	fi

# only clean vep_0 & tools with veryclean
clean: $(foreach dir, $(VEPS), clean-$(dir)) 
	-rm -f $(TOOLS)/vep-config.make $(TOOLS)/vep-config.cmd $(TOOLS)/vep-config.txt

clean-%: %
	make -C $^ clean

veryclean: clean
	make -C vep_0 clean
	make -C $(TOOLS) veryclean

.PHONY: all make-vep_0 tools tdm mm memmap mmp memmap-physical clean veryclean