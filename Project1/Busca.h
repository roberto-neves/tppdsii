#ifndef BUSCA_H_
#define BUSCA_H_

#include <set>
#include <string>
#include <map>

using std::string;

class Busca {
public:
	void Inserir_Livro(string nome, string caminho);
	void Remover_Livro(string nome);
	int Quantidade_Livros();
	void Limpa_Livros();
	std::map<string, std::set<string>> Buscar(string fraseDigitada);
	Busca();


private:
	std::map<string, string> livros_;
	std::map<string, std::set<string>> palavrasBuscadas_;
	int contaLivros_;


	void Busca_Frase(string fraseBusca);
	string Arrumar_Palavra(string palavra);
	std::set<string> Busca_Nos_Arquivos(string palavra);
	bool Varre_Arquivo(string path, string palavra);
};
#endif