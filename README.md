# BigInt-conv
#### Big integer converter by Davide Fassio

## Overview
This header-only library allows you to convert a arbitary size string of digit into a vector of 64bit unsigned integer.\
This process will speed up all the future calculation made on the number.

## Prototype
### Constructors
```c++
BigInt();         // Default constructor
BigInt(BigInt&);  // Copy constructor
BigInt(int64_t);
BigInt(std::string);
BigInt(char[]);
```

### Assignment operators
```c++
BigInt& operator=(BigInt&);
BigInt& operator=(int64_t);
BigInt& operator=(std::string);
BigInt& operator=(char[]);
```

### Getters
```c++
int getSign();
std::string getString();
std::vector<uint64_t> getVector();
```

## Examples
```c++
BigInt n1();
BigInt n2((int64_t) -123456789);
BigInt n3(n2);
BigInt n4("123456789");
BigInt n5 = n4;
BigInt n6 = "-123456789";
```

```c++

```
