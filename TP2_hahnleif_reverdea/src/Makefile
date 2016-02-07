PROGS=test_check_interval test_operator_plus_right test_affectation_one 
PROGS +=test_check_interval test_operator_minus_right test_operator_minus_left
PROGS += test_VectorAccessor test_affectation_two test_operator_plus_left 
PROGS += test_write_VectorAccessor
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
