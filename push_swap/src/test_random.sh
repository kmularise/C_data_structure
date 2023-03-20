ARG="$(($RANDOM% 11+100)) $(($RANDOM% 11+100)) $(($RANDOM% 11+100)) $(($RANDOM% 11+100)) $(($RANDOM% 11+100))"
echo $ARG
./a.out $ARG | ./checker_Mac $ARG