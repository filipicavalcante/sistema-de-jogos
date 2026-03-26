
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int opcao;
    char continuar;

    while (1) {
        system("cls");
        printf("=== MENU DE JOGOS ===\n");
        printf("1 - Perguntas e Respostas\n");
        printf("2 - Cobra na Caixa\n");
        printf("3 - Gousmas War\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            char resposta;
            char jogar_novamente;
            while (1) {
                system("cls");
                printf("Bem vindo ao jogo Perguntas e Respostas\n");
                printf("\nResponda apenas com a, b, c, d\n");
                printf("\nVamos para a primeira pergunta.\n");
                printf("Qual e o unico mamifero capaz de consehuir se guiar pelo som?\n");
                printf("a) Pinguim  b) Morcego  c) Esquilo-voador  d) falcão\n");
                printf("Sua resposta: ");
                scanf(" %c", &resposta);
                if (resposta == 'b') {
                    printf("Resposta correta!\n");
                } else {
                    printf("Incorreta! A resposta correta: b) Morcego\n");
                }

                printf("\nQual e o maior orgão do  ser humano ?\n");
                printf("a) intestino   b) figado  c) pele   d) coração\n");
                printf("Sua resposta: ");
                scanf(" %c", &resposta);
                if (resposta == 'c') {
                    printf("\nResposta correta!\n");
                } else {
                    printf("\nIncorreta! A resposta correta: c) 206\n");
                }

                printf("\nQual o maior continente do mundo?\n");
                printf("a) Asia  b) Oceania  c) Africa  d) Europa\n");
                printf("Sua resposta: ");
                scanf(" %c", &resposta);
                if (resposta == 'a') {
                    printf("\nResposta correta!\n");
                } else {
                    printf("\nIncorreta! A resposta correta: a) Asia\n");
                }

                printf("\nQual e a velocidade aproximada da luz no vacuo, em quilometros por segundo?\n");
                printf("a) 300  b) 3.000  c) 30.000  d) 300.000\n");
                printf("Sua resposta: ");
                scanf(" %c", &resposta);
                if (resposta == 'd') {
                    printf("\nResposta correta!\n");
                } else {
                    printf("\nIncorreta! A resposta correta: d) 300.000\n");
                }

                printf("\nQual e o elemento quimico e usado em usinas nucleares para gerar energia?\n");
                printf("a) Uranio  b) Plutonio  c) Torio  d) Radio\n");
                printf("Sua resposta: ");
                scanf(" %c", &resposta);
                if (resposta == 'a') {
                    printf("\nResposta correta!\n");
                } else {
                    printf("\nIncorreta! A resposta correta: a) Uranio\n");
                }

                printf("\nFim do jogo! Deseja jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);
                if (jogar_novamente == 'n' || jogar_novamente == 'N') {
                    break;
                }
            }
        }

        if (opcao == 2) {
            char *nomes[7] = {"Ashe", "Will", "Jeff", "Isis", "Rita", "Coby", "Rick"};
            char nome_jogador1[5], nome_jogador2[5];
            int caixas[5];
            int jogador_atual, escolha, jogo_rodando = 1, escolha_j1, escolha_j2;
            int posicao_botao, posicao_cobra;
            char jogar_novamente;
            while (1) {
                system("cls");
                srand(time(NULL));
                printf("Bem-vindo a Cobra na Caixa!\n");

                printf("\nEscolha seu nome para Jogador 1:\n");
                printf("1. %s\n", nomes[0]);
                printf("2. %s\n", nomes[1]);
                printf("3. %s\n", nomes[2]);
                printf("4. %s\n", nomes[3]);
                printf("5. %s\n", nomes[4]);
                printf("6. %s\n", nomes[5]);
                printf("7. %s\n", nomes[6]);
                printf("Digite o numero do seu nome (1-7): ");
                scanf("%d", &escolha_j1);
                while (escolha_j1 < 1 || escolha_j1 > 7) {
                    printf("Escolha invalida! Tente novamente: ");
                    scanf("%d", &escolha_j1);
                }
                strcpy(nome_jogador1, nomes[escolha_j1 - 1]);

                printf("\nEscolha seu nome para Jogador 2:\n");
                printf("1. %s\n", nomes[0]);
                printf("2. %s\n", nomes[1]);
                printf("3. %s\n", nomes[2]);
                printf("4. %s\n", nomes[3]);
                printf("5. %s\n", nomes[4]);
                printf("6. %s\n", nomes[5]);
                printf("7. %s\n", nomes[6]);
                printf("Digite o numero do seu nome (1-7): ");
                scanf("%d", &escolha_j2);
                while (escolha_j2 < 1 || escolha_j2 > 7) {
                    printf("Escolha invalida! Tente novamente: ");
                    scanf("%d", &escolha_j2);
                }
                strcpy(nome_jogador2, nomes[escolha_j2 - 1]);

                jogo_rodando = 1;
                jogador_atual = rand() % 2 + 1;

                while (jogo_rodando) {
                    caixas[0] = 0;
                    caixas[1] = 0;
                    caixas[2] = 0;
                    caixas[3] = 0;
                    caixas[4] = 0;

                    posicao_botao = rand() % 5;
                    caixas[posicao_botao] = 1;
                    do {
                        posicao_cobra = rand() % 5;
                    } while (posicao_cobra == posicao_botao);
                    caixas[posicao_cobra] = 2;

                    printf("\nVez de %s. Escolha uma caixa (1-5): ",
                           jogador_atual == 1 ? nome_jogador1 : nome_jogador2);
                    scanf("%d", &escolha);

                    if (escolha < 1 || escolha > 5) {
                        printf("Escolha invalida! Tente novamente.\n");
                    } else {
                        if (caixas[escolha - 1] == 0) {
                            printf("Caixa vazia. Proximo jogador!\n");
                        } else if (caixas[escolha - 1] == 1) {
                            printf("%s encontrou o botao! \nVoce venceu!\n",
                                   jogador_atual == 1 ? nome_jogador1 : nome_jogador2);
                            jogo_rodando = 0;
                        } else {
                            printf("%s encontrou a cobra! \nVoce perdeu!\n",
                                   jogador_atual == 1 ? nome_jogador1 : nome_jogador2);
                            jogo_rodando = 0;
                        }

                        if (jogo_rodando) {
                            jogador_atual = (jogador_atual == 1) ? 2 : 1;
                        }
                    }
                }

                printf("\nFim do jogo! Deseja jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);
                if (jogar_novamente == 'n' || jogar_novamente == 'N') {
                    break;
                }
            }
        }

        if (opcao == 3) {
            int furia1_j1, furia2_j1;
            int furia1_j2, furia2_j2;
            int viva1_j1, viva2_j1;
            int viva1_j2, viva2_j2;
            int num_gousmas_j1, num_gousmas_j2;
            int turno, escolha, gousma, alvo, jogar_novamente;
            while (1) {
                system("cls");
                furia1_j1 = 1;
                furia2_j1 = 1;
                furia1_j2 = 1;
                furia2_j2 = 1;
                viva1_j1 = 1;
                viva2_j1 = 1;
                viva1_j2 = 1;
                viva2_j2 = 1;
                num_gousmas_j1 = 2;
                num_gousmas_j2 = 2;
                turno = 1;

                printf("Jogo das Gousmas comecou!\n");

                while (num_gousmas_j1 > 0 && num_gousmas_j2 > 0) {
                    printf("\nJogador 1: ");
                    if (viva1_j1 == 1) printf("Gousma 1 (Furia: %d) ", furia1_j1);
                    if (viva2_j1 == 1) printf("Gousma 2 (Furia: %d) ", furia2_j1);
                    printf("\nJogador 2: ");
                    if (viva1_j2 == 1) printf("Gousma 1 (Furia: %d) ", furia1_j2);
                    if (viva2_j2 == 1) printf("Gousma 2 (Furia: %d) ", furia2_j2);
                    printf("\n");

                    printf("\nVez do Jogador %d\n", turno);
                    printf("1 - Atacar ou 2 - Dividir  ");
                    scanf("%d", &escolha);

                    if (escolha == 1) {
                        printf("Qual Gousma ataca (1 ou 2)? ");
                        scanf("%d", &gousma);
                        printf("Qual Gousma do inimigo (1 ou 2)? ");
                        scanf("%d", &alvo);
                        if (turno == 1) {
                            if (gousma == 1 && viva1_j1 == 1) {
                                if (alvo == 1 && viva1_j2 == 1) {
                                    if (furia1_j1 == 0) furia1_j2 += 1;
                                    else { furia1_j2 += furia1_j1; furia1_j1 = 0; }
                                    if (furia1_j2 > 5) {
                                        viva1_j2 = 0;
                                        num_gousmas_j2--;
                                        printf("Gousma 1 do Jogador 2 morreu!\n");
                                    }
                                } else if (alvo == 2 && viva2_j2 == 1) {
                                    if (furia1_j1 == 0) furia2_j2 += 1;
                                    else { furia2_j2 += furia1_j1; furia1_j1 = 0; }
                                    if (furia2_j2 > 5) {
                                        viva2_j2 = 0;
                                        num_gousmas_j2--;
                                        printf("Gousma 2 do Jogador 2 morreu!\n");
                                    }
                                }
                            } else if (gousma == 2 && viva2_j1 == 1) {
                                if (alvo == 1 && viva1_j2 == 1) {
                                    if (furia2_j1 == 0) furia1_j2 += 1;
                                    else { furia1_j2 += furia2_j1; furia2_j1 = 0; }
                                    if (furia1_j2 > 5) {
                                        viva1_j2 = 0;
                                        num_gousmas_j2--;
                                        printf("Gousma 1 do Jogador 2 morreu!\n");
                                    }
                                } else if (alvo == 2 && viva2_j2 == 1) {
                                    if (furia2_j1 == 0) furia2_j2 += 1;
                                    else { furia2_j2 += furia2_j1; furia2_j1 = 0; }
                                    if (furia2_j2 > 5) {
                                        viva2_j2 = 0;
                                        num_gousmas_j2--;
                                        printf("Gousma 2 do Jogador 2 morreu!\n");
                                    }
                                }
                            }
                        } else {
                            if (gousma == 1 && viva1_j2 == 1) {
                                if (alvo == 1 && viva1_j1 == 1) {
                                    if (furia1_j2 == 0) furia1_j1 += 1;
                                    else { furia1_j1 += furia1_j2; furia1_j2 = 0; }
                                    if (furia1_j1 > 5) {
                                        viva1_j1 = 0;
                                        num_gousmas_j1--;
                                        printf("Gousma 1 do Jogador 1 morreu!\n");
                                    }
                                } else if (alvo == 2 && viva2_j1 == 1) {
                                    if (furia1_j2 == 0) furia2_j1 += 1;
                                    else { furia2_j1 += furia1_j2; furia1_j2 = 0; }
                                    if (furia2_j1 > 5) {
                                        viva2_j1 = 0;
                                        num_gousmas_j1--;
                                        printf("Gousma 2 do Jogador 1 morreu!\n");
                                    }
                                }
                            } else if (gousma == 2 && viva2_j2 == 1) {
                                if (alvo == 1 && viva1_j1 == 1) {
                                    if (furia2_j2 == 0) furia1_j1 += 1;
                                    else { furia1_j1 += furia2_j2; furia2_j2 = 0; }
                                    if (furia1_j1 > 5) {
                                        viva1_j1 = 0;
                                        num_gousmas_j1--;
                                        printf("Gousma 1 do Jogador 1 morreu!\n");
                                    }
                                } else if (alvo == 2 && viva2_j1 == 1) {
                                    if (furia2_j2 == 0) furia2_j1 += 1;
                                    else { furia2_j1 += furia2_j2; furia2_j2 = 0; }
                                    if (furia2_j1 > 5) {
                                        viva2_j1 = 0;
                                        num_gousmas_j1--;
                                        printf("Gousma 2 do Jogador 1 morreu!\n");
                                    }
                                }
                            }
                        }
                    } else if (escolha == 2) {
                        printf("Qual Gousma dividir (1 ou 2)? ");
                        scanf("%d", &gousma);
                        if (turno == 1 && num_gousmas_j1 < 2) {
                            if (gousma == 1 && viva1_j1 == 1 && viva2_j1 == 0) {
                                furia2_j1 = furia1_j1 / 2;
                                furia1_j1 = furia1_j1 - furia2_j1;
                                viva2_j1 = 1;
                                num_gousmas_j1++;
                                printf("Gousma 1 do Jogador 1 dividiu!\n");
                            } else if (gousma == 2 && viva2_j1 == 1 && viva1_j1 == 0) {
                                furia1_j1 = furia2_j1 / 2;
                                furia2_j1 = furia2_j1 - furia1_j1;
                                viva1_j1 = 1;
                                num_gousmas_j1++;
                                printf("Gousma 2 do Jogador 1 dividiu!\n");
                            }
                        } else if (turno == 2 && num_gousmas_j2 < 2) {
                            if (gousma == 1 && viva1_j2 == 1 && viva2_j2 == 0) {
                                furia2_j2 = furia1_j2 / 2;
                                furia1_j2 = furia1_j2 - furia2_j2;
                                viva2_j2 = 1;
                                num_gousmas_j2++;
                                printf("Gousma 1 do Jogador 2 dividiu!\n");
                            } else if (gousma == 2 && viva2_j2 == 1 && viva1_j2 == 0) {
                                furia1_j2 = furia2_j2 / 2;
                                furia2_j2 = furia2_j2 - furia1_j2;
                                viva1_j2 = 1;
                                num_gousmas_j2++;
                                printf("Gousma 2 do Jogador 2 dividiu!\n");
                            }
                        } else {
                            printf("Nao pode dividir!\n");
                        }
                    }

                    if (turno == 1) turno = 2;
                    else turno = 1;
                }

                printf("\nJogador 1: ");
                if (viva1_j1 == 1) printf("Gousma 1 (Furia: %d) ", furia1_j1);
                if (viva2_j1 == 1) printf("Gousma 2 (Furia: %d) ", furia2_j1);
                printf("\nJogador 2: ");
                if (viva1_j2 == 1) printf("Gousma 1 (Furia: %d) ", furia1_j2);
                if (viva2_j2 == 1) printf("Gousma 2 (Furia: %d) ", furia2_j2);
                printf("\n");
                if (num_gousmas_j1 == 0) printf("\nJogador 2 ganhou!\n");
                else printf("\nJogador 1 ganhou!\n");

                printf("\nQuer jogar novamente? (s/n): ");
                scanf(" %c", &jogar_novamente);
                if (jogar_novamente == 'n' || jogar_novamente == 'N') {
                    break;
                }
            }
        }

        if (opcao == 4) {
            system("cls");
            printf("Obrigado por jogar! Ate logo!\n");
            return 0;
        }

        if (opcao < 1 || opcao > 4) {
            system("cls");
            printf("Opcao errada! Tente de novo.\n");
            scanf("%d", &opcao);
        }
    }

    return 0;
}
