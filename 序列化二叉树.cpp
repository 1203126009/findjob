//https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=3&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=4
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
private:
    TreeNode* decode(char *&str) {
        if(*str=='#'){
            str++;
            return NULL;
        }
        int num = 0;
        while(*str != ',')
            num = num*10 + (*(str++)-'0');
        str++;
        TreeNode *root = new TreeNode(num);
        root->left = decode(str);
        root->right = decode(str);
        return root;
    }
public:
    char* Serialize(TreeNode *root) {  
        if(!root) return "#";
        string r = to_string(root->val);
        r.push_back(',');
        char *left = Serialize(root->left);
        char *right = Serialize(root->right);
        char *ret = new char[strlen(left) + strlen(right) + r.size()];
        strcpy(ret, r.c_str());
        strcat(ret, left);
        strcat(ret, right);
        return ret;
    }
    TreeNode* Deserialize(char *str) {
        return decode(str);
    }
};