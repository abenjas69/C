#include "Operario.h"

Operario::Operario() {}

Operario::Operario(bool _fturno, int _num, string _setor, string _nome, string _morada, Data _data,
	float _ord_base, int _h_extra) :Funcionario(_num, _setor, _nome, _morada, _data, _ord_base, _h_extra) {
	fturno = _fturno;
}

Operario::~Operario() {}

void Operario::Show() {
	cout << "O: ";
	Funcionario::Show();
	cout << "Turno: " << (fturno ? "Sim" : "Nao");
}

void Operario::ReadK() {
	Funcionario::ReadK();

	char c;
	cout << "Turno(S/N): ";
	cin >> c;

	if (c == 'S')
		fturno = true;
	else
		fturno = false;
}

void Operario::SaveFile(ofstream& os) {
	Funcionario::SaveFile(os);
	os << "Turno: " << (fturno ? "Sim" : "Nao") << endl;
}

void Operario::ReadFile(ifstream& is) {
	Funcionario::ReadFile(is);
	char aux[100];
	is.getline(aux, sizeof aux, ';');

	if (aux == "Sim")
		fturno = true;
	else
		fturno = false;
}

float Operario::CalculaOrdenado() {
	if (fturno)
		return GetOrdBase() * 1.25 + GetHExtra() * 8;
	else
		return GetOrdBase() + GetHExtra() * 8;
}