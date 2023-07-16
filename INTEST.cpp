#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    int ret = 0;

    while(n--)
    {
        int l;
        cin >> l;
        if(l % k == 0) ret++;
    }

    cout << ret << "\n";

    return 0;
}