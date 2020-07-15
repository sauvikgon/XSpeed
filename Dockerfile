FROM ubuntu:18.04

# install Git

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y git

# install XSpeed

RUN mkdir /usr/app
WORKDIR /usr/app
RUN git clone https://rajray84@bitbucket.org/rajray84/xspeed-exe.git
WORKDIR /usr/app/xspeed-exe/
ARG CACHEBUST=1 
RUN git pull 

#install jdk 14
RUN tar -xvf openjdk-14.0.1_linux-x64_bin.tar.gz
ENV PATH="${PATH}:/usr/app/xspeed-exe/jdk-14.0.1/bin/"

ENV PATH="/usr/app/xspeed-exe:${PATH}"
ENV LD_LIBRARY_PATH="/usr/app/xspeed-exe/lib/:${LD_LIBRARY_PATH}"

ENTRYPOINT ["/usr/app/xspeed-exe/XSpeed"]
CMD []



