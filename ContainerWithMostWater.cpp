#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int len = (int)height.size();
   
    int i = 0, j = len-1, mxArea = 0, area = 0;

    while (i<j)
    {
        area = (j-i) * min(height[i],height[j]);
        //cout << area << " ## " << mxArea << " i j "<< height[i] << " " << height[j] << endl;
        if (area > mxArea) mxArea = area;
        if (height[i]<height[j]) i++;
        else j--;
      
    }
    return mxArea;
}

int main() {
    int height[] = {1,0,0,0,0,0,0,2,2}; //{1,8,6,2,5,4,8,3,7};
    int arrSize = sizeof(height)/sizeof(int);

    vector<int> vHeight(height, height+arrSize);
    cout << maxArea(vHeight) << endl;
}
