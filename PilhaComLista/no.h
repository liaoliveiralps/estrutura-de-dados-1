#ifndef NO_H
#define NO_H
namespace lia{
class No
{
private:
    int informacao;
    No *elo;
public:
    No();
    No(int elemento);
    int getInformacao()const{return informacao;}
    void setInformacao(int info){informacao = info;}
    No* getElo()const{return elo;}
    No* setElo(No* elo){this->elo = elo;}

};
}
#endif // NO_H
