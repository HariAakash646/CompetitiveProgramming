#!/bin/bash
g++ grader.cpp artswap.cpp -o artswap -Wall -static -O2 -lm -s -w -std=gnu++14 -fmax-errors=512
