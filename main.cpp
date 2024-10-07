#include <iostream>
#include <string>

class Overcoat {
private:
    std::string type;
    double price;

public:
    // �����������
    Overcoat(const std::string& type, double price) : type(type), price(price) {}

    // �������������� ��������� "=="
    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    // �������������� ��������� "="
    Overcoat& operator=(const Overcoat& other) {
        if (this == &other) {
            return *this; // �������� �� �������������
        }
        this->type = other.type;
        this->price = other.price;
        return *this;
    }

    // �������������� ��������� ">"
    bool operator>(const Overcoat& other) const {
        if (this->type == other.type) {
            return this->price > other.price;
        }
        return false; // ������� false, ���� ���� �� ����������
    }

    // ����� ��� ��������� ���������� ��� ��'���
    void print() const {
        std::cout << "Type: " << type << ", Price: " << price << std::endl;
    }
};

int main() {
    Overcoat coat1("Trench", 150.0);
    Overcoat coat2("Trench", 200.0);
    Overcoat coat3("Jacket", 100.0);

    // �������� �� ������ ����
    if (coat1 == coat2) {
        std::cout << "Coat1 and Coat2 are of the same type." << std::endl;
    } else {
        std::cout << "Coat1 and Coat2 are of different types." << std::endl;
    }

    // ��������� ������ ��'���� ������
    coat3 = coat1;
    coat3.print();

    // ��������� �� �����
    if (coat2 > coat1) {
        std::cout << "Coat2 is more expensive than Coat1." << std::endl;
    } else {
        std::cout << "Coat2 is not more expensive than Coat1." << std::endl;
    }

    return 0;
}