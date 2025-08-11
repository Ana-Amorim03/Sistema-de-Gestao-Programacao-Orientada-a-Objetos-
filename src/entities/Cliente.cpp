#include "Cliente.h"
using namespace std;

Cliente::Cliente(const string nome, const string telefone, const string email, const bool tipo){
  string entidade = "Cliente_Cliente";
  string info_antes = "Vazio";
  string info_depois = "Construida";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    setNome(nome);
    setTelefone(telefone);
    setEmail(email);
    setTipo(tipo);
    //-----------------------------------------------------
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }

  
  
}

string Cliente::getNome() const{
  string entidade = "Cliente_getNome";
  string info_acessada = "nome_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return nome_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}
void Cliente::setNome(const string nome){
  nome_ = nome;
}

string Cliente::getTelefone() const{
  return telefone_;
}
void Cliente::setTelefone(const string telefone){
  telefone_ = telefone;
}

string Cliente::getEmail() const{
  return email_;
}
void Cliente::setEmail(const string email){
  email_ = email;
}

bool Cliente::getTipo() const{
  string entidade = "Cliente_getTipo";
  string info_acessada = "tipo_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    return tipo_;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
}
void Cliente::setTipo(const bool tipo){
  tipo_ = tipo;
}

Usuario* Cliente::getUsuario() const{
  return usuario_;
}
void Cliente::setUsuario(Usuario* usuario){
  usuario_ = usuario;
}

Orcamento* Cliente::getOrcamento(unsigned int codigo){
  string entidade = "Cliente_getOrcamento";
  string info_acessada = "orcamento_";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //-----------------------------------------------------------
    for(auto it = orcamentos_.begin(); it != orcamentos_.end(); it++){
      if((*it).second->getCodigo() == codigo){
        return (*it).second;
      }
    }

    return nullptr;
    //-----------------------------------------------------------
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
  
  
  
}
map<Data,Orcamento*> Cliente::getOrcamentos(){
  return orcamentos_;
}
void Cliente::addOrcamento(Orcamento *orcamento){
string entidade = "Cliente_addOrcamento";
  string info_antes = "";
  string info_depois = "";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    info_antes += "orcamentos_ {";
    int tempaux = 0;     
    for (auto tempit = orcamentos_.begin(); tempit != orcamentos_.end(); tempit++){
      info_antes += to_string(tempaux) + ":" + to_string(tempit->second->getCodigo()) + "; ";
      tempaux++;
    }
    info_antes += "}; ";
    //-------------
    orcamentos_[data.dateNow()] = orcamento;               
    //--------------
    info_depois += "orcamentos_ {";
    tempaux = 0;     
    for (auto tempit = orcamentos_.begin(); tempit != orcamentos_.end(); tempit++){
      info_depois += to_string(tempaux) + ":" + to_string(tempit->second->getCodigo()) + "; ";
      tempaux++;
    }
    info_depois += "}; ";
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    LogAcessoNegado* lognegado = new LogAcessoNegado(entidade, data, loggedUser->getLogin(), entidade);
    logs->addLog(lognegado);
    throw ExecaoAcessoNegado((char*)"Acesso Negado");
  };
  
}