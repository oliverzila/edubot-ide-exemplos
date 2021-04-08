/*
 * EDUBOT Exemplo 4
 * @Author: Carlos Eduardo
 * Nesse exemplo o robo utiliza dados dos sensores
 * para tomar decisoes
 * Edubot move para frente enquanto nao encontra obstaculos
 * quando detecta algo a menos de 0.2 metros o robo gira e 
 * continua se movendo para frente
 * 
*/

#include <iostream>
#include "libs/EdubotLib.hpp"

using namespace std;

int main()
{

	EdubotLib *edubotLib = new EdubotLib();

	//try to connect on robot
	if (edubotLib->connect())
	{
		edubotLib->sleepMilliseconds(200);
		while (edubotLib->isConnected())
		{
			edubotLib->move(0.3);
			do
			{

			} while (edubotLib->getSonar(3) > 0.2);
			edubotLib->rotate(90);
			edubotLib->sleepMilliseconds(1500);
		}

		edubotLib->disconnect();
	}
	else
	{
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}
