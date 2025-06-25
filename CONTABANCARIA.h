#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

struct contabancaria_st {
    int numero;
    double saldo;
};

typedef struct contabancaria_s ContaBancaria;

void conta_criar(ContaBancaria* pconta, int numero, double saldo);
void conta_depositar(ContaBancaria* pconta, double valor);
int  conta_sacar(ContaBancaria* pconta, double valor);
void conta_imprimir(const ContaBancaria* pconta);

#endif// COINTABANCARIA
