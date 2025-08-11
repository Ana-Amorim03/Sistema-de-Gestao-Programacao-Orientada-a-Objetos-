#ifndef PESSOAFISICA_H
#define PESSOAFISICA_H
#include "Cliente.h"

class PessoaFisica : public Cliente {
public:
  PessoaFisica(const string nome, const string telefone, const string email,
               const bool tipo, string cpf);

  void setCPF(string cpf) override;
  
  string getCPF() const override;

  void imprimirDados() const override;

  ~PessoaFisica() {}
private:
  string cpf_;
  string entidade = "PessoaFisica";
};

#endif // PESSOAFISICA_H