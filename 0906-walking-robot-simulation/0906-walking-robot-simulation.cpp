class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
     unordered_map<string,int>mpp;

     for(auto it:obstacles)
     {
        string key = to_string(it[0])+"+"+to_string(it[1]);
        mpp[key]++;
     }   
     vector<vector<int>>directions = {{-1,0},{0,1},{1,0},{0,-1}};

     int dir = 1;
     int x = 0;
     int y = 0;
     int mxdis = 0;

     for(int it:commands)
     {
        if(it==-2)
        {
            if(dir==0)
                dir = 3;
            else
                dir--;
        }
        else if(it==-1)
        {
            dir = (dir+1)%4;
        }

        else
        {
            int k = it;
            for(int i = 1 ; i<=k ; i++)
            {
                int newx = x+ directions[dir][0];
                int newy = y+directions[dir][1];

                string key = to_string(newx)+"+"+to_string(newy);

                if(mpp.find(key)!=mpp.end())
                {
                    break;
                }
                x = newx, y=newy;
                mxdis = max(mxdis, x*x+y*y);
            }
        }
     }
     return mxdis;
    }
};