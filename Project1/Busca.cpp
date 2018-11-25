#include "Busca.h"
#include <string>
#include <map>
#include <algorithm>
#include <fstream>

using std::string;
using std::map;

void Busca::Inserir_Livro(string nome, string caminho)
{
	this->livros_[nome] = caminho;
	contaLivros_++;
}

void Busca::Remover_Livro(string nome)
{
	if (this->livros_.count(nome) > 0) {
		map<string, string>::iterator livroIterator = this->livros_.find(nome);
		this->livros_.erase(livroIterator);
		contaLivros_--;
	}
}


int Busca::Quantidade_Livros()
{
	return contaLivros_;
}

void Busca::Limpa_Livros()
{
	livros_.erase(livros_.begin(), livros_.end());
}

map<string, std::set<string>> Busca::Buscar(string fraseDigitada)
{
	Busca_Frase(fraseDigitada);
	return this->palavrasBuscadas_;
}

Busca::Busca()
{
	contaLivros_ = 0;
}


void Busca::Busca_Frase(string fraseBusca)
{
	this->palavrasBuscadas_.erase(this->palavrasBuscadas_.begin(), this->palavrasBuscadas_.end()); //Apagando informações da última busca
	size_t posicao = 0;
	string palavra;
	string delimitador = " ";
	while ((posicao = fraseBusca.find(delimitador)) != string::npos) {
		palavra = fraseBusca.substr(0, posicao);
		this->palavrasBuscadas_[palavra] = Busca_Nos_Arquivos(Arrumar_Palavra(palavra));
		fraseBusca.erase(0, posicao + delimitador.length());
	}
	this->palavrasBuscadas_[fraseBusca] = Busca_Nos_Arquivos(Arrumar_Palavra(fraseBusca));
}

string Busca::Arrumar_Palavra(string palavra)
{
	char * palavraChar = (char*)palavra.c_str();
	for (int i = 0; palavraChar[i] != NULL; i++) {
		if (int(palavraChar[i] >= 65 && int(palavraChar[i]) <= 90)) //Maísculas transformadas em Minúsuclas
			palavraChar[i] = palavraChar[i] + 32;
		else if (int(palavraChar[i]) >= 97 && int(palavraChar[i]) <= 122) {}//Minúsculas -> Do nothing
		else
			palavraChar[i] = 33; //Tranforma todo outro tipo de caracter em ! para facilitar a remoção
	}
	palavra = (string)palavraChar;
	palavra.erase(std::remove(palavra.begin(), palavra.end(), '!'), palavra.end());
	return palavra;
}

std::set<string> Busca::Busca_Nos_Arquivos(string palavra)
{
	std::set<string> arquivosCorretos;
	for (map < string, string>::iterator arquivoAtual = this->livros_.begin(); arquivoAtual != this->livros_.end(); arquivoAtual++) {
		if (Varre_Arquivo((*arquivoAtual).second, palavra))
			arquivosCorretos.insert((*arquivoAtual).first);
	}
	return arquivosCorretos;
}

bool Busca::Varre_Arquivo(string path, string palavraProcurada)
{
	string palavraArquivo;
	std::ifstream arquivo(path);
	if (arquivo.is_open()) {
		while (!arquivo.eof()) {
			std::getline(arquivo, palavraArquivo, ' ');
			if (Arrumar_Palavra(palavraArquivo) == palavraProcurada) {
				arquivo.close();
				return true;
			}
		}
		arquivo.close();
	}
	return false;
}