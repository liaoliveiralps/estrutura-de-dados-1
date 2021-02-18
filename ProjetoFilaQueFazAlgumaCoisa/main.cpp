#include <QCoreApplication>
#include <fila.h>
#include <iostream>
int main()
{
    try {
        lia::Fila filaTeste(4);
        QString saida;
        filaTeste.setTamanho(4);
        //imprime o tamanho
        std::cout << "Tamanho: "<< filaTeste.getTamanho() << " \n";
        //imprime se esta vazia ou cheia
        std::cout << "Fila Vazia: ";
        if(filaTeste.estaVazia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "Fila Cheia: ";
        if(filaTeste.estaCheia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "*****************************************************"<<"\n";
        //insere elemento na fila
        filaTeste.inserir(10);
        filaTeste.inserir(20);
        filaTeste.inserir(30);
        filaTeste.inserir(40);

        //imprime o tamanho
        std::cout << "Tamanho: "<< filaTeste.getTamanho() << " \n";
        //imprime se esta vazia ou cheia
        std::cout << "Fila Vazia: ";
        if(filaTeste.estaVazia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "Fila Cheia: ";
        if(filaTeste.estaCheia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "*****************************************************"<<"\n";

        //insere mais 5 elementos
        //filaTeste.inserir(50);
        //filaTeste.inserir(60);
        //filaTeste.inserir(70);
        //filaTeste.inserir(80);
        //filaTeste.inserir(90);

        //imprime todos os elementos da fila
        while(!filaTeste.estaVazia()){
                    std::cout << "\nElemento: " << filaTeste.consultar();
                    filaTeste.retirar();
                }

        //imprime o tamanho
        std::cout << "\nTamanho: "<< filaTeste.getTamanho() << " \n";
        //imprime se esta vazia ou cheia
        std::cout << "Fila Vazia: ";
        if(filaTeste.estaVazia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "Fila Cheia: ";
        if(filaTeste.estaCheia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "*****************************************************"<<"\n";

        filaTeste.inserir(50);
        filaTeste.inserir(60);
        filaTeste.inserir(70);
        filaTeste.inserir(80);
        std::cout << "\nTamanho: "<< filaTeste.getTamanho() << " \n";
        //imprime se esta vazia ou cheia
        std::cout << "Fila Vazia: ";
        if(filaTeste.estaVazia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "Fila Cheia: ";
        if(filaTeste.estaCheia())
            std::cout << "Sim\n";
        else
            std::cout << "Nao\n";
        std::cout << "*****************************************************"<<"\n";

        for(int i=0; i<3; i++)
            filaTeste.retirar();
    } catch(QString &erro){
        std::cout<<erro.toStdString();
    }

}
