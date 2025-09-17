class FoodRatings
{
public:
    unordered_map<string, pair<string, int>> cache; // food->  {cusines,rating}
    unordered_map<string, set<pair<int, string>>> mp;
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            cache[foods[i]] = {cuisines[i],
                               ratings[i]};
            mp[cuisines[i]].insert({-1 * ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        int old_rating = cache[food].second;
        string cusine = cache[food].first;
        cache[food].second = newRating;
        mp[cusine].erase({-1*old_rating, food});
        mp[cusine].insert({-1*newRating, food});
    }

    string highestRated(string cuisine)
    {
        auto result = *mp[cuisine].begin();
        return result.second;
        }
};