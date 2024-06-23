#define PROBLEM "https://yukicoder.me/problems/no/1077"

#include"../../template/template.hpp"
#include"../../data_structure/slope_trick.hpp"

int main(){
    int n; in(n);
    slope_trick<ll> st;
    rep(i,n){
        ll y; in(y);
        st.clear_right();
        st.add_abs(y);
    }
    out(st.min());
}