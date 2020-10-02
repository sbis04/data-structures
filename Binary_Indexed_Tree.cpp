#include <iostream>
#include <vector>

using namespace std;

class BinaryIndexedTree
{
private:
    vector<int> nums;

public:
    BinaryIndexedTree(int size)
    {
        this->nums.resize(size + 1, 0);
    }
    void update(int i, int x)
    {
        if (i == 0)
            return;
        for (int j = i; j < this->nums.size(); j += (j & -j))
            this->nums[j] += x;
    };

    int query(int i)
    {
        if (i == 0)
            return 0;
        int ans = 0;
        for (int j = i; j > 0; j -= (j & -j))
            ans += this->nums[j];
        return ans;
    };
};

int main()
{
    int n = 100;

    BinaryIndexedTree *bit = new BinaryIndexedTree(n);

    for (int i = 1; i <= n; i++)
        bit->update(i, i);

    // Alternate update and query
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            bit->update(i, i / 2);
        else
        {
            int l = 1, r = n;
            cout << (bit->query(r) - bit->query(l - 1)) << endl;
        }
    }

    return 0;
}