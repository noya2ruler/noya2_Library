namespace noya2{

struct Timer {
  private:
    chrono::high_resolution_clock::time_point start, end;
 
  public:
    Timer() { set(); }
    void set() { start = chrono::high_resolution_clock::now(); }
    int time() {
        end = chrono::high_resolution_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
    double dtime(){
        return (double)(time()) / 1000;
    }
    bool before(double T) { return time() < (int)(T * 1000); }
    void print() { cerr << "elapsed time: " << (double)time() / 1000 << " sec" << endl; }
};

} // namespace noya2