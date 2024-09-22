#pragma once
#include <fstream>
#include <iostream>
#include "data.h"

using namespace std;

class Pessoa
{
private:
	string nome, morada;
	Data data;
public:
	Pessoa();
	Pessoa(string _nome, string _morada, Data _data);
	~Pessoa();
	inline void SetNome(string _nome) { nome = _nome; }
	inline void SetMorada(string _morada) { morada = _morada; }
	inline void SetData(Data _data) { data = _data; }
	inline string GetNome() { return nome; }
	inline string GetMorada() { return morada; }
	inline Data GetData() { return data; }
	void Show();
	void ReadK();
	bool operator ==(const Pessoa outraPessoa)const;
	bool MaisNovo(Pessoa outraPessoa);
	friend ostream& operator <<(ostream& os, const Pessoa pessoa);
	friend istream& operator >>(istream& is, Pessoa& pessoa);
	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);
};