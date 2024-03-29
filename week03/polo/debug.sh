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

# Observe the values of i at the end of line 14 
# and angle at the end of lines 15 and 20. 
# Add also a watch on the value of i and x while running the loop.


gdb ./"$(basename "$1" .c)_debug.out" <<EOF
lay next
list
break 15
break 22
run
printf "i \n"
print i
printf "angle \n"
print angle
continue
printf "angle \n"
print angle
clear 15
clear 22
while i < 5
print i
print x
continue
end
EOF