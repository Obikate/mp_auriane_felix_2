PROGS=test_check_interval test_operator_plus_right test_affectation_one 
PROGS +=test_check_interval test_operator_minus_right test_operator_minus_left
PROGS += test_VectorAccessor test_affectation_two test_operator_plus_left 
PROGS += test_write_VectorAccessor test_operator_times_right
PROGS += test_operator_times_left test_operator_divide test_operator_divide_zero
PROGS += test_operator_plus_vector test_operator_plus_vector_invalid
PROGS += test_operator_minus_vector test_operator_unary_minus test_outstream
PROGS += test_outstream_empty test_instream
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
