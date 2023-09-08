#include <bits/stdc++.h>

using namespace std;

#define STEROID_NUMBER long long

#define ITER_ARR(start, var, end) for(int var = (start); var < (end); var++)
#define ITER_ARR_ALL ITER_ARR(0, i, this->n)
#define ITER_ARR_REVERSE(start, end) for(int i = (start); i >= (end); i--)

#define ITER_VEC(vec) for(int x: vec)

#define N 1000

class Solution
{
    int t, n, **gifts;
    STEROID_NUMBER ret;

    public:

    Solution()
    {
        cin >> this->t;
        int t = this->t;
        while(t--)
        {
            this->ret = 0;            
            cin >> this->n;
            int n = this->n;
            this->gifts = new int*[n];
            while(n--)
            {
                this->gifts[this->n - n - 1] = new int[3];
                ITER_ARR(0, i, 3) cin >> this->gifts[this->n - n - 1][i];
            }

            this->process();
            this->print();
        }
    }

    void process()
    {
        STEROID_NUMBER last = 0;
        ITER_ARR_ALL
        {
            int* gift = this->gifts[i];
            STEROID_NUMBER sides[3];
            sides[0] = gift[0] * gift[1];
            sides[1] = gift[1] * gift[2];
            sides[2] = gift[0] * gift[2];
            sort(sides, sides + 3);

            this->ret += sides[1] + 2 * sides[0] + 2 * sides[2];
            this->ret -= ((i > 0) ? (2 * min(sides[0], last)) : 0);
            last = sides[0];
        }
    }

    void print()
    {
        cout << this->ret << "\n";
        //cout << "\n";
    }
};

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution* sl = new Solution();
    //sl->process();
    //sl->print();

    return 0;
}