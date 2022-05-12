#!/bin/bash

wget https://raw.githubusercontent.com/bkaradzic/bgfx/master/bindings/cs/bgfx.cs &&
wget https://raw.githubusercontent.com/bkaradzic/bgfx/master/bindings/cs/bgfx_dllname.cs &&
mkdir ./src/bgfx &&
mv bgfx* ./src/bgfx


echo "see also https://bkaradzic.github.io/bgfx/build.html to build bgfx library"
echo "use `third` folder for git repositories and all binaries for bgfx"
mkdir third
