//Classe do Leitor de Automato

#ifndef LEITOR_AUTOMATO_H_
#define LEITOR_AUTOMATO_H_
#include <iostream>
#include <string>
#include "automato.h"

using namespace std;

class leitorAutomato
{

private:

public:
    static Automato *lerArquivo(const string &nome);

};

#endif