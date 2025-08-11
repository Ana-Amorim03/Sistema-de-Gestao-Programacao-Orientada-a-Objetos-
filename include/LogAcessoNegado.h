#ifndef LOG_ACESSO_NEGADO_H
#define LOG_ACESSO_NEGADO_H

#include "Log.h"

class ExecaoAcessoNegado : public ExecaoCustomizada {
    public:
        ExecaoAcessoNegado(char *e) : ExecaoCustomizada(e) {}
};

class LogAcessoNegado : public Log {
    public:
        LogAcessoNegado(const string &info_restringida, const Data &data, const string &usuario, const string &entidade);
        string getDados() const override;
        ~LogAcessoNegado() {}
    private:
        string info_restringida_;
};

#endif // LOG_ACESSO_NEGADO_H
