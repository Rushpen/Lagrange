#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y; 
};

vector<double> Lagrange1(vector<Point>p, vector <double> newx) {
    vector <double> ys;
    ys.reserve(newx.size());
    for (int k = 0; k < newx.size(); k++) {
        double result = 0;
        for (int i = 0; i < p.size(); i++) {
            double y = p[i].y;
            for (int j = 0; j < p.size(); j++) {
                if (j != i) y *= (newx[k] - p[j].x) / (p[i].x - p[j].x);
            }
            result += y;
        }
        ys.push_back(result);
    }
    return ys;
}

int main() {
    vector<Point> p
    {{-4, 0.01831564},
    { -3, 0.04978707 },
    { -1, 0.367879441 },
    { 1, 2.718281828 },
    { 2.5, 12.182494},
    { 3, 20.08553692 },
    { 4, 54.59815003 }};

    vector<double> newx{ -3.5, -2.5, -2, -1.5, -0.5, 0, 0.5, 1.5, 2, 3.3, 3.5, 3.6, 3.7, 3.9 };

    cout.width(10); cout << "X"; cout.width(10); cout << "Y" << endl;
    for (int i = 0; i < newx.size(); i++) {
        cout.width(10); cout.precision(14);cout<<newx[i];
        cout.width(20); cout.precision(14);cout << Lagrange1(p,newx)[i]<<endl;
    }

    cin.get();
    return 0;
}

/**double Lagrange(vector<Point>p, int n, double xi) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        double ys = p[i].y;
        for (int j = 0; j < n; j++) {
            if (j != i) ys *= (xi - p[j].x) / (p[i].x - p[j].x);
        }
        result += ys;
    }
    return result;
}*/