#!/bin/bash

# Checks if you have provided a) a directory path in the form "a/b/c"
# along with the name of the class you wish to make ie Logger
are_arguments_valid ()
{
	if [ "$#" -ne 2 ]; then
		echo "Please provide directory then class name.
ie: ./add_class.sh object ActionObject"
		return 2
	fi
}

# This appends the file names in the makefile to create the object files
create_object_files ()
{
	sed -i '3 a \\t../inc/'"$1"'/'"$2"'.hpp \\' Makefile
	sed -i '3 a \\t../src/'"$1"'/'"$2"'.cpp \\' Makefile
}

# This appends to the makefile to make it create the executable with those files
create_executable ()
{
	sed -i '/main.o \\/s/.*/&\
\t'"$2"'.o \\/' Makefile
}

# This encapsulates all the changes made in the makefile
edit_makefile ()
{
	create_object_files $1 $2
	create_executable $1 $2
}

# This actually creates the default source file
add_source_file ()
{
	if [ ! -s src/$1/$2 ]
	then
		mkdir -p src/$1
		echo "#include \"$1/$2.hpp\"" >> src/$1/$2.cpp
	fi
}

# This creates the default header file for the class you wish to make
add_include_file ()
{
	snake_case=`echo $2 | sed -r 's/([A-Z])/_\L\1/g' | sed 's/^_//'`
	upper_and_underscore=${snake_case^^}_HPP

	if [ ! -s inc/$1/$2 ]
	then
		mkdir -p inc/$1
		echo -e "#ifndef ${upper_and_underscore}\n#define ${upper_and_underscore}\n\n#endif" >> inc/$1/$2.hpp
	fi
}

# Entrypoint of script
if ! are_arguments_valid $1 $2; then
	exit 2
fi
edit_makefile $1 $2
add_source_file $1 $2
add_include_file $1 $2
