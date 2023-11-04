#include <stdio.h>
#include <string.h>

// Estrutura para representar uma conta bancária
typedef struct {
    char tipo[20];    // Tipo da conta (corrente, salário, poupança, investimento, etc.)
    double saldo;     // Saldo da conta
} ContaBancaria;

// Função para verificar o saldo em todas as contas e gerar mensagem em caso de saldo insuficiente
void verificarSaldo(ContaBancaria contas[], int numContas, double valorRequisitado) {
    int saldoSuficiente = 1;  // Variável para rastrear se há saldo suficiente em todas as contas
    int i;
    
    for (i = 0; i < numContas; i++){
        if (contas[i].saldo < valorRequisitado) {
            printf("Saldo insuficiente na conta %s. Saldo disponível: %.2lf\n", contas[i].tipo, contas[i].saldo);
            saldoSuficiente = 0;
        }
    }

    if (saldoSuficiente) {
        printf("Saldo suficiente em todas as contas. Transaçao aprovada.\n");
        // Aqui você pode adicionar lógica para liberar o dinheiro da transação.
    } else {
        printf("Transacao nao aprovada devido a saldo insuficiente em uma ou mais contas.\n");
    }
}

int main() {
    // Exemplo de contas bancárias
    ContaBancaria contas[] = {
        {"Corrente", 1500.0},
        {"Salário", 2000.0},
        {"Poupança", 3000.0},
        {"Investimento", 5000.0}
    };

    int numContas = sizeof(contas) / sizeof(contas[0]);

    double valorRequisitado = 4000.0; // Valor do saque

    verificarSaldo(contas, numContas, valorRequisitado);
    
    return 0;
    
}
