#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

double langrange(vector <double> vectorVariables, vector <double> vectorValues, double variable);
string conversionAndChangeOfCharacter(double data);

int main() {
	fstream file;
	vector <double> vectorX, vectorY;

	vectorX.push_back(0);
	vectorX.push_back(10);
	vectorX.push_back(40);
	vectorX.push_back(60);
	vectorX.push_back(100);

	vectorY.push_back(0);
	vectorY.push_back(100);
	vectorY.push_back(20);
	vectorY.push_back(-10);
	vectorY.push_back(0);

	double resultLangrange;
	string result;

	file.open("lagrange.txt", ios::out);
	if (file.is_open())
	{
		//wyniki dla 5 punktów
		for (int i = 0; i < 100; i += 5)
		{
			resultLangrange = langrange(vectorX, vectorY, i);
			cout << resultLangrange << endl;
			result = conversionAndChangeOfCharacter(resultLangrange);
			file << result << endl;
		}
		//wyniki dla 4 punktów
		/*
		vectorX.erase(vectorX.end() - 2);
		vectorY.erase(vectorY.end() - 2);
		for (int i = 0; i < 100; i += 5)
		{
			resultLangrange = langrange(vectorX, vectorY, i);
			cout << resultLangrange << endl;
			result = conversionAndChangeOfCharacter(resultLangrange);
			file << result << endl;
		}
		*/
	}
	else
	{
		cout << "Nie otwarto pliku!" << endl;
	}

	system("pause");
	return 0;
}

double langrange(vector<double> vectorVariables, vector<double> vectorValues, double variable)
{
	double temp;
	double result = 0;
	for (int i = 0; i < vectorVariables.size(); i++)
	{
		temp = 1;
		for (int j = 0; j < vectorVariables.size(); j++)
		{
			if (j != i)
			{
				temp *= ((variable - vectorVariables[j]) / (vectorVariables[i] - vectorVariables[j]));
			}
		}
		result += temp*vectorValues[i];
	}
	return result;
}

string conversionAndChangeOfCharacter(double data)
{
	ostringstream temp;
	string result;
	temp << data;
	result = temp.str();
	replace(result.begin(), result.end(), '.', ',');
	temp.str("");
	temp.clear();
	return result;
}
