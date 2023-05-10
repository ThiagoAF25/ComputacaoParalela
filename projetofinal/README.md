<h2>Projeto V1- Serial</h2>
<h3>Aproximação de Euler obtida:</h3>
  O código serial faz o cálculo preciso de Euler com 10.000 dígitos.

<h3>Instalação do MPFR:</h3>

```
sudo apt-get install libmpfr-dev
```
<h3>Comando de build:</h3>

```
gcc -o serial.exe serial.c -lgmp
```
<h3>Tempo de execução serial</h3>

```
real    0m0.258s
```
```
user    0m0.258s
```
```
sys     0m0.000s
```

<h2> Projeto V2 -Paralelo </h2>
<h3>Aproximação de Euler obtida:</h3>
  Os códigos serial e paralelos fazem o cálculo preciso de Euler com 2.000.000 dígitos. O tempo de de execução para este resultado está envolta de 4 minutos.O código serial da entrega anterior foi otimizado, reduzindo a quantidade de varíaveis. Os resultados dos arquivos executáveis são impressos em arquivos txt. 
  
```
serial.exe-> ResultadosSerial.txt 
```

```
paralelo2Threads.exe-> Resultados2Threads.txt
```

```
paraleloNThreads.exe-> ResultadosNThreads.txt
```

 <h3>Comando de build dos códigos parelelos:</h3>

```
gcc -o paralelo2Threads.exe paralelo2Threads.c -lgmp -fopenmp
```

```
gcc -o paraleloNThreads.exe paraleloNThreads.c -lgmp -fopenmp
```

Os resultados podem ser comparados com o número de euler obtido em <https://apod.nasa.gov/htmltest/gifcity/e.2mil> utilizando o executável CompararRes.exe. Em sua execução, basta escrever: "nome_do_arquivo.txt"

 <h3>Comando de build de para comparar arquivos txt:</h3>
 
```
gcc -o CompararRes.exe CompararRes.c
```
OBSERVAÇÃO: Foi utilizada a máquina t3nano que possui 2 processadores para a execução, logo os resultados de 4 e 8 threads, por as threads terem de perder tempo tentanto acessar o processador, os resultados pioram. 

<h3> SpeedUp com 2 threads </h3>

```
SpeedUp: 0,966543
```

<h3> SpeedUp com 4 threads </h3>

```
SpeedUp: 0,677529
```

<h3> SpeedUp com 8 threads </h3>

```
SpeedUp: 0,406142
```

