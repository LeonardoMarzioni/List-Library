#!/bin/bash
# auto compiling and/or running

src="src/test.c"
lib="src/list.c src/menu.c"
opt="-o"
out="bin/test"

help()
{
   # Display Help
   echo "Use this tool to compile and/or run your C program."
   echo
   echo "Syntax: ./makefile [-help|h|o|c|r|cr]"
   echo "options:"
   echo "h | help       Print this Help."
   echo "o              Print the compile option"
   echo "c              Compile the program."
   echo "r              Run the program."
   echo "cr             Compile and Run the program."
}

print_option()
{   
    echo "src=$src"
    echo "lib=$lib"
    echo "opt=$opt"
    echo "out=$out"
}

compile()
{
    printf "compiling...\n"
    printf "gcc $src $lib $opt $out\n"
    gcc $src $lib -o $out
    printf "compiled!\n"
}

run()
{
    ./$out
}

if [ "$#" != "1" ];
    then
        printf "Expected only 1 arguments.\nUse -help option to read the manual.\n"
    else
        case $1 in

            -help|-h)
                help
                ;;

            -c)
                compile
                ;;

            -r)
                run
                ;;

            -cr)
                compile
                run
                ;;

            -o)
                print_option
                ;;

            *)
                printf "Invalid Arguments.\nYou may use -help to read the manual.\n"
                ;;
        esac

fi
