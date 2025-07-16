// Classe do Leitor de Automato

#ifndef LEITOR_AUTOMATO_H_
#define LEITOR_AUTOMATO_H_
#include <iostream>
#include <string>
#include <fstream>   //para arquivos
#include <sstream>   //para stringstream
#include <stdexcept> //para error log's
#include <algorithm> //para remove
#include "automato.h"

using namespace std;

class leitorAutomato
{

private:
public:
    static string limparString(string str, const string &prefixo, const string &sufixo);

    static Automato *lerArquivo(const string &nome);
};

#endif