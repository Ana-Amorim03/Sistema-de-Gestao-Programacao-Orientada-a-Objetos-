#include "Empresa.h"
#include <vector>
#include <iostream>
#include <iomanip>

Empresa* Empresa::instancePtr = nullptr;

Empresa *Empresa::getInstance()
{
  // Usuario *loggedUser = Sessao::getInstance()->getSessao();
  //   Logs *logs = Logs::getInstance();
  //   string entidade = "Empresa";
  //   Data data = data.dateNow();
  //   if (loggedUser->ehPermitido("Empresa_getInstance"))
  // {
  //   string info_acessada = "Instancia";
  //   LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
  //   logs->addLog(logleitura);
    return instancePtr;
  // }
  // else
  // {
  //   string func_negada = "getInstance";
  //   LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
  //  logs->addLog(lognegado);
  //       throw ExecaoAcessoNegado((char*)"Acesso Negado");
  // }
}

Empresa *Empresa::getInstance(const string &nome, Endereco *endereco)
{
  // Usuario *loggedUser = Sessao::getInstance()->getSessao();
  //   Logs *logs = Logs::getInstance();
  //   string entidade = "Empresa";
  //   Data data = data.dateNow();
  //   if (loggedUser->ehPermitido("Empresa_getInstance"))
  // {
    // string info_acessada = "Instancia";
    // LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    // logs->addLog(logleitura);
    if (instancePtr == nullptr)
    {
      instancePtr = new Empresa(nome, endereco);
    }
    return instancePtr;
  // }
  // else
  // {
  //   string func_negada = "getInstance";
  //   LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
  //  logs->addLog(lognegado);
  //       throw ExecaoAcessoNegado((char*)"Acesso Negado");
  // }
}

Empresa::Empresa(const string &nome, Endereco *endereco) : nome_(nome), endereco_(endereco)
{
}

void Empresa::setNome(const string &nome)
{
  nome_ = nome;
}

string Empresa::getNome() const
{
  return nome_;
}

void Empresa::addDepartamento(Departamento *departamento)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_addDepartamento"))
  {
    auto it = departamentos_.find(departamento->getNome());
    if (it != departamentos_.end())
    {
      char message[100] = "Um departamento jah possui esse nome!";
      string func_negada = "addDepartamento";
      LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
     logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
      throw DepartamentoInvalido(message);
    }
    string info_antes;
    if (departamentos_.empty())
    {
      info_antes = "Departamento: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = departamentos_.begin(); it != departamentos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Departamento: " + (it)->first + "; ";
      }
    }

    departamentos_[departamento->getNome()] = departamento;
    int pos = 1;
    string info_depois;
    for (auto it = departamentos_.begin(); it != departamentos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Departamento: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addDepartamento";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Departamento *Empresa::getDepartamento(const string &nome) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getDepartamento"))
  {
    string info_acessada = "Departamento";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    auto it = departamentos_.find(nome);
    if (it != departamentos_.end())
    {
      return it->second;
    }
    char message[100] = "Nenhum departamento possui esse nome!";
    throw NaoEncontrado(message);
  }
  else
  {
    string func_negada = "getDepartamento";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Departamento *> Empresa::getDepartamentos() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getDepartamentos"))
  {
    string info_acessada = "Departamentos";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return departamentos_;
  }
  else
  {
    string func_negada = "getDepartamentos";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::removeDepartamento(const string &nome)
{
  auto it = departamentos_.find(nome);
  if (it != departamentos_.end())
  {
    delete it->second;
    departamentos_.erase(it);
  }
  char message[100] = "Nenhum departamento possui esse nome!";
  throw NaoEncontrado(message);
}

void Empresa::printDepartamentos() const
{
  cout << "Imprimindo departamentos: " << endl;
  for (auto it = departamentos_.begin(); it != departamentos_.end(); it++)
  {
    cout << it->first;
  }
}

void Empresa::addCargo(Cargo *cargo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_addCargo"))
  {
    auto it = cargos_.find(cargo->getNome());
    if (it != cargos_.end())
    {
      char message[100] = "Um cargo jah possui esse nome!";
      string func_negada = "addCargo";
      LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
     logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
      throw CargoInvalido(message);
    }
    string info_antes;
    if (cargos_.empty())
    {
      info_antes = "Cargo: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = cargos_.begin(); it != cargos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Departamento: " + (it)->first + "; ";
      }
    }

    cargos_[cargo->getNome()] = cargo;
    int pos = 1;
    string info_depois;
    for (auto it = cargos_.begin(); it != cargos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Cargo: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addCargo";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Cargo *Empresa::getCargo(const string &nome_cargo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getCargo"))
  {
    string info_acessada = "Cargo";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    auto it = cargos_.find(nome_cargo);
    if (it == cargos_.end())
    {
      char message[100] = "Nenhum cargo possui esse nome!";
      throw NaoEncontrado(message);
    }
    return it->second;
  }
  else
  {
    string func_negada = "getCargo";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Cargo *> Empresa::getCargos() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getCargos"))
  {
    string info_acessada = "Cargos";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return cargos_;
  }
  else
  {
    string func_negada = "getCargs";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::removeCargo(const string &nome_cargo)
{
  if (cargos_.find(nome_cargo) == cargos_.end())
  {
    char message[100] = "Cargo inexistente";
    throw NaoEncontrado(message);
  }
  cargos_.erase(nome_cargo);
}

void Empresa::printCargos() const
{
  cout << "Imprimindo Cargos: " << endl;
  for (auto it = cargos_.begin(); it != cargos_.end(); it++)
  {
    cout << it->first;
  }
}

void Empresa::addDissidioColetivo(Reajuste *dissidioColetivo)
{
  dissidiosColetivos_.push_back(dissidioColetivo);

  for (auto it1 = departamentos_.begin(); it1 != departamentos_.end(); it1++)
  {
    for (auto it2 = (*it1).second->getFuncionarios().begin(); it2 != (*it1).second->getFuncionarios().end(); it2++)
    {
      if ((*it2).second->getStatus() == true)
      {
        auto it = (*it2).second->getContratos().end();
        it--;
        it->second->addReajuste(dissidioColetivo);
      }
    }
  }
}

vector<Reajuste *> Empresa::getDissidiosColetivos() const
{
  return dissidiosColetivos_;
}

void Empresa::printDissidiosColetivos() const
{
  cout << "Imprimindo dissidios: " << endl;
  unsigned i = 1;
  for (auto it = dissidiosColetivos_.begin(); it != dissidiosColetivos_.end(); ++it, i++)
  {
    cout << "Reajuste " << i << ": " << fixed << setprecision(2);
    float aux = (*it)->getReajuste();
    cout << aux * 100 - 100 << "%" << endl;
  }
}

void Empresa::addCliente(Cliente *cliente)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_addCliente"))
  {
    auto it = clientes_.find(cliente->getNome());
    if (it != clientes_.end())
    {
      char message[100] = "Um cliente jah possui esse nome!";
      string func_negada = "addCliente";
      LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
     logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
      throw ClienteInvalido(message);
    }
    string info_antes;
    if (clientes_.empty())
    {
      info_antes = "Cliente: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = clientes_.begin(); it != clientes_.end(); it++)
      {
        info_antes += to_string(pos) + " - Cliente: " + (it)->first + "; ";
      }
    }

    clientes_[cliente->getNome()] = cliente;
    int pos = 1;
    string info_depois;
    for (auto it = clientes_.begin(); it != clientes_.end(); it++)
    {
      info_depois += to_string(pos) + " - cliente: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addCliente";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Cliente *> Empresa::getClientes() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getClientes"))
  {
    string info_acessada = "Clientes";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return clientes_;
  }
  else
  {
    string func_negada = "getClientes";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Cliente *Empresa::getCliente(const string &nome)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getClientes"))
  {
    string info_acessada = "Clientes";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (clientes_.find(nome) == clientes_.end())
    {
      char message[100] = "Nenhum cliente possui esse nome!";
      throw ClienteInvalido(message);
    }
    return clientes_[nome];
  }
  else
  {
    string func_negada = "getInstance";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::removeCliente(const string &nome)
{
  if (clientes_.find(nome) == clientes_.end())
  {
    char message[100] = "Cliente inexistente";
    throw NaoEncontrado(message);
  }
  clientes_.erase(nome);
}

void Empresa::printClientes() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_printClientes"))
  {
    cout << "Clientes da empresa: " << endl;
    for (auto it = clientes_.begin(); it != clientes_.end(); it++)
    {
      cout << "\t" << it->first << endl;
    }
    string info_acessada = "Clientes da Empresa";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
  }
    else
  {
    string func_negada = "printClientes";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}
void Empresa::setEstoque(Estoque* estoque){
  estoque_ = estoque;
}

Estoque *Empresa::getEstoque() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getEstoque"))
  {
    string info_acessada = "Estoque";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (estoque_ == nullptr)
    {
      char message[100] = "Estoque nao disponivel";
      throw NaoEncontrado(message);
    }
    return estoque_;
  }
  else
  {
    string func_negada = "getEstoque";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::addUsuario(Usuario *usuario)
{
    auto it = usuarios_.find(usuario->getLogin());
    if (it != usuarios_.end())
    {
      char message[100] = "Um usuario jah possui esse nome!";
      throw UsuarioInvalido(message);
    }
    usuarios_[usuario->getLogin()] = usuario;
}

Usuario *Empresa::getUsuario(const string &login, const string &senha)
{
   // Usuario *loggedUser = Sessao::getInstance()->getSessao();
  //   Logs *logs = Logs::getInstance();
  //   string entidade = "Empresa";
  //   Data data = data.dateNow();
  //   if (loggedUser->ehPermitido("Empresa_getUsuario"))
  //{
    // string info_acessada = "Usuario";
    // LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    // logs->addLog(logleitura);
    for (auto it = usuarios_.begin(); it != usuarios_.end(); it++)
    {
      if ((it->second->getLogin() == login) && (it->second->getSenha() == senha))
      {
        return it->second;
      }
    }
    return nullptr;
  //}
/*   else
  {
    string func_negada = "getUsuario";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  } */
}

void Empresa::removeUsuario(const string &login)
{
  if (usuarios_.find(login) == usuarios_.end())
  {
    char message[100] = "Usuario inexistente";
    throw NaoEncontrado(message);
  }
  usuarios_.erase(login);
}

void Empresa::printUsuarios() const
{
  cout << "Usuarios na empresa: " << endl;
  for (auto it = usuarios_.begin(); it != usuarios_.end(); it++)
  {
    cout << ". " << it->first << endl;
  }
}

void Empresa::addPermissao(Permissao *permissao)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Categoria_addPermissao"))
  {
    string info_antes;
    if (permissoes_.empty())
    {
      info_antes = "Permissões: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = permissoes_.begin(); it != permissoes_.end(); it++)
      {
        info_antes += to_string(pos) + " - Permissao: " + (it)->first + "; ";
      }
    }

    permissoes_.emplace(permissao->getNome(), permissao);
    int pos = 1;
    string info_depois;
    for (auto it = permissoes_.begin(); it != permissoes_.end(); it++)
    {
      info_depois += to_string(pos) + " - Permissao: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "addPermissao";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Permissao *Empresa::getPermissao(const string &nome) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getPermissao"))
  {
    string info_acessada = "Permissao";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (permissoes_.find(nome) == permissoes_.end())
    {
      char message[100] = "Nivel inexistente";
      throw NaoEncontrado(message);
    }
    return permissoes_.at(nome);
  }
  else
  {
    string func_negada = "getPermissao";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Permissao *> Empresa::getPermissoes() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getPermissoes"))
  {
    string info_acessada = "Permissoes";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return permissoes_;
  }
  else
  {
    string func_negada = "getPermissoes";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::removePermissao(const string &nome)
{
  if (permissoes_.find(nome) == permissoes_.end())
  {
    char message[100] = "Permissao inexistente";
    throw NaoEncontrado(message);
  }
  permissoes_.erase(nome);
}

void Empresa::printPermissoes() const
{
  cout << "Niveis de permissao na empresa: " << endl;
  for (auto it = permissoes_.begin(); it != permissoes_.end(); it++)
  {
    cout << it->first << endl;
  }
}

void Empresa::addPedidoCompra(PedidoCompra *pedido_compra)
{

  Data data_agora = Data::dateNow();
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_addPedidoCompra"))
  {
    string info_antes;
    if (pedidos_compra_.empty())
    {
      info_antes = "Pedido Compra: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = pedidos_compra_.begin(); it != pedidos_compra_.end(); it++)
      {
        info_antes += to_string(pos) + " - Pedido Compra: " + to_string((it)->second->getCodigo()) + "; ";
      }
    }
    pedidos_compra_[data_agora] = pedido_compra;

    int pos = 1;
    string info_depois;
    for (auto it = pedidos_compra_.begin(); it != pedidos_compra_.end(); it++)
    {
      info_depois += to_string(pos) + " - Pedido Compra: " + to_string((it)->second->getCodigo()) + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }

  else
  {
    string func_negada = "addPedidoCompra";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<Data, PedidoCompra *> Empresa::getPedidosCompra()
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getPedidosCompra"))
  {
    string info_acessada = "PedidosCompra";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return pedidos_compra_;
  }
  else
  {
    string func_negada = "getPedidosCompra";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

PedidoCompra *Empresa::getPedidoCompra(const Data data_pedido) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getPedidoCompra"))
  {
    string info_acessada = "PedidoCompra";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    if (pedidos_compra_.find(data_pedido) == pedidos_compra_.end())
    {
      char message[100] = "Nao ha pedido para a data";
      throw NaoEncontrado(message);
    }
    return pedidos_compra_.at(data_pedido);
  }
  else
  {
    string func_negada = "getPedidoCompra";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::printPedidosCompra() const
{
  auto it = pedidos_compra_.begin();
  if (it == pedidos_compra_.end())
  {
    cout << "Não ha pedidos de compra" << endl;
  }
  else
  {
    for (; it != pedidos_compra_.end(); it++)
    {
      PedidoCompra *pedido = (*it).second;
      Venda *venda = pedido->getVenda();
      Orcamento *orcamento = pedido->getOrcamento();
      cout << "Pedido cod: " << pedido->getCodigo() << "\n\trealizado em: " << (*it).first.getData() << endl;
      cout << "\tCliente: " << pedido->getCliente() << endl;
      cout << "\tData do orcamento: " << orcamento->getData().getData() << endl;
      cout << "\tQuantidade Total de Produto: " << orcamento->qtdTotalProdutos() << endl;
      cout << "\tPreco Total:" << orcamento->precoTotal() << endl;
      cout << "\tData da venda: " << venda->getDataVenda().getData() << endl;
    }
  }
}

map<Data, LogEscrita *> Empresa::getLogsEscrita() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getLogsEscrita"))
  {
    string info_acessada = "Logs de escrita";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return logs_escrita_;
  }

  else
  {
    string func_negada = "getLogsEscrita";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<Data, LogLeitura *> Empresa::getLogsLeitura() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getLogsLeitura"))
  {
    string info_acessada = "Logs de leitura";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return logs_leitura_;
  }

  else
  {
    string func_negada = "getLogsAcessoNegado";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<Data, LogAcessoNegado *> Empresa::getLogsAcessoNegado() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getLogsAcessoNegado"))
  {
    string info_acessada = "Logs de Acesso Negado";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return logs_acesso_negado_;
  }

  else
  {
    string func_negada = "getLogsAcessoNegado";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::addFornecedor(Fornecedor *fornecedor)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa::addFornecedor"))
  {
    string info_antes;
    if (fornecedores_.empty())
    {
      info_antes = "Fornecedor: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++)
      {
        info_antes += to_string(pos) + " - Fornecedor: " + (it)->first + "; ";
      }
    }
    string nome = fornecedor->getNome();
    fornecedores_.emplace(nome, fornecedor);
    int pos = 1;
    string info_depois;
    for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++)
    {
      info_depois += to_string(pos) + " - Fornecedor: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }

  else
  {
    string func_negada = "addFornecedor";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::removeFornecedor(const string &nome)
{
  if (fornecedores_.find(nome) == fornecedores_.end())
  {
    char message[100] = "Não ha fornecedor para o nome";
    throw NaoEncontrado(message);
  }
  fornecedores_.erase(nome);
}

Fornecedor *Empresa::getFornecedor(const string &nome) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getFornecedor"))
  {
    if (fornecedores_.find(nome) == fornecedores_.end())
    {
      char message[100] = "Não ha fornecedor para o nome";
      throw NaoEncontrado(message);
    }
    string info_acessada = "Fornecedor";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return fornecedores_.at(nome);
  }

  else
  {
    string func_negada = "getFornecedor";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Fornecedor *> Empresa::getFornecedores() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getFornecedores"))
  {
    string info_acessada = "map de Fornecedores";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return fornecedores_;
  }

  else
  {
    string func_negada = "getFornecedores";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::printFornecedores() const
{
  cout << "Imprimindo fornecedores da empresa: " << endl;
  for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++)
  {
    cout << "-> " << it->first << endl;
    it->second->printDados();
    cout << endl;
  }
}

void Empresa::addVeiculo(Veiculo *veiculo)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa::addVeiculo"))
  {
    string info_antes;
    if (veiculos_.empty())
    {
      info_antes = "Veiculo: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
      {
        info_antes += to_string(pos) + " - Veiculo: " + (it)->first + "; ";
      }
    }

    veiculos_.emplace(veiculo->getPlaca(), veiculo);
    int pos = 1;
    string info_depois;
    for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
    {
      info_depois += to_string(pos) + " - Veiculo: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }

  else
  {
    string func_negada = "addVeiculo";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::removeVeiculo(const string &placa)
{
  if (veiculos_.find(placa) == veiculos_.end())
  {
    char message[100] = "Não ha veiculo para a placa";
    throw NaoEncontrado(message);
  }
  veiculos_.erase(placa);
}

Veiculo *Empresa::getVeiculo(const string &placa) const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getVeiculo"))
  {
    if (veiculos_.find(placa) == veiculos_.end())
    {
      char message[100] = "Não ha veiculo para a placa";
      throw NaoEncontrado(message);
    }
    string info_acessada = "Veiculo";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return veiculos_.at(placa);
  }
  else
  {
    string func_negada = "getVeiculo";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

map<string, Veiculo *> Empresa::getVeiculos() const
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_getVeiculos"))
  {
    string info_acessada = "map de Veiculos";
    LogLeitura* logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    return veiculos_;
  }

  else
  {
    string func_negada = "getVeiculos";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

void Empresa::printVeiculos() const
{
  cout << "Imprimindo garagem da empresa: " << endl;
  for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
  {
    cout << "Nome do veiculo: " << it->first << endl;
  }
}

void Empresa::setJornada(const string &turno, const Horario inicio, const Horario fim)
{
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_setJornada"))
  {
    string info_antes;
    if (jornadas_.empty())
    {
      info_antes = "Jornada: Vazio";
    }
    else
    {
      int pos = 1;
      for (auto it = jornadas_.begin(); it != jornadas_.end(); it++)
      {
        info_antes += to_string(pos) + " - Jornada: " + (it)->first + "; ";
      }
    }

    JornadaTrabalho *jornada = new JornadaTrabalho(turno, inicio, fim);
    jornadas_.emplace(turno, jornada);
    int pos = 1;
    string info_depois;
    for (auto it = jornadas_.begin(); it != jornadas_.end(); it++)
    {
      info_depois += to_string(pos) + " - Jornada: " + (it)->first + "; ";
    }
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
  }
  else
  {
    string func_negada = "setJornada";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}
void Empresa::setEndereco(Endereco *endereco)
{
  endereco_ = endereco;
}

Endereco *Empresa::getEndereco() const
{
  return endereco_;
}

Usuario *Empresa::autenticarUsuario(string login, string senha)
{
  Usuario *usuario = this->getUsuario(login, senha);
  return usuario;
}

void Empresa::demissao(Funcionario *funcionario){
    Usuario *loggedUser = Sessao::getInstance()->getSessao();
    Logs *logs = Logs::getInstance();
    string entidade = "Empresa";
    Data data = data.dateNow();
    if (loggedUser->ehPermitido("Empresa_Demissao")){
    string info_antes = funcionario->getNome() + to_string(funcionario->getStatus());
    Departamento *aux = getDepartamento(funcionario->getDepartamento());
    Veiculo *veiculo = getVeiculo(funcionario->getPlacaTransporte());
    funcionario->demiteFuncionario(data);
    aux->removeFuncionario(funcionario->getNome());
    veiculo->removePassageiro(funcionario);
    string info_depois = funcionario->getNome() + to_string(funcionario->getStatus());
    LogEscrita* logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    }
  else
  {
    string func_negada = "Demissao";
    LogAcessoNegado* lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}

Empresa::~Empresa()
{
  for (auto it = jornadas_.begin(); it != jornadas_.end(); it++)
  {
    delete (*it).second;
  }
  for (auto it = clientes_.begin(); it != clientes_.end(); it++)
  {
    delete (*it).second;
  }
  for (auto it = veiculos_.begin(); it != veiculos_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = fornecedores_.begin(); it != fornecedores_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = pedidos_compra_.begin(); it != pedidos_compra_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = permissoes_.begin(); it != permissoes_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = usuarios_.begin(); it != usuarios_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = cargos_.begin(); it != cargos_.end(); it++)
  {
    delete it->second;
  }
  for (auto it = departamentos_.begin(); it != departamentos_.end(); it++)
  {
    delete it->second;
  }
  // for (unsigned it = 0; it < dissidiosColetivos_.size(); it++)
  // {
  //   delete dissidiosColetivos_[it];
  // }
  delete endereco_;
  delete instancePtr;
  delete estoque_;
}