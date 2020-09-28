#include<iostream>
#include<vector>
#include<queue>
// #include<algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node * left = nullptr;
    Node * right = nullptr;
    Node(int data){
        this->data = data;
    }
};

int  idx = 0;
Node * constructTree(vector<int> & arr){
    if(arr[idx] == -1 || idx == arr.size()){
        idx++;
        return nullptr;
    }
    Node * node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void inOrder(Node *node){
    if(node == nullptr){
        return;
    }
    inOrder(node->left);
    cout<<node->data<<" ";
    inOrder(node->right);
}

int size(Node *node){
    if(node == nullptr) return 0;
    return 1+ size(node->left) + size(node->right);

}

int height(Node *node){
    return node == nullptr ? -1 : max(height(node->left),height(node->right))+1;
}

int maximum(Node *node){
    return node == nullptr ? -1e8 : max(max(maximum(node->left),maximum(node->right)),node->data);
}

int minimum(Node *node){
    return node == nullptr ? 1e8 : min(min(minimum(node->left),minimum(node->right)),node->data);
}

bool find(Node *node, int data){
    if(node == nullptr) return false;
    if(node->data == data)  return true;
    return find(node->left,data) || find(node->right,data);
}

bool nodeToRoot(Node * node, int data, vector<Node *> & arr){
    if(node == nullptr) return false;
    if(node->data == data){
        arr.push_back(node);
        return true;
    }
    bool res = nodeToRoot(node->left,data,arr) || nodeToRoot(node->right,data,arr);
    if(res) arr.push_back(node);
    return res;
}


vector<Node *>  nodeToRoot_02(Node * node, int data){
    if(node == nullptr) return {};
    if(node->data == data){
        vector<Node *> base;
        base.push_back(node);
        return base;
    }
    vector<Node *> la = nodeToRoot_02(node->left,data);
    if(la.size()!=0){
        la.push_back(node);
        return la  ; 
    }
    vector<Node *> ra = nodeToRoot_02(node->right,data);
    if(ra.size()!=0){
        ra.push_back(node);
        return ra ; 
    }
    return {};
}

Node * lowestCommonAncestor(Node * root, Node * p, Node * q){
    vector<Node *> arr1,arr2;
    bool res = nodeToRoot(root,p->data,arr1) && nodeToRoot(root,q->data,arr2);
    if(!res)    return nullptr;
    int i = arr1.size()-1;
    int j = arr2.size()-1;
    Node * LCA = nullptr;
    while(i!=0 && j!=0) {
        if(arr1[i]->data != arr2[j]->data)  break;
        LCA = arr1[i];
        i--;
        j--;
    }
    return LCA;
}


int distanceBW2Leaf(Node * root, Node * p, Node * q){
    vector<Node *> arr1, arr2;
    bool res = nodeToRoot(root,p->data,arr1) && nodeToRoot(root,q->data,arr2);
    if(!res)    return 0;
    int i = arr1.size()-1;
    int j = arr2.size()-1;

    int LCA = 0;
    while(i>=0 && j >= 0){
        if(arr1[i]->data!=arr2[j]->data)    break;
        LCA++;
        i--;    j--;
    }
    return arr1.size()+arr2.size()-(2*LCA);
}

int diameter(Node * node){
    if(node == nullptr) return 0;
    int ld = diameter(node->left);
    int rd = diameter(node->right);
    int lh = height(node->left);
    int rh = height(node->right);
    return max(max(ld,rd),lh+rh+2);
}

pair<int, int> diameter_02(Node * node){
    if(node == nullptr) return {0,-1};
    pair<int, int > la = diameter_02(node->left);
    pair<int, int > ra = diameter_02(node->right);

    int d = max(max(la.first, ra.first), la.second+ra.second+2);
    int h = (la.second,ra.second)+1;
    return {d,h};
}

void display(Node * root){
    if(root == nullptr) return;
    string str = "";
    str += root->left == nullptr ? "." : to_string(root->left->data);
    str += " <- " + to_string(root->data) + " -> ";
    str += root->right == nullptr ? "." : to_string(root->right->data);
    cout<<str<<endl;
    display(root->left);
    display(root->right);
}

//---------------BST ALL SOL----------------------------
class allSolPair{
    public:
        bool isBST = false;
        int maxEle = -1e8;
        int minEle = 1e8;
        bool isBal = false;
        int height = -1;
        int countOfBST = 0;
        int maxSizeOfBST = 0;
        Node *maxBSTNode = nullptr;
};


allSolPair bstAll(Node * node){
    if(node == nullptr){
        allSolPair base;
        base.isBST = true;
        return base;
        
    }

    allSolPair la = bstAll(node->left);
    allSolPair ra = bstAll(node->right);

    allSolPair myAns;
    if(la.isBST && ra.isBST && la.maxEle<node->data && node->data <ra.minEle){
        myAns.isBST = true;
        myAns.countOfBST += 1;
        myAns.maxBSTNode = node;
        myAns.maxSizeOfBST = 1+la.maxSizeOfBST+ra.maxSizeOfBST;
    }

    myAns.countOfBST = la.countOfBST+ra.countOfBST;

    myAns.maxEle = max(max(la.maxEle,ra.maxEle),node->data);
    myAns.minEle = min(min(la.minEle,ra.minEle),node->data);

    if(la.isBal && ra.isBal && abs(ra.height-la.height)<2){
        myAns.isBal = true;
    }
    myAns.height = 1+ max(la.height,ra.height);
    if(!myAns.isBST){
        myAns.maxBSTNode = la.maxSizeOfBST>ra.maxSizeOfBST ? la.maxBSTNode : ra.maxBSTNode;
        myAns.maxSizeOfBST = la.maxSizeOfBST>ra.maxSizeOfBST ? la.maxSizeOfBST : ra.maxSizeOfBST;
    }

    return myAns;
}



//========== BFS ================================================================================
//========== LevelOrder ================================================================================
void levelOrder_01(Node * node){
    queue<Node *> qu;
    qu.push(node);
    while(qu.size()!=0)
    {
        Node * rvtx = qu.front();
        qu.pop();
        cout<<rvtx->data<<" ";
        if(rvtx->left)  qu.push(rvtx->left);
        if(rvtx->right)  qu.push(rvtx->right);

    }

}

void levelOrder_02(Node * node){
    queue<Node *> qu;
    qu.push(node);
    qu.push(nullptr);
    while(qu.size()!=0)
    {
        Node * rvtx = qu.front();
        qu.pop();
        cout<<rvtx->data<<" ";
        if(rvtx->left)  qu.push(rvtx->left);
        if(rvtx->right)  qu.push(rvtx->right);
        if(!qu.front()){
            cout<<endl;
            qu.pop();
            qu.push(nullptr);
        }
    }

}

void levelOrder_03(Node * node){            //MOst Demand
    queue<Node *> qu;
    qu.push(node);
    int level = 0;

    while(qu.size()!=0)
    {   
        cout<<"Level is : "<<level<< " -> ";
        int size = qu.size();
        while(size-->0){
        Node * rvtx = qu.front();
        qu.pop();
        cout<<rvtx->data<<" ";
        if(rvtx->left)  qu.push(rvtx->left);
        if(rvtx->right)  qu.push(rvtx->right);
        }
        level++;
        cout<<endl;

    }

}


//VIEWS=================================================================================================
void leftView(Node * node){
    queue<Node *> qu;
    qu.push(node);
    while(qu.size()!=0)
    {   
        int size = qu.size();
        cout<<qu.front()->data<<" ";
        while(size-->0){
        Node * rvtx = qu.front();
        qu.pop();
        
        if(rvtx->left)  qu.push(rvtx->left);
        if(rvtx->right)  qu.push(rvtx->right);
        }
        cout<<endl;
    }
}

void rightView(Node * node){
    queue<Node *> qu;
    qu.push(node);

    while(qu.size()!=0)
    {   
        
        int size = qu.size();
        Node * prev = nullptr;
        while(size-->0){
        Node * rvtx = qu.front();
        qu.pop();
        if(rvtx->left)  qu.push(rvtx->left);
        if(rvtx->right)  qu.push(rvtx->right);
        prev = rvtx;
        }
        cout<<prev->data<<" ";
        cout<<endl;

    }

}




void solve(){
    vector<int> arr = {10, 20, 30, 40, -1, -1, 50, -1, -1, 60, 70, -1, 80, -1, -1, -1, 90, 100, -1, 120, -1, -1, 110, 130, -1, -1, -1};
    Node * root = constructTree(arr);
    display(root);
}

void basic(){
    vector<int> arr = {10, 20, 30, 40, -1, -1, 50, -1, -1, 60, 70, -1, 80, -1, -1, -1, 90, 100, -1, 120, -1, -1, 110, 130, -1, -1, -1};
    Node * root = constructTree(arr);
    // inOrder(root);
    // cout<<"\n";
    // cout<<size(root)<<endl;
    // cout<<height(root)<<endl;
    // cout<<maximum(root)<<endl;
    // cout<<minimum(root)<<endl;
    // cout<<find(root,40)<<endl;

    //-----------------------------------
    // vector<Node *> pis; 
    // cout<<nodeToRoot(root,90,pis)<<endl;
    // for(Node * ele : pis)   cout<<ele->data<<" ";

    cout<<diameter(root);
}

void bfs(){
    vector<int> arr = {10, 20, 30, 40, -1, -1, 50, -1, -1, 60, 70, -1, 80, -1, -1, -1, 90, 100, -1, 120, -1, -1, 110, 130, -1, -1, -1};
    Node * root = constructTree(arr);
    // levelOrder_01(root);
    // levelOrder_02(root);
    levelOrder_03(root);
}

void view(){
    vector<int> arr = {10, 20, 30, 40, -1, -1, 50, -1, -1, 60, 70, -1, 80, -1, -1, -1, 90, 100, -1, 120, -1, -1, 110, 130, -1, -1, -1};
    Node * root = constructTree(arr);
    // leftView(root);
    rightView(root);
}

int main(){
    // solve();
    // basic();
    // bfs();
    view();
    return 0;
}