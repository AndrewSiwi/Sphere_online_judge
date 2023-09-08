#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 10

class Solution
{
    static int t;
    public: static void init()
    {
        cin >> t;
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution();
            sl->process();
            sl->print();
            delete sl;
        }
    }

    private:

    int n;
    string s, ret;


    public:

    Solution()
    {
        cin >> s;
    }

    void process()
    {
        this->n = s.size();
        ITER(i, 0, <, this->n / 2, 2)
        {
            this->ret += this->s[i];
        }
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";   
    }
};

int Solution::t = 1;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}