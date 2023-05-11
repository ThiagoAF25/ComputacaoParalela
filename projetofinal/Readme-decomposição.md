Exercício 04 - Decomposição de tarefas

Luiz Octavio Tassinari Saraiva - 32030411

Thiago Aidar Figueiredo - 32144547

Yiou Wu - 32123213


Considere o algoritmo desenvolvido para o projeto final e responda às seguintes perguntas:

1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.

Supondo 2 processadores, foi definido o DAG abaixo


![image](https://github.com/ThiagoAF25/BagresDaParalela/assets/83554105/1ee506e1-46b4-46ca-887b-74b7349f7847)


As tarefas que compõem o caminho crítico seriam: 
Inicialização de variáveis → Criação de threads com omp_parallel → Inicialização de variáveis → Cálculo da soma parcial  de Euler para a thread atual → Adição da soma parcial à soma global com uma seção crítica → Limpeza de variáveis locais → Escrita do resultado → Limpeza de variáveis


2. Qual é o limite inferior do tempo de execução paralela para cada decomposição?

O limite inferior do tempo de execução é 8 atividades. Seguem o cálculos:
T1 = 12 ; T∞ = 8 ; P = 2

![imagem_2023-05-10_231256340](https://github.com/ThiagoAF25/BagresDaParalela/assets/83554105/f07aade1-3528-4796-8ad3-c3762d8782d4)


3. Quantos processadores são necessários para se conseguir o tempo mínimo de execução?

Para obter o tempo mínimo de execução do algoritmo seria necessário que o número de threads fosse igual ao número de processadores. 
Se o número de threads for maior há perda de desempenho. Com isso, a quantidade de processadores para conseguir o tempo mínimo de execução deve ser o máximo possível disponível no ambiente. 

4. Qual é o grau máximo de concorrência?

O grau máximo de concorrência do código é definido pela variável thread_count na Main(). Caso utilizemos 2 threads, o grau máximo de concorrência será 2.

5. Qual é o paralelismo médio?

O paralelismo médio dependerá da quantidade de threads geradas pela variável thread_count. Para cada thread a mais haverá um aumento no paralelismo médio de 0,5. Dessa forma, havendo 2 threads teremos paralelismo médio de 1,5 e para 3 threads um paralelismo médio de 2.
