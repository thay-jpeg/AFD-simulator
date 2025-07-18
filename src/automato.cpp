#include "../include/automato.h"
#include <iostream>
#include <string>

#include "../include/automato.h"

/**
 * @brief Construtor do autômato.
 * 
 * @param estados Conjunto de estados.
 * @param alfabeto Alfabeto do autômato.
 * @param transicoes Mapa de transições.
 * @param estadosFinais Conjunto de estados finais.
 * 
 * @note O estado inicial é assumido como sendo sempre 0.
 */
Automato::Automato(
    const set<int> &estados,
    const set<char> &alfabeto,
    const map<pair<int, char>, int> &transicoes,
    const set<int> &estadosFinais)
    : estados(estados),
      alfabeto(alfabeto),
      transicoes(transicoes),
      estadoInicial(0),
      estadosFinais(estadosFinais)
{
}

/**
 * @brief Destrutor do autômato.
 */
Automato::~Automato() {}

/**
 * @brief Verifica se um estado é final.
 * 
 * @param estado Estado a ser verificado.
 * 
 * @return true se for estado final, false caso contrário.
 */

bool Automato::ehEstadoFinal(int estado) const { return estadosFinais.count(estado) > 0; }

/**
 * @brief Processa uma cadeia de entrada e informa se ela é aceita.
 * 
 * @param cadeia Cadeia a ser verificada. Use "@" para representar cadeia vazia.
 * 
 * @return true se for aceita pelo autômato, false caso contrário.
 */
bool Automato::processarCadeia(const string &cadeia)
{
    int estadoAtual = estadoInicial;

    if (cadeia == "@")
    {
        cout << "[" << "q" << estadoAtual << "]@" << endl;
        bool aceita = ehEstadoFinal(estadoAtual);
        cout << (aceita ? "ACEITA" : "REJEITA") << endl;
        return aceita;
    }

    for (size_t i = 0; i < cadeia.length(); i++)
    {
        cout << "[" << "q" << estadoAtual << "]" << cadeia.substr(i) << endl;
        char simbolo = cadeia[i];

        if (alfabeto.count(simbolo) == 0)
        {
            cout << "Simbolo '" << simbolo << "' nao pertence ao alfabeto!" << endl;
            cout << "REJEITA" << endl;
            return false;
        }

        auto it = transicoes.find({estadoAtual, simbolo});
        if (it == transicoes.end())
        {
            cout << "Nao ha transicao definida para (" << "q" << estadoAtual << "," << simbolo << ")" << endl;
            cout << "REJEITA" << endl;
            return false;
        }

        estadoAtual = it->second;
    }

    cout << "[" << "q" << estadoAtual << "]" << endl;

    bool aceita = ehEstadoFinal(estadoAtual);
    cout << (aceita ? "ACEITA" : "REJEITA") << endl;
    return aceita;
}


/**
 * @brief Retorna o conjunto de estados.
 */
const set<int> &Automato::getEstados() const
{
    return estados;
}

/**
 * @brief Retorna o conjunto de estados finais.
 */
const set<int> &Automato::getEstadosFinais() const
{
    return estadosFinais;
}

/**
 * @brief Retorna o mapa de transições.
 */
const map<pair<int, char>, int> &Automato::getTransicoes() const
{
    return transicoes;
}
