#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

struct kMaxMin{
    int max;
    int min;
    int maxB;
    int minB;
};

void maxValue(vector<int>, vector<char>);
void countParen(kMaxMin*, bool, const int, int, int, int[], int[]);

int main()
{
    string s;
    cin >> s;
    stringstream ss;
    ss << s;

    vector<int> num;
    vector<char> op;
    int temp_int;
    char temp_ch;
    while(ss >> temp_int){
        num.push_back(temp_int);
        ss >> temp_ch;
        op.push_back(temp_ch);
    }
    maxValue(num, op);
    return 0;
}

void maxValue(vector<int> num, vector<char> op)
{
    
    const int numSize = num.size();
    const int opSize = numSize-1;
    int maxDp[numSize][numSize], minDp[numSize][numSize];
    kMaxMin s[numSize][numSize];
    int maxTemp, minTemp, sTemp;

    //initialize maxDp, minDp, s
    for(int i = 0; i < numSize; i++){
        for(int j = 0; j < numSize; j++){
            if(i == j){
                maxDp[i][j] = num[i];
                minDp[i][j] = num[i];
            }
            else{
                maxDp[i][j] = INT_MIN;
                minDp[i][j] = INT_MAX;
            }
            s[i][j].max = -1;
            s[i][j].min = -1;
            s[i][j].maxB = -1;
            s[i][j].minB = -1;
        }
    }

    //calculate num, put it into maxDp
    for(int j = 1; j < numSize; j++){
        for(int i = 0; i+j < numSize; i++){
            for(int k = i; k < i+j; k++){
                maxTemp = maxDp[i][i+j];
                minTemp = minDp[i][i+j];
                if(op[k] == '+'){
                    maxDp[i][i+j] = max(maxDp[i][i+j], maxDp[i][k] + maxDp[k+1][i+j]);
                    if(maxDp[i][i+j] != maxTemp){
                        s[i][i+j].max = k;
                        s[i][i+j].maxB = 3;
                        maxTemp = maxDp[i][i+j];
                    }
                    minDp[i][i+j] = min(minDp[i][i+j], minDp[i][k] + minDp[k+1][i+j]);
                    if(minDp[i][i+j] != minTemp){
                        s[i][i+j].min = k;
                        s[i][i+j].minB = 0;
                        minTemp = minDp[i][i+j];
                    }
                }
                if(op[k] == '-'){
                    maxDp[i][i+j] = max(maxDp[i][i+j], maxDp[i][k] - minDp[k+1][i+j]);
                    if(maxDp[i][i+j] != maxTemp){
                        s[i][i+j].max = k;
                        s[i][i+j].maxB = 2;
                        maxTemp = maxDp[i][i+j];
                    }
                    minDp[i][i+j] = min(minDp[i][i+j], minDp[i][k] - maxDp[k+1][i+j]);
                    if(minDp[i][i+j] != minTemp){
                        s[i][i+j].min = k;
                        s[i][i+j].minB = 1;
                        minTemp = minDp[i][i+j];
                    }
                }
                if(op[k] == '*'){
                    maxDp[i][i+j] = max(maxDp[i][i+j], maxDp[i][k] * maxDp[k+1][i+j]);
                    if(maxDp[i][i+j] != maxTemp){
                        s[i][i+j].max = k;
                        s[i][i+j].maxB = 3;
                        maxTemp = maxDp[i][i+j];
                    }
                    maxDp[i][i+j] = max(maxDp[i][i+j], maxDp[i][k] * minDp[k+1][i+j]);
                    if(maxDp[i][i+j] != maxTemp){
                        s[i][i+j].max = k;
                        s[i][i+j].maxB = 2;
                        maxTemp = maxDp[i][i+j];
                    }
                    maxDp[i][i+j] = max(maxDp[i][i+j], minDp[i][k] * maxDp[k+1][i+j]);
                    if(maxDp[i][i+j] != maxTemp){
                        s[i][i+j].max = k;
                        s[i][i+j].maxB = 1;
                        maxTemp = maxDp[i][i+j];
                    }
                    maxDp[i][i+j] = max(maxDp[i][i+j], minDp[i][k] * minDp[k+1][i+j]);
                    if(maxDp[i][i+j] != maxTemp){
                        s[i][i+j].max = k;
                        s[i][i+j].maxB = 0;
                        maxTemp = maxDp[i][i+j];
                    }
                    minDp[i][i+j] = min(minDp[i][i+j], maxDp[i][k] * maxDp[k+1][i+j]);
                    if(minDp[i][i+j] != minTemp){
                        s[i][i+j].min = k;
                        s[i][i+j].minB = 3;
                        minTemp = minDp[i][i+j];
                    }
                    minDp[i][i+j] = min(minDp[i][i+j], maxDp[i][k] * minDp[k+1][i+j]);
                    if(minDp[i][i+j] != minTemp){
                        s[i][i+j].min = k;
                        s[i][i+j].minB = 2;
                        minTemp = minDp[i][i+j];
                    }
                    minDp[i][i+j] = min(minDp[i][i+j], minDp[i][k] * maxDp[k+1][i+j]);
                    if(minDp[i][i+j] != minTemp){
                        s[i][i+j].min = k;
                        s[i][i+j].minB = 1;
                        minTemp = minDp[i][i+j];
                    }
                    minDp[i][i+j] = min(minDp[i][i+j], minDp[i][k] * minDp[k+1][i+j]);
                    if(minDp[i][i+j] != minTemp){
                        s[i][i+j].min = k;
                        s[i][i+j].minB = 0;
                        minTemp = minDp[i][i+j];
                    }
                }
            }
        }
    }

    //parenthesize the expression
    int lParen[numSize] = {0};
    int rParen[numSize] = {0};
    countParen(&s[0][0], true, numSize, 0, numSize-1, lParen, rParen);
    for(int i = 0; i < numSize; i++){
        for(int j = 0; j < lParen[i]; j++)
            cout << "(";
        cout << num[i];
        for(int j = 0; j < rParen[i]; j++)
            cout << ")";
        if(i < opSize)
            cout << op[i];
    }
    cout << " = " << maxDp[0][numSize-1] << endl;
}

void countParen(kMaxMin* s, bool isItMax, const int numSize, int l, int r, int lParen[], int rParen[])
{    
    if(l < r){
        int k, B;
        bool isItMaxL, isItMaxR;
        if(isItMax == true){
            k = (*(s + (numSize*l) + r)).max;
            B = (*(s + (numSize*l) + r)).maxB;
        }
        else{
            k = (*(s + (numSize*l) + r)).min;
            B = (*(s + (numSize*l) + r)).minB;
        }

        switch (B){
        case 3:
            isItMaxL = true;
            isItMaxR = true;
            break;
        case 2:
            isItMaxL = true;
            isItMaxR = false;
            break;
        case 1:
            isItMaxL = false;
            isItMaxR = true;
            break;
        case 0:
            isItMaxL = false;
            isItMaxR = false;
            break;
        default:
            break;
        }
        lParen[l]++;
        rParen[r]++;
        countParen(s, isItMaxL, numSize, l, k, lParen, rParen);
        countParen(s, isItMaxR, numSize, k+1, r, lParen, rParen);
    }
}