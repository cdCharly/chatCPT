//
// Created by Charly CATIN--RICO on 11/03/2026.
//

#ifndef CHATBOT_INTENTS_H
#define CHATBOT_INTENTS_H
#include <string>



#endif //CHATBOT_INTENTS_H

#pragma once
#include <vector>
#include <string>

// On définit la structure ici pour qu'elle soit accessible partout
struct Intent {
    int id;
    std::vector<std::string> inSentence;
    std::vector<std::string> outSentence;
};

// On crée une liste globale d'intentions
// On utilise 'inline' pour pouvoir définir la variable directement dans le header
std::vector<Intent> globalIntents = {
    {
        0,
        {"hello", "hey", "coucou", "bonjour"},
        {"Bienvenue je suis CHATBOT", "Bonjour à toi !", "Bonjour ! Comment vas tu ?"}
    },
    {
        1,
        {"salut", "a plus tard", "a plus", "a+", "aurevoir", "goodbye"},
        {"Aurevoir, à la prochaine !", "A une prochaine fois", "Salut !"}
    },

    {
        2,
        {"comment ca va ?", "ca va ?", "comment tu va ?", "quelles sont tes ressentis ?", "comment tu te sens ?"},
        {"Je suis un chatbot je n'ai pas d'émotions, comment tu vas ?"}
    },
    {3,
        {"je vais bien", "bien", "top", "super", "en pleine forme", "super bien", "top"},
        {"super !", "c'est génial", "top alors", "bah nickel ducoup", "allerrrr", "gogogo"}
    },
    {
        4,
            {"quoi ?", "quoi", "c'est la quoi", "c'est quoi ?", "pourquoi", "pourquoi ?", "en quoi", "en quoi ?"},
            {"feur"}
    },
    {
        5,
        {"tu pue", "t'es moche", "t'es con", "tu dis de la merde", "t'es trop bete", "t con", "bouhouhou le gamin", "gros nullos", "nullos", "nul"},
        {"ftg"}
    },
    {
    6,
        {"ok", "feur"},
        {"sérieux là ?"}
    }
};