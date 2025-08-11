#include "PessoaFisica.h"
#include "Utility.h"
#include <iostream>
#include "Data.h"
#include "Sessao.h"
#include "Usuario.h"
#include "Logs.h"
/* Usuario *loggedUser = Sessao::getInstance()->getSessao();
Logs *logs = Logs::getInstance();
string entidade = "PessoaFisica";
Data data;
 */
PessoaFisica::PessoaFisica(const string nome, const string telefone,
                           const string email, const bool tipo, string cpf)
    : Cliente(nome, telefone, email, tipo) {
  string entidade = "PessoaFisica_PessoaFisica";
  string info_antes = "Vazio;";
  string info_depois = "Construido";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  Logs *logs = Logs::getInstance();
  Data data = data.dateNow();
  if (loggedUser->ehPermitido(entidade))
  {
    //-----------------------------------------------------
    setCPF(cpf);
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

void PessoaFisica::setCPF(string cpf) {

    if (Utility::validaCPF(cpf)) {
      cpf_ = cpf;     
    } else {
      throw CPFinvalido((char*)"CPF invalido!");
    }

}

string PessoaFisica::getCPF() const { 

    return cpf_;
   
}

void PessoaFisica::imprimirDados() const {

    cout << "Nome: " << getNome() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Email: " << getEmail() << endl;
    cout << "Tipo: Pessoa Fisica" << endl;
    cout << "CPF: " << cpf_ << endl;

}

  