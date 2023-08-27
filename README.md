O seguinte código tem o fito de realizar operações de busca e inserção implementadas em templates baseadas nas chaves de busca por pessoa: CPF, nome e data de nascimento. Tais operações tem 
complexidade temporal logarítmica O(lg n), para isso utiliza-se a estrutura de dado de uma árvore binária de busca "auto-balanceável", AVL, baseado nas informações que foram lidas do arquivo CSV("COMMA SEPARATED FILE"), "data.csv". As operações de busca na dita árvore são diferenciadas pelos seguintes parâmetros:

CPF:  recebe a CPF na entrada e retorna as informações do CPF pesquisado.
      mensagem de erro --> (caso não encontrado).

Nome: recebe um substring na entrada, e retorna todos os nomes que possuem pelo menos aquela substring.
        mensagem de erro --> (caso não houver correspondências).

Data: recebe duas datas e retorna todas as informações das pessoas presentes nesse intervalo.
       mensagem de erro --> (caso os intervalos não sejam válidos).



As classes PessoaPorCPF, PessoaPorNome, PessoaPorDataDeNascimento são subinstâncias da classe pai,
chamada Pessoa, utilizada ao o intento de sobrecarregar os operadores de comparação de modo díspar.

Os diferentes templates para cada subinstância de Pessoa foram implementados com as respectivas operações de comparação sobrecarregadas susoditas.


A seguir, eis o modo de compilação padrão ao código:

g++ *.cpp -o main -std=c++17 && ./main






