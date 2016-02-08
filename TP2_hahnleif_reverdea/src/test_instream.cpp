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
    Dvector y(2);
    std::cin>>y;
    y.display(std::cout);
    std::ostream strout;
    std::istream strin;
    Dvector res(2);
    strout<<y;
    double tmp;
    tmp<<strout;
    res.display(std::cout);
    std::cout<<"OK"<<std::endl;
}
