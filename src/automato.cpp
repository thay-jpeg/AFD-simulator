#include "../include/automato.h"
#include <iostream>
#include <string>

#include "../include/automato.h"

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

Automato::~Automato() {}

bool Automato::ehEstadoFinal(int estado) const { return estadosFinais.count(estado) > 0; }

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

const set<int> &Automato::getEstados() const
{
    return estados;
}

const set<int> &Automato::getEstadosFinais() const
{
    return estadosFinais;
}

const map<pair<int, char>, int> &Automato::getTransicoes() const
{
    return transicoes;
}
