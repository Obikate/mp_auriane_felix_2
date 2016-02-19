PROGS=$(patsubst %.cpp, %, $(wildcard test_*.cpp))

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
	for i in $(PROGS); do echo $$i; ./$$i;echo "\n";done;
