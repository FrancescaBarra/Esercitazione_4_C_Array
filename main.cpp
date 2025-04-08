#include <iostream>
#include "Utils.hpp"
using namespace std;

int main()
{
	string filePath = "data.txt";
	size_t n;
	double* w;
	double* r;
	unsigned int S;
	
	if (ImportVectors(filePath, n, w, r, S))
	{
		cout << "S = " << S << ", n = " << n << endl;
		cout << "w = [";
		cout << "r = [";
    }
	delete[] w;
    delete[] r;
    return 0;
}

