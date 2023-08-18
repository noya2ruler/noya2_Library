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
  bundledCode: "#line 2 \"misc/timer.hpp\"\n\n#include<chrono>\n#include<iostream>\n\
    \nnamespace noya2{\n\nstruct Timer {\n  private:\n    std::chrono::high_resolution_clock::time_point\
    \ start, end;\n \n  public:\n    Timer() { set(); }\n    void set() { start =\
    \ std::chrono::high_resolution_clock::now(); }\n    int time() {\n        end\
    \ = std::chrono::high_resolution_clock::now();\n        return std::chrono::duration_cast<std::chrono::milliseconds>(end\
    \ - start).count();\n    }\n    double dtime(){\n        return (double)(time())\
    \ / 1000;\n    }\n    bool before(double T) { return time() < (int)(T * 1000);\
    \ }\n    void print() { std::cerr << \"elapsed time: \" << (double)time() / 1000\
    \ << \" sec\" << std::endl; }\n};\n\n} // namespace noya2\n"
  code: "#pragma once\n\n#include<chrono>\n#include<iostream>\n\nnamespace noya2{\n\
    \nstruct Timer {\n  private:\n    std::chrono::high_resolution_clock::time_point\
    \ start, end;\n \n  public:\n    Timer() { set(); }\n    void set() { start =\
    \ std::chrono::high_resolution_clock::now(); }\n    int time() {\n        end\
    \ = std::chrono::high_resolution_clock::now();\n        return std::chrono::duration_cast<std::chrono::milliseconds>(end\
    \ - start).count();\n    }\n    double dtime(){\n        return (double)(time())\
    \ / 1000;\n    }\n    bool before(double T) { return time() < (int)(T * 1000);\
    \ }\n    void print() { std::cerr << \"elapsed time: \" << (double)time() / 1000\
    \ << \" sec\" << std::endl; }\n};\n\n} // namespace noya2"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2023-08-18 12:11:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
