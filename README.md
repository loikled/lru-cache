# Least recently used cache implementation

This a small project to try to solve a question I was asked a long time ago during a phone interview at Google.

The goal is to provide an implementation of a least recently used cache.

Imagine you have a function that takes a lot of time to compute:
`int expensiveFunction(int arg);`

You need to provide a way to store the results for some values or `arg` in order to save some computation.
The cache has a limited size so when there is no more space, you need to delete the least recently used entry.

# How to build
1. install cmake
2. install [googletest](https://github.com/google/googletest):
```
git clone git@github.com:google/googletest.git
cd googletest
make
sudo make install
```

3. build this project
```
mkdir build && cd build # It's better to create a separate build dir to avoid generating cmake files in the source folder.
cmake ..
make
```

# How to run

For now only tests of the lib has been implemented with gtest.
You can use `ctest` to run them:
```
ctest .
```


# Possible improvements

We could use google benchmark to test the performance of the implementation.
