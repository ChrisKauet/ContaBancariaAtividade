#include "CONTABANCARIA.h"
#include <stdio.h>

int conta_criar(ContaBancaria* pconta, int numero, double saldo_inicial) {
    if (pconta == NULL) {
        return 0;
    }


    if (saldo_inicial < 0) {
        return 0;
    }

    pconta->numero = numero;
    pconta->saldo = saldo_inicial;

    return 1;
}

void conta_depositar(ContaBancaria* pconta, double valor) {

    if (pconta != NULL && valor > 0) {
        pconta->saldo += valor;
    }
}

int conta_sacar(ContaBancaria* pconta, double valor) {

    if (pconta != NULL && valor > 0 && pconta->saldo >= valor) {
        pconta->saldo -= valor;
        return 1;
    }
    return 0;
}

void conta_imprimir(const ContaBancaria* pconta) {
    if (pconta != NULL) {
        printf("------------------------\n");
        printf("Conta Numero: %d\n", pconta->numero);
        printf("Saldo:        R$ %.2f\n", pconta->saldo);
        printf("------------------------\n");
    }
}
