#include <iostream>
using namespace std;

void print(int a[], int first, int last) {
    for (int i = first; i <= last; i++)
        cout << a[i] << " ";
    cout << endl;
}

void selection_sort2(int a[], int first, int last) {
    // Điều kiện dừng: nếu chỉ còn 1 phần tử hoặc không có phần tử nào
    if (first >= last) return;

    // Tìm vị trí phần tử nhỏ nhất trong đoạn từ first đến last
    int min_idx = first;
    for (int j = first + 1; j <= last; j++) {
        if (a[j] < a[min_idx]) {
            min_idx = j;
        }
    }

    // Hoán đổi phần tử nhỏ nhất lên đầu đoạn (vị trí first)
    int tmp = a[first];
    a[first] = a[min_idx];
    a[min_idx] = tmp;

    // Đệ quy cho phần còn lại của mảng
    selection_sort2(a, first + 1, last);
}

int main() {
    int a[] = {22, 5, 1, 18, 12, 4, 9, 6, 11};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Before sorting:" << endl;
    print(a, 0, n - 1);

    selection_sort2(a, 0, n - 1);

    cout << "After sorting:" << endl;
    print(a, 0, n - 1);

    return 0;
}