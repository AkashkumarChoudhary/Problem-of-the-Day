void Lview(Node *root, int level ,vector<int>&ans){
    if(!root)
    return ;
    if(level == ans.size())
    ans.push_back(root->data);
    Lview(root->left,level+1,ans);
    Lview(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   if(!root)
   return ans;
    Lview(root, 0, ans); // Call Lview with initial level 0
    return ans;
}