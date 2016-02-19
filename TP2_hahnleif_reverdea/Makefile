.PHONY : clean
clean:
	$(MAKE) -C src/ clean
	$(MAKE) -C docu/ clean

.PHONY : doc
doc: 
	$(MAKE) -C docu/ doc

.PHONY : all
all: doc
	$(MAKE) -C src/ all

.PHONY : check
check: 
	$(MAKE) -C src/ check
