NUM_COUNT=500
TEST_COUNT=10

j=0
while [ "$j" -lt $(expr $TEST_COUNT) ]
do
	ARG="$((-2147483648+$RANDOM +$RANDOM* 32768 +($RANDOM %4)*32768*32768))"
	# ARG="$RANDOM"
	i=0
	while [ "$i" -lt $(expr $NUM_COUNT - 1) ]
	do
		ARG+=" $((-2147483648+$RANDOM +$RANDOM* 32768 +($RANDOM %4)*32768*32768))"
		# ARG+=" $RANDOM"
		i=$(expr $i + 1)
	done
	#echo $ARG
	./a.out $ARG | ./checker_Mac $ARG
	./a.out $ARG | wc -l
	j=$(expr $j + 1)
done