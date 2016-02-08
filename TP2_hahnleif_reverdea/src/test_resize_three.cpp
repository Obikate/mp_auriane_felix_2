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
    x.resize(0);
    assert(x.size() == 0);
    std::cout<<"OK"<<std::endl;
}
