#! /bin/bash

mkdir ./libraries
cd ./libraries
sudo apt-get install lzip

#install glpk 
#wget http://ftp.gnu.org/gnu/glpk/glpk-5.0.tar.gz
tar -xvf glpk-5.0.tar.gz
cd glpk-5.0/
sudo ./configure
sudo make all
sudo make install
cd ..

#install boost
#wget https://boostorg.jfrog.io/artifactory/main/release/1.79.0/source/boost_1_79_0.tar.gz
tar -xvf boost_1_79_0.tar.gz
cd boost_1_79_0/
./bootstrap.sh
./b2
cd ..
sudo ln -sf $PWD/boost_1_79_0/boost /usr/local/include/
sudo ln -sf $PWD/boost_1_79_0/stage/lib/ /usr/local/lib/

#install z3
git clone https://github.com/Z3Prover/z3.git
cd z3/
mkdir build
cd build
cmake ..
sudo make all
sudo make install
cd ../..

#install sundials
wget http://github.com/LLNL/sundials/releases/download/v5.7.0/sundials-5.7.0.tar.gz
tar -xvf sundials-5.7.0.tar.gz
cd sundials-5.7.0/
mkdir build
cd build
cmake ..
sudo make all
sudo make install
cd ../../

#install nlopt
wget https://github.com/stevengj/nlopt/archive/v2.7.1.tar.gz
tar -xvf v2.7.1.tar.gz
cd nlopt-2.7.1
mkdir build
cd build
cmake ..
sudo make all
sudo make install
cd ../../

#install gmp
wget https://gmplib.org/download/gmp/gmp-6.2.1.tar.lz
tar --lzip -xvf gmp-6.2.1.tar.lz
cd gmp-6.2.1/
sudo ./configure
sudo make all
sudo make install
cd ../../




