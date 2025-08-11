#include "LogEscrita.h"

LogEscrita::LogEscrita( const string &info_alt_ant, const string &info_alt_dps, const Data &data, const string &usuario, const string &entidade):
Log(data, usuario, entidade), info_alt_ant_(info_alt_ant), info_alt_dps_(info_alt_dps) {}

string LogEscrita::getDados() const {

    string aux;

    aux = "Data: " + this->getData().getData() + "\n";
    aux += "Usuario: " + this->getUsuario() + "\n";
    aux += "Entidade: " + this->getEntidade() + "\n";
    aux += "Info Alterada, antes: " + info_alt_ant_ + "\n";
    aux += "Info Alterada, depois: " + info_alt_dps_ + "\n";

    return aux;
}
