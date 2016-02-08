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
    x.resize(3);
    assert(x.size() == 3);
    assert(x.pCor[0] == 2.5);
    assert(x.pCor[1] == 2.5);
    assert(x.pCor[2] == 2.5);
    std::cout<<"OK"<<std::endl;
}
