LOOP_COUNT=500
TEST_COUNT=10
echo "$MAX\n"

j=0
while [ "$j" -lt $(expr $TEST_COUNT) ]
do
	ARG="$((-2147483648+$RANDOM +$RANDOM* 32768 +($RANDOM %4)*32768*32768))"
	# ARG="$RANDOM"
	i=0
	while [ "$i" -lt $(expr $LOOP_COUNT - 1) ]
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
#echo $ARG
# ARG="4077 4331 13946 11706 8429 18237 18819 27088 7970 8657"
# ARG="29767 15662 18395 27892 21793 21134 11437 25196 6857 1785"
# ARG="2528 18648 12970 29604 10537 10641 11576 2802 26312 18865 20256 27003 29303 25913 22933 15167 32247 23870 23474 17110 13058 21859 2121 2384 7154 11546 7274 12237 27442 20634 8885 16091 19816 7582 8032 3986 12895 22500 28935 10865 14518 26977 29239 14327 10314 27204 10168 24321 10084 11441 1950 11494 5795 18490 9486 25428 16296 24861 19665 18409 17027 10048 24218 20881 28129 18669 28439 20386 28145 21837 32442 26297 32283 19110 20804 32594 2400 19540 12822 553 25999 15497 12599 32340 5421 13764 9508 5405 15394 8210 32091 18337 13091 24071 12710 553 26083 19835 23080 331"
# ./a.out $ARG | ./checker_Mac $ARG
# ./a.out $ARG | wc -l