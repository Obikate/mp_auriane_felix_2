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
    x = x*2.5;
    assert(x.pCor[0] == 6.25);
    assert(x.pCor[1] == 6.25);
    assert(x.pCor[2] == 6.25);
    std::cout<<"OK"<<std::endl;
}
