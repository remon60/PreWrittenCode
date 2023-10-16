// Transform S into new string with special characters inserted.

string convertString(const string &s)
{
    string newString;
    for(int i=0;i<s.size();i++)
    {
        newString+="#"+s.substr(i,1);
    }
    newString+="#";
    return newString;
}



string longestPalindromeSubstring(const string &s)
{
    string str = convertString(s);
    int c=0,r=0; //current center,right boundary
    memset(LPS,0,sizeof(LPS));
    int len =(s.size())*2+1;
    int maxlen=0,centerIndex=0;
    for(int i=0;i<str.size();i++)
    {
        int mirror =2*c-1;//corresponding letter in the palindromic subString
        if(r>i)
        {
            LPS[i]=min(r-i,LPS[mirror]);
        }
        int a=i+(1+LPS[i]);
        int b=i-(1+LPS[i]);
        //expand around center i
        while(a<len&&b>=0&&str[a]==str[b])
        {
            LPS[i]++;
            a++;
            b--;
        }
        //Update c,r in case if the palindrome centered at i expands past r
        if(i+LPS[i]>r)
        {
            c=i;
            r=i+LPS[i];
        }
    }
    //Find the longest palindrome length in p.
        for (int i = 0; i < str.size() ; i++) {
        if (LPS[i] > maxlen) {
            maxlen = LPS[i];
            centerIndex = i;
        }
    }
    return s.substr((centerIndex-maxlen)/2,maxlen);
}
