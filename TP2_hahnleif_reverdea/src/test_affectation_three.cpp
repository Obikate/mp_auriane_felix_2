/**
 * @author Auriane, Felix.
 * @date 07/02/16.
 * @brief Classe de test répondant à la question 2.5 de l'énoncé.
 * Copie de plusieurs millions d'éléments.
 */ 

#include "Dvector.hpp"
#include <assert.h>

int main()
{
    int sizeOfX = 1000000000;
    Dvector x(sizeOfX);
    x.fillRandomly();
    Dvector y;
    y = x;
    assert(y.size() == sizeOfX);
    for(int i=0; i<sizeOfX; i++)
        assert(x[i] == y[i]);
    std::cout<<"OK"<<std::endl;
}
