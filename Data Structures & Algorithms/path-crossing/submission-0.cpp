class Solution {
   public:
    bool isPathCrossing(string path) {
        
        // N -> (+1, 0)
        // E -> (0, -1)
        // W -> (0, +1)
        // S -> (-1, 0);

        int n = path.size();
        string s = path;
        set<pair<int, int>> visited;
        int row = 0, col = 0;
        visited.insert({row, col});

        for(int i=0; i<path.size(); i++){
            if(s[i] == 'N'){
                row++;
            }else if(s[i] == 'E'){
                col--;
            }else if(s[i] == 'W'){
                col++;
            }else{
                row--;
            }

            if(visited.find({row, col}) != visited.end()){
                return true;
            }
            visited.insert({row, col});
        }
        

        return false;
    }
};