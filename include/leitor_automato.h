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
    /**
     * @brief Limpa uma string removendo prefixo, sufixo e todos os espaços em branco.
     *
     * @param str A string de entrada a ser processada.
     * @param prefixo O prefixo a ser removido (se encontrado).
     * @param sufixo O sufixo a ser removido (se encontrado).
     *
     * @pre Nenhuma pré-condição estrita. A função lida com strings que não contenham o prefixo, sufixo ou espaços.
     * @post A string retornada não conterá a primeira ocorrência do prefixo e sufixo especificados e estará livre de todos os caracteres de espaço.
     *
     * @return Uma nova string com as modificações aplicadas.
     */
    static string limparString(string str, const string &prefixo, const string &sufixo);

    /**
     * @brief Lê um arquivo de texto que descreve um autômato finito e cria um objeto Automato.
     *
     * @param nome O nome do arquivo a ser lido. O caminho "example/" será pré-fixado e a extensão ".txt" será adicionada se não estiver presente.
     *
     * @pre
     * 1. O arquivo especificado por `nome` deve existir no diretório "example/".
     * 2. O conteúdo do arquivo deve seguir um formato estrito:
     * - Linha 1: Definição do alfabeto. Ex: "alfabeto={a,b,c}"
     * - Linha 2: Definição dos estados. Ex: "estados={q0,q1,q2}"
     * - Linha 3: Definição dos estados finais. Ex: "finais={q2}"
     * - Linhas subsequentes: Definições de transições. Ex: "(q0,a)=q1"
     *
     * @post
     * 1. Se a leitura e a análise do arquivo forem bem-sucedidas, um objeto `Automato` é alocado na memória heap e seu ponteiro é retornado.
     * 2. Se o arquivo não puder ser aberto ou contiver erros de formatação, uma mensagem de erro será impressa no console (`cout` ou `cerr`) e a função retornará `nullptr`.
     *
     * @return Um ponteiro para um novo objeto `Automato` em caso de sucesso, ou `nullptr` em caso de falha.
     */
    static Automato *lerArquivo(const string &nome);
};

#endif