/*
 * EDUBOT Exemplo 3
 * @Author: Carlos Eduardo
 * Nesse exemplo iremos obter leituras de alguns dos sensores do robo
 * As leituras sao apresentadas no console. Funcoes utilizadas:
 *  double getSonar(size_t id) -> leitura dos sonares em metros
 *  bool getBumper(size_t id) -> leitura dos bumbers
 *  int getEncoderCountLeft() -> leitura do encoder da roda esquerda
 *  int getEncoderCountRight() -> leitura do encoder da roda direita
 *  int getEncoderCountDT() -> tempo de loop dos encoders
 *  double getX() -> Posicao X do robo com relacao ao sist. de coordenadas inicial
 *  double getY() -> Posicao Y do robo com relacao ao sist. de coordenadas inicial
 *  double getTheta() -> Angulo de giro do robo com relacao ao sist. de coordenadas inicial
 *  double getBatteryCellVoltage(size_t id) -> Tensao nas celulas da bateria
*/
#include <iostream>
#include "libs/EdubotLib.hpp"

#define N_SONARES 7
#define N_BUMPERS 4
#define N_CELULAS 3

using namespace std;

int main()
{

	EdubotLib *edubotLib = new EdubotLib();
	double posX;
	double sonares[N_SONARES];

	if (edubotLib->connect())
	{

		/*
		 * Vamos fazer a leitura ciclica dos sensores a cada 1 segundo aproximadamente
		 */
		while (edubotLib->isConnected())
		{
			cout << "---" << endl;

			/*
			 * Primeiro a leitura dos 7 sonares a funcao
			 * getSonar(size_t id) deve receber como argumento um valor inteiro positivo (0 ate 6)
			 * retorna um valor do tipo double com a distancia de um obstaculo em metros
			 * a distancia maxima de deteccao: 2m
			 */

			for (int i = 0; i < N_SONARES; i++)
			{
				sonares[i] = edubotLib->getSonar(i);
				cout << "Sonar " << i << ": " << sonares[i] << "m, ";
			}
			cout << endl;

			/*
			 * A leitura dos bumpers realizada com a funcao
			 * getBumper(size_t id) recebe como argumento um valor inteiro positivo (0 ate 3)
			 * retorna um valor booleano (0 - falso, 1 - verdadeiro) indicando se
			 * houve ou n�o contato do robo com algum obstaculo
			 */
			for (int i = 0; i < N_BUMPERS; i++)
			{
				cout << "Bumper " << i << ": " << edubotLib->getBumper(i);
			}
			cout << endl;

			/*
			 * As funcoes getX(), getY() e getTheta() nao representam a leitura
			 * direta de um sensor, mas sim os valores calculados pelo robo para
			 * sua posicao no plano. Retornam valor do tipo double.
			 * A posicao eh fornecida com respeito a posicao inicial
			 */
			cout << "X: " << edubotLib->getX();
			cout << ", Y: " << edubotLib->getY();
			cout << ", Theta: " << edubotLib->getTheta() << endl;

			// Poderia armazenar a posicao em uma variavel
			posX = edubotLib->getX();

			/*
			 * A medida das tens�es nas celulas da bateria
			 * getBatteryCellVoltage(size_t id) recebe como argumento um inteiro positivo (0 ate 2)
			 * retorna um valor double com o nivel de tensao em cada uma das 3 celulas deve-se monitorar
			 * para que os valores nao fiquem abaixo de 3V
			 */
			for (int i = 0; i < N_CELULAS; i++)
			{
				cout << "Celula " << i << ": " << edubotLib->getBatteryCellVoltage(i) << ", ";
			}
			cout << endl;

			/*
			 * Leituras de pulso dos encoders
			 * getEncoderCountLeft() e getEncoderCountRight() retornam um inteiro
			 * com a contagem de pulsos dos encoders
			 * getEncoderCountDT() retorna um valor inteiro com o tempo de loop dos encoders
			 * em milissegundos
			 * Com esses valores pode-se fazer a propria implementacao das funcoes que
			 * informam a posicao e orientacao do robo
			 */
			cout << "Encoder Esq: " << edubotLib->getEncoderCountLeft() << ", ";
			cout << "Encoder Dir: " << edubotLib->getEncoderCountRight() << ", ";
			cout << "Dt: " << edubotLib->getEncoderCountDT() << endl;

			edubotLib->sleepMilliseconds(1000);
		}

		edubotLib->disconnect();
	}
	else
	{
		std::cout << "Could not connect on robot!" << std::endl;
	}

	return 0;
}
