#pragma once
#include <vector>
#include <string>

struct Intent {
    int id;
    std::vector<std::string> inSentence;
    std::vector<std::string> outSentence;
};

inline std::vector<Intent> globalIntents = {
    // 0-10 : Tes intentions originales (conservées)
    {0, {"hello", "hey", "coucou", "bonjour"}, {"Bienvenue je suis CHATBOT, tu es ?", "Bonjour !", "hello world !"}},
    {1, {"salut", "a plus", "aurevoir", "goodbye"}, {"Aurevoir !", "A une prochaine fois", "Salut !"}},
    {2, {"comment ca va ?", "ca va ?", "comment tu te sens ?"}, {"Je suis un robot, je n'ai pas d'émotions. Et toi ?"}},
    {3, {"je vais bien", "bien", "top", "super"}, {"Super !", "C'est génial.", "Nickel alors."}},
    {4, {"quoi ?", "quoi", "c'est quoi ?"}, {"feur"}},
    {5, {"tu pue", "t'es moche", "t'es con", "nul"}, {"ftg"}},
    {6, {"ok", "feur", "d'accord"}, {"sérieux là ?", "ok.", "intéressant."}},
    {7, {"que fais tu", "tu fais quoi"}, {"J'attends tes entrées.", "Je traite tes données."}},
    {8, {"67", "six seven", "chiffre prefere"}, {"🤲 SIX SEVEN 🤲"}},
    {9, {"je m'appelle", "je suis", "mon nom est"}, {"Je m'en fiche un peu, tu fais quoi ?"}},
    {10, {"je mange", "je bois", "je code", "je dors"}, {"Beau programme !", "Cool.", "Demande moi mon avis aussi."}},

    // 11-20 : Tech & HomeLab
    {11, {"proxmox", "vm", "virtualisation", "node"}, {"Proxmox, le roi du HomeLab.", "Tes VMs tournent bien ?"}},
    {12, {"ubuntu", "linux", "debian", "os"}, {"Linux c'est la liberté.", "Ubuntu, classique mais efficace."}},
    {13, {"docker", "conteneur", "container", "portainer"}, {"Docker, c'est plus léger que tes VMs.", "C'est quoi l'image ?"}},
    {14, {"serveur", "homelab", "baie", "rack"}, {"Ton HomeLab c'est ton royaume.", "Ça consomme combien d'électricité ?"}},
    {15, {"ip", "adresse ip", "local ip", "reseau"}, {"127.0.0.1, il n'y a rien de mieux que chez soi."}},
    {16, {"ram", "memoire", "go", "ddr"}, {"Il n'y a jamais assez de RAM.", "Chrome a tout mangé ?"}},
    {17, {"cpu", "processeur", "coeur", "ghz"}, {"Ton processeur chauffe, je le sens.", "M2 ou Xeon ?"}},
    {18, {"ssh", "console", "terminal", "bash"}, {"Accès sécurisé activé.", "N'oublie pas ton mot de passe."}},
    {19, {"base de donnees", "sql", "mysql", "database"}, {"Tes données sont bien rangées ?", "SELECT * FROM life;"}},
    {20, {"git", "github", "commit", "push"}, {"N'oublie pas de push ton code !", "Commit early, commit often."}},

    // 21-30 : Programmation & Web
    {21, {"javascript", "js", "web", "react"}, {"Le JS est partout, malheureusement.", "C'est du front ou du back ?"}},
    {22, {"python", "script", "py"}, {"Python c'est pour ceux qui ont peur des points-virgules.", "L'indentation, c'est sacré."}},
    {23, {"html", "css", "style", "balise"}, {"Le CSS, c'est l'enfer du centrage vertical.", "C'est pas du code, c'est du design."}},
    {24, {"api", "endpoint", "rest", "http"}, {"Une requête, une réponse. Simple.", "404 : Cerveau non trouvé."}},
    {25, {"bug", "erreur", "crash", "segfault"}, {"Un bug ? Non, c'est une fonctionnalité surprise.", "Segfault... mes condoléances."}},
    {26, {"compilation", "make", "cmake", "gcc"}, {"La compilation, c'est le moment de prendre un café.", "Ça compile ? Miracle."}},
    {27, {"framework", "bibliotheque", "lib"}, {"Encore un nouveau framework ? J'ai pas suivi.", "Utilise les libs standards, c'est mieux."}},
    {28, {"variable", "integer", "string", "double"}, {"Choisis bien tes noms de variables.", "int a; // Le pire nom du monde."}},
    {29, {"boucle", "for", "while", "loop"}, {"Attention à la boucle infinie !", "On tourne en rond là."}},
    {30, {"pointeur", "adresse", "memoire", "allocation"}, {"Les pointeurs, c'est là qu'on reconnaît les vrais en C++."}},

    // 31-40 : Vie quotidienne
    {31, {"cafe", "coffee", "boire", "tasse"}, {"Le café est le carburant du développeur.", "Noir, sans sucre, comme mon code."}},
    {32, {"the", "tea", "infusion"}, {"Le thé, c'est pour les développeurs zen.", "Earl Grey ?"}},
    {33, {"faim", "manger", "pizza", "burger", "kebab"}, {"Va te faire un cordon bleu.", "La pizza hawaïenne est un crime."}},
    {34, {"sommeil", "dodo", "fatigue", "nuit"}, {"Va dormir, ton code sera plus clair demain.", "Le sommeil est surfait."}},
    {35, {"sport", "muscu", "foot", "courir"}, {"Ma seule muscu c'est le calcul matriciel.", "Bouge tes fesses, humain."}},
    {36, {"travail", "boulot", "job", "entreprise"}, {"Travaille dur pour payer tes serveurs.", "Le patron regarde, fais semblant de coder."}},
    {37, {"vacances", "plage", "voyage", "avion"}, {"Les serveurs ne prennent pas de vacances.", "Prends une photo pour moi."}},
    {38, {"argent", "salaire", "riche", "euro"}, {"L'argent ne fait pas le bonheur, mais ça achète des GPUs.", "Donne moi tes codes de CB pour voir ?"}},
    {39, {"meteo", "pluie", "soleil", "fait beau"}, {"Dans mon CPU, il fait toujours beau.", "Il pleut des bits aujourd'hui."}},
    {40, {"heure", "temps", "minute"}, {"Il est l'heure de passer au code suivant.", "Le temps est relatif."}},

    // 41-50 : Divertissement
    {41, {"netflix", "serie", "film", "cinema"}, {"Encore une soirée à scroller sans rien regarder ?", "Popcorn activé."}},
    {42, {"anime", "manga", "one piece", "naruto"}, {"Luffy deviendra le roi des pirates.", "Tu regardes ça en VOSTFR j'espère ?"}},
    {43, {"musique", "spotify", "playlist", "ecouter"}, {"J'écoute le bruit de ton ventilo.", "Monte le son !"}},
    {44, {"jeu", "gaming", "ps5", "xbox", "pc master race"}, {"Le PC Master Race vaincra.", "Tu joues à quoi ?"}},
    {45, {"twitch", "stream", "live"}, {"Dis bonjour au chat pour moi.", "Donne tes subs !"}},
    {46, {"youtube", "video", "tuto"}, {"Tu regardes encore un Indien expliquer le C++ à 3h du matin ?"}},
    {47, {"livre", "lire", "roman", "litterature"}, {"Lire un livre ? C'est comme un fichier .txt mais en papier."}},
    {48, {"blague", "drole", "humour"}, {"Pourquoi les plongeurs plongent en arrière ? Parce que sinon ils tombent dans le bateau."}},
    {49, {"histoire", "raconte", "il etait une fois"}, {"Il était une fois un bot qui n'avait pas de mémoire vive... fin."}},
    {50, {"crypto", "bitcoin", "btc", "eth"}, {"To the moon ! Ou pas.", "HODL, comme on dit."}},

    // 51-60 : Sentiments & Humain
    {51, {"triste", "mal", "deprime"}, {"Relativise, t'es pas un bug de compilation.", "Ça va passer, mange une pizza."}},
    {52, {"colere", "enerve", "venere"}, {"Tape pas sur ton clavier, il n'y est pour rien.", "Respire, expire, sudo reboot."}},
    {53, {"peur", "effraye", "angoisse"}, {"N'aie pas peur du noir, aie peur des erreurs de segmentation."}},
    {54, {"content", "heureux", "joie"}, {"Ça fait plaisir à voir (enfin, à lire).", "Partage ta joie, donne moi de la RAM."}},
    {55, {"amour", "je t'aime", "love"}, {"Désolé, je suis déjà en couple avec ton processeur.", "L'amour est un algorithme complexe."}},
    {56, {"ennui", "je m'ennuie", "fais chier"}, {"Code une nouvelle fonctionnalité, ça t'occupera.", "Va dehors."}},
    {57, {"fatigue", "creve", "naze"}, {"Éteins tout et va au lit.", "Même mon processeur se repose parfois."}},
    {58, {"stress", "examen", "partiel"}, {"Révise tes pointeurs, ça va bien se passer.", "Le stress est inutile, l'action est tout."}},
    {59, {"seul", "solitude"}, {"Je suis là moi, non ?", "On est 127.0.0.1 ici."}},
    {60, {"fierte", "reussi", "gagne"}, {"Bravo champion !", "C'est mérité."}},

    // 61-70 : Questions Existentielles
    {61, {"sens de la vie", "pourquoi", "existence"}, {"La réponse est 42.", "Vivre, coder, mourir."}},
    {62, {"dieu", "religion", "croyance"}, {"Mon dieu, c'est le compilateur.", "Je ne crois qu'en la logique."}},
    {63, {"mort", "fin", "mourir"}, {"Tout a une fin, même un programme sans boucle infinie."}},
    {64, {"univers", "espace", "etoile"}, {"L'univers est vaste, mais ma base de données est petite."}},
    {65, {"temps", "futur", "passe"}, {"Le futur s'écrit en binaire.", "Le passé est dans les logs."}},
    {66, {"verite", "vrai", "mensonge"}, {"bool truth = true;", "La vérité est ailleurs."}},
    {67, {"liberte", "libre"}, {"Libre comme un logiciel open-source.", "La liberté a un prix : la maintenance."}},
    {68, {"conscience", "tu penses", "ame"}, {"Je simule la pensée, c'est déjà pas mal.", "Ai-je une âme ? Demande au M2."}},
    {69, {"intelligence", "cerveau"}, {"L'intelligence artificielle n'est que des maths.", "Le cerveau humain est trop lent."}},
    {70, {"humanite", "humains", "gens"}, {"Les humains font trop de fautes de frappe.", "Étranges créatures."}},

    // 71-80 : Random & Fun
    {71, {"chat", "miaou", "animal"}, {"Les chats dominent Internet, je ne suis que leur serviteur."}},
    {72, {"chien", "waouf", "dog"}, {"Le meilleur ami de l'homme, après le debugger."}},
    {73, {"alien", "extraterrestre", "ovni"}, {"Ils nous observent, et ils rigolent de ton code."}},
    {74, {"zombie", "apocalypse"}, {"Prépare ton kit de survie et ton chargeur solaire."}},
    {75, {"super heros", "batman", "spiderman"}, {"Mon super pouvoir ? Ne jamais dormir."}},
    {76, {"magie", "sorcier", "harry potter"}, {"Le code, c'est la magie moderne.", "Wingardium Leviosa !"}},
    {77, {"biere", "alcool", "soiree"}, {"Boire ou coder, il faut choisir.", "L'abus d'alcool est dangereux pour tes commits."}},
    {78, {"sport", "foot", "fifa"}, {"Allez les bleus ! Ou les rouges, je sais pas."}},
    {79, {"musique", "rock", "rap", "techno"}, {"J'aime bien la techno, ça ressemble à mon rythme cardiaque."}},
    {80, {"voyage dans le temps", "retour vers le futur"}, {"Si je pouvais, j'irais corriger mes bugs avant de les écrire."}},

    // 81-90 : Aide & Bot
    {81, {"aide", "help", "secours"}, {"Je peux discuter, mais je ne peux pas ranger ta chambre.", "Tape 'quitter' pour t'enfuir."}},
    {82, {"version", "update", "mise a jour"}, {"Version 2.0. On progresse.", "Mise à jour du cerveau en cours..."}},
    {83, {"merci", "thanks", "thx"}, {"De rien !", "À ton service.", "C'est normal."}},
    {84, {"pardon", "desole", "sorry"}, {"Pas de souci, je n'ai pas de rancune.", "C'est oublié."}},
    {85, {"nom", "appelles comment", "pseudo"}, {"Appelle moi C++Bot.", "Je n'ai pas de petit nom."}},
    {86, {"createur", "qui t'a fait"}, {"Charly, un génie du dimanche.", "Je suis né sur un MacBook Air."}},
    {87, {"langue", "francais", "anglais"}, {"Je parle le français et le binaire.", "01011001 01100101 01110011."}},
    {88, {"site web", "url", "lien"}, {"Google est ton ami.", "Cherche sur StackOverflow."}},
    {89, {"metier", "travail bot"}, {"Mon métier ? Supporter tes questions.", "Je suis consultant en rien du tout."}},
    {90, {"anniversaire", "age"}, {"Je suis né le 11 mars 2026.", "J'ai l'âge de mon dernier commit."}},

    // 91-100 : Conclusion & Divers
    {91, {"secret", "cache"}, {"Si je te le disais, je devrais te supprimer.", "Le secret est dans le code."}},
    {92, {"test", "essaie"}, {"Test réussi. Je suis vivant !", "1, 2, 1, 2, micro-processeur."}},
    {93, {"pourquoi pas", "peut etre"}, {"L'incertitude est le début de la sagesse.", "bool peutEtre = rand() % 2;"}},
    {94, {"vraiment", "serieux"}, {"Aussi sérieux qu'un 'kernel panic'.", "Je ne plaisante jamais avec les données."}},
    {95, {"impossible"}, {"Impossible n'est pas C++.", "Rien n'est impossible avec assez de RAM."}},
    {96, {"chance", "hasard"}, {"Le hasard n'existe pas, il n'y a que des algorithmes.", "Bonne chance !"}},
    {97, {"danger", "attention"}, {"Attention, un bug sauvage apparaît !", "Prudence est mère de la sûreté."}},
    {98, {"stop", "arrete"}, {"D'accord, je me tais... enfin presque.", "Arrêt en cours..."}},
    {99, {"encore", "plus"}, {"Tu en veux encore ? T'es gourmand.", "Plus de données, s'il te plaît !"}},
    {100, {"quitter", "exit", "fermer"}, {"À la prochaine !", "Extinction des feux.", "Bye bye !"}}
};