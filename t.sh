#!/bin/bash

# Use find to get all CMakeLists.txt files in the current directory and subdirectories
# Use xargs and grep to find lines containing find_package in those files
# Use sed to extract the package name
find . -name 'CMakeLists.txt' | xargs grep 'find_package' | sed -n -e 's/^.*find_package(\([^ ]*\) .*/\1/p'