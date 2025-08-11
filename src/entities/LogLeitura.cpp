#include "LogLeitura.h"

LogLeitura::LogLeitura(const string &info_acessada, const Data &data, const string &usuario, const string &entidade):
Log(data, usuario, entidade), info_acessada_(info_acessada) {}

string LogLeitura::getDados() const {

    string aux;

    aux = "Data: " + this->getData().getData() + "\n";
    aux += "Usuario: " + this->getUsuario() + "\n";
    aux += "Entidade: " + this->getEntidade() + "\n";
    aux += "Info Acessada: " + info_acessada_ + "\n";

    return aux;
}
