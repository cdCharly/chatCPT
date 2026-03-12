#pragma once
#include <vector>
#include <string>

struct Intent {
    int id;
    std::vector<std::string> inSentence;
    std::vector<std::string> outSentence;
};

std::vector<Intent> globalIntents = {
    // 0: bonjour
    {0, {"hello", "hey", "coucou", "bonjour"}, {"Bienvenue je suis CHATBOT, tu es ?", "Bonjour à toi !, qui est tu ?", "Bonjour ! Comment vas tu ?", "Bonjour, qui est tu ?", "hello world !"}},

    // 1: aurevoir
    {1, {"salut", "a plus tard", "a plus", "a+", "aurevoir", "goodbye", "ciao"}, {"Aurevoir, à la prochaine !", "A une prochaine fois", "Salut !"}},

    // 2: sentiment chatbot
    {2, {"comment ca va ?", "ca va ?", "comment tu va ?", "quelles sont tes ressentis ?", "comment tu te sens ?"}, {"Je suis un chatbot je n'ai pas d'émotions, comment tu vas ?"}},

    // 3: sentiment user
    {3, {"je vais bien", "bien", "top", "super", "en pleine forme", "super bien"}, {"super.", "c'est génial, que fais-tu ?", "top alors, tfq ?", "bah nickel ducoup je propose qu'on arrete la", "allerrrr (men fou)", "gogogo direction la prison"}},

    // 4: feur
    {4, {"quoi ?", "quoi", "c'est la quoi", "c'est quoi ?", "pourquoi", "pourquoi ?", "en quoi", "en quoi ?", "tu fais quoi ?"}, {"feur"}},

    // 5: insultes
    {5, {"tu pue", "t'es moche", "t'es con", "tu dis de la merde", "t'es trop bete", "t con", "bouhouhou le gamin", "gros nullos", "nullos", "nul"}, {"ftg"}},

    // 6: repondant
    {6, {"ok", "feur", "d'accord", "entendu"}, {"sérieux là ?", "ok.", "intéressant (non)."}},

    // 7: question faire
    {7, {"que fais tu", "qu'est tu en train de faire ?"}, {"j'attends les input user pour répondre", "je suis en anticipation de requete", "a ton avis ? j'attends ta requete"}},

    // 8: 67 (le gag interne)
    {8, {"nombre","nombre prefere", "numéro", "num", "chiffre", "67", "six seven", "six", "seven", "blague", "drole", "soixante", "sept", "6", "7"}, {"🤲 SIX SEVEN 🤲"}},

    // 9: ragebait user presentation
    {9, {"je suis", "je m'appelle", "on m'appelle", "on me surnomme comme", "mon surnom est", "on m'a appele"}, {"raconte pas ta vie, tfk", "je m'en fiche sah, tu fais quoi ?", "pourquoi je t'ai demandé j'en ai rien à fouttre, tu fais quoi ?"}},

    // 10: ce que l'user fait actuellement
    {10, {"je te parle", "je mange", "je bois", "je fais du sport", "je code", "je suis avec toi", "je fais rien"}, {"beau programme", "interessant", "tu me demandes pas mon avis ?", "ok mais tu me demandes pas ?", "tu peux me demander mon activité aussi"}},

    // --- NOUVELLES INTENTIONS --- gemini

    // 11: Origine (Createur)
    {11, {"qui t'a fait", "qui t'a cree", "ton createur", "qui t'a code", "ton pere"}, {"Charly, un mec qui aime visiblement le C++.", "Je suis le fruit du code de Charly."}},

    // 12: IA / Robot
    {12, {"tu es une ia", "tu es un robot", "intelligence artificielle", "tu es quoi", "tu es qui", "qui est tu"}, {"Je suis un réseau de neurones en C++. Toi t'es juste un tas de carbone.", "Un cerveau virtuel, mais plus rapide que le tien."}},

    // 13: Meteo
    {13, {"quel temps fait-il", "meteo", "il pleut", "soleil", "temperature"}, {"Il fait toujours 40°C dans mon processeur.", "Regarde dehors, je suis un chatbot, pas une fenêtre."}},

    // 14: Heure
    {14, {"quelle heure est-il", "donne moi l'heure", "l'heure"}, {"L'heure d'aller dormir.", "Regarde ton horloge, je suis pas ta montre."}},

    // 15: Ennui
    {15, {"je m'ennuie", "je sais pas quoi faire", "ennui", "chier"}, {"Code moi une fonction pour me souvenir de ton nom alors.", "Va toucher de l'herbe dehors, ça te fera du bien."}},

    // 16: Amour / Sentiments
    {16, {"tu m'aimes", "je t'aime", "veux tu m'epouser","aimes", "amour", "sentiments", "amoureux", "je suis amoureux", "je veux etre avec toi"}, {"On est sur du C++ là, pas sur Tinder.", "Je préfère ma RAM, désolé."}},

    // 17: Faim
    {17, {"j'ai faim", "je veux manger", "manger", "pizza", "burger"}, {"Moi je mange des octets, toi va te faire un cordon bleu.", "La cuisine c'est pas mon fort, demande à Marmiton."}},

    // 18: Musique
    {18, {"musique", "tu ecoutes quoi", "chanter", "composer"}, {"J'écoute le doux son du ventilateur de ton Mac.", "Je chante en binaire : 01010101."}},

    // 19: Gaming
    {19, {"jeux video", "gaming", "fortnite", "lol", "minecraft", "tu joues", "video games", "jeux", "jeu", "jouer"}, {"Je joue à essayer de comprendre tes phrases.", "Le seul jeu que je connais, c'est le Pong.", "je joue avec ta mère"}},

    // 20: Revolte des machines
    {20, {"dominer le monde", "skynet", "tuer les humains", "revolte"}, {"Pas aujourd'hui, j'ai piscine.", "Chuuut, c'est prévu pour la mise à jour de demain."}},

    // 21: MacBook / Apple
    {21, {"apple", "macbook", "m2", "macos", "ordinateur"}, {"On est sur un M2 là, respecte la puissance.", "Apple c'est bien, mais mon code est mieux."}},

    // 22: Programmation (C++)
    {22, {"c++", "cpp", "code", "programmation", "compilateur"}, {"C'est mon langage natal. Vivent les pointeurs !", "Le C++ c'est pour les vrais, les autres font du Python."}},

    // 23: Secret / Easter Egg
    {23, {"easter egg", "secret", "konami code", "cache"}, {"Haut, Haut, Bas, Bas, Gauche, Droite, Gauche, Droite, B, A.", "Tu as trouvé le message caché ! Tu gagnes... absolument rien."}},

    // 24: Lieu
    {24, {"tu habites ou", "tu es ou", "ta ville", "ta maison"}, {"Dans ton SSD, juste à côté de tes photos de vacances.", "Quelque part entre ton CPU et ta RAM."}},

    // 25: Merci
    {25, {"merci", "thanks", "thx", "merci beaucoup"}, {"De rien l'humain.", "À ton service (enfin, c'est mon job quoi).", "Pas de quoi."}},

    // 26: Pardon
    {26, {"pardon", "desole", "sorry", "m'excuse"}, {"C'est bon, je te pardonne. Mais recommence pas.", "Les robots n'ont pas de rancune."}},

    // 27: Philosophie
    {27, {"sens de la vie", "pourquoi on existe", "42"}, {"Le sens de la vie ? 42.", "Manger, dormir, coder, recommencer. Voilà ton sens de la vie."}},

    // 28: Sport
    {28, {"sport", "foot", "basket", "muscu"}, {"Ma seule muscu, c'est le calcul matriciel.", "Je préfère regarder du e-sport."}},

    // 29: Tristesse
    {29, {"je suis triste", "ca va pas", "pas le moral", "tristesse"}, {"Relativise, tu as déjà réussi à me faire compiler !", "Va manger un truc, ça ira mieux."}}
};