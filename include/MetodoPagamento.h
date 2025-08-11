#ifndef METODOPAGAMENTO_H
#define METODOPAGAMENTO_H
#define _BOLETO 1
#define _CARTAOCREDITO 2
#include <random>
#include "Data.h"
using namespace std;
class MetodoPagamento{
public:
    MetodoPagamento(float valor_total, unsigned int tipo);
    float getValorTotal();
    unsigned int getTipo();
    bool validaPagamento();
    virtual float getValorParcela(){return 0;}
    virtual int getQtdParcelas(){return 0;}
    virtual string getCodigoBarras(){
        return "";
    }
    virtual Data getVencimento(){ return Data(0, 0, 0); }
protected:
float valor_total_; 
private:
    unsigned int tipo_;   
};
#endif // METODOPAGAMENTO_H