CC = g++
CFLAGS = -std=c++11 -Wall -Wzero-as-null-pointer-constant

BUILD_DIR = ./build
SRC_DIR = ./src/entities
INCLUDE_DIR = ./include

TP: ./src/main.cpp ${BUILD_DIR}/Boleto.o ${BUILD_DIR}/Cargo.o ${BUILD_DIR}/CartaoCredito.o ${BUILD_DIR}/Categoria.o ${BUILD_DIR}/Cliente.o ${BUILD_DIR}/Contrato.o ${BUILD_DIR}/Data.o ${BUILD_DIR}/Departamento.o ${BUILD_DIR}/Empresa.o ${BUILD_DIR}/Endereco.o ${BUILD_DIR}/Estoque.o ${BUILD_DIR}/Empresa.o ${BUILD_DIR}/Endereco.o ${BUILD_DIR}/Estoque.o ${BUILD_DIR}/Formato.o ${BUILD_DIR}/Fornecedor.o ${BUILD_DIR}/Funcionario.o ${BUILD_DIR}/Horario.o ${BUILD_DIR}/JornadaTrabalho.o ${BUILD_DIR}/Log.o ${BUILD_DIR}/LogAcessoNegado.o ${BUILD_DIR}/LogEscrita.o ${BUILD_DIR}/LogLeitura.o ${BUILD_DIR}/Logs.o ${BUILD_DIR}/Lote.o ${BUILD_DIR}/MateriaPrima.o ${BUILD_DIR}/MetodoPagamento.o ${BUILD_DIR}/Orcamento.o ${BUILD_DIR}/OrcamentoMateriaPrima.o ${BUILD_DIR}/OrdemCompra.o ${BUILD_DIR}/OrdemProducao.o ${BUILD_DIR}/PedidoCompra.o ${BUILD_DIR}/OrdemProducao.o ${BUILD_DIR}/PedidoCompra.o ${BUILD_DIR}/Permissao.o ${BUILD_DIR}/PessoaFisica.o ${BUILD_DIR}/PessoaJuridica.o ${BUILD_DIR}/Preco.o ${BUILD_DIR}/Produto.o ${BUILD_DIR}/Venda.o ${BUILD_DIR}/Veiculo.o ${BUILD_DIR}/Usuario.o ${BUILD_DIR}/Sessao.o ${BUILD_DIR}/Utility.o ${BUILD_DIR}/Reajuste.o
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ ${BUILD_DIR}/*.o ./src/main.cpp -o TP

${BUILD_DIR}/Utility.o: ${INCLUDE_DIR}/Utility.h ${SRC_DIR}/Utility.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Utility.cpp -o ${BUILD_DIR}/Utility.o

${BUILD_DIR}/Formato.o: ${INCLUDE_DIR}/Formato.h ${SRC_DIR}/Formato.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Formato.cpp -o ${BUILD_DIR}/Formato.o

${BUILD_DIR}/Data.o: ${INCLUDE_DIR}/Data.h ${SRC_DIR}/Data.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Data.cpp -o ${BUILD_DIR}/Data.o

${BUILD_DIR}/Log.o: ${INCLUDE_DIR}/Log.h ${SRC_DIR}/Log.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Log.cpp -o ${BUILD_DIR}/Log.o

${BUILD_DIR}/LogAcessoNegado.o: ${INCLUDE_DIR}/LogAcessoNegado.h ${SRC_DIR}/LogAcessoNegado.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/LogAcessoNegado.cpp -o ${BUILD_DIR}/LogAcessoNegado.o

${BUILD_DIR}/LogEscrita.o: ${INCLUDE_DIR}/LogEscrita.h ${SRC_DIR}/LogEscrita.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/LogEscrita.cpp -o ${BUILD_DIR}/LogEscrita.o

${BUILD_DIR}/LogLeitura.o: ${INCLUDE_DIR}/LogLeitura.h ${SRC_DIR}/LogLeitura.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/LogLeitura.cpp -o ${BUILD_DIR}/LogLeitura.o

${BUILD_DIR}/Logs.o: ${INCLUDE_DIR}/Logs.h ${SRC_DIR}/Logs.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Logs.cpp -o ${BUILD_DIR}/Logs.o

${BUILD_DIR}/Permissao.o: ${INCLUDE_DIR}/Permissao.h ${SRC_DIR}/Permissao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Permissao.cpp -o ${BUILD_DIR}/Permissao.o

${BUILD_DIR}/Usuario.o: ${INCLUDE_DIR}/Usuario.h ${SRC_DIR}/Usuario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Usuario.cpp -o ${BUILD_DIR}/Usuario.o

${BUILD_DIR}/Sessao.o: ${INCLUDE_DIR}/Sessao.h ${SRC_DIR}/Sessao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Sessao.cpp -o ${BUILD_DIR}/Sessao.o

${BUILD_DIR}/Endereco.o: ${INCLUDE_DIR}/Endereco.h ${SRC_DIR}/Endereco.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Endereco.cpp -o ${BUILD_DIR}/Endereco.o

${BUILD_DIR}/Contrato.o: ${INCLUDE_DIR}/Contrato.h ${SRC_DIR}/Contrato.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Contrato.cpp -o ${BUILD_DIR}/Contrato.o

${BUILD_DIR}/Funcionario.o: ${INCLUDE_DIR}/Funcionario.h ${SRC_DIR}/Funcionario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Funcionario.cpp -o ${BUILD_DIR}/Funcionario.o

${BUILD_DIR}/Departamento.o: ${INCLUDE_DIR}/Departamento.h ${SRC_DIR}/Departamento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Departamento.cpp -o ${BUILD_DIR}/Departamento.o

${BUILD_DIR}/Horario.o: ${INCLUDE_DIR}/Horario.h ${SRC_DIR}/Horario.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Horario.cpp -o ${BUILD_DIR}/Horario.o

${BUILD_DIR}/JornadaTrabalho.o: ${INCLUDE_DIR}/JornadaTrabalho.h ${SRC_DIR}/JornadaTrabalho.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/JornadaTrabalho.cpp -o ${BUILD_DIR}/JornadaTrabalho.o

${BUILD_DIR}/Veiculo.o: ${INCLUDE_DIR}/Veiculo.h ${SRC_DIR}/Veiculo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Veiculo.cpp -o ${BUILD_DIR}/Veiculo.o

${BUILD_DIR}/Cargo.o: ${INCLUDE_DIR}/Cargo.h ${SRC_DIR}/Cargo.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Cargo.cpp -o ${BUILD_DIR}/Cargo.o

${BUILD_DIR}/Reajuste.o: ${INCLUDE_DIR}/Reajuste.h ${SRC_DIR}/Reajuste.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Reajuste.cpp -o ${BUILD_DIR}/Reajuste.o

${BUILD_DIR}/Cliente.o: ${INCLUDE_DIR}/Cliente.h ${SRC_DIR}/Cliente.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Cliente.cpp -o ${BUILD_DIR}/Cliente.o

${BUILD_DIR}/PessoaJuridica.o: ${INCLUDE_DIR}/PessoaJuridica.h ${SRC_DIR}/PessoaJuridica.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/PessoaJuridica.cpp -o ${BUILD_DIR}/PessoaJuridica.o

${BUILD_DIR}/PessoaFisica.o: ${INCLUDE_DIR}/PessoaFisica.h ${SRC_DIR}/PessoaFisica.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/PessoaFisica.cpp -o ${BUILD_DIR}/PessoaFisica.o

${BUILD_DIR}/Orcamento.o: ${INCLUDE_DIR}/Orcamento.h ${SRC_DIR}/Orcamento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Orcamento.cpp -o ${BUILD_DIR}/Orcamento.o

${BUILD_DIR}/PedidoCompra.o: ${INCLUDE_DIR}/PedidoCompra.h ${SRC_DIR}/PedidoCompra.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/PedidoCompra.cpp -o ${BUILD_DIR}/PedidoCompra.o

${BUILD_DIR}/Venda.o: ${INCLUDE_DIR}/Venda.h ${SRC_DIR}/Venda.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Venda.cpp -o ${BUILD_DIR}/Venda.o

${BUILD_DIR}/MetodoPagamento.o: ${INCLUDE_DIR}/MetodoPagamento.h ${SRC_DIR}/MetodoPagamento.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/MetodoPagamento.cpp -o ${BUILD_DIR}/MetodoPagamento.o

${BUILD_DIR}/Boleto.o: ${INCLUDE_DIR}/Boleto.h ${SRC_DIR}/Boleto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Boleto.cpp -o ${BUILD_DIR}/Boleto.o

${BUILD_DIR}/CartaoCredito.o: ${INCLUDE_DIR}/CartaoCredito.h ${SRC_DIR}/CartaoCredito.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/CartaoCredito.cpp -o ${BUILD_DIR}/CartaoCredito.o

${BUILD_DIR}/Estoque.o: ${INCLUDE_DIR}/Estoque.h ${SRC_DIR}/Estoque.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Estoque.cpp -o ${BUILD_DIR}/Estoque.o

${BUILD_DIR}/Categoria.o: ${INCLUDE_DIR}/Categoria.h ${SRC_DIR}/Categoria.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Categoria.cpp -o ${BUILD_DIR}/Categoria.o

${BUILD_DIR}/Produto.o: ${INCLUDE_DIR}/Produto.h ${SRC_DIR}/Produto.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Produto.cpp -o ${BUILD_DIR}/Produto.o

${BUILD_DIR}/Lote.o: ${INCLUDE_DIR}/Lote.h ${SRC_DIR}/Lote.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Lote.cpp -o ${BUILD_DIR}/Lote.o

${BUILD_DIR}/Preco.o: ${INCLUDE_DIR}/Preco.h ${SRC_DIR}/Preco.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Preco.cpp -o ${BUILD_DIR}/Preco.o

${BUILD_DIR}/OrdemProducao.o: ${INCLUDE_DIR}/OrdemProducao.h ${SRC_DIR}/OrdemProducao.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/OrdemProducao.cpp -o ${BUILD_DIR}/OrdemProducao.o

${BUILD_DIR}/MateriaPrima.o: ${INCLUDE_DIR}/MateriaPrima.h ${SRC_DIR}/MateriaPrima.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/MateriaPrima.cpp -o ${BUILD_DIR}/MateriaPrima.o

${BUILD_DIR}/OrdemCompra.o: ${INCLUDE_DIR}/OrdemCompra.h ${SRC_DIR}/OrdemCompra.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/OrdemCompra.cpp -o ${BUILD_DIR}/OrdemCompra.o

${BUILD_DIR}/OrcamentoMateriaPrima.o: ${INCLUDE_DIR}/OrcamentoMateriaPrima.h ${SRC_DIR}/OrcamentoMateriaPrima.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/OrcamentoMateriaPrima.cpp -o ${BUILD_DIR}/OrcamentoMateriaPrima.o

${BUILD_DIR}/Fornecedor.o: ${INCLUDE_DIR}/Fornecedor.h ${SRC_DIR}/Fornecedor.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Fornecedor.cpp -o ${BUILD_DIR}/Fornecedor.o

${BUILD_DIR}/Empresa.o: ${INCLUDE_DIR}/Empresa.h ${SRC_DIR}/Empresa.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/Empresa.cpp -o ${BUILD_DIR}/Empresa.o

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it
clean:
	rm -f ${BUILD_DIR}/*