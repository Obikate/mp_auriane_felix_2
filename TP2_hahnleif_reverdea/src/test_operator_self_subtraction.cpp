/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur -=.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 3);
    Dvector y(3, 2.5);
    x -= y;
    assert(x.pCor[0] == 0.5);
    assert(x.pCor[1] == 0.5);
    assert(x.pCor[2] == 0.5);
    x -= x;
    assert(x.pCor[0] == 0);
    assert(x.pCor[1] == 0);
    assert(x.pCor[2] == 0);
    y -= -y;
    assert(y.pCor[0] == 5);
    assert(y.pCor[1] == 5);
    assert(y.pCor[2] == 5);
    std::cout<<"OK"<<std::endl;
}
