#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no{
    char nome;
    float salario;
    struct no *prox;
};

typedef struct no No;

struct f{
    No* inicio;
    No* fim;
};

typedef f Fila;

Fila *criaFila(){
	Fila *fi = (Fila*) malloc (sizeof(Fila));
	fi->inicio = NULL;
	fi->fim = NULL;
	return fi;
}

void inserir (Fila *fila, char nome[], float salario){
	No *novo;
	novo = (No*) malloc (sizeof(No));
	
	strcpy (novo-> nome, nome);
	novo->salario=salario;
	novo->prox=NULL;
	
	if (fila->fim!=NULL){
		fila->fim->prox=novo;
	}else{
		fila->inicio=novo;
	}
	fila->fim=novo;
}

bool filaVazia(Fila *fila){
	if (fila->inicio==NULL){
		return true;
	}else{
		return false;
	}
}

void mostrar (Fila *fila){
	No *aux;
	printf ("Funcionarios que estao cadastrados: \n");
	if(filaVazia(fila)){
	printf ("Fila estar Vazia: \n");
}else{
	 aux=fila->inicio;
	
	 printf ("Nome: %s\n", fila->inicio->nome);
	 printf ("Salario: %.2f\n", fila->inicio->salario);
	 printf ("Nome: %s\n", fila->fim->nome);
	 printf ("Salario: %.2f\n", fila->fim->salario);
	 
	 for (aux=aux->prox;aux->prox!=NULL;aux=aux->prox){
	 printf ("Nome: %s\n", aux->nome);
	 printf ("Salario: %.2f\n", aux->salario);
	 }
   }
}

void maior(Fila *fila){
	float maior;
	char nome[40];
	No *aux;
	aux=fila->inicio;
	if (fila->inicio==NULL;){
		printf ("Fila VAzia!: \n");
	}else{
		maior=fila->inicio->salario;
		while ((aux!=NULL){
			if ((aux->salario>maior)){
				maior=aux->salario;
				strcpy(nome, aux->nome);
			}
		aux=aux->prox;	
		}
	}
	printf ("O Funcionario com maior salario eh: %s\n", nome);
}

void menor(Fila *fila){
	float menor;
	char nome[40];
	No *aux;
	aux=fila->inicio;
	if (fila->inicio==NULL;){
		printf ("Fila VAzia!: \n");
	}else{
		maior=fila->inicio->salario;
		while ((aux!=NULL){
			if ((aux->salario<menor)){
				menor=aux->salario;
				strcpy(nome, aux->nome);
			}
		aux=aux->prox;	
		}
	}
	printf ("O Funcionario com maior salario eh: %s\n", nome);
}

void media(Fila *fila){
	int i=0;
	float media=0;
	No *aux;
	
	if (filaVazia(fila)){
		printf ("Fila Vazia!: \n");
	}else{
		aux=fila->inicio;
		while(aux){
			media+=aux->salario;
			i++;
			aux=aux->prox;
		}
		media=media/i;
		printf ("A media do salario eh: %.2f\n", media);
	}
}

int main(){
	int opcao=0;
	Fila *fila;
	Fila=criaFila();
	
	inserir(fila, "Jose Arruda", 1000.32);
	inserir(fila, "Jucelino Costa", 1040 .30);
	inserir(fila, "Joao Carlos", 2000.35);
	inserir(fila, "Manoel Silva", 100.20);
	inserir(fila, "Karoline Magalhaes", 2010.25);
	inserir(fila, "Marlucia Dias", 1900.90);
	inserir(fila, "Jose Marques", 2400.25);
	inserir(fila, "Pedro Henrique", 1600.80);
	
	mostrar(fila);
	printf ("_ _ _  MENU _ _ _ \n\n");
    printf ("1. NOME DO FUNCIONARIO COM MAIOR SALARIO: \n");
    printf ("2. NOME DO FUNCIONARIO COM MENOR SALARIO: \n");
    printf ("3. MEDIA DO SALARIO DE TODOS OS FUNCIONARIOS \n");
    printf ("4. SAIR: \n");
    do{
    	printf ("\nDigite sua opcao desejada: \n");
    	scanf("%d", &opcao);
    	if (opcao=1){
    		maior(fila);
		}else if (opcao==2){
			menor(fila);
		}else if (opcao==3){
			media(fila);
		}else if (opcao==4){
			printf ("Sair do Programa . . . \n");
			break;
		}else{
			printf ("Opcao nao eh valida! \n");
		}
		
	}while(opcao!=4);
	
	
	return 0;
}











