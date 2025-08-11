#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <string>
#include "Formato.h"
#include "ExecaoCustomizada.h"

// Constantes de Conversao
#define YEAR_TO_SECONDS 31536000
#define DAY_TO_SECONDS 86400
#define HOURS_TO_SECONDS 3600
#define MINUTE_TO_SECONDS 60

using namespace std;

class Data
{
private:
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    int fracao_segundo;
    long ticks;    // Segundos desde 00:00:00 01/01/1970
    Formato formatoData;

    void ticksToDate();
    void dateToTicks();

public:
    Data();                      // Construtor default(PT-BR)
    Data(Formato valFormato);    // Construtor default de formato de data especifico
    Data(int valAno, int valMes, int valDia, int valHora = 0, int valMin = 0, int valSeg = 0);    // Construtor com argumentos e formato default
    Data(long valTicks);                      // Construtor a partir de ticks
    virtual ~Data();                          // Destrutor
    bool operator==(const Data &d2) const;    // Sobrecarga do operador de comparacao equal
    bool operator<(const Data &d2) const;     // Sobrecarga do operador de comparacao less than
    bool operator>(const Data &d2) const;     // Sobrecarga do operator de comparacao greater than
    Data operator-(const Data &d2) const;     // Sobrecarga do operador de subtracao

    // Metodos get:
    int getAno() const;
    int getMes() const;
    int getDia() const;
    int getHora() const;
    int getMin() const;
    int getSeg() const;
    long getTicks() const;
    string getFormato() const;
    int getFracaoSegundo();
    
    // Metodos set:
    void setAno(int valAno);
    void setMes(int valMes);
    void setDia(int valDia);
    void setHora(int valHora);
    void setMin(int valMin);
    void setSeg(int valSeg);
    void setTicks(long valTicks);
    void setFormato(Formato valFormato);
    void setFracaoSegundo(int fracao);

    bool validaData() const;     //Verifica se todos os valores dos atributos estao dentro dos limites possiveis
    static Data dateNow();       //Retorna a data do presente momento
    void printData() const;      //Imprime a data na tela de acordo com o formato ja atribuido
    string getData() const;      //Retorna a data no formato de string
    int diffData(Data) const;    // Retorna a diferença entre duas datas em dias
};

#endif // DATA_H_INCLUDED