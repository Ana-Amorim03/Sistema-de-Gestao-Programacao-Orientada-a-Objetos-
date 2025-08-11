#ifndef LOG_H
#define LOG_H

#include <string>
using namespace std;

#include "Data.h"

class Log {
    public:
        virtual string getDados() const { return ""; }
        Data getData() const;
        string getUsuario() const;
        string getEntidade() const;
        virtual ~Log() {}
    protected:
        Log(const Data &data, const string &usuario, const string &entidade);
    private:
        Data data_;
        string usuario_;
        string entidade_;
};

#endif // LOG_H
