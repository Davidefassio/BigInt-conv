# BigInt-conv
## Overview
This header-only library allows you to convert a arbitary size string of digit into a vector of 64bit unsigned integer.\
This process will speed up all the future calculation made on the number.

## Prototype
### Constructors
```BigInt();\
BigInt(BigInt&);\
BigInt(int64_t);\
BigInt(std::string);\
BigInt(char[]);```

### Assignment operators
```BigInt& operator=(BigInt&);\
BigInt& operator=(int64_t);\
BigInt& operator=(std::string);\
BigInt& operator=(char[]);```

### Getters
```int getSign();\
std::string getString();\
std::vector<uint64_t> getVector();```
