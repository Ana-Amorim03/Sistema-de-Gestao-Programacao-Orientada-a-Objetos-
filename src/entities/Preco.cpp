#include "Preco.h"
#include <string>


Preco::Preco(Data data_alteracao, float novo_valor)
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Preco";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Preco_Preco"))
    {
        data_alteracao_ = data_alteracao;
        novo_valor_ = novo_valor;
        string info_antes = "Data_alteracao: Vazio; Novo_valor: Vazio;";
        string info_depois = "Data_alteracao: " + data_alteracao.getData() + "; Novo_valor: " + to_string(novo_valor) + ";";
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
Data Preco::getDataAlteracao()
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Preco";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Preco_getDataAlteracao"))
    {
        string info_acessada = "Data alteracao";
        LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return data_alteracao_;
    }
    else
    {
        string func_negada = "getDataAlteracao";
        LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}
float Preco::getNovoValor()
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Preco";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Preco_getNovoValor"))
    {
        string info_acessada = "Novo Valor";
        LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
        logs->addLog(logleitura);
        return novo_valor_;
    }
    else
    {
        string func_negada = "getNovoValor";
        LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
       logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
    }
}
