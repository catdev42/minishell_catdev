#!/usr/bin/bash

#declare STRING variable
STRING="Hello World"
#print variable on the screen
echo $STRING

directory="./Scripting"
if [ -d $directory ]; then
    echo "Directory exists"
else
    echo "Directory does not exist"
fi

echo $1 $2 $3

echo Hello there people! >outfile.txt
cat < outfile.txt

#for loops

for f in $( ls /var ); do
    echo $f >> varcontents.txt
done

# while loop
# COUNT=6
# while [ $COUNT -gt 0 ]; do
#     echo Count: $COUNT
#     let COUNT=COUNT-1
# done
COUNT=6
while [ $COUNT -gt 0 ]; do
    echo "Count: $COUNT"
    ((COUNT=COUNT-1))
done

# stringt manipulation

foo="Hello"
foo="$foo World"
echo $foo
a="hello"
b="world"
c=$a$b
echo $c
echo ${#foo}

#env
echo $HOME
echo $PATH
echo $USER
