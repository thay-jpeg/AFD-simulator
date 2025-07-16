#ifndef AUTOMATO_H_
#define AUTOMATO_H_
#include <iostream>
#include <string>
#include <set> // p/ armazenar conjuntos, em ordem crescente e sem elementos duplicados
#include <map> // fará mapeamento de transições de cada estado, armazena pares de chave-valor
#include <utility>

using namespace std;
class Automato{
private:
    set<int> estados;
    set<char> alfabeto;
    map<pair<int, char>, int> transicoes; // mapeia (estado_atual, simbolo) -> estado_destino. ex: (q0, a) = q1
    int estadoInicial;
    set<int> estadosFinais;

    bool ehEstadoFinal(int estado) const;

public:
    Automato(
        const set<int> &estados,                     // p/ armazenar o conjunto dos numeros dos estados, ex: 1 de q1
        const set<char> &alfabeto,                   // para armazenar o alfabeto
        const map<pair<int, char>, int> &transicoes, // struct que agrupa a chave de numero do estado e o simbolo lido p/ retorna o valor (prox estado)
        const set<int> &estadosFinais                // p/ representar conjunto dos estados finais
    );

    // processa uma cadeia de entrada e determina se ela é aceita pelo autômato.
    bool processarCadeia(const string &cadeia);

    // getters
    const set<int> &getEstados() const;
    const set<int> &getEstadosFinais() const;
    const map<pair<int, char>, int> &getTransicoes() const;

    // destrutor
    ~Automato();
};

#endif // AUTOMATO_H