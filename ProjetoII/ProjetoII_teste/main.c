#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include "funcoes_de_ordenacao.h"
#include "funcoes_de_busca.h"

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao,x=0, troca=0, comparar=0;
    unsigned long long int compara=0, trocar=0;
    int vet100[100], vet1000[1000], vet10000[10000], vet100000[100000];
    srand(time(NULL));
    int libera = 0, libera_ordena = 0;
    double tempo;

    do{
        system("cls");
        printf("\t_____________________________________________________\n");
        printf(" \n\t\t\tORDENAÇÃO DE ARQUIVOS\n\n");
        printf("\t_____________________________________________________\n");
        printf("\n 1 - CRIAR ARQUIVOS DE 100, 1000, 10000 E 100000\n\n ");
        printf("2 - ORDENAR ARQUIVOS\n\n ");
        printf("3 - BUSCAR ARQUIVO\n\n ");
        printf("4 - SAIR\n\n");

        printf("\nESCOLHA A OPERAÇÃO: ");
        scanf("%d", &x);

        switch (x){
        case 1:{

            criar_Arquivo(vet100, vet1000, vet10000, vet100000, &libera);
            printf("\n\t_______________________________________________________\n");
            printf("\n\t\t\tCLIQUE ENTER PARA CONFIRMAR\n");
            printf("\t_______________________________________________________\n");


            getch();
            break;
        }

        case 2:{
            if (libera == 0){
                system("cls");
                printf("\n\n\n\n\n\n\n\n\t\t_________________________________________________________\n");
                printf("\n\t\t\t    CRIE O ARQUIVO PRIMEIRO!\n");
                printf("\t\t_________________________________________________________\n");

                Sleep(2000);
                break;
            }
            system("cls");
            do{

                printf("\t_____________________________________________________________\n");
                printf("\t\t\t\tORDENAR ARQUIVOS\n");
                printf("\t_____________________________________________________________\n");

                printf ("\n\n\t-Tamanho do arquivo");
                printf("\n\t-Tempo de execução");
                printf("\n\t-Trocas Realizadas");
                printf("\n\t-Comparações realizadas");
                printf("\n\t____________________________________________________________\n");

                printf("\n\n\t\t1 - SELECTION SORT\n\t\t");
                printf("2 - INSERTION SORT\n\t\t");
                printf("3 - BUBBLE SORT\n\t\t");
                printf("4 - RADIX SORT\n\t\t");
                printf("5 - QUICK SORT\n\t\t");
                printf("6 - MERGE SORT\n\t\t");
                printf("7 - HEAP SORT\n\t\t");
                printf("8 - VOLTAR\n");

                printf("Opção: ");

                setbuf(stdin,NULL);
                scanf("%d",&opcao);

                switch(opcao){



                    case 1:{
                        system("cls");
                        selection_Sort(vet100, 100, &tempo, &comparar, &troca);
                        printf("\n\t\t__________________SELECTION SORT___________________\n\n");
                        printf("\n\t\t____________________VETOR DE 100___________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);


                        selection_Sort(vet1000, 1000, &tempo, &comparar, &troca);
                        printf("\n\t\t____________________VETOR DE 1.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);


                        selection_Sort(vet10000, 10000, &tempo, &comparar, &troca);
                        printf("\n\t\t____________________VETOR DE 10.000________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        selection_Sort(vet100000, 100000, &tempo, &comparar, &troca);
                        printf("\n\t\t___________________VETOR DE 100.000________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);
                        getch();

                        ordena(vet100, vet1000, vet10000, vet100000, &libera_ordena);

                        break;
                    }
                    case 2:{
                        system("cls");
                        insertion_Sort(vet100, 100, &tempo, &compara, &troca);
                        printf("\n\t\t__________________INSERTION SORT___________________\n\n");
                        printf("\n\t\t____________________VETOR DE 100___________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",compara);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        insertion_Sort(vet1000, 1000, &tempo, &compara, &troca);
                        printf("\n\t\t____________________VETOR DE 1.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",compara);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);


                        insertion_Sort(vet10000, 10000, &tempo, &compara, &troca);
                        printf("\n\t\t___________________VETOR DE 10.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",compara);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        insertion_Sort(vet100000, 100000, &tempo, &compara, &troca);

                        printf("\n\t\t__________________VETOR DE 100.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",troca);
                        printf("\t\t\tComparações: %d\n",compara);
                        printf("\t\t\tTempo de Execução: %lf\n",tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);
                        getch();

                        ordena(vet100, vet1000, vet10000, vet100000, &libera_ordena);

                        break;
                    }

                    case 3:{
                        system("cls");

                        bubble_Sort(vet100, 100, &tempo, &comparar, &trocar);
                        printf("\n\t\t____________________BUBBLE SORT____________________\n\n");
                        printf("\n\t\t____________________VETOR DE 100___________________\n");
                        printf("\t\t\tTrocas: %d\n",trocar);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        bubble_Sort(vet1000, 1000, &tempo, &comparar, &trocar);
                        printf("\n\t\t____________________VETOR DE 1.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",trocar);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        bubble_Sort(vet10000, 10000, &tempo, &comparar, &trocar);
                        printf("\n\t\t___________________VETOR DE 10.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",trocar);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        bubble_Sort(vet100000, 100000, &tempo, &comparar, &trocar);
                        printf("\n\t\t__________________VETOR DE 100.000_________________\n");
                        printf("\t\t\tTrocas: %d\n",trocar);
                        printf("\t\t\tComparações: %d\n",comparar);
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);
                        getch();

                        ordena(vet100, vet1000, vet10000, vet100000, &libera_ordena);

                        break;
                    }

                    case 4:{
                        system("cls");

                        radix_Sort(vet100, 100, &tempo);
                        printf("\n\t\t____________________RADIX SORT_____________________\n\n");
                        printf("\n\t\t____________________VETOR DE 100___________________\n");
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        radix_Sort(vet1000, 1000, &tempo);
                        printf("\n\t\t____________________VETOR DE 1.000_________________\n");
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        radix_Sort(vet10000, 10000, &tempo);
                        printf("\n\t\t___________________VETOR DE 10.000_________________\n");
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);

                        radix_Sort(vet100000, 100000, &tempo);
                        printf("\n\t\t__________________VETOR DE 100.000_________________\n");
                        printf("\t\t\tTempo de Execução: %lf\n", tempo);
                        printf("\t\t___________________________________________________\n");
                        Sleep(1000);
                        getch();

                        ordena(vet100, vet1000, vet10000, vet100000, &libera_ordena);

                        break;
                    }
                    case 5:{
                        system("cls");

                        break;
                    }
                    case 6:{
                        system("cls");
                        break;
                    }
                    case 7:{
                        system("cls");
                        break;
                    }

                }
                system("cls");
            }
            while (opcao!= 8);
            break;
        }

        case 3:{
        do{
                system("cls");
                printf("\t__________________________________________________________");
                printf("\t\t\t\t\t\tBUSCAR ARQUIVOS\n");
                printf("\t__________________________________________________________");
                printf("\n\n\t\t1 - BUSCA SEQUENCIAL\n\t\t");
                printf("2 - BUSCA BINÁRIA\n\t\t");
                printf("3 - VOLTAR\n\t\t");
                printf("\n\n\t-OPÇÃO: ");
                setbuf(stdin, NULL);
                scanf("%d", &x);

                switch(x){
                    case 1:{
                        if (libera == 0){
                        system("cls");
                        printf("\n\n\t__________________________________________________________");
                        printf("\n\n\t\t\t    PRIMEIRO ORDENE O ARQUIVO\n");
                        printf("\n\n\t__________________________________________________________");
                        Sleep(3000);
                        break;
                        }
                        system("cls");
                        break;
                    }

                    case 2:{
                        if (libera == 0 || libera_ordena == 0){
                            system("cls");
                            printf("\n\n\t__________________________________________________________");
                            printf("\n\n\t\t\t    PRIMEIRO ORDENE O ARQUIVO\n");
                            printf("\n\n\t__________________________________________________________");

                            if (libera == 1 && libera_ordena == 0){
                                system("cls");
                                printf("\n\n\t__________________________________________________________");
                                printf("\n\n\t\t\t    PRIMEIRO ORDENE O ARQUIVO\n");
                                printf("\n\n\t__________________________________________________________");

                            }
                        Sleep(3000);
                        break;
                        }
                        system("cls");
                        printf("\t\t__________________________________________________");
                        printf("\t\t\t\t\t\tBUSCA BINARIA\n");
                        printf("\t\t__________________________________________________\n\n");

                        break;

                        case 3:{
                        if(x == 3){
                            return main();
                        }
                    }
                    }
                    case 8:{
                        if(x == 8){
                            return main();
                        }
                    }
                }
            }while (x != 8);
        }


        case 4:{
            system("cls");
            exit(1);
            }

        }
    }while (x != 4);

    return 0;
}
