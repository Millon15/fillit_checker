# Tetriminos-generator
*Test file for the 42 Fillit project*

## How to install ?

	git clone https://github.com/hqro/Tetriminos-generator
	cd Tetriminos-generator
	make

## How to use ?

	chmod +x tetri-gen
	./tetri-gen -v -f 4

or

	./tetri-gen -v -s 4 > ./a.out

**-v** : valid tetriminos grid<br />
**-i** : invalid grid<br />
**-f** : write the tetriminos in a file "sample.fillit"<br />
**-s** : send the tetriminos from the standard input

The third argument is the number of 4x4 tetriminos blocs

## Examples

	$> make

	$> Création de tetri-gen
	$> ./tetri-gen -v -f 4
	$> cat -e sample.fillit
	....$
	....$
	..##$
	.##.$
	$
	....$
	##..$
	##..$
	....$
	$
	....$
	.##.$
	.#..$
	.#..$
	$
	....$
	.##.$
	.##.$
	....$
	$>

