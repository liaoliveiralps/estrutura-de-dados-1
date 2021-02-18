#ifndef ORDENAR_H
#define ORDENAR_H
#include <QString>
#include <pilha.h>
namespace lia
{
class Ordenar
{
private:
    int tamanho;
    int *array;
public:
    Ordenar(int tamanho);
    ~Ordenar(){if(array)delete[]array;}
    QString arrumar();
    QString vetorDesordenado()const;
};
}
#endif // ORDENAR_H
