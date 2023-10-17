#pragma once

namespace noya2{

// sum[ i in [0,n) ] floor( (a * i + b) / m )
template<typename T>
T floor_sum(T n, T m, T a, T b){
    assert(m >= 1);
    if (n <= 0) return 0;
    T ans = 0;
    if (a < 0){
        T da = a / m;
        T ra = a - m * da;
        if (ra < 0) da--, ra += m;
        ans += (n >> 1) * ((n-1)|1) * da;
        a = ra;
    }
    if (b < 0){
        T db = b / m;
        T rb = b - m * db;
        if (rb < 0) db--, rb += m;
        ans += n * db;
        b = rb;
    }
    while (true){
        T da = a / m;
        ans += (n >> 1) * ((n-1)|1) * da;
        a -= da * m;
        T db = b / m;
        ans += n * db;
        b -= db * m;
        T y_max = a * n + b;
        if (y_max < m) break;
        T dy_max = y_max / m;
        n = dy_max;
        b = y_max - dy_max * m;
        std::swap(m, a);
    }
    return ans;
}

} // namespace noya2
