Question Link: https://leetcode.com/problems/can-place-flowers/description/

Solution:
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int len = flowerbed.size(), can_place = 0;

    if(len == 1 && flowerbed[0] == 0) return (n <= 1);

    for(int i=0;i<len;i++)
    {
        if(flowerbed[i] == 1) continue;

        if(i-1 >= 0 && flowerbed[i-1] == 0 && i+1 < len && flowerbed[i+1] == 0)
        {
            can_place++;
            flowerbed[i] = 1;
        }
        else if(i == 0 && i+1 < len && flowerbed[i+1] == 0)
        {
            can_place++;
            flowerbed[i] = 1;
        }
        else if(i == len-1 && i-1 >= 0 && flowerbed[i-1] == 0)
        {
            can_place++;
            flowerbed[i] = 1;
        }
    }

    return (n <= can_place);
}
