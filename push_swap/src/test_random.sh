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
ARG="4077 4331 13946 11706 8429 18237 18819 27088 7970 8657"
./a.out $ARG