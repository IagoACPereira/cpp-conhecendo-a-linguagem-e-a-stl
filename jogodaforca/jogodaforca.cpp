#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;

string PALAVRA_SECRETA = "MELANCIA";
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

vector<string> le_arquivo() {
	ifstream arquivo;
        arquivo.open("palavras.txt");
	if (arquivo.is_open()) {
		int qtd_palavras;
		arquivo >> qtd_palavras;
		vector<string> palavras_arquivo;
		for(int i = 0; i < qtd_palavras; i++) {
			string palavra_lida;
			arquivo >> palavra_lida;
			palavras_arquivo.push_back(palavra_lida);
		}
		arquivo.close();
		return palavras_arquivo;
	}
	else {
		cout << "Nao foi possivel acessar o banco de palavras" << endl;
		exit(0); // Para a execucao do programa.
	}
}

void sorteia_palavra() {
	vector<string> palavras = le_arquivo();
	srand(time(NULL));
	int indice_sorteado = rand() % palavras.size();
	PALAVRA_SECRETA = palavras[indice_sorteado];
}

void salva_arquivo(vector<string> nova_lista) {
	ofstream arquivo;
	arquivo.open("arquivo.txt");
	if (arquivo.is_open()) {
		arquivo << nova_lista.size() << endl;
		for (string palavra : nova_lista) {
			arquivo << palavra << endl;
		}
		arquivo.close();
	}
	else {
                cout << "Nao foi possivel acessar o banco de palavras" << endl;
                exit(0); // Para a execucao do programa.
        }
}

void adiciona_palavra() {
	cout << "Digite a nova palavra, em letras maiusculas: ";
	string nova_palavra;
	cin >> nova_palavra;
	vector<string> lista_palavras = le_arquivo();
	lista_palavras.push_back(nova_palavra);
	salva_arquivo(lista_palavras);
}

int main() {
	imprime_cabecalho();
	le_arquivo();
	sorteia_palavra();
	while(nao_acertou() && nao_enforcou()) {
		imprime_erros();
		imprime_acertos();
		chuta();
	}
	cout << "Fim de jogo!" << endl;
        cout << "Palavra secreta: " << PALAVRA_SECRETA << endl;
	if (!nao_acertou()) {
		cout << "Parabens! Voce venceu o jogo" << endl;
		cout << "Voce deseja adicionar uma nova palavra ao banco? (S/N)" << endl;
		char resposta;
		cin >> resposta;
		if (resposta == 'S' || resposta == 's') {
			adiciona_palavra();
		}
	}
	else {
		cout << "Infelizmente voce perdeu! tente novamente" << endl;
	}
	return 0;
}
