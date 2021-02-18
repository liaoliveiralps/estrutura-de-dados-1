#include "curso.h"
namespace lula {
Curso::Curso()
{

}
Curso::Curso(codigo curso)
{
    if (curso != engenhariaDaComputacao and curso != cienciaDaComputacao and
        curso != pedagogia and curso != administracao)
    {
        throw QString ("Curso não cadastrado!");
    }
    this->curso=curso;
}
}
