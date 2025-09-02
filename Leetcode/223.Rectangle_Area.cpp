#include <bits/stdc++.h>
using namespace std;

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2)
{
    // given coordinates of 2 rectangles
    // return the total area covered by the two rectangles
    // 1st rect: bottom-left corner (ax1, ay1) , top-right corner (ax2, ay2)
    // 2nd rect: bottom-left corner (bx1, by1) , top-right corner (bx2, by2)
    // total area = area of rect1 + area of rect2 - area of overlap(if any)
    int area1 = (ax1 - ax2) * (ay1 - ay2);
    int area2 = (bx1 - bx2) * (by1 - by2);
    // overlapping area:
    bool doesOverlap = true;
    if (ax1 >= bx2 || bx1 >= ax2)
    {
        doesOverlap = false;
    }
    if (ay1 >= by2 || by1 >= ay2)
    {
        doesOverlap = false;
    }
    if (!doesOverlap)
    {
        return area1 + area2;
    }
    int x_overlap = min(bx2, ax2) - max(bx1, ax1);
    int y_overlap = min(by2, ay2) - max(by1, ay1);
    int overlap_area = x_overlap * y_overlap;
    return area1 + area2 - overlap_area;
}

int main()
{

    return 0;
}