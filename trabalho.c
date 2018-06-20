#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>



int cont1=0, cont2=0,cont3=0, cont4=0, cont5=0,cont6=0; // contadores do preenchimento dos vetores dos cursos
int n_inscricao=0; 

// registro das informações do candidato
struct dados {
	char nome[100];
	int idade;
	int nota;
	int inscricao;

};

// vetores dos cursos 
struct dados curso1[40];
struct dados curso2[40];
struct dados curso3[40];
struct dados curso4[40];
struct dados curso5[40];
struct dados curso6[40];

// prototipos das funções 
int lista (struct dados *curso,int posicao);
int cadastro(struct dados *curso, int contador);
int salvar (struct dados *curso, int posicao, char *arqnomes, char *arqdados);
int ordenacao(struct dados curso[], int contador);

int menu (){ // mostra as opções e encaminha às funções 

	setlocale(LC_ALL,"portuguese");
	int alt ;// variavel para a alternativa de ação a ser escolhida no menu, pelo usuário
	int curso; // variavel para a alternativa de curso no qual o usuário quer se cadastrar 
	int list; // variável para a alternativa de lista que o usuário quer ver
	
	//strings com os nomes dos arquivos nos quais os dados vão ser salvos (serão utilizadas como aparametros para chamar a função de salvamento)
	char nomes1[15],dados1[15],nomes2[15],dados2[15],nomes3[15],dados3[15],nomes4[15],dados4[15],nomes5[15],dados5[15],nomes6[15],dados6[15];
	
	
	
	strcpy(nomes1,"curso1nomes.txt");
	strcpy(dados1,"curso1dados.txt");
	
	strcpy(nomes2,"curso2nomes.txt");
	strcpy(dados2,"curso2dados.txt");
	
	strcpy(nomes3,"curso3nomes.txt");
	strcpy(dados3,"curso3dados.txt");
	
	strcpy(nomes4,"curso4nomes.txt");
	strcpy(dados4,"curso4dados.txt");
	
	strcpy(nomes5,"curso5nomes.txt");
	strcpy(dados5,"curso5dados.txt");
	
	strcpy(nomes6,"curso6nomes.txt");
	strcpy(dados6,"curso6dados.txt");
	
	
	// escolha da ação 
	printf (" 1. Cadastre a sua nota no nosso sistema\n");
	printf (" 2. Veja as listas parcial dos aprovados\n");
	printf (" 3. Mostrar o regulamento\n");
	printf (" 4. Sair\n\n");
	printf ("Digite o código da operação que deseja realizar:\n");
	scanf("%d",&alt);

	
	switch (alt){
	
		case 1: // cadastro -> por meio da variável curso, manda o ponteiro do vetor do curso escolhido para a função cadastro
	
		printf ("\nEm qual curso deseja ingressar?\n");
		printf(" 1. Medicina\n 2. Psicologia\n 3. Direito\n 4. Engenharia Elétrica\n 5. Engenharia Mecânica\n 6. Engenharia da Computação\n 7. Voltar para o menu \n\n");
		scanf ("%d",&curso);
			
		switch (curso){		
			case 1 : // cadastro no curso 1
				printf("\n=================================================================================================\n");
				printf("                                        Medicina ");
				cont1++;
				cadastro (curso1,cont1);
				break;
			case 2: // cadastro no curso 2
				printf("\n=================================================================================================\n");
				printf("                                       Psicologia ");
				cont2++;
				cadastro (curso2,cont2);
				break;
			case 3: // cadastro no curso 3
				printf("\n=================================================================================================\n");
				printf("                                         Direito ");
				cont3++;
				cadastro (curso3,cont3);
				break;
			case 4: // cadastro no curso 4 
				printf("\n=================================================================================================\n");
				printf("                                   Engenharia Elétrica ");
				cont4++;
				cadastro (curso4,cont4);
				break;
			case 5: // cadastro no curso 5 
				printf("\n=================================================================================================\n");
				printf("                                   Engenharia Mecânica ");
				cont5++;
				cadastro (curso5,cont5);
				break;
			case 6: // cadastro no curso 6 
				printf("\n=================================================================================================\n");
				printf("                                Engenharia da Computação ");
				cont6++;	
				cadastro (curso6,cont6);
				break;
			case 7: // sair 
				printf ("\n");
				menu ();
			default :
				//while(curso<1 || curso>7){
				printf("\nCódigo inválido!\nInsira um código válido:\n");
				//scanf("%d",&curso);
                alt = 1;
                menu();
               // }
				break;
				}	
		break;	
			
		case 2: // mostrar uma lista -> por meio da variável list, manda o ponteiro do vetor do curso escolhido para a função lista
			printf("\nQual lista deseja ver?\n");
			printf(" 1. Medicina\n 2. Psicologia\n 3. Direito\n 4. Engenharia Elétrica\n 5. Engenharia Mecânica\n 6. Engenharia da Computação\n 7. Voltar para o menu \n\n");
			scanf("%d",&list);
			switch (list){
				case 1: // lista do curso 1
                    ordenacao(curso1, cont1);
					printf("\n=================================================================================================\n");
					printf("                                              Medicina");
					printf("\n=================================================================================================\n");
					lista(curso1,cont1);
					break;
				case 2: // lista do curso 2 
					printf("\n=================================================================================================\n");
					printf("                                             Psicologia");
					printf("\n=================================================================================================\n");
					lista(curso2,cont2);
					break;
				case 3: // lista do curso 3
					printf("\n=================================================================================================\n");
					printf("                                               Direito");
					printf("\n=================================================================================================\n");  
					lista(curso3,cont3);
					break;
				case 4: // lista do curso 4 
					printf("\n=================================================================================================\n");
					printf("                                         Engenharia Elétrica");
					printf("\n=================================================================================================\n");
					lista(curso4,cont4);
					break;
				case 5: // lista do curso 5
					printf("\n=================================================================================================\n");
					printf("                                         Engenharia Mecânica");
					printf("\n=================================================================================================\n");
					lista(curso5,cont5);
					break;
				case 6: // lista do curso 6
					printf("\n=================================================================================================\n");
					printf("                                      Engenharia da Computação");
					printf("\n=================================================================================================\n");
					lista(curso6,cont6);
					break;
				case 7: // sair
					printf ("\n");
					menu ();
					break;
				default:
				while(list<1 || list>7){
				printf("\nCódigo inválido!\nInsira um código válido:\n");
				scanf("%d",&list);}
				break;
					break;
					
				}
			break;
		
		case 3: // regulamento
			
		case 4: // chama a função de salvamento, finaliza a função menu e termina o programa
		
			salvar(curso1,cont1,nomes1,dados1);
			salvar(curso2,cont2,nomes2,dados2);
			salvar(curso3,cont3,nomes3,dados3);
			salvar(curso4,cont4,nomes4,dados4);
			salvar(curso5,cont5,nomes5,dados5);
			salvar(curso6,cont6,nomes6,dados6);
			
			printf("\n===========\n");
			printf("  Até logo!");
			printf("\n===========\n");
			
			system ("pause");
			return 0;
		break;
		default:
			while(alt<1 || alt>3){
				printf("\nCódigo inválido!\nInsira um código válido:\n");
				scanf("%d",&alt);}
				break;
			
}
}

int cadastro(struct dados *curso, int contador){  // cadastra os candidatos 
//(recebe o vetor do curso em que o usuário irá se cadastrar e até onde ele está preenchido)
    setlocale(LC_ALL,"portuguese");
    n_inscricao++; // incremento para o número de inscrição ser diferente
    int i;
    printf("- INSCRIÇÃO");
	printf("\n=================================================================================================\n");



    
    printf("\nDigite seu nome: "); // nome do candidato
    setbuf(stdin,NULL);
    scanf("%[^\n]s", &curso[contador].nome); 
    
    
    printf("\nIdade: "); // idade do candidato (se for menor que 15 anos é impossibilitado de fazer a inscrição)
    scanf("%d", &curso[contador].idade);
        while(curso[contador].idade <= 13 || curso[contador].idade>99){
        	printf("Idade inválida. Por favor, digite novamente.\n");
        	
        	printf("Idade: ");
            scanf("%d", &curso[contador].idade);    	
		}  
		
		if(curso[contador].idade >= 120){
			printf("                         Você não deveria está morto?\n"); // A não ser que seja um vampiro
		}
		
    printf("\nNota: "); // nota do candidato (maior ou igual que 0 e menor ou igual que 5000)
    scanf("%d", &curso[contador].nota);
        while(curso[contador].nota < 0 || curso[contador].nota > 5000){
        		
		
        	printf("\nNota inválida. Por favor, digite novamente.\n");
        	
        	printf("Nota: ");
            scanf("%d", &curso[contador].nota);
        
		}
		
	curso[contador].inscricao = n_inscricao;	//rebece o número de inscrição
	printf("\nNúmero de inscrição : %d\n", curso[contador].inscricao);
	
	printf("\n                                   Inscrição realizada com sucesso!\n");
	
printf ("\n=================================================================================================\n");

	printf("\nO que deseja fazer agora?\n");
	menu ();
	
}

int mostrador(struct dados *curso, int posicao){  //auxiliar a função lista -> função estética
setlocale(LC_ALL,"portuguese");
int i;


for(i=1;i<=posicao;i++){
	if(i<10){
		printf("   %dº            ",i); // se a posição possuir apenas um digito, serão imprimidos 3 espaços
	}
	else{
		printf("  %dº            ",i); //se a posição possuir dois digitos, serão impimidos dois espaços
	}
	
	if(curso[i].inscricao<10){
		printf("000%d          ",curso[i].inscricao); // se o numero de inscrição possuir apenas 1 digito, será impresso no formato 000X
	}
	
	if(curso[i].inscricao<100 && curso[i].inscricao>=10){ //se o numero de inscrição possuir dois digitos, será impresso no formato 00XX
		printf("00%d          ",curso[i].inscricao);
	}
	
	if(curso[i].inscricao<1000 && curso[i].inscricao>=100){ //se o numero de inscrição possuir três digitos, será impresso no formato 0XXX
		printf("0%d          ",curso[i].inscricao);
	}
	
	if(curso[i].inscricao>=1000){
		printf("%d      ",curso[i].inscricao);
	}
	if(curso[i].nota<10){
		printf("000%d     ",curso[i].nota); // se o numero de inscrição possuir apenas 1 digito, será impresso no formato 000X
	}
	
	if(curso[i].nota<100 && curso[i].nota>=10){ //se o numero de inscrição possuir dois digitos, será impresso no formato 00XX
		printf("00%d     ",curso[i].nota);
	}
	
	if(curso[i].nota<1000 && curso[i].nota>=100){ //se o numero de inscrição possuir três digitos, será impresso no formato 0XXX
		printf("0%d     ",curso[i].nota);
		
	}
	if(curso[i].nota>=1000){
		printf("%d     ",curso[i].nota);
	}
	printf("%d     %s\n",curso[i].idade,curso[i].nome);

}
}

int lista (struct dados *curso,int posicao){    //  imprime as lista de aprovados dos cursos

//(recebe o vetor do curso em que o usuário irá se cadastrar e até onde ele está preenchido)
setlocale(LC_ALL,"portuguese");
printf (" Posição    Nº de inscrição    Nota   Idade                     Nome completo \n");
printf ("=========  =================  ====== =======  ===================================================\n");

if(posicao<40){// se o vetor não estiver preenchido até a posição 40, irá mostrar a lista até onde foi preenchido
	mostrador(curso,posicao);}

if(posicao>=40){ //se o vetor tiver mais do que 40 elementos, mostrará apenas os 40 primeiros. 
	mostrador(curso,40);}
	
printf ("\n=================================================================================================\n");

printf("\nO que deseja fazer agora?\n"); // retorna ao menu
menu ();	
}


int ordenacao(struct dados curso[], int contador){ // ordena os vetores
// fazer por recursao 
        printf("Ordenando... %d\n", contador);

        int i , j , aux;

        for(i = 0; i < contador ; i++){

            for(j = 0; j < contador-1-i; j++){
                if(curso[i].nota >curso[i+1].nota){
					printf("Trocando...\n");
                    aux = curso[i].nota;
                    curso[i].nota = curso[i+1].nota;
                    curso[i+1].nota = aux;
                }
            }
  
        }

}

int salvar (struct dados *curso, int posicao, char *arqnomes, char *arqdados){ // salva as variaveis em arquivos

	FILE *arquivo;
	int i;
	arquivo = fopen(arqnomes,"w+");
	
	if(fopen==NULL){
		printf("Erro no salvamento dos dados\n");
	}
	
	for(i=1;i<=posicao;i++){
		printf("%d. funcionou\n",i);
		fprintf(arquivo,"%s\n",curso[i].nome);
	}
	
	fclose(arquivo);
	
	arquivo = fopen(arqdados,"w+");
	
	if(fopen==NULL){
		
		printf("Erro no salvamento dos dados\n");
	}
	
	for(i=1;i<=posicao;i++){
		printf("%d. funcionou\n",i);
		fprintf(arquivo,"%d %d %d\n",curso[i].nota,curso[i].inscricao,curso[i].idade);
	}
	fclose(arquivo);
	
}

int leitura(){ // lê os arquivos e os transforma de novo em variaveis
}


int main (){// introdução ao programa

	setlocale(LC_ALL,"portuguese");
	
	// introdução ao programa
	printf("===============================================================================\n");
	printf("Olá, seja bem-vindo ao portal de seleção da Universidade Federal Genérica (UFG)\n");
	printf("===============================================================================\n\n");
	
	printf("Aqui você pode realizar as seguintes operações:\n");
	
	// exemplos pra testes (excluir antes de acabar)
	strcpy(curso1[1].nome, "Leticia Maria Bezerra");
	strcpy(curso1[2].nome, "Lucas Fernandes Farias");
	strcpy(curso1[10].nome, "Josias Nascimento Martins");
	strcpy(curso1[39].nome, "Fernanda Nogueira Oliveira");
	strcpy(curso1[45].nome, "Roberta Rocha da Silva");
	

	curso1[1].idade=27;
	curso1[2].idade=17;
	curso1[10].idade=36;
	curso1[39].idade=19;
	curso1[45].idade=23;
	
	
	curso1[1].nota=2089;
	curso1[2].nota=370;
	curso1[10].nota=298;
	curso1[39].nota=3512;
	curso1[45].nota=90;
	
	
	curso1[1].inscricao=28;
	curso1[2].inscricao=349;
	curso1[10].inscricao=8;
	curso1[39].inscricao=12;
	curso1[45].inscricao=999;
	
	menu();
	
	
	
	return 0;
}
