#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
using namespace std;

struct TreeNode
{
	TreeNode *left;
	TreeNode *right;
	int val;
	//TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	//TreeNode(){}
};

void Link(TreeNode *nodes, int parent, int left, int right)
{
	if (left != -1)
	{
		nodes[parent].left = &nodes[left];
	}
	if (right != -1)
	{
		nodes[parent].right = &nodes[right];
	}
}

int Depth_Pre(TreeNode *root)
{
    if(!root) return 0;
    int i = Depth_Pre(root->left);
    int j = Depth_Pre(root->right);
    return max(i, j) + 1;
}

void Level(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);
    TreeNode *temp;
    while(!q.empty())
    {
        temp = q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

}



int main(int argc, char* argv[])
{
    int n, a, b;
    while (cin>>n)
    {
        TreeNode test1[1005] = {0};
        for (int i = 0; i < n; i++)
        {
            test1[i].val = i;
        }

        set<int> mp;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>a>>b;
            if (mp.find(a) == mp.end())
            {
                mp.insert(a);
                Link(&test1[0], a, b, -1);
            }
            else
            {
                Link(&test1[0], a, -1, b);
            }
        }

        cout<<Depth_Pre(&test1[0])<<endl;
        Level(&test1[0]);
    }
	return 0;
}
