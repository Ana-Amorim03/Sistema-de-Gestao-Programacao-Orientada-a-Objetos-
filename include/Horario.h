#ifndef HORARIO_H
#define HORARIO_H
#include <string>
#include "Data.h"
using namespace std;

class HoraInvalida : public ExecaoCustomizada {
public:
  HoraInvalida(char *e) : ExecaoCustomizada(e) {}
};

class Horario{
  
public:
  Horario();
  Horario(float horas);
  Horario(int hora, int minuto, int segundo);
  int getHora();
  int getMinuto();
  int getSegundo();
  Horario operator+(Horario horario);
  Horario operator-(Horario horario);
  float paraHoras();
  void printHorario();

private:
  
  int hora_; 
  int minuto_;
  int segundo_;

};
#endif // HORARIO