#install glpk 
wget http://ftp.gnu.org/gnu/glpk/glpk-5.0.tar.gz
mv glpk-5.0.tar.gz ./libraries/
cd ./libraries
tar -xvf glpk-5.0.tar.gz
cd glpk-5.0/
sudo ./configure
sudo make all
sudo make install
cd ..
#install boost
wget https://boostorg.jfrog.io/artifactory/main/release/1.76.0/source/boost_1_76_0.tar.gz
mv boost_1_76_0.tar.gz ./libraries/
cd ./libraries
tar -xvf boost_1_76_0.tar.gz
cd boost_1_76_0/
./bootstrap.sh
./b2
cd ..
#install z3
git clone https://github.com/Z3Prover/z3.git
cd z3/
mkdir build
cd build
cmake ..
cd build
sudo make all
sudo make install
#install sundials

