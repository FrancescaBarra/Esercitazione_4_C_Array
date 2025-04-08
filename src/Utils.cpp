#include "Utils.hpp"
#include "fstream"
#include "iostream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& inputFilePath, size_t& n, double*& w, double*& r, unsigned int& S)
{
	ifstream fstr(inputFilePath);
	if(fstr.fail())
		return false;
	
	string tmp;
	getline(fstr, tmp, ';');
	fstr >> S;
	
	getline(fstr, tmp, ';');
	fstr >> n;
	
	w = new double[n];
	r = new double[n];
	
	char c;
	unsigned int i = 0;
	getline(fstr, tmp);
	while(getline(fstr, tmp)&& i <= n)
	{
		stringstream str(tmp);
		str >> w[i] >> c >> r[i];
		i++;
	}
	return true;
}

unsigned int DotProduct(const size_t& n, const double* const& w, const double* const& r, const unsigned int& S, double& V)
{
	double ror = 0;
	unsigned int i = 0;
	for(i, i < n; i++)
		ror += w[i] * r[i];
	V = (1 + ror) * S;
    return ror;
}

bool ExportResult(const string& outputFilePath, const size_t& n, const double* const& w, const double* const& r, const unsigned int& dotProduct, const double& V)
{
    ofstream result;
    result.open(outputFilePath);

    if (result.fail())
    {
        cerr<< "Errore nell'apertura del file"<< endl;
        return false;
    }

    result << "S = " << S << ", n = " << n << endl;
	
	result << "w = [ ";
	for(unsigned int = 0, i < n; i++)
		result << w[i]
	result << " ]" << endl;
	
	result << "r = [ ";
	for(unsigned int = 0, i < n; i++)
		result << r[i]
	result << " ]" << endl;

	result << "Rate of return of the portfolio: " << setprecision(4) << dotProduct << endl;
	result << "V: " << setprecision(2) << V << endl;

    result.close();
	
    return true;
}