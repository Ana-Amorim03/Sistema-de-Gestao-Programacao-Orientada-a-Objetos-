#include "Usuario.h"
#include <string>

using namespace std;

#ifndef SESSAO_H
#define SESSAO_H


class ErroAutenticacao : public ExecaoCustomizada {
public:
 ErroAutenticacao(char *e) : ExecaoCustomizada(e) {}
};
class SessaoIndisponivel : public ExecaoCustomizada {
public:
 SessaoIndisponivel(char *e) : ExecaoCustomizada(e) {}
};

class Sessao {
public:
   static void login(Usuario* usuario);
   static Sessao* getInstance();
   static void logout();
   static Usuario* getSessao();
private:
   static Usuario* usuario_;
   static Sessao* instancePtr;  // The one, single instance
   Sessao(); // private constructor
   ~Sessao();
};

#endif //SESSAO_H