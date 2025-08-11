#include "Log.h"

Log::Log(const Data &data, const string &usuario, const string &entidade):
data_(data), usuario_(usuario), entidade_(entidade) {}

Data Log::getData() const { return data_; }

string Log::getUsuario() const { return usuario_; }

string Log::getEntidade() const { return entidade_; }
