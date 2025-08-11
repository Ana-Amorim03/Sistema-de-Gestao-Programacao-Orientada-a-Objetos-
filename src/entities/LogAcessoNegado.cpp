#include "LogAcessoNegado.h"

LogAcessoNegado::LogAcessoNegado(const string &info_restringida, const Data &data, const string &usuario, const string &entidade):
Log(data, usuario, entidade), info_restringida_(info_restringida) {}

string LogAcessoNegado::getDados() const {

    string aux;

    aux = "Data: " + this->getData().getData() + "\n";
    aux += "Usuario: " + this->getUsuario() + "\n";
    aux += "Entidade: " + this->getEntidade() + "\n";
    aux += "Info Restringida: " + info_restringida_ + "\n";

    return aux;
}
