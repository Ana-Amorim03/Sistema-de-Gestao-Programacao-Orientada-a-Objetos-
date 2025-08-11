#ifndef ORCAMENTO_MATERIA_PRIMA_H
#define ORCAMENTO_MATERIA_PRIMA_H

#include <string>
using namespace std;

#include "Data.h"

class OrcamentoMateriaPrima {
    public:
        OrcamentoMateriaPrima(const Data &data_orcamento, const unsigned &codigo, 
        const string &fornecedor, const float &qtd, const float &preco, const string &unidade_medida);
        Data getDataOrcamento() const;
        unsigned getCodigo() const;
        string getFornecedor();
        float getQtd() const;
        float getPreco() const;
        void printDados() const;
    private:
        Data data_orcamento_;
        unsigned codigo_;
        string fornecedor_;
        float qtd_;
        float preco_;
        string unidade_medida_;
};

#endif // ORCAMENTO_MATERIA_PRIMA_H
