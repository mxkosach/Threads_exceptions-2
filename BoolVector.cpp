#include "BoolVector.h"
#include <iostream>
#include<fstream>
using namespace std;

int BoolVector::get_dim() {
	return dim;
};

bool* BoolVector::getVector() {
	return coord;
};

BoolVector::BoolVector()
{
	dim = rand() % 10 + 1;
	coord = new bool[dim + 1];
	if (!coord) {
		cout << "Error";
		return;
	}
	for (int i = 0; i < dim; i++)
		coord[i] = rand() % 2;
}
BoolVector::BoolVector(int k)
{
	dim = k;
	coord = new bool[dim + 1];
	if (!coord) {
		cout << "Error";
		return;
	}
	for (int i = 0; i < dim; i++)
		coord[i] = rand() % 2;
}
BoolVector::BoolVector(const BoolVector& vect)
{
	dim = vect.dim;
	coord = new bool[dim + 1];
	if (!coord) {
		cout << "Error";
		return;
	}
	for (int i = 0; i <= dim; i++)
		coord[i] = vect.coord[i];
}
BoolVector::BoolVector(int k, int array[]) {
	dim = k;
	coord = new bool[dim + 1];
	if (!coord) {
		cout << "Error";
		return;
	}
	for (int i = 0; i < dim; i++)
		coord[i] = array[i];
}
void BoolVector::show(bool Endl)
{
	for (int i = 0; i < dim; i++)
		cout << coord[i];
	if (Endl)
		cout << endl;
}
void BoolVector::giveMemory(int k) {
	if (coord)
		delete[]coord;
	coord = new bool[k + 1];
	if (!coord) {
		cout << "Error";
	}
}

void BoolVector::set(int Dim, int* array) {
	dim = Dim;
	if (coord)
		delete[]coord;
	coord = new bool[dim + 1];
	for (int i = 0; i < dim; i++)
		coord[i] = array[i];
}

int BoolVector::calc_0() {
	int z = 0;
	for (int i = 0; i < dim; i++)
	{
		if (!coord[i])
			z++;
	}
	return z;
}
int BoolVector::calc_1() {
	int k = 0;
	for (int i = 0; i < dim; i++)
	{
		if (coord[i])
			k++;
	}
	return k;
}

void BoolVector::conjunction(BoolVector vect) {
	if (dim != vect.dim)
	{
		cout << "Ops... Different dimensions\n";
		return;
	}
	cout << "conjunction a&b: ";
	for (int i = 0; i < dim; i++)
		cout << (coord[i] & vect.coord[i]);
	cout << endl;
}

void BoolVector::disjunction(BoolVector vect) {
	if (dim != vect.dim)
	{
		cout << "Ops... Different dimensions\n";
		return;
	}
	cout << "disjunction aVb: ";
	for (int i = 0; i < dim; i++)
		cout << (coord[i] | vect.coord[i]);
	cout << endl;
}

void BoolVector::negation() {
	cout << "negation: ";
	for (int i = 0; i < dim; i++)
		cout << !coord[i];
	cout << endl;
}

BoolVector BoolVector::operator & (BoolVector vect)
{
	if (dim != vect.dim)
	{
		cout << "Ops... Different dimensions\n";
		return 0;
	}
	BoolVector temp(dim);
	temp.giveMemory(dim);
	temp.dim = dim;
	for (int i = 0; i < dim; i++)
		temp.coord[i] = (coord[i] & vect.coord[i]);
	return temp;
}

BoolVector BoolVector::operator=(BoolVector vect)
{
	dim = vect.get_dim();
	vect.giveMemory(dim);
	for (int i = 0; i < dim; i++)
		vect.coord[i] = coord[i];
	return BoolVector();
}

BoolVector BoolVector::operator|(BoolVector vect)
{
	if (dim != vect.dim)
	{
		cout << "Ops... Different dimensions\n";
		return 0;
	}
	BoolVector temp(dim);
	temp.giveMemory(dim);
	for (int i = 0; i < dim; i++)
		temp.coord[i] = (coord[i] | vect.coord[i]);
	return temp;
}

BoolVector BoolVector::operator~()
{
	for (int i = 0; i < dim; i++)
		coord[i] = !coord[i];
	return *this;
}

bool BoolVector::operator>(BoolVector vect)
{
	for (int i = 0; i < dim; i++)
		if (coord[i] < vect.coord[i])
			return true;
		else
			if (coord[i] > vect.coord[i])
				return false;
}

bool BoolVector::operator<(BoolVector vect)
{
	for (int i = 0; i < dim; i++)
		if (coord[i] > vect.coord[i])
			return true;
		else
			if (coord[i] < vect.coord[i])
				return false;
}

bool BoolVector::operator==(BoolVector vect)
{
	int k = 0;
	if (dim = vect.dim) {
		for (int i = 0; i < dim; i++)
			if (coord[i] == vect.coord[i])
				k++;
		if (k == dim)
			return true;
	}
	else {
		for (int i = 0; i < dim; i++)
			if (coord[i] == 0 && vect.coord[i] == 0)
				break;
			else
				if (coord[i] == vect.coord[i])
					k++;
	}
}

std::ostream& operator<<(std::ostream& out, const BoolVector& vect) {
	for (int i = 0; i < vect.dim; i++)
		out << vect.coord[i];
	return out;
}

std::istream& operator>>(std::istream& in, BoolVector& vect)
{
	string str="";
	in >> str;
	vect.dim = str.size();
	bool* b = new bool[vect.dim];
	for (int i = 0; i < vect.dim; i++)
	{
		b[i] = (str[i] == '1');
	}
	vect.coord = b;
	return in;
}
