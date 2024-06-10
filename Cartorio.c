#include <stdio.h> //biblioteca de comunicao com o usuario
#include <stdlib.h>//biblioteca de alocacao de espaco em memoria
#include <locale.h>//biblioteca de alocacao de texto por regiao
#include <string.h>//biblioteca reponsavel por cuidar das string

int registro()//função a ser referenciada na funçáo principal com a finalidade de regiustro
{
	//Declaraçáo de variaveis
	char arquivo[40];//armnasenar cpf apos registro
	char cpf[40];//recener cpf
	char nome[40];//receber nome 
	char sobrenome [40];//receber sobrenome
	char cargo [40];//receber cargo
	
	//Entradada de dados
	printf("Digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//copiar registro do cpf
	
	FILE *file;//chamar funçáo
	file = fopen(arquivo, "w");//abrir funçáo de registro
	fprintf(file,cpf);//receber dados
	fprintf(file,"\n");
	fclose (file);//fechar funçáo


	
	printf("Digite o nome do a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen (arquivo,"a");
	fprintf(file,nome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consulta()//função a ser referenciada na funçáo principal com a finalidade de consulta
{
	//declaraçáo de variaveis
	char cpf[40];//receber cpf
  	char conteudo[200];//receber conteudo arquivado
  	int cont=0;//contador de loop
  	
  	//Definir idioma 
	setlocale(LC_ALL, "Portuguese");
	
	//Entrada de dados
  	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	system("cls");
	
	//Saida de dados
  	FILE *file;
  	file = fopen(cpf,"r");
 
  	if(file == NULL)//validaçáo
	{
  		printf("\nNão foi possível abrir o arquivo, não localizado!\n\n");
  		system ("pause");
	}
	else//apresentaçáo dos dados
	{
		printf ("\n Essas são as informações do usuário: \n\n");
		while(fgets(conteudo, 200, file)!= NULL)
		{
			switch(cont)
			{
				case 0:
					printf(" CPF do usuário: \t");
					printf ("%s",conteudo);
				break;
				
				case 1:
					printf(" Nome do usuário: \t");
					printf ("%s",conteudo);
				break;
				
				case 2:
					printf(" Sobrenome do usuário: \t");
					printf ("%s",conteudo);
				break;
				
				case 3:
					printf(" Cargo do usuário: \t");
					printf ("%s",conteudo);
				break;
			}
				cont=cont+1;
		}
		printf ("\n\n");
	  	system("pause");
  }
}
int deletar()//função a ser referenciada na funçáo principal com a finalidade de deletar
{
	char cpf[40];
	
	setlocale(LC_ALL, "Portuguese");	
	
    printf("\nDigite o CPF do usuário a ser deletado: ");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("\nO usuário de CPF %s não se encontra no sistema\n\n!",cpf);
    	system("pause");
	}
	else
	{
		printf("\nO usuário de CPF %s deletado com sucesso!\n\n",cpf);
    	system("pause");
	}
}

int main()//funçáo principal
{
	//Definição de variaveis
	int opcao=0;//variavel de registro
	int laco=0;//variavel de contagem
	
	//Execução do programa
	for(laco=1;laco==1;)//loop
	{
		//Definição de tipo de texto
		setlocale(LC_ALL, "Portuguese");
		
		//Saida de texto
		printf("### Cartório da EBAC ###\n\n");//inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n");
		printf("Opção: ");//fim do menu
		
		//Entrada de dados
		scanf("%d",&opcao);//recebendo valor de opcao
		
		system("cls");//limpamdo tela
		
		//Saida de dados
		switch (opcao)//inicio da selecao
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("\n\n\nEssa opção não esta disponível!\n\n\n\n");
			system ("pause");
			break;
			
		}//fim da selecao
		system("cls");
	}
	//Royalties
	printf("\n\nEsse Softare é de Fernando Nogueira de Souza\n");
	
	return (0);
}
