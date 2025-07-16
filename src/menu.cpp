// Implementação

#include "../include/menu.h"
// #include "../include/gerador_gramatica.h"
#include "../include/leitor_automato.h"
#include <iostream>
#include <string>
#include <limits> //limpar buffer cin

using namespace std;

Menu::Menu() : automato(nullptr) {}

Menu::~Menu()
{

    cout << "Liberando memoria de automato carregado..." << endl;
    delete automato;
}

int Menu::vazio(Automato *automato) const
{
    return (automato == nullptr);
}

void Menu::executar()
{

    // Linhas de teste de automatos por injeçao de informaçoes
    // set<char> alfabeto = {'a', 'b', 'c', '0', '1', '2'};
    // set<int> estados = {0, 1, 2, 3, 4, 5};
    // map<pair<int, char>, int> transicoes = {
    //     {{0, 'a'}, 1},
    //     {{1, 'a'}, 2},
    //     {{1, 'b'}, 1},
    //     {{1, '0'}, 4},
    //     {{2, 'c'}, 3},
    //     {{3, 'b'}, 2},
    //     {{3, '0'}, 5},
    //     {{4, '0'}, 2},
    //     {{4, '1'}, 5},
    //     {{5, '2'}, 4},
    // };
    // set<int> finais = {0,2, 5};

    // automato = new Automato(estados, alfabeto, transicoes, finais);

    int opcao;

    do
    {
        exibirOpcoes();
        cout << "\nDigite a opcao desejada:" << endl;
        cin >> opcao;

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpa buffer

        switch (opcao)
        {
        case 1:
        {
            carregarAutomato();
            aguardarEntrada();
            break;
        }
        case 2:
        {
            // imprimirGramatica();
            aguardarEntrada();
            break;
        }
        case 3:
        {
            verificarPalavra();
            aguardarEntrada();
            break;
        }
        case 0:
        {
            cout << "\nObrigado(a) por utilizar o simulador!" << endl;
            break;
        }
        default:
            cout << "\nOpcao invalida, tente novamente." << endl;
            break;
        }
    } while (opcao != 0);
}

void Menu::exibirOpcoes() const
{
    cout << endl;
    cout << "===========================================================" << endl;
    cout << "               AUTOMATO FINITO DETERMINISTICO          " << endl;
    cout << "===========================================================" << endl;
    cout << "|                                                         |" << endl;
    cout << "|\t1 - Carregar arquivo                              |" << endl;
    cout << "|\t2 - Imprimir gramatica                            |" << endl;
    cout << "|\t3 - Verificar palavra                             |" << endl;
    cout << "|\t0 - Sair                                          |" << endl;
    cout << "|                                                         |" << endl;
    cout << "===========================================================" << endl;
}

void Menu::carregarAutomato()
{

    cout << "\nDigite o nome do arquivo .txt de definicao do automato (deve estar na pasta 'example'): ";
    string nome;
    getline(cin, nome);
    cout << endl;

    // antes de carregar um novo, libera o antigo
    if (!vazio(automato))
    {
        delete automato;
        automato = nullptr;
    }

    automato = leitorAutomato::lerArquivo(nome);

    if (!vazio(automato))
    {
        cout << "Automato carregado com sucesso do arquivo '" << nome << "'!" << endl;
    }
}

// void Menu::imprimirGramatica() const
// {
//     if (vazio(automato))
//     {
//         cout << "\nERRO: Nenhum automato carregado. Por favor, carregue um automato primeiro." << endl;
//         return;
//     }

//     geradorGramatica::gerar(*automato);
// }

void Menu::verificarPalavra() const
{

    if (vazio(automato))
    {
        cout << "\nERRO: Nenhum automato carregado. Por favor, carregue um automato primeiro." << endl;
        return;
    }

    cout << "\nDigite a palavra a ser verificada (use @ para palavra vazia):" << endl;
    string palavra;
    getline(cin, palavra);
    cout << endl;

    automato->processarCadeia(palavra);
}

void Menu::aguardarEntrada() const
{
    cout << "\nPressione ENTER para continuar...";
    cin.get();
}