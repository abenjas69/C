#pragma once
#include <list>//para podermos usar a template lista
#include "Funcionario.h"
#include "Operario.h"
#include "Administrativo.h"


class Gestor_Func
{
private:
	list<Funcionario*>Lista;
public:
	Gestor_Func();
	~Gestor_Func();

	void AdicionarFunc(Funcionario* func);

	void ShowFunc();

	void RemoverFunc(int num);

	void SaveFile();

	void ReadFile();

	friend ostream& operator <<(ostream& os, Gestor_Func f);
	friend istream& operator >>(istream& is, Gestor_Func& f);
};

