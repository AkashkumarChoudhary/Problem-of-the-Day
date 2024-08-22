vector<int>tsort(int v, vector<int>adj[] )
  {
      int indegree[v]={0};
      for(int i=0;i<v;i++)
      {
          for(auto it:adj[i])
          indegree[it]++;
      }
      
      queue<int>qq;
      
      for(int i=0;i<v;i++)
      {
          if(indegree[i]==0)
          qq.push(i);
      }
       vector<int>topo;
      while(!qq.empty())
      {
          int node=qq.front();
          qq.pop();
          
          topo.push_back(node);
          for(auto it:adj[node])
          {
              indegree[it]--;
              if(indegree[it]==0)
              {
                  qq.push(it);
              }
          }
      }
     
     return topo;
      
  }
    string findOrder(string dict[], int n, int k) {
        
        vector<int>adj[k];
        
        for(int i=0;i<n-1;i++)
        {
            string s1=dict[i];
            string s2=dict[i+1];
            int nn=s1.size();
            int m=s2.size();
            
            
            for(int j=0;j<min(nn,m);j++)
            {
                if(s1[j]!=s2[j])
                {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        
        vector<int>ans=tsort(k,adj);
        string an="";
        
        for(auto it:ans)
        {
            an+=(it+'a');
        }
        return an;
    }