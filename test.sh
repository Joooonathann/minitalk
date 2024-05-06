#!/bin/bash

# PID du serveur
SERVER_PID="$1"

# Exécute deux instances du client simultanément avec des données aléatoires
./client $SERVER_PID "coucou sdkf,ndsfknfdskjfdsnfdsfdsf essfdfdsfdsfds" & 
./client $SERVER_PID "helllooo sdfknsdfjkdsfnj njdnfsdjnfdsjsdfnj ndjnsdfjnds" &
wait
