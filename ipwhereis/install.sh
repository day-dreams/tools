pip install requests

# for python script
mkdir _ipwhereis
cp ./src/ipwhereis.py _ipwhereis
mv _ipwhereis /usr/local/bin/

# for elf file
g++ -std=c++11 ./src/ipwhereis.cpp -o ipwhereis
mv ipwhereis /usr/local/bin/ipwhereis

