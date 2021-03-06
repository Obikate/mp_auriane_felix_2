#ifndef DVECTORH
#define DVECTORH

#include <iostream>

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
        Dvector & operator=(const Dvector &);
        double & operator()(int i);
        double & operator[](int i);
        double & operator()(int i) const;
        double & operator[](int i) const;
        Dvector & operator +=(const Dvector & dvec); 
        Dvector & operator +=(const double & d); 
        Dvector & operator -=(const Dvector & dvec); 
        Dvector & operator -=(const double & d); 
        Dvector & operator *=(const double & d); 
        Dvector & operator /=(const double & d); 
        bool operator ==(const Dvector & dvec);
        bool operator !=(const Dvector & dvec);

        void resize(int newDim, double newVal=0);
};
Dvector operator-(const Dvector &);
//opérations entre un Dvector et un double
Dvector operator +(const Dvector &, const double &); 
Dvector operator +(const double &, const Dvector &); 
Dvector operator -(const Dvector &, const double &); 
Dvector operator -(const double &, const Dvector &); 
Dvector operator *(const Dvector &, const double &); 
Dvector operator *(const double &, const Dvector &); 
Dvector operator /(const Dvector &, const double &); 

//opérations entre deux Dvectors
Dvector operator +(const Dvector &, const Dvector &); 
Dvector operator -(const Dvector &, const Dvector &); 
//opérateurs de flux
std::ostream & operator <<(std::ostream &, const Dvector &);
std::istream & operator >>(std::istream &, const Dvector &);


#endif
