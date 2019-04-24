# Trabalho 1 - Computação de Alto Desempenho - UFRJ

Autores: Alexandre de Paiva Silva
         Pedro Wagner
         Raphael Oliveira Sathler de Souza

# Objetivo

O objetivo desse trabalho consiste em codar um algoritmo multiplicação de matrizes densas nas linguagens C e Fortran utilizando um loop de fors, e apresentar a diferença entre a multiplição linha x coluna e coluna x linha. Para tal, faz-se necessário aumentar o tamanho de n, onde n é o tamanho da matriz quadrada, e anotando então o tempo de execução do algoritmo, desconsiderando o tempo de inicialização das matrizes. Por fim, deve-se deliberar sobre a complexidade desse algoritmo e o tempo de execução dos programas, além de comparar as diferenças entre as linguagens.

# Programas

## C

Para executar o código em C, é preciso compilar primeiro e então,ao executar, passar como parâmetro o tamanho desejado da matriz quadrada:

**Compilando**
```
$ gcc -O3 -o c_matrix c_matrix.c 
```

**Executando**        
```
$ ./c_matrix {tamanho-da-matriz}
```

## Fortran

Para executar o código em Fortran, é preciso compilar primeiro e então, ao executar, passar como parâmetro o tamanho desejado da matriz quadrada:


**Compilando**
```
$  gfortran -O3 -mcmodel=large -o f_matrix f_matrix.f95
```

**Executando**        
```
$ ./f_matrix {tamanho-da-matriz}
```