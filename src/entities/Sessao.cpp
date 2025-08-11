#include "Sessao.h"
#include <iostream>
#include "Data.h"
#include "LogEscrita.h"
#include "LogLeitura.h"
#include "LogAcessoNegado.h"
#include "Logs.h"



using namespace std;

Sessao* Sessao::instancePtr = nullptr;
Usuario* Sessao::usuario_ = nullptr;

Sessao::Sessao(){}

Sessao* Sessao::getInstance() {
   if (instancePtr == nullptr) {
      instancePtr = new Sessao();
   }
   return instancePtr;
}

void Sessao::logout(){
    if(usuario_ != nullptr){
        usuario_ = nullptr;
    }
}

void Sessao::login(Usuario* usuario){
  if(usuario == nullptr)
  {
    char message[100] = "Erro de Autenticacao";
    throw ErroAutenticacao(message);
  }
  else if(usuario_ != nullptr){
    char message[100] = "Ja existe um usuario logado";
    throw ErroAutenticacao(message);
  }
  if(usuario_ == nullptr){
        usuario_ = usuario;
    }
}

Usuario* Sessao::getSessao(){
  return usuario_;
}

Sessao::~Sessao(){
  delete instancePtr;
}