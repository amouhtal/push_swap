#!/bin/bash

make 1>/dev/null
# make bonus 1>/dev/null
echo -n "cheker_OS -->" $(./push_swap $(cat list.txt) | ./checker_OS $(cat list.txt))
# echo -n "   cheker -->" $(./push_swap $(cat list.txt) | ./checker $(cat list.txt))
./push_swap $(cat list.txt) | wc -l
