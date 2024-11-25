#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
	for(char letra : PALAVRA_SECRETA) {
		if (chute == letra) {
			return true;
		}
	}
	return false;
}

bool nao_acertou() {
	for(char letra : PALAVRA_SECRETA) {
		if (!chutou[letra]) {
			return true;
		}
	}
	return false;
}

bool nao_enforcou() {
	return chutes_errados.size() < 5;
}

int main() {
	cout << "*********************" << endl;
	cout << "*** JOGO DA FORCA ***" << endl;
	cout << "*********************" << endl;
	cout << endl;
	while(nao_acertou() && nao_enforcou()) {
		cout << "Chutes errados: ";
		for(char letra : chutes_errados) {
			cout << letra << " ";
		}
		cout << endl;
		for(char letra : PALAVRA_SECRETA) {
			if (chutou[letra]) {
				cout << letra << " ";
			}
			else {
				cout << "_ ";
			}
		}
		cout << endl;
		cout << "Chute uma letra: ";
		char chute;
		cin >> chute;
		chutou[chute] = true;
		cout << "Seu chute foi: " << chute << endl;
		if (letra_existe(chute)) {
			cout << "Voce acertou! Seu chute esta na palavra" << endl;
		}
		else {
			cout << "Voce errou! Seu chute nao esta na palavra" << endl;
			chutes_errados.push_back(chute);
		}
		cout << endl;
	}
	return 0;
}
