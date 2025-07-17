<img src="./cabecalho.png"
style="width:6.37007in;height:1.12598in" />

**\#** **Simulador** **de** **Autômato** **Finito** **Determinístico** 

Trata-se de um simulador de autômato finito determinístico capaz de carregar o arquivo texto de um autômato, gerar a gramática regular equivalente e processar cadeia de símbolos correspondente às características do autômato carregado. O simulador foi implementado na linguagem C++, com interface de interação do usuário via *prompt* do sistema operacional.  

**\##** **Funcionalidades** **Implementadas** 

O sistema possui 4 (quatro) opções, sendo: 

> **1.** **Carregar** **arquivo:** 
>
> a\. Esta funcionalidade realiza o carregamento de informações de um autômato finito determinístico que estão armazenados dentro de um arquivo de texto *.txt* localizado na pasta *example* do simulador. O simulador faz a leitura da especificação do autômato conforme a sintaxe exemplificada na pré-condição do trabalho. Ele lê os dados e verifica se, dependendo da circunstância da ausência de algum dado necessário para o registro, exibirá mensagens como “*arquivo vazio ou faltando linha do alfabeto*”, “*faltando linha de estados*”, “*faltando linha de estados finais*” ou “*formato de transição inválido*” na tela. Caso não possuir nenhum arquivo com o nome declarado para a busca, informará que “*não foi possível abrir o arquivo*”. 
>
> b\. **Como usar:** você precisará informar o nome do arquivo texto exatamente como está registrado, com letras maiúsculas, minúsculas ou *underline* (\_), se existir, para o sistema puder acessá-lo. Você pode digitar o nome do arquivo com ou sem '*.txt*' no final, que a busca funcionará da mesma forma. 
>
> **2.** **Imprimir** **gramática:** 
>
> a\. Esta opção permite consultar a gramática regular equivalente do autômato finito determinístico lido no arquivo de texto. O simulador define o estado inicial com ‘*S’*, faz a contagem de quantos estados possui o autômato de *‘A’* até ‘*n’* quantidades e faz a verificação das transições e os estados finais. Ele adiciona a produção da palavra vazia (@) se for um estado final. Ao final do processamento,  ele  imprime  a  gramática  regular  equivalente  em  ordem alfabética, separando as transições com ‘|’.  
>
> b\. **Como usar:** carregue um autômato finito determinístico e selecione a opção no menu. 
>
> **3** **Verificar** **palavra:** 
>
> a\. Esta opção permite verificar se uma cadeia de símbolos é aceita ou rejeitada pelo autômato finito determinístico carregado do arquivo de texto. O simulador processa a palavra símbolo por símbolo verificando se ela existe no alfabeto do autômato e se existe uma transição equivalente definida para o estado e símbolo atual lido. Caso contrário, exibirá, respectivamente, as mensagens “*este símbolo não pertence ao alfabeto*” ou “*não há transição definida para o estado e símbolo atual*” na tela. Ao final, se a cadeia toda estiver lida e o simulador estiver num estado final, ele alegará que a palavra é aceita pelo autômato carregado. Se não estiver, exibirá “*rejeita*” após o processamento. 
>
> b\. **Como usar:** carregue um autômato finito determinístico, selecione a opção no menu e descreva a palavra que deseja verificar. 
>
> **0.** **Sair:** 
>
> a\. Sai do simulador. 
>
> b\. **Como usar:** apenas selecione a opção do menu. 
