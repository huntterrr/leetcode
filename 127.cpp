class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(), wordList.end());
        if (!words.count(endWord)){
            return 0;
        }
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty()){
            string word = q.front().first;
            int n = q.front().second;
            q.pop();
            for (int i = 0; i < word.size(); i++){
                for (int j = 0; j<26; j++){
                    char letter = j+'a';
                    string newWord = word.substr(0, i)+letter+word.substr(i+1);
                    if (words.count(newWord) and newWord!=word){
                        if (newWord==endWord){
                            return n+1;
                        }
                        words.erase(newWord);
                        q.push({newWord, n+1});
                    }
                }
            }
        }
        return 0;
    }
};