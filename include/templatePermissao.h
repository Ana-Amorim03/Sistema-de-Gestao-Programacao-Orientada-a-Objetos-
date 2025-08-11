#include <iostream>
#include "Usuario.h"
#include "Logs.h"

Usuario *loggedUser = Sessao::getInstance()->getSessao();
Logs *logs = Logs::getInstance();
string entidade = "TemplatePermissao";
Data data;
void nada(){



  string nomedafuncao = "nomedafuncao";	 
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  if (loggedUser->ehPermitido(nomedafuncao)){
    string info_acessada = nomedafuncao;
    Log *logleitura = new LogLeitura(info_acessada, data, loggedUser->getLogin(), entidade);
    logs->addLog(logleitura);
    //___________________________________
    
    //___________________________________
  }else{
    Data data;
    data = data.dateNow();
    string func_negada = nomedafuncao;
    Log *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
  
  
  
  string nomedafuncao = "nomedafuncao";
  Usuario *loggedUser = Sessao::getInstance()->getSessao();
  if (loggedUser->ehPermitido(nomedafuncao)){
    string info_antes = "info antes";
    string info_depois = "info depois";
    Log *logescrita = new LogEscrita(info_antes, info_depois, data, loggedUser->getLogin(), entidade);
    logs->addLog(logescrita);
    //___________________________________
    
    //___________________________________
  }else{
    Data data;
    data = data.dateNow();
    string func_negada = nomedafuncao;
    Log *lognegado = new LogAcessoNegado(func_negada, data, loggedUser->getLogin(), entidade);
   logs->addLog(lognegado);
        throw ExecaoAcessoNegado((char*)"Acesso Negado");
  }
}



