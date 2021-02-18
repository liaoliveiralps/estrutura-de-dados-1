#ifndef PESSOA_H
#define PESSOA_H
#include <string>

class Pessoa
{
private:
    std::string nome;
    std::string telefone;
public:
    Pessoa();
    std::string getNome()const{return nome;}
    void setNome(const std::string nome){this->nome=nome;}
    std::string getTelefone()const;
    void setTelefone(const std::string telefone);
};

#endif // PESSOA_H
