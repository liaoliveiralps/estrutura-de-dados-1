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
    int getNumero()const{return numero;}
    void setNumero(int numero){this->numero = numero;}
    int getBase()const{return base;}
    void setBase(int base){this->base = base;}
    QString divisao();
};
}
#endif // MUDARBASE_H
