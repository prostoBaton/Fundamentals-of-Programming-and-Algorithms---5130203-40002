#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Ellipse {
public:
    double h, k;
    double a, b;
    bool majorAxisX; // true - ось X, false - ось Y

    // конструкторы
    Ellipse() {
        h = 0;
        k = 0;
    }

    Ellipse(double h1, double k1, double a1, double b1, bool isMajorX) {
        if (a1 < b1)
            swap(a1, b1); // a >= b
        a = a1;
        b = b1;
        h = h1;
        k = k1;
        majorAxisX = isMajorX;
    }

    Ellipse(const Ellipse& other) {
        a = other.getA();
        b = other.getB();
        h = other.getH();
        k = other.getK();
        majorAxisX = other.isMajorAxisX();
    }

    // геттеры
    double getH() const { return h; }
    double getK() const { return k; }
    double getA() const { return a; }
    double getB() const { return b; }
    bool isMajorAxisX() const { return majorAxisX; }

    // сеттеры
    void setH(double newH) { h = newH; }
    void setK(double newK) { k = newK; }
    void setMajorAxis(bool isMajorX) { majorAxisX = isMajorX; }

    void setA(double newA) {
        if (newA < b) swap(newA, b);
        a = newA;
    }

    void setB(double newB) {
        if (a < newB) swap(a, newB);
        b = newB;
    }

    // гиперпараметр
    double hyperParam() const {
        return sqrt(a * a - b * b);
    }

    // получение вершин
    vector<pair<double, double>> getVertices() const {
        if (majorAxisX) {
            return { {h - a, k}, {h + a, k} };
        }
        else {
            return { {h, k - a}, {h, k + a} };
        }
    }

    // получение фокусов
    vector<pair<double, double>> getFocus() const {
        double c = hyperParam();
        if (majorAxisX) {
            return { {h - c, k}, {h + c, k} };
        }
        else {
            return { {h, k - c}, {h, k + c} };
        }
    }

    // получение длины фокальной хорды и эксцентриситета
    double getFocalChord() const { return 2 * b * b / a; }
    double getEccentricity() const { return hyperParam() / a; }

    // печать уравнения
    void printEquation() const {
        cout << "(x - " << h << ")^2 / ";

        if (majorAxisX) {
            cout << a * a;
        }
        else {
            cout << b * b;
        }

        cout << " + (y - " << k << ")^2 / ";

        if (majorAxisX) {
            cout << b * b;
        }
        else {
            cout << a * a;
        }

        cout << " = 1" << endl;
    }

    // проверка положения точки
    string checkPoint(double x, double y) const {
        double termX, termY;

        if (majorAxisX) {
            termX = pow(x - h, 2) / (a * a);
        }
        else {
            termX = pow(x - h, 2) / (b * b);
        }

        if (majorAxisX) {
            termY = pow(y - k, 2) / (b * b);
        }
        else {
            termY = pow(y - k, 2) / (a * a);
        }

        double total = termX + termY;

        if (total < 1) {
            return "Внутри элипса";
        }
        else if (total == 1) {
            return "На элипсе";
        }
        else {
            return "Снаружи элипса";
        }
    }

    // периметр
    double perimeter() const {
        return M_PI * (3 * (a + b) - sqrt((3 * a + b) * (a + 3 * b)));
    }

    // площадь
    double area() const { return M_PI * a * b; }

    // вычисление второй координаты
    vector<double> calcOtherCoordinate(double coord, bool isXGiven) const {
        vector<double> result;
        double term;

        if (majorAxisX) {
            if (isXGiven) {
                term = 1 - pow(coord - h, 2) / (a * a);
                if (term < 0)
                    return result;
                term = b * sqrt(term);
                result.push_back(k + term);
                result.push_back(k - term);
            }
            else {
                term = 1 - pow(coord - k, 2) / (b * b);
                if (term < 0)
                    return result;
                term = a * sqrt(term);
                result.push_back(h + term);
                result.push_back(h - term);
            }
        }
        else {
            if (isXGiven) {
                term = 1 - pow(coord - h, 2) / (b * b);
                if (term < 0)
                    return result;
                term = a * sqrt(term);
                result.push_back(k + term);
                result.push_back(k - term);
            }
            else {
                term = 1 - pow(coord - k, 2) / (a * a);
                if (term < 0)
                    return result;
                term = b * sqrt(term);
                result.push_back(h + term);
                result.push_back(h - term);
            }
        }

        return result;
    }
};