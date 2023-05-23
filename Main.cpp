#include <iostream>
#include <iomanip>
#include<fstream>
#include "BoolVector.h"
using namespace std;

int main()
{
	try {
		srand(time(0));
		setlocale(LC_ALL, "rus");

		int dim = 5;
		BoolVector a(dim), b(dim);
		cout << "a = "; a.show();
		cout << "b = "; b.show();
		cout << "-----------------------------------------\n";
		cout << "Методы класса:\n";
		cout << "Количество нулей в a=" << a.calc_0() << ", в b=" << b.calc_0() << endl;
		cout << "Количество единиц в a=" << a.calc_1() << ", в b=" << b.calc_1() << endl;
		a.conjunction(b);
		a.disjunction(b);
		a.negation();
		b.negation();
		cout << "-----------------------------------------\n";
		cout << "Перегруженные операции:\n";
		cout << "a&b= "; (a & b).show();
		cout << "aVb= "; (a | b).show();
		cout << "-a= "; (~a).show();
		cout << "-b= "; (~b).show();
		cout << "(a > b)? " << (a > b) << endl;
		cout << "(a < b)? " << (a < b) << endl;
		cout << "(a == b)? " << (a == b) << endl;
		cout << "(a == a)? " << (a == a) << endl;
		cout << "-----------------------------------------\n";

		const int n = 10;
		BoolVector* A[n];
		BoolVector* B[n];

		for (int i = 0; i < n; i++)
		{
			A[i] = new BoolVector(dim);
			B[i] = new BoolVector(dim);
		}


		int i = 0;
		ifstream fin;
		string inFile = "input.txt";

		fin.open(inFile);
		while (!fin.eof()) {
			fin >> *A[i];
			fin >> *B[i];
			i++;
		}
		ofstream fout;
		fout.open("result.txt");
		cout << setw(dim + 2) << left << "A" << setw(dim + 2) << left << "B" << setw(dim + 2) << left << "-B" << " A V -B" << endl;
		fout << setw(dim + 2) << left << "A" << setw(dim + 2) << left << "B" << setw(dim + 2) << left << "-B" << " A V -B" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << fixed << *A[i] << "  "; fout << *A[i] << "  ";
			cout << *B[i] << "  "; fout << *B[i] << "  ";
			*B[i] = ~*B[i];
			cout << *B[i] << " | "; fout << *B[i] << " | ";
			cout << (*A[i] | *B[i]) << endl;
			fout << (*A[i] | *B[i]) << endl;
		}
		for (int i = 0; i < n; i++)
		{
			delete A[i];
			delete B[i];
		}
		fout.close();
	}

	catch (const ifstream::failure& ex) {
		cout << ex.what() << endl;
		cout << ex.code() << endl;
		cout << "Ошибка открытия файла\n";
	}
	catch (bad_alloc x)
	{
		cout << "Ошибка при выделении памяти\n";
	}
	catch (...)
	{
		cout << "Ошибка! Что-то пошло не так...\n";
	}
	return 0;
}