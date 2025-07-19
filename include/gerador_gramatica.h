//Classe do Gerador de Gramática

#ifndef GERADOR_GRAMATICA_H_
#define GERADOR_GRAMATICA_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "automato.h"

using namespace std;

/**
 * @brief Classe utilitária estática para gerar a gramática regular de um autômato.
 * @details Fornece um método estático para converter um AFD em sua gramática regular equivalente.
 * A classe não precisa ser instanciada, pois suas funcionalidades são acessadas diretamente.
 */
class geradorGramatica
{

private:

public:
    /**
     * @brief Gera e imprime no console a gramática regular equivalente a um autômato finito determinístico.
     * @details Este método estático converte um objeto Automato em sua representação de gramática regular.
     * A conversão segue duas regras principais:
     * 1. Para cada transição (qi, a) = qj, uma produção Xi -> aXj é criada.
     * 2. Para cada estado final qi, uma produção Xi -> @ (palavra vazia) é adicionada.
     * Os estados do autômato (q0, q1, q2...) são mapeados para símbolos não-terminais (S, A, B...).
     * @param automato Uma referência constante ao objeto Automato que será convertido.
     * @pre O objeto 'automato' deve ser um ponteiro válido, representando um AFD completamente inicializado.
     * @post A gramática regular equivalente é impressa na saída padrão (cout). O objeto 'automato' não é modificado.
     */
    static void gerar(const Automato &automato);

};

#endif