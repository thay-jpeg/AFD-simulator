//Classe do Gerador de Gramática

#ifndef GERADOR_GRAMATICA_H_
#define GERADOR_GRAMATICA_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "automato.h"

using namespace std;

class geradorGramatica
{

private:

public:

    static void gerar(const Automato &automato);

};

#endif