/*
 * EDUBOT Exemplo 1
 * @Author: Carlos Eduardo
 * Esse exemplo demonstra as funcoes de movimentacao do robo:
 * move(double velocity) -> movimento linear
 * stop() -> freia os motores
 * rotate(double angle) -> movimento rotacional
 * neutral() -> coloca os motores em neutro
 */
#include <iostream>
#include "libs/EdubotLib.hpp"

int main(){
    /*
     * vamos criar um ponteiro para um objeto da classe edubot
     * esse elemento nos permitira acessar todas as funcoes que sao
     * fornecidas pela biblioteca
     */
    EdubotLib *edubotLib = new EdubotLib();
       /*
      * primeiro precisamos nos conectar ao robo
      * a funcao connect retorna verdadeiro em caso de sucesso
        */
    if(edubotLib->connect()){
        /*
         * Funcao move > move(double velocity)
         * Deve receber um valor double entre (-1.0, 1.0)
         * Valores positivos move para frente negativos para tras
        */
        edubotLib->move(0.5);
        /*
         * Para permitir que o robo se movimente por um determinado tempo
         * se utiliza da funcao sleepMilliseconds(int ms), que suspende a
         * execucao do programa pelo valor de milissegundos passado em seu
         * argumento
         */
        edubotLib->sleepMilliseconds(2000);
        /*
         * Funcao rotate > rotate(double angle)
         * Deve receber um angulo em graus entre (-180, 180)
         * Valores positivos rotaciona para direita, negativos para a esquerda
        */
        edubotLib->rotate(90);
        // Mais uma vez aguarda um periodo para o robo poder rotacionar
        edubotLib->sleepMilliseconds(2000);
        // Agora movimenta o robo para tras
        edubotLib->move(-0.5);
        edubotLib->sleepMilliseconds(2000);
        /*
         * Funcao stop
         * Utilizada para frear os motores
         */
        edubotLib->stop();
        // Aguarda 1 segundo para garantir que o robo esta parado
        edubotLib->sleepMilliseconds(1000);
        /*
         * Funcao neutral
         * coloca os motores em estado neutro
        */
        edubotLib->neutral();
        edubotLib->sleepMilliseconds(500);
        /*
         * Funcao disconnect
         * desconecta o programa do robo
         * SEMPRE deve ser utilizada
        */
        edubotLib->disconnect();
    }
    else{
        // Caso nao seja possivel conectar ao robo, enviar um aviso na tela da ide
        std::cout << "Could not connect on robot!" << std::endl;
    }
    return 0;
}