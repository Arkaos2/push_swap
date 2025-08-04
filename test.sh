#!/bin/bash

# === CONFIG ===
EXEC=./push_swap           # chemin vers ton exécutable
TRIES=1000                   # nombre d'essais pour taille 100
SIZE=100                   # seule taille testée

# === FONCTION DE TEST ===
test_push_swap() {
    size=$1
    echo "=== Taille: $size ==="
    total=0
    max=0

    for ((i=1; i<=TRIES; i++)); do
        ARG=$(shuf -i 0-$(($size * 10)) -n $size | tr '\n' ' ')
        COUNT=$($EXEC $ARG | wc -l)

        echo "Essai $i : $COUNT instructions"
        total=$((total + COUNT))
        if [ $COUNT -gt $max ]; then
            max=$COUNT
        fi
    done

    avg=$((total / TRIES))
    echo "--> Moyenne : $avg  |  Max : $max"
    echo ""
}

# === TEST UNIQUE POUR 100 ===
test_push_swap $SIZE
