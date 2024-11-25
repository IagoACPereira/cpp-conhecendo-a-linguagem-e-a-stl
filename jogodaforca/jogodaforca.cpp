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
	cout << "Fim de jogo!" << endl;
	cout << "Palavra secreta: " << PALAVRA_SECRETA << endl;
	cout << "Parabens voce venceu o jogo" << endl;
	return false;
}

bool nao_enforcou() {
	cout << "Fim de jogo!" << endl;
	cout << "Palavra secreta: " << PALAVRA_SECRETA << endl;
	cout << "Infelizmente voce perdeu o jogo" << endl;
	return chutes_errados.size() < 5;
}

void imprime_cabecalho() {
	cout << "*********************" << endl;
        cout << "*** JOGO DA FORCA ***" << endl;
        cout << "*********************" << endl;
        cout << endl;
}

void imprime_erros() {
	cout << "Chutes errados: ";
	for(char letra : chutes_errados) {
		cout << letra << " ";
	}
	cout << endl;
}

void imprime_acertos() {
	for(char letra : PALAVRA_SECRETA) {
		if (chutou[letra]) {
			cout << letra << " ";
		}
		else {
			cout << "_ ";
		}
	}
	cout << endl;
}

void chuta() {
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

int main() {
	imprime_cabecalho();
	while(nao_acertou() && nao_enforcou()) {
		imprime_erros();
		imprime_acertos();
		chuta();
	}
	return 0;
}
