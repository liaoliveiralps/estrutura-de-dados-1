#ifndef MUDARBASE_H
#define MUDARBASE_H
#include <QString>
namespace ED1{
class MudarBase
{
private:
    int numero;
    int base;
public:
    MudarBase();
    int getNumero(){return numero;}
    void setNumero(int numero){this->numero = numero;}
    int getBase(){return base;}
    void setBase(int base){this->base = base;}
    void divisao(int numero, int base);
};
}
#endif // MUDARBASE_H
