#include <bits/stdc++.h>
using namespace std;

// #define FOR(i, j, k, in) for (int i = j; i < k; i += in)
// #define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
// #define REP(i, j) FOR(i, 0, j, 1)
// #define RREP(i, j) RFOR(i, j, 0, 1)

// #define INF (int)1e9
// #define PI 3.1415926535897932384626433832795
// #define MOD 1000000007
#define endl "\n" // \n is faster than endl b/c cout << endl is actually cout << "\n" << flush;

typedef long long ll;
typedef unsigned long long ull;

// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<ll> vl;
// typedef vector<vl> vvl;
// typedef vector<char> vc;
// typedef vector<vc> vvc;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<string, string> pss;
// typedef map<int, int> mii;
// typedef unordered_map<int, int> umap_ii;
// typedef unordered_map<string, int> umap_si;

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

// ---------------------------------------------------------------------------------------
#include <math.h>

void solve()
{
    // Solve below
    int n = 8;
    vector<vector<char>> board(n, vector<char>(n, '.'));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    char curr = ' ';
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(board[i][j] != board[i][j-1] || board[i][j] == '.') {
                curr = ' ';
                break;
            } else {
                curr = board[i][j];
            }
        }
        if(curr != ' ') {
            cout << curr << endl;
            return;
        }
    }

    curr = ' ';
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(board[j][i] != board[j-1][i] || board[j][i] == '.') {
                curr = ' ';
                break;
            } else {
                curr = board[j][i];
                
            }
        }
        if(curr != ' ') {
            cout << curr << endl;
            return;
        }
    }
        
}


// ---------------------------------------------------------------------------------------
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}