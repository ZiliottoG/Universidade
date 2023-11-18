#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 50
#define MAX_STRING 100


typedef struct Estudante {
	char nome[MAX_STRING], nascimento[MAX_STRING], cpf[MAX_STRING];
	int idade,id,atividade;
}TEstudante;

void exibe_menu(){
		//Exibir as opções do menu
	
		printf("\nBem Vindo\n\n");
		printf("Escolha uma opcao:\n");
		printf("1. Novo Cadastro\n2. Lista de cadastros\n3. Pesquisar Cadastro\n4. Atualizar Cadastro\n5. Remover Cadastro\n6. Sair\n");
}
void exibe_menurep(){
		//Exibe as opções do menu mais uma mensagem de opção invalida
		
		printf("\n\nOpcao Invalida!\n\n");
		printf("Escolha uma opcao valida:\n");
		printf("1. Novo Cadastro\n2. Lista de cadastros\n3. Pesquisar Cadastro\n4. Atualizar Cadastro\n5. Remover Cadastro\n");
}
void cadastrar_estudante(TEstudante estudantes[], int apontadora){
	//Informações cadastrais dos estudantes
	
	printf("Entre com o nome:\n");
	fgets(estudantes[apontadora].nome, MAX_STRING-1, stdin);
	
	printf("Entre com a idade:\n");
	scanf("%d", &estudantes[apontadora].idade);
	getchar();
	
	printf("Entre com o CPF:\n");
	fgets(estudantes[apontadora].cpf, MAX_STRING-1, stdin);
	
	printf("Entre com a data de nascimento:\n");
	fgets(estudantes[apontadora].nascimento, MAX_STRING-1, stdin);
	
	//Definição de ID e Atividade 
	estudantes[apontadora].id = apontadora + 1;
	estudantes[apontadora].atividade = 1;
	
	printf("Cadastrado com sucesso!\nID:  0%d\n\n\n\n", estudantes[apontadora].id);
	
	apontadora++;
	
	}	
void exibe_cadastros(TEstudante estudantes[], int apontadora){
	int i;
	
	for (i=0; i<apontadora; i++) {
	
		printf("--------------------------------------------------------------");
		printf("\nDados da pessoa %d:\n", estudantes[i].id);
		printf("nome = %s", estudantes[i].nome);
		printf("idade = %d\n", estudantes[i].idade);
		printf("cpf = %s", estudantes[i].cpf);
		printf("data de nascimento = %s", estudantes[i].nascimento);
		printf("ID = %d\n", estudantes[i].id);
	
		if(estudantes[i].atividade == 1){
			printf("Situacao: Ativo\n");
		}
		else{
			printf("Situacao: inativo\n");
		}
		printf("-------------------------------------------------------------\n");
	}
}
void pesquisa_cadastro(TEstudante estudantes[], int apontadora){
	
	int numid = 0;	
	
	//Repetição caso o numero digitado não seja encontrado
	
	while(numid <= 0 || numid > apontadora){

		printf("Digite o ID do cadastro desejado:\n");
		scanf("%d", &numid);
	
		if(numid <= 0 || numid > apontadora){
			printf("ID invalido ou nao encontrado.\nTente Novamente\n");
		}	
	}
	
	//ID - 1 para ser selecionado corretamente na struct
	
	numid = numid-1;
	
	printf("--------------------------------------------------------------\n");
	printf("\nDados da pessoa %d:\n", estudantes[numid].id);
	printf("nome = %s", estudantes[numid].nome);
	printf("idade = %d\n", estudantes[numid].idade);
	printf("cpf = %s", estudantes[numid].cpf);
	printf("data de nascimento = %s", estudantes[numid].nascimento);
	printf("ID = %d\n", estudantes[numid].id);
	
	if(estudantes[numid].atividade == 1){
		printf("Situacao: Ativo\n");
	}
	else{
		printf("Situacao: inativo\n");
	}
	printf("--------------------------------------------------------------\n");
	
}
void atualiza_cadastro(TEstudante estudantes[], int apontadora){
	
	int numid, op;
	op = 0;
	numid = 0;
	
	//repetição para selecionar ID do aluno
	while(numid <= 0 || numid > apontadora ){
		printf("Digite o ID do cadastro que quer atualizar:\n");
		scanf("%d", &numid);
	
			if(numid <= 0 || numid > apontadora){
				printf("ID invalido ou nao encontrado.\nTente Novamente\n");
			}		
	}	
	
	//ID - 1 para ser selecionado corretamente na struct
	numid = numid - 1;
	
	printf("--------------------------------------------------------------\n");
	printf("\nDados da pessoa %d:\n", estudantes[numid].id);
	printf("nome = %s", estudantes[numid].nome);
	printf("idade = %d\n", estudantes[numid].idade);
	printf("cpf = %s", estudantes[numid].cpf);
	printf("data de nascimento = %s", estudantes[numid].nascimento);
	printf("ID = %d\n", estudantes[numid].id);
	
	if(estudantes[numid].atividade == 1){
		printf("Situacao: Ativo\n");
	}
	else{
		printf("Situacao: inativo\n");
	}
	printf("--------------------------------------------------------------\n");
	
	//menu para a mudança do cadastro
	while(op <= 0 || op > 4){
		printf("O que deseja alterar nesse cadastro?\n\n");
	
		printf("1. Nome\n2. Idade\n3. CPF\n4. Data de nascimento\n");
		scanf("%d", &op);
		
		if(op <= 0 || op > 4){
			printf("Opcao invalida!\n");
		}
	
	}
	
	
	
	switch(op){
		
		case 1:
			getchar();
			printf("Entre com o nome do estudante:\n");
			fgets(estudantes[numid].nome, MAX_STRING-1, stdin);
		
		break;
		
		case 2:
			printf("Entre com a idade do estudante:\n");
			scanf("%d", &estudantes[numid].idade);
		
		break;
		
		case 3:
			getchar();
			printf("Entre com o CPF do estudante:\n");
			fgets(estudantes[numid].cpf, MAX_STRING-1, stdin);
		
		break;
		
		case 4:
			getchar();
			printf("Entre com a data de nascimento do Estudante:\n");
			fgets(estudantes[numid].nascimento, MAX_STRING-1, stdin);
		break;
		
		default:
			printf("opcao invalida!\n");
		
		break;
	}
	
	printf("Operacao realizada com sucesso!\n");
	
	
}
void remove_cadastro (TEstudante estudantes[], int apontadora){


	int op, numid;
	
	op = 0;
	
	numid = 0;
	
	while (op != 1){
	
		while (numid <= 0 || numid > apontadora){
		
			printf("Digite o ID do estudante que Deseja remover:\n");
			scanf("%d", &numid);
		
			if (numid <= 0 || numid > apontadora) {
				printf("ID invalido ou nao encontrado.\nTente Novamente\n");
			}	
		}
	
		numid = numid - 1;
	
		printf("--------------------------------------------------------------\n");
		printf("\nDados da pessoa %d:\n", estudantes[numid].id);
		printf("nome = %s", estudantes[numid].nome);
		printf("idade = %d\n", estudantes[numid].idade);
		printf("cpf = %s", estudantes[numid].cpf);
		printf("data de nascimento = %s", estudantes[numid].nascimento);
		printf("ID = %d\n", estudantes[numid].id);
	
		if (estudantes[numid].atividade == 1){
			printf("Situacao: Ativo\n");
		}
		else{
			printf("Situacao: inativo\n");
		}
		printf("--------------------------------------------------------------\n");
	
		printf("\n\nDeseja inativar esse cadastro?\n");
		printf("1. Para sim\n2. Para nao\n");
		scanf("%d", &op);
	}
		if(op == 1){
		
			estudantes[numid].atividade = 0;
		}
	
	printf("--------------------------------------");
	printf("\nOperacao realizada com sucesso!\n");
	printf("--------------------------------------\n");
}

int main(){

	TEstudante estudantes[TAM];
	
	int opcao, num_estudantes, apontadora;
	
	apontadora = 0;
	opcao = 0;
	
	while(opcao != 6){	
	
		exibe_menu();
		
		scanf("%d", &opcao);
	
		if(opcao > 6 || opcao <=0){
			
			exibe_menurep();
		}
		
		switch (opcao){
		
			case 1: 
				getchar();
				cadastrar_estudante(estudantes, apontadora);
				apontadora++;
			break;
		
			case 2:
				exibe_cadastros(estudantes, apontadora);
						
			break;
		
			case 3:
				pesquisa_cadastro(estudantes, apontadora);
			
			break;
		
			case 4:
				atualiza_cadastro(estudantes, apontadora);
			
			break;
		
			case 5:
				remove_cadastro(estudantes, apontadora);
			
			break;
			
			case 6:
				printf("\nEncerrando...\n");
			break;
		
		}
	}
}
