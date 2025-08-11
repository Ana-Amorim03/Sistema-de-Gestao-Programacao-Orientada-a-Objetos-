#include "Fornecedor.h"
#include "Utility.h"
#include "Sessao.h"

#include <iostream>

Fornecedor::Fornecedor(const string &nome, string &cnpj) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_Fornecedor")) {
        nome_ = nome;
        if (Utility::validaCNPJ(cnpj)) {
            cnpj_ = cnpj;
        } else {
            throw CNPJinvalido((char*)"CNPJ invalido!");
        }
        logs->addLog(new LogEscrita("", "fornecedor " + nome + " cadastrado", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("Fornecedor", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

string Fornecedor::getNome() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_getNome")) {
        logs->addLog(new LogLeitura("getNome", data, loggedUser->getLogin(), entidade));
        return nome_;
    } else {
        logs->addLog(new LogAcessoNegado("getNome", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void Fornecedor::setCNPJ(string &cnpj) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_setCNPJ")) {
        string cnpj_antes = cnpj_;
        if (Utility::validaCNPJ(cnpj)) {
            cnpj_ = cnpj;
        } else {
            throw CNPJinvalido((char*)"CNPJ invalido!");
        }
        logs->addLog(new LogEscrita("cnpj_: " + cnpj_antes, "cnpj_: " + cnpj, data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("setCNPJ", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

string Fornecedor::getCNPJ() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_getCNPJ")) {
        logs->addLog(new LogLeitura("getCNPJ", data, loggedUser->getLogin(), entidade));
        return cnpj_;
    } else {
        logs->addLog(new LogAcessoNegado("getCNPJ", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void Fornecedor::addMateriaPrima(const string &materia_prima) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_addMateriaPrima")) {
        materias_primas_.push_back(materia_prima);
        logs->addLog(new LogEscrita("", "materia prima " + materia_prima + " adicionada para " + nome_, data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("addMateriaPrima", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void Fornecedor::removeMateriaPrima(const string &materia_prima) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_removeMateriaPrima")) {
        logs->addLog(new LogEscrita("", "materia prima " + materia_prima + " removida", data, loggedUser->getLogin(), entidade));
        materias_primas_.remove(materia_prima);
    } else {
        logs->addLog(new LogAcessoNegado("removeMateriaPrima", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

list<string> Fornecedor::getMateriasPrimas() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_getMateriasPrimas")) {
        logs->addLog(new LogLeitura("getMateriasPrimas", data, loggedUser->getLogin(), entidade));
        return materias_primas_;
    } else {
        logs->addLog(new LogAcessoNegado("getMateriasPrimas", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

OrcamentoMateriaPrima* Fornecedor::gerarOrcamento(const string &materia_prima, const float &qtd, const string &unidade_medida) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_gerarOrcamento")) {
        OrcamentoMateriaPrima *orcamento = new OrcamentoMateriaPrima(Data::dateNow(), Utility::geraCodigo(), nome_, qtd, Utility::randomPrice(100, 200), unidade_medida);
        logs->addLog(new LogEscrita("", "orcamento gerado para " + materia_prima, data, loggedUser->getLogin(), entidade));
        return orcamento;
    } else {
        logs->addLog(new LogAcessoNegado("gerarOrcamento", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void Fornecedor::printDados() const {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Fornecedor";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("Fornecedor_printDados")) {

        cout << "\tNome: " << nome_ << endl;
        cout << "\tCNPJ: " << cnpj_ << endl;
        cout << "\tMaterias Primas: " << endl;

        cout << "\t\t";
        for (auto it = materias_primas_.begin(); it != materias_primas_.end(); it++) {
            cout << (*it)  << "; ";;
        }
        cout << endl;

        logs->addLog(new LogLeitura("printDados", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("printDados", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}
