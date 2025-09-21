#include <bits/stdc++.h>
using namespace std;

struct PairHash {
    size_t operator()(const pair<int, int> &p) const {
        return ((long long)p.first << 32) ^ p.second;
    }
};

class MovieRentingSystem {
public:
    unordered_map<int, set<pair<int, int>>> unrented; // movie -> {price, shop}
    unordered_map<pair<int, int>, int, PairHash> entry_list; // (shop,movie) -> price
    set<tuple<int, int, int>> rented_st; // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>> &entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            unrented[movie].insert({price, shop});
            entry_list[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> result;
        auto &temp = unrented[movie];
        for (auto [price, shop] : temp) {
            if (result.size() >= 5) break;
            result.push_back(shop);
        }
        return result;
    }

    void rent(int shop, int movie) {
        int price = entry_list[{shop, movie}];
        unrented[movie].erase({price, shop});
        rented_st.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = entry_list[{shop, movie}];
        unrented[movie].insert({price, shop});
        rented_st.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> result;
        for (auto [price, shop, movie] : rented_st) {
            if (result.size() >= 5) break;
            result.push_back({shop, movie});
        }
        return result;
    }
};
