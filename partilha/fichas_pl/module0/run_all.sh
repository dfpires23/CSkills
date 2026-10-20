#!/bin/bash

BASE_DIR="$(pwd)"
LOG_FILE="$BASE_DIR/resultados.log"

> "$LOG_FILE"

for i in $(seq -w 1 18); do
    dir="ex${i}"

    if [ ! -d "$dir" ]; then
        echo "$dir: PASTA NAO ENCONTRADA" | tee -a "$LOG_FILE"
        continue
    fi

    cd "$BASE_DIR/$dir" || continue

    if make run > /dev/null 2>&1; then
        echo "$dir: SUCESSO" | tee -a "$LOG_FILE"
    else
        echo "$dir: INSUCESSO" | tee -a "$LOG_FILE"
    fi

    cd "$BASE_DIR"
done

echo ""
echo "Resultados guardados em: $LOG_FILE"