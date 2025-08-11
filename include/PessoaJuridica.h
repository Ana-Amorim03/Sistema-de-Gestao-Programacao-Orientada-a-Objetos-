#ifndef PESSOAJURIDICA_H
#define PESSOAJURIDICA_H
#include "Cliente.h"

class PessoaJuridica : public Cliente {
public:
  PessoaJuridica(const string &nome, const string &telefone,
                 const string &email, const bool &tipo, string cnpj);

  void setCNPJ(string cnpj) override;
  
  string getCNPJ() const override;

  void imprimirDados() const override;

  ~PessoaJuridica() {}
private:
  string cnpj_;
};

#endif // PESSOAJURIDICA_H