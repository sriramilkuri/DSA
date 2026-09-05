#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:

    int isValid(string a, string b)
    {
        int count = 0;

        for(int i = 0; i < a.size(); i++)
        {
            count += (a[i] != b[i]);
        }

        return count;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int ans = 0;
        int n = wordList.size();
        bool isEndwordFound = false;
        unordered_map<string, vector<string>> mp;
        unordered_set<string> s;
        queue<pair<string, int>> q;
        for(int i = 0; i < n; i++)
        {
            int m = isValid(beginWord, wordList[i]);
            if(m <= 1)
            {
                q.push({wordList[i], m});
                s.insert(wordList[i]);          
            }
            if(wordList[i] == endWord)
            {
                isEndwordFound = true;
            }
        }
        if(!isEndwordFound)
            return 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(isValid(wordList[i], wordList[j]) == 1)
                {
                    mp[wordList[i]].push_back(wordList[j]);
                    mp[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        while(!q.empty())
        {
            auto [word, dist] = q.front();
            q.pop();
            for(int i = 0; i < mp[word].size(); i++)
            {
                string nextWord = mp[word][i];
                if(s.find(nextWord) == s.end())
                {
                    q.push({nextWord, dist + 1});
                    s.insert(nextWord);
                    if(nextWord == endWord)
                    {
                        return dist + 1;
                    }
                }
            }
        }
        return 0;
    }
};


int main()
{
    Solution solution;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList =
    {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };
    int answer = solution.ladderLength(
        beginWord,
        endWord,
        wordList
    );
    return 0;
}
