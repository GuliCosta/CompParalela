Gustavo Fernandes Costa Tia:32161093

Comando para executar

gcc -o nome_executável nome_programa.c -lgmp


Como resolveram o problema: descrição simples do algoritmo e estratégia de paralelismo adotada:
R:A estratégia utilizada foi utilizar OpenMP para dividir a carga do trabalho.


Considerações sobre a estratégia de paralelismo adotada e como isso auxiliou na escala do problema. 
R:A estratégia de paralelismo adotada permite que várias threads calculem partes diferentes da série, reduzindo o tempo total de execução.
R:A utilização de uma redução em euler garante que as threads possam realizar suas somas parciais sem conflitos.
