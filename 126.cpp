#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string b;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        b = beginWord;
        queue<string> q;
        q.push(beginWord);
        mpp[beginWord] = 1;
        words.erase(beginWord);
        while (!q.empty())
        {
            string node = q.front();
            q.pop();
            if (node==endWord){
                break;
            }
            for (int i = 0; i < node.length(); i++)
            {
                for (char j = 'a'; j <= 'z'; j++)
                {
                    string newWord = node.substr(0, i)+j+node.substr(i+1);
                    if (words.count(newWord))
                    {
                        q.push(newWord);
                        words.erase(newWord);
                        mpp[newWord] = mpp[node]+1;
                    }
                }
            }
            
        }
        if (mpp.find(endWord)!=mpp.end())
        {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
            
        return ans;
    }
private:
    void dfs(string word, vector<string>& seq){
        if (word==b)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        for (int i = 0; i < word.size(); i++)
        {
            for (char it = 'a'; it <= 'z'; it++)
            {
                string newWord = word.substr(0, i)+it+word.substr(i+1);
                if (mpp.find(newWord)!=mpp.end() and mpp[newWord]==mpp[word]-1)
                {
                    seq.push_back(newWord);
                    dfs(newWord, seq);
                    seq.pop_back();
                }
            }
        }
    }
};

