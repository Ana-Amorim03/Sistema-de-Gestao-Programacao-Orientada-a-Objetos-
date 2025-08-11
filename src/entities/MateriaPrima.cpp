#include "MateriaPrima.h"
#include "Sessao.h"
#include "Utility.h"

#include <iostream>

MateriaPrima::MateriaPrima(const string &nome, const unsigned &codigo, const float &estoque_min, const string &unidade_medida) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_MateriaPrima"))
    {
        nome_ = nome;
        codigo_ = codigo;
        qtd_atual_ = 0;
        estoque_min_ = estoque_min;
        unidade_medida_ = unidade_medida;
        logs->addLog(new LogEscrita("", "materia prima " + nome + " construida", data, loggedUser->getLogin(), entidade));
    }
    else
    {
        logs->addLog(new LogAcessoNegado("MateriaPrima", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::setNome(const string &nome) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_setNome")) {
        logs->addLog(new LogEscrita("nome_: " + nome_, "nome_: " + nome, data, loggedUser->getLogin(), entidade));
        nome_ = nome;
    } else {
        logs->addLog(new LogAcessoNegado("setNome", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

string MateriaPrima::getNome() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getNome")) {
        logs->addLog(new LogLeitura("getNome", data, loggedUser->getLogin(), entidade));
        return nome_;
    } else {
        logs->addLog(new LogAcessoNegado("getNome", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::setCodigo(const unsigned &codigo) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_setCodigo")) {
        logs->addLog(new LogEscrita("codigo_: " + to_string(codigo_), "codigo_: " + to_string(codigo), data, loggedUser->getLogin(), entidade));
        codigo_ = codigo;
    } else {
        logs->addLog(new LogAcessoNegado("setNome", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

unsigned MateriaPrima::getCodigo() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getCodigo")) {
        logs->addLog(new LogLeitura("getCodigo", data, loggedUser->getLogin(), entidade));
        return codigo_;
    } else {
        logs->addLog(new LogAcessoNegado("getCodigo", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

float MateriaPrima::getQtdAtual() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getQtdAtual")) {
        logs->addLog(new LogLeitura("getQtdAtual", data, loggedUser->getLogin(), entidade));
        return qtd_atual_;
    } else {
        logs->addLog(new LogAcessoNegado("getQtdAtual", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::addQtdAtual(const float &qtd) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_addQtdAtual")) {
        logs->addLog(new LogEscrita("qtd_atual_: " + to_string(qtd_atual_), "qtd_atual_: " + to_string(qtd_atual_ + qtd), data, loggedUser->getLogin(), entidade));
        qtd_atual_ += qtd;
    } else {
        logs->addLog(new LogAcessoNegado("addQtdAtual", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::subQtdAtual(const float &qtd) {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_subQtdAtual")) {
        
        if ((qtd_atual_ - qtd) < 0) {
            throw ExecaoMateriaPrimaInsuficiente((char*)"Quantidade de materia prima insuficiente");
        }

        logs->addLog(new LogEscrita("qtd_atual_: " + to_string(qtd_atual_), "qtd_atual_: " + to_string(qtd_atual_ - qtd), data, loggedUser->getLogin(), entidade));

        qtd_atual_ -= qtd;

        if (abaixoEstoqueMin()) {
            addOrdemCompra(new OrdemCompra(Data::dateNow(), Utility::geraCodigo(), estoque_min_ - qtd_atual_, unidade_medida_));
        }
    } else {
        logs->addLog(new LogAcessoNegado("subQtdAtual", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }    
}

void MateriaPrima::setEstoqueMin(const float &estoque_min) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_setEstoqueMin")) {
        logs->addLog(new LogEscrita("estoque_min_: " + to_string(estoque_min_), "estoque_min_: " + to_string(estoque_min), data, loggedUser->getLogin(), entidade));
        estoque_min_ = estoque_min;
    } else {
        logs->addLog(new LogAcessoNegado("setEstoqueMin", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

float MateriaPrima::getEstoqueMin() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getEstoqueMin")) {
        logs->addLog(new LogLeitura("getEstoqueMin", data, loggedUser->getLogin(), entidade));
        return estoque_min_;
    } else {
        logs->addLog(new LogAcessoNegado("getEstoqueMin", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::setUnidadeMedida(const string &unidade_medida) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_setUnidadeMedida")) {
        logs->addLog(new LogEscrita("unidade_medida_: " + unidade_medida_, "unidade_medida_: " + unidade_medida, data, loggedUser->getLogin(), entidade));
        unidade_medida_ = unidade_medida;
    } else {
        logs->addLog(new LogAcessoNegado("setUnidadeMedida", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

string MateriaPrima::getUnidadeMedida() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getUnidadeMedida")) {
        logs->addLog(new LogLeitura("getUnidadeMedida", data, loggedUser->getLogin(), entidade));
        return unidade_medida_;
    } else {
        logs->addLog(new LogAcessoNegado("getUnidadeMedida", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

bool MateriaPrima::abaixoEstoqueMin() const { // Metodo Privado
    if (qtd_atual_ < estoque_min_) {
        return true;
    }
    return false;
}

void MateriaPrima::addOrdemCompra(OrdemCompra* ordem_compra) {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_addOrdemCompra")) {

        for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++) {
            ordem_compra->addOrcamento((*it)->gerarOrcamento(nome_, ordem_compra->getQtdComprada(), unidade_medida_));
        }
        ordem_compra->setOrcamentoEscolhido();
        
        ordens_compra_[ordem_compra->getDataOrdem()] = ordem_compra;
        addQtdAtual(ordem_compra->getQtdComprada());

        logs->addLog(new LogEscrita("", "ordem de compra adicionada para " + nome_, data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("addOrdemCompra", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

map<Data, OrdemCompra*> MateriaPrima::getOrdensCompra() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getOrdensCompra")) {
        logs->addLog(new LogLeitura("getOrdensCompra", data, loggedUser->getLogin(), entidade));
        return ordens_compra_;
    } else {
        logs->addLog(new LogAcessoNegado("getOrdensCompra", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::printOrdensCompra() const {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_printOrdensCompra")) {

        for (auto it = ordens_compra_.begin(); it != ordens_compra_.end(); it++) {
            cout << endl;
            it->second->printDados();
            cout << endl;
        }

        logs->addLog(new LogLeitura("printOrdensCompra", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("printOrdensCompra", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

OrdemCompra* MateriaPrima::getOrdemCompra(const Data &data_ordem) const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getOrdemCompra")) {
        logs->addLog(new LogLeitura("getOrdemCompra", data, loggedUser->getLogin(), entidade));
        return ordens_compra_.find(data_ordem)->second;
    } else {
        logs->addLog(new LogAcessoNegado("getOrdemCompra", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::addFornecedor(Fornecedor* fornecedor) {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_addFornecedor")) {

        fornecedor->addMateriaPrima(nome_);
        fornecedores_.push_back(fornecedor);

        logs->addLog(new LogEscrita("", "fornecedor adicionado para " + nome_, data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("addFornecedor", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

list<Fornecedor*> MateriaPrima::getFornecedores() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_getFornecedores")) {
        logs->addLog(new LogLeitura("getFornecedores", data, loggedUser->getLogin(), entidade));
        return fornecedores_;
    } else {
        logs->addLog(new LogAcessoNegado("getFornecedores", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::printFornecedores() const {

    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_printFornecedores")) {

        for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++) {
            cout << endl;
            (*it)->printDados();
            cout << endl;
        }

        logs->addLog(new LogLeitura("printFornecedores", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("printFornecedores", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::removeFornecedor(const string &nome) {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_removeFornecedor")) {

        for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++) {
            if ((*it)->getNome() == nome) {
                (*it)->removeMateriaPrima(nome_);
                fornecedores_.remove(*it);
            }
        }

        logs->addLog(new LogEscrita("", "fornecedor removido para " + nome_, data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("removeFornecedor", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void MateriaPrima::printDados() const {
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "MateriaPrima";
    Data data = data.dateNow();

    if (loggedUser->ehPermitido("MateriaPrima_printDados")) {

        cout << "Nome: " << nome_ << endl;
        cout << "Codigo: " << codigo_ << endl;
        cout << "Quantidade Atual: " << qtd_atual_ << " " << unidade_medida_ << endl;
        cout << "Estoque Minimo: " << estoque_min_ << " " << unidade_medida_ << endl;

        logs->addLog(new LogLeitura("printDados", data, loggedUser->getLogin(), entidade));
    } else {
        logs->addLog(new LogAcessoNegado("printDados", data, loggedUser->getLogin(), entidade));
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

MateriaPrima::~MateriaPrima() {
    for (auto it = ordens_compra_.begin(); it != ordens_compra_.end(); it++) {
        delete it->second;
    }
}
