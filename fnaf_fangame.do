DEPS="build/demo/main.o build/demo/dumblib.o"
redo-ifchange $DEPS
clang -lraylib -Wall -o build/$2 $DEPS