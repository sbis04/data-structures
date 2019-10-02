// Disjoint Set Union: optimised complexity O(1) by using 'union by height' and 'path compression'

#include <iostream>
#include <vector>
using namespace std;

class dsu {
private:
    vector<int> parent, height;
    // parent[] stores parent of each node & height[] stores heights of root node
public:
    dsu(int n);
    int findSet(int a); // returns the root of that component
    bool isSameSet(int a, int b); // returns if they are in same set or not
    void unionSet(int a, int b); // merges two components into one
    void reset();
};

dsu::dsu(int n) {
    parent.assign(n, 0);
    height.assign(n, 0);
    for (int i = 0;i < parent.size();i++)
        parent[i] = i; // Initialize each node being the root of itself
}

int dsu::findSet(int a) {
    return parent[a] == a ? a : parent[a] = findSet(parent[a]); // storing root/parent of the set and then returning the value : 'path compression'
}

bool dsu::isSameSet(int a, int b) {
    return findSet(a) == findSet(b);
}

void dsu::unionSet(int a, int b) {
    int x = findSet(a), y = findSet(b);
    height[x] < height[y] ? parent[x] = y : parent[y] = x; // The root having more height becomes parent of the other root
    if (height[x] == height[y])
        height[x]++; // If both have same height => choose any one of them & increase the height of that root by 1
}

void dsu::reset() {
    for (int i = 0;i < parent.size();i++) {
        parent[i] = i;
        height[i] = 0;
    }
}

int main()
{
    // Usage of dsu class is given below
    dsu a(5); // creates 5 disjoint sets i.e {{0}, {1}, {2}, {3}, {4}}
    a.unionSet(1, 4); // now the structue becomes {{0}, {1,4}, {2}, {3}}
    a.unionSet(3, 4); // now the structue becomes {{0}, {1,4,3}, {2}}
    cout << a.isSameSet(2, 0) << "\n"; // returns false
    cout << a.isSameSet(4, 1) << "\n"; // returns true
    a.reset(); // the structure resets to {{0}, {1}, {2}, {3}, {4}}
    cout << a.isSameSet(4, 1) << "\n"; // returns false
    return 0;
}
