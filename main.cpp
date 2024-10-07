#include <iostream>

class Flat {
private:
    double area; // ����� ��������
    double price; // ���� ��������

public:
    // ����������� �� �������������
    Flat() : area(0), price(0) {}

    // ����������� � �����������
    Flat(double a, double p) : area(a), price(p) {}

    // �������������� ��������� "=="
    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }

    // �������������� ��������� "="
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    // �������������� ��������� ">"
    bool operator>(const Flat& other) const {
        return this->price > other.price;
    }

    // ����� ��� ��������� ���������� ��� ��������
    void print() const {
        std::cout << "Area: " << area << ", Price: " << price << std::endl;
    }
};

int main() {
    Flat flat1(50.0, 100000.0);
    Flat flat2(60.0, 120000.0);
    Flat flat3(50.0, 90000.0);

    // �������� �� ������ ����
    if (flat1 == flat3) {
        std::cout << "Flat1 and Flat3 have the same area." << std::endl;
    } else {
        std::cout << "Flat1 and Flat3 have different areas." << std::endl;
    }

    // ������������ ������ ��'���� ������
    flat2 = flat1;
    flat2.print();

    // ��������� ���� ������� �� �����
    if (flat1 > flat3) {
        std::cout << "Flat1 is more expensive than Flat3." << std::endl;
    } else {
        std::cout << "Flat1 is cheaper than or equal in price to Flat3." << std::endl;
    }

    return 0;
}