#include <iostream>
#include "Busca.h"
#include <map>
#include <set>

using std::string;
using std::map;
using std::set;

int main() {
	Busca minhaBusca= Busca();
	minhaBusca.Inserir_Livro("Romeu e Julieta", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\romeoandjuliet.txt");
	minhaBusca.Inserir_Livro("Hamlet", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\hamlet.txt");
	minhaBusca.Inserir_Livro("Othello", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\othello.txt");
	minhaBusca.Inserir_Livro("Kinglear", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\kinglear.txt");
	minhaBusca.Inserir_Livro("Macbeth", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\macbeth.txt");
	minhaBusca.Remover_Livro("Macbeth");
	int livros = minhaBusca.Quantidade_Livros();
	string frase;
	std::cout << "Digite a frase que deseja buscar: ";
	std::getline(std::cin, frase);
	map<string, set<string>> resultado = minhaBusca.Buscar(frase);
	std::cout << "Pesquisando em " << livros << " livros.\n";
	for (map<string, set<string>>::iterator mapa = resultado.begin(); mapa != resultado.end(); mapa++) {
		std::cout << "Palavra: " << (*mapa).first << "\nLivros: ";
		for (set<string>::iterator livroSet = (*mapa).second.begin(); livroSet != (*mapa).second.end(); livroSet++) {
			std::cout << (*livroSet) << " ";
		}
		std::cout << "\n";
	}
	system("pause");
	return 0;
}