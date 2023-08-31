#include <bits/stdc++.h>

using namespace std;

class Solution
{
    int t;

    public:

    Solution()
    {
        cin >> this->t;
    }

    bool isPrime(int n)
    {
        if(n == 1) return false;
        for(int i = 2; i <= sqrt(n); i++) if(n % i == 0) return false; 
        return true;
    }

    void process()
    {
        int t = this->t;
        while(t--)
        {
            if(t < (this->t - 1)) cout << "\n";

            int m, n;
            cin >> m >> n;
            if(m <= 2) cout << 2 << "\n";
            if(m % 2 == 0) m++;
            for(int i = m; i <= n; i += 2)
            {
                if(this->isPrime(i)) cout << i << "\n";
            }
        }
    }

    void print()
    {
        //cout << "\n";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    sl->process();
    sl->print();

    return 0;
}