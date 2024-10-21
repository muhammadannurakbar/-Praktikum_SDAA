#include <iostream>
#include <cmath>
using namespace std;

struct NodeString {
    string data;
    NodeString* next;
};

struct NodeInt {
    int data;
    NodeInt* next;
};

void displayString(NodeString* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void addString(NodeString** head, string data) {
    NodeString* newNode = new NodeString;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void displayInt(NodeInt* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void addInt(NodeInt** head, int data) {
    NodeInt* newNode = new NodeInt;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

int fibSearch(NodeInt* head, int x) {
    int n = 0;
    NodeInt* temp = head;
    while (temp != NULL) { 
        n++;
        temp = temp->next;
    }

    int fibMMm2 = 0;  
    int fibMMm1 = 1;  
    int fibM = fibMMm2 + fibMMm1; 

    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    NodeInt* current = head;
    NodeInt* prev = head;

    while (fibM > 1) {
        int i = min(offset + fibMMm2, n - 1);
        
        int step = i - offset;
        for (int k = 0; k < step && current != NULL; k++) {
            prev = current;
            current = current->next;
        }

        if (current == NULL) return -1; 

        if (current->data < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        } else if (current->data > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            current = prev;
        } else {
            return i;
        }
    }

    if (fibMMm1 && current->data == x) {
        return offset + 1;
    }

    return -1;
}

int jumpSearch(NodeInt* head, int x) {
    int n = 0;
    NodeInt* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    int step = sqrt(n);
    int prev = 0;
    temp = head;
    NodeInt* current = head;

    while (current->data < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            return -1;
        }

        for (int i = prev; i < step && i < n; i++) {
            current = current->next;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        if (current->data == x) {
            return i;
        }
        current = current->next;
    }

    return -1;
}

const int NO_OF_CHARS = 256;

void badCharHeuristic(string str, int size, int badChar[NO_OF_CHARS]) {
    for (int i = 0; i < NO_OF_CHARS; i++) {
        badChar[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        badChar[(int)str[i]] = i;
    }
}

void searchString(NodeString* head, string pat) {
    int m = pat.size();
    NodeString* temp = head;

    while (temp != NULL) {
        int n = temp->data.size();  
        int badChar[NO_OF_CHARS];

        badCharHeuristic(pat, m, badChar);

        int s = 0;

        while (s <= (n - m)) {
            int j = m - 1;

            while (j >= 0 && pat[j] == temp->data[s + j]) {
                j--;
            }

            if (j < 0) {
                cout << temp->data << endl;
                break; 
            } else {
                s += max(1, j - badChar[(int)temp->data[s + j]]);
            }
        }

        temp = temp->next; 
    }
}

int main() {
    NodeInt* headInt = NULL;
    NodeString* headString = NULL;
    int choice;

    cout << "Pilih tipe data yang ingin digunakan:\n";
    cout << "1. Integer\n";
    cout << "2. String\n";
    cout << "Pilihan: ";
    cin >> choice;

    if (choice == 1) {
        int num;
        cout << "Masukkan jumlah elemen integer: ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            int data;
            cout << "Masukkan elemen: ";
            cin >> data;
            addInt(&headInt, data);
        }

        cout << "\nData dalam linked list: " << endl;
        displayInt(headInt);

        int target;
        cout << "\nMasukkan elemen yang ingin dicari: ";
        cin >> target;

        cout << "Pilih metode pencarian:\n";
        cout << "1. Fibonacci Search\n";
        cout << "2. Jump Search\n";
        cout << "Pilihan: ";
        cin >> choice;

        int result = -1;
        if (choice == 1) {
            result = fibSearch(headInt, target);
        } else if (choice == 2) {
            result = jumpSearch(headInt, target);
        }

        if (result != -1) {
            cout << "Elemen ditemukan pada index: " << result << endl;
        } else {
            cout << "Elemen tidak ditemukan." << endl;
        }
    } else if (choice == 2) {
        int num;
        cout << "Masukkan jumlah elemen string: ";
        cin >> num;
        for (int i = 0; i < num; i++) {
            string data;
            cout << "Masukkan elemen: ";
            cin >> data;
            addString(&headString, data);
        }

        cout << "\nData dalam linked list: " << endl;
        displayString(headString);

        string pattern;
        cout << "\nMasukkan elemen yang ingin dicari: ";
        cin >> pattern;

        cout << "Elemen yang sesuai: " << endl;
        searchString(headString, pattern);
    }

    return 0;
}
