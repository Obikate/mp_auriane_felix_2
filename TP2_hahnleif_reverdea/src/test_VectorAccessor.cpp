/**
 * @author Auriane, Felix.
 * @date 06/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la méthode 
 * getVector.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector v("tp1_test1.txt");
    assert(v.size() == 10);
    double res = v[9];
    assert(res == 7.4815159e-01);
    res = v(9);
    assert(res == 7.4815159e-01);
    std::cout<<"OK"<<std::endl;
}
