# # test non nuimeric parameters
# echo "test non nuimeric parameters #1"
# ARG="3 - 23 4 1 0 6 9"
# #./push_swap $ARG | 
# ./checker_Mac $ARG
# echo "test non nuimeric parameters #2"
# ARG="3 /t32323 23 4 1 0 6 9"
# echo $ARG
# #./push_swap $ARG
# ./checker_Mac $ARG
# echo "test only numeric parameters including one greater than MAXINT"
# ARG="2147483648"
# # ARG="sdfsdfsdf"
# ./push_swap $ARG
# ./checker_Mac $ARG

echo "Checker program - False tests "
./checker_Mac

echo "Checker program - Right tests"
./checker_Mac 0 9 1 8 2
