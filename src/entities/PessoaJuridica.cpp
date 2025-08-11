#include "PessoaJuridica.h"
#include "Utility.h"
#include <iostream>

PessoaJuridica::PessoaJuridica(const string &nome, const string &telefone,
                               const string &email, const bool &tipo,
                               string cnpj)
    : Cliente(nome, telefone, email, tipo) {
  string entidade = "PessoaJuridica_PessoaJuridica";
  string info_antes = "Vazio";
  string info_depois = "Construido";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    setCNPJ(cnpj);
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


void PessoaJuridica::setCNPJ(string cnpj) {
  if (Utility::validaCNPJ(cnpj)) {
    cnpj_ = cnpj;
  } else {
    throw CNPJinvalido((char*)"CNPJ invalido!");
  }
}

string PessoaJuridica::getCNPJ() const { return cnpj_; }

void PessoaJuridica::imprimirDados() const {
  cout << "Nome: " << getNome() << endl;
  cout << "Telefone: " << getTelefone() << endl;
  cout << "Email: " << getEmail() << endl;
  cout << "Tipo: Pessoa Juridica" << endl;
  cout << "CNPJ: " << cnpj_ << endl;
}