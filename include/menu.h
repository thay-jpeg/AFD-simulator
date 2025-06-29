// Classe do objeto Menu

#ifndef MENU_H_
#define MENU_H_
#include "automato.h"

class Menu {

public: 

//construtor
Menu();

//destrutor
~Menu();

//método para executar o menu
void executar();

private:

Automato* m_automato; //ponteiro p/ automato

int vazio(Automato * m_automato) const;
void exibirOpcoes() const;
void carregarAutomato();
void imprimirGramatica() const;
void verificarPalavra() const;
void aguardarEntrada() const; //system("pause")

};

#endif //MENU_H