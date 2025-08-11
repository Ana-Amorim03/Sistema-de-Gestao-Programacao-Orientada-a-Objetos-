#include "OrdemCompra.h"
#include "Sessao.h"

#include <iostream>
#include <iomanip>

OrdemCompra::OrdemCompra(const Data &data_ordem, const unsigned &codigo, const float &qtd_comprada, const string &unidade_medida) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_OrdemCompra")) {
        data_ordem_ = data_ordem;
        codigo_ = codigo;
        qtd_comprada_ = qtd_comprada;
        orcamento_escolhido_ = nullptr;
        unidade_medida_ = unidade_medida;
        logs->addLog(new LogEscrita("", "ordem compra construida", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("OrdemCompra", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

Data OrdemCompra::getDataOrdem() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_getDataOrdem")) {
        logs->addLog(new LogLeitura("getDataOrdem", data, loggedUser->getLogin(), entidade));
        return data_ordem_;
    } else {
        logs->addLog(new LogAcessoNegado("getDataOrdem", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

float OrdemCompra::getQtdComprada() const {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_getQtdComprada")) {
        logs->addLog(new LogLeitura("getQtdComprada", data, loggedUser->getLogin(), entidade));
        return qtd_comprada_;
    } else {
        logs->addLog(new LogAcessoNegado("getQtdComprada", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

unsigned OrdemCompra::getCodigo() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_getCodigo")) {
        logs->addLog(new LogLeitura("getCodigo", data, loggedUser->getLogin(), entidade));
        return qtd_comprada_;
    } else {
        logs->addLog(new LogAcessoNegado("getCodigo", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void OrdemCompra::addOrcamento(OrcamentoMateriaPrima* orcamento) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_addOrcamento")) {
        orcamentos_retornados_.push_back(orcamento);
        logs->addLog(new LogEscrita("", "orcamento adicionado", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("addOrcamento", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void OrdemCompra::setOrcamentoEscolhido() {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_setOrcamentoEscolhido")) {
        orcamento_escolhido_ = orcamentos_retornados_[0];
        for (unsigned it = 1; it < orcamentos_retornados_.size(); it++) {
            if (orcamentos_retornados_[it]->getPreco() < orcamento_escolhido_->getPreco()) {
                orcamento_escolhido_ = orcamentos_retornados_[it];
            }
        }
        logs->addLog(new LogEscrita("", "melhor orcamento escolhido", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("setOrcamentoEscolhido", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void OrdemCompra::printDados() const {

    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "OrdemCompra";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("OrdemCompra_printDados")) {

        cout << "Data Ordem: ";
        data_ordem_.printData();
        cout << "Codigo: " << codigo_ << endl;
        cout << "Quantidade Comprada: " << qtd_comprada_ << " " << unidade_medida_ << endl;
        cout << "Orcamento Escolhido: " << endl;
        orcamento_escolhido_->printDados();

        logs->addLog(new LogLeitura("printDados", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("printDados", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

OrdemCompra::~OrdemCompra() {
    for (unsigned it = 0; it < orcamentos_retornados_.size(); it++) {
        delete orcamentos_retornados_[it];
    }
}
