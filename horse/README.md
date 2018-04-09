# Homework 2 - Horse

## User Guide

The source code includes

```
main.cc
```

### Prerequisites

GCC 5.4.0~ with C++ 11 support is needed to build this program.

### How to build

You can choose to use MakeFiles or just simply compile with g++.

#### Build with make

```
cmake .
make
```

#### Build with g++

```
g++ -o horse -g main.cc --std=c++11
```

### Run the program

```
./horse
```

## About the Program

The horse needs to run 410421301 * 2 (820842602) meters.
It can only run 1000 meters for each round.
Each round we give a random speed up to 15 meters per seconds.
We calculate the time it needs to finish the round.
And then sum up the elapsed time.

### Results

The result on a real machine:

* OS: Ubuntu 16.04.4 LTS
* 

![real_machine](real_machine.png)

The result on a virtual machine:

![virtual_machine](virtual_machine.png)
