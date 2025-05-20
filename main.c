#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int menu, i, opcao, j, eh_valido, usuario_existe, login_valido;
    int largura = 50;
    int max_usuarios = 10;
    int tam_usuario = 20;
    int tam_senha = 50;
    int total_usuarios = 0;
    char usuarios[10][20];
    char senhas[10][50];
    char usuario_digitado[20];
    char senha_digitada[50];

    //Linha superior
    printf("*");
    for(i = 0; i < largura; i++){
        printf("-");
    }
    printf("*\n");

    //Cabeçalho
    printf("|                   LOGIN DO ALUNO                 |\n");

    //Linha inferior
    printf("*");
    for(i = 0; i < largura; i++){
        printf("-");
    }
    printf("*\n");

    //LOGIN
    while(1) {

        printf("1. Cadastrar novo usuario\n");
        printf("2. Fazer login\n");
        printf("3. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        
        if(opcao == 3) {

            printf("Encerrando sistema...\n");
            break;
        }
        
        if(opcao == 1) {
            // Cadastro de novo usuário
            printf("\n--- NOVO CADASTRO ---\n");
            
            // Verifica limite
            if(total_usuarios >= max_usuarios) {
                printf("Limite de usuarios atingido!\n");
                continue;
            }
            
            // Validação do nome de usuário (apenas números)
            while(1) {
                printf("Usuario (apenas numeros): ");
                scanf("%19s", usuario_digitado);
                
                // Verifica se todos são dígitos (sem isdigit)
                eh_valido = 1;
                for(j = 0; usuario_digitado[j] != '\0'; j++) {
                    if(usuario_digitado[j] < '0' || usuario_digitado[j] > '9') {
                        eh_valido = 0;
                        break;
                    }
                }
                
                if(eh_valido) break;
                printf("Erro: O usuario deve conter apenas numeros (0-9)!\n");
            }
            
            // Verifica se usuário já existe (sem strcmp)
            usuario_existe = 0;
            for(i = 0; i < total_usuarios; i++) {
                // Comparação manual de strings
                int sao_iguais = 1;
                for(j = 0; usuarios[i][j] != '\0' || usuario_digitado[j] != '\0'; j++) {
                    if(usuarios[i][j] != usuario_digitado[j]) {
                        sao_iguais = 0;
                        break;
                    }
                }
                if(sao_iguais) {
                    usuario_existe = 1;
                    break;
                }
            }
            
            if(usuario_existe) {
                printf("Erro: Usuario ja cadastrado!\n");
                continue;
            }
            
            // Solicita a senha
            printf("Senha: ");
            scanf("%49s", senhas[total_usuarios]);
            
            // Copia manual do usuário (sem strcpy)
            for(j = 0; usuario_digitado[j] != '\0'; j++) {
                usuarios[total_usuarios][j] = usuario_digitado[j];
            }
            usuarios[total_usuarios][j] = '\0'; // Terminador
            
            total_usuarios++;
            printf("Usuario cadastrado com sucesso!\n");
        }
        else if(opcao == 2) {

            printf("\n--- LOGIN ---\n");
            
            printf("Usuario: ");
            scanf("%19s", usuario_digitado);
            
            printf("Senha: ");
            scanf("%49s", senha_digitada);
            
            // Verifica credenciais
            login_valido = 0;
            for(i = 0; i < total_usuarios; i++) {
                // Compara usuário
                int usuario_igual = 1;
                for(j = 0; usuarios[i][j] != '\0' || usuario_digitado[j] != '\0'; j++) {
                    if(usuarios[i][j] != usuario_digitado[j]) {
                        usuario_igual = 0;
                        break;
                    }
                }
                
                // Compara senha
                int senha_igual = 1;
                for(j = 0; senhas[i][j] != '\0' || senha_digitada[j] != '\0'; j++) {
                    if(senhas[i][j] != senha_digitada[j]) {
                        senha_igual = 0;
                        break;
                    }
                }
                
                if(usuario_igual && senha_igual) {
                    login_valido = 1;
                    break;
                }
            }
            
            if(login_valido) {
                printf("Login realizado com sucesso! Bem-vindo, %s.\n", usuario_digitado);

                //Menu logado
                do{
                    printf("Escolha uma das opções abaixo:\n\n");
                    printf("1) Informacoes Cadastrais\n");
                    printf("2) Notas, Frequencia, P.Ensino\n");
                    printf("3) Pagamentos\n");
                    printf("4) Declaracoes e Historicos\n");
                    printf("5) Sair\n\n");
                    scanf("%d", &menu);

                    if(menu == 1){
                        
                        int i;
                        int largura = 50;

                        //Linha superior
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");
                        
                        //Dados da tabela
                        printf("Matrícula: 19070211\n");
                        printf("Nome: CAIO AUGUSTO FREITAS BARBOSA DE SOUZA\n");
                        printf("Curso: CIÊNCIA DA COMPUTAÇÃO\n");
                        printf("Período: 1º\n");
                        printf("Situação: MATRICULADO\n");
                        printf("Dat Mat: 05/02/2025\n");
                        printf("Turno: TARDE\n");
                        printf("Turma: CC1TA\n");
                        printf("Dat Nasc: 09/06/1994\n");
                        printf("E-mail: caioafreitasbarbosa@gmail.com\n");
                        printf("Telefone: 3230-4917\n");
                        printf("Cidade: BELÉM\t UF: PA\n");
                        printf("Endereço: RUA DOS MUNDURUCUS\n");
                        printf("Bairro: CREMAÇÃO\n");

                        //Linha inferior
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n\n");
                    }else if(menu == 2){
                        
                        int i;
                        int largura = 100;

                        //Linha superior Notas
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Cabeçalho Notas
                        printf("|              DISCIPLINAS              |TURMA|1º BIM|2º BIM|MÉDIA BIM|3ª AVAL|MÉDIA FINAL|SIT. FINAL|\n");

                        //Linha divisória
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Dados da tabela Notas
                        printf("|PROGRAMAÇÃO DE SOFTWARE                |CC1TA|08.00 |10.00 |  09.00  |   -   |   09.00   |     A    |\n");
                        printf("|PENSAMENTO COMPUTACIONAL PARA CIENTISTA|CC1TA|08.40 |10.00 |  09.20  |   -   |   09.20   |     A    |\n");
                        printf("|ALGORITMO E CODIFICACAO DE SISTEMAS    |CC1TA|10.00 |10.00 |  10.00  |   -   |   10.00   |     A    |\n");
                        printf("|LOGICA DIGITAL                         |CC1TA|10.00 |10.00 |  10.00  |   -   |   10.00   |     A    |\n");
                        printf("|NEGOCIOS DIGITAIS                      |CC1TA|08.50 |10.00 |  09.30  |   -   |   09.30   |     A    |\n");

                        //Linha inferior Notas
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");
                        
                        printf("Sit. Final: A - Aprovado R - Reprovado RF - Reprovado por Faltas 3ª - 3ª Avaliação\n\n");

                        //Linha superior Faltas
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Cabeçalho Faltas
                        printf("|                                       |                       FALTAS                  |            |\n");
                        printf("|              DISCIPLINAS              |JAN|FEV|MAR|ABR|MAI|JUN|JUL|AGO|SET|OUT|NOV|DEZ|      %%     |\n");

                        //Linha divisória
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Dados da tabela Faltas
                        printf("|PROGRAMAÇÃO DE SOFTWARE                | - | 2 | 2 | 2 | - | - | - | - | - | - | - | - |      94    |\n");
                        printf("|PENSAMENTO COMPUTACIONAL PARA CIENTISTA| - | 2 | 0 | 4 | - | - | - | - | - | - | - | - |      92    |\n");
                        printf("|ALGORITMO E CODIFICACAO DE SISTEMAS    | - | 3 | 0 | 0 | - | - | - | - | - | - | - | - |      95    |\n");
                        printf("|LOGICA DIGITAL                         | - | 2 | 0 | 2 | - | - | - | - | - | - | - | - |      95    |\n");
                        printf("|NEGOCIOS DIGITAIS                      | - | 0 | 0 | 0 | - | - | - | - | - | - | - | - |     100    |\n");

                        //Linha inferior Faltas
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Linha superior PE
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Cabeçalho PE
                        printf("|             DISCIPLINAS               |                         PROFESSOR                          |\n");

                        //Linha divisória
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Dados da tabela PE
                        printf("|PROGRAMAÇÃO DE SOFTWARE                |RICARDO MELO CASSEB DO CARMO                                |\n");
                        printf("|PENSAMENTO COMPUTACIONAL PARA CIENTISTA|ALESSANDRA NATASHA ALCANTRA BARREIROS BAGANHA               |\n");
                        printf("|ALGORITMO E CODIFICACAO DE SISTEMAS    |PEDRO HENRIQUE SALES GIROTTO                                |\n");
                        printf("|LOGICA DIGITAL                         |POLYANA SANTOS FONSECA NASCIMENTO                           |\n");
                        printf("|NEGOCIOS DIGITAIS                      |RENATA NOVAES DA SILVA                                      |\n");

                        //Linha inferior PE
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");
                    }else if(menu == 3){
                        
                        int i;
                        int largura = 100;

                        //Linha superior
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Cabeçalho
                        printf("|                                     MENSALIDADES ESCOLARES                                         |\n");

                        //Linha divisória
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Dados da tabela
                        printf("|MENSALIDADE|DATA DOS VENCIMENTOS|    VALOR    |DATA DO PAGAMENTO| VALOR PAGO  |                     |\n");
                        printf("|     1     |      06/01/25      | R$ 2.526,63 |    30/01/2025   | R$ 2.526,63 |                     |\n");
                        printf("|     2     |      28/02/25      | R$ 1.267,91 |    27/02/2025   | R$ 1.204,51 |                     |\n");
                        printf("|     3     |      31/03/25      | R$ 1.267,91 |    31/03/2025   | R$ 1.204,51 |                     |\n");
                        printf("|     4     |      30/04/25      | R$ 1.267,91 |    29/04/2025   | R$ 1.204,51 |                     |\n");
                        printf("|     5     |      30/05/25      | R$ 1.267,91 |    29/05/2025   | R$ 1.204,51 |                     |\n");

                        //Linha inferior
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");
                    }else if(menu == 4){
                        
                        int i;
                        int largura = 100;

                        //Linha superior
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Cabeçalho
                        printf("|                      DECLARAÇÕES E HISTÓRICO ESCOLAR (Para simples conferência)                    |\n");

                        //Linha divisória
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");

                        //Dados da tabela
                        printf("|DECLARAÇÃO DE IMPOSTO DE RENDA           |                        EMITIR                            |\n");
                        printf("|DECLARAÇÃO DE REGULARIDADE ACADÊMICA     |                        EMITIR                            |\n");
                        printf("|HISTÓRICO ESCOLAR                        |                        EMITIR                            |\n");
                        printf("|DOCUMENTO DE INFORMAÇÕES ACADÊMICAS      |                        EMITIR                            |\n");

                        //Linha inferior
                        printf("*");
                        for(i = 0; i < largura; i++){
                            printf("-");
                        }
                        printf("*\n");
                    }


                } while (menu != 5);
            } else {
                printf("Usuario ou senha incorretos!\n");
            }
        }
        else {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}