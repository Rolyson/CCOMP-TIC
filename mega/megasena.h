#ifndef MEGASENA_H
#define MEGASENA_H

int solicitaValor(char enunciado[], int vl_min, int vl_max);
int** aposta(int linhas, int qd, int** matriz, int type); // type 1 = Aposta Manual, type = Surpresinha
void exibirApostaManual(int** matriz, int qm, int qd);
// int ordenar_array(int* lista, int tamanho);

#endif 