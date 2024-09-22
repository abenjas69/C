#pragma once
#include "Pessoa.h"
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

class Funcionario : public Pessoa
{
private:
	int num, h_extra;
	float ord_base;
	string setor;
public:
	Funcionario();
	//Funcionario como herda da Pessoa tem os atributos + os da class Pessoa
	Funcionario(int _num, string _setor, string _nome, string _morada, Data _data, float _ord_base,
		int _h_extra);
	~Funcionario();

	inline void SetNum(int _num) { num = _num; }
	inline void SetSetor(string _setor) { setor = _setor; }
	inline void SetOrdBase(float _ord_base) { ord_base = _ord_base; }
	inline void SetHExtra(int _h_extra) { h_extra = _h_extra; }
	inline int GetNum() { return num; }
	inline string GetSetor() { return setor; }
	inline float GetOrdBase() { return ord_base; }
	inline int GetHExtra() { return h_extra; }

	virtual float CalculaOrdenado() = 0;//metodo virtual puro; com isto a classe torna se uma classe abstrata

	void Show();
	//friend ostream& operator <<(ostream& os, const Funcionario funcionario);
	friend istream& operator >>(istream& is, Funcionario& funcionario);

	void ReadK();

	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);

};

