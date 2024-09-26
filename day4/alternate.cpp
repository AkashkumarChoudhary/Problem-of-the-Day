 void rearrange(vector<int> &arr) {
        // code here
        queue<int>pos;
        queue<int>neg;
        for(int i = 0; i<arr.size(); i++){
            if(arr[i]>=0) pos.push(arr[i]);
            else neg.push(arr[i]);
        }
        arr.clear();
        while(!pos.empty() && !neg.empty()){
            arr.push_back(pos.front());
            arr.push_back(neg.front());
            pos.pop();
            neg.pop();
        }
        while(!pos.empty()){
            arr.push_back(pos.front());
            pos.pop();
        }
        while(!neg.empty()){
            arr.push_back(neg.front());
            neg.pop();
        }
    }