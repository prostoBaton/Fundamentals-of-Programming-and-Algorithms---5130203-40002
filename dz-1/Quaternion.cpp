#include <iostream>
#include <cmath>

class Quaternion {
public:
    double a, b, c, d;

    // конструкторы
    Quaternion() {
        a = 1;
        b = 0;
        c = 0;
        d = 0;
    }
    Quaternion(double a1, double b1, double c1, double d1) {
        a = a1;
        b = b1;
        c = c1;
        d = d1;
    }
    Quaternion(const Quaternion& other) : a(other.a), b(other.b), c(other.c), d(other.d) {
        a = other.getA();
        b = other.getB();
        c = other.getC();
        d = other.getD();
    }

    // геттеры
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
    double getD() const { return d; }

    // сеттеры
    void setA(double a1) { a = a1; }
    void setB(double b1) { b = b1; }
    void setC(double c1) { c = c1; }
    void setD(double d1) { d = d1; }

    // Базовые операции
    double norm() const { return sqrt(a * a + b * b + c * c + d * d); }
    Quaternion conjugate() const { return Quaternion(a, -b, -c, -d); }

    // печать кватерниона
    void print() const {
        std::cout << a << " + " << b << "i + " << c << "j + " << d << "k\n";
    }

    // норма кватерниона
    double norm() const {
        return sqrt(a * a + b * b + c * c + d * d);
    }

    // cопряжение
    Quaternion conjugate() const {
        return Quaternion(a, -b, -c, -d);
    }

    // нормализация
    Quaternion normalize() const {
        double n = norm();
        return Quaternion(a / n, b / n, c / n, d / n);
    }

    // инверсия
    Quaternion inverse() const {
        double n = pow(norm(), 2);
        Quaternion q = conjugate();
        return Quaternion(q.getA() / n, q.getB() / n, q.getC() / n, q.getD() / n );
    }
    // операторы класса
    Quaternion operator+(const Quaternion& other) const {
        return Quaternion(a + other.a, b + other.b, c + other.c, d + other.d);
    }

    Quaternion operator-(const Quaternion& other) const {
        return Quaternion(a - other.a, b - other.b, c - other.c, d - other.d);
    }

    Quaternion operator*(const Quaternion& other) const {
        double newA = a * other.a - b * other.b - c * other.c - d * other.d;
        double newB = a * other.b + b * other.a + c * other.d - d * other.c;
        double newC = a * other.c - b * other.d + c * other.a + d * other.b;
        double newD = a * other.d + b * other.c - c * other.b + d * other.a;
        return Quaternion(newA, newB, newC, newD);
    }

    Quaternion operator*(double scalar) const {
        return Quaternion(a * scalar, b * scalar, c * scalar, d * scalar);
    }

    Quaternion operator/(const Quaternion& other) const {
        return *this * other.inverse();
    }
};

// глобальные операции
Quaternion operator*(double scalar, const Quaternion& q) {
    return q * scalar;
}

double dotProduct(const Quaternion& q1, const Quaternion& q2) {
    return q1.getA() * q2.getA() + q1.getB() * q2.getB() + q1.getC() * q2.getC() + q1.getD() * q2.getD();
}

double euclideanDistance(const Quaternion& q1, const Quaternion& q2) {
    double da = q1.getA() - q2.getA();
    double db = q1.getB() - q2.getB();
    double dc = q1.getC() - q2.getC();
    double dd = q1.getD() - q2.getD();
    return sqrt(da * da + db * db + dc * dc + dd * dd);
}

double chebyshevNorm(const Quaternion& q1, const Quaternion& q2) {
    double diffA = fabs(q1.getA() - q2.getA());
    double diffB = fabs(q1.getB() - q2.getB());
    double diffC = fabs(q1.getC() - q2.getC());
    double diffD = fabs(q1.getD() - q2.getD());
    return std::max({ diffA, diffB, diffC, diffD });
}