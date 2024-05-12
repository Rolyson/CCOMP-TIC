#ifndef MEGASENA_H
#define MEGASENA_H

int solicitaValor(char enunciado[], int vl_min, int vl_max);
int** aposta(int linhas, int qd, int** matriz, int type); // type 1 = Aposta Manual, type = Surpresinha
int revisarAposta(int QT, int QM, int QS, int QD, int** apostasManuais, int** apostasSurpresinhas);
int sorteio(int** apostasManuais, int** apostasSurpresinhas, int QD, int QM, int QS); 
// int ordenar_array(int* lista, int tamanho);

#endif 