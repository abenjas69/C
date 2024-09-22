#pragma once
#include <fstream>
#include <iostream>


using namespace std;

class Data
{
private:
	int ano, dia, mes;
public:
	Data();
	Data(int _ano, int _mes, int _dia);
	virtual ~Data();

	inline void SetAno(int _ano) { ano = _ano; }
	inline void SetMes(int _mes) { mes = _mes; }
	inline void SetDia(int _dia) { dia = _dia; }
	inline int GetAno() { return ano; }
	inline int GetMes() { return mes; }
	inline int GetDia() { return dia; }
	void Show(void);
	void Update(int _ano, int _mes, int _dia);
	bool Igual(Data outraData);
	bool operator ==(const Data outraData) const;
	bool operator !=(const Data outraData) const;
	friend ostream& operator <<(ostream& os, const Data data);
	friend istream& operator >>(istream& is, Data& data);
	void ReadFile(ifstream& is);// recebe a stream para ler ficheiros
	void SaveFile(ofstream& os);
};
