#include "Utility.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <random>
using namespace std;

const std::string whiteSpaces(" \f\n\r\t\v");

int rand_code  = 0;

unsigned int Utility::geraCodigo(){
  int codigo = (100 + rand_code);
  rand_code++;

  return codigo;
}

unsigned int Utility::randomCode(int min, int max)
{
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max); // distribution in range
  unsigned int aux = dist6(rng);

  return aux;
}

float Utility::randomPrice(float min, float max) {
  std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dist(min, max);

  return dist(gen);
}

void trimRight(std::string &str, const std::string &trimChars = whiteSpaces) {
  std::string::size_type pos = str.find_last_not_of(trimChars);
  str.erase(pos + 1);
}

void trimLeft(std::string &str, const std::string &trimChars = whiteSpaces) {
  std::string::size_type pos = str.find_first_not_of(trimChars);
  str.erase(0, pos);
}

void trim(std::string &str, const std::string &trimChars = whiteSpaces) {
  trimRight(str, trimChars);
  trimLeft(str, trimChars);
}

static bool endsWith(const std::string &str, const std::string &suffix) {
  return str.size() >= suffix.size() &&
         0 == str.compare(str.size() - suffix.size(), suffix.size(), suffix);
}

bool Utility::validaCNPJ(string &cnpj) {
  int *multiplicador1 = new int[12]{5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
  int *multiplicador2 = new int[13]{6, 5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};

  int somador;
  int resto;
  string digito;
  string cnpjAux;
  // troca ".", ",", "/" e "-" por ""
  cnpj.erase(remove(cnpj.begin(), cnpj.end(), '.'), cnpj.end());
  cnpj.erase(remove(cnpj.begin(), cnpj.end(), '/'), cnpj.end());
  cnpj.erase(remove(cnpj.begin(), cnpj.end(), ','), cnpj.end());
  cnpj.erase(remove(cnpj.begin(), cnpj.end(), '-'), cnpj.end());
  trim(cnpj); // tira espaços em branco do final e do inicio
  if (cnpj.size() != 14) {

    return false;
  } else {
    cnpjAux = cnpj.substr(0, 12);
    somador = 0;


    for (int i = 0; i < 12; i++) {
      stringstream strValue;
      strValue << cnpjAux[i];

      unsigned int intValue;
      strValue >> intValue;
      somador += intValue * multiplicador1[i];
    }

    resto = (somador % 11);

    if (resto < 2) {
      resto = 0;
    } else {
      resto = 11 - resto;
    }

    digito = to_string(resto); // 1º digito armazenado.

    cnpjAux = cnpjAux + digito; // agora com 13 números.

    somador = 0; // zera somador

    for (int i = 0; i < 13; i++) {
      stringstream strValue;
      strValue << cnpjAux[i];

      unsigned int intValue;
      strValue >> intValue;
      somador += intValue * multiplicador2[i];
    }

    resto = (somador % 11);

    if (resto < 2) {
      resto = 0;
    } else {
      resto = 11 - resto;
    }

    digito =
        digito +
        to_string(resto); // Concatenação do 1º dígito com o 2º dígito. ex: "00"

    delete[] multiplicador1;
    delete[] multiplicador2;

    return endsWith(cnpj,
                    digito); // se for igual retorna true, senão retorna false.
  }
}

bool Utility::validaCPF(string &input_cpf){   
    // https://www.vivaolinux.com.br/script/Validar-CPF-em-C-esse-funciona
    input_cpf.erase(remove(input_cpf.begin(), input_cpf.end(), '.'), input_cpf.end());
    input_cpf.erase(remove(input_cpf.begin(), input_cpf.end(), '/'), input_cpf.end());
    input_cpf.erase(remove(input_cpf.begin(), input_cpf.end(), ','), input_cpf.end());
    input_cpf.erase(remove(input_cpf.begin(), input_cpf.end(), '-'), input_cpf.end());
    trim(input_cpf);
    const char* input = input_cpf.c_str();
    int cpf[11];
    for(unsigned char i = 0; i < 11; i++){
        cpf[i] = static_cast<int>(input[i] - 48);
    }
    
    int digito1,
        digito2,
        temp = 0;

    /*Obtendo o primeiro digito verificador:

    Os 9 primeiros algarismos são multiplicados pela sequência 10, 9, 8, 7, 6, 5, 4, 3, 2
    (o primeiro por 10, o segundo por 9, e assim por diante);
    Em seguida, calcula-se o resto “r1″ da divisão da soma dos resultados das multiplicações por 11,
    e se o resto for zero ou 1, digito é zero, caso contrário digito = (11-r1) */
    
    for(unsigned char i = 0; i < 9; i++)
        temp += (cpf[i] * (10 - i));

    temp %= 11;

    if(temp < 2)
        digito1 = 0;
    else
        digito1 = 11 - temp;

    /*Obtendo o segundo digito verificador:

    O dígito2 é calculado pela mesma regra, porém inclui-se o primeiro digito verificador ao final
    da sequencia. Os 10 primeiros algarismos são multiplicados pela sequencia 11, 10, 9, ... etc...
    (o primeiro por 11, o segundo por 10, e assim por diante);
    procedendo da mesma maneira do primeiro digito*/

    temp = 0;
    for(unsigned char i = 0; i < 10; i++)
        temp += (cpf[i] * (11 - i));

    temp %= 11;

    if(temp < 2)
        digito2 = 0;
    else
        digito2 = 11 - temp;

    /* Se os digitos verificadores obtidos forem iguais aos informados pelo usuário,
       então o CPF é válido */

    if(digito1 == cpf[9] && digito2 == cpf[10])
        return true;
    else
        return false;
}
