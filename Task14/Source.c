#include <stdio.h>
#include <math.h>
#include <locale.h>

#define N 100 // Максимальный размер массива

// Функция заполнения (используем функцию из ЛБ8 - arcsin)
double* full_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        double x = -0.9 + (1.8 / (n - 1)) * i;
        ptr_array[i] = asin(x);
    }
    return ptr_array;
}

// Функция печати
int put_elements(double* ptr_array, int n) {
    printf("Массив: ");
    for (int i = 0; i < n; i++) {
        printf("%.4lf ", ptr_array[i]);
    }
    printf("\n");
    return 0;
}

// Функция обработки (например, удвоение каждого элемента)
double* calc_elements(double* ptr_array, int n) {
    for (int i = 0; i < n; i++) {
        ptr_array[i] *= 2;
    }
    return ptr_array;
}

int mainz1() {
    setlocale(LC_ALL, "RUS");
    double array[N];
    int size;

    printf("Введите размер массива (не более %d): ", N);
    scanf("%d", &size);

    if (size > 0 && size <= N) {
        full_elements(array, size);
        printf("Исходный массив:\n");
        put_elements(array, size);

        calc_elements(array, size);
        printf("Обработанный массив (x2):\n");
        put_elements(array, size);
    }
    else {
        printf("Некорректный размер массива!\n");
    }

    return 0;
}
// Функция суммы
double sum_elements(double* ptr_array, int begin, int end) {
    double sum = 0;
    for (int i = begin; i <= end; i++) {
        sum += ptr_array[i];
    }
    return sum;
}

// Функция поиска
int find_element(double* ptr_array, int n, double element) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] == element) {
            return i; // Нашли элемент, возвращаем индекс
        }
    }
    return -1; // Не нашли
}

/* Вызов в main:
   double s = sum_elements(array, 2, 5);
   int idx = find_element(array, size, 3.14);
*/

// Функция поиска первого элемента, не равного A
int find_first_not_equal(double* ptr_array, int n, double A) {
    for (int i = 0; i < n; i++) {
        if (ptr_array[i] != A) {
            return i; // Возвращаем порядковый номер (индекс)
        }
    }
    return -1; // Если все элементы равны A
}

int mainz2() {
    setlocale(LC_ALL, "RUS");
    int size;
    double A;

    printf("Введите размер массива: ");
    scanf("%d", &size);
    double array[size];

    printf("Введите элементы массива:\n");
    for (int i = 0; i < size; i++) {
        scanf("%lf", &array[i]);
    }

    printf("Введите значение A: ");
    scanf("%lf", &A);

    int result = find_first_not_equal(array, size, A);

    if (result != -1) {
        printf("Первый элемент, не равный %.2lf, находится на позиции %d (индекс).\n", A, result);
    }
    else {
        printf("Все элементы массива равны %.2lf.\n", A);
    }

    return 0;
}

int main() {

    mainz1();
    mainz2();

    return 0;
}