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
