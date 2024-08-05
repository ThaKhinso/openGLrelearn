#!/bin/sh

set -xe

g++ -o openglrelearn relearn.cpp -lGLEW -lglfw3 -lGL -lrt -lm -ldl -lX11 -lpthread -lxcb -lXau

