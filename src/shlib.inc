#!/bin/bash -e

! $(return &>/dev/null) \
    && echo `basename $0`": not intended to be run run directly" >&2 \
    && exit 1

[ $SHLIB_INC ] && return || SHLIB_INC=loaded
lib=`readlink -f \`dirname $BASH_SOURCE\``

# import a module
# Usage:
#   import <module>
import () {
    local module="$1"
    local path="$lib/$module.inc"

    [ -e "$path" ] \
        && . "$path" \
        || err.gen "Could not find '$module' module at '$path'"
}

import err
