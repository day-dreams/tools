# /bin/bash


ps -ef | grep $1 | grep -v grep 


echo -n "Are you sure to kill process below ?:(y/n)" 

# wait for input 'y' or 'n'
read input

if [ "$input"x = "y"x ]; then
    ps -ef | grep $1 | grep -v grep | awk '{print $2}' | xargs kill -9 
fi

