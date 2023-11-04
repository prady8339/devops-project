#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>> &webPages, int currPage, int goalPage, vector<bool> &vis) {
    std::queue<pair<int,int>> q;
    q.push({currPage, 0});
   
    while(!q.empty()){
        auto tp = q.front();
        if(tp.first == goalPage) return tp.second;
        for(auto nextPage : webPages[tp.first]){
            if(!vis[nextPage]){
                q.push({nextPage, tp.second + 1});
                vis[tp.first] = true;
            }
        }
        q.pop();
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> webPages(n);
    cin.ignore();
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        string str;
        getline(cin, str);

        string currNum = "";
        size_t idx = 0; // Changed to size_t

        while (idx < str.size()) {
            if (str[idx] == ' ') {
                temp.push_back(stoi(currNum) - 1);
                currNum = "";
            } else {
                currNum += str[idx];
            }
            idx++;
        }
        if (!currNum.empty()) {
            temp.push_back(stoi(currNum) - 1);
        }
        webPages[i] = temp;
    }
    int currPage, goalPage;
    cin >> currPage >> goalPage;
    vector<bool> vis(n);
    int ans = solve(webPages, currPage - 1, goalPage - 1, vis);
    if (ans >= 1e9) cout << -1;
    else cout << ans;
    return 0;
}
