#pragma once
#include "Funcionario.h"
#include <cstring>
#include <fstream>
#include <iostream>

class Administrativo :public Funcionario {
public:
	Administrativo();
	Administrativo(int _num, string _setor, string _nome, string _morada, Data _data,
		float _ord_base, int _h_extra);
	~Administrativo();

	float CalculaOrdenado();

	void Show();
	//void ReadK();
	//void SaveFile(ofstream& os);
	//void ReadFile(ifstream& is);
};

