#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int w, n;
    map<string, int> a;
    a["FB"] = 25;
    a["SQ"] = 30;
    a["MS"] = 50;
    a["SO"] = 60;
    a["GS"] = 75;
    a["TJ"] = 80;
    
    while(cin >> w >> n){
        map<string, int> mp;
        vector<string> b, c;
        for(int i = 0; i < n; ++ i){
            string name, jr;
            cin >> name >> jr;
            if(mp.count(name) == 0) c.push_back(name);
            mp[name] += a[jr];
        }
        for(auto a:c)
            if(mp[a] >= 100) b.push_back(a);
        cout << w << "-hafta";
        
        if(b.empty()) cout << " Hech kimning telefoni olib qo'yilmadi\n";
        else{
            bool p = false;
            for(auto a:b){
                if(p) cout << ",";
                else p = true;
                cout << " " << a;
            }
            cout << '\n';
        }
    }
    return 0;
}