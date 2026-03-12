//
// Created by Charly CATIN--RICO on 11/03/2026.
//

#ifndef CHATBOT_INTENTS_H
#define CHATBOT_INTENTS_H
#include <string>



#endif //CHATBOT_INTENTS_H

#pragma once
#include <vector>
//#include <string>

// On définit la structure ici pour qu'elle soit accessible partout
struct Intent {
    int id;
    std::vector<std::string> inSentence;
    std::vector<std::string> outSentence;
};

// On crée une liste globale d'intentions
// On utilise 'inline' pour pouvoir définir la variable directement dans le header
std::vector<Intent> globalIntents = {

    // bonjour
    {
        0,
        {"hello", "hey", "coucou", "bonjour"},
        {"Bienvenue je suis CHATBOT, tu es ?", "Bonjour à toi !, qui est tu ?", "Bonjour ! Comment vas tu ?", "Bonjour, qui est tu ?", "hello world !"}
    },

    // aurevoir
    {
        1,
        {"salut", "a plus tard", "a plus", "a+", "aurevoir", "goodbye"},
        {"Aurevoir, à la prochaine !", "A une prochaine fois", "Salut !"}
    },

    // sentiment chatbot
    {
        2,
        {"comment ca va ?", "ca va ?", "comment tu va ?", "quelles sont tes ressentis ?", "comment tu te sens ?"},
        {"Je suis un chatbot je n'ai pas d'émotions, comment tu vas ?"}
    },

    // sentiment user
    {3,
        {"je vais bien", "bien", "top", "super", "en pleine forme", "super bien", "top"},
        {"super.", "c'est génial, que fais-tu ?", "top alors, tfq ?", "bah nickel ducoup je propose qu'on arrete la", "allerrrr (men fou)", "gogogo direction la prison"}
    },

    // feur
    {
        4,
            {"quoi ?", "quoi", "c'est la quoi", "c'est quoi ?", "pourquoi", "pourquoi ?", "en quoi", "en quoi ?", "tu fais quoi ?"},
            {"feur"}
    },

    // insultes
    {
        5,
        {"tu pue", "t'es moche", "t'es con", "tu dis de la merde", "t'es trop bete", "t con", "bouhouhou le gamin", "gros nullos", "nullos", "nul"},
        {"ftg"}
    },

    // repondant
    {
    6,
        {"ok", "feur"},
        {"sérieux là ?"}
    },

    // question faire
    {7,
        {"que fais tu", "qu'est tu en train de faire ?"},
        {"j'attends les input user pour répondre", "je suis en attente de requete de l'utilisateur", "j'attends un requete !", "a ton avis ? j'attends ta requete"}
    },

    // 67
    {
        8,
        {"nombre","nombre prefere", "numéro", "num", "chiffre", "67", "six seven", "six", "seven", "blague", "drole", "soixante", "sept", "6", "7"},
        {"🤲 SIX SEVEN 🤲"}
    },

    // ragebait user presentation
    {
        9,
        {"je suis", "je m'appelle", "on m'appelle", "on me surnomme comme", "mon surnom est", "on m'a appele"},
        {"raconte pas ta vie, tfk", "je m'en fiche sah, tu fais quoi ?", "pourquoi je t'ai demandé j'en ai rien à fouttre, tu fais quoi ?"}
    },

    // ce que l'user fait actuellement
    {10,
        {"je te parle", "je mange", "je bois", "je fais du sport", "je code", "je suis avec toi", "je fais rien"},
        {"beau programme", "interessant", "tiptop", "demande moi aussi fin jsp on est deux la", "ok mais tu me demandes pas ?", "demandes moi aussi en vrai", "tu peux me demander mon activité aussi"}
    }
};