// Ex_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Pessoa.h"
#include <vector>
#include "Operario.h"
#include "Administrativo.h"
#include <string>
#include "Gestor_Func.h"


int main()
{
	Operario* op = new Operario(false, 25050, "Pintura", "Zeca Estacionancio", "Rua A n9", Data(1985, 1, 1), 1100, 15);
	Administrativo* adm = new Administrativo(25051, "RecHumanos", "Adrusila Lopes", "Rua E n6", Data(1996, 6, 6), 900, 0);

	Gestor_Func gestor;

	gestor.AdicionarFunc(op);
	gestor.AdicionarFunc(adm);

	gestor.ShowFunc();

	gestor.SaveFile();
	


}