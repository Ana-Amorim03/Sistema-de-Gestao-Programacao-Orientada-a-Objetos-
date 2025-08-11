#include "Data.h"
#include "Orcamento.h"
#include <string>
#include "MetodoPagamento.h"
#include "Venda.h"

#ifndef PEDIDO_COMPRA
#define PEDIDO_COMPRA

using namespace std;

class VendaCancelada : public ExecaoCustomizada {
public:
  VendaCancelada(char *e) : ExecaoCustomizada(e) {}
};
class PedidoCompra{
    unsigned int codigo_;
    Data data_pedido_;
    Orcamento* orcamento_;
    string cliente_;
    MetodoPagamento* pagamento_;
    Data data_pagamento_ = Data();
    Venda* venda_;
    bool status_;
public:
    PedidoCompra(unsigned int codigo, Data data_pedido, Orcamento* orcamento, string cliente, MetodoPagamento* pagamento);
    unsigned int getCodigo();
    Data getDataPedido();
    Orcamento* getOrcamento();
    string getCliente();
    Data getDataPagamento();
    void gerarVenda();
    void printDados();
    Venda* getVenda();
};

#endif //PEDIDO_COMPRA