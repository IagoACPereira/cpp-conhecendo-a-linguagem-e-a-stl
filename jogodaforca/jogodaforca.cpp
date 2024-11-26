#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
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

void le_arquivo() {
	ifstream arquivo;
	arquivo.open("palavras.txt");
	int qtd_palavras;
	arquivo >> qtd_palavras;
	cout << "O arquivo possui " << qtd_palavras << " palavras." << endl;
	for(int i = 0; i < qtd_palavras; i++) {
		string palavra_lida;
		arquivo >> palavra_lida;
		cout << "Na linha " << i << " : " << palavra_lida << endl;
	}
}

int main() {
	imprime_cabecalho();
	le_arquivo();
	while(nao_acertou() && nao_enforcou()) {
		imprime_erros();
		imprime_acertos();
		chuta();
	}
	cout << "Fim de jogo!" << endl;
        cout << "Palavra secreta: " << PALAVRA_SECRETA << endl;
	if (!nao_acertou()) {
		cout << "Parabens! Voce venceu o jogo" << endl;
	}
	else {
		cout << "Infelizmente voce perdeu! tente novamente" << endl;
	}
	return 0;
}
