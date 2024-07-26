 #include<bits/stdc++.h>
 bool kPangram(string str, int k) {
       map<char,int>m;
       for(auto i:str) {
           if(i>='a' and i<='z') m[i]++;
       }
       int count=0;
       for(auto i:m){
           if(i.second>1) count+=(i.second-1);
       }
       if(count<k) k=count;
       for(char i='a';i<='z';i++){
           if(!m[i]){
               if(k==0) return false;
               else k--;
           }
       }
       return true;
    }
