#!/bin/zsh

if [[ $1 -ne "-v" && $1 -ne "-i" ]] || [[ $2 == "" || $3 == "" ]]; then
	echo "Usage $0 (-v|-i) <1st_fillit_folder> <2nd_fillit_folder>"
	echo
	echo "-v:\tlaunch main valid test"
	echo "-i:\tlaunch incorrect test"
	exit 1;
fi

GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[1;34m'
RESET='\033[0m'

GEN=generator/tetri-gen
TDIR=.fillit_tests/

FST=$2
SCD=$3
LIMITS=(1 2 10)


rm -rf $TDIR
mkdir $TDIR
make -C $GEN &> /dev/null
make -C $FST &> /dev/null
make -C $SCD &> /dev/null
for i in {1..${LIMITS[1]}}; do
	for j in {${LIMITS[2]}..${LIMITS[3]}}; do
		f="${i}_${j}"
		$GEN $1 -s $j 0> $TDIR/${f}.map
		${FST}/fillit $TDIR/${f}.map > $TDIR/fst_${f}.out 2> $TDIR/fst_${f}.err &
		${SCD}/fillit $TDIR/${f}.map > $TDIR/scd_${f}.out 2> $TDIR/scd_${f}.err &
	done
done

printf $BLUE
while [[ $(pgrep fillit) ]]; do
	echo "Waiting... for $(pgrep fillit | wc -l | sed -e 's/ //g') proccesses"; sleep 5
	cu=($(top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {printf "%s %s\n",  $3, $5;}'))
	if [[ $(echo ${cu[1]/\%/} + ${cu[2]/\%/} | bc) > 99 ]]; then
		kill -9 $(pgrep fillit)
	fi
done

for i in {1..${LIMITS[1]}}; do
	for j in {${LIMITS[2]}..${LIMITS[3]}}; do
		f="${i}_${j}.out"
		if [[ "$(diff $TDIR/fst_${f} $TDIR/scd_${f})" ]]; then
			printf $RED; echo "Error occured with files: $TDIR/fst_${f} $TDIR/scd_${f}"
			printf $RESET; echo DUMP:
			echo "$TDIR/fst_${f}:"; cat $TDIR/fst_${f}
			echo "\n--------------------\n"
			echo "$TDIR/scd_${f}:"; cat $TDIR/scd_${f}
			exit 2;
		fi
	done
done

printf $GREEN; echo $(echo "${LIMITS[1]} * (${LIMITS[3]} - ${LIMITS[2]} + 1)" | bc) "tests passed successfully"
