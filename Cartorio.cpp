#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h>// biblioteca rsponável por cuidar das string


int registro() //Função responsável por cadastrar os usuário no sistema
{
	//início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //cria o arquivo e o "a" significa atualizar/armazenar 
	fprintf(file,","); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrato: "); //coletando informação do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	system("pause");
	
	
}

int consulta() //Função responsável por consultar os usuário no sistema
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	//início da criação de variáveis/string
	char cpf[40];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar() //Função responsável por deletar os usuário no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}	
}


int main()
{
    int opcao=0; //Definindo as variáveis
    int x=1;
    
    for(x=1;x==1;)
    {
	
		system("cls"); //responsável por limpar a tela
		    
    	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
    
    	printf("### Cartório da EBAC ###\n\n"); //início do menu
    	printf("Escolha a opção desejada do menu\n\n");
    	printf("\t1 - Registrar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//fim do menu
    
    	scanf("%d", &opcao); //armazenando a escolha do usuário
    
    	system("cls"); //responável por limpar a tela
    
    	switch(opcao)
    	
    	{
    			case 1:
    			registro(); //chamada de funções
				break;
    			
    			case 2:
    			consulta();
    			break;
    			
    			case 3:
    			deletar();
    			break;
    			
    			case 4:
    			printf("Obrigado por utilizar o sistema\n");
    			return 0;
    			break;
    			
    			default:
    			printf("Essa opção não está disponível!\n");
    			system("pause");
    			break;
		}
		
	}
}
