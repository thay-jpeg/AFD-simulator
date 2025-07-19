//Implementação

#include "../include/menu.h"
#include "../include/gerador_gramatica.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

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
void geradorGramatica::gerar(const Automato &automato) {
   
    // Mapear cada estado (int) para um símbolo não-terminal (char).
    // Este mapa servirá como uma "tabela de tradução" entre os números dos estados e os símbolos da gramática.
    map<int, char> mapaEstadoSimbolo;
    char simboloAtual = 'A'; // Começamos com 'A' para os estados não iniciais.

    // Pega todos os estados do autômato para poder iterar sobre eles.
    set<int> estados = automato.getEstados();

    // Por convenção, o estado inicial q0 sempre será mapeado para o símbolo 'S'.
    mapaEstadoSimbolo[0] = 'S'; 

    // Mapeia os outros estados para A, B, C... em ordem.
    for (int estado : estados) {
        if (estado != 0) { // Se não for o estado inicial...
            mapaEstadoSimbolo[estado] = simboloAtual++; // Associa o símbolo atual e o incrementa (A -> B -> C).
        }
    }

    // Montar as regras de produção para cada símbolo.
    // Usaremos um mapa onde a chave é o símbolo (ex: 'S') e o valor é um vetor de strings com suas produções (ex: {"aA", "bS"}).
    map<char, vector<string>> producoes;
    
    // Pega as transições e os estados finais do autômato para fácil acesso.
    map<pair<int, char>, int> transicoes = automato.getTransicoes();
    set<int> estadosFinais = automato.getEstadosFinais();

    // Itera sobre todos os estados para criar as regras de produção de cada um.
    for (int estado : estados) {
        char simboloOrigem = mapaEstadoSimbolo[estado];

        // Itera sobre todas as transições para encontrar as que partem do estado atual.
        for (auto const& [par, estadoDestino] : transicoes) {
            // par.first = estado de origem, par.second = simbolo do alfabeto.
            if (par.first == estado) {
                char simboloDoAlfabeto = par.second;
                char simboloDestino = mapaEstadoSimbolo[estadoDestino];

                // Constrói a parte direita da regra de produção (ex: "aB").
                string regra;
                regra += simboloDoAlfabeto;
                regra += simboloDestino;
                producoes[simboloOrigem].push_back(regra);
            }
        }

        // Adiciona a produção da palavra vazia "@" se o estado for final.
        if (estadosFinais.count(estado) > 0) {
            producoes[simboloOrigem].push_back("@");
        }
    }

    // Imprimir a gramática formatada para o usuário.
    cout << "\n===========================================================" << endl;
    cout << "           GRAMATICA REGULAR EQUIVALENTE" << endl;
    cout << "===========================================================" << endl;

    // Imprime a regra para 'S' primeiro, por convenção de gramáticas.
    if (producoes.count('S') > 0) {
        cout << "S -> ";
        for (size_t i = 0; i < producoes['S'].size(); ++i) {
            // Usa um operador ternário para não imprimir o separador "|" após a última produção.
            cout << producoes['S'][i] << (i == producoes['S'].size() - 1 ? "" : " | ");
        }
        cout << endl;
    }

    // Imprime as outras regras em ordem alfabética (garantido pela ordenação de chaves do std::map).
    for (auto const& [simbolo, regras] : producoes) {
        if (simbolo == 'S') continue; // Pula a regra 'S' pois já foi impressa.

        cout << simbolo << " -> ";
        for (size_t i = 0; i < regras.size(); ++i) {
            cout << regras[i] << (i == regras.size() - 1 ? "" : " | ");
        }
        cout << endl;
    }
    cout << "===========================================================" << endl;
}