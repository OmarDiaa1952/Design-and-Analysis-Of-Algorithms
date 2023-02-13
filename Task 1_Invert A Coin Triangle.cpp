#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n, k;
vector<int> v1;
vector<int> v2;
vector<int> v3;
/* Overloading * operator */
string operator*(string s, size_t count)
{
	string ret;
	for (size_t i = 0; i < count; ++i)
	{
		ret = ret + s;
	}
	return ret;
}

void drawVector3()
{
	cout << "[ ";
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << " ";
	}
	cout << "]" << endl;
}
void drawVector2()
{
	cout << "[ ";
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << " ";
	}
	cout << "]" << endl;
}
void drawVector1()
{
	cout << "[ ";
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << "]" << endl;
}
void reverse_triangle(vector<int> v)
{
	string data1 = " ";
	string data2 = "* ";
	for (int i = 0; i <= v.size() - 1; i++)
	{
		std::cout << data1 * (v.size() - v[i]) + data2 * (v[i]) << "\n";
	}
}
void drawTriangle(int n)
{
	int counter = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int x = n - i; x > 0; x--)
		{

			cout << " ";
		}
		for (int j = 1; j <= i; j++)
		{

			cout << "* ";
		}
		cout << endl;
		v1.push_back(counter);
		counter++;
	}
	cout << "the original vector\n";
	drawVector1();
}

void Kth(int m, int s)
{
	// m is n & s is k
	if (s <= 0 || s > m)
	{
		cout << "invalid value of the base row please restart the program and enter a valid value" << endl;
		exit(0);
	}
	if ((m - s) % 2 == 0)
	{
		for (int i = 0; i <= (n - k) / 2; i++)
		{
			int val = m;
			// cout << val << endl;
			while (s != val)
			{
				v1[m - 1] = v1[m - 1] - 2;
				v1[s - 1] = v1[s - 1] + 2;
				// remove MostRight from last row and add it to MostRight of Kth Row ;
				// remove MostLeft from last row and add it to MostLeft of Kth Row ;

				val = val - 2;
			}
			drawVector1();
			reverse_triangle(v1);

			m--;
			s++;
		}
		// drawVector1();
	}
	else
	{
		for (int i = 0; i <= (((n - k) / 2) + 1); i++)
		{
			//	int j = 0;
			int val = m;
			while (s != val && s <= m)
			{

				v1[m - 1] = v1[m - 1] - (1);
				v1[s - 1] = v1[s - 1] + (1);
				val = val - (1);
			}
			m--;
			s++;
		}
		drawVector1();
		reverse_triangle(v1);
	}
	for (int i = k - 1; i > 0; i--)
	{
		v2.push_back(i);
	}
	drawVector2();

	for (int i = k; i <= v1.size(); i++)
	{
		v3.push_back(v1[i - 1]);
	}
	drawVector3();
	for (int i = 0; i <= v2.size() - 1; i++)
	{
		v3.push_back(v2[i]);
	}

	drawVector3();
}

int main()
{
	cout << "enter number of rows of the triangle and the base of inverter triangle  " << endl;
	cin >> n >> k;
	drawTriangle(n);
	Kth(n, k);
	reverse_triangle(v3);

	return 0;
}
