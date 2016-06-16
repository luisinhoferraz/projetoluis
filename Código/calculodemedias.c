#include <stdio.h>
#include <string.h>

// Dados de cada aluno do tipo Pessoa
typedef struct pessoa {
	char nome[100];
	int ra, faltas, apnota, appresenca;
	float p1, p2, p3, trabalho, exame;
	float mediaparcial, mediafinal;
} Pessoa;

// Serão cadastrados no máximo 35 alunos
Pessoa alunos[35];

// Funções utilizadas
void cadastrarAluno(Pessoa x[], int i);
void calcularMediaFinal(Pessoa x[], int i);
void verificarFaltas(Pessoa x[], int i);
void resultadoFinal(Pessoa x[], int i);
void gerarRelatorio(float i);

// Contadores de aprovação e reprovação
float aprovacao = 0.0, reprovacao = 0.0;

int main(){
    int n, cont, teste;
    float i;

    printf("|------------- Bem vindo ao sistema Calculo de Medias! ------------|\n");
    printf("\nDeseja avaliar quantos alunos? ");
    scanf("%d", &n);
    getchar();

    if(n < 0){
        n = 0 - n;
    }

    while(n > 35){
        printf("\nO limite eh de 35 alunos. Digite novamente a quantidade: ");
        scanf("%d", &n);
        getchar();
    }

    // Cadastrar n alunos
    for(cont = 0; cont < n; cont++){
        cadastrarAluno(alunos,cont);
        calcularMediaFinal(alunos, cont);
        verificarFaltas(alunos, cont);
        resultadoFinal(alunos, cont);
    }

    // Gerar relatorio
    printf("\nDeseja obter um relatorio da turma?");

    do{
        printf("\n(1) Sim ou (0) Nao\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &teste);
        getchar();
    } while ((teste != 1) && (teste != 0));

    if(teste == 1){
        i = n;
        gerarRelatorio(i);
    }

    getchar();

	return 0;
}

// Função que cadastra aluno em posição i do vetor
void cadastrarAluno(Pessoa x[], int i){
    int teste;

    printf("\n");
    printf("|------------------------------------------------------------------|\n");
    printf("|------------------- CALCULO DE MEDIA DO ALUNO %d ------------------|\n", i+1);
    printf("|------------------------------------------------------------------|\n");

    printf("\nNome do aluno: "); // Receber nome do aluno
    fgets(x[i].nome, 100, stdin);
    getchar();

    printf("\nRegistro Academico: "); // Receber RA
    scanf("%d", &x[i].ra);
    getchar();

    printf("\nO aluno fez a P3?\n"); // A P3 é opcional
    do {
        printf("(1) Sim ou (0) Nao\n");
        printf("Digite a opcao escolhida: ");
        scanf("%d", &teste);
        getchar();
    } while ((teste != 0) && (teste != 1));

    printf("\nNota da P1: "); // Receber nota da P1
    scanf("%f", &x[i].p1);
    getchar();

    while((x[i].p1 > 10) || (x[i].p1 < 0)){
        printf("\nO valor deve estar entre 0 e 10. Digite novo valor: "); // Receber nota da P1
        scanf("%f", &x[i].p1);
        getchar();
    }

    printf("\nNota da P2: "); // Receber nota da P2
    scanf("%f", &x[i].p2);
    getchar();

    while((x[i].p2 > 10) || (x[i].p2 < 0)){
        printf("\nO valor deve estar entre 0 e 10. Digite novo valor: "); // Receber nota da P1
        scanf("%f", &x[i].p2);
        getchar();
    }

    if (teste == 1){ // O aluno fez a P3
        printf("\nNota da P3: "); // Receber nota da P3
        scanf("%f", &x[i].p3);
        getchar();

        while((x[i].p3 > 10) || (x[i].p3 < 0)){
            printf("\nO valor deve estar entre 0 e 10. Digite novo valor: "); // Receber nota da P1
            scanf("%f", &x[i].p3);
            getchar();
        }
    }

    else { // O aluno não fez a P3
        x[i].p3 = -1; // Nota negativa para cálculo de média sem P3
    }

    printf("\nNota do trabalho: "); // Receber nota do trabalho
    scanf("%f", &x[i].trabalho);
    getchar();

    while((x[i].trabalho > 10) || (x[i].trabalho < 0)){
        printf("\nO valor deve estar entre 0 e 10. Digite novo valor: "); // Receber nota da P1
        scanf("%f", &x[i].trabalho);
        getchar();
    }

    printf("\nNumero de faltas do aluno: "); // Receber número de faltas
    scanf("%d", &x[i].faltas);
    getchar();

    while(x[i].faltas < 0){
        printf("\nO valor deve ser maior ou igual a 0. Digite novo valor: "); // Receber nota da P1
        scanf("%d", &x[i].faltas);
        getchar();
    }
}

// Função que calcula a média final do aluno
void calcularMediaFinal(Pessoa x[], int i){
    if(x[i].p3 != -1){ // O aluno fez a P3
        x[i].mediaparcial=(((x[i].p1)+(x[i].p2)+(x[i].p3))/3)*9/10; // A media das provas representa 90% da media parcial
        x[i].mediaparcial+=(x[i].trabalho*1/10); // O trabalho representa 10% da media parcial
    }

    else{ // O aluno nao fez a P3
        x[i].mediaparcial=(((x[i].p1)+(x[i].p2))/2)*9/10; // A media das provas representa 90% da media parcial
        x[i].mediaparcial+=(x[i].trabalho*1/10); // O trabalho representa 10% da media parcial
    }

    if(x[i].mediaparcial >= 6.0){ // O aluno foi aprovado direto
            x[i].mediafinal=x[i].mediaparcial;
            x[i].apnota=1;
            printf("\nA media final do aluno %d eh: %.2f\n", i+1, x[i].mediafinal);
    }
    else{
        if(x[i].mediaparcial < 2.5){ // O aluno foi reprovado direto
            x[i].mediafinal=x[i].mediaparcial;
            x[i].apnota=0;
            printf("\nA media final do aluno %d eh: %.2f\n", i+1, x[i].mediafinal);
        }

        else{ // O aluno precisou de exame
            printf("\nDigite a nota do aluno no exame: ");
            scanf("%f", &x[i].exame);
            getchar();

                while((x[i].exame > 10) || (x[i].exame < 0)){
                    printf("\nO valor deve estar entre 0 e 10. Digite novo valor: "); // Receber nota da P1
                    scanf("%f", &x[i].exame);
                    getchar();
                }

            x[i].mediafinal=(x[i].mediaparcial*2 + x[i].exame*1)/3;
            if(x[i].mediafinal>=5){
                x[i].apnota=1; // O aluno foi aprovado por nota
            }
            else{
                x[i].apnota=0; // O aluno foi reprovado por nota
            }
            printf("\nA media final do aluno %d eh: %.2f\n", i+1, x[i].mediafinal);
        }
    }

}

// Função que verifica a quantidade de faltas do alunos
void verificarFaltas(Pessoa x[], int i){
    if(x[i].faltas <= 4){
        x[i].appresenca=1; // O aluno foi aprovado por presenca
    }
    else{
        x[i].appresenca=0; // O aluno foi reprovado por falta
    }
}

// Função que exibe o resultado final do aluno
void resultadoFinal(Pessoa x[], int i){
    if((x[i].apnota==1)&&(x[i].appresenca==1)) {
        aprovacao++;
        printf("\n\nRESULTADO FINAL DO ALUNO %s O aluno foi aprovado por nota e por presenca.\n", x[i].nome);
    }
    else{
        if(x[i].apnota==0){
            reprovacao++;
            printf("\n\nRESULTADO FINAL DO ALUNO %s O aluno foi reprovado por nota.\n", x[i].nome);
        }
        else{
            reprovacao++;
            printf("\n\nRESULTADO FINAL DO ALUNO %s O aluno foi reprovado por falta.\n", x[i].nome);
        }
    }
}

// Função que gera o relatório de aprovações e reprovações totais da turma
void gerarRelatorio(float i){
    float taxaap = 0.0, taxarep = 0.0;

    printf("\n");
    printf("|------------------------------------------------------------------|\n");
    printf("| Total de aprovacoes: %.0f         | Total de reprovacoes: %.0f         |\n", aprovacao, reprovacao);
    printf("|------------------------------------------------------------------|\n");
    taxaap = (aprovacao/i)*100;
    taxarep = (reprovacao/i)*100;
    printf("| Porcentagem de aprovacao: %.1f | Porcentagem de reprovacao: %.1f |\n", taxaap, taxarep);
    printf("|------------------------------------------------------------------|\n");
}
