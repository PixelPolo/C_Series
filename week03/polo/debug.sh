#!/usr/bin/env bash

# Check if no args are passed
if [ $# -eq 0 ]; then 
    echo "Error: No args specified !"
    exit 1
elif [ $# -gt 1 ]; then
    echo "Erreur : Only one arg is supported !"
    exit 1
# -f $1     check if it's a file
# =~        allow regex comparisons
# \.c$      check if end (with $) .c
elif [ ! -f "$1" ] || [[ ! "$1" =~ \.c$ ]]; then
    echo "Erreur : arg must be a .c file !"
    exit 1
fi

# Print state
echo "Compiling $1 with debugging options -g"

# -Wall     All warnings
# -ggdb     Produce debugging information for use by GDB
# "$(basename "$1" .c)"    Remove ".c" 
gcc -Wall -ggdb $1 -o "$(basename "$1" .c)_debug.out" -lm
