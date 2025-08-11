#include "Empresa.h"

using namespace std;

int main()
{
  Logs::getInstance();

  //(1 - TESTE) ◦Instanciar um objeto da classe Empresa.
  // 1.1 Cria um endereço
  cout << "\nComeco do Teste 1:\n" << endl;
  pair<float, float> lat_long = {-19.86, -43.97};
  Endereco *mineirao = new Endereco("Av. Antonio Abrahao Caram", 1001, "Estadio", "31275000", "Sao Jose", "Belo Horizonte", "MG", "Brasil", lat_long);

  // 1.2 Instancia uma empresa
  Empresa *CBF = Empresa::getInstance("Confederacao Brasileira de Futebol", mineirao);
  // imprime o nome da empresa
  cout << "Nome da empresa: " << CBF->getNome() << endl;
  // imprime o endereco da empresa
  cout << "Endereco da empresa: " << endl;
  CBF->getEndereco()->printEndereco();
  // define um estoque para a empresa
  Estoque *estoque = new Estoque();
  CBF->setEstoque(estoque);
  cout << "\nFim do Teste 1" << endl;
  cout << endl;
  // fim do teste 1
  
  //(2 E 3 - TESTE) ◦Instanciar um objeto de um usuário logado que deverá ter permissão de acesso à todas as funcionalidades,
  //exceto ao método que realiza a exclusão de um funcionário e comprovar o funcionamento do singleton do usuário logado.
  cout << "\nComeco do Teste 2 e 3:\n" << endl;
  
  //2.1 Restringe acesso a determinados metodos
  list<string> metodos_negados = {"Empresa_Demissao", "Funcionario_demiteFuncionario"};
  
  //2.2 Cria uma premissao
  Permissao *ceo = new Permissao("CEO", metodos_negados);
  
  //2.3 Cria usuarios com a permissao de ceo
  Usuario *ronaldo = new Usuario("Fenomeno", "hexa2022", ceo);
  Usuario *kroos = new Usuario("Toni Kross", "seteaumnasede", ceo);

  //2.4 adiciona os usuarios criados à empresa
  CBF->addUsuario(ronaldo);
  CBF->addUsuario(kroos);

  // metodos nao permitidos do Ronaldo
  CBF->getUsuario("Fenomeno", "hexa2022")->printPermissao();
  
  //3.0 Cria uma sessao e loga o usuario na empresa 
  Sessao *session = Sessao::getInstance();
  try
  {
    // 3.1 Tentativa - tentar logar com usuario inexistente -> Deve falhar e lancar uma excessao
    Usuario *user = CBF->autenticarUsuario("Maradona", "argentinaesmejorquebrasil");
    session->login(user);
  }
  catch (ExecaoCustomizada &e)
  {
    cout << "Tentando logar com login inexistente: ";
    cout << e.what() << endl;
  }

  try
  {
    // 3.2 Tentativa - logando com um usuario valido -> Deve ser bem sucedida
    cout << "Tentando logar um usuario valido: ";
    session->login(CBF->autenticarUsuario("Fenomeno", "hexa2022"));
    cout << "Login feito com sucesso" << endl;
  }
  catch (ExecaoCustomizada &e)
  {
    cout << e.what() << endl;
  }

  // 3.3 Tentativa - tentando a partir de uma sessao já ocupada -> Deve falhar e lancar uma excessao
  try
  {
    session->login(CBF->autenticarUsuario("Toni Kross", "seteaumnasede"));
  }
  catch (ExecaoCustomizada &e)
  {
    cout << "Tentando logar em uma sessao ja ocupada: ";
    cout << e.what() << endl;
  }
  
  // 3.4 cria uma nova referencia para a sessao, mostrando que ambas armazenam as mesmas informacoes
  Sessao *sessao2 = Sessao::getInstance();
  
  // 3.5 acessa o usuario a partir dessa nova referencia
  Usuario *logged = sessao2->getSessao();
  cout << "Usuario logado: " << logged->getLogin() << endl;

  cout  << "\nFim do Teste 2 e 3" << endl;
  cout  << endl;
  // Fim do teste 2 e 3 

  // (4 - TESTE) ◦Cadastrar três funcionários.
  cout << "\nComeco do Teste 4:" << endl;

  // 4.1 define lat_longs para os funcionarios
  pair<float, float> latlong_viniJr = {-19.86334295251793, -43.99690102550068};       // Endereço da Toca da Raposa 1
  pair<float, float> latlong_richarlison = {-19.890573038686828, -43.96805386663168}; // Endereco Shopping delRey
  pair<float, float> latlong_antony = {-19.834035387310355, -44.0032855460466};       // Endereco da Toca da Raposa 2

  // 4.2 define enderecos para os funcionários
  Endereco *endereco_viniJr = new Endereco("Av. Otacilio Negrao de Lima", 7100, "Apartamento", "31340380", "Bandeirantes", "Belo Horizonte", "MG", "Brasil", latlong_viniJr);
  Endereco *endereco_richarlison = new Endereco("Av. Presidente Carlos Luz", 3001, "Casa", "31340380", "Pampulha", "Belo Horizonte", "MG", "Brasil", latlong_richarlison);
  Endereco *endereco_antony = new Endereco("Rua Adolfo Lippi Fonseca", 250, "Casa", "31545170", "Trevo", "Belo Horizonte", "MG", "Brasil", latlong_antony);

  // 4.3 define os funcionarios
  Data nascimento(2002, 06, 30);
  Funcionario *viniJr = new Funcionario("Vini Jr", "17372418704", endereco_viniJr, nascimento, "viniJr@gmail.com", "2021070888");
  Funcionario *richarlison = new Funcionario("Richarlison", "15287531605", endereco_richarlison, nascimento, "pombo@gmail.com", "2021013604");
  Funcionario *antony = new Funcionario("Antony", "13820119701", endereco_antony, nascimento, "antony@gmail.com", "2021019335");

  // 4.4.1 Define os contratos
  float salario = 5000.00;
  Cargo *cargo = new Cargo("Jogador");
  Data data = data.dateNow();
  Contrato *contrato_viniJr = new Contrato(data, cargo, salario);
  Contrato *contrato_antony = new Contrato(data, cargo, salario);
  Contrato *contrato_richarlisson = new Contrato(data, cargo, salario);

 // 4.4.2 Cria novo contrato para viniJr
  float salario2 = 10000.00;
  Cargo *cargo2 = new Cargo("Auxiliar Tecnico");
  Data data2 = data.dateNow();
  Contrato *contrato2_viniJr = new Contrato(data2, cargo2, salario2);

  viniJr->addContrato(contrato_viniJr);
  richarlison->addContrato(contrato_richarlisson);
  antony->addContrato(contrato_antony);
  viniJr->addContrato(contrato2_viniJr);
  // 4.5 Define os departamentos respectivos a cada funcionario
  Departamento *departamento = new Departamento("Concentracao");
  //4.5.1 Adiciona o departamento em empresa
  CBF->addDepartamento(departamento);
  //4.5.2 Adiciona os funcionarios no departamento
  departamento->addFuncionario(viniJr);
  departamento->addFuncionario(richarlison);
  departamento->addFuncionario(antony);
  cout << endl;
  cout << "Os funcionario do departamento Concentracao sao: " << endl;
  departamento->printFuncionarios();
  cout << endl;
  cout << "Contratos dos Funcionarios da Empresa:" << endl;
  viniJr->printContratos();
  cout << endl;
  richarlison->printContratos();
  cout << endl;
  antony->printContratos();
  cout << endl;

  cout << "\nFim do Teste 4" << endl;
  cout  << endl;
  // fim do teste 4 de cadastro de funcionarios

// (TESTE 5) Cadastrar dois clientes, sendo um PF e outro PJ.
  cout << "\nComeco do Teste 5:\n" << endl;

  const bool tpcpf = true;
  const bool tpcnpj = false;
  // 5.1 Cadastra cliente pessoa fisica
  PessoaFisica *ronaldinho = new PessoaFisica("Ronaldinho", "27996995694", "ronaldinho@ufmg.br", tpcpf, "880.298.316-09");
  // 5.2 Cadastra cliente pessoa juridica
  PessoaJuridica *flamengo = new PessoaJuridica("Clube de Regatas Flamengo", "1140028922", "flamengo@email.com", tpcnpj, "61.493.600/0001-23");
  // 5.3 Adiciona clientes em empresa
  CBF->addCliente(ronaldinho);
  CBF->addCliente(flamengo);
  //Imprime clientes de empresa
  CBF->printClientes();
  cout << "\nFim do Teste 5" << endl;
  cout  << endl;
  // Fim do teste 5 de cadastro de clientes
  
 //(TESTE 6 ) Cadastrar o produto Mesa (estoque mínimo: 20 unidades), que, para sua produção, necessita das matérias-primas e quantidades abaixo, que também devem ser cadastradas.
  /*
    ▪ Madeira: 450g (estoque mínimo: 1 Kg)
    ▪ Plástico: 150g (estoque mínimo: 1 Kg)
    ▪ Alumínio: 100g (estoque mínimo: 1 Kg)
    ▪ Parafusos: 8 unidades (estoque mínimo: 20 unidades)
  */
  cout << "\nComeco do Teste 6:\n" << endl;
  
  // 6.1.1 Cria os fornecedores de materia prima
  string cnpjNike = "87.878.428/0001-10";
  string cnpjAdidas = "17.793.403/0001-38";
  Fornecedor *nike = new Fornecedor("Nike", cnpjNike);
  Fornecedor *adidas = new Fornecedor("Adidas", cnpjAdidas);
  // 6.1.2 Adiciona os fornecedores de materia prima em empresa
  CBF->addFornecedor(nike);
  CBF->addFornecedor(adidas);

  // 6.2.1 Cadastra as materias primas em empresa
  MateriaPrima *madeira = new MateriaPrima("Madeira", 01, 1.00, "Kg");
  MateriaPrima *plastico = new MateriaPrima("Plastico", 02, 1.00, "Kg");
  MateriaPrima *aluminio = new MateriaPrima("Aluminio", 03, 1.00, "Kg");
  MateriaPrima *parafuso = new MateriaPrima("Parafuso", 04, 20.00, "Unidades");
  

  // 6.2.1 Adicionando os fornedores às matérias primas
  madeira->addFornecedor(nike);
  madeira->addFornecedor(adidas);
  plastico->addFornecedor(nike);
  plastico->addFornecedor(adidas);
  aluminio->addFornecedor(nike);
  aluminio->addFornecedor(adidas);
  parafuso->addFornecedor(nike);
  parafuso->addFornecedor(adidas);

  // 6.2.2 adiciona materias primas ao estoque;
  estoque->addMateriaPrima(madeira);
  estoque->addMateriaPrima(plastico);
  estoque->addMateriaPrima(aluminio);
  estoque->addMateriaPrima(parafuso);
  //imprime os fornecedores
  CBF->printFornecedores();
  

  // 6.3 Imprime ordem de compra e fornecedores de cada materia prima
  cout << "Fornecedores de materia prima: " << endl;
  cout << "Forcenedores de " << CBF->getEstoque()->getMateriaPrima("Madeira")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Madeira")->printFornecedores();
  cout << "Forcenedores de " << CBF->getEstoque()->getMateriaPrima("Plastico")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Plastico")->printFornecedores();
  cout << "Forcenedores de " << CBF->getEstoque()->getMateriaPrima("Aluminio")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Aluminio")->printFornecedores();
  cout << "Forcenedores de " << CBF->getEstoque()->getMateriaPrima("Parafuso")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Parafuso")->printFornecedores();
  
  cout << "Ordens de compra de materia prima: " << endl;
  cout << "Ordens de compra de " << CBF->getEstoque()->getMateriaPrima("Madeira")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Madeira")->printOrdensCompra();
  cout << "Ordens de compra de " << CBF->getEstoque()->getMateriaPrima("Plastico")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Plastico")->printOrdensCompra();
  cout << "Ordens de compra de " << CBF->getEstoque()->getMateriaPrima("Aluminio")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Aluminio")->printOrdensCompra();
  cout << "Ordens de compra de " << CBF->getEstoque()->getMateriaPrima("Parafuso")->getNome() << ":" << endl;
  CBF->getEstoque()->getMateriaPrima("Parafuso")->printOrdensCompra();

  // 6.4 Criando uma categoria para produto
  Categoria *categoria = new Categoria("moveis");
  // 6.4.1 Adiciona a categoria ao estoque de empresa
  estoque->addCategoria(categoria);

  // 6.5 Criar e adicionar produto
  // 6.5.1 Define preco para produto
  Preco *preco = new Preco(Data::dateNow(), 1500);
  // 6.5.2 Define as materias primas para produto
  map<MateriaPrima *, float> materias_primas_do_produto;
  materias_primas_do_produto.insert(make_pair(madeira, 0.450));
  materias_primas_do_produto.insert(make_pair(plastico, 0.150));
  materias_primas_do_produto.insert(make_pair(aluminio, 0.100));
  materias_primas_do_produto.insert(make_pair(parafuso, 8.00));
  // 6.5.3 Instancia um produto
  Produto *mesa = new Produto("Mesa", 05, preco, Data::dateNow(), 10, 20, materias_primas_do_produto);
  // 6.5.4 Adiciona produto a categoria
  categoria->addProduto(mesa);
  cout << "\nFim do teste 6" << endl;
  // fim do  teste 6 cadastro do produto

 // (TESTE 7) Devem ser produzidos lotes de mesa para atender o estoque mínimo
  cout << "\nInicio teste 7:\n" << endl;
  Utility u;

  // 7.1 Instancia um novo lote
  Lote *one = new Lote(Data::dateNow(), u.randomCode(100, 200), 25);
  // 7.2 Instancia um novo lote
  Lote *two = new Lote(Data::dateNow(), u.randomCode(300, 400), 25);

  // 7.3 Comprovando a quantidade antes de adicionar os lotes
  cout << "Quantidade de mesa ANTES de gerar os lotes: " << mesa->getQtdAtual() << endl;
  cout << "Quantidade de materia prima ANTES de produzir mais mesas (adicionar mais lotes): " << endl;
  for (auto it = materias_primas_do_produto.begin(); it != materias_primas_do_produto.end(); it++)
  {
    cout << "\tNome: " << it->first->getNome() << "-> Quantidade: " << it->first->getQtdAtual()
         << " " << it->first->getUnidadeMedida() << endl;
  }
  mesa->addLoteAtivo(one);
  mesa->addLoteAtivo(two); // olhar qd acabar a materia prima

  // 7.4 Comprovando a alteracao depois de adicionar os lotes
  cout << "Imprimindo lotes ativos de mesa" << endl;
  cout << "Quantidade de lotes ativos em mesa: " << estoque->getCategoria(categoria->getNome())->getProduto(mesa->getNome())->getLotesAtivos().size() << endl;
  list<Lote *> lotes = estoque->getCategoria(categoria->getNome())->getProduto(mesa->getNome())->getLotesAtivos();
  for (auto itr = lotes.begin(); itr != lotes.end(); itr++)
  {
    cout << " COD: " << (*itr)->getNumLote() << " - Quantidade atual do lote: " << (*itr)->getQuantidadeAtual() << endl;
  }

  cout << "\nQuantidade de mesa DEPOIS de gerar os lotes: " << mesa->getQtdAtual() << endl;
  //ATENTE-SE QUE AS MATERIAS PRIMAS SEMPRE IRÃO TER A QUANTIDADE MÍNIMA, POR MAIS QUE SEJA CONSUMIDA, SERA REPOSTA ATÉ A QUANTIDADE MÍNIMA
  //A MATERIA SO TERÁ MAIS QUANDO FOR SOLICITADA OCASIONALMENTE, FORA DE PRODUCAO DE PRODUTO 
  cout << "Quantidade de materia prima depois de produzir as mesas: " << endl; 
  for (auto it = materias_primas_do_produto.begin(); it != materias_primas_do_produto.end(); it++)
  {
    cout << "\tNome: " << it->first->getNome() << "-> Quantidade: " << it->first->getQtdAtual()
         << " " << it->first->getUnidadeMedida() << endl;
  }
  
  // 7.4.1 comprando materia prima ocasionalmente, apenas para ter mais no estoque
  madeira->addOrdemCompra(new OrdemCompra(Data::dateNow(), Utility::randomCode(10000,100000),30, madeira->getUnidadeMedida()));
  cout << "\nQuantidade de materia prima depois comprar apenas madeira: " << endl; 
  for (auto it = materias_primas_do_produto.begin(); it != materias_primas_do_produto.end(); it++)
  {
    cout << "\tNome: " << it->first->getNome() << "-> Quantidade: " << it->first->getQtdAtual()
         << " " << it->first->getUnidadeMedida() << endl;
  }

  // IMPRIMIR ORDENS DE PRODUCAO DE MESA
  CBF->getEstoque()->getCategoria(categoria->getNome())->getProduto(mesa->getNome())->printOrdemProducao();

  cout << "\nFim do teste 7" << endl;
  // fim do teste 7 producao de lotes

  // (TESTE 8) Tentar excluir um funcionário cadastrado no sistema
  cout << "\nInicio teste 8:\n" << endl;
  try
  {
    cout << "Antes de tentar demitir:" << endl;
    departamento->printFuncionarios();
    CBF->demissao(viniJr);
    cout << "Depois de tentar demitir:" << endl;
    departamento->printFuncionarios();
  }
  catch (ExecaoCustomizada &e)
  {
    cout << "Demite Funcionario: " << e.what() << endl;
  }
  
  cout << "\nDepois de tentar demitir:" << endl;
  departamento->printFuncionarios();
  cout << "\nFim teste 8" << endl;
  // Fim do teste 8 tentativa de Demissao

  // (TESTE 9)O cliente PJ deve solicitar um orçamento para aquisição de 10 mesas. Em função da previsão de falta de matéria-prima, após a geração desse orçamento, o preço da mesa deve sofrer um aumento de 5%. Em seguida o cliente decide adquirir as 10 mesas, mesmo após o aumento.
  cout << "\nInicio teste 9" << endl;

  //9.1 orcamento para 10 mesas
  map<Produto *, int> produto_quantidade;
  produto_quantidade.insert(make_pair(mesa, 10));
  unsigned int auxcodigo = Utility::randomCode(1000,10000);
  Orcamento *orcamento = new Orcamento(Data::dateNow(), auxcodigo, produto_quantidade);
  //9.2 adiciona orcamento ao cliente
  flamengo->addOrcamento(orcamento);

  flamengo->getOrcamento(auxcodigo)->printDados();
  // 9.3 aumento de preco
  cout << "Preco da mesa antes do aumento: " << mesa->getPrecoVendaAtual() << endl;
  Preco novopreco(Data::dateNow(), mesa->getPrecoVendaAtual() * 1.05);
  mesa->addPreco(&novopreco);
  cout << "Preco da mesa depois do aumento: " << mesa->getPrecoVendaAtual() << endl;

  //9.4 Define metodo de pagamento e pedido de compra
  CartaoCredito *cartao = new CartaoCredito(1, 987, "3456567890801234", orcamento->precoTotal(), 2);
  PedidoCompra *compra = new PedidoCompra(Utility::randomCode(100,1000), Data::dateNow(), orcamento, flamengo->getNome(), cartao);
  //9.5adiciona orcamento em cliente
  flamengo->addOrcamento(orcamento);
  try
  {
    //9.6 decisao do cliente
    compra->gerarVenda();
    CBF->addPedidoCompra(compra);
  }
  catch (ExecaoCustomizada &e)
  {
    cout << e.what() << endl;
  }

  //9.7 imprime todos os pedidos de compra em empresa
  cout << "Os pedidos de compra sao: " << endl;
  CBF->printPedidosCompra();

  cout << "\nFim do teste 9" << endl;

  //fim do teste 9

  //(TESTE 10) Deve ser cadastrada a rota de um veículo para transporte dos três funcionários cadastrados trabalharem no turno da manhã que se inicia às 8h. Devem ver exibidos os horários em que cada funcionário deverá embarcar.

  // 10.1 define jornada de trabalho
  cout << "\nInicio teste 10:\n" << endl;
  Horario inicio_turno(8, 0, 0);
  Horario fim_turno(13, 0, 0);
  JornadaTrabalho *jornada = new JornadaTrabalho("manha", inicio_turno, fim_turno);
  // 10.2 instancia veiculo
  Veiculo *brasilMovel = new Veiculo("HEXA2022", 20, jornada, mineirao);
  // 10.3 adiciona os funcionarios no veiculo
  brasilMovel->addPassageiro(viniJr);
  brasilMovel->addPassageiro(richarlison);
  brasilMovel->addPassageiro(antony);
  // 10.4 imprime a rota do veiculo
  brasilMovel->printRota();
  // 10.5 imprime horarios de embarque dos passageiros
  brasilMovel->printHorarioEmbarque();
  cout << "\nFim do teste 10" << endl;
  // fim do teste 10 de rota

  // (TESTE 11) Por fim, deve-se exibir os logs de todas as operações realizadas.
  cout << "\nTeste 11:\n" << endl;
  Logs::getInstance()->gerarTxtLogs();
  cout << "Logs gerados, confira o arquivo de texto 'Logs.txt'." << endl;
  cout << "\nFim do teste 11" << endl;
  //fim do teste 11 gerar logs
}