# BigInt-conv
#### Big integer converter by Davide Fassio.

## Overview
This header-only library allows you to convert a arbitary size string of digit into a vector of 64bit unsigned integer.\
This process will speed up all the future calculation made on the number.

## Prototypes
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

sdt::string str = n2.getString();
int sign = n4.getSign();
std::vector<uint64_t> vec = n6.getVector();
```

## License
```
MIT License

Copyright (c) 2020 Davide Fassio

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
