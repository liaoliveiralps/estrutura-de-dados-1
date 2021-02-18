#ifndef FILA_H
#define FILA_H
#include <QString>
namespace lia{
class Fila
{
private:
    int tamanho;
    int *array;
    int fim;
    int inicio;
    int quantidade;
public:
    Fila();
    Fila(int tamanho);
    ~Fila(){if(array) delete[] array;}
    void inserir(int elemento);
    bool estaCheia()const;
    bool estaVazia()const;
    int retirar();
    int consultar()const;
};
}
#endif // FILA_H
