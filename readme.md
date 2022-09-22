# ARM protocol based neural network on chip
## 這是中山大學的畢業專題
## Prerequirement
```
cmake
conan
```

## How to build:
```shell=
mkdir build && cd build
conan install ../Conanfile.txt --build=systemc
cmake ..
make
```

## AMBA : AXI4 stream
## API : SystemC 
- version : 2.3.3

## AXI4 stream Channel
- Data channel

## AXI signal

### READY
- TREADY

### VALID
- TVALID
## 組員
- 吳秉勳
- 王昇鴻
