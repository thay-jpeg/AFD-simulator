//Implementação

#include "../include/menu.h"
#include "../include/gerador_gramatica.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void geradorGramatica::gerar(const Automato &automato) {
   
    map<int, char> mapaEstadoSimbolo;
    char simboloAtual = 'A';

    set<int> estados = automato.getEstados();

    mapaEstadoSimbolo[0] = 'S'; 

    for (int estado : estados) {
        if (estado != 0) { //caso nao for o estado inicial
            mapaEstadoSimbolo[estado] = simboloAtual++;
        }
    }

    map<char, vector<string>> producoes;
    
    // Pega as transicoes e os estados finais do automato
    map<pair<int, char>, int> transicoes = automato.getTransicoes();
    set<int> estadosFinais = automato.getEstadosFinais();

    for (int estado : estados) {
        char simboloOrigem = mapaEstadoSimbolo[estado];

        for (auto const& [par, estadoDestino] : transicoes) {
            // par.first = estado de origem, par.second = simbolo do alfabeto
            if (par.first == estado) {
                char simboloDoAlfabeto = par.second;
                char simboloDestino = mapaEstadoSimbolo[estadoDestino];

                string regra;
                regra += simboloDoAlfabeto;
                regra += simboloDestino;
                producoes[simboloOrigem].push_back(regra);
            }
        }

        // add a producao da palavra vazia "@" se o estado for final
        if (estadosFinais.count(estado) > 0) {
            producoes[simboloOrigem].push_back("@");
        }
    }

    cout << "\n===========================================================" << endl;
    cout << "           GRAMATICA REGULAR EQUIVALENTE" << endl;
    cout << "===========================================================" << endl;

    if (producoes.count('S') > 0) {
        cout << "S -> ";
        for (size_t i = 0; i < producoes['S'].size(); ++i) {
            cout << producoes['S'][i] << (i == producoes['S'].size() - 1 ? "" : " | ");
        }
        cout << endl;
    }

    // Imprime as outras regras em ordem alfabetica
    for (auto const& [simbolo, regras] : producoes) {
        if (simbolo == 'S') continue; 

        cout << simbolo << " -> ";
        for (size_t i = 0; i < regras.size(); ++i) {
            cout << regras[i] << (i == regras.size() - 1 ? "" : " | ");
        }
        cout << endl;
    }
    cout << "===========================================================" << endl;
}