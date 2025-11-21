#include "bookshelf.h"
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>

static int n, m, t;
static std::vector<std::vector<int>> grid;

static void exit_mes(const char* mes) {
    printf("%s\n", mes);
    exit(0);
}

static void grid_check(std::vector<std::vector<int>> a){
    std::vector<int> tot;
    int n_ = (int)a.size();
    if(n != n_){
        exit_mes("wrong size n");
    }

    for(int i = 0; i < (int)a.size(); ++i){
        if((int)a[i].size() != m){
            exit_mes("wrong size m");
        }
        for(int j = 0; j < (int)a[i].size(); ++j){
            tot.push_back(a[i][j]);
        }
    }
    
    sort(tot.begin(), tot.end());
    tot.erase(unique(tot.begin(), tot.end()), tot.end());
    if(tot[0] < 0 || tot.back() >= n * m) {
        exit_mes("min or max element in grid out of bound");
    }
    
    if((int)tot.size() != n * m){
        exit_mes("does not contain all of elements between 0 and n * m - 1");
    }
}

void rearrange_row(std::vector<std::vector<int>> b) {
    auto a = grid;
    grid_check(b);
    grid = b;

    for(int i = 0; i < n; ++i){
        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());
        
        if(a[i] != b[i]) {
            exit_mes("illegal operation performed");
        }
    }
    
    if(t == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
}

void rearrange_column(std::vector<std::vector<int>> b) {
    auto a = grid;
    grid_check(b);
    grid = b;
    
    std::vector<int> x(n), y(n);
    for(int j = 0; j < m; ++j){
        for(int i = 0; i < n; ++i){
            x[i] = a[i][j];
            y[i] = b[i][j];
        }
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if(x != y) {
            exit_mes("illegal operation performed");
        }
    }

    if(t == 2) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    assert(3 == scanf("%d %d %d", &n, &m, &t));
    grid = std::vector<std::vector<int>>(n, std::vector<int>(m));
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            assert(1 == scanf("%d", &grid[i][j]));
        }
    }
    
    fclose(stdin);

    int res = sort_books(n, m, grid);
    printf("%d\n", res);
    fclose(stdout);
    return 0;
}
