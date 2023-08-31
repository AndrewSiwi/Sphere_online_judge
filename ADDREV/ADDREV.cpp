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
        int ct = 0;
        while(ct < t /*!cin.eof()*/)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    string one, two;
    int ret = 0;

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->one >> this->two;
    }

    void process()
    {
        string reverseOne = "";
        for(auto it = this->one.rbegin(); it != this->one.rend(); it++)
        {
            reverseOne += *it;
        }

        string reverseTwo = "";
        for(auto it = this->two.rbegin(); it != this->two.rend(); it++)
        {
            reverseTwo += *it;
        }

        int ret = stoi(reverseOne) + stoi(reverseTwo);
        string sret = to_string(ret);

        string reverseRet = "";
        for(auto it = sret.rbegin(); it != sret.rend(); it++)
        {
            reverseRet += *it;
        }

        this->ret = stoi(reverseRet);
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