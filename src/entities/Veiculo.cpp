#include "Veiculo.h"
#include "Horario.h"
#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include "LogAcessoNegado.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "Sessao.h"
#include "Logs.h"
#include <iomanip>

Veiculo::Veiculo(string placa, int capacidade, JornadaTrabalho *turno, Endereco *local_saida)
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_Veiculo"))
  {
    placa_ = placa;
    capacidade_ = capacidade;
    turno_ = turno;
    local_saida_ = local_saida;
    string info_antes = "Placa: Vazio; Capacidade: Vazio; Turno: Vazio; Local_Saida: Vazio;";
    string info_depois = "Placa: " + placa + "; Capacidade: " + to_string(capacidade) +
                         "; Turno: " + turno->getTurno() + "; Local_Saida: " + local_saida->getCEP();
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

string Veiculo::getPlaca()
{
  return placa_;
}

int Veiculo::getCapacidade()
{
  return capacidade_;
}

void Veiculo::addPassageiro(Funcionario *funcionario)
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_addPassageiro"))
  {
    string info_antes = "";
    int pos = 1;
    for (auto it = rota_.begin(); it != rota_.end(); it++)
    {
      info_antes += "Passageiro " + to_string(pos) + ":" + (*it)->getNome() + "; ";
      pos++;
    }
    rota_.push_back(funcionario);
    this->setHorariosEmbarque();
    funcionario->setJornada(turno_);
    string info_depois = "";
    pos = 1;
    for (auto it = rota_.begin(); it != rota_.end(); it++)
    {
      info_depois += "Passageiro " + to_string(pos) + ":" + (*it)->getNome() + "; ";
      pos++;
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addPassageiro";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

list<Funcionario *> Veiculo::getRota()
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_getRota"))
  {
    string info_acessada = "rota";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return rota_;
  }
  else
  {
    string func_negada = "getRota";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Veiculo::removePassageiro(Funcionario *funcionario)
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_removePassageiro"))
  {
    string info_antes = "";
    int pos = 1;
    for (auto it = rota_.begin(); it != rota_.end(); it++)
    {
      info_antes += "Passageiro " + to_string(pos) + ":" + (*it)->getNome() + "; ";
      pos++;
    }
    rota_.remove(funcionario);
    this->setHorariosEmbarque();
    string info_depois = "";
    pos = 1;
    for (auto it = rota_.begin(); it != rota_.end(); it++)
    {
      info_depois += "Passageiro " + to_string(pos) + ":" + (*it)->getNome() + "; ";
      pos++;
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "removePassageiro";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Veiculo::printRota()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_printRota"))
    {
      string info_acessada = "Rota";
      LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
      logs->addLog(logleitura);

      cout << endl;
      cout << "Imprimindo rota do veiculo" << endl;
      int pos = 1;
      for (auto it = rota_.begin(); it != rota_.end(); it++)
      {
        cout << "\t" << pos << ": " << (*it)->getNome() << "-> " << (*it)->getEndereco()->getLatLong().first << "," << (*it)->getEndereco()->getLatLong().second << endl;
        pos++;
      }
      cout << endl;
      cout << "\tDistancia total percorrida: " << fixed << setprecision(3) << distancia_total_ << "Km" << endl;
      cout << "\tHorario de saida do veiculo: " << horario_saida_.getHora() << ":" << horario_saida_.getMinuto() << ":" << horario_saida_.getSegundo() <<endl;
      cout << "\tTempo total de percurso (horas):(minutos) " << tempo_percurso_.getHora() << ":" << tempo_percurso_.getMinuto() << endl;
    }
   else
  {
    string func_negada = "printRota";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Veiculo::printHorarioEmbarque()
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_printHorarioEmbarque"))
  {
    string info_acessada = "HorariosEmbarque";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    int pos = 1;
    cout << endl;
    cout << "Imprimindo HORARIOS DE EMBARQUE: " << endl;
    for (auto it = rota_.begin(); it != rota_.end(); it++)
    {
      cout << "\t" << pos << ": " << (*it)->getNome() << "-> ";
      (*it)->getEmbarque().printHorario();
      pos++;
    }
    cout << endl;
    
  }
  else
  {
    string func_negada = "printHorarioEmbarque";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Veiculo::setTurnoVeiculo(JornadaTrabalho *turno)
{
  turno_ = turno;
}

void Veiculo::setLocalSaida(Endereco *local_saida)
{
  local_saida_ = local_saida;
}

JornadaTrabalho *Veiculo::getTurnoVeiculo()
{
  return turno_;
}

Endereco *Veiculo::getLocalSaida()
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_getLocalSaida"))
  {
    string info_acessada = "local_saida";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return local_saida_;
  }
  else
  {
    string func_negada = "getLocalSaida";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

float Veiculo::getDistanciaTotal()
{
  return distancia_total_;
}
Horario Veiculo::getTempoPercurso()
{
  return tempo_percurso_;
}

Horario Veiculo::getHorarioSaida()
{
  return horario_saida_;
}

void Veiculo::printDados()
{
  cout << "Informaçao sobre o veiculo: " << endl;
  cout << "Placa: " << this->getPlaca() << endl;
  cout << "Capacidade: " << this->getCapacidade() << endl;
  cout << "Turno de trabalho: " << this->getTurnoVeiculo()->getTurno() << endl;
  cout << "Local(rua) saida: " << this->getLocalSaida()->getRua() << endl;
  cout << "Horario saida (horas):(minutos) " << horario_saida_.getHora() << ":" << horario_saida_.getMinuto() << endl;
}

float Veiculo::calculaDistancia(pair<float, float> a, pair<float, float> b)
{
Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Veiculo_calculaDistancia"))
  {
    string info_acessada = "distancia";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return 110.57 * sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
  }
  else
  {
    string func_negada = "getcalculaDistancia";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Veiculo::setHorariosEmbarque()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Veiculo";
    Data data = data.dateNow();
  string info_antes;
  string info_depois;
  if (loggedUser->ehPermitido("Veiculo_setHorariosEmbarque"))
  {
    Horario dezmin = Horario(0, 10, 0);

    // 1 - horario de inicio do turno referente ao veiculo - 10 min
    Horario aux = this->turno_->getInicio() - dezmin;

    // 2 - calcular a distancia do ponto de saida(inicio) ate o funcionario(fim)
    pair<float, float> aux_coord = local_saida_->getLatLong();

    auto it = rota_.end();
    it--;
    float distance = 0;
    float tempo_gasto = 0;
    distancia_total_ = 0;

    // caso tenha apenas um passageiro
    if (it == rota_.begin())
    {
      // antes
      int pos = 1;
      info_antes = "Passageiro " + to_string(pos) + ":" + to_string((*it)->getEmbarque().paraHoras()) + "; ";
      
      pair<float, float> coordfunc = (*it)->getEndereco()->getLatLong();
      distance = this->calculaDistancia(aux_coord, coordfunc);

      // 3 - calcular o tempo gasto ao percorrer a distancia
      tempo_gasto = (distance) / 18;
      Horario horario(tempo_gasto);

      // 4 - subtrair tempo gasto do horario de chegada
      (*it)->setEmbarque(aux - horario);
      horario_saida_ = (*it)->getEmbarque() - horario;
      distancia_total_ = (2 * distance); // ida e volta
      tempo_percurso_ = aux - horario_saida_;
    }

    else
    {
      // antes
      info_antes = "";
      int pos = 1;
      for (auto it = rota_.begin(); it != rota_.end(); it++)
      {
        info_antes += "Passageiro " + to_string(pos) + ":" + to_string((*it)->getEmbarque().paraHoras()) + "; ";
        pos++;
      }
      for (; it != rota_.begin(); it--)
      {
        pair<float, float> coordfunc = (*it)->getEndereco()->getLatLong();
        distance = this->calculaDistancia(aux_coord, coordfunc);

        tempo_gasto = distance / 18;
        Horario horario(tempo_gasto);

        (*it)->setEmbarque(aux - horario);
        aux = aux - horario;
        aux_coord = coordfunc;
        distancia_total_ += distance;
      }

      // 5 - distância entre o primeiro e segundo funcionario da rota
      distance = this->calculaDistancia((*it)->getEndereco()->getLatLong(), aux_coord);
      tempo_gasto = distance / 18;

      // 6 - setando embarque do primeiro funcionario da rota
      Horario horario1(tempo_gasto);
      (*it)->setEmbarque(aux - horario1);

      // 7 - distância entre a empresa e o primeiro funcionario
      distance += this->calculaDistancia((*it)->getEndereco()->getLatLong(), local_saida_->getLatLong());
      tempo_gasto = distance / 18;
      distancia_total_ += distance;

      Horario horario(tempo_gasto);
      it++;
      horario_saida_ = (*it)->getEmbarque() - horario;
      aux = this->turno_->getInicio() - dezmin;
      tempo_percurso_ = aux - horario_saida_;
    }
    // depois
    info_depois = "";
    int pos = 1;
    for (auto it = rota_.begin(); it != rota_.end(); it++)
    {
      info_depois += "Passageiro " + to_string(pos) + ":" + to_string((*it)->getEmbarque().paraHoras()) + "; ";
      pos++;
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "setHorariosEmbarque";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Veiculo::~Veiculo(){
  delete turno_;
  delete local_saida_;
}