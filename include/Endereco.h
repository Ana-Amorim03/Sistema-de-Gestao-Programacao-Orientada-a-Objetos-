#ifndef ENDERECO_H
#define ENDERECO_H
#include "Sessao.h"
#include "Usuario.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Data.h"
#include "Logs.h"
#include <string>
#include <utility>
using namespace std;

class Endereco {

public:
  Endereco(const string &rua, const int &numero, const string &complemento,
           const string &cep, const string &bairro, const string &cidade,
           const string &uf, const string &pais, pair<float,float> lat_long);

  void setRua(const string &Rua);

  string getRua() const;

  void setNumero(const int &Numero);

  int getNumero() const;

  void setComplemento(const string &Complemento);

  string getComplemento() const;

  void setCEP(const string &CEP);

  string getCEP() const;

  void setBairro(const string &Bairro);

  string getBairro() const;

  void setCidade(const string &Cidade);

  string getCidade() const;

  void setUF(const string &UF);

  string getUF() const;

  void setPais(const string &Pais);

  string getPais() const;

  void setLatLong(pair<float,float> lat_long);

  pair<float,float>getLatLong();

  void printEndereco() const;

  //~Endereco();

private:
  string Rua_;
  int Numero_;
  string Complemento_;
  string CEP_;
  string Bairro_;
  string Cidade_;
  string UF_;
  string Pais_;
  pair<float, float> lat_long_;
};

#endif // ENDERECO_H
