#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Vector3D {
private:
    double x1, y1, z1;
    double x2, y2, z2;

public:
    // Конструктор без параметрів
    Vector3D()
        : x1(0), y1(0), z1(0),
          x2(0), y2(0), z2(0) {}

    // Параметризований конструктор
    Vector3D(double ax1, double ay1, double az1,
             double ax2, double ay2, double az2)
        : x1(ax1), y1(ay1), z1(az1),
          x2(ax2), y2(ay2), z2(az2) {}

    // Деструктор
    ~Vector3D() {
        cout << "Об'єкт Vector3D знищено.\n";
    }

    void input() {
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
    }

    void print(const string& title) const {
        cout << title << '\n';
        cout << "Початок: (" << x1 << "; " << y1 << "; " << z1 << ")\n";
        cout << "Кінець:  (" << x2 << "; " << y2 << "; " << z2 << ")\n";
        cout << "Компоненти: <"
             << x2 - x1 << "; "
             << y2 - y1 << "; "
             << z2 - z1 << ">\n";
        cout << "Довжина: " << fixed << setprecision(3)
             << length() << "\n\n";
    }

    double length() const {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double dz = z2 - z1;

        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    Vector3D operator+(const Vector3D& other) const {
        double ax = x2 - x1;
        double ay = y2 - y1;
        double az = z2 - z1;

        double bx = other.x2 - other.x1;
        double by = other.y2 - other.y1;
        double bz = other.z2 - other.z1;

        return Vector3D(
            0, 0, 0,
            ax + bx,
            ay + by,
            az + bz
        );
    }

    Vector3D operator-(const Vector3D& other) const {
        double ax = x2 - x1;
        double ay = y2 - y1;
        double az = z2 - z1;

        double bx = other.x2 - other.x1;
        double by = other.y2 - other.y1;
        double bz = other.z2 - other.z1;

        return Vector3D(
            0, 0, 0,
            ax - bx,
            ay - by,
            az - bz
        );
    }
};

int main() {
    cout << "Введіть координати початку та кінця першого вектора:\n";
    Vector3D a;
    a.input();

    cout << "Введіть координати початку та кінця другого вектора:\n";
    Vector3D b;
    b.input();

    cout << '\n';

    a.print("Вектор A:");
    b.print("Вектор B:");

    Vector3D sum = a + b;
    Vector3D difference = a - b;

    sum.print("A + B:");
    difference.print("A - B:");

    return 0;
}
