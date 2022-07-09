#!/bin/python3
import sys;

def main():
    words = {};
    for line in sys.stdin:
        elements = line.split(); 

        for word in elements:
            if word in words:
                words[word] = words[word]+1;
            else:
                words[word] = 1;

    print(words);

main();
