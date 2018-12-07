#!/bin/zsh

if [[ $1 -ne "-v" && $1 -ne "-i" ]] || [[ $2 == "" || $3 == "" ]] || ! $(ls $2 $3 1>/dev/null); then
	echo "Usage $0 (-v|-i) <1st_fillit_folder> <2nd_fillit_folder>"
	echo
	echo "-v:\tlaunch main valid test"
	echo "-i:\tlaunch incorrect test"
	exit 1;
fi

GREEN='\e[0;32m'
RED='\e[0;31m'
YELLOW='\e[93m'
CYAN='\e[96m'
MAG='\e[95m'
BOLD='\e[1m'
BLUE='\e[1;34m'
RESET='\e[0m'

GEN=generator/tetri-gen
TDIR=.fillit_tests/

FST=$2
SCD=$3
LIMITS=(1 1 26)


rm -rf $TDIR
mkdir $TDIR
make -C $GEN &> /dev/null
make -C $FST &> /dev/null
make -C $SCD &> /dev/null
for i in {1..${LIMITS[1]}}; do
	for j in {${LIMITS[2]}..${LIMITS[3]}}; do
		f="${i}_${j}"
		$GEN $1 -s $j 0> $TDIR/${f}.map
		${FST}/fillit $TDIR/${f}.map > $TDIR/${FST}_${f}.out 2> $TDIR/${FST}_${f}.err &
		${SCD}/fillit $TDIR/${f}.map > $TDIR/${SCD}_${f}.out 2> $TDIR/${SCD}_${f}.err &
	done
done

echo "${MAG}If your computer will be close to blow himself up just ^C and type in your shell the command below\n>>> kill -9 \$(pgrep fillit)"
printf $BLUE
while [[ $(pgrep fillit) ]]; do
	cu=($(top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {printf "%s %s\n",  $3, $5;}'))
	CPU=$(echo ${cu[1]/\%/} + ${cu[2]/\%/} | bc)
	echo "Waiting... for $(pgrep fillit | wc -l | sed -e 's/ //g') proccesses. CPU usage: $CPU"; sleep 5
	if (( $CPU >= 100.7 )); then
		kill -9 $(pgrep fillit)
	fi
done

ERRS=0
if [[ $1 == "-v" ]]; then
	echo "${YELLOW}Checking with valid maps:"
	for i in {1..${LIMITS[1]}}; do
		for j in {${LIMITS[2]}..${LIMITS[3]}}; do
			f="${i}_${j}"
			if [[ "$(diff $TDIR/${FST}_${f}.out $TDIR/${SCD}_${f}.out)" ]]; then
				echo "${RED}Error occured with files: $TDIR/${FST}_${f}.out $TDIR/${SCD}_${f}.out"
				echo "$RED----------------------------------------"
				echo "${RESET}DUMP for ${CYAN}$TDIR/${f}.map${RESET}:\n$TDIR/${FST}_${f}.out:"
				cat $TDIR/${FST}_${f}.out
				echo "\n--------------------\n"
				echo "$TDIR/${SCD}_${f}.out:"
				cat $TDIR/${SCD}_${f}.out
				echo "$BOLD$RED----------------------------------------"
				let ERRS++;
			else
				echo "${GREEN}Valid test $f passed successfully!"
			fi
		done
	done
else
	echo "${YELLOW}Checking with invalid maps:"
	for i in {1..${LIMITS[1]}}; do
		for j in {${LIMITS[2]}..${LIMITS[3]}}; do
			f="${i}_${j}"
			if (( $(wc -l < $TDIR/fst_${f}.out) != $(wc -l < $TDIR/${SCD}_${f}.out) )); then
				echo "${RED}Error occured with files: $TDIR/fst_${f}.out $TDIR/${SCD}_${f}.out OR $TDIR/fst_${f}.err $TDIR/${SCD}_${f}.err"
				let ERRS++;
			else
				echo "${GREEN}Invalid test $f passed successfully!"
			fi
		done
	done
fi

P=$(( ${LIMITS[1]} * (${LIMITS[3]} - ${LIMITS[2]} + 1) ))
SP=$(( $P - $ERRS ))
echo "${CYAN}$SP/$P tests passed successfully"
