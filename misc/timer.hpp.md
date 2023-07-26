---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/timer.hpp\"\nnamespace noya2{\n\nstruct Timer {\n \
    \ private:\n    chrono::high_resolution_clock::time_point start, end;\n \n  public:\n\
    \    Timer() { set(); }\n    void set() { start = chrono::high_resolution_clock::now();\
    \ }\n    int time() {\n        end = chrono::high_resolution_clock::now();\n \
    \       return chrono::duration_cast<chrono::milliseconds>(end - start).count();\n\
    \    }\n    double dtime(){\n        return (double)(time()) / 1000;\n    }\n\
    \    bool before(double T) { return time() < (int)(T * 1000); }\n    void print()\
    \ { cerr << \"elapsed time: \" << (double)time() / 1000 << \" sec\" << endl; }\n\
    };\n\n} // namespace noya2\n"
  code: "namespace noya2{\n\nstruct Timer {\n  private:\n    chrono::high_resolution_clock::time_point\
    \ start, end;\n \n  public:\n    Timer() { set(); }\n    void set() { start =\
    \ chrono::high_resolution_clock::now(); }\n    int time() {\n        end = chrono::high_resolution_clock::now();\n\
    \        return chrono::duration_cast<chrono::milliseconds>(end - start).count();\n\
    \    }\n    double dtime(){\n        return (double)(time()) / 1000;\n    }\n\
    \    bool before(double T) { return time() < (int)(T * 1000); }\n    void print()\
    \ { cerr << \"elapsed time: \" << (double)time() / 1000 << \" sec\" << endl; }\n\
    };\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2023-07-26 23:17:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
