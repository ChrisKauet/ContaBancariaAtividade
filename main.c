#include "CONTABANCARIA.h"
#include <stdio.h>

int main() {
    ContaBancaria conta1, conta2;

    printf("--- Teste 1: Criacao de conta com saldo VALIDO ---\n");
    if (conta_criar(&conta1, 192, 500.00)) {
        printf("Conta conta1 criada com sucesso!\n");
        conta_imprimir(&conta1);
    } else {
        printf("Falha ao criar a conta conta1.\n");
    }

    printf("\n--- Teste 2: Tentativa de criar conta com saldo INVALIDO (negativo) ---\n");
    if (conta_criar(&conta2, 168, -100.00)) {
        printf("Conta conta2 criada com sucesso!\n");
        conta_imprimir(&conta2);
    } else {
        printf("Falha ao criar a conta c2, como esperado. Saldo inicial negativo nao permitido.\n");
    }

    printf("\n--- Teste 3: Tentativa de depositar valor INVALIDO (negativo) ---\n");
    printf("Saldo de conta1 ANTES do deposito: %.2f\n", conta1.saldo);
    conta_depositar(&conta1, -50.00);
    printf("Saldo de conta1 DEPOIS do deposito: %.2f. O valor nao mudou, como esperado.\n", conta1.saldo);
    conta_imprimir(&conta1);

    printf("\n--- Teste 4: Tentativa de sacar valor MAIOR que o saldo ---\n");
    printf("Saldo de conta1 ANTES do saque: %.2f\n", conta1.saldo);
    if (conta_sacar(&conta1, 1000.00)) {
        printf("Saque realizado com sucesso.\n");
    } else {
        printf("Falha ao sacar: Saldo insuficiente, como esperado.\n");
    }
    printf("Saldo de conta1 DEPOIS do saque: %.2f. O valor nao mudou, como esperado.\n", conta1.saldo);
    conta_imprimir(&conta1);

    return 0;
}
