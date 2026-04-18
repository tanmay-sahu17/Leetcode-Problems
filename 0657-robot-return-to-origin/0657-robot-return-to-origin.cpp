class Solution {
public:
    bool judgeCircle(string moves) {
         int horizontal=0;
        int vertical=0;
        for(int i=0;i<moves.size();i++){
           if(moves[i]=='U')vertical++;
           if(moves[i]=='L')horizontal--;
           if(moves[i]=='D')vertical--;
           if(moves[i]=='R')horizontal++;
             
             

        }
             if(vertical==0&&horizontal==0)return true;

         return false;
    }
};