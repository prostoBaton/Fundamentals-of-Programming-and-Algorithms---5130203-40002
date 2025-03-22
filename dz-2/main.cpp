#include "VectPolynomial.cpp"

using namespace std; 

int main() {
    VectPolynomial V1(6), V2(6);

    V1[0] = Polynomial({ 1, 2 });        // 1 + 2x
    V1[1] = Polynomial({ 0, 1, 1 });     // x + x^2
    V1[2] = Polynomial({ 2 });           // 2
    V1[3] = Polynomial({ 1, 0, 3 });     // 1 + 3x^2
    V1[4] = Polynomial({ 0, 1 });        // x
    V1[5] = Polynomial({ 1, 1, 1 });     // 1 + x + x^2

    V2[0] = Polynomial({ 2, 1 });        // 2 + x
    V2[1] = Polynomial({ 1, 0, 1 });     // 1 + x^2
    V2[2] = Polynomial({ 1, 2 });        // 1 + 2x
    V2[3] = Polynomial({ 0, 1, 1 });     // x + x^2
    V2[4] = Polynomial({ 3 });           // 3
    V2[5] = Polynomial({ 1, 0, 2 });     // 1 + 2x^2

    VectPolynomial V_out(6);
    for (size_t i = 0; i < V1.size(); ++i) {
        if (i % 2 == 1) {
            V_out[i] = V1[i] + V2[i];
        }
        else {
            V_out[i] = V1[i] - V2[i];
        }
    }

    cout << "V_out:" << endl;
    V_out.print();

    double x = 2.0;
    cout << "\nВычисление V_out при x = " << x << ":\n";
    for (size_t i = 0; i < V_out.size(); ++i) {
        cout << "V_out[" << i << "](" << x << ") = " << V_out[i].evaluate(x) << endl;
    }

}