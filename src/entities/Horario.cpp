#include "Horario.h"
#include <string>
#include <cmath>
#include <iostream>
#include "Sessao.h"
#include "Logs.h"

using namespace std;

Horario::Horario()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_Horario"))
  {
    hora_ = 0;
    minuto_ = 0;
    segundo_ = 0;
    string info_antes = "Hora: Vazio; Minuto: Vazio; Segundo: Vazio;";
    string info_depois = "Hora: 0; Minuto: 0; Segundo: 0";
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "Construtor";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Horario::Horario(float horas)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_Horario"))
  {
    float partedecimal_1, partedecimal_2;
    hora_ = floor(horas);
    partedecimal_1 = horas - hora_;
    minuto_ = floor(((partedecimal_1) * (60)));
    partedecimal_2 = (((partedecimal_1) * (60)) - minuto_);
    segundo_ = floor(((partedecimal_2) * (60)));

    string info_antes = "Hora: Vazio; Minuto: Vazio; Segundo: Vazio;";
    string info_depois = "Hora: " + to_string(hora_) + "; Minuto: " + to_string(minuto_) + "; Segundo: " + to_string(segundo_);
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "Construtor";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Horario::Horario(int hora, int minuto, int segundo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_Horario"))
  {
    hora_ = hora;
    minuto_ = minuto;
    segundo_ = segundo;
    string info_antes = "Hora: Vazio; Minuto: Vazio; Segundo: Vazio;";
    string info_depois = "Hora: " + to_string(hora_) + "; Minuto: " + to_string(minuto_) + "; Segundo: " + to_string(segundo_);
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "Construtor";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

int Horario::getHora()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_getHora"))
  {
    string info_acessada = "hora";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return hora_;
  }
  else
  {
    string func_negada = "getHora";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

int Horario::getMinuto()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_getMinuto"))
  {
    string info_acessada = "minuto";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return minuto_;
  }
  else
  {
    string func_negada = "getMinuto";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

int Horario::getSegundo()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_getSegundo"))
  {
    string info_acessada = "segundo";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return segundo_;
  }
  else
  {
    string func_negada = "getSegundo";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Horario Horario::operator+(Horario horario)
{
  float aux1;
  aux1 = ((this->paraHoras()) + horario.paraHoras());
  Horario soma(aux1);
  return soma;
}

Horario Horario::operator-(Horario horario)
{
  float aux1;
  if ((this->paraHoras()) < (horario.paraHoras()))
  {
    char message[100] = "Horario invalido";
    throw HoraInvalida(message);
  }
  aux1 = ((this->paraHoras()) - (horario.paraHoras()));
  Horario sub(aux1);
  return sub;
}

float Horario::paraHoras()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_getSegundo"))
  {

    float aux_min, aux_seg, horas;
    aux_min = (float(minuto_) / (60));
    aux_seg = (float(segundo_) / (3600));
    // horas = floorf((aux_min + aux_seg + (hora_)) * 100) / 100;
    horas = (aux_min + aux_seg + (hora_));
    // log
    string info_antes = "Hora: " + to_string(hora_) + "; Minuto: " + to_string(minuto_) + "; Segundo: " + to_string(segundo_);
    string info_depois = "Horas: " + to_string(horas);
    LogEscrita *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    return horas;
  }
  else
  {
    string func_negada = "paraHoras";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Horario::printHorario()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  string entidade = "Horario";
  Data data = data.dateNow();
  if (loggedUser->ehPermitido("Horario_printHorarios"))
  {
    string info_acessada = "Horario";
    LogLeitura *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    cout << hora_ << ":" << minuto_ << ":" << segundo_ << endl;
  }
  else
  {
    string func_negada = "printHorarios";
    LogAcessoNegado *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}
