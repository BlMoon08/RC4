#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// Thuật toán KSA - Key Scheduling Algorithm
void RC4_KSA(vector<int>& S, const vector<int>& K) {
    int j = 0;
    int n = S.size();
    int keylen = K.size();

    for (int i = 0; i < n; i++) {
        j = (j + S[i] + K[i % keylen]) % n;
        swap(S[i], S[j]);
    }
}

int main() {
    // ===== Bước 1: Khởi tạo S =====
    int n;
    cout << "Nhap kich thuoc S (vi du: 10 hoac 256): ";
    cin >> n;
    cin.ignore();

    vector<int> S(n);
    for (int i = 0; i < n; i++) S[i] = i;

    // ===== Bước 2: Nhap khoa K =====
    cout << "Nhap khoa K (cac so cach nhau boi dau cach, vi du: 1 2 3 6): ";
    string inputKey;
    getline(cin, inputKey);

    // Tách key thành vector<int>
    vector<int> K;
    int num;
    stringstream ss(inputKey);
    while (ss >> num) K.push_back(num);

    // ===== Bước 3: Thực hiện hoán vị theo KSA =====
    RC4_KSA(S, K);

    // ===== Bước 4: In ra Initial permutation of S =====
    cout << "\nInitial permutation of S:" << endl;
    for (int i = 0; i < n; i++) {
        cout << S[i] << " ";
    }
    cout << endl;

    return 0;
}

