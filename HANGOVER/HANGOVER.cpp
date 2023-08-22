#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER(var, start, cond, end, diff) for(int var = (start); var cond (end); var += diff)
#define ITER_FIX(var, start, end) ITER(var, start, <, end, 1)
#define ITER_ARR(var) ITER_FIX(var, 0, this->n)
#define ITER_REVERSE(var, start, end) ITER(var, start, >=, end, -1)

#define ITER_CONT(var, cont) for(auto& var: cont)
#define ITER_CONT_IT(var, cont) for(auto var = cont.begin(); var != cont.end();)

#define N 520

class Solution
{
    static int t;
    public: static void init()
    {
        //cin >> t;
        ITER_FIX(i, 0, t)
        {
            Solution* sl = new Solution(i);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int TAB[N];
    vector<int> input;
    int ret;

    public: Solution(int ct)
    {
        this->ct = ct;

        float x;
        cin >> x;
        while(x > 0.0)
        {
            int ix = round(x * 100);
            this->input.push_back(ix);
            cin >> x;
        }
    }

    void process()
    {
        this->TAB[0] = 1;
        float sum = (1.0 / 2);
        ITER_FIX(i, 1, N)
        {
            int n = this->TAB[i - 1];
            float overhang = ((float)(i + 1) / 100);
            while(sum < overhang)
            {
                n++;
                sum += (1.0 / (n + 1));
            }
            this->TAB[i] = n;
        }

        ITER_CONT(x, this->input) cout << this->TAB[x - 1] << " card(s)" << "\n";
    }

    void print()
    {
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