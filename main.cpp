#include <iostream>

class Flat {
private:
    double area; // площа квартири
    double price; // ціна квартири

public:
    // Конструктор за замовчуванням
    Flat() : area(0), price(0) {}

    // Конструктор з параметрами
    Flat(double a, double p) : area(a), price(p) {}

    // Перевантаження оператора "=="
    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }

    // Перевантаження оператора "="
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    // Перевантаження оператора ">"
    bool operator>(const Flat& other) const {
        return this->price > other.price;
    }

    // Метод для виведення інформації про квартиру
    void print() const {
        std::cout << "Area: " << area << ", Price: " << price << std::endl;
    }
};

int main() {
    Flat flat1(50.0, 100000.0);
    Flat flat2(60.0, 120000.0);
    Flat flat3(50.0, 90000.0);

    // Перевірка на рівність площ
    if (flat1 == flat3) {
        std::cout << "Flat1 and Flat3 have the same area." << std::endl;
    } else {
        std::cout << "Flat1 and Flat3 have different areas." << std::endl;
    }

    // Присвоювання одного об'єкта іншому
    flat2 = flat1;
    flat2.print();

    // Порівняння двох квартир за ціною
    if (flat1 > flat3) {
        std::cout << "Flat1 is more expensive than Flat3." << std::endl;
    } else {
        std::cout << "Flat1 is cheaper than or equal in price to Flat3." << std::endl;
    }

    return 0;
}