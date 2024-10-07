#include <iostream>
#include <string>

class Overcoat {
private:
    std::string type;
    double price;

public:
    // Конструктор
    Overcoat(const std::string& type, double price) : type(type), price(price) {}

    // Перевантаження оператора "=="
    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    // Перевантаження оператора "="
    Overcoat& operator=(const Overcoat& other) {
        if (this == &other) {
            return *this; // Перевірка на самоприсвоєння
        }
        this->type = other.type;
        this->price = other.price;
        return *this;
    }

    // Перевантаження оператора ">"
    bool operator>(const Overcoat& other) const {
        if (this->type == other.type) {
            return this->price > other.price;
        }
        return false; // Повертає false, якщо типи не співпадають
    }

    // Метод для виведення інформації про об'єкт
    void print() const {
        std::cout << "Type: " << type << ", Price: " << price << std::endl;
    }
};

int main() {
    Overcoat coat1("Trench", 150.0);
    Overcoat coat2("Trench", 200.0);
    Overcoat coat3("Jacket", 100.0);

    // Перевірка на рівність типів
    if (coat1 == coat2) {
        std::cout << "Coat1 and Coat2 are of the same type." << std::endl;
    } else {
        std::cout << "Coat1 and Coat2 are of different types." << std::endl;
    }

    // Присвоєння одного об'єкта іншому
    coat3 = coat1;
    coat3.print();

    // Порівняння за ціною
    if (coat2 > coat1) {
        std::cout << "Coat2 is more expensive than Coat1." << std::endl;
    } else {
        std::cout << "Coat2 is not more expensive than Coat1." << std::endl;
    }

    return 0;
}