class Solution {
public:
    bool isPalindrome(string s) {
       int l=0;
       int r=s.size()-1;
      while(l<s.size()-1&&s[l]==' ')l++;
      while(r>=0&&s[r]==' ')r--;

       while(l<=r){
        
        while(l<r&&!isalnum(s[l]))l++;
        while(l<r&&!isalnum(s[r]))r--;
        if(tolower(s[l])!=tolower(s[r]))return false;
        l++;
        r--;
       }
       return true;

    }
};