#! /bin/bash
ldd $1 | grep -q $2
exit $?