#include "Pessoa.h"
#include <cstring>

Pessoa::Pessoa() {}

Pessoa::Pessoa(string _nome, string _morada, Data _data) {
	nome = _nome;
	morada = _morada;
	data = _data;
}

Pessoa::~Pessoa() {}

void Pessoa::Show() {
	cout << "Nome: " << GetNome() << ";";
	cout << "Morada: " << GetMorada() << ";";
	data.Show();//Como a classe já tem implemnetado o show 
}

void Pessoa::ReadK() {
	char aux[30];
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Nome: ";
	cin.getline(aux, sizeof(aux));
	nome = aux;

	cout << "Morada: ";
	cin.getline(aux, sizeof(aux));
	morada = aux;

	cout << "Data: " << endl;
	cin >> data;//Temos na classe data o operador >> implemntado
}

bool Pessoa:: operator ==(const Pessoa outraPessoa)const {
	if (nome == outraPessoa.nome && morada == outraPessoa.morada && data == outraPessoa.data)
		return true;
	else
		return false;
}

bool Pessoa::MaisNovo(Pessoa outraPessoa) {
	if (data.GetAno() > outraPessoa.data.GetAno())
		return true;
	else
		return false;
	//teria de meter todas as outras condicoes n vejo outra forma
}

ostream& operator <<(ostream& os, const Pessoa pessoa) {
	os << "Nome: " << pessoa.nome << ";";
	os << "Morada: " << pessoa.morada << ";";
	os << "Data: " << pessoa.data << ";" << endl;
	return os;
}

istream& operator >>(istream& is, Pessoa& pessoa) {
	char aux[30];
	// Ignorar o caractere de nova linha residual antes de ler o nome
	is.ignore(numeric_limits<streamsize>::max(), '\n');
	//
	cout << "Nome: " << endl;
	is.getline(aux, sizeof aux);//pq é uma string
	pessoa.nome = aux;
	cout << "Morada: " << endl;
	is.getline(aux, sizeof aux);
	pessoa.morada = aux;
	cout << "Data: " << endl;
	is >> pessoa.data;

	return is;
}

void Pessoa::SaveFile(ofstream& os) {
	os << GetNome() << ";" << GetMorada() << ";";
	data.SaveFile(os);
}

void Pessoa::ReadFile(ifstream& is) {
	char aux[30];
	is.getline(aux, 30, ';');
	nome = aux;
	is.getline(aux, 30, ';');
	morada = aux;

	data.ReadFile(is);
}
