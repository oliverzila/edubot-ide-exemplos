/*
 * Exemplo C++
 * @Author: Carlos Eduardo
*/
#include <iostream>
#include "libs/EdubotLib.hpp"
int main(){
    // inicializacao
    int a = 1;
    int b, c;
    std::cout<<"Inicializacao"<<std::endl;
    b = 0;    
    // loop
    while(true){
        std::cout<<"O valor de a: "<<a<<std::endl;
        std::cout<<"O tamanho de um int: "<<sizeof(int)<<std::endl;
        b += 1; // b = b+1
        std::cout<<"O valor de b: "<<b<<std::endl;
    }
    return 0;
}