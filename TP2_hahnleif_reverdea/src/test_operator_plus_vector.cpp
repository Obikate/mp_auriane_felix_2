/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x = x + x;
    assert(x.pCor[0] == 5);
    assert(x.pCor[1] == 5);
    assert(x.pCor[2] == 5);
    Dvector y(3, 3);
    x = x + y;
    assert(x.pCor[0] == 8);
    assert(x.pCor[1] == 8);
    assert(x.pCor[2] == 8);
    std::cout<<"OK"<<std::endl;
}
