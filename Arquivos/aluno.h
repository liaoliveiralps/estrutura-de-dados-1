#ifndef ALUNO_H
#define ALUNO_H
#include<QString>
#include<separar.h>

class Aluno
{
private:
    QString nome;

public:
    enum cursos{EngenhariaDaComputação= 33,
                CienciaDaComputação= 28,
                Pedagogia= 13,
                Administração= 18};
    Aluno();
    ~Aluno();
    QString Escolha(QString cod);
};

#endif // ALUNO_H
