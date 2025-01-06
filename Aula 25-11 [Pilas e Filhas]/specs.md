Slides: [https://www.canva.com/design/DAGXfZpChes/6kB7kFx2THERXFyU01Zhfg/edit?utm_content=DAGXfZpChes&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton]

Exercício 1: 
    - Desenvolva um programa em que uma pilha principal seja ordenada em ordem crescente (ou decrescente), utilizando apenas outra pilha auxiliar e operações básicas (push, pop, top). Não utilize estruturas adicionais como arrays ou listas.

Exercício 2:
    - Um estacionamento possui garagens organizadas como pilhas, onde cada uma comporta até N carros. Os clientes chegam em uma fila de espera para deixar seus veículos, informando o tempo estimado de permanência. Sua tarefa é desenvolver um sistema que:
    Atribua o carro a uma garagem com base no tempo estimado de saída, visando minimizar movimentações futuras.
    Reorganize os carros após M veículos serem adicionados, utilizando chofers para otimizar a disposição nas garagens.
    Dicas para Resolver:
    Pilha: Use para simular cada garagem, já que carros só podem sair pela entrada/saída (ordem LIFO).
    Fila: Armazene os carros enquanto aguardam serem designados a uma garagem.
    Reordenação: Crie uma função que, após M inserções, ajuste as pilhas para minimizar reposicionamentos futuros. Considere tempo estimado como critério principal.
