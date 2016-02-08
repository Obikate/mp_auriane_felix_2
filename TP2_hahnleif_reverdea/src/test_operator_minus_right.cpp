/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur '-'.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 5);
    x = x - 2.5;
    assert(x.pCor[0] == 2.5);
    assert(x.pCor[1] == 2.5);
    assert(x.pCor[2] == 2.5);
    std::cout<<"OK"<<std::endl;
}
