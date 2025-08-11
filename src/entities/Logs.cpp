#include "Logs.h"

#include <fstream>

Logs* Logs::instancePtr_ = nullptr;

Logs* Logs::getInstance() {
    
    if (instancePtr_ == nullptr) {

        instancePtr_ = new Logs;
    }
    return instancePtr_;
}

void Logs::addLog(Log* log) { logs_.push_back(log); }

void Logs::gerarTxtLogs() const {

    ofstream fout("Logs.txt");

    for (unsigned it = 0; it < logs_.size(); it++){
        fout << logs_[it]->getDados() << endl;
    }
}

Logs::~Logs() {
    for (unsigned it = 0; it < logs_.size(); it++){
        delete logs_[it];
    }
    delete instancePtr_;
}
