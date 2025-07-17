// Classe do objeto Menu

#ifndef MENU_H_
#define MENU_H_
#include "automato.h"

class Menu
{

public:
    /**
     * @brief Construtor da classe Menu.
     * @pre Nenhuma.
     * @post Um objeto Menu é criado e o ponteiro interno `automato` é inicializado como nulo (`nullptr`).
     */
    Menu();

    /**
     * @brief Destrutor da classe Menu.
     * @pre Nenhuma.
     * @post A memória alocada para o `automato` carregado (se houver) é liberada. O objeto Menu é destruído.
     */
    ~Menu();

    /**
     * @brief Inicia e executa o loop principal do menu interativo.
     * @details Este método controla o fluxo principal do programa, exibindo opções,
     * capturando a entrada do usuário e acionando as funcionalidades correspondentes
     * até que a opção de sair (0) seja escolhida.
     * @pre Nenhuma.
     * @post O programa termina após o usuário selecionar a opção de saída.
     */
    void executar();

private:
    Automato *automato;

    /**
     * @brief Verifica se o ponteiro do autômato é nulo.
     * @param automato O ponteiro para o autômato a ser verificado.
     * @return Retorna 1 (verdadeiro) se o ponteiro for nulo, caso contrário retorna 0 (falso).
     * @pre Nenhuma.
     * @post Nenhuma mudança no estado do objeto.
     */
    int vazio(Automato *automato) const;

    /**
     * @brief Imprime o menu de opções no console.
     * @pre Nenhuma.
     * @post O menu de texto é exibido no console. Nenhuma mudança no estado do objeto.
     */
    void exibirOpcoes() const;

    /**
     * @brief Solicita o nome de um arquivo e carrega o autômato.
     * @pre Nenhuma.
     * @post Se um autômato já estava carregado, sua memória é liberada.
     * O ponteiro `automato` do menu é atualizado para o novo autômato carregado
     * ou para `nullptr` se a leitura do arquivo falhar. Uma mensagem de status é exibida.
     */
    void carregarAutomato();

    /**
     * @brief Imprime a gramática regular do autômato carregado.
     * @pre Um autômato deve estar carregado (ponteiro `automato` não pode ser nulo).
     * @post Se a pré-condição for atendida, a gramática é impressa no console.
     * Caso contrário, uma mensagem de erro é exibida. O estado do objeto não muda.
     */
    void imprimirGramatica() const;

    /**
     * @brief Solicita uma palavra e verifica se pertence à linguagem do autômato.
     * @pre Um autômato deve estar carregado (ponteiro `automato` não pode ser nulo).
     * @post Se a pré-condição for atendida, o resultado da verificação da palavra é
     * impresso no console. Caso contrário, uma mensagem de erro é exibida. O estado do objeto não muda.
     */
    void verificarPalavra() const;

    /**
     * @brief Pausa a execução e aguarda o usuário pressionar ENTER. (system("pause"))
     * @pre Nenhuma.
     * @post O programa continua somente após o usuário pressionar a tecla ENTER.
     */
    void aguardarEntrada() const;
};

#endif // MENU_H