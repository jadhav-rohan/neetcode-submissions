class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        map<string, vector<string>> m;

        for(int i=0; i<strs.size(); i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(m.find(temp) != m.end()){
                m[temp].push_back(strs[i]);
            }else{
                m.insert({temp, {strs[i]}});
            }
        }

        for(auto itr = m.begin(); itr != m.end(); itr++){
            // int s = itr->second.size();
            // for(int i=0; i<s; i++){
                ans.push_back(itr->second);
            // }
        }
        

        return ans;

    }

};
