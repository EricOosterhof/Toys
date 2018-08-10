#!/bin/bash
[ "$0" = "$BASH_SOURCE" ] && echo "This script is meant to be sourced." 1>&2 && exit 1

functionLocalTest ()
{
    ls;
    local STATUS="${PIPESTATUS[0]}";
    STATUS="FUNCTION LOCAL TEST"
    return $STATUS
}

functionScopeTest ()
{
    local STATUS="SCOPE TEST FUNCTION"
    functionLocalTest
    echo $STATUS
}
