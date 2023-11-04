#include <bits/stdc++.h>

using namespace std;
int solve(vector<vector<int>> &webPages,int currPage,int goalPage,vector<bool> &vis){
    if(currPage==goalPage) return 1;
    if(vis[currPage]) return 1e9;
    vis[currPage] = true;
    int cost = 1e9;
    for(auto &nextPage : webPages[currPage]){
        cost = min(cost, 1 + solve(webPages,nextPage,goalPage,vis));
    }
    return cost;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<vector<int>> webPages(n);
     cin.ignore();
    for (int i = 0; i < n; i++) {
        vector<int> temp;
        string str;
        getline(cin, str);

        string currNum = "";
        size_t idx = 0;

        while (idx < str.size()) {
            if (str[idx] == ' ') {
                temp.push_back(stoi(currNum)-1);
                currNum = "";
            } else {
                currNum += str[idx];
            }
            idx++;
        }
        if (!currNum.empty()) {
            temp.push_back(stoi(currNum)-1);
        }
        webPages[i] = temp;
    }
    // for (auto &arr : webPages) {
    //     for (auto &num : arr) {
    //         cout << num << " ";
    //     }
    //     cout << "\n";
    // }
    int currPage, goalPage;
    cin >> currPage >> goalPage;
    vector<bool> vis(n);
    int ans = solve(webPages, currPage, goalPage,vis);
    if(ans>=1e9) cout<<-1;
    else cout<<ans;
    return 0;
}
