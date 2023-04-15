#include <iostream>

#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct node{
    int data;
    node* left;     // smaller than data
    node* right;    // bigger than data

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* createNode(int data){
    node* newnode = new node(data);
    return newnode;
}

node* insertNode(node* current, int data){
    if(current == NULL) return createNode(data);

    if(data < current->data){
        current->left = insertNode(current->left, data);
    }
    else if(data > current->data){
        current->right = insertNode(current->right, data);
    }
    return current;
}

void postSearch(node* start){
    if(start == NULL) return;

    postSearch(start->left);
    postSearch(start->right);
    cout << start->data << '\n';
}

int main(void){
    fastio;
    int n;
    cin >> n;
    struct node* root = createNode(n);
    //postSearch(root);
    int buf;
    while(cin >> buf){
        insertNode(root, buf);
    }

    postSearch(root);


}
