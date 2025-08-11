#include "Cargo.h"

Cargo::Cargo(const string &nome){
    
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Cargo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Cargo_Cargo"))
    {
        nome_ = nome;
        string info_antes = "Nome: Vazio";
        string info_depois = "Nome: "  + nome;
        LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
        logs->addLog(logescrita);
    }
    else
    {
        string func_negada = "Construtor";
        LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
        
}

string Cargo::getNome() const { 
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Cargo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Cargo_getNome"))
    {
        string info_acessada = "Nome ";
        LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return nome_;
    }
    else
    {
        string func_negada = "getNome";
        LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}

void Cargo::setNome(const string &nome) { nome_ = nome; }

Cargo::~Cargo() {}
