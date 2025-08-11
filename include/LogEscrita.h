#ifndef LOG_ESCRITA_H
#define LOG_ESCRITA_H

#include "Log.h"

class LogEscrita : public Log {
    public:
        LogEscrita( const string &info_alt_ant, const string &info_alt_dps, const Data &data, const string &usuario, const string &entidade);
        string getDados() const override;
        ~LogEscrita() {}
    private:
        string info_alt_ant_;
        string info_alt_dps_;
};

#endif // LOG_ESCRITA_H
