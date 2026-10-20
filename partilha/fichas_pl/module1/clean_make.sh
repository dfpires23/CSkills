#!/bin/bash

inicio=1
fim=22

for ((i=inicio; i<=fim; i++))
do
    pasta=$(printf "ex%02d" "$i")
    make --no-print-directory -C "$pasta" clean > /dev/null
done

echo "Clean: ex$(printf "%02d" "$inicio") -> ex$(printf "%02d" "$fim")"