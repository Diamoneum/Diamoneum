#!/usr/bin/env bash
# Diamoneum developers 2018
# use this installer to clone-and-compile diamoneum in one line
# supports Ubuntu 16 LTS

sudo apt-get update
yes "" | sudo apt-get install build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost-all-dev
export CXXFLAGS="-std=gnu++11"
git clone https://github.com/Diamoneum/Diamoneum
cd Diamoneum
mkdir build && cd $_
cmake ..
make
