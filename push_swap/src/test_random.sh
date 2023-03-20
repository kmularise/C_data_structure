# ARG="$(($RANDOM% 11+100)) $(($RANDOM% 11+100)) $(($RANDOM% 11+100)) $(($RANDOM% 11+100)) $(($RANDOM% 11+100))"
# echo $ARG
# ./a.out $ARG | ./checker_Mac $ARG
LOOP_COUNT=10
ARG="$(($RANDOM% 100000-11))"
i=0
while [ "$i" -lt $(expr $LOOP_COUNT - 1) ]
do
	ARG+=" $(($RANDOM% 100000-11))"
	i=$(expr $i + 1)
done
echo $ARG
./a.out $ARG