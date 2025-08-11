#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Contrato.h"
#include "Endereco.h"
#include "Data.h"
#include "Usuario.h"
#include "JornadaTrabalho.h"
#include "Horario.h"
#include <map>

class DataInvalida : public ExecaoCustomizada {
public:
  DataInvalida(char *e) : ExecaoCustomizada(e) {}
};

class FuncionarioDesligado : public ExecaoCustomizada {
public:
  FuncionarioDesligado(char *e) : ExecaoCustomizada(e) {}
};

class Funcionario {

public:
  Funcionario(const string &nome, string cpf, Endereco *endereco,
              Data &data_nasc, const string &email, const string &matricula);

  void setNome(const string &nome);

  void setCPF(string cpf);

  void setEndereco(const string &rua, const int &numero,
                   const string &complemento, const string &cep,
                   const string &bairro, const string &cidade, const string &uf,
                   const string &pais);

  void setDataNasc(Data &data_nasc);

  void setEmail(const string &email);

  void setMatricula(const string &matricula);

  void setUsuario(Usuario *usuario);

  void setStatus(bool status);

  string getNome() const;

  string getCpf() const;

  Endereco *getEndereco() const;

  Data getDataNasc() const;

  string getEmail() const;

  string getMatricula() const;

  map<Data, Contrato *> getContratos() const;

  Contrato *getContrato(Data &data_admissao) const;

  bool getStatus() const;

  Usuario *getUsuario() const;

  void addContrato(Contrato *contrato);

  void removeContrato(Data &data_admissao);

  void printContratos();

  void printDados();

  void demiteFuncionario(Data &data_desligamento);

  void setJornada(JornadaTrabalho *jornada);

  JornadaTrabalho *getJornada();

  void setEmbarque(Horario embarque);

  Horario getEmbarque();

  void setPlacaTransporte(string placa);

  string getPlacaTransporte();

  string getDepartamento();

  void setDepartamento(string departamento);

  ~Funcionario();

private:
  string nome_;
  string cpf_;
  Endereco *endereco_;
  Data data_nasc_;
  Data data_zero_;
  string email_;
  string matricula_;
  map<Data,Contrato *> contratos_;
  bool status_;
  Usuario *usuario_ = nullptr;
  JornadaTrabalho *jornada_ = nullptr;
  string placa_transporte_;
  Horario embarque_;
  string departamento_;
  
};

#endif // FUNCIONARIO_H
