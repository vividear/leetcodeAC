class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        if(len==0) return 0;
        int c(0),left(1),result(1);
        for(int i=1;i<len;i++)
        {
            if(ratings[i]>=ratings[i-1]){
                if(c>0){
                    if(c<left) result+=c*(c+1)/2;
                    else result+=(c+2)*(c+1)/2-left;
                    left=1;
                }
                if(ratings[i]==ratings[i-1]) left=0;
                    left+=1;
                    result+=left;
                    c=0;
            }
            else{
                c+=1;
            } 
        }
         if(c>0){
                if(c<left) result+=c*(c+1)/2;
                else result+=(c+2)*(c+1)/2-left;
            }
        return result;
    }
};
