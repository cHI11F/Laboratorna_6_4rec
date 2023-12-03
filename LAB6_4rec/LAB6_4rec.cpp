#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;

void fillArrayRandom(double arr[], int size, int index = 0) {
    if (index < size) {
        arr[index] = rand() % 100 - 50;
        fillArrayRandom(arr, size, index + 1);
    }
}

void printArray(const double arr[], int size, int index = 0) {
    if (index < size) {
        cout << setw(4) << arr[index] << " ";
        printArray(arr, size, index + 1);
    }
    else {
        cout << endl;
    }
}

double productPositiveElements(const double arr[], int size, int index = 0) {
    if (index < size) {
        if (arr[index] > 0) {
            return arr[index] * productPositiveElements(arr, size, index + 1);
        }
        else {
            return productPositiveElements(arr, size, index + 1);
        }
    }
    else {
        return 1.0;
    }
}

double sumElementsBeforeMinimum(const double arr[], int size, double minElement, int index = 0) {
    if (index < size && arr[index] != minElement) {
        return arr[index] + sumElementsBeforeMinimum(arr, size, minElement, index + 1);
    }
    else {
        return 0.0;
    }
}

void orderEvenOddElements(double arr[], int size, int index = 0) {
    vector<double> evenElements;
    vector<double> oddElements;

    if (index < size) {
        if (index % 2 == 0) {
            evenElements.push_back(arr[index]);
        }
        else {
            oddElements.push_back(arr[index]);
        }

        orderEvenOddElements(arr, size, index + 1);
    }

    sort(evenElements.begin(), evenElements.end());
    sort(oddElements.begin(), oddElements.end());

    int i = 0;
    for (double evenElement : evenElements) {
        arr[i++] = evenElement;
    }
    for (double oddElement : oddElements) {
        arr[i++] = oddElement;
    }
}

int main() {
    int n;
    cout << "Array size: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid array size (should be greater than 0)" << endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(nullptr)));

    double* arr = new double[n];

    fillArrayRandom(arr, n);

    cout << "Array:" << endl;
    printArray(arr, n);

    double posProduct = productPositiveElements(arr, n);
    cout << "Product(P): " << posProduct << endl;

    double minElement = *min_element(arr, arr + n);
    double sumBeforeMin = sumElementsBeforeMinimum(arr, n, minElement);
    cout << "Sum(BM): " << sumBeforeMin << endl;

    orderEvenOddElements(arr, n);

    cout << "Ordered Array:" << endl;
    printArray(arr, n);

    delete[] arr;

    return 0;
}