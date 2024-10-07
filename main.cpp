#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int calculateGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw "Denominator cannot be zero";
        }
        simplify();
    }

    // Operator overloading for addition
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Operator overloading for subtraction
    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Operator overloading for multiplication
    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    // Operator overloading for division
    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw "Cannot divide by zero";
        }
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    // Friend function to output the fraction
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

int main() {
    try {
        Fraction f1(1, 2);
        Fraction f2(3, 4);

        Fraction resultAdd = f1 + f2;
        Fraction resultSub = f1 - f2;
        Fraction resultMul = f1 * f2;
        Fraction resultDiv = f1 / f2;

        std::cout << "Addition: " << resultAdd << std::endl;
        std::cout << "Subtraction: " << resultSub << std::endl;
        std::cout << "Multiplication: " << resultMul << std::endl;
        std::cout << "Division: " << resultDiv << std::endl;
    } catch (const char* e) {
        std::cerr << "Error: " << e << std::endl;
    }


    return 0;
}