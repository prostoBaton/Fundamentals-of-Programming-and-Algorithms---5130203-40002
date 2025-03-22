#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients;

public:
    Polynomial() : coefficients(1, 0.0) {}
    Polynomial(const vector<double>& coeffs) : coefficients(coeffs) {}

    int getDegree() const {
        for (int i = coefficients.size() - 1; i >= 0; --i) {
            if (coefficients[i] != 0.0) return i;
        }
        return -1;
    }

    double getCoefficient(int exponent) const {
        if (exponent < 0 || exponent >= coefficients.size()) return 0.0;
        return coefficients[exponent];
    }

    void setCoefficient(int exponent, double value) {
        if (exponent < 0) return;
        if (exponent >= coefficients.size()) {
            coefficients.resize(exponent + 1, 0.0);
        }
        coefficients[exponent] = value;
    }

    void print() const {
        int degree = getDegree();
        if (degree == -1) {
            cout << "0";
            return;
        }
        bool first = true;
        for (int i = 0; i <= degree; ++i) {
            if (coefficients[i] == 0.0) continue;
            if (!first && coefficients[i] > 0) cout << " + ";
            else if (coefficients[i] < 0) cout << " - ";
            if (i == 0 || abs(coefficients[i]) != 1) cout << abs(coefficients[i]);
            else if (first && coefficients[i] == -1) cout << "-";
            if (i > 0) cout << "x";
            if (i > 1) cout << "^" << i;
            first = false;
        }
        if (first) cout << "0";
    }

    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i < coefficients.size(); ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial operator+(const Polynomial& other) const {
        size_t max_size = max(coefficients.size(), other.coefficients.size());
        vector<double> result(max_size, 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] += other.coefficients[i];
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t max_size = max(coefficients.size(), other.coefficients.size());
        vector<double> result(max_size, 0.0);
        for (size_t i = 0; i < coefficients.size(); ++i) {
            result[i] += coefficients[i];
        }
        for (size_t i = 0; i < other.coefficients.size(); ++i) {
            result[i] -= other.coefficients[i];
        }
        return Polynomial(result);
    }
};