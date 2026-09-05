#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int ans = 0;
        unordered_set<string> s;
        queue<pair<string, int>> q;
        unordered_set<string> visited;
        s.insert(wordList.begin(), wordList.end());
        q.push({beginWord,1});
        visited.insert(beginWord);
        
        while(!q.empty())
        {
            auto [word, dist] = q.front();
            q.pop();
            for(int i = 0; i < word.size(); i++)
            {
                char original = word[i];
               for(char a = 'a'; a <= 'z' ; a++)
               {
                word[i] = a;
                if(s.find(word) != s.end() && visited.find(word) == visited.end())
                {
                    q.push({word,dist+1});
                    if(word == endWord)return dist + 1;
                }
               }
                word[i] = original;

            }
        }
        return 0;
    }};
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
    cout << answer << endl;
    return 0;

}