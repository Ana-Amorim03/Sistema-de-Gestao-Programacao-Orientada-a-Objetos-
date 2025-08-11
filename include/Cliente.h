#ifndef CLIENTE_H
#define CLIENTE_H
#define _CNPJ 0
#define _CPF 1
#include <string>
#include "Usuario.h"
#include "Data.h"
#include <map>
#include <utility>
#include "Orcamento.h"
#include <iostream>
using namespace std;

class Cliente {
public: 
  string getNome() const;
  void setNome(const string nome);
  
  string getTelefone() const;
  void setTelefone(const string telefone);

  string getEmail() const;
  void setEmail(const string email);

  bool getTipo() const;
  void setTipo(const bool tipo);

  Usuario* getUsuario() const;
  void setUsuario(Usuario* usuario);
  
  Orcamento* getOrcamento(unsigned int codigo);
  map<Data,Orcamento*> getOrcamentos();
  void addOrcamento(Orcamento *orcamento);

  virtual void setCPF(string cpf) {}
  virtual void setCNPJ(string cnpj) {}
  virtual string getCPF() const {return "";}
  virtual string getCNPJ() const {return"";}

  virtual void imprimirDados() const {}

  virtual ~Cliente() {}
protected:
  Cliente(const string nome, const string telefone,
                 const string email, const bool tipo);

private:
  string nome_;
  string telefone_;
  string email_;
  Usuario* usuario_ = nullptr;
  bool tipo_;
  map<Data, Orcamento*> orcamentos_;
  string entidade = "Cliente";
};

#endif // CLIENTE_H