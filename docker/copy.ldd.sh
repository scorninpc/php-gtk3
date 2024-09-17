#!/bin/bash

#ldd -u -r $1 | awk 'NF == 4 { system("cp " $3 " /app/usr/lib") }'

ldconfig -p | grep libgladeui-2.so | tr ' ' '\n' | grep /
ldconfig -p | grep libgtksourceview-3.0.so | tr ' ' '\n' | grep /


# cp /lib/x86_64-linux-gnu/libgladeui-2.so /app/usr/lib/libgladeui-2.so.13
