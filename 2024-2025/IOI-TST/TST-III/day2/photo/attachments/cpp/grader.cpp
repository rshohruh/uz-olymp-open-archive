#include "photo.h"
#include <cassert>
#include <cstdio>
#include <vector>

int main() {
	int k, n;
	assert(2 == scanf("%d %d", &k, &n));

    std::vector<int> a(n);
    for (int i = 0; i < n; i++){
        assert(1 == scanf("%d", &a[i]));
    }

    int q;
    assert(1 == scanf("%d", &q));

    std::vector<int> l(q), r(q);
    for (int j = 0; j < q; j++){
        assert(2 == scanf("%d %d", &l[j], &r[j]));
    }

	init(k, n, a);

    for (int j = 0; j < q; j++){
        int res = query(l[j], r[j]);
        printf("%d\n", res);
    }

	return 0;
}
