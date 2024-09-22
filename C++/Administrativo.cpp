#include "Administrativo.h"

Administrativo::Administrativo() {}

Administrativo::Administrativo(int _num, string _setor, string _nome, string _morada, Data _data,
	float _ord_base, int _h_extra) :Funcionario(_num, _setor, _nome, _morada, _data, _ord_base, _h_extra) {}

Administrativo::~Administrativo() {}

float Administrativo::CalculaOrdenado() {
	return GetOrdBase() + GetHExtra() * 10;
}

void Administrativo::Show() {
	cout << "A: ";
	Funcionario::Show();
}

//void Administrativo::ReadK() {
//	Funcionario::ReadK();
//}

//void Administrativo::SaveFile(ofstream& os) {
//	Funcionario::SaveFile(os);
//}

//void Administrativo::ReadFile(ifstream& is) {
//	Funcionario::ReadFile(is);
//}