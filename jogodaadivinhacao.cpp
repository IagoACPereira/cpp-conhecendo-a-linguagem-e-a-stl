#include<iostream>
using namespace std;

int main() {
	cout << "******************************************" << endl;
	cout << "*    Bem vindo ao jogo da adivinhacao    *" << endl;
	cout << "******************************************" << endl;

	cout << "Adivinhe o numero secreto entre 1 e 100." << endl;
        const int NUMERO_SECRETO = 32;
        bool errou = true;
        int tentativas = 0;
	double pontos = 1000;

	cout << "Escolha o nivel de dificuldade: " << endl;
	cout << "Facil [F], Medio [M] ou Dificil [D]" << endl;

	char dificuldade;
	cin >> dificuldade;

	int numero_tentativas;

	if (dificuldade == 'F') {
	    numero_tentativas = 15;
	}
	else if (dificuldade == 'M') {
	    numero_tentativas = 10;
	}
	else {
	    numero_tentativas = 5;
	}

        for(tentativas = 1; tentativas <= numero_tentativas; tentativas++) {
            int chute;

            cout << "Tentativa " << tentativas << endl;
            cout << "Chute um numero: ";
            cin >> chute;

            bool acertou = chute == NUMERO_SECRETO;
            bool maior = chute > NUMERO_SECRETO;
	    double pontos_perdidos = abs((chute - NUMERO_SECRETO) / 2.0);
	    pontos = pontos - pontos_perdidos;

            if (acertou) {
                cout << "Parabens! Voce acertou o numero secreto." << endl;
                errou = false;
		break;
            }
            else if (maior) {
                cout << "Seu chute e maior que o numero secreto." << endl;
            }
            else {
                cout << "Seu chute e menor que o numero secreto." << endl;
            }
        }

	if (errou) {
	    cout << "Voce perdeu. Tente novamente." << endl;
	}
	else {
            cout << "Fim de jogo!" << endl;
            cout << "Voce acertou o numero secreto em " << tentativas << " tentativas." << endl;
	    cout.precision(2);
	    cout << fixed;
	    cout << "Pontuacao: " << pontos << endl;
	}
}
