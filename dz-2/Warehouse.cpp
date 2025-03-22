#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include "Product.cpp" 

using namespace std;

enum WarehouseType { CENTER, WEST, EAST };

class Warehouse {
private:
    string id;
    WarehouseType type;
    float longitude;
    float latitude;
    int maxCapacity;
    int totalStock;
    vector<Product> products;

public:
    Warehouse(){}

    Warehouse(string i, WarehouseType t, float lon, float lat, int maxCap) {
        id = i;
        type = t;
        longitude = lon;
        latitude = lat;
        maxCapacity = maxCap;
        totalStock = 0;
    }

    Warehouse(const Warehouse& other) {
        id = other.id;
        type = other.type;
        longitude = other.longitude;
        latitude = other.latitude;
        maxCapacity = other.maxCapacity;
        totalStock = other.totalStock;
        products = other.products;
    }

    ~Warehouse() { products.clear(); }

    int calculateDistance(const Product& p) const {
        return abs(latitude - p.getPosLatitude()) + abs(longitude - p.getPosLongitude());
    }

    bool addProduct(const Product& p) {
        if (totalStock + p.getQuantity() > maxCapacity) return false;
        products.push_back(p);
        totalStock += p.getQuantity();
        return true;
    }

    bool removeProduct(int index) {
        if (index < 0 || index >= products.size()) return false;
        totalStock -= products[index].getQuantity();
        products.erase(products.begin() + index);
        return true;
    }

    void printProducts() const {
        cout << "Продукты:" << endl;
        for (size_t i = 0; i < products.size(); ++i) {
            products[i].print();
        }
    }

    void searchByDescription(const string& keyword) const {
        for (const auto& p : products) {
            if (p.getDescription().find(keyword) != string::npos) {
                p.print();
            }
        }
    }

    string getId() const { return id; }
    WarehouseType getType() const { return type; }
};
