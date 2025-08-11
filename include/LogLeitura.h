#ifndef LOG_LEITURA_H
#define LOG_LEITURA_H

#include "Log.h"

class LogLeitura : public Log {
    public:
        LogLeitura(const string &info_acessada, const Data &data, const string &usuario, const string &entidade);
        string getDados() const override;
        ~LogLeitura() {}
    private:
        string info_acessada_;
};

#endif // LOG_LEITURA_H
