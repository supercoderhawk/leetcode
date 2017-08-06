cmake_minimum_required(VERSION 3.7)
project(C)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c 301-350/328-Odd-Even-Linked-List.c 201-250/233-Number-of-Digit-One.c 1-50/1-Two-Sum.c 1-50/2-Add-Two_Numbers.c 1-50/3-Longest-Substring-Without-Repeating-Characters.c 1-50/5.-Longest-Palindromic-Substring.c 1-50/7-Reverse-Integer.c 1-50/8-String-to-Integer-atoi.c 1-50/6-ZigZag-Conversion.c 1-50/9-Palindrome-Number.c headers/problem_301_350.h headers/problem_201_250.h 151-200/172.-Factorial-Trailing-Zeroes.c "201-250/224-Basic-Calculator .c" headers/problem_151_200.h 1-50/11.-Container-With-Most-Water.c)
add_executable(C ${SOURCE_FILES})