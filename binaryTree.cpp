#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

typedef pair <int, int> ii;
typedef vector <int> vi;
int ans=0;

struct BSTNode
{
    public:
        int dia=1;
        int key;
        BSTNode *left;
        BSTNode *right;
        BSTNode *paren;
};

int diameter(BSTNode *root)
{   int cur;
    if(root->left != nullptr)
    {
    diameter(root->left);
    }
    if(root->right != nullptr)
    {
    diameter(root->right);
    }
     if(root->left != nullptr && root->right != nullptr)
    {
    root->dia = max(root->left->dia,root->right->dia) + 1;
    cur = 1 + root->left->dia + root->right->dia;
    }
    if(root->left != nullptr && root->right == nullptr)
    {
    root->dia = root->left->dia + 1;
    cur = 1 + root->left->dia ;
    }
    if(root->left == nullptr && root->right != nullptr)
    {
    root->dia = root->right->dia + 1;
    cur = 1 + root->right->dia;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
    return 0;
    }
    
    ans = max (ans,cur);



}

int traversal(BSTNode *root)
{
    BSTNode *tree = root;
    BSTNode *temp = new BSTNode;
    stack<BSTNode*>s;
    s.push(tree);
    while(!s.empty()){
        temp = s.top();
        s.pop();
        cout<<temp->key;
        if((temp->left) != nullptr)
        {
            s.push(temp->left);
        }
        if((temp->right) != nullptr)
        {
            s.push(temp->right);
        }

    }

    return 0;
}

int main()
{
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;
        vector <ii> a (1001, ii(-1, -1));
        vi p (1001, -1);

        for (int i = 0; i < n; i++) {
            int u, v;
            char c;
            cin >> u >> v >> c;

            if (c == 'L') {
                a[u].first = v;
            } else {
                a[u].second = v;
            }
            p[v] = u;
        }

        for (int i = 1; i <= 3; i++) {
            cout << a[i].first << " " << a[i].second << "\n";
        }

        int root_index = -1;
        for (int i = 1; i <= 1000; i++) {
            if (a[i].first != -1 or a[i].second != -1) {
                if (p[i] == -1) {
                    assert (root_index == -1);
                    root_index = i;
                }
            }
        }
        cout<<root_index << "\n";
        flush (cout);


        BSTNode* root = new BSTNode;
        root -> key = root_index;
        root -> paren = nullptr;
        
        stack <pair<BSTNode*,int> > s;
        pair<BSTNode*,int> y;
        s.push ({root,root_index});

        while (!s.empty()) {
            y = s.top();
            s.pop();
            int u = y.second;
            
            if (a[u].first != -1) {
                BSTNode *cur = new BSTNode;
                y.first -> left = cur;
                cur -> key = a[u].first;
                cur -> paren = y.first;
                s.push ({cur,cur -> key});
            } else {
                y.first -> left = nullptr;
            }
            if (a[u].second != -1) {
                BSTNode *cur = new BSTNode;
                y.first -> right = cur;
                cur -> key = a[u].second;
                cur -> paren = y.first;
                s.push ({cur,cur -> key});
            } else {
                y.first -> right = nullptr;
            }
        }


        traversal(root);
        diameter(root);
        cout<<"diameter"<<ans;
        
    }
return 0;

}