class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        int side1 = nums[0];
        int side2 = nums[1];
        int side3 = nums[2];
        // Check if the sides can form a valid triangle first
        if (side1 + side2 <= side3 || side1 + side3 <= side2 ||
            side2 + side3 <= side1)
        {
            return "none"; // If it cannot form a triangle
        }

        if (side1 == side2 && side2 == side3)
        {
            return "equilateral";
        }
        if ((side1 == side2 && side2 != side3) ||
            (side1 == side3 && side1 != side2) ||
            (side2 == side3 && side1 != side2))
        {
            return "isosceles";
        }
        // some of any 2 sides>third side for scalene
        return "scalene";
    }
};