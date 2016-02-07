/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 *  d'affectation.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    Dvector y(5, -3.123);
    x = y;
    assert(x.size() == 5);
    assert(x.pCor[0] == -3.123);
    assert(x.pCor[1] == -3.123);
    assert(x.pCor[2] == -3.123);
    assert(x.pCor[3] == -3.123);
    assert(x.pCor[4] == -3.123);
    std::cout<<"OK"<<std::endl;
}
