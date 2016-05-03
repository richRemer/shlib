#!/bin/bash -e

! $(return &>/dev/null) \
    && echo `basename $0`": not intended to be run run directly" >&2 \
    && exit 1

[ $ERR_INC ] && return || ERR_INC=loaded

import std

E_BADARG=1

# write error message and generate error status
# Usage:
#   err.gen <msg> [<status>]
# Examples:
#   err.gen "Something went wrong"  # exit with status 1
#   err.gen "More bad things" 101   # exit with status 101
err.gen () {
    std.err "$1"
    [ $# -gt 1 ] && exit $2 || exit 1
}
