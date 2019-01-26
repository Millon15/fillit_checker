#!/bin/zsh

GREEN='\e[0;32m'
RED='\e[0;31m'
YELLOW='\e[93m'
CYAN='\e[96m'
MAG='\e[95m'
BLUE='\e[1;34m'
RESET='\e[0m'

get_usage()
{
	echo "Usage ./fillit_checker.zsh (-v|-i) <1st_fillit_folder_or_exec> <2nd_fillit_folder_or_exec> [limit_numbers]"
	echo "${YELLOW}Be aware! Folders, that you passed as parameters, must be valid fillit project folders and contains Makefile inside."
	echo "Or you can pass regular ./fillit executables as a parameters, also you can combine folders and executables.${RESET}"
	echo "-v:\t\t\tlaunch main valid test"
	echo "-i:\t\t\tlaunch incorrect test"
	echo "[limit_numbers]:\tpair of numbers, that represent start(1st number) and end(2nd) size of the test maps. By default: start=1; end=12"
	echo
	echo "Example:\t\t./fillit_checker.zsh -v ../my_fillit etalon_fillit 1 12"
	exit 1
}

get_name()
{
	if [ -f $1 ]; then
		pn=$(cd $(dirname $1); pwd)/$(basename $1)
		pn=${pn%%\/.}
		pn=${pn%%\/..}
		pn=${pn%%\/.git}
		pn=$(basename $pn)
	else
		pn=$(cd $1; pwd)
		pn=$(basename $pn)
	fi
	pn=${pn/#./}
	echo $pn
}

prove_path()
{
	if ! ls $1 1> /dev/null; then get_usage; fi

	if [[ -d $1 ]]; then
		if ! make -C $1 1> /dev/null; then get_usage; fi
		if ! $1/fillit $TDIR/test.map 1> /dev/null; then get_usage; fi
		echo $1/fillit
	else
		$1 $TDIR/test.map
		if (( $? != 0 )) || [[ $($1 $TDIR/test.map) == "error" ]]; then get_usage; fi
		echo $1
	fi
}
if [[ $1 -ne "-v" && $1 -ne "-i" ]] || [[ "$2" == "" || "$3" == "" ]]; then get_usage; fi
TDIR=.fillit_tests/
GEN=generator/tetri-gen
make -C $GEN &> /dev/null
$GEN -v -s 1 0> $TDIR/test.map

prove_path $2 > /dev/null
prove_path $3 > /dev/null
FST_EX=$(prove_path $2)
SCD_EX=$(prove_path $3)


FST=$(get_name $2)
SCD=$(get_name $3)
LIMITS=(1 12)
if [[ "$4" ]]; then [[ $4 =~ "^[0-9]+$" ]] && { LIMITS[1]=$4 } || { get_usage }; fi
if [[ "$5" ]]; then [[ $5 =~ "^[0-9]+$" ]] && { LIMITS[2]=$5 } || { get_usage }; fi

rm -rf $TDIR
mkdir $TDIR
for j in {${LIMITS[1]}..${LIMITS[2]}}; do
	f="$j"
	$GEN $1 -s $j 0> $TDIR/${f}.map
	$FST_EX $TDIR/${f}.map > $TDIR/${FST}_${f}.out 2> $TDIR/${FST}_${f}.err &
	$SCD_EX $TDIR/${f}.map > $TDIR/${SCD}_${f}.out 2> $TDIR/${SCD}_${f}.err &
done

echo "${MAG}NOTE: all test maps with your fillit's output(.err files for 2nd file descriptor and .out for 1st) placed with ❤️  in .fillit_tests folder"
printf $BLUE
while [[ $(pgrep fillit) ]]; do
	cu=($(top -l 1 -i 1 -n 0 | awk '/CPU usage:/ {printf "%s %s\n",  $3, $5;}'))
	CPU=$(echo ${cu[1]/\%/} + ${cu[2]/\%/} | bc)
	echo "Waiting... for end of $(pgrep fillit | wc -l | sed -e 's/ //g') fillit proccesses. CPU usage: $CPU"
	if (( $CPU >= 100.7 )); then
		kill -9 $(pgrep fillit)
	fi
	sleep 5
done

ERRS=0
if [[ $1 == "-v" ]]; then
	echo "${YELLOW}Checking with valid maps:"
	for j in {${LIMITS[1]}..${LIMITS[2]}}; do
		f="$j"
		if [[ "$(head $TDIR/${FST}_${f}.err)" || "$(head $TDIR/${SCD}_${f}.err)" || "$(diff $TDIR/${FST}_${f}.out $TDIR/${SCD}_${f}.out)" ]]; then
			echo "${YELLOW}Suggest to test:"
			echo "$FST_EX $TDIR/${f}.map"
			echo "~OR~"
			echo "$SCD_EX $TDIR/${f}.map"
			echo "${RED}----------------------------------------"
			echo "${RESET}DUMP for ${CYAN}$TDIR/${f}.map${RESET}:\n$TDIR/${FST}_${f}.out:"
			cat $TDIR/${FST}_${f}.out
			echo "\n--------------------\n"
			echo "$TDIR/${SCD}_${f}.out:"
			cat $TDIR/${SCD}_${f}.out
			echo "${RED}----------------------------------------"
			let ERRS++;
		else
			echo "${GREEN}Valid test $f passed successfully!"
		fi
	done
else
	echo "${YELLOW}Checking with invalid maps:"
	for j in {${LIMITS[1]}..${LIMITS[2]}}; do
		f="$j"
		if (( $(wc -l < $TDIR/fst_${f}.out) != $(wc -l < $TDIR/${SCD}_${f}.out) )); then
			echo "${RED}Error occured with files: $TDIR/fst_${f}.out $TDIR/${SCD}_${f}.out OR $TDIR/fst_${f}.err $TDIR/${SCD}_${f}.err"
			let ERRS++;
		else
			echo "${GREEN}Invalid test $f passed successfully!"
		fi
	done
fi

P=$(( ${LIMITS[2]} - ${LIMITS[1]} + 1 ))
SP=$(( $P - $ERRS ))
echo "${CYAN}$SP/$P tests passed successfully"
