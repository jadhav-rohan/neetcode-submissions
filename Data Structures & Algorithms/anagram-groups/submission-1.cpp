class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<string, vector<string>> m;

        for(int i=0; i<strs.size(); i++){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            if(m.find(sorted) == m.end()){
                m.insert({sorted, {strs[i]}});
            }else{
                m[sorted].push_back(strs[i]);
            }
        }

        for(auto itr = m.begin(); itr != m.end(); itr++){
            vector<string> tmp = itr->second;
            ans.push_back(tmp);
        }

        return ans;
        
    }
};
