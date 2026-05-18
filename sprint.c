#include <stdio.h>

int main() {
// Configurações do Sistema (Constantes)
const float CAPACIDADE_MAX = 60.0;
const float PRECO_KWH = 1.45;

// Variáveis
float batAtual, batDesejada;
int tipoUsuario;
float energiaConsumida, custoFinal;
int tempoEstimado;

printf("------------------------------------------\n");
printf(" SISTEMA DE RECARGA - SPRINT 1\n");
printf("------------------------------------------\n\n");

// 1. Validação de Entrada da Bateria
do {
printf("Porcentagem atual da bateria (0-99%%): ");
scanf("%f", &batAtual);
printf("Porcentagem desejada (1-100%%): ");
scanf("%f", &batDesejada);

if (batAtual >= batDesejada || batAtual < 0 || batDesejada > 100) {
printf("\n[ERRO] Valores invalidos! A carga final deve ser maior que a inicial.\n");
}
} while (batAtual >= batDesejada || batAtual < 0 || batDesejada > 100);

// 2. Validação do Tipo de Usuário (Melhoria de Robustez)
do {
printf("\nSelecione o perfil do usuario:\n");
printf("[1] Regular (Tarifa normal)\n");
printf("[2] Premium (15%% de desconto)\n");
printf("Escolha: ");
scanf("%d", &tipoUsuario);

if (tipoUsuario != 1 && tipoUsuario != 2) {
printf("[ERRO] Opcao invalida! Digite 1 ou 2.\n");
}
} while (tipoUsuario != 1 && tipoUsuario != 2);

// 3. Simulação da Sessão (Lógica de Loop Corrigida)
printf("\nIniciando recarga...\n");
float i = batAtual;
while (i < batDesejada) {
printf("Carregando... %.1f%%\n", i);
i += 10.0;
if (i > batDesejada) i = batDesejada; // Garante que a última exibição seja o alvo
}
printf("Carregando... %.1f%%\n", batDesejada);
printf("Carga finalizada com sucesso!\n");

// 4. Cálculos
energiaConsumida = ((batDesejada - batAtual) / 100.0) * CAPACIDADE_MAX;
custoFinal = energiaConsumida * PRECO_KWH;

// Regra de Negócio: Desconto Premium
if (tipoUsuario == 2) {
custoFinal *= 0.85;
}

// Tempo estimado: 1 min para cada 2% de carga
tempoEstimado = (int)(batDesejada - batAtual) / 2;

// 5. Relatório de Saída
printf("\n==========================================");
printf("\n RESUMO DA SESSAO ");
printf("\n==========================================");
printf("\nUsuario: %s", (tipoUsuario == 2) ? "PREMIUM" : "REGULAR");
printf("\nEnergia Total: %.2f kWh", energiaConsumida);
printf("\nTempo Estimado: %d minutos", tempoEstimado);
printf("\n------------------------------------------");
printf("\nVALOR A PAGAR: R$ %.2f", custoFinal);
printf("\n==========================================\n");

return 0;
}