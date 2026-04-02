#include <iostream>

using namespace std;

// Định nghĩa cấu trúc của một Node
struct Node {
    int data;
    Node* next;
};

// Hàm tạo một Node mới
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Hàm thêm vào cuối danh sách
void insertAtTail(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Hàm xóa node cuối (Trọng tâm bạn cần test)
void deleteAtTail(Node*& head) {
    if (head == nullptr) {
        cout << "Danh sach rong, khong co gi de xoa!" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Da xoa node duy nhat. Danh sach hien tai rong." << endl;
        return;
    }

    Node* temp = head;
    // Duyệt đến node kế cuối
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;    // Giải phóng node cuối
    temp->next = nullptr; // Cập nhật node kế cuối trỏ vào NULL
    cout << "Da xoa node cuoi cung." << endl;
}

// Hàm in danh sách
void printList(Node* head) {
    if (head == nullptr) {
        cout << "Danh sach trong!" << endl;
        return;
    }
    Node* temp = head;
    cout << "Danh sach: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // 1. Thêm một vài phần tử để test
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    
    cout << "--- Khoi tao danh sach ---" << endl;
    printList(head);

    // 2. Test xóa node cuối lần 1
    cout << "\n--- Thuc hien xoa node cuoi ---" << endl;
    deleteAtTail(head);
    printList(head);

    // 3. Test xóa node cuối lần 2
    deleteAtTail(head);
    printList(head);

    // 4. Them lai de test
    cout << "\n--- Them phan tu 99 vao cuoi ---" << endl;
    insertAtTail(head, 99);
    printList(head);

    // Giải phóng bộ nhớ còn lại trước khi kết thúc (tốt cho thực hành)
    while (head != nullptr) {
        deleteAtTail(head);
    }

    cout << "\nChuong trinh ket thuc. Nhan Enter de thoat...";
    cin.ignore();
    return 0;
}