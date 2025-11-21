#include "stbz.h"
#include <vector>
#include <cassert>
#include <cstdio>

int main() {
    int n;
    assert(1 == scanf("%d", &n));
    
    std::vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) assert(1 == scanf("%d", &a[i]));
    for(int i = 0; i < n; ++i) assert(1 == scanf("%d", &b[i]));
    init(n, a, b);

    int q;
    assert(1 == scanf("%d", &q));
    std::vector<int> answer;
    for(int s = 0; s < q; ++s) {
        int t;
        assert(1 == scanf("%d", &t));
        assert(t == 0 || t == 1);
        if(t == 0) {
            int l, r;
            assert(2 == scanf("%d %d", &l, &r));
            answer.push_back(query(l, r));
        } else {
            int i, c, d;
            assert(3 == scanf("%d %d %d", &i, &c, &d));
            update(i, c, d);
        }
    }
    
    fclose(stdin);

    for(int x: answer) {
        printf("%d\n", x);
    }

    fclose(stdout);
    return 0;
}
