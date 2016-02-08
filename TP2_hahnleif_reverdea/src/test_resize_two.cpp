/**
 * @author Auriane, Felix.
 * @date 08/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la méthode
 * resize.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x.resize(5);
    assert(x.size() == 5);
    assert(x.pCor[0] == 2.5);
    assert(x.pCor[1] == 2.5);
    assert(x.pCor[2] == 2.5);
    assert(x.pCor[3] == 0);
    assert(x.pCor[4] == 0);
    std::cout<<"OK"<<std::endl;
}
