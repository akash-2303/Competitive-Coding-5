// Time Complexity: O(n)
// Space Complexity: O(n)
// Did this code successfully run on Leetcode : Yes

// Approach: 
// 1. We will use BFS to traverse the tree level by level.
// 2. We will maintain a deque to store the nodes at each level.
// 3. At each level, we will find the maximum value and store it in a temp variable.
// 4. We will then push the left and right child of the node into the deque.
// 5. We will keep on doing this until the deque is empty.
// 6. We will return the result vector containing the maximum value at each level.

class Solution {
    public:
        vector<int> largestValues(TreeNode* root) {
            vector<int> result;
            if(root == nullptr){return result;}
            deque<TreeNode*> q;
            q.push_back(root);
            while(!q.empty()){
                int temp = INT_MIN;
                int count = q.size();
                for(int i = 0; i < count; i++){
                    TreeNode* node = q.front();
                    q.pop_front();
                    temp = max(temp, node -> val);
                    if(node -> left != nullptr){
                        q.push_back(node -> left);
                    }
                    if(node -> right != nullptr){
                        q.push_back(node -> right);
                    }
                }
                result.push_back(temp);
            }
            return result;
            
        }
    };