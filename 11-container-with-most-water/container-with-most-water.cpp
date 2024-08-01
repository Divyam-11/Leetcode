class Solution {
public:
    int maxArea(vector<int>& height) {
     int i = 0;
     int j = height.size() - 1;
     int max_area = 0;
     int area = 0;
     while (i < j)      
     {
        area = min(height[i],height[j]) * (j-i);
         max_area = max(area,max_area);
    if(height[i]<height[j]){
            i++;
        }
        else{
            j--;
        }
  
            

     }
        return max_area;
    }
}; 