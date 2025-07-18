#ifndef AUTOMATO_H_
#define AUTOMATO_H_
#include <iostream>
#include <string>
#include <set> 
#include <map>
#include <utility>

using namespace std;

/**
 * @brief Classe que representa um Autômato Finito Determinístico (AFD).
 */
class Automato{
private:
    set<int> estados;
    set<char> alfabeto;
    map<pair<int, char>, int> transicoes;
    int estadoInicial;
    set<int> estadosFinais;

    /**
     * @brief Verifica se um estado é final.
     * 
     * @param estado Estado a ser verificado.
     * 
     * @return true se for estado final, false caso contrário.
     */
    bool ehEstadoFinal(int estado) const;

public:

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
    Automato(
        const set<int> &estados,                     // p/ armazenar o conjunto dos numeros dos estados, ex: 1 de q1
        const set<char> &alfabeto,                   // para armazenar o alfabeto
        const map<pair<int, char>, int> &transicoes, // struct que agrupa a chave de numero do estado e o simbolo lido p/ retorna o valor (prox estado)
        const set<int> &estadosFinais                // p/ representar conjunto dos estados finais
    );

    /**
     * @brief Processa uma cadeia de entrada e informa se ela é aceita.
     * 
     * @param cadeia Cadeia a ser verificada. Use "@" para representar cadeia vazia.
     * 
     * @return true se for aceita pelo autômato, false caso contrário.
     */
    bool processarCadeia(const string &cadeia);

    // getters
    /**
    * @brief Retorna o conjunto de estados.
    */
    const set<int> &getEstados() const; 

    /**
    * @brief Retorna o conjunto de estados finais.
    */
    const set<int> &getEstadosFinais() const;
    
    /**
    * @brief Retorna o mapa de transições.
    */
    const map<pair<int, char>, int> &getTransicoes() const;

    /**
     * @brief Destrutor do autômato.
     */
    ~Automato();
};

#endif // AUTOMATO_H