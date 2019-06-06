#include <stdio.h>
#include <stdlib.h>

void mergesort(int *v, int n);
void sort(int *v, int *c, int i, int f);
void merge(int *v, int *c, int i, int m, int f);

int main() {
  int i,n;
  scanf("%d",&n);
  int v[n];
  for (i = 0; i < n; i++)
  {
  	scanf("%d",&v[i]);
  }

  mergesort(v, 8);

  for (i = 0; i < 8; i++) printf("%d ", v[i]);

  putchar('\n');

  return 0;
}


void mergesort(int *vetor, int tamanho) {
  int *vAux = malloc(sizeof(int) * tamanho);
  sort(vetor, vAux, 0, tamanho - 1);
  free(vAux);
}


void sort(int *vetor, int *vAux, int inicio, int fim) {
  if (inicio >= fim) return;

  int meio = (inicio + fim) / 2;

  sort(vetor, vAux, inicio, meio);
  sort(vetor, vAux, meio + 1, fim);

 
  if (vetor[meio] <= vetor[meio + 1]) return;

  merge(vetor, vAux, inicio, meio, fim);
}


void merge(int *vetor, int *vAux, int inicio, int meio, int fim) {
  int count, iv = inicio, ic = meio + 1;

  for (count = inicio; count <= fim; count++) vAux[count] = vetor[count];

  count = inicio;

  while (iv <= meio && ic <= fim) {

    if (vAux[iv] < vAux[ic]) vetor[count++] = vAux[iv++];
    else /* if (c[iv] > c[ic]) */ vetor[count++] = vAux[ic++];
  }

  while (iv <= meio) vetor[count++] = vAux[iv++];

  while (ic <= fim) vetor[count++] = vAux[ic++];
}