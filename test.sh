#!/bin/bash

# Vérifier le nombre d'arguments
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <pid>"
    exit 1
fi

# Récupérer le PID passé en argument
pid="$1"

# Lancer deux instances du client en arrière-plan avec le PID et les messages
./client "$pid" "coucou c moi tchoupi"" &
./client "$pid" "cje suis hariryuheb nje suis hariryuhebje suis hariryuhebje suis hariryuhebje suis hariryuheb" &

# Attendre la fin de tous les processus en arrière-plan
wait

echo "Les deux instances du client ont terminé l'exécution."
