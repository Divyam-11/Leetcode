
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Robot
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1,0}, {0,-1}};
    vector<string> dirs = {"East", "North", "West", "South"};
    int ptr;
    int width, height;
    int x, y;
    Robot(int width, int height)
    {
        this->width = width-1;
        this->height = height-1;
        x = 0;
        y = 0;
        ptr = 0;
    }

    void step(int num)
    {
        int tempx = 0, tempy = 0;
        int h = height;
        int w = width;
        num = num % (2*(h+w));
        if(num == 0) num = 2*(h+w);
        while (num)
        {

            tempx = x + dir[ptr].first * num;
            tempy = y + dir[ptr].second * num;
           
            int overflow = 0;
            if (tempx < 0)
            {
                overflow = -tempx;
                tempx = 0;
            }
            if (tempx > width)
            {
                overflow = tempx - width;
                tempx = width;
            }
            if (tempy < 0)
            {
                overflow = -tempy;
                tempy = 0;
            }
            if (tempy > height)
            {
                overflow = tempy - height;
                tempy = height;
            }
            if (overflow)
            {
                ptr = (ptr + 1) % 4;
                num = overflow;
            }

            else
            {
                num = 0;
            }
            x = tempx;
            y = tempy;
        }
        // cout<<x<<" "<<y<<" "<<dirs[ptr]<<endl;
    }

    vector<int> getPos()
    {
        return {x, y};
    }

    string getDir()
    {
        return dirs[ptr];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */

// int main()
// {
//     return 0;
// }