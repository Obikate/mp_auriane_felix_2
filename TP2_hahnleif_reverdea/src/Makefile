PROGS=test_size test_display test_constructor test_constructor_normal 
PROGS += test_empty_file test_values_file test_big_file test_display_file
PROGS += test_constructor_recopie test_fill_randomly
CXX = g++
CXXFLAGS = -Wall #-g

test_%: Dvector.o test_%.o 
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY : clean
clean:
	rm -f *.o $(PROGS)

.PHONY : all
all: $(PROGS)

.PHONY : check
check: all
	for i in $(PROGS); do echo $$i; ./$$i;done;
