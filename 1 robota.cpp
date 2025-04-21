#include <iostream>
#include <cmath>
#include <stdexcept>

class Vector3D {
private:
    double x, y, z;

public:
    Vector3D() : x(0), y(0), z(0) {}
    Vector3D(const Vector3D& other) : x(other.x), y(other.y), z(other.z) {}
    Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    Vector3D operator+(const Vector3D& other) const {
        return Vector3D(x + other.x, y + other.y, z + other.z);
    }

    Vector3D operator-(const Vector3D& other) const {
        return Vector3D(x - other.x, y - other.y, z - other.z);
    }

    Vector3D& operator+=(const Vector3D& other) {
        x += other.x; y += other.y; z += other.z;
        return *this;
    }

    Vector3D& operator-=(const Vector3D& other) {
        x -= other.x; y -= other.y; z -= other.z;
        return *this;
    }

    double dot(const Vector3D& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    Vector3D cross(const Vector3D& other) const {
        return Vector3D(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    Vector3D operator*(double scalar) const {
        return Vector3D(x * scalar, y * scalar, z * scalar);
    }

    Vector3D operator/(double scalar) const {
        if (scalar == 0) {
            throw std::runtime_error("Division by zero!");
        }
        return Vector3D(x / scalar, y / scalar, z / scalar);
    }

    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }

    double length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vector3D normalize() const {
        double len = length();
        if (len == 0) throw std::runtime_error("Cannot normalize zero vector.");
        return *this / len;
    }

    bool isZero() const {
        return x == 0 && y == 0 && z == 0;
    }

    void input(const std::string& name = "вектор") {
        std::cout << "Введи координати для " << name << " (x y z): ";
        std::cin >> x >> y >> z;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }
};

// Дружелюбное меню
void showMenu() {
    std::cout << "\n=== Меню операцій з векторами ===\n";
    std::cout << "1. Додавання (a + b)\n";
    std::cout << "2. Віднімання (a - b)\n";
    std::cout << "3. Скалярний добуток (a . b)\n";
    std::cout << "4. Векторний добуток (a x b)\n";
    std::cout << "5. Масштабування вектора a\n";
    std::cout << "6. Нормалізація вектора a\n";
    std::cout << "7. Довжина вектора a\n";
    std::cout << "8. Вивід зворотного вектора -a\n";
    std::cout << "9. Вихід\n";
    std::cout << "Оберіть опцію: ";
}

int main() {
    Vector3D a, b;
    std::cout << "=== Робота з векторами ===" << std::endl;

    a.input("вектора a");
    b.input("вектора b");

    int choice;
    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "a + b = " << (a + b) << std::endl;
                break;
            case 2:
                std::cout << "a - b = " << (a - b) << std::endl;
                break;
            case 3:
                std::cout << "a . b = " << a.dot(b) << std::endl;
                break;
            case 4:
                std::cout << "a x b = " << a.cross(b) << std::endl;
                break;
            case 5: {
                double k;
                std::cout << "Введи скаляр: ";
                std::cin >> k;
                std::cout << "a * " << k << " = " << (a * k) << std::endl;
                break;
            }
            case 6:
                try {
                    std::cout << "Нормалізований a = " << a.normalize() << std::endl;
                } catch (const std::exception& e) {
                    std::cout << "Помилка: " << e.what() << std::endl;
                }
                break;
            case 7:
                std::cout << "|a| = " << a.length() << std::endl;
                break;
            case 8:
                std::cout << "-a = " << -a << std::endl;
                break;
            case 9:
                std::cout << "До зустрічі!" << std::endl;
                break;
            default:
                std::cout << "Невірна опція. Спробуй ще раз." << std::endl;
        }

    } while (choice != 9);

    return 0;
}
