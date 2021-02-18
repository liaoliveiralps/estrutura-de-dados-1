#ifndef LLSE_H
#define LLSE_H
#include <no.h>
#include <QString>
namespace lia{
class LLSE
{
private:
    No* pInicio; //ponteiro
    No* pFim;
    int quantidade;
public:
    LLSE();
    ~LLSE();
    int getQuantidade()const{return quantidade;}
    bool estaVazio()const{return(quantidade==0);}
    void inserirInicio(int elemento);
    int retirarInicio();
};
}
#endif // LLSE_H
