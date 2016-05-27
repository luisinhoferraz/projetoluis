/* Projeto de Engenharia de Software:
   Calcular a nota final dos alunos e ver se foram aprovados
   Haverá vários alunos cadastrados
*/

// 1º: Cadastrar os alunos em um vetor de structs (Máximo 35) (OK)
//      Nome, RA, faltas, P1, P2, P3 (opcional), trabalho e exame (OK)
//	    Cadastrar 1 aluno (OK)
//      Cadastrar n alunos (OK)
// 2º: Calcular média parcial (OK)
//	    ((P1+P2)/2)*9/10 + T*1/10 ou ((P1+P2+P3)/3)*9/10 + T*1/10 (OK)
// 3º: Verificar Exame (OK)
//	    Média < 2.5 (Reprovação) (OK)
//	    2.5 <= Média <= 5.9 (Exame) (OK)
//	    Média >= 6 (Aprovação) (OK)
// 4º: Calcular nota final (OK)
//	    Nota = Média parcial (OK)
//	    Ou Nota = Média Parcial*2/3 + Exame*1/3 (OK)
//		Nota >= 5 (Aprovação) (OK)
// 5º: Avaliar faltas (OK)
//	    4 ou menos faltas (Aprovação) (OK)
//	    Mais que 4 faltas (Reprovação por falta) (OK)
// 6º: Exibir aprovação/reprovação
// 7º: Opção de relatório de aprovações (Requisito inconsciente)
//	    Alunos aprovados
//	    Alunos reprovados
//	    Total de alunos
//	    Taxas de aprovação e de reprovação

#include <stdio.h>
#include <string.h>

// Dados de cada aluno do tipo Pessoa
typedef struct pessoa {
	char nome[100];
	int ra, faltas;
	float p1, p2, p3, trabalho, exame;
	float mediaparcial, mediafinal;
} Pessoa;

// Serão cadastrados no máximo 35 alunos
Pessoa alunos[35];

// Funções utilizadas
void cadastrarAluno(Pessoa x[], int i);
void calcularMediaParcial(Pessoa x[], int i);
void verificarExame(Pessoa x[], int i);
void verificarFaltas(Pessoa x[], int i);

int main(){
    int n, cont;

    printf("Deseja cadastrar quantos alunos? ");
    scanf("%d", &n);
    getchar();

    while(n > 35){
        printf("\nCadastre no maximo 35 alunos. Digite novo valor: ");
        scanf("%d", &n);
        getchar();
    }

    // Cadastrar n alunos
    for(cont = 0; cont < n; cont++){
            cadastrarAluno(alunos,cont);
            calcularMediaParcial(alunos, cont);
            verificarExame(alunos, cont);
            verificarFaltas(alunos, cont);
    }

	return 0;
}

// Função que cadastra aluno em posição i do vetor
void cadastrarAluno(Pessoa x[], int i){
    int teste;

    printf("\n=== CADASTRO DO ALUNO %d ===", i+1);

    printf("\nNome do aluno: "); // Receber nome do aluno
    fgets(x[i].nome, 100, stdin);
    getchar();

    printf("\nRA: "); // Receber RA
    scanf("%d", &x[i].ra);
    getchar();

    printf("\nNota da P1: "); // Receber nota da P1
    scanf("%f", &x[i].p1);
    getchar();

    printf("\nNota da P2: "); // Receber nota da P2
    scanf("%f", &x[i].p2);
    getchar();

    printf("\nO aluno fez a P3? (1 para sim, 0 para nao) "); // A P3 é opcional
    scanf("%d", &teste);
    getchar();

    if (teste == 1){ // O aluno fez a P3
        printf("\nNota da P3: "); // Receber nota da P3
        scanf("%f", &x[i].p3);
        getchar();
        printf("\n");
    }

    else { // O aluno não fez a P3
        x[i].p3 = -1; // Nota negativa para cálculo de média sem P3
    }

    printf("\nNota do trabalho: "); // Receber nota do trabalho
    scanf("%f", &x[i].trabalho);
    getchar();

    printf("\nNumero de faltas: "); // Receber número de faltas
    scanf("%d", &x[i].faltas);
    getchar();
    printf("\n");
}

// Função que calcula a média parcial do aluno
void calcularMediaParcial(Pessoa x[], int i){
    if(x[i].p3 != -1){ // O aluno fez a P3
        x[i].mediaparcial=(((x[i].p1)+(x[i].p2)+(x[i].p3))/3)*9/10; // A media das provas representa 90% da media parcial
        x[i].mediaparcial+=(x[i].trabalho*1/10); // O trabalho representa 10% da media parcial
        printf("\nMedia parcial do aluno %d (posicao %d), que fez a P3: %.2f\n", i+1, i, x[i].mediaparcial);
    }

    else{ // O aluno nao fez a P3
        x[i].mediaparcial=(((x[i].p1)+(x[i].p2))/2)*9/10; // A media das provas representa 90% da media parcial
        x[i].mediaparcial+=(x[i].trabalho*1/10); // O trabalho representa 10% da media parcial
        printf("\nMedia parcial do aluno %d (posicao %d), que NAO fez a P3: %.2f\n", i+1, i, x[i].mediaparcial);
    }
}

// Função que verifica se o aluno precisa de exame
void verificarExame(Pessoa x[], int i){
    if(x[i].mediaparcial >= 6.0){
            x[i].mediafinal=x[i].mediaparcial; // O aluno foi aprovado por nota
            x[i].exame=-1;
            printf("\nmedia final: %.2f\n", x[i].mediafinal);
    }
    else{
        if(x[i].mediaparcial < 2.5){
            x[i].mediafinal=x[i].mediaparcial; // O aluno foi reprovado por nota
            x[i].exame=-1;
            printf("\nmedia final: %.2f\n", x[i].mediafinal);
        }

        else{
            printf("\nDigite a nota do aluno no exame: ");
            scanf("%f", &x[i].exame);
            getchar();
            x[i].mediafinal=(x[i].mediaparcial*2 + x[i].exame*1)/3;
            printf("\nMedia final do aluno %d (posicao %d): %.2f\n", i+1, i, x[i].mediafinal);
        }
    }
}

// Função que verifica a quantidade de faltas do alunos
void verificarFaltas(Pessoa x[], int i){
    if(x[i].faltas <= 4){
        printf("\nO aluno foi aprovado por presença.\n");
    }
    else{
        printf("\nO aluno foi reprovado por falta.\n");
    }
}
