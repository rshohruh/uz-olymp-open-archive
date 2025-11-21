#include "aplusb.h"
#include <cstdio>
#include <vector>

int main(){
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }

    int res = aplusb(n, a, b);
    printf("%d\n", res);

    return 0;
}