
#!/bin/bash

BASE_DIR="$(pwd)"
LOG_FILE="$BASE_DIR/resultados.log"

> "$LOG_FILE"

for module in module0 module1 module2 module3; do

    echo "========== $module ==========" | tee -a "$LOG_FILE"

    case "$module" in
        module0) total=20 ;;
        module1) total=22 ;;
        module2) total=21 ;;
        module3) total=20 ;;
    esac

    for i in $(seq -w 1 "$total"); do
        dir="$BASE_DIR/$module/ex${i}"

        if [ ! -d "$dir" ]; then
            echo "$module/ex${i}: PASTA NAO ENCONTRADA" | tee -a "$LOG_FILE"
            continue
        fi

        if (cd "$dir" && make > /dev/null 2>&1); then
            echo "$module/ex${i}: SUCESSO" | tee -a "$LOG_FILE"
        else
            echo "$module/ex${i}: INSUCESSO" | tee -a "$LOG_FILE"
        fi
    done

    echo "" | tee -a "$LOG_FILE"

done

echo "Resultados guardados em: $LOG_FILE"
