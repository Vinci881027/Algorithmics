#include <iostream>
using namespace std;

struct buy{
    int low = 0;
    int high = 0;
    int profit = 0;
};

buy MSP(int[], int, int);

int main()
{
    int n = 0;
    buy stock;
    stock.low = 0;
    stock.high = 0;
    stock.profit = 0;
    cout << "A Stock Buying Problem" << endl;
    cout << "You have the prices that a stock traded at over a period of n consecutive days, n = ";
    cin >> n;
    cout << "input the price from day 0 to day " << n << ": ";
    int price[n+1];
    for(int i = 0; i <= n; i++)
        cin >> price[i];
    stock = MSP(price, 0, n);
    if(stock.profit != -1)
        cout << "Day " << stock.low << " bought, day " << stock.high << " sold, the maximum profit = " << stock.profit << endl;
    else
        cout << "You should not buy the stock." << endl;
    return 0;
}

buy MSP(int price[], int l, int r)
{
    buy stock, left, mid, right;
    if(l < r){
        stock.low = l;
        stock.high = l;
        stock.profit = price[l];
        for(int i = l; i <= r; i++){  //find the lowest and higher
            if(price[i] <= price[stock.low])
                stock.low = i;
            if(price[i] >= price[stock.high])
                stock.high = i;
        }
        if(stock.low < stock.high){
            stock.profit = price[stock.high] - price[stock.low];
            return stock;
        }
        else if(stock.low > stock.high){  //recurrences
            left = MSP(price, l, stock.high);
            mid = MSP(price, stock.high+1, stock.low-1);
            right = MSP(price, stock.low, r);
            if(left.profit > mid.profit && left.profit > right.profit)
                return left;
            if(mid.profit > left.profit && mid.profit > right.profit)
                return mid;
            if(right.profit > left.profit && right.profit > mid.profit)
                return right;
        }
        else{
            stock.low = l;
            stock.high = r;
            stock.profit = 0;
            return stock;
        }
    }
    stock.low = -1;  //do not buy the stock
    stock.high = -1;
    stock.profit = -1;
    return stock;
}
