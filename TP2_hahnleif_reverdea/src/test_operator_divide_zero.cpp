/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surchage
 * d'opérateur.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x = x/0;
    assert(x.pCor[0] == 1);
    assert(x.pCor[1] == 1);
    assert(x.pCor[2] == 1);
    std::cout<<"OK"<<std::endl;
}
