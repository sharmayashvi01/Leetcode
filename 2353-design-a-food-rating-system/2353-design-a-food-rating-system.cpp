class FoodRatings {
public:
    
    unordered_map<string,int> food_rating;
    // food and its rating
    unordered_map<string, set<pair<int,string>>> cuisine_rating_food;
    // cuisine , set of pair<rating, food> ; set=to maintain the order
    unordered_map<string,string> food_cuisine;
    // food and its cuisine
    
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++)
        {
            string food=foods[i];
            string cuisine=cuisines[i];
            int rating=ratings[i];
            
            cuisine_rating_food[cuisine].insert({-rating,food});
            //<string, set<pair<int,string>>>
            // cuisine wale index pr, ith index wala food aur rating 
            food_cuisine[food] = cuisine;   // <string,string>
            food_rating[food]=rating;       // <string,int>
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisine[food];
        int oldRating = food_rating[food];
        food_rating[food] = newRating;
        cuisine_rating_food[cuisine].erase({-oldRating,food});
        cuisine_rating_food[cuisine].insert({-newRating,food});
        
    }
    
    string highestRated(string cuisine) {
        return begin(cuisine_rating_food[cuisine])->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */