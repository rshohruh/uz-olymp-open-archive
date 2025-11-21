#include "diameter.h"
#include <cassert>
#include <cstdio>
#include <vector>

int main() {
	int n;
	assert(1 == scanf("%d", &n));

    std::vector<int> u(n), v(n);
    for (int i = 0; i < n; i++){
        assert(2 == scanf("%d %d", &u[i], &v[i]));
    }

	std::vector<int> res = find_diameters(n, u, v);

    if ((int)res.size() != n){
        printf("Returned array is not of length n");
    } else {
        for (int i = 0; i < n; i++){
            printf("%d ", res[i]);
        }
        printf("\n");
    }

	return 0;
}
