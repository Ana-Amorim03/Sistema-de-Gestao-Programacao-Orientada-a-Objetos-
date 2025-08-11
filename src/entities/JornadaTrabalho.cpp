#include "JornadaTrabalho.h"
#include <string>
#include <iostream>
#include "LogAcessoNegado.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "Sessao.h"
#include "Logs.h"



using namespace std;

JornadaTrabalho::JornadaTrabalho(string turno, Horario inicio, Horario fim)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "JornadaTrabalho";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("JornadaTrabalho_JornadaTrabalho"))
  {
    turno_ = turno;
    inicio_ = inicio;
    fim_ = fim;
    string info_antes = "Turno: Vazio; Turno: Vazio; Segundo: Vazio;";
    string info_depois = "Turno: " + turno + "; Inicio: " + to_string(inicio.getHora()) + ":" + to_string(inicio.getMinuto()) + ":" + to_string(inicio.getSegundo());
    +"; Fim: " + to_string(fim.getHora()) + ":" + to_string(fim.getMinuto()) + ":" + to_string(fim.getSegundo());
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

string JornadaTrabalho::getTurno()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "JornadaTrabalho";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("JornadaTrabalho_getTurno"))
  {
    string info_acessada = "turno";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return turno_;
  }
  else
  {
    string func_negada = "getTurno";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void JornadaTrabalho::setInicio(Horario inicio)
{
  inicio_ = inicio;
}

Horario JornadaTrabalho::getInicio()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "JornadaTrabalho";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("JornadaTrabalho_getInicio"))
  {
    string info_acessada = "inicio";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return inicio_;
  }
  else
  {
    string func_negada = "getInicio";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void JornadaTrabalho::setFim(Horario fim) { fim_ = fim; }

Horario JornadaTrabalho::getFim()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "JornadaTrabalho";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("JornadaTrabalho_getFim"))
  {
    string info_acessada = "fim";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return fim_;
  }
  else
  {
    string func_negada = "getFim";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Horario JornadaTrabalho::cargaHoraria()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "JornadaTrabalho";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("JornadaTrabalho_cargaHoraria"))
  {
    string info_acessada = "carga_horaria";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return (fim_ - inicio_);
  }
  else
  {
    string func_negada = "cargaHoraria";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void JornadaTrabalho::printJornada()
{
  cout << "\tTurno: " << turno_ << endl;
  cout << "\tHora de Inicio: ";
  inicio_.printHorario();
  cout << "\tHora do Final: ";
  fim_.printHorario();
}
