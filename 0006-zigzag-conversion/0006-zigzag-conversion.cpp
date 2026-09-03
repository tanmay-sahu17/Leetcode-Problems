class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1||s.size()<=numRows){
            return s;
        }
        int row=0;
        int direction=1;

        vector<string>rows(numRows);

        for(char ch:s){
            rows[row]+=ch;
              
              if(row==0){
                 direction=1;
              }
              else if(row==numRows-1){
                direction=-1;
              }
              row+=direction;

        }

        string ans="";

        for(auto row:rows){
            ans+=row;
        }     
        return ans;  
    }
};