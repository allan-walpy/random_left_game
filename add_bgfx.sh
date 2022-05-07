#!/bin/bash

wget https://raw.githubusercontent.com/bkaradzic/bgfx/master/bindings/cs/bgfx.cs &&
wget https://raw.githubusercontent.com/bkaradzic/bgfx/master/bindings/cs/bgfx_dllname.cs &&
mkdir ./src/bgfx &&
mv bgfx* ./src/bgfx
