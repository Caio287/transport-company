#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 100			// tamanho dos vetores de caracteres
#define MAX_A 1000		// tamanho dos veiculos(ilimitado)
#define MAX_A2 10000		// tamanho das viagens(ilimitado)

typedef struct nomeempresa{
	
	int matricula;
	char marca[MAX];
	char modelo[MAX];
	int dia,mes,ano;
	float custo;
	char tipov;
	
}veiculo;

typedef struct Nomeempresa{
	
	char tipov;
	int num;
	int pdia ,pmes,pano;
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
	float consumo;
	
}viagem;

int random(int a, int b){
	return((b-a)*(rand()/RAND_MAX)+a);
}

float randomf(float a, float b){
	return((b-a)*((float)rand()/RAND_MAX)+a);
}

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

int randomn(int min, int max)
{
   return min + rand() % (max+1 - min);
}

int main(){
	
	FILE *viagemn;
	FILE *veiculof;
	FILE *viagemf;
	FILE *file;
	FILE *file2;
	veiculo *info;
	viagem *info2;
	
	info = alok(MAX_A);
	info2 = alok2(MAX_A2);
	
	srand(time(NULL));
	
	int i,j=00001,k;
	int c1,c2,c3,c4,c5,c6,c7,c8,c9;
	float custo;
	char a ='A',b = 'B',c = 'C',d = 'D',e = 'E';
	
	char a1[10]="Carro";
	char a2[10]="Caminhao";
	char a3[20]="Caminhonete";
	char a4[10]="Moto";
	
	char a5[20]="Lisboa";
	char a6[20]="Viseu";
	char a7[20]="Braga";
	char a8[20]="Coimbra";
	char a9[20]="Belem";
	
	char a10[20]="Volwks";
	char a11[20]="Cytrohein";
	char a12[20]="Pegege";
	
	char b1[20]="Caio Quintas";
	char b2[20]="Luigi Monteiro";
	char b3[20]="Mario Souza";
	char b4[20]="Reni Bispo";
	char b5[20]="Abel Marques";
	char b13[20]="Airton Sena";
	char b14[20]="Felipe Massa";
	
	char b6[20]="Aveiro";
	
	veiculof = fopen("veiculos.dat","wb");
	for(i=0;i<MAX_A;i++){
		
		c1=randomn(1,3);
		
		if(c1==1){
		strcpy(info[i].marca,a10);
		}else if(c1==2){
			strcpy(info[i].marca,a11);
		}else if(c1==3){
			strcpy(info[i].marca,a12);
		}
		
		c2 = randomn(1,50);
		
		if(c2>=1 && c2<=10){
			info[i].tipov = 'A';
		}else if(c2>=11 && c2 <= 20){
			info[i].tipov = 'B';
		}else if(c2>=21 && c2<=30){
			info[i].tipov = 'C';
		}else if(c2>=31 && c2<=40){
			info[i].tipov = 'D';
		}else if(c2>=41 && c2<=50){
			info[i].tipov = 'E';
		}
	
	
		info[i].custo = randomf(11000.00,200000.00);
		
		info[i].dia = randomn(1,31);
		info[i].mes = randomn(1,12);
		info[i].ano = randomn(2000,2025);
		
		
		c3 = randomn(1,4);
		if(c3 ==1){
			strcpy(info[i].modelo,a1);
		}else if(c3 ==2){
			strcpy(info[i].modelo,a2);
		}else if(c3 ==3){
			strcpy(info[i].modelo,a3);
		}else if(c3 ==4){
			strcpy(info[i].modelo,a3);
		}
		
		
		info[i].matricula=j;
		j++;

	}
	fwrite(info,sizeof(veiculo),MAX_A,veiculof);
	fclose(veiculof);
	
	j=00001;
	
	viagemn = fopen("viagens.dat","wb");
	
	for(i=0;i<MAX_A2;i++){
		
		info2[i].custov = 0.0;
		info2[i].consumo = 0.0;
		
		
		c4 = randomn(1,5);
		if(c4 == 1){
			info2[i].tipov = 'A';
		}else if(c4==2){
			info2[i].tipov = 'B';
		}else if(c4==3){
			info2[i].tipov = 'C';
		}else if(c4==4){
			info2[i].tipov = 'D';
		}else if(c4==5){
			info2[i].tipov = 'E';
		}
	
		info2[i].num = j;
		j++;
		
		// 999 00000
		nov:
		info2[i].pdia = randomn(1,31); 
		info2[i].pmes= randomn(1,12); 
		info2[i].pano = randomn(2000,2025);
		
		info2[i].sdia = randomn(1,31); 
		info2[i].smes= randomn(1,12); 
		info2[i].sano = randomn(2000,2025);
		
		if(info2[i].pdia < info2[i].sdia && info2[i].smes < info2[i].pmes && info2[i].sano < info2[i].pano || info2[i].smes < info2[i].pmes && info2[i].sano < info2[i].pano || info2[i].sano < info2[i].pano){
			goto nov;
		}
		
		info2[i].km = randomf(50.0,600.0);
		
		c5 = randomn(1,7);
		if(c5 ==1){
			strcpy(info2[i].partida,a5);
		}else if(c5 ==2){
			strcpy(info2[i].partida,a6);
		}else if(c5 ==3){
			strcpy(info2[i].partida,a7);
		}else if(c5 ==4){
			strcpy(info2[i].partida,a8);
		}else if(c5 ==5){
			strcpy(info2[i].partida,a9);
		}else if(c5 ==6){
			strcpy(info2[i].partida,"Vila Real");
		}else if(c5 ==7){
			strcpy(info2[i].partida,"Guarda");
		}
		
		c6 = randomn(1,7);
		if(c6==7){
			strcpy(info2[i].chegada,b6);
		}else if(c6 ==1){
			strcpy(info2[i].chegada,a6);
				/*if(c5 == 1){
					info2[i].km = 293.0;
				}else if(c5 == 2){
					info2[i].km = 363.5;
				}else if(c5==3){
					info2[i].km = 204.1;
				}else if(c4 ==4){
					info2[i].km = 296.7;
				}*/
		}else if(c6 ==2){
			strcpy(info2[i].chegada,a7);
			/*if(c5 == 1){
					info2[i].km = 293.0;
				}else if(c5 == 3){
					info2[i].km = 363.5;
				}else if(c5==4){
					info2[i].km = 204.1;
				}else if(c4 ==4){
					info2[i].km = 296.7;
				}*/
		}else if(c6 ==3){
			strcpy(info2[i].chegada,a8);
		}else if(c6 ==4){
			strcpy(info2[i].chegada,a9);
		}else if(c5 ==5){
			strcpy(info2[i].partida,"Vila Real");
		}else if(c5 ==6){
			strcpy(info2[i].partida,"Guarda");
		}
		
	/*char a5[20]="Lisboa";
	char a6[20]="Viseu";
	char a7[20]="Braga";
	char a8[20]="Coimbra";
	char a9[20]="Belem";
	*/
		c7 = randomn(1,9);
		if(c7== 1){
		strcpy(info2[i].condutor,b1);
		}else if(c7==2){
		strcpy(info2[i].condutor,b2);
		}else if(c7==3){
			strcpy(info2[i].condutor,b3);
		}else if(c7==4){
			strcpy(info2[i].condutor,b4);
		}else if(c7==5){
			strcpy(info2[i].condutor,b5);
		}else if(c7==6){
			strcpy(info2[i].condutor,"Joao Miguel");
		}else if(c7==7){
			strcpy(info2[i].condutor,"Maria Silva");
		}else if(c7==8){
			strcpy(info2[i].condutor,b13);
		}else if(c7==9){
			strcpy(info2[i].condutor,b14);
		}
		
		c8 = randomn(1,2);
		if(c8==1){
			
		c7 = randomn(1,5);
		if(c7== 1){
		strcpy(info2[i].gdescricao,"Almoco");
		}else if(c7==2){
		strcpy(info2[i].gdescricao,"Jantar");
		}else if(c7==3){
			strcpy(info2[i].gdescricao,"Hospedagem");
		}else if(c7==4){
			strcpy(info2[i].gdescricao,"Agua");
		}else if(c7==5){
			strcpy(info2[i].gdescricao,"Refrigerante");
		}
			
			nov3:
			info2[i].gdia = randomn(1,31); 
			info2[i].gmes = randomn(1,12); 
			info2[i].gano = randomn(2000,2025);
			if(info2[i].pano > info2[i].gano || info2[i].sano < info2[i].gano){
				goto nov3;
			}
			
			c7 = randomn(1,7);
		if(c7== 1){
		strcpy(info2[i].ghora,"12:23");
		}else if(c7==2){
		strcpy(info2[i].ghora,"13:59");
		}else if(c7==3){
			strcpy(info2[i].ghora,"07:51");
		}else if(c7==4){
			strcpy(info2[i].ghora,"10:23");
		}else if(c7==5){
			strcpy(info2[i].ghora,"23:32");
		}else if(c7==6){
			strcpy(info2[i].ghora,"01:47");
		}else if(c7==7){
			strcpy(info2[i].ghora,"16:15");
		}
			
		info2[i].gcusto = randomf(1.0,3.5);
		}else if(c8==2){
			strcpy(info2[i].gdescricao,"00:00");
			info2[i].gdia = 1; 
			info2[i].gmes = 1; 
			info2[i].gano = 1;
			strcpy(info2[i].ghora,"0:00");
			info2[i].gcusto = 0.0;
			}
		
	
	}
	
	fwrite(info2, sizeof(viagem), MAX_A2, viagemn);
	fclose(viagemn);

	viagemf = fopen("Novas Viagens.dat","wb");
	fclose(viagemf);
	file = fopen("Novas Viagens.txt","w");
	fclose(file);
	file2 = fopen("Informacoes Salvas.txt","w");
	fclose(file2);
	
	free(info);
	free(info2);
	
	printf("\n AQUIVO CRIADO COM SUCESSO!! \n\n\n");
	
}

