class RideSharingSystem
{
public:
    int n1;
    int n2;
    set<pair<int, int>> riders;
    set<pair<int, int>> drivers;
    unordered_map<int, int> id_idx1;
    // unordered_map<int, int> id_idx2;
    RideSharingSystem()
    {
        n1 = 0;
        n2 = 0;
    }

    void addRider(int riderId)
    {
        riders.insert({n1, riderId});
        id_idx1[riderId] = n1;
        n1++;
    }

    void addDriver(int driverId)
    {
        drivers.insert({n2, driverId});
        // id_idx2[driverId] = n2;
        n2++;
    }

    vector<int> matchDriverWithRider()
    {
        if (riders.empty() || drivers.empty())
            return {-1,-1};
        auto temp1 = *riders.begin();
        auto temp2 = *drivers.begin();
        riders.erase(riders.begin());
        drivers.erase(drivers.begin());
        id_idx1.erase(temp1.second);
        // id_idx2.erase(temp2.second);
        return {temp2.second, temp1.second};
    }

    void cancelRider(int riderId)
    {
        if (id_idx1.find(riderId) != id_idx1.end())
        {
            riders.erase({id_idx1[riderId], riderId});
            id_idx1.erase(riderId);
        }
    }
};