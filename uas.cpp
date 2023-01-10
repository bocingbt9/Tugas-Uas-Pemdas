#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

double sum(vector<double> a)
{
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += a[i];
	}
	return s;
}

double mean(vector<double> a)
{
	return sum(a) / a.size();
}

double sqsum(vector<double> a)
{
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s += pow(a[i], 2);
	}
	return s;
}

double stdev(vector<double> nums)
{
	double N = nums.size();
	return pow(sqsum(nums) / N - pow(sum(nums) / N, 2), 0.5);
}

vector<double> operator-(vector<double> a, double b)
{
	vector<double> retvect;
	for (int i = 0; i < a.size(); i++)
	{
		retvect.push_back(a[i] - b);
	}
	return retvect;
}

vector<double> operator*(vector<double> a, vector<double> b)
{
	vector<double> retvect;
	for (int i = 0; i < a.size() ; i++)
	{
		retvect.push_back(a[i] * b[i]);
	}
	return retvect;
}

double pearsoncoeff(vector<double> X, vector<double> Y)
{
	return sum((X - mean(X))*(Y - mean(Y))) / (X.size()*stdev(X)* stdev(Y));
}

int main() {
	int N;
	cout << "Masukan berapa banyak X dan Y yg akan di input :" << endl;
	cin >> N;
	vector<double> X(N);
	vector<double> Y(N);

	for (int i = 0; i < X.size() ; i++)
	{
		cout << "Masukan Nilai X :" << endl;
		cin >> X[i];
	}
	for (int i = 0; i < Y.size(); i++)
	{
		cout << "Masukan Nilai Y :" << endl;
		cin >> Y[i];
	}

	cout << fixed << setprecision(3) << pearsoncoeff(X, Y) << endl;

	return 0;
}