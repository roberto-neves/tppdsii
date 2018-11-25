#include "stdafx.h"
#include "CppUnitTest.h"
#include "Busca.h"
#include "Busca.cpp"
#include <map>
#include <set>
#include <string>
#include <iostream>

using std::map;
using std::set;
using std::string;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestesUnidade
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Teste_Mecanismo_Livros)
		{
			Busca testeBusca = Busca();
			testeBusca.Inserir_Livro("a", "b");
			Assert::AreEqual(testeBusca.Quantidade_Livros(), 1);
			testeBusca.Remover_Livro("a");
			Assert::AreEqual(testeBusca.Quantidade_Livros(), 0);
			testeBusca.Inserir_Livro("a", "b");
			testeBusca.Remover_Livro("b");
			Assert::AreEqual(testeBusca.Quantidade_Livros(), 1);
			testeBusca.Limpa_Livros();
			Assert::AreEqual(testeBusca.Quantidade_Livros(), 0);
			testeBusca.Inserir_Livro("a", "b");
			testeBusca.Inserir_Livro("b", "c");
			Assert::AreEqual(testeBusca.Quantidade_Livros(), 2);
			testeBusca.Remover_Livro("b");
			testeBusca.Remover_Livro("a");
			Assert::AreEqual(testeBusca.Quantidade_Livros(), 0);
		}

		TEST_METHOD(Teste_Arrumar_Palavra)
		{
			Busca minhaBusca = Busca();
			map<string, set<string>> mapaTeste = minhaBusca.Buscar("and");
			map<string, set<string>>::iterator it = mapaTeste.begin();
			string a = (*it).first;
			string b;
			Assert::AreEqual((string)"and", a);
			mapaTeste = minhaBusca.Buscar("?aN-d?");
			it = mapaTeste.begin();
			a = (*it).first;
			Assert::AreEqual((string)"and", a);
			mapaTeste = minhaBusca.Buscar("romeo and");
			it = mapaTeste.begin();
			a = (*it).first;
			it++;
			b = (*it).first;
			Assert::AreEqual((string)"and", a);
			Assert::AreEqual((string)"romeo", b);
			mapaTeste = minhaBusca.Buscar("and romeo");
			it = mapaTeste.begin();
			a = (*it).first;
			it++;
			b = (*it).first;
			Assert::AreEqual((string)"and", a);
			Assert::AreEqual((string)"romeo", b);
			mapaTeste = minhaBusca.Buscar("r-o-me-o??? !A^ND");
			it = mapaTeste.begin();
			a = (*it).first;
			it++;
			b = (*it).first;
			Assert::AreEqual((string)"and", a);
			Assert::AreEqual((string)"romeo", b);
		}

		TEST_METHOD(Construtor)
		{
			Busca minhaBusca = Busca();
			Assert::AreEqual(minhaBusca.Quantidade_Livros(), 0);
		}

		TEST_METHOD(Resultado_Busca)
		{
			Busca minhaBusca = Busca();
			minhaBusca.Inserir_Livro("Romeu e Julieta", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\romeoandjuliet.txt");
			minhaBusca.Inserir_Livro("Hamlet", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\hamlet.txt");
			minhaBusca.Inserir_Livro("Othello", "C:\\Users\\admin\\Desktop\\TP PDS\\shakespeare\\othello.txt");
			map<string, set<string>> mapaTeste = minhaBusca.Buscar("romeo and juliet");
			map<string, set<string>>::iterator itMap = mapaTeste.begin();
			set<string>::iterator itSet = (*itMap).second.begin();
			Assert::AreEqual((string)"Hamlet", (*itSet));
			itSet++;
			Assert::AreEqual((string)"Othello", (*itSet));
			itSet++;
			Assert::AreEqual((string)"Romeu e Julieta", (*itSet));
			itMap++;
			itSet = (*itMap).second.begin();
			Assert::AreEqual((string)"Romeu e Julieta", (*itSet));
			itMap++;
			itSet = (*itMap).second.begin();
			Assert::AreEqual((string)"Romeu e Julieta", (*itSet));
		}
		

	};
}