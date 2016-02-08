/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 * d'opérateur.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector x;
    Dvector y;
    assert(x == y);
    std::cout<<"OK"<<std::endl;
}
