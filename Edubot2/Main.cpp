/*
 * EDUBOT Exemplo 2
 * @Author: Carlos Eduardo
 * Nesse exemplo faremos o edubot percorrer uma trajetoria
 * na forma de um quadrado repetidamente
*/
#include <iostream>
#include "libs/EdubotLib.hpp"

int main(){
	EdubotLib *edubotLib = new EdubotLib();
	//try to connect on robot
	if(edubotLib->connect()){

		while(edubotLib->isConnected()){
			edubotLib->move(0.5);
			edubotLib->sleepMilliseconds(1000);
			edubotLib->rotate(90);
			edubotLib->sleepMilliseconds(2000);
		}
		edubotLib->disconnect();
	}
	else{
		std::cout << "Could not connect on robot!" << std::endl;
	}
	return 0;
}
