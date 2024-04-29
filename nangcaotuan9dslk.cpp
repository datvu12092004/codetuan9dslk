#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int m) {
    list<int> survivors;

    for (int i = 1; i <= n; ++i)
        survivors.push_back(i);

    auto kill = survivors.begin();
    while (survivors.size() > 1) {
        for (int count = 0; count < m; ++count) {
            kill++;
            if (kill == survivors.end())
                kill = survivors.begin();
        }

        auto next = ++kill;
        if (next == survivors.end())
            next = survivors.begin();

        --kill;
        survivors.erase(kill);
        kill = next;
        if (kill == survivors.end())
            kill = survivors.begin();
    }

    return *(survivors.begin());
}

int main() {
    int n, m;
    cout << "Nhap so nguoi (N): ";
    cin >> n;
    cout << "Nhap so nguoi bi loai (M): ";
    cin >> m;

    cout << "Nguoi chien thang cuoi cung la: " << josephus(n, m) << endl;

    return 0;
}
