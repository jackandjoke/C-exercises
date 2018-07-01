#include<iostream>
#include<string>


using namespace std;

class TreeNode{
    public:
        TreeNode():value(""),count(0),left(nullptr),right(nullptr){}
        TreeNode(string v,int c):count(c),value(v),left(nullptr),right(nullptr){}
        TreeNode(const TreeNode &rhs):value(rhs.value),count(rhs.count){
            if(rhs.left)
                left = copy(rhs.left);
            if(rhs.right)
                right = copy(rhs.right);
        }
    private:
    string value;

    int count;
    TreeNode *left, *right;

    TreeNode *copy(const TreeNode* rhs){
        TreeNode *ret = new TreeNode(rhs->value,rhs->count);
        if(rhs->left)
            ret->left = copy(rhs->left);
        if(rhs->right)
            ret->right = copy(rhs->right);
        return ret;
    }

};


int main(){
    TreeNode t1("t",1);    
    TreeNode t2("k",2);    
    TreeNode t3 = t1;
    TreeNode t4 = t2;

    return 0;
}
