#pragma once

#include <vector>
#include <functional>
#include <stack>
#include <utility>

namespace noya2 {

// {root, par}, par[root] == root
template<typename T, class comp = std::less<T>>
std::pair<int, std::vector<int>> cartesian_tree(std::vector<T> a){
    comp cp;
    int n = a.size();
    std::stack<int, std::vector<int>> st;
    st.push(0);
    std::vector<int> par(n);
    for (int i = 1; i < n; i++){
        if (cp(a[st.top()], a[i])){
            par[i] = st.top();
            st.push(i);
            continue;
        }
        int ch = -1;
        while (!st.empty() && !cp(a[st.top()],a[i])){
            ch = st.top(); st.pop();
        }
        par[ch] = i;
        if (!st.empty()){
            par[i] = st.top();
        }
        st.push(i);
    }
    while (st.size() > 1u) st.pop();
    par[st.top()] = st.top();
    return {st.top(), par};
}

} // namespace noya2