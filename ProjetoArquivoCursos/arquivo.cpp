#include "arquivo.h"

dadosArquivo::dadosArquivo()
    : nomeArquivo("")
    , tamanhoArquivo(0)
{

}
dadosArquivo::dadosArquivo(QString nomeArquivo){
    if (nomeArquivo.isEmpty()) throw QString ("Arquivo não pode ser aberto");
    this->nomeArquivo = nomeArquivo;
    std::ifstream arquivo(nomeArquivo.toStdString().c_str());
    std::string linha;
    int cont = 0;
    while (!arquivo.fail()){
        std::getline(arquivo, linha);
        cont++;
    }
    cont = cont -1;
    arquivo.close();
    tamanhoArquivo = cont;
}
QString dadosArquivo::getNomeAluno(int posicaoLinha) const{
    if(posicaoLinha > tamanhoArquivo) throw QString ("Posicao inválida");
    std::ifstream arquivo(nomeArquivo.toStdString().c_str());
    std::string nome("");
    std::string linha("");
    int cont = 0;
    std::getline(arquivo, linha);
    for (int i = 0; i < posicaoLinha; i++)
        std::getline(arquivo, linha);
    while (linha[cont] != ';'){
        nome += linha[cont];
        cont++;
    }
    arquivo.close();
    return QString::fromStdString(nome);
}
int dadosArquivo::getCurso(int posicaoLinha) const{
    if(posicaoLinha > tamanhoArquivo) throw QString ("Posicao inválida");
    std::ifstream arquivo(nomeArquivo.toStdString().c_str());
    std::string curso("");
    std::string linha("");
    int cont = 0;
    std::getline(arquivo, linha);
    for (int i = 0; i < posicaoLinha; i++)
        std::getline(arquivo, linha);
    while (linha[cont] != ';')
        cont++;
    cont++;
    while (linha[cont] != *linha.end()){
        curso += linha[cont];
        cont++;
    }
    arquivo.close();
    return QString::fromStdString(curso).toInt();
}
void dadosArquivo::setNomeArquivo(QString nomeArquivo){
    if (nomeArquivo.isEmpty()) throw QString("Arquivo não selecionado");
    this->nomeArquivo = nomeArquivo;
    std::ifstream arquivo(nomeArquivo.toStdString().c_str());
    std::string linha;
    int cont = 0;
    while (!arquivo.fail()){
        std::getline(arquivo, linha);
        cont++;
    }
    cont = cont -1;
    tamanhoArquivo = cont;
    arquivo.close();
}
