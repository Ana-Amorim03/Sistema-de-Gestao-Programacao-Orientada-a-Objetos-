#ifndef BOLETO_H
#define BOLETO_H
#include "MetodoPagamento.h"
#include <string>
#include "Data.h"
using namespace std;

class Boleto : public MetodoPagamento{
public:
    Boleto(Data vencimento, float valor_total, unsigned int tipo, string codigo_de_barras);
    Data getVencimento();
    void setVencimento(Data vencimento);
    string getCodigoDeBarras();
    void setCodigoDeBarras(string codigo_de_barras);
private:
    Data vencimento_;
    string codigo_de_barras_;
};
#endif// BOLETO_H