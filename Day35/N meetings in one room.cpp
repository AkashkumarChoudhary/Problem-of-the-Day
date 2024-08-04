 static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1] < b[1];
    }
    int maxMeetings(int n, int start[], int end[]) {
        vector<vector<int>>matrix(n, vector<int>(2));
        for(int i=0; i<n; i++)
        {
            matrix[i][0] = start[i];
            matrix[i][1] = end[i];
        }
        
        sort(matrix.begin(),matrix.end(),cmp);
        
        int selmon = matrix[0][0];
        int elivis = matrix[0][1];
        
        int i = 0;
        int j = 1;
        int cnt = 1;
        while(i < n-1)
        {
            if(elivis < matrix[i+1][0])
            {
                cnt++;
                elivis = matrix[i+1][1];
                i++;
            }
            else
            {
                i++;
            }
        }
        return cnt;
    }