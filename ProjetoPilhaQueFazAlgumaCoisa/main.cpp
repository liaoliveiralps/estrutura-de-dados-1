#include <QCoreApplication>
#include <pilha.h>
#include <iostream>
int main()
{
    try {
            //cria a pilha de tamanho
            ED1::Pilha pilhaTeste(4);
            QString saida;
            //imprime o tamanho
            std::cout << "Tamanho: "<< pilhaTeste.quantidade() << " \n";
            //imprime se esta vazia ou cheia
            std::cout << "Pilha Vazia: ";
            if(pilhaTeste.estaVazio())
                std::cout << "Sim\n";
            else
                std::cout << "Nao\n";
            std::cout << "Pilha Cheia: ";
            if(pilhaTeste.estaCheio())
                std::cout << "Sim\n";
            else
                std::cout << "Nao\n";
            std::cout << "*****************************************************";
            //insere elemento na pilha
            pilhaTeste.inserir(10);
            pilhaTeste.inserir(20);
            pilhaTeste.inserir(30);
            pilhaTeste.inserir(40);
            //pilhaTeste.inserir(99);

            std::cout << "*****************************************************";
            //imprime o tamanho
            std::cout << "\nTamanho: "<< pilhaTeste.quantidade() << " \n";
            //imprime se esta vazia ou cheia
            std::cout << "Pilha Vazia: ";
            if(pilhaTeste.estaVazio())
                std::cout << "Sim\n";
            else
                std::cout << "Nao\n";
            std::cout << "Pilha Cheia: ";
            if(pilhaTeste.estaCheio())
                std::cout << "Sim\n";
            else
                std::cout << "Não\n";

            std::cout << "*****************************************************";
            //pilhaTeste.inserir(50);
            //pilhaTeste.inserir(60);
            //pilhaTeste.inserir(70);
            //pilhaTeste.inserir(80);
           // pilhaTeste.inserir(90);

            std::cout << "*****************************************************";

            //imprime todos os elementos da pilha
            while(!pilhaTeste.estaVazio()){
                        std::cout << "\nElemento: " << pilhaTeste.consultar();
                        pilhaTeste.retirar();
                    }

            std::cout << "\n" << "*****************************************************";
            //imprime o tamanho
            std::cout << "\nTamanho: "<< pilhaTeste.quantidade() << " \n";
            //imprime se esta vazia ou cheia
            std::cout << "Pilha Vazia: ";
            if(pilhaTeste.estaVazio())
                std::cout << "Sim\n";
            else
                std::cout << "Não\n";
            std::cout << "Pilha Cheia: ";
            if(pilhaTeste.estaCheio())
                std::cout << "Sim\n";
            else
                std::cout << "Nao\n";

            std::cout << "*****************************************************";
            //insere elementos na pilha
            pilhaTeste.inserir(100);
            pilhaTeste.inserir(200);
            pilhaTeste.inserir(300);
            pilhaTeste.inserir(400);

            std::cout << "*****************************************************";
            //imprime o tamanho
            std::cout << "\nTamanho: "<< pilhaTeste.quantidade() << " \n";
            //imprime se esta vazia ou cheia
            std::cout << "Pilha Vazia: ";
            if(pilhaTeste.estaVazio())
                std::cout << "Sim\n";
            else
                std::cout << "Nao\n";
            std::cout << "Pilha Cheia: ";
            if(pilhaTeste.estaCheio())
                std::cout << "Sim\n";
            else
                std::cout << "Nao\n";

            std::cout << "*****************************************************";
           //retira elementos da pilha
            pilhaTeste.retirar();
            pilhaTeste.retirar();
            pilhaTeste.retirar();


        } catch(QString &erro){
            std::cout<<erro.toStdString();
        }

}
