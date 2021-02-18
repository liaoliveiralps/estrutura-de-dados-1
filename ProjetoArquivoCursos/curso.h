#ifndef CURSO_H
#define CURSO_H
#include"llde.h"
#include"aluno.h"
namespace lula {
enum codigo { engenhariaDaComputacao = 33, cienciaDaComputacao = 28, pedagogia = 13, administracao = 18};
class Curso
{
protected:
    codigo curso;
public:
    Curso();
    Curso(codigo disciplina);
    lula::LLDE<Aluno&> alunos;
    codigo getCursoAtual() {return curso;}
    void setCursoAtual(codigo cursoAtual) {this->curso  = cursoAtual;}
    bool operator==(Curso & curso)const{return this->curso == curso.curso;}
};

}

#endif // CURSO_H
