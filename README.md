# Linux-Shell-Commands
Contains some very basic Linux Shell Commands in C Language using fork() and pthreads.

## Features
Some flags/options working here are:
cd

    cd ~                -changes current directory to home directory
    cd /                -changes current directory to / directory
    cd --help           -help function

pwd

    pwd                 -prints the path of present(currently) working directory

echo

    echo text           -prints the text
    echo -n text        -prints the text without new line in the end
    echo -E text        -prints (default)

exit

    exit                 -to terminate the shell


External Commands

cat

    cat file_name       -prints the text in file file_name
    cat -n file_name    -prints the text with number line in the file file_name
    cat > file_name     -creates a new file file_name if it doesnot exists

rm

    rm file_name        -removes file file_name
    rm -f file_name     -removes file file_name without generating any error
    rm -i file_name     -ask before removing file file_name

date

    date                -prints localtime of the system
    date -u             -prnts the utc time
    date -R             -(default) prints the localtime of the system

ls

    ls                  -prints files in current directory no hidden files
    ls -a               -prints hidden files too in current directory
    ls -l               -prints files in current directory no hidden files in list format
    ls -al              -prints hidden files too in current directory in list format

some advanced commands in ls

    ls ./dir            -prints files in current directory no hidden files
    ls -a ./dir         -prints hidden files too in current directory
    ls -l ./dir         -prints files in current directory no hidden files in list format
    ls -al ./dir        -prints hidden files too in current directory in list format 

mkdir

    mkdir dir           -make a new directory in the current directory
    mkdir -v dir        -make a new directory in the current directory also prints the statement
    mkdir -m=rwx dir    -make a new directory with special modes provided in the current directory
    
#### Using Pthreads
To call the commands by threads use "&t" in the end of the command.
Eg: ls &t
    
#### Errors are being taken care of.

## Future Implementations
Implementations of some more flags/options of the commands.
