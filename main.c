/*
 Disciplina: Técnicas de Programação
 Aluno: Eduardo Pessonia Molina Cortez
 MAtrícula: 2020215387
 
 Esse programa simula um sistema de cadastro e busca de carros;
 
 Os dados referentes aos carros são:
    - marca do veículo
    - modelo
    - ano de fabricação
    - placa (formato XXX-YYYY
 
 As funções do sistema são:
    - Listar os veículos cadastrados;
    - Inserir um novo veículo (o sistema reordena os carros por ano de fabricação);
    - Listar os veículos filtrando-se por ano de fabricação;
    - Listar os veículos com o ano de fabricação acima de um certo valor especificado pelo usuário
    - Listar os veículos filtrando-se pelo modelo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct placa
{
    char xxx[4];
    char yyyy[5];
}PLACA;

typedef struct carro
{
    char marca[20];
    char modelo[20];
    int ano;
    PLACA pl;
}CARRO;


void cadastrar(CARRO *c)
{
    printf("\nPreencha as seguintes informações\n\n");
    printf("Marca do veículo: ");
    fgets(c->marca, 20, stdin);
    c->marca[strcspn(c->marca, "\n")] = 0;
    printf("Modelo do veículo: ");
    fgets(c->modelo, 20, stdin);
    c->modelo[strcspn(c->modelo, "\n")] = 0;
    printf("Ano do veículo: ");
    scanf("%4d", &c->ano);
    fflush(stdin);
        //Verifgicar se o valor digitado é um número
        while(c->ano == 0)
        {
            printf("\nValor incompatível com o ano do carro. Por favor, digite novamente\n");
            printf("Ano do veículo: ");
            scanf("%4d", &c->ano);
            fflush(stdin);
        }
    printf("Placa do veículo:\n");
    printf("\tLetras: ");
    fgets(c->pl.xxx, 4, stdin);
    fflush(stdin);
        // Checar se o formato é válido
        int i;
        for(i = 0; i < 3; i++)
        {
            while (c->pl.xxx[i] < 'A' || c->pl.xxx[i] > 'Z')
            {
                printf("\nDigitação incorreta. Utilize letras maiúsculas\n\n");
                printf("\tLetras: ");
                fgets(c->pl.xxx, 4, stdin);
                fflush(stdin);
            }
        }
    printf("\tNúmeros: ");
    fgets(c->pl.yyyy, 5, stdin);
    fflush(stdin);
        // Checar se o formato é válido
    for(i = 0; i < 4; i++)
        {
            while (c->pl.yyyy[0] < '0' || c->pl.yyyy[0] > '9')
            {
                printf("\nDigitação incorreta. Utilize números\n\n");
                printf("\tNúmeros: ");
                fgets(c->pl.yyyy, 5, stdin);
                fflush(stdin);
            }
        }
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    CARRO carros[10]; //Criei um array de carros;
    
    // Garante que nenhum lixo da memória será interpretado como carro no ordenamento dos veículos enquanto os 10 carros não forem preenchidos pelo usuário
    carros[0].ano = 0;
    carros[1].ano = 0;
    carros[2].ano = 0;
    carros[3].ano = 0;
    carros[4].ano = 0;
    carros[5].ano = 0;
    carros[6].ano = 0;
    carros[7].ano = 0;
    carros[8].ano = 0;
    carros[9].ano = 0;
    
    int numCadast = 0;
    int print;
    
    int opt = 0; //Opção do Case Switch Geral
    int opt2; // Controla o Loop do cadastro (default = 1)
    int resposta2; // Confirma o loop do castro (default = 0)
    int resposta1; // Aplicação de filtros na listagem
    int resposta11; // Verifica se a saída do filtro é para a lista completa ou para o início do programa
    
    int filtroAno;
    char filtroMarca[20];
    
    do{
    
    opt2 = 1; // Loop do cadastro por default
    resposta2 = 0; // resposta para confirmar o loop do castro
        
    printf("\n");
    printf("##############################################\n");
    printf("##############################################\n");
    printf("##                                          ##\n");
    printf("##       BEM VIND AO GESTOR DE VEÍCULOS     ##\n");
    printf("##                                          ##\n");
    printf("##       O QUE DESEJA FAZER?                ##\n");
    printf("##                                          ##\n");
    printf("##  1 - LISTAR VEÍCULOS CADASTRADOS         ##\n");
    printf("##        (Selecione para ver mais opções)  ##\n");
    printf("##  2 - CADASTRAR VEÍCULO                   ##\n");
    printf("##  3 - SAIR                                ##\n");
    printf("##                                          ##\n");
    printf("##                                          ##\n");
    printf("##############################################\n");
    printf("##############################################\n");
    printf("\n\n");
    
   
        printf("Opção: ");
        scanf("%d", &opt);
        fflush(stdin);
        switch (opt) //Case Switch Geral
        {
            case 1: //Listar veículos
            {
               // Verificar se já há veículo cadastrado
                if(numCadast == 0)
               {
                   printf("\n\nVocê ainda não tem veículos cadastrados.\n");
                   printf("Gostaria de cadastrar um veículo? S/N \n");
                   char resposta = 'a';
                   while(resposta != 'S' && resposta != 'N')
                   {
                   scanf("%c", &resposta);
                   fflush(stdin);
                   resposta = toupper(resposta);
                   switch(resposta)
                        {
                            case 'S':
                                cadastrar(&carros[numCadast]);
                                numCadast = numCadast + 1;
                                
                                // Confirmar que o veículo foi cadastrado e imprimir suas informações
                                printf("\n\nVeículo cadastrado com sucesso.");
                                printf("\n\nANO \tPLACA \t\tMARCA \t\tMODELO \n");
                                printf("%d \t%s-%s \t%s \t\t%s \n", carros[numCadast-1].ano, carros[numCadast-1].pl.xxx, carros[numCadast-1].pl.yyyy, carros[numCadast-1].marca, carros[numCadast-1].modelo);
                                
                                printf("\nPressione \"enter\" para continuar.\n");
                                getchar();
                                
                                opt = 0;
                                
                                break;
                            case 'N':
                                opt = 0;
                                break;
                            default:
                                printf("Resposta inválida. Digite S ou N.\n");
                       }
                   }
               }
                else
                {
                    resposta11 = 1; // default para retornar para cá
                    while(resposta11 == 1)
                    {
                    // Imprimir todos
                    printf("\n\nLista completa de veículos:");
                    printf("\n\nANO \tPLACA \t\tMARCA \t\tMODELO \n");
                    for(print = 0; print < numCadast; print++)
                    {
                        printf("%d \t%s-%s \t%s \t\t%s \n", carros[print].ano, carros[print].pl.xxx, carros[print].pl.yyyy, carros[print].marca, carros[print].modelo);
                    }
                    
                    resposta1 = 0;
                    while(resposta1 == 0)
                    {
                    //Oferecer filtros
                    printf("\n\nSelecione uma das opções abaixo:\n\n");
                    printf("1 - Filtrar veículos por ANO DE FABRICAÇÃO ESPECÍFICO.\n");
                    printf("2 - Filtrar veículos A PARTIR de determinado ano de fabricação.\n");
                    printf("3 - Filtrar veículos por MARCA ESPECÍFICA.\n");
                    printf("4 - Voltar ao início.\n");
                    
                    //Seleção da opção
                    scanf("%d", &resposta1);
                    fflush(stdin);
                    switch(resposta1)
                    {
                        case 1:
                        {
                            printf("\nDigite o ano de fabricação ESPECÍFICO: ");
                            scanf("%d", &filtroAno);
                            fflush(stdin);
                            
                            //Impressão de carros de um ano específico
                            printf("\n\nANO \tPLACA \t\tMARCA \t\tMODELO \n");
                            for(print = 0; print < numCadast; print++)
                            {
                                if(carros[print].ano == filtroAno)
                                {
                                printf("%d \t%s-%s \t%s 't\t%s \n", carros[print].ano, carros[print].pl.xxx, carros[print].pl.yyyy, carros[print].marca, carros[print].modelo);
                                }
                            }
                            
                            //Voltar para a lista completa ou para o início
                            do
                            {
                            printf("\nSelecione a opção desejada:\n");
                            printf("1 - Retornar à lista compeleta de carros;\n");
                            printf("2 - Retornar ao início.\n");
                            
                            scanf("%d", &resposta11);
                            fflush(stdin);
                            
                            if(resposta11 == 2)
                                opt = 0;
                            else if(resposta11 != 1) // Se for 1, volta no início do programa
                                printf("\n\nResposta inválida.\n");
                            } while(resposta11 != 1 && resposta11 != 2); // Volta nesta pergunta
                        }
                            break;
                        case 2:
                        {
                            printf("\nDigite o ano de fabricação A PARTIR do qual será impressa a lista de carros: ");
                            scanf("%d", &filtroAno);
                            fflush(stdin);
                            
                            //Impressão de carros a partir de um determinado ano
                            printf("\n\nANO \tPLACA \t\tMARCA \t\tMODELO \n");
                            for(print = 0; print < numCadast; print++)
                            {
                                if(carros[print].ano >= filtroAno)
                                {
                                printf("%d \t%s-%s \t%s \t\t%s \n", carros[print].ano, carros[print].pl.xxx, carros[print].pl.yyyy, carros[print].marca, carros[print].modelo);
                                }
                            }
                            
                            //Voltar para a lista completa ou para o início
                            do
                            {
                            printf("\nSelecione a opção desejada:\n");
                            printf("1 - Retornar à lista compeleta de carros;\n");
                            printf("2 - Retornar ao início.\n");
                            
                            scanf("%d", &resposta11);
                            fflush(stdin);
                            
                            if(resposta11 == 2)
                                opt = 0;
                            else if(resposta11 != 1) // Se for 1, volta no início do programa
                                printf("\n\nResposta inválida.\n");
                            } while(resposta11 != 1 && resposta11 != 2); // Volta nesta pergunta
                        }
                            break;
                        case 3:
                        {
                            printf("\nDigite a MARCA específica dos carros que quer ver: ");
                            fflush(stdin);
                            fgets(filtroMarca, 20, stdin);
                            filtroMarca[strcspn(filtroMarca, "\n")] = 0;
                            
                            //Impressão de carros de uma determinada marca
                            printf("\n\nANO \tPLACA \t\tMARCA \t\tMODELO \n");
                            for(print = 0; print < numCadast; print++)
                            {
                                if(strcmp(carros[print].marca, filtroMarca) == 0)
                                {
                                printf("%d \t%s-%s \t%s \t\t%s \n", carros[print].ano, carros[print].pl.xxx, carros[print].pl.yyyy, carros[print].marca, carros[print].modelo);
                                }
                            }
                            
                            //Voltar para a lista completa ou para o início
                            do
                            {
                            printf("\nSelecione a opção desejada:\n");
                            printf("1 - Retornar à lista compeleta de carros;\n");
                            printf("2 - Retornar ao início.\n");
                            
                            scanf("%d", &resposta11);
                            fflush(stdin);
                            
                            if(resposta11 == 2)
                                opt = 0;
                            else if(resposta11 != 1) // Se for 1, volta no início do programa
                                printf("\n\nResposta inválida.\n");
                            } while(resposta11 != 1 && resposta11 != 2); // Volta nesta pergunta
                        }
                            break;
                        case 4:
                        {
                            resposta11 = 2;
                            opt = 0; // Volta ao início
                        }
                            break;
                        default:
                        {
                            printf("\n\nResposta inválida.\n");
                            resposta1 = 0;
                        }
                    }
                    }
                    }
                }
            }
                break;
            case 2: //Cadastrar veículos
            {
                do
                {
                resposta2 = 0;
                    
                if(numCadast < 10) // Checa se ainda há espaço para cadastrar veículos
                {
                cadastrar(&carros[numCadast]);
                numCadast = numCadast + 1;
                    
                // Confirmação de cadastro
                    printf("\n\nVeículo cadastrado com sucesso.");
                    printf("\n\nANO \tPLACA \t\tMARCA \t\tMODELO \n");
                    printf("%d \t%s-%s \t%s \t\t%s \n", carros[numCadast-1].ano, carros[numCadast-1].pl.xxx, carros[numCadast-1].pl.yyyy, carros[numCadast-1].marca, carros[numCadast-1].modelo);
                
                // Reordenar por ano
                int c1, c2, posNovo;
                CARRO carTemp, maisNovo;
                
                for(c1 = 0; c1 <= numCadast; c1++)
                {
                    maisNovo = carros[c1];
                    posNovo = c1;
                    for(c2 = c1+1; c2 <= numCadast; c2++)
                    {
                        if(carros[c2].ano > carros[c1].ano)
                        {
                            maisNovo = carros[c2];
                            posNovo = c2;
                        }
                    }
                    if(posNovo != c1)
                    {
                        carTemp = carros[c1];
                        carros[c1] = carros[posNovo];
                        carros[posNovo] = carTemp;
                    }
                }
                    
                // Questionar se o usuário deseja cadastrar novo veículo ou retornar ao início.
                    while(resposta2 != 1)
                    {
                    printf("\nO que deseja fazer?\n");
                    printf("\n1 - Cadastrar novo veículo; \n2 - Retornar ao início.\n");
                
                    scanf("%d", &resposta2);
                    fflush(stdin);
                    
                    if(resposta2 == 2)
                    {
                        resposta2 = 1;
                        opt2 = 2;
                        opt = 0;
                    }
                    else if(resposta2 != 1)
                    {
                        printf("\n\nResposta inválida.\n");
                    }
                    }
                    
                }
                else //Já possui 10 veículos cadastrados
                {
                    printf("\n\nVocê já cadastrou o máximo de 10 veículos em nosso sistema.\n\n");
                    printf("Pressione \"enter\" para retornar ao início.");
                    
                    getchar();
                    
                    opt = 0;
                }
                
                }while(opt2 == 1);
                
            }
                break;
            case 3 : return 0;
            default:
                printf("Opção inválida. Tente novamente.\n\n");
            
        }
    } while(opt < 1 || opt > 3);
}

