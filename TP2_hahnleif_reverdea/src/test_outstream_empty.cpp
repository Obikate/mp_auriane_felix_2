/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 * d'opérateur.
 */ 

#include "Dvector.h"
#include <assert.h>
#include <sstream>

int main()
{
    Dvector x;
    std::stringstream str;
    str<<x;
    assert(str.str() == "Dvector: \n");
    std::cout<<"OK"<<std::endl;
}
