#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void add(Node** head, string data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
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

void search(Node* head, string pat) {
    int m = pat.size();
    Node* temp = head;

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
    Node* HEAD = NULL;
    int num;

    cout << "Masukkan jumlah nama yang ingin ditambahkan: ";
    cin >> num;

    for (int i = 0; i < num; i++) {
        string name;
        cout << "Masukkan nama: ";
        cin >> name;
        add(&HEAD, name);
    }

    cout << "\nData dalam linked list: " << endl;
    display(HEAD);

    string pattern;
    cout << "\nMasukkan nama yang ingin dicari: ";
    cin >> pattern;

    bool found = false; 
    
    Node* temp = HEAD;
    while (temp != NULL) {
        int n = temp->data.size();
        int m = pattern.size();

        for (int i = 0; i <= n - m; i++) {
            if (temp->data.substr(i, m) == pattern) {
                found = true;
                break;
            }
        }

        if (found) {
            break; 
        }
        temp = temp->next;
    }

    if (found) {
        cout << "\nData yang sesuai dengan text '" << pattern << "' adalah: " << endl;
        search(HEAD, pattern);
    } else {
        cout << "Nama tidak ditemukan." << endl;
    }

    while (HEAD != NULL) {
        Node* temp = HEAD;
        HEAD = HEAD->next;
        delete temp;
    }

    return 0;
}
