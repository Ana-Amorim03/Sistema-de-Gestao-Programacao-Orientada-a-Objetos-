#ifndef LOGS_H
#define LOGS_H

#include <vector>

#include "LogAcessoNegado.h"
#include "LogEscrita.h"
#include "LogLeitura.h"

class Logs {
    public:
        static Logs* getInstance();
        void addLog(Log* log);
        void gerarTxtLogs() const;
    private:
        Logs() {}
        ~Logs();
        static Logs* instancePtr_;
        vector<Log*> logs_;
};

#endif // LOGS_H
