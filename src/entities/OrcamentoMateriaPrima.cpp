#include "OrcamentoMateriaPrima.h"
#include "Sessao.h"

#include <iostream>
#include <iomanip>

OrcamentoMateriaPrima::OrcamentoMateriaPrima(const Data &data_orcamento, const unsigned &codigo, 
const string &fornecedor, const float &qtd, const float &preco, const string &unidade_medida) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_OrcamentoMateriaPrima")) {
        data_orcamento_ = data_orcamento;
        codigo_ = codigo;
        fornecedor_ = fornecedor;
        qtd_ = qtd;
        preco_ = preco;
        unidade_medida_ = unidade_medida;
        logs->addLog(new LogEscrita("", "orcamento construido para " + fornecedor, data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("OrcamentoMateriaPrima", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

Data OrcamentoMateriaPrima::getDataOrcamento() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_getData")) {
        logs->addLog(new LogLeitura("getData", data, loggedUser->getLogin(), entidade));
        return data_orcamento_;
    } else {
        logs->addLog(new LogAcessoNegado("getData", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

unsigned OrcamentoMateriaPrima::getCodigo() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_getCodigo")) {
        logs->addLog(new LogLeitura("getCodigo", data, loggedUser->getLogin(), entidade));
        return codigo_;
    } else {
        logs->addLog(new LogAcessoNegado("getCodigo", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

string OrcamentoMateriaPrima::getFornecedor() {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_getFornecedor")) {
        logs->addLog(new LogLeitura("getFornecedor", data, loggedUser->getLogin(), entidade));
        return fornecedor_;
    } else {
        logs->addLog(new LogAcessoNegado("getFornecedor", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

float OrcamentoMateriaPrima::getQtd() const {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_getQtd")) {
        logs->addLog(new LogLeitura("getQtd", data, loggedUser->getLogin(), entidade));
        return qtd_;
    } else {
        logs->addLog(new LogAcessoNegado("getQtd", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

float OrcamentoMateriaPrima::getPreco() const {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_getPreco")) {
        logs->addLog(new LogLeitura("getPreco", data, loggedUser->getLogin(), entidade));
        return preco_;
    } else {
        logs->addLog(new LogAcessoNegado("getPreco", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void OrcamentoMateriaPrima::printDados() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrcamentoMateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrcamentoMateriaPrima_printDados")) {

        cout << "\tData: ";
        data_orcamento_.printData();
        cout << "\tCodigo: " << codigo_ << endl;
        cout << "\tFornecedor: " << fornecedor_ << endl;
        cout << "\tQtd: " << fixed << setprecision(2) << qtd_ << " " << unidade_medida_ << endl;
        cout << "\tPreco: R$" << preco_ << endl;

        logs->addLog(new LogLeitura("printDados", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("printDados", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}
