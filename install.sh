#! /bin/bash

# install prerequisites

sudo apt -y update
echo
sudo apt -y install git build-essential libssl-dev wget cmake lzip
echo

#make a directory to store the libraries

mkdir ./libraries
cd ./libraries
# install openjdk16

sudo apt -y install openjdk-16-jre-headless
echo

# install z3

X=$(find /usr/local/include/z3++.h)
if test -z "$X"
then
	sudo wget https://github.com/Z3Prover/z3/archive/refs/tags/z3-4.8.10.tar.gz
	tar -xvf z3-4.8.10.tar.gz
	cd ./z3-z3-4.8.10/
	sudo mkdir build && \
		cd build && \
		sudo cmake -G "Unix Makefiles" ../ && \
		sudo make -j4
	sudo make install
	cd ../..
	echo
else
	echo "Found z3 Theorem Prover."
fi

# install GLPK

X=$(find /usr/local/include/glpk.h)
if test -z "$X"
then
	sudo http://ftp.gnu.org/gnu/glpk/glpk-5.0.tar.gz
	tar -xvf glpk-5.0.tar.gz
	cd ./glpk-5.0
	sudo ./configure && \
		sudo make all && \
		sudo make install
	cd ..
	echo
else
	echo "Found GLPK."
fi

# install GMP

X=$(find /usr/local/include/gmp.h)
if test -z "$X"
then
	sudo wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
	tar -xvf gmp-6.2.1.tar.lz
	cd ./gmp-6.2.1
	sudo ./configure && \
		sudo make all && \
		sudo make install
	cd ..
	echo
else
	echo "Found GMP."
fi

# install NLOpt

X=$(find /usr/local/include/nlopt.h)
if test -z "$X"
then
	wget https://github.com/stevengj/nlopt/archive/v2.7.1.tar.gz
	tar -xvf v2.7.1.tar.gz
	cd ./nlopt-2.7.1
	sudo cmake . && sudo make && sudo make install
	cd ..
	echo
else
	echo "Found NLOpt."
fi

# install Boost

X=$(find /usr/local/include/boost)
if test -z "$X"
then
	sudo wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz
	tar -xvf boost_1_79_0.tar.gz
        cd boost_1_79_0/
        ./bootstrap.sh
        ./b2
        cd ..
        sudo ln -sf $PWD/boost_1_79_0/boost /usr/local/include/
        sudo ln -sf $PWD/boost_1_79_0/stage/lib/ /usr/local/lib/
else
	echo "Found BOOST Library."
fi

# install SUNDIALS

echo "Installing SUNDIALS Library (version 5.7.0)."
sudo wget http://github.com/LLNL/sundials/releases/download/v5.7.0/sundials-5.7.0.tar.gz
tar -xvf sundials-5.7.0.tar.gz
cd ./sundials-5.7.0/
sudo mkdir builddir
cd ./builddir
sudo cmake .. && sudo make && sudo make install
cd ../..
echo


# install plotutils

echo
sudo apt -y install plotutils
echo

#set library path env variable to include boost and nlopt

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib/lib:/usr/local/lib/x86_64-linux-gnu/

# install XSpeed
cd ..
echo "building XSpeed ..."
cd ./build
sudo make all

# Check the installation by asking for the help menu of the tool.

echo
./xspeed --help

