#include "Funcionario.h"
#include <cstring>
#include <fstream>
#include <iostream>
Funcionario::Funcionario() {}

//os outros atributos são herdados da class Pessoa
//chamamos o construtor da class Pessoa
Funcionario::Funcionario(int _num, string _setor, string _nome, string _morada, Data _data,
	float _ord_base, int _h_extra) :Pessoa(_nome, _morada, _data) {
	num = _num;
	setor = _setor;
	ord_base = _ord_base;
	h_extra = _h_extra;
}

Funcionario::~Funcionario() {}

void Funcionario::Show() {
	cout << "Numero: " << GetNum() << ";";
	cout << "Setor: " << GetSetor() << ";";
	// Sem Pessoa:: atras ia chamar o proprio Show do Funcionario
	Pessoa::Show();//Implementado na classe pessoa

	cout << "Ordenado base: " << GetOrdBase() << ";";
	cout << "Horas extra: " << GetHExtra() << ";";
}

//ostream& operator <<(ostream& os,const Funcionario funcionario) {

	//os << "Numero: " << funcionario.num << endl;
	//os << "Setor: " << funcionario.setor << endl;
	//so podemos fazer cast direto porqueo funcionario deriva da classe Pessoa
	//os << (Pessoa&)funcionario;

	//return os;
//}

istream& operator >>(istream& is, Funcionario& funcionario) {

	cout << "Numero: ";
	is >> funcionario.num;
	is.ignore();

	char aux[100];
	cout << "Setor: ";
	is.getline(aux, sizeof aux);
	funcionario.setor = aux;

	is >> (Pessoa&)funcionario;

	return is;
}

void Funcionario::ReadK() {
	Pessoa::ReadK();

	char aux[100];

	cin.ignore();
	cout << "Numero: ";
	cin.getline(aux, sizeof(aux));
	num = atoi(aux);

	cout << "Setor: ";
	cin.getline(aux, sizeof(aux));
	setor = aux;

	cout << "OrdBase: ";
	cin.getline(aux, sizeof(aux));
	ord_base = atoi(aux);

	//quando é numeros posso só fazer o seguinte
	cout << "HExtra: ";
	cin >> h_extra;
}

void Funcionario::SaveFile(ofstream& os) {
	os << GetNum() << ";";
	os << GetSetor() << ";";
	Pessoa::SaveFile(os);
	os << GetOrdBase() << ";";
	os << GetHExtra() << ";";
}

void Funcionario::ReadFile(ifstream& is) {
	char aux[100];
	is.getline(aux, sizeof(aux), ';');
	//converte para um numero
	num = atoi(aux);

	is.getline(aux, sizeof(aux), ';');
	setor = aux;

	Pessoa::ReadFile(is);

	is.getline(aux, sizeof aux, ';');
	ord_base = atoi(aux);

	is.getline(aux, sizeof aux, ';');
	h_extra = atoi(aux);
}
