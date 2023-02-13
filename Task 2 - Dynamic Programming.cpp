//Input: the array size.
//Output: the location of the empty cells and the corresponding location of the remaining peg for every solution.
#include <iostream>
#include <vector>
using namespace std;
void print(long long x, vector<long long> v) {
	cout << "If the empty position was in " << x + 1 << ", then the possible final peg positions are : ";
	if (v.size() == 0) { cout << "no possible solution" << endl; return; }
	cout << v[0];
	for (long long i = 1; i < v.size(); i++)
	{
		cout << " or " << v[i];
	}
	cout << endl;
}
long long onlyONE(vector<int>v) {
	long long x = -1;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i] == 1) {
			if (x == -1) { x = i; }
			else { return -1; }
		}
	}
	return x;
}
vector<long long> add(vector<long long> soln, int x) {
	for (size_t i = 0; i < soln.size(); i++)
	{
		if (soln[i] == x) { return soln; }
	}
	soln.push_back(x);
	return soln;
}

long long bin_rep(vector<int> v) {
	long long base = 1;
	long long res = 0;
	for (long long i = v.size() - 1; i >= 0; i--)
	{
		res += v[i] * base;
		base *= 2;
	}
	return res;
}

long long get_index(long long rep, vector<long long> to_get_index) {
	for (size_t i = 0; i < to_get_index.size(); i++)
	{
		if (to_get_index[i] == rep) { return i; }
	}
	return -1;
}

long long sum(vector<int> v) {
	long long res = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		res += v[i];
	}
	return res;
}

vector<long long> sol(vector<int> v, vector<long long> soln) {

	static vector<long long> to_get_index;
	static vector<vector<long long>> real_soln;
	long long rep = bin_rep(v);
	long long index = get_index(rep, to_get_index);

	long long x = onlyONE(v);
	if (x != -1) {
		soln = add(soln, x + 1);
		if (index == -1) {
			to_get_index.push_back(rep);
			real_soln.push_back(soln);
		}
		else {
			real_soln[index] = soln;
		}
		return soln;
	}

	//if (index != -1) {
	//	return real_soln[index];
	//}

	vector<int> poss(v.size(), 0);
	for (size_t i = 0; i < v.size(); i++)
	{
		if (i < v.size() - 2) {
			if (v[i] == 1 && v[i + 1] == 1 && v[i + 2] == 0) { poss[i] += 1; }
		}
		if (i > 1) {
			if (v[i] == 1 && v[i - 1] == 1 && v[i - 2] == 0) { poss[i] += 10; }
		}
	}

	if (sum(poss) == 0) {
		to_get_index.push_back(rep);
		real_soln.push_back(soln);
		return soln;
	}

	for (size_t i = 0; i < poss.size(); i++)
	{
		if (poss[i] == 1 || poss[i] == 11) {
			vector<int> vv = v;
			vv[i] = 0; vv[i + 1] = 0; vv[i + 2] = 1;
			soln = sol(vv, soln);
			if (index == -1) {
				to_get_index.push_back(rep);
				real_soln.push_back(soln);
			}
			else {
				real_soln[index] = soln;
			}
		}
		if (poss[i] >= 10) {
			vector<int> vv = v;
			vv[i] = 0; vv[i - 1] = 0; vv[i - 2] = 1;
			soln = sol(vv, soln);
			if (index == -1) {
				to_get_index.push_back(rep);
				real_soln.push_back(soln);
			}
			else {
				real_soln[index] = soln;
			}

		}
	}

	return soln;
}

int main() {

	long long n;
	cin >> n;
	vector<int> v(n, 1);
	for (long long i = 0; i < n; i++)
	{
		v[i] = 0;
		vector<long long> soln = sol(v, {});
		print(i, soln);
		v[i] = 1;
	}


	return 0;
}