class Solution {
public:
    unordered_map<string,vector<string>>adj;
    vector<vector<string>>answer;
    unordered_map<string,int>dis;
    bool check(string s1,string s2){
        int c=0;
        if(s1.length() != s2.length()) return false;
        for(int i=0;i<s1.length();i++) if(s1[i]!=s2[i]) c++;
        return c<=1;
    }

    void dfs(string beginWord,string word,vector<string>&path){
        if(beginWord==word){
            vector<string>temp=path;
            reverse(temp.begin(),temp.end());
            answer.push_back(temp);
            return ;
        }
        for(auto i:adj[word]){
            if(dis.count(i) && dis[i]==dis[word]-1){
                path.push_back(i);
                dfs(beginWord,i,path);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), beginWord) == wordList.end()) {
            wordList.push_back(beginWord);
        }
        unordered_set<string>st(wordList.begin(),wordList.end());
        if(st.find(endWord)==st.end()) return {};
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(check(wordList[i],wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        queue<string>q;
        q.push(beginWord);
        dis[beginWord]=0;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(auto neigh : adj[curr]){
                if(dis.find(neigh)==dis.end()){
                    dis[neigh]=dis[curr]+1;
                    q.push(neigh);
                }
            }
        }
        if(!dis.count(endWord)) return {};

        vector<string>path={endWord};
        dfs(beginWord,endWord,path);
        return answer;
    }
};