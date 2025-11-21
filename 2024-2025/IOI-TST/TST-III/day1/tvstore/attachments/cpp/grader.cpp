#include "tvstore.h"
#include <cassert>
#include <cstdio>
#include <vector>

int main() {
	int n;
	assert(1 == scanf("%d", &n));

    std::vector<int> w(n), h(n), c(n);
    for (int i = 0; i < n; i++){
        assert(3 == scanf("%d %d %d", &w[i], &h[i], &c[i]));
    }

    int q;
	assert(1 == scanf("%d", &q));

    std::vector<int> x(q), y(q), b(q);
    for (int j = 0; j < q; j++){
        assert(3 == scanf("%d %d %d", &x[j], &y[j], &b[j]));
    }

	std::vector<int> res = best_tv(n, w, h, c, q, x, y, b);

    for (int j = 0; j < q; j++){
        printf("%d\n", res[j]);
    }
    printf("\n");

	fclose(stdout);
	return 0;
}
