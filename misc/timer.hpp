#pragma once

#include<chrono>
#include<iostream>

namespace noya2{

struct Timer {
  private:
    std::chrono::high_resolution_clock::time_point start, end;
 
  public:
    Timer() { set(); }
    void set() { start = std::chrono::high_resolution_clock::now(); }
    int time() {
        end = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }
    double dtime(){
        return (double)(time()) / 1000;
    }
    bool before(double T) { return time() < (int)(T * 1000); }
    void print() { std::cerr << "elapsed time: " << (double)time() / 1000 << " sec" << std::endl; }
};

} // namespace noya2