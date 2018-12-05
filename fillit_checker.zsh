#!/bin/zsh

if [[ $1 -ne "-v" && $1 -ne "-i" ]] || [[ $2 == "" || $3 == "" ]] || ! $(ls $2 $3 1>/dev/null); then
	echo "Usage $0 (-v|-i) <1st_fillit_folder> <2nd_fillit_folder>"
	echo
	echo "-v:\tlaunch main valid test"
	echo "-i:\tlaunch incorrect test"
	exit 1;
fi

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\e[93m'
CYAN='\e[96m'
BLUE='\033[1;34m'
RESET='\033[0m'

GEN=generator/tetri-gen
TDIR=.fillit_tests/

FST=$2
SCD=$3
LIMITS=(1 1 20)


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
	cu=($(top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {printf "%s %s\n",  $3, $5;}'))
	CPU=$(echo ${cu[1]/\%/} + ${cu[2]/\%/} | bc)
	echo "Waiting... for $(pgrep fillit | wc -l | sed -e 's/ //g') proccesses. CPU usage: $CPU"; sleep 5
	if (( $CPU >= 100.7 )); then
		kill -9 $(pgrep fillit)
	fi
done

printf $YELLOW
ERRS=0
if [[ $1 == "-v" ]]; then
	echo "Checking with valid maps:"
	for i in {1..${LIMITS[1]}}; do
		for j in {${LIMITS[2]}..${LIMITS[3]}}; do
			f="${i}_${j}"
			if [[ "$(diff $TDIR/fst_${f}.out $TDIR/scd_${f}.out)" ]]; then
				printf $RED; echo "Error occured with files: $TDIR/fst_${f}.out $TDIR/scd_${f}.out"
				printf $RESET;
				echo "DUMP:\n$TDIR/fst_${f}.out:"; cat $TDIR/fst_${f}.out
				echo "\n--------------------\n"
				echo "$TDIR/scd_${f}.out:"; cat $TDIR/scd_${f}.out
				let ERRS++;
			else
				printf $GREEN; echo "Valid test $f passed successfully!"
			fi
		done
	done
else
	echo "Checking with invalid maps:"
	for i in {1..${LIMITS[1]}}; do
		for j in {${LIMITS[2]}..${LIMITS[3]}}; do
			f="${i}_${j}"
			if (( $(wc -l < $TDIR/fst_${f}.out) != $(wc -l < $TDIR/scd_${f}.out) )); then
				printf $RED; echo "Error occured with files: $TDIR/fst_${f}.out $TDIR/scd_${f}.out OR $TDIR/fst_${f}.err $TDIR/scd_${f}.err"
				let ERRS++;
			else
				printf $GREEN; echo "Invalid test $f passed successfully!"
			fi
		done
	done
fi

printf $CYAN; echo; echo $(echo "${LIMITS[1]} * (${LIMITS[3]} - ${LIMITS[2]} + 1) - $ERRS" | bc) "tests passed successfully"
