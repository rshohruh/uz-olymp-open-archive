#include "stbz.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

// --- Data Structures ---

struct Node {
    int ans = 0;
    vector<int> x;
};

// --- Helper Functions ---

Node merge_nodes(const Node& a, const Node& b) {
    Node res;
    res.ans = max(a.ans, b.ans);
    
    if (a.x.size() > 1 && b.x.size() > 0) {
        res.ans = max(res.ans, b.x[0] - a.x.rbegin()[1] - 1);
    }
    if (b.x.size() > 1 && a.x.size() > 0) {
        res.ans = max(res.ans, b.x[1] - a.x.rbegin()[0] - 1);
    }

    res.x = a.x;
    res.x.insert(res.x.end(), b.x.begin(), b.x.end());
    
    if (res.x.size() > 4) {
        vector<int> pruned;
        pruned.reserve(4);
        pruned.push_back(res.x[0]);
        pruned.push_back(res.x[1]);
        pruned.push_back(res.x[res.x.size() - 2]);
        pruned.push_back(res.x[res.x.size() - 1]);
        res.x = pruned;
    }
    
    return res;
}

Node make_removable(pair<int, int> val, int i) {
    if (val == pair<int, int>{0, 0}) return Node{0, {i, i, i, i}};
    if (val == pair<int, int>{1, 1}) return Node{0, {}};
    return Node{0, {i}};
}

Node make_strict(pair<int, int> val, int i) {
    if (val == pair<int, int>{0, 0}) return Node{0, {i, i, i, i}};
    if (val == pair<int, int>{1, 1}) return Node{0, {}};
    return Node{0, {i, i}};
}

bool make_bool_fn(pair<int, int> val) {
    return (val.first == 0 && val.second == 0);
}

// --- Segment Tree Classes ---

template <typename T>
class SegTree {
public:
    using MergeFunc = function<Node(const Node&, const Node&)>;
    using MakeFunc = function<Node(T, int)>;

    SegTree(const vector<T>& v, const Node& id_node, MakeFunc make_node, MergeFunc merge)
        : _n((int)v.size()), _id_node(id_node), _make_node(make_node), _merge(merge) {
        _log = 0;
        while ((1 << _log) < _n) _log++;
        _size = 1 << _log;
        _d.assign(2 * _size, _id_node);

        for (int i = 0; i < _n; i++) _d[_size + i] = _make_node(v[i], i);
        for (int i = _size - 1; i >= 1; i--) update(i);
    }

    void set(int p, T val) {
        int idx = p;
        p += _size;
        _d[p] = _make_node(val, idx);
        for (int i = 1; i <= _log; ++i) update(p >> i);
    }

    Node query(int l, int r) {
        Node sml = _id_node, smr = _id_node;
        l += _size;
        r += _size + 1;

        while (l < r) {
            if (l & 1) sml = _merge(sml, _d[l++]);
            if (r & 1) smr = _merge(_d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return _merge(sml, smr);
    }

private:
    int _n, _size, _log;
    vector<Node> _d;
    Node _id_node;
    MakeFunc _make_node;
    MergeFunc _merge;

    void update(int k) {
        _d[k] = _merge(_d[2 * k], _d[2 * k + 1]);
    }
};

class BoolSegTree {
public:
    BoolSegTree(const vector<pair<int, int>>& v, function<bool(pair<int, int>)> make) 
        : _n((int)v.size()), _make(make) {
        _log = 0;
        while ((1 << _log) < _n) _log++;
        _size = 1 << _log;
        _d.assign(2 * _size, false);

        for (int i = 0; i < _n; i++) _d[_size + i] = _make(v[i]);
        for (int i = _size - 1; i >= 1; i--) _d[i] = _d[2 * i] | _d[2 * i + 1];
    }

    void set(int p, pair<int, int> val) {
        p += _size;
        _d[p] = _make(val);
        for (p >>= 1; p >= 1; p >>= 1) _d[p] = _d[2 * p] | _d[2 * p + 1];
    }

    bool query(int l, int r) {
        bool res = false;
        l += _size;
        r += _size + 1;
        while (l < r) {
            if (l & 1) res = res | _d[l++];
            if (r & 1) res = res | _d[--r];
            l >>= 1; r >>= 1;
        }
        return res;
    }

private:
    int _n, _size, _log;
    vector<bool> _d;
    function<bool(pair<int, int>)> _make;
};

// --- Global State ---

SegTree<pair<int, int>>* st1 = nullptr;
SegTree<pair<int, int>>* st2 = nullptr;
BoolSegTree* stf = nullptr;

// --- Interface Functions ---

void init(int n, const std::vector<int>& a, const std::vector<int>& b) {
    vector<pair<int, int>> ab(n);
    for (int i = 0; i < n; ++i) {
        ab[i] = {a[i], b[i]};
    }
    
    if (st1) delete st1;
    if (st2) delete st2;
    if (stf) delete stf;

    st1 = new SegTree<pair<int, int>>(ab, Node{}, make_removable, merge_nodes);
    st2 = new SegTree<pair<int, int>>(ab, Node{}, make_strict, merge_nodes);
    stf = new BoolSegTree(ab, make_bool_fn);
}

int query(int l, int r) {
    bool has_strong = stf->query(l, r);
    Node result = has_strong ? st1->query(l, r) : st2->query(l, r);
    
    // Handle circularity
    Node shifted_result = result;
    for (int& idx : shifted_result.x) idx += (r - l + 1);
    
    Node circular_combined = merge_nodes(result, shifted_result);
    return circular_combined.ans;
}

void update(int i, int a, int b) {
    pair<int, int> val = {a, b};
    st1->set(i, val);
    st2->set(i, val);
    stf->set(i, val);
}