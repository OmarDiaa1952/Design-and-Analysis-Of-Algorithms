task switches

#include <iostream>
#include <vector>
using namespace std;

int x = 0;

void dis(vector<int> v, vector<int> vv) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " " << vv[i] << endl;
    }
    cout << endl;
}

void dis(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void flip_u(vector<int>& v, int i);

void flip_d(vector<int>& v, int i) {
    int j = v.size() - 1;
    if (i == j) {
        v[i] = (v[i] == 0) ? 1 : 0;
        x++;
        dis(v);
        return;
    }
    if (i == j - 1) {
        v[i] = (v[i] == 0) ? 1 : 0;
        dis(v);
        v[j] = (v[j] == 0) ? 1 : 0;
        x++;
        x++;
        dis(v);
        return;
    }
    flip_d(v, i + 2);
    v[i] = (v[i] == 0) ? 1 : 0;
    x++;
    dis(v);
    flip_u(v, i + 2);
    flip_d(v, i + 1);
    return;
}

void flip_u(vector<int>& v, int i) {
    int j = v.size() - 1;
    if (i == j) {
        v[i] = (v[i] == 0) ? 1 : 0;
        x++;
        dis(v);
        return;
    }
    if (i == j - 1) {
        v[j] = (v[j] == 0) ? 1 : 0;
        dis(v);
        v[i] = (v[i] == 0) ? 1 : 0;
        x++;
        x++;
        dis(v);
        return;
    }
    flip_u(v, i + 1);
    flip_d(v, i + 2);
    v[i] = (v[i] == 0) ? 1 : 0;
    x++;
    dis(v);
    flip_u(v, i + 2);
    return;
}

int main() {
    /*vector<int> nn;
    vector<int> xx;
    int n=1;
    while (n<=15) {
        nn.push_back(n);
        vector<int> v(n, 1);
        dis(v);
        flip_d(v, 0);
        xx.push_back(x);
        x = 0;
        n++;
    }
    dis(nn,xx);*/

    int n = 10;
    vector<int> v(n, 1);
    dis(v);
    flip_d(v, 0);

    cout << endl << x;

    return 0;
}
