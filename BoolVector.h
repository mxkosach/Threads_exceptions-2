#pragma once
#include<fstream>

class BoolVector
{
	int dim;
	bool* coord;
public:
	BoolVector();
	BoolVector(int k);
	BoolVector(int k, int array[]);
	BoolVector(const BoolVector& vect);
	~BoolVector() {
		delete[]coord;
	};

	int get_dim();
	bool* getVector();
	void conjunction(BoolVector vect);
	void disjunction(BoolVector vect);
	void negation();
	void show(bool Endl = true);
	bool getcoord(BoolVector vect);
	void giveMemory(int k);
	void set(int Dim, int* array);

	int calc_0();
	int calc_1();
	BoolVector operator & (BoolVector vect);
	BoolVector operator = (BoolVector vect);
	BoolVector operator | (BoolVector vect);
	BoolVector operator ~ ();
	bool operator > (BoolVector vect);
	bool operator < (BoolVector vect);
	bool operator == (BoolVector vect);
	friend std::ostream& operator<<(std::ostream& out, const BoolVector& vect);
	friend std::istream& operator>> (std::istream& in, BoolVector& vect);

};