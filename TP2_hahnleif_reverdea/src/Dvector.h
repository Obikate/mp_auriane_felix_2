#ifndef DVECTORH
#define DVECTORH

#include <iostream>
#include <fstream>
#include "stdlib.h"
#include <stdexcept>
#include <cstring>

class Dvector {
    private:
        int dim;
    public:
        double *pCor;
        //question 1
        Dvector(int dim=0, double init=0);
        ~Dvector();
        void display(std::ostream& str);
        //question 2
        int size(int catchError=0) const;
        void fillRandomly(int catchError=0);
        Dvector(const Dvector & d);
        //question 3
        Dvector(std::string str);
        //TP2
        void checkInterval(int inf, int max, int arg);
        Dvector & operator=(const Dvector &);
	     double & operator()(int i);
     	  double & operator[](int i);
};
        Dvector operator +(const Dvector &, const double &); 

#endif
