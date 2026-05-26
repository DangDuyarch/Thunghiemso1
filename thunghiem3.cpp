#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct File {
    string name;
    double size; 
    long timestamp; // Giả sử số càng lớn là file càng mới
};

struct Node {
    File data;
    Node* next;
};

// Hàm chèn file theo thứ tự thời gian (Thao tác 2)
void insertByTime(Node*& head, File newFileData) {
    Node* newNode = new Node{newFileData, nullptr};
    if (head == nullptr || newFileData.timestamp < head->data.timestamp) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr && curr->next->data.timestamp < newFileData.timestamp) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

// Hàm tính tổng kích thước (Thao tác 3)
double getTotalSize(Node* head) {
    double total = 0;
    while (head) {
        total += head->data.size;
        head = head->next;
    }
    return total;
}

// Hàm xóa file nhỏ nhất (Thao tác 4)
void removeSmallest(Node*& head) {
    if (!head) return;
    Node *minNode = head, *minPrev = nullptr, *curr = head, *prev = nullptr;
    while (curr) {
        if (curr->data.size < minNode->data.size) {
            minNode = curr;
            minPrev = prev;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "--- Dang loai bo file nho nhat: " << minNode->data.name << " (" << minNode->data.size << "GB)" << endl;
    if (minNode == head) head = head->next;
    else minPrev->next = minNode->next;
    delete minNode;
}

void printList(Node* head) {
    while (head) {
        cout << "[" << head->data.name << " | Time: " << head->data.timestamp << " | Size: " << head->data.size << "GB] -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* myFolder = nullptr;

    // 1. Demo Copy-Paste (Chèn file)
    insertByTime(myFolder, {"BaoCao.docx", 15.5, 1001});
    insertByTime(myFolder, {"Phim_Hay.mp4", 20.0, 1005});
    insertByTime(myFolder, {"Anh_Ky_Niem.jpg", 2.5, 1003});

    cout << "Danh sach file hien tai (theo thoi gian):" << endl;
    printList(myFolder);

    // 2. Tinh tong kich thuoc
    double currentSize = getTotalSize(myFolder);
    cout << "\nTong dung luong hien tai: " << currentSize << " GB" << endl;

    // 3. Sao luu vao USB 32GB
    const double USB_CAPACITY = 32.0;
    if (currentSize > USB_CAPACITY) {
        cout << "Canh bao: Dung luong vuot qua 32GB! Bat dau giai phong..." << endl;
        while (getTotalSize(myFolder) > USB_CAPACITY) {
            removeSmallest(myFolder);
        }
    }

    cout << "\nDanh sach file sau khi toi uu de backup vao USB:" << endl;
    printList(myFolder);
    cout << "Tong dung luong cuoi cung: " << getTotalSize(myFolder) << " GB" << endl;

    return 0;
}