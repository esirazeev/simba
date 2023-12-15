#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Debug -H. -Bbuild/debug
make -C build/debug -j8