#include "Data.h"

Data::Data() {}

Data::Data(int _ano, int _mes, int _dia) {
	ano = _ano;
	mes = _mes;
	dia = _dia;
}

Data::~Data() {}

void Data::Show(void) {
	cout << GetAno() << "/" << GetMes() << "/" << GetDia() << endl;
}

void Data::Update(int _ano, int _mes, int _dia) {
	ano = _ano;
	mes = _mes;
	dia = _dia;
}

bool Data::Igual(Data outraData) {
	if (GetAno() == outraData.GetAno() && GetMes() == outraData.GetMes() && GetDia() == outraData.GetDia())
		return true;
	else
		return false;
}

bool Data:: operator ==(const Data outraData) const {
	if (ano == outraData.ano && mes == outraData.mes && dia == outraData.dia)
		return true;
	else
		return false;
}

bool Data::operator !=(const Data outraData)const {
	if (ano != outraData.ano || mes != outraData.mes || dia != outraData.dia)
		return true;
	else
		return false;
}

ostream& operator <<(ostream& os, const Data data) {
	os << data.ano << "/" << data.mes << "/" << data.dia << endl;
	return os; //NAO ESQUECER O RETURN!!!
}

istream& operator >>(istream& is, Data& data) {
	cout << "Introduza o ano: ";
	is >> data.ano;
	cout << "Introduza o mes: ";
	is >> data.mes;
	cout << "Introduza o dia: ";
	is >> data.dia;

	return is; //Nao esquecer o return!!!
}

void Data::ReadFile(ifstream& is) {
	char separador;
	is >> ano >> separador >> mes >> separador >> dia >> separador;
}

void Data::SaveFile(ofstream& os) {
	os << GetAno() << "/<" << GetMes() << "/" << GetDia() << endl;
}

