 vector <int> bottomView(Node *root) {
        // Your Code Here
        vector <int> ans;
        if(root==NULL)
            return ans;
        map<int,int>hash;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            Node* node=it.first;
            int line=it.second;
            hash[line]=node->data;

            if(node->left!=NULL){
                q.push({node->left,line-1});
            }
            if(node->right!=NULL){
                q.push({node->right,line+1});
            }
        }
        for(auto it:hash){
            ans.push_back(it.second);
        }
        return ans;
    }