class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set.erase(beginWord);
        
        while(!q.empty()){
            string str = q.front().first;
            int level = q.front().second;
            q.pop();
            if(str == endWord)return level;
            
            for(int i= 0;i<str.length();i++){
                char original = str[i];
                for(char ch = 'a';ch <= 'z';ch++){
                    str[i] = ch;
                    if(set.find(str)!=set.end()){
                        q.push({str, level+1});
                        set.erase(str);
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};