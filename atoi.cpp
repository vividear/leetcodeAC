class Solution {
public:
    int myAtoi(string str) {
        int result=0;
        int start=0;
        int sign=1;
        while(str[start]==' ')   //还要处理空格输入，真是够烦
        start++;
        if(str[start]=='-'||str[start]=='+')   
       {
            if (str[start]=='-') sign=-1;
            start++;
       }
        for(int i=start;i<str.size();i++)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
            int tempoverflow=result;
            result=(str[i]-'0')+result*10;
            if (tempoverflow!=(result-(str[i]-'0'))/10||tempoverflow>0&&result<0)
            {
                result=2147483647;   //发生溢出
                if(sign==-1) return -1*(result+1);  //溢出边界这个问题我真是要醉了
                break;
            }
            }
            else break;
        }
            return sign*result;
    }
};
