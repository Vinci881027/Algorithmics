#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

struct node{
    char name;
    int data;
    node *left = 0;
    node *right = 0;
    string huffman = "";
};

deque<node*> sortedHuffman;

bool compData(node *a, node *b){  //sorted by freq
  return a->data < b->data;
}

bool compName(node *a, node *b){  //sorted by alphabet
  return a->name < b->name;
}

void traversal(node *p, string huffmanPart){
    if(p){
        p->huffman = p->huffman + huffmanPart;
        if(!(p->left && p->right))
            sortedHuffman.push_back(p);
        traversal(p->left, huffmanPart + "0");
        traversal(p->right, huffmanPart + "1");
    }
}

int main()
{
    int n;
    cin >> n;
    char alpha[n];
    int freq[n];
    node *temp;
    node *addNode;
    deque<node*> q;
    deque<node*> addQ;
    for(int i = 0; i < n; i++){
        cin >> alpha[i] >> freq[i];
        temp = new node();
        temp->name = alpha[i];
        temp->data = freq[i];
        q.push_back(temp);
    }
    sort(q.begin(), q.end(), compData);
    while(q.size() > 1){
        addNode = new node();
        addNode->data = q[0]->data + q[1]->data;
        addNode->left = q[0];
        addNode->right = q[1];
        q.push_back(addNode);
        sort(q.begin(), q.end(), compData);
        q.pop_front();
        q.pop_front();
    }
    traversal(q[0], "");
    sort(sortedHuffman.begin(), sortedHuffman.end(), compName);
    for(int i = 0; i < sortedHuffman.size(); i++)
        cout << sortedHuffman[i]->name << " " << sortedHuffman[i]->huffman << endl;
    return 0;
}