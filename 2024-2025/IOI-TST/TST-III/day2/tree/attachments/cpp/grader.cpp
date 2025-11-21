#include "tree.h"
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>

int main() {
    int n, r;
    assert(2 == scanf("%d %d", &n, &r));

    std::vector<int> p(n);
    for(int i = 0; i < n; ++i){
        assert(1 == scanf("%d", &p[i]));
    }

    int q;
    assert(1 == scanf("%d", &q));
    std::vector<long long> b(q);
    for(int i = 0; i < q; ++i) {
        assert(1 == scanf("%lld", &b[i]));
    }
    
    fclose(stdin);

    std::vector<long long> res = answer(n, r, p, q, b);
    
    if((int)res.size() != q) {
        printf("returned array is not size of q");
        return 0;
    }
    
    for(int i = 0; i < q; ++i) {
        printf("%lld\n", res[i]);
    }
    fclose(stdout);
    return 0;
}
