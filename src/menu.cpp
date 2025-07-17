// Implementação

#include "../include/menu.h"
#include "../include/gerador_gramatica.h"
#include "../include/leitor_automato.h"
#include <iostream>
#include <string>
#include <limits> //limpar buffer cin

using namespace std;

/**
 * @brief Construtor da classe Menu.
 * @pre Nenhuma.
 * @post Um objeto Menu é criado e o ponteiro interno `automato` é inicializado como nulo (`nullptr`).
 */
Menu::Menu() : automato(nullptr) {}

/**
 * @brief Destrutor da classe Menu.
 * @pre Nenhuma.
 * @post A memória alocada para o `automato` carregado (se houver) é liberada. O objeto Menu é destruído.
 */
Menu::~Menu()
{

    cout << "Liberando memoria de automato carregado..." << endl;
    delete automato;
}

/**
 * @brief Verifica se o ponteiro do autômato é nulo.
 * @param automato O ponteiro para o autômato a ser verificado.
 * @return Retorna 1 (verdadeiro) se o ponteiro for nulo, caso contrário retorna 0 (falso).
 * @pre Nenhuma.
 * @post Nenhuma mudança no estado do objeto.
 */
int Menu::vazio(Automato *automato) const
{
    return (automato == nullptr);
}

/**
 * @brief Inicia e executa o loop principal do menu interativo.
 * @details Este método controla o fluxo principal do programa, exibindo opções,
 * capturando a entrada do usuário e acionando as funcionalidades correspondentes
 * até que a opção de sair (0) seja escolhida.
 * @pre Nenhuma.
 * @post O programa termina após o usuário selecionar a opção de saída.
 */
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
            cout << "\nObrigado(a) por utilizar o simulador!" << endl;
            break;
        }
        default:
            cout << "\nOpcao invalida, tente novamente." << endl;
            break;
        }
    } while (opcao != 0);
}

/**
 * @brief Imprime o menu de opções no console.
 * @pre Nenhuma.
 * @post O menu de texto é exibido no console. Nenhuma mudança no estado do objeto.
 */
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

/**
 * @brief Solicita o nome de um arquivo e carrega o autômato.
 * @pre Nenhuma.
 * @post Se um autômato já estava carregado, sua memória é liberada.
 * O ponteiro `automato` do menu é atualizado para o novo autômato carregado
 * ou para `nullptr` se a leitura do arquivo falhar. Uma mensagem de status é exibida.
 */
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

/**
 * @brief Imprime a gramática regular do autômato carregado.
 * @pre Um autômato deve estar carregado (ponteiro `automato` não pode ser nulo).
 * @post Se a pré-condição for atendida, a gramática é impressa no console.
 * Caso contrário, uma mensagem de erro é exibida. O estado do objeto não muda.
 */
void Menu::imprimirGramatica() const
{
    if (vazio(automato))
    {
        cout << "\nERRO: Nenhum automato carregado. Por favor, carregue um automato primeiro." << endl;
        return;
    }

    geradorGramatica::gerar(*automato);
}

/**
 * @brief Solicita uma palavra e verifica se pertence à linguagem do autômato.
 * @pre Um autômato deve estar carregado (ponteiro `automato` não pode ser nulo).
 * @post Se a pré-condição for atendida, o resultado da verificação da palavra é
 * impresso no console. Caso contrário, uma mensagem de erro é exibida. O estado do objeto não muda.
 */
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

/**
 * @brief Pausa a execução e aguarda o usuário pressionar ENTER. (system("pause"))
 * @pre Nenhuma.
 * @post O programa continua somente após o usuário pressionar a tecla ENTER.
 */
void Menu::aguardarEntrada() const
{
    cout << "\nPressione ENTER para continuar...";
    cin.get();
}