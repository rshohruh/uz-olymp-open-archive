#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<pair<char, int>> evenMul, oddAdd, other;

    for (int i = 0; i < n; ++i) {
        char op;
        int val;
        cin >> op >> val;

        if (op == '*' && val % 2 == 0) {
            evenMul.insert({op, val});
        } else if (op == '+' && val % 2 == 1) {
            oddAdd.insert({op, val});
        } else {
            other.insert({op, val});
        }
    }

    int x;
    cin >> x;

    if (evenMul.size() == 1 && oddAdd.size() % 2 == 1) {
        cout << 1 << "\n";
        auto it = evenMul.begin();
        cout << it->first << " " << it->second << "\n";

        while (!oddAdd.empty() || !other.empty()) {
            char c;
            int y;
            cin >> c >> y;

            if (oddAdd.count({c, y})) oddAdd.erase(oddAdd.find({c, y}));
            else other.erase(other.find({c, y}));

            if (!oddAdd.empty()) {
                auto p = oddAdd.begin();
                cout << p->first << " " << p->second << "\n";
                oddAdd.erase(p);
            } else if (!other.empty()) {
                auto p = other.begin();
                cout << p->first << " " << p->second << "\n";
                other.erase(p);
            }
        }
    }
    else if (evenMul.empty() && (oddAdd.size() + x) % 2 == 1) {
        cout << 1 << "\n";

        if (!oddAdd.empty()) {
            auto p = oddAdd.begin();
            cout << p->first << " " << p->second << "\n";
            oddAdd.erase(p);
        } else if (!other.empty()) {
            auto p = other.begin();
            cout << p->first << " " << p->second << "\n";
            other.erase(p);
        }

        while (!oddAdd.empty() || !other.empty()) {
            char c;
            int y;
            cin >> c >> y;

            if (oddAdd.count({c, y})) oddAdd.erase(oddAdd.find({c, y}));
            else other.erase(other.find({c, y}));

            if (!oddAdd.empty()) {
                auto p = oddAdd.begin();
                cout << p->first << " " << p->second << "\n";
                oddAdd.erase(p);
            } else if (!other.empty()) {
                auto p = other.begin();
                cout << p->first << " " << p->second << "\n";
                other.erase(p);
            }
        }
    }
    else {
        cout << 2 << "\n";

        while (!oddAdd.empty() || !evenMul.empty() || !other.empty()) {
            char c;
            int y;
            cin >> c >> y;

            if (oddAdd.count({c, y})) oddAdd.erase(oddAdd.find({c, y}));
            else if (other.count({c, y})) other.erase(other.find({c, y}));
            else evenMul.erase(evenMul.find({c, y}));

            if (oddAdd.size() % 2 == 1 && !oddAdd.empty()) {
                auto p = oddAdd.begin();
                cout << p->first << " " << p->second << "\n";
                oddAdd.erase(p);
            } else if (!evenMul.empty()) {
                auto p = evenMul.begin();
                cout << p->first << " " << p->second << "\n";
                evenMul.erase(p);
            } else if (!other.empty()) {
                auto p = other.begin();
                cout << p->first << " " << p->second << "\n";
                other.erase(p);
            }
        }
    }

    return 0;
}
