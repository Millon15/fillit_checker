# Fillit checker
*Checker for the 42 Fillit project*

## ACHTUNG

./fillit_checker just compares output of two fillit executables, keep it in mind!!!
You can always get more information about checker if you take look on its source code in *fillit_checker.zsh* file<br />
As etalon of the fillit you can always use @akondaur with @osyrotiu fillit, which placed in project folder as etalon_fillit

## How to install ?

	git clone https://github.com/millon15/fillit_checker
	chmod +x fillit_checker.zsh

## How to use ?

	./fillit_checker.zsh -v ../path/to/your/fillit/folder/of/executable etalon_fillit
<br /><br />
	Usage ./fillit_checker.zsh (-v|-i) <1st_fillit_folder_or_exec> <2nd_fillit_folder_or_exec>
	-v: launch main valid test
	-i: launch incorrect test

NOTE: all test maps with your fillit's output(.err files for 2nd file descriptor and .out for 1st) placed with ❤️ in .fillit_tests folder"

## Special thanks to @hqro for the beautiful tetraminos-generator and to @akondaur:@osyrotiu for perfect etalon fillit
