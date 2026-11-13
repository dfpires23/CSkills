#!/bin/bash

BASE_DIR="$(pwd)"
LOG_FILE="$BASE_DIR/resultados.log"

> "$LOG_FILE"

for i in $(seq -w 1 22); do
    dir="ex${i}"

    if [ ! -d "$BASE_DIR/$dir" ]; then
        echo "$dir: PASTA NAO ENCONTRADA" | tee -a "$LOG_FILE"
        continue
    fi

    if (cd "$BASE_DIR/$dir" && make > /dev/null 2>&1); then
        echo "$dir: SUCESSO" | tee -a "$LOG_FILE"
    else
        echo "$dir: INSUCESSO" | tee -a "$LOG_FILE"
    fi
done

echo ""
echo "Resultados guardados em: $LOG_FILE"
