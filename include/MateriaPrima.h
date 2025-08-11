#ifndef MATERIA_PRIMA_H
#define MATERIA_PRIMA_H

#include <map>
#include <string>

#include "OrdemCompra.h"
#include "Fornecedor.h"

class ExecaoMateriaPrimaInsuficiente : public ExecaoCustomizada {
    public:
        ExecaoMateriaPrimaInsuficiente(char *e) : ExecaoCustomizada(e) {}
};

class MateriaPrima {
    public:
        MateriaPrima(const string &nome, const unsigned &codigo, const float &estoque_min, const string &unidade_medida);
        void setNome(const string &nome);
        string getNome() const;
        void setCodigo(const unsigned &codigo);
        unsigned getCodigo() const;
        float getQtdAtual() const;
        void addQtdAtual(const float &qtd);
        void subQtdAtual(const float &qtd);
        void setEstoqueMin(const float &estoque_min);
        float getEstoqueMin() const;
        void setUnidadeMedida(const string &unidade_medida);
        string getUnidadeMedida() const;
        void addOrdemCompra(OrdemCompra* ordem_compra);
        map<Data, OrdemCompra*> getOrdensCompra() const;
        void printOrdensCompra() const;
        OrdemCompra* getOrdemCompra(const Data &data_ordem) const;
        void addFornecedor(Fornecedor* fornecedor);
        list<Fornecedor*> getFornecedores() const;
        void printFornecedores() const;
        void removeFornecedor(const string &nome);
        void printDados() const;
        ~MateriaPrima();
    private:
        bool abaixoEstoqueMin() const;
        string nome_;
        unsigned codigo_;
        float qtd_atual_;
        float estoque_min_;
        string unidade_medida_;
        map<Data, OrdemCompra*> ordens_compra_;
        list<Fornecedor*> fornecedores_;
};

#endif // MATERIA_PRIMA_H
