//Implementação

#include "../include/menu.h"
#include "../include/gerador_gramatica.h"
#include "../include/leitor_automato.h"
#include <iostream>
#include <string>
#include <limits> //limpar buffer cin

using namespace std;

Menu::Menu() : m_automato(nullptr) {}

Menu::~Menu()
{

    cout << "Liberando memoria de automato carregado..." << endl;
    delete m_automato;
}

int Menu::vazio(Automato *m_automato) const
{
    return (m_automato == nullptr);
}

void Menu::executar()
{

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
            imprimirGramatica();
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
            cout << "\nObrigado(a) por utilizar o simulador! Saindo..." << endl;
            break;
        }
        default:
            cout << "\nOpcao invalida, tente novamente!" << endl;
            break;
        }
    } while (opcao != 0);
}

void Menu::exibirOpcoes() const
{

    cout << string(50, '\n'); //limpar tela
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

    cout << "\nDigite o nome do arquivo .txt de definicao do automato: ";
    string nome;
    getline(cin, nome);

    // antes de carregar um novo, libera o antigo
    if (!vazio(m_automato))
    {
        delete m_automato;
        m_automato = nullptr;
    }

    m_automato = leitorAutomato::lerArquivo(nome);

    if (!vazio(m_automato))
    {
        cout << "Automato carregado com sucesso do arquivo '" << nome << ".txt!'" << endl;
    }
    else
    {
        cout << "ERRO: Nao foi possivel carregar o arquivo do automato." << endl;
    }
}

void Menu::imprimirGramatica() const
{
    if (vazio(m_automato))
    {
        cout << "\nERRO: Nenhum automato carregado. Por favor, carregue um automato primeiro." << endl;
        return;
    }

    geradorGramatica::gerar(*m_automato);
}

void Menu::verificarPalavra() const {
    
    if (vazio(m_automato))
    {
        cout << "\nERRO: Nenhum automato carregado. Por favor, carregue um automato primeiro." << endl;
        return;
    }

    cout << "\nDigite a palavra a ser verificada (use @ para palavra vazia):" << endl;
    string palavra;
    getline(cin, palavra);

    m_automato->processarCadeia(palavra);
}

void Menu::aguardarEntrada() const
{
    cout << "\nPressione ENTER para continuar...";
    cin.get();
}