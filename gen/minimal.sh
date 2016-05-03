#!/bin/bash -e

script=$0
cmd=`basename "$script"`
bin=`readlink -f \`dirname "$script"\``
src=`readlink -f "$bin/../src"`
lib=`readlink -f "$bin/../lib"`

. $src/shlib.inc
