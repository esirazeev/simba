#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Release -H. -Bbuild/release
make -C build/release -j8