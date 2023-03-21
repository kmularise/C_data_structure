MIN=0
MAX=123456
while
  rnd=$(cat /dev/urandom | tr -dc 0-9 | fold -w${#MAX} | head -1 | sed 's/^0*//;')
  [ -z $rnd ] && rnd=0
  (( $rnd < $MIN || $rnd > $MAX ))
do :
done