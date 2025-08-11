#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <list>

#include "OrcamentoMateriaPrima.h"

class Fornecedor {
    public:
        Fornecedor(const string &nome, string &cnpj);
        string getNome() const;
        void setCNPJ(string &cnpj);
        string getCNPJ() const;
        void addMateriaPrima(const string &materia_prima);
        void removeMateriaPrima(const string &materia_prima);
        list<string> getMateriasPrimas() const;
        OrcamentoMateriaPrima* gerarOrcamento(const string &materia_prima, const float &qtd, const string &unidade_medida);
        void printDados() const;
    private:
        string nome_;
        string cnpj_;
        list<string> materias_primas_;
};

#endif // FORNECEDOR_H
