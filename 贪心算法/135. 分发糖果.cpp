class Solution {
public:
    //贪心算法
    //先正序遍历, 从左到右，对"右>左"的关系, 进行处理(右 = 左 + 1);   [3,2,1,1,2,2,3]
    //再逆序遍历, 从右到左, 对"左>右"的关系, 进行处理(左 = max(左本身, 右 + 1));
    int candy(vector<int>& ratings) 
    {
        vector<int> deliveryCandy(ratings.size());
        deliveryCandy[0] = 1;

        //正序遍历
        for(int i = 1; i < ratings.size(); ++i)
        {
            if(ratings[i] > ratings[i - 1]){
                deliveryCandy[i] = deliveryCandy[i - 1] + 1;
            }
            else{
                deliveryCandy[i] = 1;
            }

        }

        //逆序遍历
        for(int i = ratings.size() - 2; i >= 0; --i)
        {
            if(ratings[i] > ratings[i + 1]){
                deliveryCandy[i] = max(deliveryCandy[i], deliveryCandy[i + 1] + 1);
            }
        }
        int res = 0;
        for(int e : deliveryCandy)
            res += e;

        return res;
    }
};

// 错误
// class Solution {
// public:
//     int candy(vector<int>& ratings) 
//     {
//         pair<int, int> minRating = {INT_MAX, INT_MAX};
//         for(int i = 0; i < ratings.size(); ++i)
//         {
//             if(ratings[i] < minRating.first){
//                 minRating.first = ratings[i];
//                 minRating.second = i;
//             }
//         }
        
//         int deliveryCandys = 1;
//         //正序
//         int CumulativeCandys = 1;
//         for(int i = minRating.second + 1; i < ratings.size(); ++i)
//         {
//             //如果 当前i > 前一个i, 累计糖果+1
//             if(ratings[i] > ratings[i - 1]){
//                 CumulativeCandys += 1;
//             }
//             else{   //否则 累计糖果变为1
//                 CumulativeCandys = 1;
//             }
            
//             deliveryCandys += CumulativeCandys;
//         }

//         //逆序
//         CumulativeCandys = 1;   //累计糖果为1
//         for(int i = minRating.second - 1; i >= 0; --i)
//         {
//             if(ratings[i] > ratings[i + 1]){
//                 CumulativeCandys += 1;
//             }
//             else if(ratings[i] < ratings[i + 1]){
//                 CumulativeCandys = 1;
//             }
//             else{//ratings[i] == ratings[i + 1]
//                 if(i - 1 >= 0 && ratings[i - 1] < ratings[i]){
//                     CumulativeCandys = 
//                 }
//                 else
//             }

//             deliveryCandys += CumulativeCandys;
//         }

//         return deliveryCandys;
//     }
// };