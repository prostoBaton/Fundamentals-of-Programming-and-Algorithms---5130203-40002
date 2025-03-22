#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

class Product {
private:
    string barcode;
    string description;
    float price;
    int quantity;
    float posLongitude;
    float posLatitude;

    void generateBarcode() {
        srand(time(nullptr));
        string part1 = "460";
        string part2 = to_string(1000 + (rand() % 9) * 1000);
        string part3 = to_string(rand() % 900000);
        barcode = part1 + part2 + part3;
    }

public:
    Product(){
        generateBarcode();
    }

    Product(string desc, float p, int q, float lon, float lat){
        description = desc;
        price = p;
        quantity = q;
        posLongitude = lon;
        posLatitude = lat;
        generateBarcode();
    }

    Product(const Product& other) {
        barcode = other.barcode;
        description = other.description;
        price = other.price;
        quantity = other.quantity;
        posLongitude = other.posLongitude;
        posLatitude = other.posLatitude;
    }

    string getBarcode() const { return barcode; }
    string getDescription() const { return description; }
    float getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    float getPosLongitude() const { return posLongitude; }
    float getPosLatitude() const { return posLatitude; }

    void setLongitude(float lon) { posLongitude = lon; }
    void setLatitude(float lat) { posLatitude = lat; }
    void setDescription(const string& desc) { description = desc; }
    void setPrice(float p) { price = p; }
    void setQuantity(int q) { quantity = q; }


    void print() const {
        cout << "Штрих-код: " << barcode <<  << endl;
        cout << "Описание: " << description << endl;
        cout << "Цена: " << price << " RUB" << endl;
        cout << "Количество: " << quantity << endl;
        cout << "Координаты: (" << posLongitude << ", " << posLatitude << ")"<< endl;
    }
};