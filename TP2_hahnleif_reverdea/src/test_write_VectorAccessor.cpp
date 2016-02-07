/**
 * @author Auriane, Felix.
 * @date 06/02/16.
 * @brief Classe de test vérifiant le bon fonctionnement de la méthode 
 * getVector.
 */ 

#include "Dvector.h"
#include <assert.h>

int main()
{
    Dvector v("tp1_test1.txt");
    assert(v.size() == 10);
    v[9] = 2;
    assert(v[9] == 2);
    std::cout<<"OK"<<std::endl;
}
