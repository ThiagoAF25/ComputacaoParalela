Metodologia: Para realizar esse projeto, adotamos a abordagem na qual a recursão não está envolvida. Nosso código paralelo divide o problema em N partes, sendo que esse número é igual ao número de Threads estabelecido. Cada thread é responsável por calcular uma parte do N estipulado. Nós desenvolvemos uma forma de cada Thread calcular o fatorial e a divisão sem depender da outra thread. Apesar disso parecer óbvio num código paralelo, o ideal não seria calcular a mesma coisa duas vezes, porém por Euler depender de contas sucessivas não seria possível chegar a um valor intermediário sem passar pelo seu predecessor.
	
  
GMP:

Utilizamos a biblioteca GMP para iniciar as variáveis para os cálculos e estabelecer uma unidade de precisão que satisfizesse o desafio em questão. Isso se demonstrou necessário uma vez que o maior tipo primitivo disponível para o cálculos era Long Double, com 16 bytes de tamanho. Isso se mostrou muito insuficiente para alcançar uma precisão que ultrapassasse de 100 casas decimais no cálculo de Euler.
Essa função é usada para inicializar uma variável de precisão arbitrária (mpf_t) com uma precisão específica. A precisão é especificada como o número de bits que serão usados para representar o número em ponto flutuante. No caso do código fornecido, a precisão é definida como 6700000 bits.


A função mpf_set_ui permite atribuir um valor a partir de um inteiro sem sinal (unsigned int). Ela converte o valor inteiro em um número de ponto flutuante de precisão arbitrária e o armazena em uma variável mpf_t. No entato, se você deseja atribuir o valor de uma variável de ponto flutuante existente a outra variável mpf_t, você deve usar mpf_set.


A função mpf_div_ui realiza uma divisão do segundo parâmetro de tipo mpf_t por um terceiro parâmetro do tipo uint. O resultado é armazenado em uma variável do tipo mpf_t. Essa função foi utilizada pois utilizamos um valor inteiro para a divisão sucessiva. 


A função mpf_add é utilizada para a operação de soma entre variáveis de tipo mpf_t e armazenar o resultado em uma variável de tipo mpf_t.


OMP:


Utilizamos a biblioteca OMP para realizar a programação paralela em plataforma compartilhadas de memória, como CPUs multicores. Ela oferece um conjunto de diretivas de compilação, rotinas de biblioteca e variáveis de ambiente para facilitar o desenvolvimento de programas paralelos. 


Diretiva OpenMP ‘#pragma omp parallel num_threads(thread_count)’ cria um bloco paralelo com o número de threads especificado. A função 'thread Euler' será executada em paralelo pelas threads.


Região crítica(‘#   pragma omp critical’) garante que apenas uma thread por vez pode atualizar a variável 'global euler' de forma segura, a soma do valor local de ‘euler’ e adicionado ao valor global.





Execução Paralela:

![image](https://github.com/ThiagoAF25/BagresDaParalela/assets/83554105/63f181ac-8cd8-4472-ab00-3bbc12944b78)


Comando para build: !gcc -o paraleloNThreads.exe paraleloNThreads.c -lgmp -fopenmp





Execução Serial:

![image](https://github.com/ThiagoAF25/BagresDaParalela/assets/83554105/6c77c547-37af-4c6a-a873-8b489a09d7de)


Comando para build: !gcc -o serial.exe serial.c -lgmp



Paralelo =~ 250 segundos

Serial =~ 222 segundos


SpeedUp: 222/250 = 0.888




