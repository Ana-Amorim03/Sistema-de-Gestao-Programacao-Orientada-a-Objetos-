#include "JornadaTrabalho.h"
#include "Funcionario.h"
#include "Horario.h"
#include <list>


#ifndef VEICULO_H
#define VEICULO_H

using namespace std;

class Veiculo{

public:
  Veiculo(string placa, int capacidade, JornadaTrabalho* turno, Endereco* local_saida);
  string getPlaca();
  int getCapacidade();
  void addPassageiro(Funcionario* funcionario);
  list<Funcionario*> getRota();
  void removePassageiro(Funcionario* funcionario);
  void printRota();
  void setTurnoVeiculo(JornadaTrabalho* turno);
  JornadaTrabalho* getTurnoVeiculo();
  void setLocalSaida(Endereco* local_saida);
  Endereco* getLocalSaida();
  float getDistanciaTotal();
  Horario getTempoPercurso();
  Horario getHorarioSaida();
  void printDados();
  void printHorarioEmbarque();
  float calculaDistancia(pair<float, float> a,pair<float, float> b);
  void setHorariosEmbarque();
  ~Veiculo();
private:
  string placa_;
  int capacidade_;
  JornadaTrabalho* turno_;
  list<Funcionario*> rota_;
  float distancia_total_;
  Horario tempo_percurso_;
  Horario horario_saida_;
  Endereco* local_saida_;

};
#endif //VEICULO_H