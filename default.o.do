mkdir -p build/demo

SRC=${1#build/}
SRC=${SRC%%.o}
redo-ifchange $SRC.c
gcc -o $3 -c $SRC.c