#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SET{
    vector<unsigned int> element;
};

void UNION(SET, SET);
void INTERSECTION(SET, SET);
void GIVENSET(SET, int);

int main()
{
    int num = 1;
    SET set1;
    SET set2;
    SET gset;
    //input set1
    cout << "Compute the union and intersection of two sets." << endl;
    cout << "Set1 (input 0 to stop): ";
    while(cin >> num){
        if(num == 0)
            break;
        set1.element.push_back(num);
    }
    //input set2
    num = 1;
    cout << "Set2 (input 0 to stop): ";
    while(cin >> num){
        if(num == 0)
            break;
        set2.element.push_back(num);
    }
    UNION(set1, set2);
    INTERSECTION(set1, set2);
    cout << endl;
    //given set
    num = 1;
    cout << "Determine if a given element is in a given set." << endl;
    cout << "A given set (input 0 to stop): ";
    while(cin >> num){
        if(num == 0)
            break;
        gset.element.push_back(num);
    }
    cout << "A given element: ";
    cin >> num;
    sort(gset.element.begin(), gset.element.end());
    GIVENSET(gset, num);
    return 0;
}

void UNION(SET set1, SET set2)
{
    //O(nlogn)
    sort(set1.element.begin(), set1.element.end());
    sort(set2.element.begin(), set2.element.end());
    //O(n)
    SET unionSet;
    int pset1 = 0, pset2 = 0;
    while(pset1 < set1.element.size() && pset2 < set2.element.size()){
        if(set1.element[pset1] < set2.element[pset2])
            pset1++;
        else if(set1.element[pset1] > set2.element[pset2])
            pset2++;
        else{
            unionSet.element.push_back(set1.element[pset1]);
            pset1++;
            pset2++;
        }
    }
    cout << "the union: ";
    for(int i = 0; i < unionSet.element.size(); i++)
        cout << unionSet.element[i] << " ";
    cout << endl;
}

void INTERSECTION(SET set1, SET set2)
{
    //O(nlogn)
    sort(set1.element.begin(), set1.element.end());
    sort(set2.element.begin(), set2.element.end());
    //O(n)
    SET intersectionSet;
    int pset1 = 0, pset2 = 0;
    while(pset1 < set1.element.size() && pset2 < set2.element.size()){
        if(set1.element[pset1] < set2.element[pset2]){
            intersectionSet.element.push_back(set1.element[pset1]);
            pset1++;
        }
        else if(set1.element[pset1] > set2.element[pset2]){
            intersectionSet.element.push_back(set2.element[pset2]);
            pset2++;
        }
        else{
            intersectionSet.element.push_back(set1.element[pset1]);
            pset1++;
            pset2++;
        }
    }
    //add the remainder of them
    if(pset1 < set1.element.size()){
        for(int i = pset1; i < set1.element.size(); i++)
            intersectionSet.element.push_back(set1.element[i]);
    }
    else if(pset2 < set2.element.size()){
        for(int i = pset2; i < set2.element.size(); i++)
            intersectionSet.element.push_back(set2.element[i]);
    }
    cout << "the intersection: ";
    for(int i = 0; i < intersectionSet.element.size(); i++)
        cout << intersectionSet.element[i] << " ";
    cout << endl;
}
void GIVENSET(SET gset, int num)
{
    //O(nlogn)
    sort(gset.element.begin(), gset.element.end());
    //binary search
    //O(log n)
    if(binary_search(gset.element.begin(), gset.element.end(), num))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
