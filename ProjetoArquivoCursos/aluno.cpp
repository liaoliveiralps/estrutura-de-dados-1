#include "aluno.h"
namespace lula{
Aluno::Aluno()
    :nome("")
    ,curso(0)
{

}
Aluno::Aluno(QString nome, int curso)
    :nome(nome)
    ,curso(0)
{
    if(curso<0) throw QString ("Código inválido");
    this->curso =curso;
}
}
