FILES=$(find . -name "*.s")

rm -rf Players/*.cor
for file in $FILES
do
    valgrind ./asm $file
	echo "\n\n\n\n\n\n\n\n\n"
done
