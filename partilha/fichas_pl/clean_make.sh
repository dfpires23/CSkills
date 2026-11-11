#!/bin/bash

BASE_DIR="$(pwd)"

for module in module0 module1 module2 module3; do

    case "$module" in
        module0) total=20 ;;
        module1) total=22 ;;
        module2) total=21 ;;
        module3) total=20 ;;
    esac

    for ((i=1; i<=total; i++)); do
        pasta=$(printf "ex%02d" "$i")

        if [ -d "$BASE_DIR/$module/$pasta" ]; then
            make --no-print-directory -C "$BASE_DIR/$module/$pasta" clean > /dev/null 2>&1
        fi
    done

    echo "Clean: $module (ex01 -> ex$(printf "%02d" "$total"))"

done

echo "Todos os módulos foram limpos!"
