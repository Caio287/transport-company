//
//  Copyright ao 2019 Grupo 4. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // biblioteca usada para setar a seed de um rand() 
#include <string.h>

#define MAX 100  // tamanho dos vetores de caracteres
#define MAX_A 1000  // quantidade de veiculos(ilimitado)
#define MAX_A2 10000  //quantidade de viagens(ilimitado)

//estrutura dos veiculos
typedef struct nomeempresa{
	
	int matricula;		
	char marca[MAX];
	char modelo[MAX];
	int dia,mes,ano;
	float custo;
	char tipov;
	
}veiculo;

//estrutura das viagens
typedef struct Nomeempresa{
	
	char tipo;
	int num;
	int pdia,pmes,pano;
	int sdia,smes,sano;
	char partida[MAX];
	char chegada[MAX];
	char condutor[MAX];
	float km;
	char gdescricao[MAX];
	int gdia,gmes,gano;
	char ghora[MAX];
	float gcusto;
	float custov;
	float consumov;
	
}viagem;

//estrutura das avaliacoes dos clientes
typedef struct rating{
	char nome[MAX];
	float nota;
	char comentario[250];
	int dia,mes,ano;
}avaliacao;

//funcao para alocar dinamicamente o vetor de veiculos
veiculo *alok(int n){
	
	veiculo *p;
	p = ( veiculo* )malloc(n *  sizeof(veiculo));
	if(p!=NULL){
		return p;
	}else{
		printf("\n|| Memoria insuficiente!\n");
		return NULL;
	}
	
}

//funcao para alocar dinamicamente o vetor de viagens
viagem *alok2(int n){
	
	viagem *p;
	p = ( viagem* )malloc(n *  sizeof(viagem));
	if(p!=NULL){
		return p;
	}else{
		printf("\n|| Memoria insuficiente!\n");
		return NULL;
	}
	
}

//funcao para alocar dinamicamente o vetor de avaliacoes
avaliacao *alok3(int n){
	
	avaliacao *p;
	p = ( avaliacao* )malloc(n *  sizeof(avaliacao));
	if(p!=NULL){
		return p;
	}else{
		printf("\n|| Memoria insuficiente!\n");
		return NULL;
	}
	
}

//funcao para abrir o ficheiro de veiculos
void abrirveiculo(FILE *veiculof, veiculo *info){
	INICIO:
	veiculof = fopen("veiculos.dat","rb");
	if(veiculof == NULL){
		printf("\nImpossivel abrir o arquivo veiculos\n");
		getchar();
		goto INICIO;
	}
	fread(info, sizeof(veiculo),MAX_A,veiculof);
	fclose(veiculof);
}

//funcao para abrir o vetor de viagens
void abrirviagens(FILE *viagemf, viagem *info2){
	INICIO2:
	viagemf = fopen("viagens.dat","rb");
	if(viagemf == NULL){
		printf("\n|| Impossivel abrir o arquivo viagens\n");
		getchar();
		goto INICIO2;
	}
	fread(info2, sizeof(viagem),MAX_A2,viagemf);
	fclose(viagemf);
}

void checktxt(FILE *exportf){
	INICIO10:
	exportf = fopen("Informacoes Salvas.txt","w");
	if(exportf == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO10;
	}
	fclose(exportf);
}

void criarnovab(FILE *file){
	KAPPA:
	file = fopen("Novas Viagens.dat","wb");
	if(file ==NULL){
		printf("\nImpossivel abrir o arquivo Novas Viagens.dat\n");
		getchar();
		goto KAPPA;
	}
	fclose(file);
}

void criarnovat(FILE *file){
	KAPPA2:
	file = fopen("Novas Viagens.txt","w");
	if(file ==NULL){
		printf("\nImpossivel abrir o arquivo Novas Viagens.txt \n");
		getchar();
		goto KAPPA2;
	}
	fclose(file);
}

//funcao para checar se todos os dados estao corretos 
// EX: Dias menores que 0  || Dias maiores que 31  ||  Matriculas e numero de viagens iguais
void checklist(viagem *info2,veiculo *info,int n,int n2){
	
	int i,j;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(info[i].matricula == info[j].matricula){
				if(i!=j){
				printf("\n|| O veiculo n%i tem o mesmo numero de matricula que o n%i",i+1,j+1);
				printf("\n|| Numero de matricula atual do veiculo n%d, mude aqui para:  ",j+1);
				scanf("%d",&info[j].matricula);
				}
			}
		}
		if(info[i].custo < 0 ){
			printf("\n|| O veiculo n%i tem seu custo negativo",i+1);
			printf("\n|| Mude aqui o seu custo:  ");
			scanf("%f",&info[i].custo);
		}
		if(info[i].dia < 0 || info[i].dia >31 || info[i].mes < 0 || info[i].mes > 12 || info[i].ano < 0){
			printf("\n|| A data do seu veiculo n%i esta incorreta",i+1);
			printf("\n|| Digite aqui a data corretamente(DD MM YYYY):  ");
			scanf("%d %d %d",&info[i].dia,&info[i].mes,&info[i].ano);
		}
	}
	
	for(i=0;i<n2;i++){
		for(j=0;j<n2;j++){
			if(info2[i].num == info2[j].num){
				if(i!=j){
				printf("\n|| O viagem n%i tem o mesmo numero que a n%i",i+1,j+1);
				printf("\n|| Numero de atual da viagem e n%d, mude aqui para:  ",j+1);
				scanf("%d",&info2[j].num);
				}
			}
		}
		if(info2[i].pdia < 0 || info2[i].pdia >31 || info2[i].pmes < 0 || info2[i].pmes >12 || info2[i].pano < 0){
			printf("\n|| A data de partida da sua viagem n%d esta incorreta",i+1);
			printf("\n|| Digite aqui a data corretamente(DD MM YYYY):  ");
			scanf("%d %d %d",&info2[i].pdia,&info2[i].pmes,&info2[i].pano);
		}
		if(info2[i].sdia < 0 || info2[i].sdia >31 || info2[i].smes < 0 || info2[i].smes >12 || info2[i].sano < 0){
			printf("\n|| A data de chegada da sua viagem n%d esta incorreta",i+1);
			printf("\n|| Digite aqui a data corretamente(DD MM YYYY):  ");
			scanf("%d %d %d",&info2[i].sdia,&info2[i].smes,&info2[i].sano);
		}
		if(info2[i].km < 0 ){
			printf("\n|| Os seus Km da viagem %d estao negativos, mude aqui:  ",i+1);
			scanf(" %f",info2[i].km);
		}
		if(info2[i].gdia < 0 || info2[i].gdia >31 || info2[i].gmes < 0 || info2[i].gmes >12 || info2[i].gano < 0){
			printf("\n|| A data do gasto da sua viagem n%d esta incorreta",i+1);
			printf("\n|| Digite aqui a data corretamente(DD MM YYYY):  ");
			scanf("%d %d %d",&info2[i].gdia,&info2[i].gmes,&info2[i].gano);
		}
	}
	
	printf("\n");
	printf("|| Todas as informacoes nos ficheiros estao corretas\n|| ");
	system("pause");
	system("cls");
	
}

// funcao para limpar o buffer
// ao alocar memoria com o malloc o buffer fica cheio de memoria "Lixo"
void limparbuffer(){
	char c;
	while((c=getchar()) != '\n' && c != EOF);
}

// funcao para randomizar um dado A de tipo float entre outro dado B tipo float
// usado para o calculo de acoes da empresa
float random(float a, float b){

	return((b-a)*((float)rand()/RAND_MAX)+a);
}

// calcula o custo de cada viagem com o preco do gasoleo e manutencao
int calculov(viagem *info2,int n){
	
	int i,n2,j,n8=0;
	float maiorv=0;
	char a ='A',b = 'B',c = 'C',d = 'D',e = 'E', c2='s';
	
	for(i=0;i<n;i++)
	info2[i].consumov = info2[i].km / 1.40;
	
	for(i=0;i<n;i++){
		if(a == info2[i].tipo){
			info2[i].custov = info2[i].consumov + (info2[i].km/0.1);
		}
		else if(b == info2[i].tipo){
			info2[i].custov = info2[i].consumov + (info2[i].km/0.2);
		}
		else if(c == info2[i].tipo){
			info2[i].custov = info2[i].consumov + (info2[i].km/0.3);
		}
		else if(d == info2[i].tipo){
			info2[i].custov = info2[i].consumov + (info2[i].km/0.4);
		}
		else if(e == info2[i].tipo){
			info2[i].custov = info2[i].consumov + (info2[i].km/0.6);
		}
		if(info2[i].custov+info2[i].gcusto>n8){
			n8=i;
		}
	}
	
	/*

GASOLEO == 1.40 / L

CUSTO MANUTENCAO POR TIPO DE
VEICULO: A  0.1
		 B  0.2
		 C  0.3
		 D  0.4
		 E  0.6

*/
return n8;
}

// chama o menu principal e o menu do cliente
int menu(){
	
	int mani;
	
	system("cls");
	printf("\n");
	printf("|| O que desejas fazer ? \n");
	printf("|| 1 - Visualizar Banco de Dados \n|| 2 - Atualizar Dados de Veiculos \n|| 3 - Calcular Viagens \n|| 4 - Custos Entre Datas \n|| 5 - Criar novo Ficheiro para Viagens \n|| 6 - Atualizar a Lista de Veiculos \n|| 7 - Atuais Acoes da Empresa \n|| 8 - Informacoes legais \n|| 9 - Menu para clientes \n||\n");
	printf("|| Escreva sua opcao aqui (0 para sair do programa):  ");
	scanf("%i",&mani);
	
	return mani;
}

// menu do cliente
int menuc(){
	int mani;
	system("cls");
	printf("\n");
	printf("|| O que desejas fazer ? \n");
	printf("|| 1 - Avaliacoes dos Clientes \n|| 2 - Central de Ajuda \n|| 3 - Tabela de precos e informacoes \n|| 4 - Acoes atuais da empresa \n||\n");
	printf("|| Escreva sua opcao aqui (0 para voltar ao menu):  ");
	scanf("%i",&mani);
	return mani;
}

/*
int pgs(int a,int n){
	a++;
	int j=1;
	if(a==500){
		printf("\n|| Pagina %i de %i, Aperte enter para continuar\n|| ",j,n/500);
		system("pause");
		j++;
		a=0;
	}
	return a;
}
*/

// mostra os dados do ficheiro para o usuario com filtros
void lerdados(veiculo *info, int n , viagem *info2, int n2,FILE *file){
	
	INICIO13:
	file = fopen("Informacoes Salvas.txt","a");
	if(file == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO13;
	}
	
	int i,j=0,mani,mani2,mani3,k,x;
	char c ='s' , c2 = 'S';
	char c3='s',c4,c5,c6,c7,c8,c9,c10[MAX],c70;
	int a2=0;
	
	do{
	system("cls");
	printf("\n|| Voce deseja gravar as informacoes em um ficheiro txt (s/n)?  ");
	scanf(" %c",&c6);
	fprintf(file,"\n||\n||\n|| Visualizacao de dados com filtro -----------------------------------\n");
	system("cls");
	printf("\n|| O que desejas visualizar ? \n");
	printf("|| 1 - Informacoes dos veiculos \n|| 2 - Informacoes da viagem \n||\n");
	printf("|| Escreva sua opcao aqui (0 para voltar ao menu):  ");
	scanf("%i",&mani);
	
	if(mani == 0){
		printf("\n|| Aperte enter para sair \n\n|| ");
		system("pause");
		system("cls");
		return;
	}
	else if(mani == 1){
		system("cls");
		printf("\n|| Existe(m) %i veiculos na sua empresa \n|| 1 - visualizar algum especifico \n|| 2 - listar todos os veiculos  ",n);
		printf("\n||\n|| O que desejas fazer ?  ");
		scanf("%i",&mani2);
		
		switch(mani2){
			case 1:
			printf("|| Qual o numero do veiculo que voce deseja visualizar ?  ");
			scanf("%i",&mani3);
			mani3--;
			if(mani3<=0){
				mani3 = 0;
			}
			printf("\n|| Dados do veliculo n%i \n",mani3+1);
			printf("|| Matricula:  %d ",info[mani3].matricula);
			printf("\n|| Marca:  %s ",info[mani3].marca);
			printf("\n|| Modelo:  %s",info[mani3].modelo);
			printf("\n|| Data de aquisicao:  %i/%i/%i ",info[mani3].dia,info[mani3].mes,info[mani3].ano);
			printf("\n|| Tipo:  %c",info[mani3].tipov);
			printf("\n|| Custo:  %.2f\n\n",info[mani3].custo);
			if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| O veiculo: %i tem a matricula: %d, a marca: %s, comprado no dia: %i/%i/%i, tipo: %c, e custou: %.2f",mani3+1,info[mani3].matricula,info[mani3].marca,info[mani3].dia,info[mani3].mes,info[mani3].ano,info[mani3].tipov,info[mani3].custo);
			}
			break;
			
			case 2:
			printf("\n|| Filtros ");
			printf("\n|| Voce deseja ver de todos os tipo de veiculos(s/n)?  ");
			scanf(" %c",&c3);	
			
			a2=1;
			j=0;
			if(c3=='s'||c3=='S'){
			for(i=0;i<n;i++){
			j++;
			if(info[i].matricula != NULL){
			printf("\n|| Dados do veliculo n%i \n",i+1);
			printf("|| Matricula: %d ",info[i].matricula);
			printf("\n|| Marca: %s ",info[i].marca);
			printf("\n|| Modelo:  %s",info[i].modelo);
			printf("\n|| Data de aquisicao:  %i/%i/%i ",info[i].dia,info[i].mes,info[i].ano);
			printf("\n|| Tipo:  %c",info[i].tipov);
			printf("\n|| Custo:  %.2f\n\n",info[i].custo);
			if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n|| O veiculo: %i tem a matricula: %d, a marca: %s, comprado no dia: %i/%i/%i, tipo: %c, e custou: %.2f",i+1,info[i].matricula,info[i].marca,info[i].dia,info[i].mes,info[i].ano,info[i].tipov,info[i].custo);
			}
				}
				if(j==500){
					printf("\n|| Pagina %i de %i, Aperte enter para continuar\n|| ",a2,n/500);
					system("pause");
					j=0;
					a2++;
				}
			}
		}else{
				printf("\n|| Qual o tipo de veiculo que voce deseja ver ?");
				printf("\n|| 1 - A");
				printf("\n|| 2 - B");
				printf("\n|| 3 - C");
				printf("\n|| 4 - D");
				printf("\n|| 5 - E");
				printf("\n||\n|| Escreva aqui o tipo do seu veiculo:  ");
				scanf(" %c",&c4);
				for(i=0;i<n;i++){
			if(info[i].matricula != NULL && info[i].tipov == c4){
			printf("\n|| Dados do veliculo n%i \n",i+1);
			printf("|| Matricula: %d ",info[i].matricula);
			printf("\n|| Marca: %s ",info[i].marca);
			printf("\n|| Modelo:  %s",info[i].modelo);
			printf("\n|| Data de aquisicao:  %i/%i/%i ",info[i].dia,info[i].mes,info[i].ano);
			printf("\n|| Tipo:  %c",info[i].tipov);
			printf("\n|| Custo:  %.2f\n\n",info[i].custo);
			if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n|| O veiculo: %i tem a matricula: %d, a marca: %s, comprado no dia: %i/%i/%i, tipo: %c, e custou: %.2f",i+1,info[i].matricula,info[i].marca,info[i].dia,info[i].mes,info[i].ano,info[i].tipov,info[i].custo);
			}
					}
				}
			}
			break;
		}
	}
	else if(mani == 2){
		system("cls");
		printf("\n|| Existe(m) %i viagens feitas na sua empresa \n|| 1 - Visualizar uma viagem especifica \n|| 2 - Listar todos as viagens",n2);
		printf("\n||\n|| O que dssejas fazer ?  ");
		scanf("%i",&mani2);
		switch(mani2){
			case 1:
			printf("|| Qual a da viagem que voce deseja visualizar ?  ");
			scanf("%i",&mani3);
			mani3--;
			if(mani3<=0){
				mani3 = 0;
			}
			printf("\n|| Dados do veliculo n%i \n",mani3+1);
			printf("|| Numero da viagem: %d ",info2[mani3].num);
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[mani3].partida, info2[mani3].pdia, info2[mani3].pmes, info2[mani3].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[mani3].chegada, info2[mani3].sdia, info2[mani3].smes, info2[mani3].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[mani3].tipo);
			printf("\n|| Nome do condutor: %s ",info2[mani3].condutor);
			printf("\n|| Kilometros rodados:  %d",info2[mani3].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[mani3].custov);
			if(info2[mani3].gcusto != 0.0){
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[mani3].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[mani3].gdia,info2[mani3].gmes,info2[mani3].gano);
			printf("\n|| Hora do gasto:  %s ",info2[mani3].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[mani3].gcusto);
			if(c6 =='s' && info2[mani3].gcusto != 0.0 || c6 =='S' && info2[mani3].gcusto != 0.0 ){
		   	//	fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, e o custo total(Manutencao e Gasoleo): %.2f",mani3+1,info2[mani3].num,info2[mani3].partida, info2[mani3].pdia, info2[mani3].pmes, info2[mani3].pano,info2[mani3].chegada, info2[mani3].sdia, info2[mani3].smes, info2[mani3].sano,info2[mani3].tipo,info2[mani3].condutor,info2[mani3].km,info2[mani3].custov);
		   		fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",mani3+1,info2[mani3].num,info2[mani3].partida, info2[mani3].pdia, info2[mani3].pmes, info2[mani3].pano,info2[mani3].chegada, info2[mani3].sdia, info2[mani3].smes, info2[mani3].sano,info2[mani3].tipo,info2[mani3].condutor,info2[mani3].km,info2[mani3].custov,info2[mani3].gdescricao,info2[mani3].gdia,info2[mani3].gmes,info2[mani3].gano,info2[mani3].ghora,info2[mani3].gcusto);
			}else if(c6 =='s' || c6 =='S'){
			//	fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",mani3+1,info2[mani3].num,info2[mani3].partida, info2[mani3].pdia, info2[mani3].pmes, info2[mani3].pano,info2[mani3].chegada, info2[mani3].sdia, info2[mani3].smes, info2[mani3].sano,info2[mani3].tipo,info2[mani3].condutor,info2[mani3].km,info2[mani3].custov,info2[mani3].gdescricao,info2[mani3].gdia,info2[mani3].gmes,info2[mani3].gano,info2[mani3].ghora,info2[mani3].gcusto);
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",mani3+1,info2[mani3].num,info2[mani3].partida, info2[mani3].pdia, info2[mani3].pmes, info2[mani3].pano,info2[mani3].chegada, info2[mani3].sdia, info2[mani3].smes, info2[mani3].sano,info2[mani3].tipo,info2[mani3].condutor,info2[mani3].km,info2[mani3].custov);
			}
		}else{
			printf("\n\n");
		}
			
			break;
			case 2:
				
			printf("\n|| Filtros");
			printf("\n|| Voce deseja visualizar todas as informacoes(s/n)?  ");
			scanf(" %c",&c5);
			
			if(c5=='s'|| c5 =='S'){
			system("cls");
			j=0;
			a2=1;
			for(i=0;i<n2;i++){
			j++;
			if(info2[i].num != NULL){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[i].custov);
			if(info2[i].gcusto != 0.0){
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[i].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[i].gdia,info2[i].gmes,info2[i].gano);
			printf("\n|| Hora do gasto:  %s ",info2[i].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[i].gcusto);
			if(c6 =='s' && info2[i].gcusto != 0.0 || c6 =='S' && info2[i].gcusto != 0.0 ){
		   		fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov,info2[i].gdescricao,info2[i].gdia,info2[i].gmes,info2[i].gano,info2[i].ghora,info2[i].gcusto);
			}else if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov);
							}
						}else{
						printf("\n\n");
					}
				}
					if(j==500){
					printf("\n|| Pagina %i de %i, Aperte enter para continuar\n|| ",a2,n2/500);
					system("pause");
						a2++;
						j=0;	
				}
			}
		}else{
			int k3;
				printf("\n|| O que voce deseja filtrar ?");
				printf("\n|| 1 - Nome de Condutor");
				printf("\n|| 2 - Se a viagem teve custo extra");
				printf("\n|| 3 - Local de partida");
				printf("\n|| 4 - Local de chegada");
				printf("\n|| 5 - Tipo de veiculo");
				printf("\n||\n|| Digite aqui sua opcao:  ");
				scanf("%i",&k);
				
				switch(k){
					case 1:
						system("cls");
						printf("\n|| Qual o nome do condutor?  ");
						limparbuffer();
						gets(c10);
			
			for(i=0;i<n2;i++){
			if(info2[i].num != NULL && (strcmp (info2[i].condutor, c10) ==0 )){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[i].custov);
			if(info2[i].gcusto != 0.0){
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[i].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[i].gdia,info2[i].gmes,info2[i].gano);
			printf("\n|| Hora do gasto:  %s ",info2[i].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[i].gcusto);
			if(c6 =='s' && info2[i].gcusto != 0.0 || c6 =='S' && info2[i].gcusto != 0.0 ){
		   		fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov,info2[i].gdescricao,info2[i].gdia,info2[i].gmes,info2[i].gano,info2[i].ghora,info2[i].gcusto);
			}   else if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov);
				}
						}else{
						printf("\n\n");
					}
				}
			}
		
						
					break;
					case 2:
					printf("\n|| 1 - Viagens com custo extra");
					printf("\n|| 2 - Viagens sem custo extra");
					printf("\n||\n|| Digite aqui dua opcao:  ");
					scanf(" %i",&x);
						
						if(x==1){
						for(i=0;i<n2;i++){
			if(info2[i].num != NULL&&info2[i].gcusto!=0.0){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[i].custov);
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[i].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[i].gdia,info2[i].gmes,info2[i].gano);
			printf("\n|| Hora do gasto:  %s ",info2[i].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[i].gcusto);
			if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov, info2[i].gdescricao,info2[i].gdia,info2[i].gmes,info2[i].gano,info2[i].ghora,info2[i].gcusto);
					}	
		 	}
			}}else if(x==2){
				for(i=0;i<n2;i++){
			if(info2[i].num != NULL&&info2[i].gcusto==0.0){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f\n",info2[i].custov);
			if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov);
						}
					}
				}
			}
					break;
					case 3:
						system("cls");
						printf("\n|| Qual o local de partida?  ");
						limparbuffer();
						scanf(" %s",&c10);
			
			for(i=0;i<n2;i++){
			if(info2[i].num != NULL && strcmp(c10, info2[i].partida) == 0){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[i].custov);
			if(info2[i].gcusto != 0.0){
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[i].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[i].gdia,info2[i].gmes,info2[i].gano);
			printf("\n|| Hora do gasto:  %s ",info2[i].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[i].gcusto);
			if(c6 =='s' && info2[i].gcusto != 0.0 || c6 =='S' && info2[i].gcusto != 0.0 ){
		   		fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov, info2[i].gdescricao,info2[i].gdia,info2[i].gmes,info2[i].gano,info2[i].ghora,info2[i].gcusto);
			}   else if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov);
				}
						}else{
						printf("\n\n");
					}
				}
			}
					break;
					case 4:
					system("cls");
						printf("\n|| Qual o local de chegada?  ");
						limparbuffer();
						scanf(" %s",&c10);
			
			for(i=0;i<n2;i++){
			if(info2[i].num != NULL && strcmp(c10, info2[i].chegada) == 0){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[i].custov);
			if(info2[i].gcusto != 0.0){
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[i].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[i].gdia,info2[i].gmes,info2[i].gano);
			printf("\n|| Hora do gasto:  %s ",info2[i].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[i].gcusto);
		   		fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov, info2[i].gdescricao,info2[i].gdia,info2[i].gmes,info2[i].gano,info2[i].ghora,info2[i].gcusto);
						}else{
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[mani3].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov);
						printf("\n\n");
					}
				}
			}
					break;
					case 5:
					system("cls");
					printf("\n|| Tipos de veiculo a filtrar");
					printf("\n|| 1 - A");
					printf("\n|| 2 - B");
					printf("\n|| 3 - C");
					printf("\n|| 4 - D");
					printf("\n|| 5 - E");
					printf("\n||\n|| Digite aqui o tipo de veiculo(caracter):  ");
					scanf(" %c",&c70);
					
					for(i=0;i<n2;i++){
			if(info2[i].num != NULL && info2[i].tipo == c70 ){
			printf("\n|| Dados da viagem n%i ",i+1);
			printf("\n|| Numero da viagem: %d ",info2[i].num);	
			printf("\n|| Partido de: %s no dia:  %i/%i/%i",info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano);
			printf("\n|| Chegado em: %s no dia:  %i/%i/%i",info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano);
			printf("\n|| Tipo de veiculo da viagem: %c",info2[i].tipo);
			printf("\n|| Nome do condutor: %s ",info2[i].condutor);
			printf("\n|| Kilometros rodados:  %.2f",info2[i].km);
			printf("\n|| Custo total (Manutencao e Gasoleo):  %.2f",info2[i].custov);
			if(info2[i].gcusto != 0.0){
			printf("\n|| Gastos --");
			printf("\n|| Descricao do gasto:  %s ",info2[i].gdescricao);
			printf("\n|| Data do gasto:  %i/%i/%i ",info2[i].gdia,info2[i].gmes,info2[i].gano);
			printf("\n|| Hora do gasto:  %s ",info2[i].ghora);
			printf("\n|| Custo:  %.2f \n\n",info2[i].gcusto);
			if(c6 =='s' && info2[i].gcusto != 0.0 || c6 =='S' && info2[i].gcusto != 0.0 ){
		   		fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f, teve gastos em: %s, no dia %i/%i/%i as %s e custou: %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov,info2[i].gdescricao,info2[i].gdia,info2[i].gmes,info2[i].gano,info2[i].ghora,info2[i].gcusto);
			}   else if(c6 =='s' || c6 =='S'){
				fprintf(file,"\n||\n|| A viagem: %i de numero: %d, partido de: %s no dia %i/%i/%i, chegado em: %s no dia %i/%i/%i, com o tipo de veiculo: %c, nome do condutor: %s, fez: %.2f Km, e o custo total(Manutencao e Gasoleo): %.2f",i+1,info2[i].num,info2[i].partida, info2[i].pdia, info2[i].pmes, info2[i].pano,info2[i].chegada, info2[i].sdia, info2[i].smes, info2[i].sano,info2[i].tipo,info2[i].condutor,info2[i].km,info2[i].custov);
				}
						}else{
						printf("\n\n");
					}
				}
			}
					break;
				}
			
			}
			break;
		}
	}
	
	printf("\n|| Deseja visualizar mais alguma informacao (s/n)?  ");
	scanf(" %c",&c);
 }while(c == 's' || c== 'S');
	
	printf("\n\n|| ");
	system("pause");
	fclose(file);
}

// funcao para a atualizacao de dados de veiculos
// EX: mudar a matricula ou mudar o modelo
int mudardadosv(veiculo *info, int n,FILE *file){
	
	INICIO15:
	file = fopen("Informacoes Salvas.txt","a");
	if(file == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO15;
	}
	
	int i,j,mani=0,mani2,mani3=0,k;
	char c,c2 = 's',c3;
	do{
	system("cls");
	printf("\n");
	printf("|| 1 - Matricula \n|| 2 - Marca \n|| 3 - Modelo \n|| 4 - Data da aquisicao \n|| 5 - Custo \n|| 6 - Tipo \n|| 7 - Remover veiculo \n|| 8 - Adcionar veiculo \n||\n");
	printf("|| Escreva sua opcao aqui (0 para ir ao menu):  ");
	scanf("%i",&mani2);
	
	printf("\n|| Desejas salvar as novas informacoes em um ficheiro (s/n)?  ");
	scanf(" %c",&c3);
	if(c3=='s'||c3=='S'){
		fprintf(file,"\n||\n||\n|| Dados atualizados de veiculos -----------------------------------");
	}
	
	if(mani2 <= 0 ){
		printf("||\n|| Aperte enter para sair ao menu!\n\n");
		system("pause");
		system("cls");
		return 0;
	}
	
	if(mani2!=8){
	printf("||\n|| Digite o numero do seu veiculo para atualizar suas informacoes(Voce tem %i veiculos):  ",n+1);
	scanf("%i",&mani);
	mani--;
	}
	if(mani<=0){
		mani= 0;	
	}
	
	if(mani2 == 1){
		printf("\n|| A sua matricula atual desse veiculo e: %i ",info[mani].matricula);
		printf("\n|| Digite a nova matricula:  ");
		scanf("%i",&info[mani].matricula);
		if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| O novo numero de matricula do veiculo %i e: %d",mani+1,info[i].matricula);
		}
	}
	else if(mani2 == 2){
		printf("\n|| A marca atual desse veiculo e: %s ",info[mani].marca);
		printf("\n|| Digite a nova marca:  ");
		scanf(" %s",info[mani].marca);
		if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| A nova marca do veiculo %i e: %d",mani+1,info[i].marca);
		}
	}
	else if(mani2 == 3){
		printf("\n|| O modelo atual desse veiculo e: %s ",info[mani].modelo);
		printf("\n|| Digite o novo modelo(Carro/Caminhao/Caminhonete/Moto):  ");
		scanf(" %s",info[mani].modelo);
		if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| O novo modelo do veiculo %i e: %d",mani+1,info[i].modelo);
		}
	}
	else if(mani2 == 4){
		
		nov:
		printf("\n|| A data de aquisicao atual do seu veiculo e: %i/%i/%i ",info[mani].dia,info[mani].mes,info[mani].ano);
		printf("\n|| Digite a nova data de aquisicao (DD MM YYYY):  ");
		scanf("%i %i %i", &info[mani].dia,&info[mani].mes,&info[mani].ano);
		
		if(info[mani].dia > 31 || info[mani].dia < 0 || info[mani].mes > 12 || info[mani].mes < 0 || info[mani].ano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||");
			goto nov;
		}
		
		if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| A nova data aquisicao do veiculo %i e: %d/%d/%d",mani+1,info[mani].dia,info[mani].mes,info[mani].ano);
		}
		
	}
	else if(mani2 == 5){
		no1:
		printf("\n|| O custo atual desse veiculo e: %.2f ",info[mani].custo);
		printf("\n|| Digite o novo custo(Euro):  ");
		scanf("%f",&info[mani].custo);
		if(info[mani].custo<=0){
			goto no1;
		}
		if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| O novo custo de aquisicao do veiculo %i e: %d",mani+1,info[mani].custo);
		}
	}
	else if(mani2 == 6){
		
		nov2:
		printf("\n|| O tipo atual desse veiculo e: %c ",info[mani].tipov);
		printf("\n|| Digite o novo tipo(A,B,C,D,E):  ");
		scanf(" %c",&info[mani].tipov);
		if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| O novo tipo do veiculo %i e: %c",mani+1,info[mani].tipov);
		}
		
	}
	else if(mani2 == 7){
		printf("\n|| O veiculo atual e o: %i ",mani+1);
		printf("\n|| Deseja remover todos os seus dados (s/n):  ");
		scanf(" %c",&c);
		if(c == 's' || c == 'S'){
			info[mani].matricula = '0';
			info[mani].marca[1] = NULL;
			info[mani].modelo[1] = NULL;
			info[mani].tipov = '0';
			info[mani].dia = 0;
			info[mani].mes = 0;
			info[mani].ano = 0;
			info[mani].custo = 0.0;
			if(c3=='s'||c3=='S'){
			fprintf(file,"\n||\n|| O veiculo %d foi removido da sua tropa",mani+1);
			}
		}
	}
	else if(mani2==8){
		printf("\n|| Digite a quantidade de veiculos que voce quer adcionar:  ");
		scanf("%i",&k);
		mani3=k+n+1;
		i=n+1;
		// n = 1, mani3 = 1, i = 1; 
		do{
			printf("\n|| Digite a matricula do veiculo %i:  ",i+1);
			scanf("%i",&info[i].matricula);
			printf("|| Digite a marca do veiculo %i:  ",i+1);
			scanf(" %s",info[i].marca);
			printf("|| Digite o modelo do veiculo %i (Carro/Caminhao/Caminhonete/Moto):  ",i+1);
			scanf(" %s",info[i].modelo);
			printf("|| Digite o tipo do veiculo %i (A,B,C,D,E):  ",i+1);
			scanf(" %c",&info[i].tipov);
			nov10:
			printf("|| Digite a data de aquisicao do veiculo %i (DD MM YYYY):  ",i+1);
			scanf("%i %i %i",&info[i].dia,&info[i].mes,&info[i].ano);
			if(info[i].dia > 31 || info[i].dia < 0 || info[i].mes > 12 || info[i].mes < 0 || info[i].ano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||");
			goto nov10;
			}
			no2:
			printf("|| Digite o custo do veiculo %i (Euro):  ",i+1);
			scanf("%f",&info[i].custo);
			if(info[mani].custo<=0){
			goto no2;
			}
			if(c3=='s'||c3=='S'){
				fprintf(file,"\n||\n|| O novo veiculo: %i tem a matricula: %d, a marca: %s, comprado no dia: %i/%i/%i, tipo: %c, e custou: %.2f",i+1,info[i].matricula,info[i].marca,info[i].dia,info[i].mes,info[i].ano,info[i].tipov,info[i].custo);
		}
		i++;
		}while(i!=mani3);
	}
	
	printf("\n|| Deseja atualizar mais alguma informacao (s/n)?  ");
	scanf(" %c",&c2);
	}while(c2 == 's' || c2 == 'S' );
		
	printf("\n\n|| ");
	system("pause");
	fclose(file);
	return mani3;
	
}

// calcula o custo/custo medeio de cada viagem e pode ser considerado custos adcionais, assim como o custo total da frota
void custosviagem(viagem *info, int n,int n2,int n3,FILE *file){
	
	INICIO16:
	file = fopen("Informacoes Salvas.txt","a");
	if(file == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO16;
	}
	
	int i,j,mani,mani2;
	char c4;
	float custototal=0;
	float acusto=0,bcusto=0,ccusto=0,dcusto=0,ecusto=0;
	int avig=0, bvig=0, cvig=0, dvig=0, evig=0;
	float agastom=0,bgastom=0,cgastom=0,dgastom=0,egastom=0;
	int maiorv;
	char a ='A',b = 'B',c = 'C',d = 'D',e = 'E', c2='s',c3;
	
	// gasoleo gcusto manutencao = custo medio se c4 = s
	
	printf("\n|| Voce quer considerar gastos adcionais (s/n)?  ");
	scanf(" %c",&c4);
	printf("|| Voce quer salvar esses dados em um ficheiro (s/n)?  ");
	scanf(" %c",&c3);
	if(c3=='s' || c3=='S'){
		fprintf(file,"\n||\n||\n|| Custos da viagem -----------------------------------");
	}
	
	for(i=0;i<n;i++){
		
		custototal = custototal + info[i].gcusto + info[i].custov;
		
		if(a == info[i].tipo){
			if(c4 == 's' || c4 == 'S'){
				acusto = acusto+ info[i].gcusto+info[i].custov;
		}else{
			acusto += info[i].custov;
		}
			avig++;
		}
		else if(b == info[i].tipo){
			if(c4 == 's' || c4 == 'S'){
				bcusto = bcusto+ info[i].gcusto+info[i].custov;
		}else{
			bcusto+= info[i].custov;
		}
			bvig++;
		}
		else if(c == info[i].tipo){
			if(c4 == 's' || c4 == 'S'){
				ccusto =ccusto+ info[i].gcusto+info[i].custov;
		}else{
			ccusto+= info[i].custov;
		}
			cvig++;
		}
		else if(d == info[i].tipo){
			if(c4 == 's' || c4 == 'S'){
				dcusto= dcusto+ info[i].gcusto+info[i].custov;
		}else{
			dcusto+= info[i].custov;
		}
			dvig++;
		}
		else if(e == info[i].tipo){
			if(c4 == 's' || c4 == 'S'){
				ecusto=ecusto+ info[i].gcusto+info[i].custov;
		}else{
			ecusto+= info[i].custov;
		}
			evig++;
		}
	}
	
	// termino do calculo medio
	// galoseo manu gcusto 
	if(c4 == 's'|| c4=='S'){
		agastom=acusto/3;
		bgastom=bcusto/3;
		cgastom=ccusto/3;
		dgastom=dcusto/3;
		egastom=ecusto/3;
	}else{
		agastom=acusto/2;
		bgastom=bcusto/2;
		cgastom=ccusto/2;
		dgastom=dcusto/2;
		egastom=ecusto/2;
	}
	
	
	printf("\n|| O valor total de custos nas viagens das tropas foi: %.2f ",custototal);
	printf("\n|| A viagem com o maior custo foi a n%i",n3);
	printf("\n\n|| Voce deseja ver os custos para cada tipo de veiculo (s/n) ?  ");
	scanf(" %c",&c2);
	if(c2 == 's' && c3 != 's' || c2 == 'S' && c3 != 'S'){
		printf("\n||O Tipo A gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",acusto,avig,agastom);
		printf("\n||O Tipo B gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",bcusto,bvig,bgastom);
		printf("\n||O Tipo C gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",ccusto,cvig,cgastom);
		printf("\n||O Tipo D gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",dcusto,dvig,dgastom);
		printf("\n||O Tipo E gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",ecusto,evig,egastom);
	}else if(c2 == 's' && c3 == 's' || c2 == 'S' && c3 == 'S'){
		fprintf(file,"\n||O Tipo A gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",acusto,avig,agastom);
		fprintf(file,"\n||O Tipo B gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",bcusto,bvig,bgastom);
		fprintf(file,"\n||O Tipo C gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",ccusto,cvig,cgastom);
		fprintf(file,"\n||O Tipo D gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",dcusto,dvig,dgastom);
		fprintf(file,"\n||O Tipo E gastou no total: %.2f em um total de %i viagens, com um custo medio de: %.2f",ecusto,evig,egastom);
	}
	
	printf("\n\n|| ");
	system("pause");
	fclose(file);
}

// funcao para procurar uma viagem feita entre duas datas definidas pelo usuario
void custodata(viagem *info2,int n,FILE *file){
	
	INICIO17:
	file = fopen("Informacoes Salvas.txt","a");
	if(file == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO17;
	}
	
	system("cls");
	int i,j,mani;
	int dia2,mes2,ano2,dia,mes,ano;
	float custototal=0.0,b[MAX_A2];
	int a=0;
	char c3,c;
	
	printf("\n|| Custo entre datas");
	printf("\n|| Voce deseja salvar os dados em um ficheiro (s/n)?  ");
	scanf(" %c",&c);
	if(c=='s'||c=='S'){
		fprintf(file,"\n||\n||\n|| Custo entre datas -----------------------------------");
	}
	
	nov3:
	printf("\n|| Insira a primeira data(DD MM YYYY):  ");
	scanf("%i %i %i)",&dia, &mes, &ano);
	if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || ano < 1){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE \n||");
			goto nov3;
		}
		
	nov4:
	printf("|| Insira a segunda data(DD MM YYYY):  ");
	scanf("%i %i %i",&dia2, &mes2, &ano2);
	if(dia2 > 31 || dia2 < 1 || mes2 > 12 || mes2 < 1 || ano2 < 1){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE \n||");
			goto nov4;
		}
		
	printf("\n|| Voce deseja ver as viagens que nao estao nesses parametros (s/n) ?  ");
	scanf(" %c",&c3);
	
	if(c=='s'||c=='S'){
		fprintf(file,"\n|| Viagens entre as datas %i/%i/%i e %i/%i/%i ",dia,mes,ano,dia2,mes2,ano2);
	}
	
	for(i=0; i<MAX_A2 ;i++){
	if(c3=='s'||c3=='S'){
	if(dia < info2[i].pdia || mes < info2[i].pmes || ano < info2[i].pano || dia > info2[i].pdia || mes < info2[i].pmes || ano < info2[i].pano || dia > info2[i].pdia || mes > info2[i].pmes || ano < info2[i].pano){
		printf("\n|| A viagem n%i nao esta nos parametros",i+1);
		if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| A viagem n%i nao esta nos parametros",i+1);
			}
		}
	}
	else if(dia >= info2[i].pdia && mes >= info2[i].pmes && ano >= info2[i].pano   &&   info2[i].sdia <= dia2 && info2[i].smes <= mes2 && info2[i].sano <= ano2){
		printf("\n|| A viagem n%i esta nos parametros e teve como gasto total:  %.2f",i+1, b[i] = info2[i].gcusto + info2[i].custov);
		b[i]=0;
		a++;
		custototal = custototal+info2[i].gcusto+info2[i].custov;
		if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| A viagem n%i esta nos parametros e teve como gasto total:  %.2f",i+1, b[i] = info2[i].gcusto + info2[i].custov);
			}
		}
	}
	
	if(a!=0){
	printf("\n||\n|| O numero de viagens entre essas datas foram: %i e o custo total foi igual a: %.2f",a,custototal);
	if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| O numero de viagens entre essas datas foram: %i e o custo total foi igual a: %.2f",a,custototal);
	}
	}else if(a==0){
		printf("\n||\n|| Nao existe viagens entre essas datas");
	if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| Nao existe viagens entre essas datas");
	}
	}
	
	printf("\n\n|| ");
	system("pause");
	fclose(file);
}

// escreve dentro do arquivo novas viagens para pessoas sem conexao com internet
void criararquivo(viagem *info, int n, FILE *viagemn,FILE *file){
	
	int i,n2,j,b,k;
	int mat;
	int dia,mes,ano;
	char hora[MAX];
	char c2,c3;
		
		system("cls");
		printf("\n|| Menu de criacao de arquivos ");
		printf("\n|| Voce deseja usar um ficheiro binario (s/n)?  ");
		scanf(" %c",&c3);
		
		if(c3=='s'||c3=='S'){
			
		INICIO3:
		viagemn = fopen("Novas Viagens.dat","ab");
		if(viagemn == NULL){
		printf("\n|| Impossivel abrir o arquivo Novas Viagens.dat\n");
		getchar();
		goto INICIO3;
		}
			
		}else if(c3=='n'||c3=='N'){
			
		INICIO20:
		file = fopen("Novas viagens.txt","a");
		if(file == NULL){
		printf("\n|| Impossivel abrir o arquivo Novas Viagens.txt\n");
		getchar();
		goto INICIO20;
		}
			
		}
		
		printf("||\n|| Digite quantas viagens voce deseja registrar:  ");
		scanf("%i",&k);
		
		n2=k+n+1;
		i=n+1;
		j = MAX_A2;
		// n=5 n2=1 || i=5 n2=6
		do{
			printf("\n|| Dados da viagem n%i",i+1);
			// printf("|| Numero da viagem:  ");
			// scanf("%d",&info[i].num);
			if(c3=='n'||c3=='N'){
				printf("\n|| Digite aqui a matricula do veiculo:  ");
				scanf("%d",&mat);
				j++;
				info[i].num = j;
				nov10:
				printf("|| Dia da emicao do arquivo(DD MM YYYY):  ");
				scanf("%i %i %i",&dia,&mes,&ano);
				if(dia > 31 || dia < 0 || mes > 12 || mes < 0 || ano < 0){
				printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||\n");
				goto nov10;
				}
				printf("|| Hora da emicao do aquivo(HH:MM):  ");
				scanf(" %s",hora);
				printf("|| Partido de:  ");
			}else if(c3=='S'||c3=='s'){
				j++;
				info[i].num = j;
				printf("\n|| Partido de:  ");
			}
			limparbuffer();
			fgets(info[i].partida,MAX,stdin);               //scanf("%[^\n]", info[i].partida); || gets_s || gets
			nov5:
			printf("|| Dia da partida(DD MM YYYY):  ");
			scanf("%i %i %i",&info[i].pdia, &info[i].pmes, &info[i].pano);
			if(info[i].pdia > 31 || info[i].pdia < 0 || info[i].pmes > 12 || info[i].pmes < 0 || info[i].pano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||\n");
			goto nov5;
			}
			limparbuffer(); 
			printf("|| Chegado em:  ");
			fgets(info[i].chegada,MAX,stdin);
			nov6:
			printf("|| Dia da chegada(DD MM YYYY):  ");
			scanf("%i %i %i",&info[i].sdia, &info[i].smes, &info[i].sano);
			if(info[i].sdia > 31 || info[i].sdia < 0 || info[i].smes > 12 || info[i].smes < 0 || info[i].sano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||\n");
			goto nov6;
			}
			printf("|| Tipo de veiculo da viagem(A,B,C,D,E):  ");
			scanf(" %c",&info[i].tipo);
			limparbuffer();
			printf("|| Nome do condutor:  ");
			fgets(info[i].condutor,MAX,stdin);
			printf("|| Kilometros rodados(Km):  ");
			scanf("%f",&info[i].km);
			
			printf("|| Houve gastos (s/n)?  ");
			scanf(" %c",&c2);
			
			if(c2 =='s'|| c2 =='S'){
			limparbuffer(); 
			printf("|| Descricao do gasto:  ");
			fgets(info[i].gdescricao,MAX,stdin);
			nov7:
			printf("|| Data do gasto(DD MM YYYY):  ");
			scanf("%i %i %i",&info[i].gdia, &info[i].gmes, &info[i].gano);
			if(info[i].gdia > 31 || info[i].gdia < 0 || info[i].gmes > 12 || info[i].gmes < 0 || info[i].gano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||\n");
			goto nov7;
			}
			printf("|| Hora do gasto(HH:MM):  ");
			scanf(" %s",info[i].ghora);
			printf("|| Custo(Euro):  ");
			scanf("%f",&info[i].gcusto);
				}else if(c2 == 'n' || c2 == 'N'){
					info[i].gdescricao[MAX] = NULL;
					info[i].gdia=0; 
					info[i].gmes=0; 
					info[i].gano=0;
					info[i].ghora[MAX] = NULL;
					info[i].gcusto=0.0;
			}
			
			if(c3=='n'||c3=='N'){
			fprintf(file,"\n||\n||\n|| Para a viagem %d: Matricula do veiculo: %d, Dia e hora de criacao desse aquivo: %d/%d/%d as %s --- ",info[i].num, mat, dia, mes ,ano,hora);	
			fprintf(file,"\n|| Patido de: %s no dia %d/%d/%d e Chegado em: %s no dia %d/%d/%d",info[i].partida, info[i].pdia ,info[i].pmes ,info[i].pano ,info[i].chegada ,info[i].sdia ,info[i].smes, info[i].sano);
			fprintf(file,"\n|| Tipo de veiculo: %c",info[i].tipo);
			fprintf(file,"\n|| Nome do condutor: %s",info[i].condutor);
			fprintf(file,"\n|| Kilometros rodados: %.2f",info[i].km);
			if(info[i].gcusto!=0.0)
			fprintf(file,"\n|| Gastos --- \n|| Descricao do gasto: %s \n|| Data do gasto: %d/%d/%d as %s\n|| Custo do gasto: %.2f",info[i].gdescricao,info[i].gdia,info[i].gmes,info[i].gano,info[i].ghora,info[i].gcusto);
			}
			
			i++;
			
		}while(i!=n2);
		
		
	if(c3=='s'||c3=='S'){
	fwrite(info, sizeof(viagem), n2, viagemn);
	fclose(viagemn);
	}else if(c3=='n'||c3=='N'){
	 fclose(file);
	}
	
	printf("\n\n|| ");
	system("pause");
}

// atualizar no ficheiro os dados atualizados na funcao mudardadosv 
void atualizarv(veiculo *info, int n4, int n, FILE *veiculof ){
	
	INICIO5:
	veiculof = fopen("veiculos.dat","wb");
	if(veiculof == NULL){
		printf("\n|| Impossivel abrir o arquivo veiculos\n");
		getchar();
		goto INICIO5;
	}
	
	int i,j,n2;
	
	// n4 = 1   n = 98   
	
	fwrite(info, sizeof(veiculo), MAX_A, veiculof);
	
	printf("\n|| Novas informacoes sobre veiculos salvas com sucesso! ");
	
	fclose(veiculof);
	printf("\n\n|| ");
	system("pause");
	
}

// calculo das acoes da empresa
// feito apartir de um numero aleatorio
float stonks(float x,float n5,FILE *file){
	
	INICIO12:
	file = fopen("Informacoes Salvas.txt","a");
	if(file == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO12;
	}
	
	int i;
	float y;
	float var;
	char c;
	
	// 7 - 6.5
	// x  100
	// var  r
	
	printf("\n|| Voce deseja salvar suas informacoes em um ficheio (s/n)?  ");
	scanf(" %c",&c);
	if(c=='s'|| c=='S'){
		fprintf(file,"\n||\n||\n|| Acoes da empresa -----------------------------------");
	}
	
	var = random(-6.0,6.0);
	
	if(var>0){
	y = (x/100) * var;
	x = x+y;
	printf("\n|| As suas acoes atuais valem: %.2f com um aumento de %.2f%%",x,var);
	if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| As suas acoes atuais valem: %.2f com um aumento de %.2f%%",x,var);
		}
	}else if(var<0){
	y = (x/100) * (-var);
	x = x-y;
	printf("\n|| As suas acoes atuais valem: %.2f com uma decremento de %.2f%%",x,var);
	if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| As suas acoes atuais valem: %.2f com uma decremento de %.2f%%",x,var);
		}
	}
	else if(var==0){
		printf("\n|| As suas acoes atuais valem: %.2f sem nehuma variacao",x);
		if(c=='s'||c=='S'){
		fprintf(file,"\n||\n|| As suas acoes atuais valem: %.2f sem nehuma variacao",x);
		}
	}
	
	printf("\n\n|| ");
	system("pause");
	fclose(file);
	return x;
}

// Miscellaneous ----------------------------------------

// menu de avaliacoes dos clientes da empresa
int rating(avaliacao *info, int n,FILE *file){
	
	INICIO18:
	file = fopen("Informacoes Salvas.txt","a");
	if(file == NULL){
		printf("\nImpossivel abrir o arquivo txt\n");
		getchar();
		goto INICIO18;
	}
	
	int i,mani,mani2,mani3,j=0,k;
	char c,c2;
	
	do{
	system("cls");
	printf("\n|| Menu de avaliacao");
	printf("\n|| 1 - Fazer uma avaliacao ");
	printf("\n|| 2 - Retirar uma avaliacao ");
	printf("\n|| 3 - Mudar alguma avaliacao ");
	printf("\n|| 4 - Ver avaliacoes\n");
	printf("||\n|| Escreva sua opcaoa aqui(0 para voltar ao menu):  ");
	scanf(" %i",&mani);
	printf("||\n|| Voce deseja salvar as informacoes em um ficheiro (s/n)?  ");
	scanf(" %c",&c2);
	if(c2=='s'||c2=='S'){
		fprintf(file,"\n||\n||\n|| Menu do cliente -----------------------------------");
	}
	
	if(mani==0){
		printf("\n|| Aperte enter para voltar ao menu!\n\n");
		system("pause");
		return 0;
	}
	else if(mani==1){
		printf("\n|| Quantas avaliacoes voce quer registrar:  ");
		scanf("%i",&k);
		if(k<=0){
			k=1;
		}
		j = k+n+1;
		i=n+1;
		if(n==0){
			i=n;
			j=k+n;
		}
		while(i!=j){
			printf("\n|| Para a avaliacao n%i \n",i+1);
			limparbuffer();
			printf("|| Digite o nome do avaliador: ");
			fgets(info[i].nome,MAX,stdin);
			printf("|| Digite o dia da avaliacao(DD MM YYYY):  ");
			nov8:
			scanf("%i %i %i",&info[i].dia,&info[i].mes,&info[i].ano);
			if(info[i].dia > 31 || info[i].dia < 0 || info[i].mes > 12 || info[i].mes < 0 || info[i].ano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||");
			goto nov8;
			}
			printf("|| Digite a avaliacao(1 - 5):  ");
			scanf("%f",&info[i].nota);
			limparbuffer();
			printf("|| Digite o comentario(Maximo de 250 caracteres): ");
			fgets(info[i].comentario,250,stdin);
			i++;
			if(c2=='s'||c2=='S'){
			fprintf(file,"\n||\n|| Para a avaliacao n%i - Nome do avaliador: %s, dia da avaliacao %d/%d/%d, avaliacao:  %f, comentario do avaliador %s",i+1,info[i].nome,info[i].dia,info[i].mes,info[i].ano,info[i].nota,info[i].comentario);
			}
		};
	}
	else if(mani==2){
		printf("\n|| Voce tem %i avaliacoes feitas. Qual o numero da avaliacao que voce quer retirar ?  ",n+1);
		scanf("%i",&mani2);
		mani2--;
		if(mani2<=0){
			mani2 =0;
		}
		info[mani2].nome[1] = NULL;
		info[mani2].dia = 0; info[mani2].mes =0; info[mani2].ano =0;
		info[mani2].comentario[1] = NULL;
		info[mani2].nota = 48;
		if(c2=='s'||c2=='S'){
		fprintf(file,"\n||\n|| A avaliacao n%i foi retirada",mani2+1);
		}
	}
	else if(mani==3){
		printf("\n|| O que voce deseja mudar ?");
		printf("\n|| 1 - Nome de alguma avaliacao");
		printf("\n|| 2 - Dia de alguma avaliacao");
		printf("\n|| 3 - Comentario de alguma avaliacao");
		printf("\n|| 4 - Nota de alguma avaliacao\n");
		printf("||\n|| Escreva sua opcao aqui:  ");
		scanf("%i",&mani2);
		
		printf("\n|| Qual avaliacao voce quer mudar ?  ");
				scanf("%i",&mani3);
				mani3--;
				if(mani3<=0){
					mani3=0;
				}
				
		switch(mani2){
			case 1:
				printf("\n|| O nome da avaliacao n%i e %s ",mani3+1,info[mani3].nome);
				limparbuffer();
				printf("\n|| Digite o nome atualizado aqui:  ");
				fgets(info[mani3].nome,MAX,stdin);
				if(c2=='s'||c2=='S'){
					fprintf(file,"\n||\n|| Nome atualizado da avaliacao n%i: %s",mani3+1,info[mani3].nome);
				}
			break;
			case 2:
				printf("\n|| O dia da avaliacao n%i e %i/%i/%i ",mani3+1,info[mani3].dia,info[mani3].mes,info[mani3].ano);
				printf("\n|| Digite a data atualizada aqui:  ");
				nov9:
			scanf("%i %i %i",&info[mani3].dia,&info[mani3].mes,&info[mani3].ano);
			if(info[i].dia > 31 || info[i].dia < 0 || info[i].mes > 12 || info[i].mes < 0 || info[i].ano < 0){
			printf("\n|| DATA INVALIDA TENTE NOVAMENTE ||");
			goto nov9;
				if(c2=='s'||c2=='S'){
					fprintf(file,"\n||\n|| Data atualizada da avaliacao n%i: %i/%i/%i",mani3+1,info[mani3].dia,info[mani3].mes,info[mani3].ano);
				}
			}
			break;
			case 3:
				printf("\n|| Digite o novo comentario da avaliacao n%i aqui(Maximo de 250 caracteres):  ",n+1);
				limparbuffer();
				fgets(info[mani3].comentario,250,stdin);
				if(c2=='s'||c2=='S'){
					fprintf(file,"\n||\n|| Comentario atualizado da avaliacao n%i: %s",mani3+1,info[mani3].comentario);
				}
			break;
			case 4:
				printf("\n|| A avaliacao atual n%i e %.2f",n+1,info[mani3].nota);
				printf("\n|| Digite a nova nota aqui(1 - 5):  ");
				scanf("%f",&info[mani3].nota);
				if(c2=='s'||c2=='S'){
					fprintf(file,"\n||\n|| Comentario atualizado da avaliacao n%i: %.2f",mani3+1,info[i].nota);
				}
			break;
		}
	}
	else if(mani==4){
		for(i=0;i<j;i++){
			if(info[i].nota !=48&&info[i].nota!=NULL){
			printf("\n|| A avaliacao n%i ",i+1);
			printf("\n|| Feita pelo(a):  %s||",info[i].nome);
			printf("\n|| Teve nota %.2f",info[i].nota);
			printf("\n|| E Seu comentario foi:  %s||\n",info[i].comentario);
			if(c2=='s'||c2=='S'){
			fprintf(file,"\n||\n|| Para a avaliacao n%i - Nome do avaliador: %s, dia da avaliacao %d/%d/%d, avaliacao:  %f, comentario do avaliador %s",i+1,info[i].nome,info[i].dia,info[i].mes,info[i].ano,info[i].nota,info[i].comentario);
				}
			}
		}
	}
	
	printf("\n\n|| Voce deseja ver mais alguma informacao(s/n) ?  ");
	scanf(" %c",&c);
	
	}while(c=='s'|| c=='S');
	
	printf("\n\n|| ");
	system("pause");
	fclose(file);
	return j;
}

// mostra informacoes legais do programa
void informacoes(){
	
	system ("cls");
	system("color A");
	printf("\n|||||||||||||||||||||||||||||||||||||||");
	printf("\n|| Programa feito por:               ||");
	printf("\n|| Caio Quintas Santiago - 18433     ||");
	printf("\n|| Luigi Monteiro Jesus - 18435      ||");
	printf("\n|| Abel Marques - 18549              ||");
	printf("\n|| Renidicksonraramedi Bispo - 18461 ||");
	printf("\n|||||||||||||||||||||||||||||||||||||||");
	
	printf("\n\n|| ");
	system("pause");
	system ("color F");
	
}

// menu da central de atendimento ao cliente
void central(){
	int mani;
	char c;

	do{
	system("cls");
	printf("\n|| Bem vindo a central de ajuda, no que podemos ajudar ?");
	printf("\n|| 1 - Contato para suporte ");
	printf("\n|| 2 - Envio de reclamacao");
	printf("\n|| 3 - Versao do aplicativo\n");
	printf("||\n|| Digite sua opcao aqui(0 para voltar ao menu):  ");
	scanf("%i",&mani);
	switch(mani){
		case 0:
		break;
		case 1:
			printf("\n|| Numero para contado direto: +351 910 848 163 (Taxas podem ser cobradas pela operadora)");
			printf("\n|| Email para contato: caioquintassantiago(a)gmail.com");
			printf("\n|| Loja fisica: IPV - ESTGV laboratorio 3 as quartas e sextas apartir das 18:00 horas");
			printf("\n");
			
		break;
		
		case 2:
			printf("\n|| Servico indisponivel no momento, redirecionando para contado para suporte!");
			printf("\n|| Aperte enter para ver os contatos ");
			system("pause");
			printf("|| Numero para contado direto: +351 910 848 163 (Taxas podem ser cobradas pela operadora)");
			printf("\n|| Email para contato: caioquintassantiago(a)gmail.com");
			printf("\n|| Loja fisica: IPV - ESTGV laboratorio 3 as quartas feiras e sextas feiras apartir das 18:00 horas");
			printf("\n");
		break;
		
		case 3:
			printf("\n|| O aplicativo esta rodando na versao 3.6 build A");
			printf("\n");
		break;
	}
	
	printf("\n|| Voce deseja ver mais alguma informacao(s/n):  ");
	scanf(" %c",&c);
}while(c=='s'|| c=='S');
	
	printf("\n\n|| ");
	system("pause");
}

// menu da ficha da tabela de precos e informacoes por tipo de veiculo
void ficha(){
	int mani;
	char c;

	do{
	system("cls");
	printf("\n|| Voce abriu a tabela de precos e informacoes, no que podemos ajudar ?");
	printf("\n|| 1 - Consultar preco do gasoleo ");
	printf("\n|| 2 - Colsultar preco de manutencao para os diferentes tipos de veiculos");
	printf("\n|| 3 - Tabela de precos por veiculo\n");
	printf("||\n|| Digite sua opcao aqui(0 para voltar ao menu):  ");
	scanf("%i",&mani);
	
	switch(mani){
		case 0:
		break;
		case 1:
			printf("\n|| O gasoleo esta avaliado em: 1.40 euros por litro\n");
		break;
		case 2:
			printf("\n|| O tipo A tem um custo de manutencao de 0.1 por km");
			printf("\n|| O tipo B tem um custo de manutencao de 0.2 por km");
			printf("\n|| O tipo C tem um custo de manutencao de 0.3 por km");
			printf("\n|| O tipo D tem um custo de manutencao de 0.4 por km");
			printf("\n|| O tipo E tem um custo de manutencao de 0.6 por km\n");
		break;
		case 3:
			printf("\n|| As informacoes a segir sao os precos por modelo de veiculo");
			printf("\n|| Preco por cada caminhao: 200.00 euros");
			printf("\n|| Preco por cada carro: 80.00 euros");
			printf("\n|| Preco por cada moto: 40.00 euros");
			printf("\n|| Preco por cada caminhonete: 100.00 euros\n");
		break;
	}
	
	printf("\n|| Voce deseja ver mais alguma informacao(s/n):  ");
	scanf(" %c",&c);
	}while(c=='s'|| c=='S');

	printf("\n\n|| ");
	system("pause");
}



int main(){
	
	system ("color F");   // muda toda a cor do ecra
	
	// inicializa os ponteiros para os ficheiro
	FILE *veiculof;       
	FILE *viagemf;		  
	FILE *viagemn;	
	FILE *viagemnn;
	FILE *file;  
	veiculo *info;
	viagem *info2;
	avaliacao *info3;
	
	// alocacao de memoria para as estruturas
	info = alok(MAX_A);
	info2 = alok2(MAX_A2);
	info3 = alok3(MAX_A2);

	abrirveiculo(veiculof,info);		// abre o aquivo veiculos 
	abrirviagens(viagemf,info2);		// abre o arquivo viagens
	checktxt(file);						// checa o arquivo de infomacoes salvas
	criarnovab(viagemn);				// cria o arquivo para registrar viagens .dat
	criarnovat(viagemnn);				// cria o arquivo para registrar viagens .txt
	
	int n,n2,mani,n3,n4,i=0,n7,mani2,n8;
	float n5 = 0.0;							// variavel de controle
	float x = 3500.0;						// preco das acoes iniciais    

	n = MAX_A;							// veiculos totais
	n2 = MAX_A2;						// veiagens totais
	n8 = calculov(info2,n2);
	
	checklist(info2,info,n,n2);			// faz uma leitura nos ficheiros para identificar informacoes inconsistentes
	
	// apresentacao dos dados
	printf("\n|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||||||||||||||||||BEM VINDO|||||||||||||||||||||||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("|||||||||||||||||||||||||||||||||||||||||||||||||||\n\n");
	printf("|| O gasoleo esta a 1.40 \n");
	printf("|| A manutencao por KM e tipo de veiculo da empresa e: \n");
	printf("|| A - 0.1 || B - 0.2 || C - 0.3 || D - 0.4 || E - 0.6 \n");
	printf("|| As suas acoes atuais valem:  %.2f\n",x);
	printf("||\n");
	printf("|| Seus dados foram lidos Aperte enter para continuar \n\n|| ");
	system("pause");
	system("cls");
	
	// apos chamar o menu, esses if's e else if's controlam o programa enquanto o usuario mao digitar 0
	do{
	mani = menu();
	
	if(mani == 0){
		printf("\nPrograma finalizado com sucesso, aperte enter para sair!\n\n");
		system("pause");
		system("cls");
		return 0;
	}
	
	else if(mani == 1){
		
		lerdados(info,n,info2,n2,file);
		
	}
	
	else if(mani == 2){
		
		// apos atualizar os dados se for adcionado algum veiculo, ele sera adcionado na variavel n(veiculos totais)
		n4=0;
		n4  =  mudardadosv(info,n,file);
		n = n+n4;
		
	}
	
	else if(mani == 3){
		
		custosviagem(info2,n2,n3,n8,file);
		
	}
	
	else if(mani == 4){
		
		custodata(info2,n2,file);
		
	}
	
	else if(mani ==5 ){
		
		criararquivo(info2,n2,viagemn,viagemnn);
		
	}
	
	else if(mani ==6){
		
		atualizarv(info,n4,n,veiculof);
		
	}
	
	else if(mani ==7){
		
		// devolve o valor float e atualiza as acoes sempre que selecionado
		x = stonks(x,n5,file);
		// finaliza o programa se as acoes foram iguais ou menores que 0
		if(x<=0){
			system("cls");
			printf("\n|| Voce brincou demais com suas acoes!!!");
			printf("\n|| A sua empresa esta falida, sem dinheiro");
			printf("\n|| Fechando o programa\n");
			system("pause");
			return 0;
		}
		
	}
	
	else if(mani ==8){
		
		informacoes();
	
	}
	
	else if(mani ==9){
		
		do{
		// menu do cliente
		mani2 = menuc();
		switch(mani2){
			case 0:
			break;
			case 1:
			n7+=rating(info3,n7,file);
			break;
			case 2:
			central();
			break;
			case 3:
			ficha();
			break;
			case 4:
		// devolve o valor float e atualiza as acoes sempre que selecionado
		x = stonks(x,n5,file);
		// finaliza o programa se as acoes foram iguais ou menores que 0
		if(x<=0){
			system("cls");
			printf("\n|| Voce brincou demais com suas acoes!!!");
			printf("\n|| A sua empresa esta falida, sem dinheiro");
			printf("\n|| Fechando o programa\n|| ");
			system("pause");
			return 0;
		}
			break;
			}	
		}while(mani2!=0);
	}
	
	}while(mani != 0);
	
	// liberar memoria
	
	free(info);
	free(info2);
	free(info3);
	
	// 250 250 250 250
	
	return 0;
}
