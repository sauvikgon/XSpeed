**Building XSpeed from Source**

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

6. Z3 (Theorem Prover)

    The package can be downloaded from https://github.com/Z3Prover/z3

7. UnitTest++ (A unit testing package)
	
	The package can be downloaded from https://github.com/unittest-cpp/unittest-cpp

Allow default installation of the library header files into the directory `/usr/local/include` and the .a/.so files into the directory `/usr/local/lib`

Compiling the source:

`cd build`

`sudo make all`

The tool executable with the name *XSpeed-plan* will be created in the *build* directory.

**Running XSpeed**

Requirements:

Running XSpeed requires JDK 14 or higher installed and set as default.

It can be downloaded from https://jdk.java.net/14/


XSpeed can analyze hybrid automata models in *SpaceEx input format*. The in-built parser
parses the hybrid automata model file (*.xml) and the configuration file (*.cfg) when given as inputs
from the command-line:

`./XSpeed-plan -m <path-to-model.xml> -c <path-to-model.cfg>`

To see the help menu of the tool, run:

`XSpeed-plan --help`

** Running from Docker Image **
Building the Dockerfile will create a docker container of
XSpeed in your local machine, which you can use to run the tool.
Follow the steps below to build the Dockerfile


Install docker (https://docs.docker.com/engine/install/ubuntu/)


Go to the directory where the Dockerfile of XSpeed is present and run:
sudo docker build -t xspeed .


To check whether the docker image is ready, run:
sudo docker run xspeed --help


You should see the help menu of the tool in the console. Your docker image is ready!

**Testing**

Contributors should write unit-tests for their code contributions and keep them in the *testers* directory.
If test-cases as files are required, then all test-cases should be kept in the *testcases* directory

Running the tests:

`cd test`

`sudo make all`

The test executable with the name *XSpeed-test* will be created in the *test* directory.
