#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include"funcoes_de_ordenacao.h"

void criar_Arquivo(int *vet100, int *vet1000, int *vet10000, int *vet100000, int *libera){
    int i;

                FILE *arquivo_100;
                arquivo_100 = fopen("arquivo_100.txt", "w");
                for(i=0; i<100; i++){
                    fprintf (arquivo_100, "%d\t", ( rand() % 101 ));
                }
                fclose(arquivo_100);
                arquivo_100 = fopen("arquivo_100.txt", "r");
                for (i=0; i<100; i++){
                    fscanf(arquivo_100, "%d", &vet100[i]);
                }
                fclose(arquivo_100);


                FILE *arquivo_1000;
                arquivo_1000 = fopen("arquivo_1000.txt", "w");
                for(i=0; i<1000; i++){
                    fprintf(arquivo_1000, "%d\t",( rand() % 101 ));
                }
                fclose(arquivo_1000);
                arquivo_1000 = fopen("arquivo_1000.txt", "r");
                for (i=0; i<1000; i++){
                    fscanf(arquivo_1000, "%d", &vet1000[i]);
                }
                fclose(arquivo_1000);


                FILE *arquivo_10000;
                arquivo_10000 = fopen("arquivo_10000.txt", "w");
                for(i=0; i< 10000; i++){
                    fprintf(arquivo_10000,"%d\t", ( rand() % 101 ));
                }
                fclose(arquivo_10000);
                arquivo_10000 = fopen("arquivo_10000.txt", "r");
                for (i=0; i<10000; i++){
                    fscanf(arquivo_10000, "%d", &vet10000[i]);
                }
                fclose(arquivo_10000);


                FILE *arquivo_100000;
                arquivo_100000 = fopen("arquivo_100000.txt", "w");
                for(i=0; i<100000; i++){
                    fprintf(arquivo_100000,"%d\t", ( rand() % 101 ));
                }
                fclose(arquivo_100000);
                arquivo_100000 = fopen("arquivo_100000.txt", "r");
                for (i=0; i<100000; i++){
                    fscanf(arquivo_100000, "%d", &vet100000[i]);
                }
                fclose(arquivo_100000);

                *libera = 1;
}


void selection_Sort(int *vet, int tam, double *tempo, int *comparar, int *troca){
    clock_t start_time;
    start_time = clock();

    *comparar = 0;
    *troca = 0;

    int i, j, menor, aux;
    for (i = 0; i < tam-1; i++){
        menor = i;
        for (j = i+1; j < tam; j++){
            if(vet[j] < vet[menor]){
                menor = j;
            }
            *comparar+=1;
        }
        if (i != menor){
            aux = vet[i];
            vet[i] = vet[menor];
            vet[menor] = aux;
            *troca+=1;
        }
    }

    *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}

void insertion_Sort(int *vet, int tam, double *tempo,unsigned long long int *compara, int *troca){
    clock_t start_time;
    start_time = clock();
    *compara = 0;
    *troca = 0;

    int i, j, aux;

    for(i = 1; i < tam; i++){
        aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]); j--){
            *compara+=1;
            vet[j] = vet[j - 1];
        }
        vet[j] = aux;
        *troca+=1;
    }

    *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}

void bubble_Sort(int vet[], int tam, double *tempo, int *comparar, unsigned long long int *troca){
    clock_t start_time;
    start_time = clock();

    int i, j, aux;

    for (i = 0 ; i < ( tam - 1 ); i++){
        for (j = 0 ; j < tam - i - 1; j++){
            if (vet[j] > vet[j+1]){
                /* Swapping */
                aux         = vet[j];
                vet[j]   = vet[j+1];
                vet[j+1] = aux;
                *troca+=1;
             }
             *comparar+=1;
         }
     }

     *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}

void radix_Sort(int vet[], int tamanho, double *tempo) {
    clock_t start_time;
    start_time = clock();

    int *b;
    int maior = vet[0];
    int i, exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vet[i] > maior)
            maior = vet[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
        for (i = 0; i < tamanho; i++)
            bucket[(vet[i] / exp) % 10]++;
            for (i = 1; i < 10; i++)
                bucket[i] += bucket[i - 1];
                for (i = tamanho - 1; i >= 0; i--)
                    b[--bucket[(vet[i] / exp) % 10]] = vet[i];
                    for (i = 0; i < tamanho; i++)
                        vet[i] = b[i];
                        exp *= 10;
    }

    free(b);

    *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}

void quick_Sort(int *vet, int inicio, int fim, double *tempo, int *comparar, int *troca){
    clock_t start_time;
    start_time = clock();

    int particiona(int *vet, int inicio, int fim){
        int esq, dir, pivo, aux;
        esq = inicio;
        dir = fim;
        pivo = vet[inicio];

        while(esq < dir){
                *comparar+=1;
            while (vet[esq] <= pivo){
                *comparar+=1;
                esq++;
            }
            while (vet[dir] > pivo){
                *comparar+=1;
                dir--;
            }
            if (esq < dir){
                *troca+=1;
                aux = vet[esq];
                vet[esq] = vet[dir];
                vet[dir] = aux;
            }
        }
        vet[inicio] = vet[dir];
        vet[dir] = pivo;

        return dir;
    }

    int pivo;
        if(fim > inicio){
            *comparar+=1;
            pivo = particiona(vet, inicio, fim);
            quick_Sort(vet, inicio, pivo-1, tempo, comparar, troca);
            quick_Sort(vet, pivo+1, fim, tempo, comparar, troca);
        }

    *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}

void merge_Sort (int *vet, int inicio, int fim, double *tempo, int *comparar, int *troca){
    clock_t start_time;
    start_time = clock();

    void merge(int *vet, int inicio, int meio, int fim){
        int *aux, p1, p2, tam, i, j, k;
        int fim1 = 1, fim2 = 1;
        tam = fim-inicio+1;
        p1 = inicio;
        p2 = meio +1;

        aux = (int *) malloc(tam*sizeof(int));

        for (i = 0; i < tam; i++){
            if(fim1 && fim2){
                    *comparar+=1;
                    //*troca+=1;
                if(vet[p1] < vet[p2]){
                    aux[i] = vet[p1++];
                }
                else{
                    aux[i] = vet[p2++];
                }
                if(p1 > meio)
                    fim1 = 0;
                if(p2 > fim)
                    fim2 = 0;
            }
            else{
                    *troca+=1;
                if(fim1){
                    aux[i] = vet[p1++];
                }
                else{

                    aux[i] = vet[p2++];
                }
            }
        }
        for(j = 0, k = inicio; j < tam; j++, k++){
            vet[k] = aux[j];
        }

        free(aux);
    }

    int meio;
    if (inicio < fim){
        meio = (inicio + fim)/2;
        merge_Sort(vet, inicio, meio, tempo, comparar, troca);
        merge_Sort(vet, meio+1, fim, tempo, comparar, troca);
        merge(vet, inicio, meio, fim);
    }

    *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}

void heap_Sort(int *vet, int inicio, int tam, double *tempo, int *comparar, int *troca){
    clock_t start_time;
    start_time = clock();

    void criaHeap(int *vet, int i, int f){
        int aux = vet[i];
        int j = i*2+1;
        while (j <= f){
            if (j < f){
                *comparar+=1;
                if (vet[j] < vet[j + 1]){
                    j++;
                }
            }
            *comparar+=1;
            if(aux < vet[j]){
                *troca+=1;
                vet[i] = vet[j];
                i = j;
                j = 2 * i + 1;
            }
            else{
                j = f + 1;
            }
        }
        vet[i] = aux;
    }

        int i, aux;

        for (i = (tam-1)/2; i >= 0; i--){
            criaHeap(vet, i, tam-1);
        }

        for (i = tam-1; i >= 1; i--){
            *troca+=1;
            aux = vet[0];
            vet[0] = vet[i];
            vet[i] = aux;
            criaHeap(vet, 0 , i-1);
        }

        *tempo = ((double)clock() - start_time) / (double)CLOCKS_PER_SEC;
}


void ordena(int *vet100, int *vet1000, int *vet10000, int *vet100000, int *libera_ordena){
    int i;

                        FILE *arquivo100_Ordenado;
                        arquivo100_Ordenado = fopen("arquivo100_Ordenado.txt", "w");

                        for (i = 0; i < 100; i++){
                            fprintf(arquivo100_Ordenado, "%d\t", vet100[i]);
                        }
                        fclose(arquivo100_Ordenado);


                        FILE *arquivo1000_Ordenado;
                        arquivo1000_Ordenado = fopen("arquivo1000_Ordenado.txt", "w");
                        for (i = 0; i < 1000; i++){
                            fprintf(arquivo1000_Ordenado, "%d\t", vet1000[i]);
                        }
                        fclose(arquivo1000_Ordenado);


                        FILE *arquivo10000_Ordenado;
                        arquivo10000_Ordenado = fopen("arquivo10000_Ordenado.txt", "w");
                        for (i = 0; i < 10000; i++){
                            fprintf(arquivo10000_Ordenado, "%d\t", vet10000[i]);
                        }
                        fclose(arquivo10000_Ordenado);


                        FILE *arquivo100000_Ordenado;
                        arquivo100000_Ordenado = fopen("arquivo100000_Ordenado.txt", "w");
                        for (i = 0; i < 100000; i++){
                            fprintf(arquivo100000_Ordenado, "%d\t", vet100000[i]);
                        }
                        fclose(arquivo100000_Ordenado);

                        *libera_ordena = 1;
}

