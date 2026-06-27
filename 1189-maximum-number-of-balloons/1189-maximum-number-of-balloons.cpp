class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int>st;
        string k="balloon";
        for(char i:k) st[i]=1;
        int cnt=1e4;
        for(char i:text)if(st.find(i)!=st.end())st[i]++;
        for(auto i:st)cnt=min(cnt,--i.second);

        while(cnt*2>=st['l'] || cnt*2>=st['o']) cnt--;
        return cnt;

    }
};