class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        // cout<<endl;
        int n=tokens.size();
        int i=0,j=n-1,score=0;
        sort(begin(tokens),end(tokens));
        // while(i<=j){            
        //     if(score && power<tokens[i])
        //         power+=tokens[j],    score--,    j--;
        //     else if(power>0 && power>=tokens[i])
        //         power-=tokens[i],    score++,    i++;
            // cout<<"power="<<power<<" and score="<<score<<endl;
        // }
        int maxScore=0;
        while(i<=j)
        {
            if(power>=tokens[i]){
                power -= tokens[i], score++,    i++;
                maxScore=max(maxScore,score);
            }
            else if(score>0)
                power += tokens[j], score--,    j--;
            else
                return maxScore;
        }
        return maxScore;
    }
};