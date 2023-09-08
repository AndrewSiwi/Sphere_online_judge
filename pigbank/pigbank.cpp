#include <bits/stdc++.h>

using namespace std;

#define int long long

#define iter(var, start, cond, end, diff) for(int var = (start); var cond (end); var += (diff))
#define iter_fix(var, start, end) iter(var, start, <, end, 1)
#define iter_arr(var) iter_fix(var, 0, this->n)
#define iter_reverse(var, start, end) iter(var, start, >=, end, -1)

#define iter_cont(var, cont) for(auto& var: cont)
#define iter_cont_it(var, cont, comm) for(auto var = cont.begin(); var != cont.end(); comm)
#define iter_cont_revit(var, cont, comm) for(auto var = cont.rbegin(); var != cont.rend(); comm)

const int N = 1e4 + 1;
const int MAX_PRICE = 25e6;

class Solution
{
    static int t;
    public: static void init()
    {
        cin >> t;
        int ct = 0;
        while(ct < t)
        {
            Solution* sl = new Solution(ct++);
            sl->process();
            sl->print();
            delete sl;
        }
    }


    private: int ct;

    int e, f, n, ret = 0;
    pair<int, int> arr[N];

    public: Solution(int ct)
    {
        this->ct = ct;

        cin >> this->e >> this->f >> this->n;
        int n = this->n;
        while(n--)
        {
            int p, w;
            cin >> p >> w;
            this->arr[this->n - n - 1] = { p, w };
        }
    }

    void process()
    {        
        int w = this->f - this->e;
        int table[N] = { 0 };
        iter_fix(i, 0, N)
            table[i] = MAX_PRICE;
        
        table[0] = 0;
        iter_fix(i, 1, w + 1)
            iter_arr(j)
                if(this->arr[j].second <= i)
                    if(this->arr[j].first + table[i - this->arr[j].second] < table[i])
                        table[i] = this->arr[j].first + table[i - this->arr[j].second];

        this->ret = table[w];
    }

    void print()
    {
        if(this->ret < MAX_PRICE)
            cout << "The minimum amount of money in the piggy-bank is " << this->ret << "." << "\n";
        else
            cout << "This is impossible." << "\n";
        //cout << "\n";
    }
};

int Solution::t = 1;

#undef int
int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution::init();

    return 0;
}