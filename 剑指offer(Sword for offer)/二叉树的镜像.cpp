/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 方法1：先前序遍历这棵树的每个结点，如果遍历到的结点有子结点，就交换它的两个子节点，
// 当交换完所有的非叶子结点的左右子结点之后，就得到了树的镜像
class Solution {
public:
    void Mirror(TreeNode *r) {
        // 当r为空或r为叶子节点
        if(!r || (!r->left && !r->right)){
          return;
        }
        // 非叶子结点的左右子结点交换
        TreeNode *pTmp;
        pTmp = r->left;
        r->left = r->right;
        r->right = pTmp;
        // 递归
        Mirror(r->left);
        Mirror(r->right);
    }
};

// 方法2：我的傻瓜方法。画图举例可得，镜像树的中序序列是原树的中序序列的逆，镜像树的后序序列是原树的先序序列的逆
// 我先求得原树的序列，再得到镜像树的序列，从而构建出镜像树
class Solution {
public:
    void Mirror(TreeNode *r) {
        if(!r || (!r->left && !r->right)){return;}
        // 得到原树的先序和中序序列
        vector<int> in;
        vector<int> pre;
        inTree(r, in);
        preTree(r, pre);
        // 得到镜像树的中序序列和后序序列
        reverse(in.begin(), in.end()); // reverse函数是定义在<algorithm>里的逆序函数
        reverse(pre.begin(), pre.end()); // 此时in是镜像树的中序序列，pre是镜像树的后序序列
        int tree_size = pre.size();
        TreeNode* t = inPostTree(in, pre);
        // 要注意，inPostTree函数返回的是一个新的树，具有新的地址
        // 而Mirror函数是void类型的，要达到题目要求，就必须修改r指针指向的内容
        // 就需要用到memcpy函数，将新的树的内容拷贝到r指针所指向的地址上去
		memcpy(r, t, tree_size*sizeof(TreeNode));
    }
    
    // 将树的先序遍历存到vector里
    void preTree(TreeNode *t, vector<int> &pre){
        if(t){
            pre.push_back(t->val);
            preTree(t->left, pre);
            preTree(t->right, pre);
        }
    }
    // 将树的中序遍历存到vector里
    void inTree(TreeNode *t, vector<int> &in){
        if(t){
            inTree(t->left, in);
            in.push_back(t->val);
            inTree(t->right, in);
        }
    }
    
    // 根据树的中序和后序构建二叉树
    TreeNode* inPostTree(vector<int> in, vector<int> post){
        if(in.size()==0||post.size()==0||in.size()!=post.size()){
                return NULL;
        }
        // 后序遍历的最后一个元素为树的头结点
        TreeNode* node = new TreeNode(post.back());
        vector<int> leftIn;
        vector<int> leftPost;
        vector<int> rightIn;
        vector<int> rightPost;
        int rootIndex = 0;
        // 找到中序序列中头结点的位置索引
        for(int i = 0; i < in.size(); ++i){
            if(in[i] == post.back()){
                rootIndex = i;
                break;
            }
        }
        // 中序序列以rootIndex为界，左边m个元素为左子树的中序序列，右边n个元素为右子树中序序列
        // 后序序列的前m个元素为左子树的后序序列，接下去的n个元素为右子树的后序序列
        for(int i = 0; i < rootIndex; ++i){
            leftIn.push_back(in[i]);
            leftPost.push_back(post[i]);
        }
        for(int i = rootIndex + 1; i < in.size(); ++i){
            rightIn.push_back(in[i]);
        }
        for(int i = rootIndex; i < in.size() - 1; ++i){
            rightPost.push_back(post[i]);
        }
        // 遍历得到头结点的左子树、右子树
        node->left = inPostTree(leftIn, leftPost);
        node->right = inPostTree(rightIn, rightPost);
        return node;
    }
};
