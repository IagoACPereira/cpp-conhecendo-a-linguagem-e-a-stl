#include<iostream>
#include<string>
#include<map>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;

bool letra_existe(char chute) {
	for(char letra : PALAVRA_SECRETA) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

int main() {
	bool nao_errou = true;
	bool nao_enforcou = true;
	while(nao_errou && nao_enforcou) {
		for(char letra : PALAVRA_SECRETA) {
			if (chutou[letra]) {
				cout << letra << " ";
			}
			else {
				cout << "_ ";
			}
		}
		cout << endl;
		char chute;
		cin >> chute;
		chutou[chute] = true;
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
