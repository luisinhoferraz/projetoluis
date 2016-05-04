/* Projeto de Engenharia de Software:
   Calcular a nota final dos alunos e ver se foram aprovados
   Haver� v�rios alunos cadastrados
*/

// 1�: Cadastrar os alunos em um vetor de structs (M�ximo 35)
//      Nome, RA, faltas, P1, P2, P3 (opcional), trabalho e exame (OK)
//	    Cadastrar 1 aluno (OK)
//      Cadastrar n alunos (OK)
// 2�: Calcular m�dia parcial
//	    (P1+P2)*0.45 + T*0.1 ou (P1+P2+P3)*0.3 + T*0.1
// 3�: Verificar Exame
//	    M�dia < 2.5 (Reprova��o)
//	    2.5 <= M�dia <= 5.9 (Exame)
//	    M�dia >= 6 (Aprova��o)
// 4�: Calcular nota final
//	    Nota = M�dia parcial
//	    Ou Nota = (M�dia Parcial*2 + Exame*1)/3
//		Nota >= 5 (Aprova��o)
// 5�: Avaliar faltas
//	    4 ou menos faltas (Aprova��o)
//	    Mais que 4 faltas (Reprova��o por falta)
// 6�: Exibir aprova��o/reprova��o
// 7�: Op��o de relat�rio de aprova��es (Requisito inconsciente)
//	    Alunos aprovados
//	    Alunos reprovados
//	    Total de alunos
//	    Taxas de aprova��o e de reprova��o

#include <stdio.h>
#include <string.h>

// Dados de cada aluno do tipo Pessoa
typedef struct pessoa {
	char nome[100];
	int ra, faltas;
	float p1, p2, p3, trabalho, exame;
} Pessoa;

// Ser�o cadastrados no m�ximo 35 alunos
Pessoa alunos[35];

// Fun��es utilizadas
void cadastrarAluno(Pessoa x[], int i);
// Teste: void mostrarAlunos (Pessoa x[], int i);

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
    }

    /* Teste
    for(cont = 0; cont < n; cont++){
            mostrarAlunos(alunos,cont);
    }
    */

	return 0;
}

// Fun��o que cadastra aluno em posi��o i do vetor
void cadastrarAluno(Pessoa x[], int i){
    int teste;

    printf("\n=== CADASTRO DO ALUNO %d ===", i+1);

    printf("\nNome do aluno: "); // Receber nome do aluno
    fgets(x[i].nome, 100, stdin);
    getchar();
    // Teste: printf("\n%s\n", x[i].nome);

    printf("\nRA: "); // Receber RA
    scanf("%d", &x[i].ra);
    getchar();
    // Teste: printf("\n%d\n", x[i].ra);

    printf("\nNota da P1: "); // Receber nota da P1
    scanf("%f", &x[i].p1);
    getchar();
    // Teste: printf("\n%.2f\n", x[i].p1);

    printf("\nNota da P2: "); // Receber nota da P2
    scanf("%f", &x[i].p2);
    getchar();
    // Teste: printf("\n%.2f\n", x[i].p2);

    printf("\nO aluno fez a P3? (1 para sim, 0 para nao) "); // A P3 � opcional
    scanf("%d", &teste);
    getchar();

    if (teste == 1){ // O aluno fez a P3
        printf("\nNota da P3: "); // Receber nota da P3
        scanf("%f", &x[i].p3);
        getchar();
        // Teste: printf("\n%.2f\n", x[i].p3);
        printf("\n");
    }

    else { // O aluno n�o fez a P3
        x[i].p3 = -1; // Nota negativa para c�lculo de m�dia sem P3
        // Teste: printf("\n%.0f\n", x[i].p3);
    }

    printf("\nNota do trabalho: "); // Receber nota do trabalho
    scanf("%f", &x[i].trabalho);
    getchar();
    // Teste: printf("\n%.2f\n", x[i].trabalho);

    printf("\nNumero de faltas: "); // Receber n�mero de faltas
    scanf("%d", &x[i].faltas);
    getchar();
    // Teste: printf("\n%d\n", x[i].faltas);
    printf("\n");
}

// Fun��o que imprime todos os dados do aluno (ser� excluida posteriormente)
void mostrarAlunos (Pessoa x[], int i){
    printf("\n=== Aluno %d (posicao %d) ===", i+1, i);
    printf("\nNome: %s", x[i].nome);
    printf("\nRA: %d", x[i].ra);
    printf("\nNota da P1: %.2f", x[i].p1);
    printf("\nNota da P2: %.2f", x[i].p2);
    printf("\nNota da P3: %.2f", x[i].p3);
    printf("\nNota do trabalho: %.2f", x[i].trabalho);
    printf("\nFaltas: %d\n", x[i].faltas);
}
