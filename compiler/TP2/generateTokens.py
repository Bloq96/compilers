#!/bin/python3

import sys

def main():
    tokens = ["class", "else", "false", "fi", "if", "in", "inherits",
    "isvoid", "let", "loop", "pool", "then", "while", "case", 'esac',
    "new", "of", "not", "true"];
    temp = [];
    length = 0;
    possibilities = 0;
    string = [];
    for token in tokens:
        length = len(token);
        possibilities = 2**length;
        
        temp = [];
        for possibility in range(possibilities):
            temp.append(token);

        for possibility in range(possibilities):
            string = [];
            for charIndex in range(length):
                if(int(possibility/(2**charIndex))%2==1):
                    string.append(
                    temp[possibility][charIndex].upper());
                else:
                    string.append(
                    temp[possibility][charIndex].lower());
            temp[possibility] = "".join(string);

        print(" ".join(temp));

main();
