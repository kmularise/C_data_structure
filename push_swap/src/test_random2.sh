max=0
min=1000000
for var in {1..10}
do
    ARGS="$(seq 500 | sort -R | xargs)"
    # ./push_swap $ARGS | ./checker_Mac $ARGS
    # ./push_swap $ARGS | wc -l | tr -d ' '
    str=$(./push_swap $ARGS | ./checker_Mac $ARGS)
    tmp=$(./push_swap $ARGS | wc -l | tr -d ' ')
    if [ $str == "KO" ]
    then
        echo $ARGS
    else
        echo $str
        ./push_swap $ARGS | wc -l | tr -d ' '
    fi
    if [ $((tmp)) -gt $((max)) ]
    then
        max=$tmp
    fi
done
echo $max