Building XSpeed from Source.

For building from source, install the following third party libraries:

1. GLPK (GNU Linear Programming Kit)

	Install the latest GLPK library from http://ftp.gnu.org/gnu/glpk [via http] or ftp://ftp.gnu.org/gnu/glpk [via ftp].

2. Boost C++ Libraries

	The latest package can be downloaded from https://www.boost.org/

3. SUNDIALS (SUite of Nonlinear and DIfferential/ALgebraic equation Solvers)

	SUNDIALS package can be downloaded from https://computing.llnl.gov/projects/sundials/sundials-software

4. NLopt (Non-Linear optimization) C++ library

	The latest package can be downloaded from https://nlopt.readthedocs.io/en/latest/#download-and-installation

5. GMP (GNU Multiple Precision arithmetic library)

    The latest package can be downloaded from https://gmplib.org/

6. UnitTest++
	
	The package can be downloaded from https://github.com/unittest-cpp/unittest-cpp

Allow default installation of the library header files into the directory `/usr/local/include` and the .a/.so files into the directory `/usr/local/lib`

Compiling the source:

`cd build`

`sudo make all`

The tool executable with the name *XSpeed-plan* will be installed in the build directory.
