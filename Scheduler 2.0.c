#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>

typedef struct processo{
	char ID;
	int tempo;
	int rank;
	int restante;
}processo;

processo processos[8];

void LimparRank();
void inserir();
void FCFS();
void SJF();
void LJF();
void RoundRobin();
int main(){
	setlocale(LC_ALL, "Portuguese");
	int op;
	do{
		printf("0 - Inserir processos\n");
		printf("1 - Ordem de chegada (FCFS)\n");
		printf("2 - Ordem do mais curto (SJF)\n");
		printf("3 - Ordem do mais longo (LJF)\n");
		printf("4 - Preemptivo (Round Robin)\n");
		
		printf("Comando: "); 
		scanf("%d",&op); printf("\n");
		
				switch(op){
			case 0:
				system("cls");
				inserir();
				break;
				
			case 1:
				system("cls");
				FCFS();
				break;
				
			case 2:
				system("cls");
				SJF();
				break;
			
			case 3:
				system("cls");
				LJF();
				break;
				
			case 4: 
				system("cls");
				RoundRobin();
				break;
				
			case 10:
				system("cls");
				printf("CHAVE DO MEU PIX\n");
				printf("40783409893\n");
				break;
				
			default:
			printf("Opção inválida\n");
								
		}
	}while(op != -1);
	
	
	return 0;
}
void LimparRank(){
	for(int i = 0; i < 8;i++){
		processos[i].rank = 0;
		processos[i].restante = 0;
	}
}

void inserir(){
	printf("Tempos de cada processo:\n\n");
	for(int i = 0;i < 8;i++){
		printf("P[%d]: ",i + 1);
		scanf("%d",&processos[i].tempo);	
	}
	
	processos[0].ID = 'A';
	processos[1].ID = 'B';
	processos[2].ID = 'C';
	processos[3].ID = 'D';
	processos[4].ID = 'E';
	processos[5].ID = 'F';
	processos[6].ID = 'G';
	processos[7].ID = 'H';
	processos[8].ID = 'I';
	system("cls");
	for(int i = 0;i < 8;i++){
		printf("P[%c]: %ds\n",processos[i].ID,processos[i].tempo);
	}

}
void FCFS(){
 	printf("FCFS - Ordem de chegada\n");
	for(int i = 0;i < 8;i++){
		printf("Executando...\b\b\b\b\b\b\b\b\b\b\b\b\b");
		usleep(50000);
        printf("P[%c]: Executado - Time: %ds\n",processos[i].ID,processos[i].tempo);
        usleep(50000);
	}
}
void SJF(){
	LimparRank();
	int p = 7;
	printf("SJF - Ordem do mais curto\n");
	
	// Criação de rank
	for(int x = 0; x < 8; x++){
		for(int i = 0; i < 8; i++){
			if(processos[x].tempo < processos[i].tempo){
				processos[x].rank++;
			}
		}
	}
	
	// Execução dos processos com base no rank
	for(int x = 0; x < 8; x++){
		for(int i = 0; i < 8; i++){
			if(processos[i].rank == p){
				printf("Executando...\b\b\b\b\b\b\b\b\b\b\b\b\b");
				usleep(50000);
                printf("P[%c]: Executado - Time: %ds\n",processos[i].ID,processos[i].tempo);
                usleep(50000);
                p--;
                if(p < 0){
                    break;
                }
            }
		}
		if(p < 0){
            break;
        }
	}
}

void LJF(){
	LimparRank();
	int p = 7;
	printf("LJF - Ordem do mais Longo\n");
	
	// Criação de rank
	for(int x = 0; x < 8; x++){
		for(int i = 0; i < 8; i++){
			if(processos[x].tempo > processos[i].tempo){
				processos[x].rank++;
			}
		}
	}
	
	// Execução dos processos com base no rank
	for(int x = 0; x < 8; x++){
		for(int i = 0; i < 8; i++){
			if(processos[i].rank == p){
				printf("Executando...\b\b\b\b\b\b\b\b\b\b\b\b\b");
				usleep(50000);
                printf("P[%c]: Executado - Time: %ds\n",processos[i].ID,processos[i].tempo);
                usleep(50000);
                p--;
                if(p < 0){
                    break;
                }
            }
		}
		if(p < 0){
            break;
        }
	}
}

void RoundRobin(){
	LimparRank();
	printf("Round Robin - Com fatias de tempo de 50 segundos\n");
	int controle = 0;
	processo interrompidos[8];
	for(int i = 0; i < 8;i++){
		if(processos[i].tempo > 50){
			processos[i].restante = processos[i].tempo - 50;
			interrompidos[controle] = processos[i];
			controle++;
		printf("Executando...\b\b\b\b\b\b\b\b\b\b\b\b\b");
		usleep(50000);
        printf("P[%c]: Interrompido - Tempo restante: %ds\n",processos[i].ID,processos[i].restante);
        usleep(50000);
		}else{
		printf("Executando...\b\b\b\b\b\b\b\b\b\b\b\b\b");
		usleep(50000);
        printf("P[%c]: Executado - Time: %ds\n",processos[i].ID,processos[i].tempo);
        usleep(50000);
    	}
	}
	for(int i = 0;i < controle;i++){
		printf("Executando...\b\b\b\b\b\b\b\b\b\b\b\b\b");
		usleep(50000);
        printf("P[%c] Retomado: Executado - Time: %ds\n",interrompidos[i].ID,interrompidos[i].restante);
        usleep(50000);
	}
}

	




