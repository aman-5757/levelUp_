#include<iostream>
#include<vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



//Leetcode 1373
//isBST, max, min,sum

int maxSum = 0;
vector<int> maxSumBST(TreeNode* root) {
    if(root == nullptr){
        return {1,(int)-1e8, (int) 1e8, 0};
    }
    vector<int> la = maxSumBST(root->left);
    vector<int> ra = maxSumBST(root->right);
    bool isBST = la[0] && ra[0] && root->val<ra[1] && root->val > la[2];
    int sum = root->val+la[3]+ra[3];
    if(isBST){
        maxSum = max(maxSum,sum);
    }
    return{isBST?1:0,max(max(la[1],ra[1]),root->val), min(min(la[2],ra[2]), root->val)};
}

vector<int> maxSumBST_02(TreeNode* root) {
    if(root == nullptr){
        return {1,(int)-1e8, (int) 1e8, 0,0};
    }
    vector<int> la = maxSumBST_02(root->left);
    vector<int> ra = maxSumBST_02(root->right);
    bool isBST = la[0] && ra[0] && root->val<ra[2] && root->val > la[1];
    int sum = root->val+la[3]+ra[3];
    int maxSum = 0;
    if(isBST){
        maxSum = max(sum,max(la[4],ra[4]));
    }
    else{
        maxSum = max(la[4],ra[4]);
    }
    return{isBST?1:0,max(max(la[1],ra[1]),root->val), min(min(la[2],ra[2]), root->val),sum,maxSum};
}


//Leetcode 112  ========================================================================================================================
public boolean hasPathSum(TreeNode root, int sum) {   
    if(root == null )    return false;
    if(sum - root.val == 0 && root.left == null && root.right == null)  return true;
    return hasPathSum(root.left, sum-root.val) || hasPathSum(root.right, sum-root.val);
}


//Leetcode 113 ========================================================================================================================

vector<int> res;
vector<vector<int>> ans;
void pathSum_(TreeNode* root, int sum) {
    if(root == nullptr)    return;
    if(sum - root->val == 0 && root->left == nullptr && root->right == nullptr){
        vector<int> base(res);
        base.push_back(root->val);
        ans.push_back(base);
        return;
    }
    res.push_back(root->val);
    pathSum_(root->left,sum-root->val);
    pathSum_(root->right,sum-root->val);
    res.pop_back();
}

//Leetcode 98=======================================================================================================================================


//Leetcode 99 =======================================================================================================================================




//Leetcode 124 MAX SUM NODE TO NODE =================================================================================================

int maxSumNTN = (int)-1e8;
int maxPathSum_(TreeNode* root) {
    if(root == nullptr) return 0;
    int la = maxPathSum_(root->left);
    int ra = maxPathSum_(root->right);
    int max_ = max(la,ra);
    maxSumNTN = max(max_+root->val,max(root->val,max(la+ra+root->val,maxSumNTN)));
    return max(root->val,max_+root->val);        
}
int maxPathSum(TreeNode* root) {
    maxSumNTN = (int)-1e8;
    maxPathSum_(root);
    return maxSumNTN;
}

int main(){
    return 0;
}