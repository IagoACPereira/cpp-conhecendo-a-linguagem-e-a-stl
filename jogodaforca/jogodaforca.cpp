#include<iostream>
#include<string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute) {
	for(char letra : PALAVRA_SECRETA) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

int main() {
	cout << PALAVRA_SECRETA  << endl;
	bool nao_errou = true;
	bool nao_enforcou = true;
	while(nao_errou && nao_enforcou) {
		char chute;
		cin >> chute;
		cout << "Seu chute foi: " << chute << endl;
		if (letra_existe(chute)) {
			cout << "Voce acertou! Seu chute esta na palavra" << endl;
		}
		else {
			cout << "Voce errou! Seu chute nao esta na palavra" << endl;
		}
	}
	return 0;
}
