class Solution {
public:
    string reverse(string word, int start, int end){
        while(start<=end)
        {
            char ch=word[start];
            word[start]=word[end];
            word[end]=ch;
            // cout<<word<<" ";
            start++;
            end--;
        }
        return word;
    }
    string reversePrefix(string word, char ch) {
        int n=word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]==ch)
                return reverse(word, 0, i);
        }
        return word;
    }
};