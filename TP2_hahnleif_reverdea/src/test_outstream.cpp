/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la surcharge
 * d'opérateur.
 */ 

#include "Dvector.hpp"
#include <assert.h>
#include <sstream>

int main()
{
    Dvector x(3, 2.5);
    std::stringstream str;
    str<<x;
    assert(str.str() == "Dvector: 2.5 2.5 2.5 \n");
    std::cout<<"OK"<<std::endl;
}
