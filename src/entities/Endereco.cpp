#include "Endereco.h"
#include <iostream>
#include <string>


Endereco::Endereco(const string &rua, const int &numero,
                   const string &complemento, const string &cep,
                   const string &bairro, const string &cidade, const string &uf,
                   const string &pais, pair<float, float> lat_long)
{
    Rua_ = rua;
    Numero_ = numero;
    Complemento_ = complemento;
    Bairro_ = bairro;
    Cidade_ = cidade;
    UF_ = uf;
    Pais_ = pais;
    CEP_ = cep;
    lat_long_ = lat_long;
}

void Endereco::setRua(const string &Rua) { Rua_ = Rua; }

string Endereco::getRua() const { return Rua_; }

void Endereco::setNumero(const int &Numero) { Numero_ = Numero; }

int Endereco::getNumero() const { return Numero_; }

void Endereco::setComplemento(const string &Complemento) { Complemento_ = Complemento; }

string Endereco::getComplemento() const { return Complemento_; }

void Endereco::setCEP(const string &CEP) { CEP_ = CEP; }

string Endereco::getCEP() const {
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Endereco";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Endereco_getCEP"))
  {      
    string info_acessada = "CEP";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return CEP_;
  }
  else{
    string func_negada = "getCEP";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Endereco::setBairro(const string &Bairro) { Bairro_ = Bairro; }

string Endereco::getBairro() const { return Bairro_; }

void Endereco::setCidade(const string &Cidade) { Cidade_ = Cidade; }

string Endereco::getCidade() const { return Cidade_; }

void Endereco::setUF(const string &UF) { UF_ = UF; }

string Endereco::getUF() const { return UF_; }

void Endereco::setPais(const string &Pais) { Pais_ = Pais; }

string Endereco::getPais() const { return Pais_; }

void Endereco::setLatLong(pair<float, float> lat_long) { lat_long_ = lat_long; }

pair<float, float> Endereco::getLatLong()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Endereco";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Endereco_getLatLong"))
  {      
    string info_acessada = "lat_long";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return lat_long_;
  }
  else{
    string func_negada = "getLatLong";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Endereco::printEndereco() const
{
  cout << Rua_ << ", " << Numero_ << ", " << Complemento_ << ", " << CEP_
       << ", " << Bairro_ << ", " << Cidade_ << ", " << UF_ << ", " << Pais_
       << endl;
  cout << "Latitude e Longitude: " << lat_long_.first << " " << lat_long_.second << endl;
}
