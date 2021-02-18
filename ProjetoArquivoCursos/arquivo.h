#ifndef GERENCIARARQUIVO_H
#define GERENCIARARQUIVO_H
#include <QString>
#include <fstream>
#include <string>
class dadosArquivo
{
private:
    std::ifstream arquivo;
    QString nomeArquivo;
    int tamanhoArquivo;
public:
    dadosArquivo();
    dadosArquivo(QString nomeArquivo);
    QString getNomeArquivo() const { return this->nomeArquivo; }
    int getTamanhoArquivo() const { return this->tamanhoArquivo; }
    void setNomeArquivo(QString nomeArquivo);
    QString getNomeAluno(int posicaoLinha) const;
    int getCurso(int posicaoLinha) const;


};

#endif // GERENCIARARQUIVO_H
