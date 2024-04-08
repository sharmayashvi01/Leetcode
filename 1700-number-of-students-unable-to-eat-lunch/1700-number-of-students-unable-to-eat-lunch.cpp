class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        int n = students.size();
        int zero = 0, one = 0;
        for(int i=0 ; i<n ; i++)
        {
            if(students[i] == 0) zero++;
            else one++;
        }
        
        for(auto sandwich : sandwiches)
        {
            if(sandwich == 1 && one) one--;
            else if (sandwich == 1 && !one) return zero;
            
            else if(sandwich == 0 && zero) zero--;
            else if(sandwich == 0 && !zero) return one;           
        }
        return 0;
    }
};