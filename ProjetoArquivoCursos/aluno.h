#ifndef ALUNO_H
#define ALUNO_H
#include<QString>
#include<string>
namespace lula {
class Aluno
{
private:
    QString nome;
    int curso;
public:
    Aluno();
    Aluno(QString nome, int curso);
    QString getNome() {return this->nome;}
    int getCurso() {return this->curso;}
    void setNome(QString nome) {this->nome = nome;}
    void setCurso(int curso) {this->curso = curso;}
    bool operator<=(Aluno & aluno) const {return (this->nome <= aluno.getNome());}
};

}
#endif // ALUNO_H
