#include <stdio.h>
#include <math.h>

double f(double x) {
    return (x - 2) * (x - 2);
}

double ternarySearch(double a, double b, double delta) {
    while (1) {
        double c1 = a + (b - a) / 3;
        double c2 = a + 2 * (b - a) / 3;

        if (f(c1) > f(c2)) {
            a = c1;
        } else if (f(c1) < f(c2)) {
            b = c2;
        } else {
            if (c1 == c2) {
                return c1;
            } else {
                a = c1;
                b = c2;
            }
        }

        if (fabs(a - b) <= delta) {
            break;
        }
    }

    return (a + b) / 2;
}

int main() {
    double a = 0;   // Điểm bắt đầu của khoảng tìm kiếm
    double b = 4;   // Điểm kết thúc của khoảng tìm kiếm
    double delta = 0.0001;   // Ngưỡng dừng (độ chính xác)

    double result = ternarySearch(a, b, delta);

    printf("Giá trị tối ưu: %lf\n", result);
    printf("Giá trị hàm tại điểm tối ưu: %lf\n", f(result));

    return 0;
}
