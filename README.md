# Minitalk
Minitalk est un projet de communication entre deux programmes via des signaux UNIX. L’objectif est d’envoyer des messages d’un client vers un serveur, bit par bit, en utilisant uniquement les signaux SIGUSR1 et SIGUSR2.

## 🧩 Objectif
Créer un système simple de transmission de texte entre processus en exploitant la mécanique des signaux.

## ⚙️ Fonctionnalités
Un serveur capable de recevoir et d’afficher des messages envoyés par le client

Un client qui convertit chaque caractère en bits et les envoie via signaux

Gestion correcte des signaux et des erreurs

Transmission fluide de messages (y compris les caractères spéciaux)

## ▶️ Utilisation
Compiler le projet :

    ´´´bash
    make
Lancer le serveur :

    ´´´bash
    ./server
Copier le PID affiché par le serveur, puis lancer le client :

    ´´´bash
    ./client <PID_du_serveur> "Votre message ici"
    
## 🧠 Compétences acquises
Utilisation des signaux UNIX (kill, signal, sigaction)

Transmission d’informations bit à bit

Gestion de la synchronisation entre processus

Manipulation des chaînes de caractères et des conversions binaires

## ✨ Partie Bonus
Ce projet inclut également des fonctionnalités bonus qui enrichissent l’expérience de communication entre le client et le serveur :

✅ Accusé de réception : Le serveur envoie un signal de confirmation au client une fois le message entièrement reçu.

🌐 Support Unicode : Le client est capable d’envoyer des caractères en UTF-8, permettant ainsi la transmission de messages multilingues (ex. : العربية، 中文、🌍).
