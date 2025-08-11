#ifndef CARTAOCREDITO_H
#define CARTAOCREDITO_H
#include "Data.h"
#include "MetodoPagamento.h"
#include <string>

class CartaoCredito : public MetodoPagamento{
    int qtd_parcelas_;
    string num_cartao_;
    int cvv_;
public:
    CartaoCredito(int qtd_parcelas, int cvv, string num_cartao, float valor_total, unsigned int tipo);
    float getValorParcela();
    int getQtdParcelas();
};
#endif// CARTAOCREDITO_H