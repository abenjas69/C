#include "Gestor_Func.h"
#include<string>
Gestor_Func::Gestor_Func()
{
	if (!Lista.empty())
		Lista.clear();
}

Gestor_Func::~Gestor_Func()
{
	if (!Lista.empty())
		Lista.clear();

}

void Gestor_Func::AdicionarFunc(Funcionario* func)
{
	//Verificar se existem algum funcionario com o mesmo numero
	for (Funcionario* f : Lista)
	{
		if (f->GetNum() == func->GetNum())
			return;
	}

	Lista.push_back(func);
}

void Gestor_Func::RemoverFunc(int numero)
{
	for (Funcionario* f : Lista)
	{
		if (f->GetNum() == numero)
		{
			Lista.remove(f);
			return;

		}
	}

	//OU
	//Usar iterador
	//Começamos no inicio da lista

	list<Funcionario*>::iterator pos = Lista.begin();

	while (pos != Lista.end())
	{
		if ((*pos)->GetNum() == numero)
		{
			Lista.erase(pos); //usamos iterador
			//OU
			Lista.remove((*pos)); //usamos o valor
		}
		pos++; //Passar para o nó seguinte
	}

}

void Gestor_Func::ShowFunc()
{
	for (Funcionario* f : Lista)
	{
		//Ver de que tipo é o Func
		if (Operario* op = dynamic_cast<Operario*>(f))
		{
			op->Show();
		}
		if (Administrativo* adm = dynamic_cast<Administrativo*>(f))
		{
			adm->Show();
		}
		cout << endl;
	}
}

void Gestor_Func::ReadFile()
{
	ifstream is;
	is.open("Funcionarios.txt");

	if (!is.is_open())
	{
		exit(-1);
	}

	//Apaga o conteudo da lista
	Lista.clear();

	while (is.peek() != EOF)
	{
		string tipo;
		getline(is, tipo, ':');
		if (tipo == "O")
		{
			Operario* op = new Operario();
			op->ReadFile(is);

			//Temos que inserir na Lista
			Lista.push_back(op);
		}
		else if (tipo == "A")
		{
			Administrativo* adm = new Administrativo();
			adm->ReadFile(is);

			//Temos que inserir na Lista
			Lista.push_back(adm);
		}

		//ignorar o \n
		is.get();
	}
}

void Gestor_Func::SaveFile()
{
	ofstream os;

	os.open("Funcionario.txt");

	if (!os.is_open())
	{
		exit(-1);
	}
	for (Funcionario* f : Lista)
	{
		if (Operario* op = dynamic_cast<Operario*>(f))
		{
			os << "O:";
			op->SaveFile(os);

		}
		if (Administrativo* adm = dynamic_cast<Administrativo*>(f))
		{
			os << "A:";
			adm->SaveFile(os);

		}
		os << endl;
	}
	os.close();
}



istream& operator>>(istream& is, Gestor_Func& f)
{
	char tipo;

	cout << "Escolha o tipo: " << endl;
	cout << "O - Operario" << endl;
	cout << "A - Administrador" << endl;

	cin >> tipo;
	cin.ignore();

	if (tipo == 'O' || tipo == 'o')
	{
		Operario* op = new Operario(); // criar um ponteiro de operario
		op->ReadK(); //Se for ponteiro, uasmos -> e não o .
		f.Lista.push_back(op); //Inserir no fim da lista
	}

	else if (tipo == 'A' || tipo == 'a')
	{
		Administrativo* adm = new Administrativo(); // criar um ponteiro de operario
		adm->ReadK(); //Se for ponteiro, uasmos -> e não o .
		f.Lista.push_back(adm); //Inserir no fim da lista
	}

	return is;
}

ostream& operator<<(ostream& os, Gestor_Func f)
{
	f.ShowFunc();
	return os;
}

