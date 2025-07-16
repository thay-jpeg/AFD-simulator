// Implementação

#include "../include/menu.h"
#include "../include/leitor_automato.h"
#include <iostream>
#include <string>

using namespace std;

string leitorAutomato::limparString(string str, const string &prefixo, const string &sufixo)
{

    size_t pos = str.find(prefixo);

    // remove o prefixo
    if (pos != string::npos)
        str.erase(pos, prefixo.length());

    pos = str.find(sufixo);

    // remove o sufixo
    if (pos != string::npos)
        str.erase(pos, sufixo.length());

    // remove espaço em branco
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}

Automato *leitorAutomato::lerArquivo(const string &nome)
{

    string nomeArquivo = "example/" + nome;

    // se nao tiver .txt no nome do arquivo, adiciona
    if (nomeArquivo.rfind(".txt") == string::npos) ///< no position
        nomeArquivo += ".txt";

    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open())
    {
        cout << "ERRO: Nao foi possivel abrir o arquivo '" << nomeArquivo << "'!" << endl;
        return nullptr;
    }

    set<int> estados;
    set<char> alfabeto;
    map<pair<int, char>, int> transicoes;
    set<int> estadosFinais;

    string linha;

    // para prevenir erros de segmentação por ausencia de entradas ou inesperadas
    try
    {
        if (getline(arquivo, linha))
        {
            string conteudo = limparString(linha, "alfabeto={", "}");

            stringstream ss_cursor(conteudo);
            char simbolo;

            while (ss_cursor >> simbolo)
            {

                alfabeto.insert(simbolo);

                if (ss_cursor.peek() == ',')
                    ss_cursor.ignore();
            }
        }
        else
            throw runtime_error("Arquivo vazio ou faltando linha do alfabeto.");

        if (getline(arquivo, linha))
        {
            string conteudo = limparString(linha, "estados={", "}");

            // remove organiza a string com todos os elementos !q para o inicio da string mantendo a ordem
            // e deixa os q no final da string. retorna um it para o começo desse "lixo"
            // erase apaga desde o inicio do it até o final da string
            conteudo.erase(remove(conteudo.begin(), conteudo.end(), 'q'), conteudo.end());

            stringstream ss_cursor(conteudo);
            int estado_num;

            while (ss_cursor >> estado_num)
            {
                estados.insert(estado_num);

                if (ss_cursor.peek() == ',')
                    ss_cursor.ignore();
            }
        }
        else
            throw runtime_error("Faltando linha de estados.");

        if (getline(arquivo, linha))
        {
            string conteudo = limparString(linha, "finais={", "}");

            conteudo.erase(remove(conteudo.begin(), conteudo.end(), 'q'), conteudo.end());

            stringstream ss_cursor(conteudo);
            int estadoFinal_num;

            while (ss_cursor >> estadoFinal_num)
            {

                estadosFinais.insert(estadoFinal_num);

                if (ss_cursor.peek() == ',')
                    ss_cursor.ignore();
            }
        }
        else
            throw runtime_error("Faltando linha de estados finais.");

        while (getline(arquivo, linha))
        {

            // pula linhas em branco
            if (linha.empty())
                continue;

            string limpa = limparString(linha, "(", ")");

            size_t pos_virgula = limpa.find(',');
            size_t pos_igual = limpa.find('=');

            if (pos_virgula == string::npos || pos_igual == string::npos)
                throw runtime_error("Formato de transicao invalido: " + linha);

            // calcula a extração na string do int de transicao a partir do indice 1, ou seja, apos o primeiro 'q'
            // e pega somente o caractere que denota o numero da transição pois apos ele tem a virgula
            string q_origem = limpa.substr(1, pos_virgula - 1);

            // apos a virgula, pega o simbulo de transicao
            char simbolo = limpa[pos_virgula + 1];

            // mesmo processo, calculando a extração na string do int de transição após o espaço em branco e o 'q'
            string q_destino = limpa.substr(pos_igual + 2);

            int origem = stoi(q_origem);
            int destino = stoi(q_destino);

            transicoes[{origem, simbolo}] = destino;
        }
    }
    catch (const exception &error) // pega qualquer alerta de erro
    {
        cerr << "ERRO CRITICO ao processar o arquivo: " << error.what() << endl;
        arquivo.close();
        return nullptr;
    }

    arquivo.close();

    return new Automato(estados, alfabeto, transicoes, estadosFinais);
}