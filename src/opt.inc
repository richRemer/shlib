#!/bin/bash -e

! $(return &>/dev/null) \
    && echo `basename $0`": not intended to be run run directly" >&2 \
    && exit 1

[ $OPT_INC ] && return || OPT_INC=loaded

import err

OPT_defs=()

# return error status if option does not exist
# Usage:
#   opt.exists <option>
# Example:
#   opt.exists -f       # generates error if '-f' has not been defined
opt.exists () {
    local optdef
    local opt

    for optdef in ${OPT_defs[@]}; do
        opt=`echo $optdef | awk '{print $1}'`
        [ "$1" == "$opt" ] && return
    done

    false
}

# read an option from the arguments and set OPT_name, OPT_val, and OPT_shift
# for caller.
# Usage:
#   opt.read [<arg> ...]
# Example:
#   opt.read "$@"
#   shift $OPT_shift
opt.read () {
    OPT_name=
    OPT_val=
    OPT_shift=0

    
}

# define a flag option
# Usage:
#   opt.flag [-i|--increment] <name> <flag>
# Examples:
#   opt.flag secure -s
#   opt.flag secure --secure-mode
#   opt.flag -i verbosity --verbose
opt.flag () {
    local optname="$1"
    local inc

    [ "$optname" == -i ] || [ "$optname" == "--increment" ]
    [ "$1" == -i ] || [ "$1" && inc="$1"
}
