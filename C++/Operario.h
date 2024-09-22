#pragma once
#pragma once
#include "Funcionario.h"
#include <cstring>
#include <fstream>
#include <iostream>

class Operario : public Funcionario {
private:
	bool fturno;
public:
	Operario();
	Operario(bool _fturno, int _num, string _setor, string _nome, string _morada, Data _data,
		float _ord_base, int _h_extra);
	~Operario();
	inline void SetFTurno(bool _fturno) { fturno = _fturno; }
	inline bool GetFTurno() { return fturno; }

	void Show();
	void ReadK();
	void SaveFile(ofstream& os);
	void ReadFile(ifstream& is);

	float CalculaOrdenado();

};
