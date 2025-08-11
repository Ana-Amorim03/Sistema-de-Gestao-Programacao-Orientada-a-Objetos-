#ifndef EMPRESA_H
#define EMPRESA_H

#include "CartaoCredito.h"
#include "Boleto.h"
#include "Departamento.h"
#include "PessoaFisica.h"
#include "PessoaJuridica.h"
#include "Estoque.h"
#include "Reajuste.h"
#include "PedidoCompra.h"
#include "Fornecedor.h"
#include "Veiculo.h"
#include "JornadaTrabalho.h"
#include "Horario.h"
#include "Data.h"
#include "Logs.h"
#include "Log.h"
#include "Sessao.h"
#include "Usuario.h"
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <list>

using namespace std;

class CargoInvalido : public ExecaoCustomizada {
public:
  CargoInvalido(char *e) : ExecaoCustomizada(e) {}
};

class ClienteInvalido : public ExecaoCustomizada {
public:
  ClienteInvalido(char *e) : ExecaoCustomizada(e) {}
};

class UsuarioInvalido : public ExecaoCustomizada {
public:
  UsuarioInvalido(char *e) : ExecaoCustomizada(e) {}
};

class DepartamentoInvalido : public ExecaoCustomizada {
public:
  DepartamentoInvalido(char *e) : ExecaoCustomizada(e) {}
};

class NaoEncontrado : public ExecaoCustomizada {
public:
  NaoEncontrado(char *e) : ExecaoCustomizada(e) {}
};

class Empresa {
  string nome_;
  map<string, Departamento*> departamentos_;
  map<string, Cargo*> cargos_;
  vector<Reajuste*> dissidiosColetivos_;
  map<string, Cliente*> clientes_;
  Estoque* estoque_;
  map<string, Usuario*> usuarios_;
  map<string, Permissao*>permissoes_;
  static Empresa *instancePtr;
  map<Data, PedidoCompra*> pedidos_compra_;
  map<Data, LogEscrita*> logs_escrita_;
  map<Data, LogLeitura*> logs_leitura_;
  map<Data, LogAcessoNegado*> logs_acesso_negado_;
  map<string, Fornecedor*> fornecedores_;
  map<string, Veiculo*> veiculos_;
  map<string, JornadaTrabalho*> jornadas_;
  Endereco* endereco_;
  Empresa(const string &nome, Endereco* endereco);
public:
  static Empresa* getInstance(const string &nome, Endereco* endereco);  
  static Empresa* getInstance();  
  void setNome(const string &nome);
  string getNome() const;
  void addDepartamento(Departamento *departamento);
  Departamento* getDepartamento(const string &nome) const;
  map<string, Departamento*> getDepartamentos() const;
  void removeDepartamento(const string &nome);
  void printDepartamentos() const;  
  void addCargo(Cargo *cargo);
  Cargo* getCargo(const string &nome_cargo);
  map<string, Cargo*> getCargos() const;
  void removeCargo(const string &nome_cargo);
  void printCargos() const;
  void addDissidioColetivo(Reajuste* dissidioColetivo);
  vector<Reajuste*> getDissidiosColetivos() const;
  void printDissidiosColetivos() const;
  void addCliente(Cliente *cliente);
  map<string, Cliente*> getClientes() const;
  Cliente* getCliente(const string &nome);
  void removeCliente(const string &nome);
  void printClientes() const;
  void setEstoque(Estoque* estoque);
  Estoque* getEstoque() const;
  void addUsuario(Usuario* usuario);
  Usuario* getUsuario(const string &login, const string &senha);
  void removeUsuario(const string &login);
  void printUsuarios() const;
  void addPermissao(Permissao* permissao);
  Permissao* getPermissao(const string &nome) const;
  map<string, Permissao*> getPermissoes() const;
  void removePermissao(const string &nome);
  void printPermissoes() const;
  void addPedidoCompra(PedidoCompra* pedido_compra);
  map<Data, PedidoCompra*> getPedidosCompra();
  PedidoCompra* getPedidoCompra(const Data data_pedido) const;
  void printPedidosCompra() const;
  map<Data, LogEscrita*> getLogsEscrita() const;
  map<Data, LogLeitura*> getLogsLeitura() const;
  map<Data, LogAcessoNegado *> getLogsAcessoNegado() const;
  void addFornecedor(Fornecedor *fornecedor);
  void removeFornecedor(const string &nome);
  Fornecedor* getFornecedor(const string &nome) const;
  map<string, Fornecedor*> getFornecedores() const;
  void printFornecedores() const;
  void addVeiculo(Veiculo* veiculo);
  void removeVeiculo(const string &placa);
  Veiculo* getVeiculo(const string &placa) const;
  map<string, Veiculo*> getVeiculos() const;
  void printVeiculos() const;
  void setJornada(const string &turno, const Horario inicio, const Horario fim);
  void setEndereco(Endereco *endereco);
  Endereco* getEndereco() const;
  Usuario* autenticarUsuario(string login, string senha);
  void demissao(Funcionario *funcionario);
  ~Empresa();
};

#endif // EMPRESA_H
