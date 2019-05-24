# Trabalho 2 - Computação de Alto Desempenho - UFRJ

Autores: Alexandre de Paiva Silva
         Pedro Wagner
         Raphael Oliveira Sathler de Souza

# Objetivo

O objetivo deste trabalho é paralelizar o produto matvec utilizando-se das diretrizes do OpenMP. Aqui neste documento serão relatadas as diversas tentativas e seus resultados.

# Programas

## C

Para executar o código em C, é preciso compilar primeiro e então, ao executar, passar como parâmetro o tamanho desejado da matriz quadrada:

**Compilando**
```
$ g++ -fopenmp -O3 -o c_matrix c_matrix.c -pthread
```

**Executando**        
```
$ ./c_matrix {tamanho-da-matriz}
```