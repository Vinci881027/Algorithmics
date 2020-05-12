#include <iostream>
#include <string>
using namespace std;

const int del = 2;  //delete
const int ins = 2;  //insert
const int cop = -1;  //copy
const int rep = 1;  //replace
int EDIT(string, string);
int min(int a, int b)
{
    if(a < b)
        return a;
    else
        return b;
}
int main()
{
    string x,y;
    cin >> x >> y;
    cout << EDIT(x,y);
    return 0;
}

int EDIT(string x, string y)
{
    int m = x.length();
    int n = y.length();
    int dp[m+1][n+1];
    //initialize dp[m][n]
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++)
            dp[i][j] = 100;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= m; i++)
        dp[i][0] = dp[i-1][0] + ins;
    for(int j = 1; j <= n; j++)
        dp[0][j] = dp[0][j-1] + ins;
    //min edit distance
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(x[i-1] == y[j-1])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + cop);
            else
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + rep);
            dp[i][j] = min(dp[i][j], dp[i-1][j] + del);
            dp[i][j] = min(dp[i][j], dp[i][j-1] + ins);
        }
    }
    /*for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }*/
    return dp[m][n];
}