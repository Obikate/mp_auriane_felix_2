/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur *= avec un réel.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x *= 2;
    assert(x.pCor[0] == 5);
    assert(x.pCor[1] == 5);
    assert(x.pCor[2] == 5);
    std::cout<<"OK"<<std::endl;
}
