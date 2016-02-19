/**
 * @author Auriane, Felix.
 * @date 07/01/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 *  d'affectation.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    Dvector x(3, 2.5);
    x = x;
    assert(x.size() == 3);
    assert(x[0] == 2.5);
    assert(x[1] == 2.5);
    assert(x[2] == 2.5);
    std::cout<<"OK"<<std::endl;
}
