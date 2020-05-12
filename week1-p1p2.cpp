#include <iostream>
#include <algorithm>
using namespace std;

void sum2IsM(int, int[], int);
void sum3IsM(int, int[], int);

int main()
{
    int n = 0, M = 0;
    cout << "n: ";
    cin >> n;
    int S[n] = {0};
    cout << "S: ";
    for(int i = 0; i < n; i++)
        cin >> S[i];
    cout << "M: ";
    cin >> M;
    sort(S, S+n);
    sum2IsM(n, S, M);
    sum3IsM(n, S, M);
    return 0;
}

void sum2IsM(int n, int S[], int M)
{
    cout << "2 numbers: ";
    int i = 0, j = n-1;
    while(i < j){
        if(S[i]+S[j] < M){
            i++;
        }
        else if(S[i]+S[j] > M){
            j--;
        }
        else{
            cout << "YES, M = " << S[i] << " + " << S[j] << endl;
            break;
        }
    }
    if(i >= j)
        cout << "NO" << endl;
}

void sum3IsM(int n, int S[], int M)
{
    bool exist = false;
    cout << "3 numbers: ";
    int i = 0, j = n-1;
    for(int x = 0; x < n; x++){
        i = 0;
        j = n-1;
        while(i < j){
            if(S[i] == S[x])
                i++;
            if(S[j] == S[x])
                j--;
            if(S[i]+S[j] < M-S[x]){
                i++;
            }
            else if(S[i]+S[j] > M-S[x]){
                j--;
            }
            else{
                cout << "YES, M = " << S[x] << " + " << S[i] << " + " << S[j] << endl;
                exist = true;
                break;
            }
        }
        if(exist)
            break;
    }
    if(!exist)
        cout << "NO" << endl;
}
