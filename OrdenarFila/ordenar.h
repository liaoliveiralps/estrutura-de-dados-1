#ifndef ORDENAR_H
#define ORDENAR_H
#include <QString>
#include <fila.h>
namespace lia {
class Ordenar
{
private:
    int *vetor;
    int tamanho;
public:
    Ordenar(int tamanho);
    ~Ordenar(){if(vetor) delete [] vetor;}
    void arrumarVetor();
    QString getVetor();
};
}

#endif // ORDENAR_H
