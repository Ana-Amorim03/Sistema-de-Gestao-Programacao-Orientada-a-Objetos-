#ifndef JORNADATRBALHO_H
#define JORNADATRBALHO_H
#include <string>
#include "Horario.h"


using namespace std;

class JornadaTrabalho{
  
public:
  JornadaTrabalho(string turno, Horario inicio, Horario fim);
  string getTurno();
  void setInicio(Horario inicio);
  Horario getInicio();
  void setFim(Horario fim);
  Horario getFim();
  Horario cargaHoraria();
  void printJornada();

private:
  
  string turno_;
  Horario inicio_;
  Horario fim_;
};
#endif // JORNADATRBALHO