class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans; //ans for storing rows
        //this for loop for every row go through
        for(int i=0;i<numRows;i++){
            vector<int> row(i+1,1);
            //this for every elemnt
            for(int j=1;j<i;j++){
                row[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(row);
        }
        return ans;
    }
};