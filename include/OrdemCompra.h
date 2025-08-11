#ifndef ORDEM_COMPRA_H
#define ORDEM_COMPRA_H

#include <vector>

#include "OrcamentoMateriaPrima.h"

class OrdemCompra {
    public:
        OrdemCompra(const Data &data_ordem, const unsigned &codigo, const float &qtd_comprada, const string &unidade_medida);
        Data getDataOrdem() const;
        float getQtdComprada() const;
        unsigned getCodigo() const;
        void addOrcamento(OrcamentoMateriaPrima* orcamento);
        void setOrcamentoEscolhido();
        void printDados() const;
        ~OrdemCompra();
    private:
        Data data_ordem_;
        unsigned codigo_;
        float qtd_comprada_;
        string unidade_medida_;
        vector<OrcamentoMateriaPrima*> orcamentos_retornados_;
        OrcamentoMateriaPrima* orcamento_escolhido_;
};

#endif // ORDEM_COMPRA_H
