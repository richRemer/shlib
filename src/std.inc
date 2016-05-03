#!/bin/bash -e

! $(return &>/dev/null) \
    && echo `basename $0`": not intended to be run run directly" >&2 \
    && exit 1

[ $STD_INC ] && return || STD_INC=loaded

# print message to stdout
# Usage:
#   std.out <msg>
# Example:
#   std.out "Started things"        # prints 'Started things' to STDOUT
std.out () {
    echo "$1"
}

# print message to stderr
# USage:
#   std.err <msg>
# Example:
#   std.err "Bad stuff"             # prints 'Bad stuff' to STDERR
std.err () {
    echo "$1" 1>&2
}
