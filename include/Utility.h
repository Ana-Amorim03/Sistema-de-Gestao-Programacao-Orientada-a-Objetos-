#ifndef UTILITY_H
#define UTILITY_H

#include <string>
using namespace std;

#include "ExecaoCustomizada.h"

class CPFinvalido : public ExecaoCustomizada {
public:
  CPFinvalido(char *e) : ExecaoCustomizada(e) {}
};

class CNPJinvalido : public ExecaoCustomizada {
public:
  CNPJinvalido(char *e) : ExecaoCustomizada(e) {}
};

class Utility {
public:
  static bool validaCPF(string &cpf);
  static bool validaCNPJ(string &cnpj);
  static unsigned int randomCode(int min, int max);
  static unsigned int geraCodigo();
  static float randomPrice(float min, float max);
};

#endif // UTILITY_H
