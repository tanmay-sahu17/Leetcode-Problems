class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string temp="";
        int i = 0;
        while (i<n) {
           while(i<n&&s[i]==' ')i++;
          if(i>=n)break; 
        if(!temp.empty())temp+=" ";
             while(i<n&&s[i]!=' '){
            temp+=s[i++];
           }
        }

       reverse(temp.begin(),temp.end());
        int start=0;
        for(int i=0;i<=temp.size();i++){
            if(i==temp.size()||temp[i]==' '){
                reverse(temp.begin()+start,temp.begin()+i);
                start=i+1;
            }
        }

        return temp;
    }
};
