/* Projeto de Engenharia de Software:
   Calcular a nota final dos alunos e ver se foram aprovados
   Haverá vários alunos cadastrados
*/

// 1º: Cadastrar os alunos em um vetor de structs (Máximo 35)
//      Nome, RA, faltas, P1, P2, P3 (opcional), trabalho e exame (OK)
//	    Cadastrar 1 aluno (OK)
//      Cadastrar n alunos
// 2º: Receber notas e faltas
//	    4 ou menos faltas (Aprovação)
//	    Mais que 4 faltas (Reprovação por falta)
// 3º: Calcular média parcial
//	    (P1+P2)*0.45 + T*0.1 ou (P1+P2+P3)*0.3 + T*0.1
// 4º: Verificar Exame
//	    Média < 2.5 (Reprovação)
//	    2.5 <= Média <= 5.9 (Exame)
//	    Média >= 6 (Aprovação)
// 5º: Calcular nota final
//	    Nota = Média parcial
//	    Ou Nota = (Média Parcial*2 + Exame*1)/3
//		Nota >= 5 (Aprovação)
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
} Pessoa;

// Serão cadastrados no máximo 35 alunos
Pessoa alunos[35];

// Funções utilizadas
void cadastrarAluno(Pessoa x[], int i);

int main(){
    int i = 0;

    // Cadastrar 1 aluno
    cadastrarAluno(alunos,i);

	return 0;
}

void cadastrarAluno(Pessoa x[], int i){
    int teste = 0;

    printf("Nome do aluno %d: ", i+1);
    fgets(x[i].nome,100,stdin);
    getchar();
    // printf("\n%s\n", x[i].nome);

    printf("\nRA: ");
    scanf("%d", &x[i].ra);
    getchar();
    // printf("\n%d\n", x[i].ra);

    printf("\nNumero de faltas: ");
    scanf("%d", &x[i].faltas);
    getchar();
    // printf("\n%d\n", x[i].faltas);

    printf("\nNota da P1: ");
    scanf("%f", &x[i].p1);
    getchar();
    // printf("\n%.2f\n", x[i].p1);

    printf("\nNota da P2: ");
    scanf("%f", &x[i].p2);
    getchar();
    // printf("\n%.2f\n", x[i].p2);

    printf("\nO aluno %d fez a P3? (1 para sim, 0 para não) ", i+1);
    scanf("%d", &teste);
    getchar();

    if (teste==1){
        printf("\nNota da P3: ");
        scanf("%f", &x[i].p3);
        getchar();
        // printf("\n%.2f\n", x[i].p3);
    }

    else {
        x[i].p3 = -1;
        // printf("\n%.0f\n", x[i].p3);
    }

    printf("\nNota do trabalho: ");
    scanf("%f", &x[i].trabalho);
    getchar();
    // printf("\n%.2f\n", x[i].trabalho);
}
