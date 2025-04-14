#include "Utils.hpp"
#include "fstream"
#include "iostream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportVectors(const string& inputFilePath, 
				   size_t& n, 
				   double*& w, 
				   double*& r, 
				   double& S)
{
	ifstream fstr(inputFilePath);
	if(fstr.fail())
		return false;
	
	string riga;
	char lettera;
	char sep;
	
	//Leggo la prima linea del file: S;1000
	getline(fstr, riga);
	stringstream str1(riga);
	str1 >> lettera >> sep >> S;
	
	//Leggo la seconda riga del file: n;8
	getline(fstr, riga);
	stringstream str2(riga);
	str2 >> lettera >> sep >> n;
	
	//Salto la riga con scritto w;r
	string tmp;
	getline(fstr, tmp);
	
	w = new double[n];
	r = new double[n];
	string line;
	for(unsigned int i = 0; i < n; i++){
		getline(fstr, line);
		stringstream str3(line);
		str3 >> w[i] >> sep >> r[i];
	}
	
	return true;
}

double DotProduct(const size_t& n, 
				  const double* const& w, 
				  const double* const& r)
{
	double prodotto = 0.0;
	for(unsigned int i = 0; i < n; i++)
		prodotto += w[i] * r[i];
    return prodotto;
}

double ValuePortfolio(const size_t& n,
					  const double& S,
					  const double* const& w,
					  const double* const& r)
{
	double V = 0.0;
	for(unsigned int i = 0; i < n; i++)
		V += w[i] * (1 + r[i]);
	V = V * S;
	return V;
}

bool ExportResult(const string& outputFilePath, 
				  const size_t& n, 
				  const double* const& w, 
				  const double* const& r, 
				  const double& S,
				  const double& V,
				  const double& prodotto)
{
    ofstream result;
    result.open(outputFilePath);

    if (result.fail())
    {
        cerr << "Errore nell'apertura del file" << endl;
        return false;
    }

    result << "S = " << setprecision(2) << fixed << S << ", n = " << n << endl;
	
	result << "w = [ ";
	for(unsigned int i = 0; i < n; i++)
		result << w[i] << " ";
	result << "]" << endl;
	
	result << "r = [ ";
	for(unsigned int i = 0; i < n; i++)
		result << r[i] << " ";
	result << "]" << endl;

	result << "Rate of return of the portfolio: " << setprecision(4) << fixed << prodotto << endl;
	result << "V: " << setprecision(2) << fixed << V << endl;

    result.close();
	
    return true;
}