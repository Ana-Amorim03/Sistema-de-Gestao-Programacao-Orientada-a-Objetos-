#include "Funcionario.h"
#include "Endereco.h"
#include "Utility.h"
#include "Horario.h"
#include <iostream>
#include <string>

using namespace std;


Funcionario::Funcionario(const string &nome, string cpf, Endereco *endereco,
                         Data &data_nasc, const string &email,
                         const string &matricula)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_Funcionario"))
  {
    nome_ = nome;
    endereco_ = endereco;
    data_nasc_ = data_nasc;
    email_ = email;
    matricula_ = matricula;
    status_ = false;
    embarque_ = Horario();
    if (Utility::validaCPF(cpf))
    {
      cpf_ = cpf;
    }
    else
    {
      char message[100] = "CPF invalido, altere o CPF!";
      throw CPFinvalido(message);
    }
    string info_antes = "Nome: Vazio; Endereco: Vazio; Data nascimento: Vazio; CPF: Vazio; Email: Vazio; Matricula: Vazio; Status: Vazio";
    string info_depois = "Nome: " + nome + "; Endereco: " + endereco->getCEP() + "; Data nascimento: " + data_nasc.getData() + "; CPF: " + cpf + "; Email: " + email + "; Matricula: " + matricula + "; Status: " + to_string(status_);
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

void Funcionario::setNome(const string &nome) { nome_ = nome; }

void Funcionario::setCPF(string cpf)
{
  if (Utility::validaCPF(cpf))
  {
    cpf_ = cpf;
  }
  else
  {
    char message[100] = "CPF invalido, altere o CPF!";
    throw CPFinvalido(message);
  }
}

void Funcionario::setEndereco(const string &rua, const int &numero,
                              const string &complemento, const string &cep,
                              const string &bairro, const string &cidade,
                              const string &uf, const string &pais)
{
  endereco_->setRua(rua);
  endereco_->setNumero(numero);
  endereco_->setComplemento(complemento);
  endereco_->setCEP(cep);
  endereco_->setBairro(bairro);
  endereco_->setCidade(cidade);
  endereco_->setUF(uf);
  endereco_->setPais(pais);
}

void Funcionario::setDataNasc(Data &data_nasc) { data_nasc_ = data_nasc; }

void Funcionario::setEmail(const string &email) { email_ = email; }

void Funcionario::setMatricula(const string &matricula)
{
  matricula_ = matricula;
}

void Funcionario::setStatus(bool status)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_setStatus"))
  {
    string info_antes = "Status: " + to_string(status_);
    string info_depois = "Status: " + to_string(status);
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    status_ = status;
  }
  else
  {
    string func_negada = "setStatus";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

string Funcionario::getNome() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getNome"))
  {
    string info_acessada = "nome";
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

string Funcionario::getCpf() const
{

  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getCpf"))
  {
    string info_acessada = "CPF";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return cpf_;
  }
  else
  {
    string func_negada = "getCPF";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Endereco *Funcionario::getEndereco() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getEndereco"))
  {
    string info_acessada = "Endereco";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return endereco_;
  }
  else
  {
    string func_negada = "getEndereco";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Data Funcionario::getDataNasc() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getDataNasc"))
  {
    string info_acessada = "data_nasc";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return data_nasc_;
  }
  else
  {
    string func_negada = "getDataNasc";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

string Funcionario::getEmail() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getEmail"))
  {
    string info_acessada = "email";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return email_;
  }
  else
  {
    string func_negada = "getEmail";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

string Funcionario::getMatricula() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getMatricula"))
  {
    string info_acessada = "matricula";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return matricula_;
  }
  else
  {
    string func_negada = "getMatricula";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<Data, Contrato *> Funcionario::getContratos() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getContratos"))
  {
    string info_acessada = "contratos";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return contratos_;
  }
  else
  {
    string func_negada = "getContratos";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Contrato *Funcionario::getContrato(Data &data_admissao) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getContrato"))
  {
    string info_acessada = "Contrato";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    auto it = contratos_.find(data_admissao);
    if (it == contratos_.end())
    {
      char message[100] = "Nenhum contrato possui essa data de admissao!";
      throw DataInvalida(message);
    }
    return it->second;
  }
  else
  {
    string func_negada = "getContrato";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

bool Funcionario::getStatus() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getStatus"))
  {
    string info_acessada = "status";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return status_;
  }
  else
  {
    string func_negada = "getStatus";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Usuario *Funcionario::getUsuario() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getUsuario"))
  {
    string info_acessada = "usuario";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return usuario_;
  }
  else
  {
    string func_negada = "getUsuario";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::setUsuario(Usuario *usuario)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_setUsuario"))
  {
    string info_antes = "Usuario: " + (usuario_ != nullptr) ? usuario_->getLogin() : "Vazio";
    string info_depois = "Usuario: " + (usuario != nullptr) ? usuario->getLogin() : "Vazio";
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    usuario_ = usuario;
  }
  else
  {
    string func_negada = "setUsuario";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::addContrato(Contrato *contrato)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_addContrato"))
  {
    string info_antes = "Data: Vazio; Cargo: Vazio; Salario: Vazio";
    status_ = true;
    if (!contratos_.empty())
    {
      auto it = contratos_.end();
      --it;
      if (it->second->getDataDesligamento() == contrato->getDataZero())
      {
        if (it->second->getDataAdmissao() > contrato->getDataAdmissao())
        {
          char message[100] = "Data de admissao anteior a data de "
                              "admissao/desligamento do ultimo contrato!";
          throw DataInvalida(message);
        }
        else
        {
          it->second->setDataDesligamento(contrato->getDataAdmissao());
        }
      }
      string info_antes = "Data: " + it->first.getData() + "Cargo: " + it->second->getCargo()->getNome() + "Salario: " + to_string(it->second->getSalarioAtual());
    }
    pair<Data, Contrato *> auxiliar = make_pair(contrato->getDataAdmissao(), contrato);
    contratos_.insert(auxiliar);

    string info_depois = "Data: " + contrato->getDataAdmissao().getData() + "Cargo: " + contrato->getCargo()->getNome() + "Salario: " + to_string(contrato->getSalarioAtual());
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addContrato";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::demiteFuncionario(Data &data_desligamento)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_demiteFuncionario"))
  {
    if (status_ == false)
    {
      char message[100] = "O funcionario jah se encontra desligado!";
      throw FuncionarioDesligado(message);
    }
    auto it = contratos_.end();
    --it;

    Data data_admissao = it->second->getDataAdmissao();

    if (data_admissao > data_desligamento)
    {
      char message[100] = "Data de desligamento anteior a data de admissao!";

      throw DataInvalida(message);
    }

    status_ = false;
    string info_antes = "Status: " + status_;
    string info_depois = "Status: " + status_;
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    it->second->setDataDesligamento(data_desligamento);
  }

  else
  {
    string func_negada = "demiteFuncionario";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::removeContrato(Data &data_admissao)
{
  map<Data, Contrato *>::iterator itr = contratos_.find(data_admissao);
  if (itr == contratos_.end())
  {
    char message[100] = "Nenhum contrato possui essa data de admissao!";
    throw DataInvalida(message);
  }
  else
  {
    status_ = false;
    contratos_.erase(itr);
  }
  /* unsigned i = 0;
  for (auto it = contratos_.begin(); it != contratos_.end(); it++, i++) {
    if (*((*it)->getDataAdmissao()) == data_admissao) {
      if (i == contratos_.size() - 1) {
        status_ = false;
      }
      delete (*it);
      contratos_.erase(it);
      return;
    }
  } */
}

void Funcionario::printContratos()
{
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
  
  if (loggedUser->ehPermitido("Funcionario_printContratos"))
  {
  cout << "Funcionario: " << nome_ << endl;
  int num = 1;
  for (auto it = contratos_.begin(); it != contratos_.end(); it++)
  {
    cout << "\tContrato " << to_string(num) << endl;
    cout << "\t\tData de admissao: ";
    it->first.printData();
    if ((*it).second->getDataDesligamento().getData() != data_zero_.getData())
    {
      cout << "\t\tData de Desligamento: " << it->second->getDataDesligamento().getData() << endl;
      cout << "\t\tStatus: Nao Valido" << endl;
    }
    else
    {
      cout << "\t\tStatus: Valido" << endl;
    }
    num++;
  }
    string info_acessada = "printContratos";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
  }
    else
  {
    string func_negada = "printContratos";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::printDados()
{
  cout<< "Imprimindo dados de funcionario" << endl;
  cout << "\tNome: " << nome_ << endl;
  cout << "\tCPF: " << cpf_ << endl;

  cout << "\tEndereco: \t";
  endereco_->printEndereco();

  cout << "\tData de Nascimento: \t";
  data_nasc_.printData();

  cout << "\tEmail: " << email_ << endl;
  cout << "\tMatricula: " << matricula_ << endl;

  cout << "\tJornada de Trabalho:" << endl;
  jornada_->printJornada();

  cout << "\tPlaca do Transporte: " << placa_transporte_ << endl;
  cout << "\tHorario de Embarque: ";
  embarque_.printHorario();

  if (status_)
  {
    cout << "\tStatus: Ativo" << endl;
  }
  else
  {
    cout << "\tStatus: Desligado" << endl;
  }
}

void Funcionario::setJornada(JornadaTrabalho *jornada)
{
  
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_setJornada"))
  {
    
    string info_antes;
    if(jornada_ == nullptr){
      info_antes = "Jornada: Vazio";
    }else{
      info_antes = "Jornada:" + jornada->getTurno();
    }
    jornada_ = jornada;
    string info_depois;
    if(jornada_ == nullptr){
      info_depois = "Jornada: Vazio";
    }else{
      info_depois= "Jornada:" + jornada->getTurno();
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "setJornada";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

JornadaTrabalho *Funcionario::getJornada()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getJornada"))
  {
    string info_acessada = "jornada";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return jornada_;
  }
  else
  {
    string func_negada = "getjornada";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::setEmbarque(Horario embarque)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_setEmbarque"))
  {
    string info_antes;
    string info_depois;
    if (embarque_.paraHoras() == 0)
    {
      info_antes = "Embarque: Vazio";
    }
    else
    {
      info_antes = "Embarque: " + to_string(embarque_.getHora()) + ":" + to_string(embarque_.getMinuto()) + ":" + to_string(embarque_.getSegundo());
    }

    if (embarque.paraHoras() == 0)
    {
      info_depois = "Embarque: Vazio";
    }
    else
    {
      info_depois = "Embarque: " + to_string(embarque.getHora()) + ":" + to_string(embarque.getMinuto()) + ":" + to_string(embarque.getSegundo());
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    embarque_ = embarque;
  }

  else
  {
    string func_negada = "setEmbarque";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Horario Funcionario::getEmbarque()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getEmbarque"))
  {
    string info_acessada = "embarque";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return embarque_;
  }
  else
  {
    string func_negada = "getEmbarque";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::setPlacaTransporte(string placa)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_setPlacaTransporte"))
  {
    string info_antes = "Placa: Vazio ";
    string info_depois = "Placa: " + placa;
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    placa_transporte_ = placa;
  }
  else
  {
    string func_negada = "setPlacaTransporte";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

string Funcionario::getPlacaTransporte()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getPlacaTransporte"))
  {
    string info_acessada = "Placa do transporte";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return placa_transporte_;
  }
  else
  {
    string func_negada = "getPlacaTransporte";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

string Funcionario::getDepartamento(){
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Funcionario_getDepartamento"))
  {
    string info_acessada = "Nome do Departamento";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return departamento_;
  }
  else
  {
    string func_negada = "getDepartamento";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Funcionario::setDepartamento(string departamento){
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Funcionario";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_setDepartamento"))
  {
    departamento_ = departamento;
    string info_acessada = "Departamento " + departamento;
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
  }
    else
  {
    string func_negada = "setDepartamento";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}
Funcionario::~Funcionario()
{
  status_ = false;
  for (auto it = contratos_.begin(); it != contratos_.end(); it++)
   {
      delete it->second;
   }
  delete endereco_;
  delete usuario_;
  delete jornada_;
}
