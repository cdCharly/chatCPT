//
// Created by Charly CATIN--RICO on 11/03
//
// CHATBOT assez basique pour comprndre le fonctionnement d'un réseau de neuronnes
//TODO j'aimerai ajouter des mathématiques pour qu'il comprenne des calculs de base (+ - = * / ** sqrt)
// ajouter
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <cstdlib> // Pour rand()
#include<cmath>
#include <fstream>
//#include "intents.h"
#include "intentsGemini.h"

using namespace std;


//structure d'intention de base
/*
struct Intent {
    int id;
    vector<string> inSentence;
    vector<string> outSentence;
};
*/

// structure qui va servir de base de comprehension pour le reseau de neuronnes
struct TrainingData {
    vector<int> input; // le bag de la phrase
    vector<int> output; // one hot encoding pour l'intention
};


// neurone du chatbot
struct Neuron {
    double value = 0.0; // resultat de son calcul | niveau d'activation
    double bias = 0.0; // sensibilite du neurone | + bias est haut + il s'active fort
    vector<double> weights; // poids du neurone par rapport à sa profondeur de connexion
};

// réseau de neurone du chatbot (map du cerveau)
struct NeuralNetwork {
    vector<Neuron> hiddenlayer; // couche intermediaire de calcul
    vector<Neuron> outputlayer; // sortie du réseau final
};



vector<Intent> INTENTSTRUCT; // global car souvent utilisée, il sert à garder toutes les intentions


// debug set
void printSet(set<string> const &v) {
    for (const string& word : v) {
        cout << word << endl;
    }
}

// debug vector
void printVector(vector<string> const &v) {
    for (int i = 0; i <v.size(); i++) {
        cout << v[i] << endl;
    }
}


// sert à passer d'un phrase et d'un vocabulaire à une tokenisation par correspondance de mot
vector<int> getBagOfWords(string const &sentence, vector<string> const &vocab) {
    // vector qui sert de base pour tokeniser, initialisé à 000...00
    vector<int> bag;
    for (int i = 0; i < vocab.size(); i++) {
        bag.push_back(0);
    }
    stringstream flux(sentence);
    string motExtrait;
    while (flux >> motExtrait){
                                                        // 3. Pour chaque mot extrait de 'sentence', chercher à quel index il se trouve dans 'vocab'.
        for (int i = 0; i < vocab.size(); i++) {
            if (motExtrait == vocab[i]) bag[i] = 1;    // si on retrouve le mot alors on tokenise à 1
        }
    }
    return bag;
}



// recuperer la bonne intuition
vector<int> getTargetVector(int intentId, int totalIntents) {
    vector<int> target;
    for (int i = 0; i < totalIntents; i++) { // init à 0, 0% de chance dans toutes les intuitions
        target.push_back(0);
    }
    target[intentId] = 1; // on met de la chance sur la bonne intention visée

    return target;
}

// Fonction qui génère un nombre décimal aléatoire entre -1.0 et 1.0 (Gemini)
double randomWeight() {
    return ((double)rand() / (RAND_MAX)) * 2.0 - 1.0;
}

// fonciton sigmoide
double sigmoide(double x) {
    return 1.0/(1.0+exp(-x));
}


// initialisation du cerveau,
NeuralNetwork initNetwork(int inputSize, int hiddenSize, int outputSize) {
    NeuralNetwork net;

    // 1. Initialiser la couche cachée (hiddenlayer)
    for (int i = 0; i < hiddenSize; i++) {
        Neuron n;
        n.value = 0.0;
        n.bias = randomWeight();

        // mettre un poids au hasard pour chaque neurone de la couche cachée
        for (int j = 0; j < inputSize; j++) {
            n.weights.push_back(randomWeight());
        }

        net.hiddenlayer.push_back(n); // mettre le neuron initialisé dans la couche cachée
    }

    // initialiser la couche de sortie (outputlayer)
    for (int i = 0; i < outputSize; i++) {
        Neuron nO; // neuron couche output
        nO.value = 0.0;
        nO.bias = randomWeight();
        for (int j = 0; j < hiddenSize; j++) {
            nO.weights.push_back(randomWeight());
        }
        net.outputlayer.push_back(nO); // ajouter le neuron de sortie à la couche de sortie
    }


    return net; // réseau complet
}

// trajet que l'info fait pour formuler une prediction depuis une input un bag
vector<double> forwardPass(NeuralNetwork& net, vector<int> const &input) {

    // partie input | couche cachée
    for (int i = 0; i < net.hiddenlayer.size(); i++) { // parcourir la couche de neurones cachée
        double somme = 0.0;
        for (int j = 0; j < input.size(); j++) { // un neurone
            somme += input[j] * net.hiddenlayer[i].weights[j]; // formule de la somme
        }
        somme += net.hiddenlayer[i].bias; // ajouter la sensibilité du neurone
        somme = sigmoide(somme);        // passage en sigmoide
        net.hiddenlayer[i].value = somme;   // attribuer à la valueur du neurone
    }

    // partie output | couche de sortie
    vector<double> res;
    for (int i = 0; i < net.outputlayer.size(); i++) {
        double outputSomme = 0.0;
        for (int j = 0; j < net.hiddenlayer.size(); j++) {
            outputSomme += net.hiddenlayer[j].value * net.outputlayer[i].weights[j];
        }
        outputSomme += net.outputlayer[i].bias;
        outputSomme = sigmoide(outputSomme);
        net.outputlayer[i].value = outputSomme;
        res.push_back(net.outputlayer[i].value);
    }
    return res;

}

// derivee de la sigmoide
double sigmoideDerivee(double s) {
    return s*(1-s);
}



void train(NeuralNetwork& net, vector<int> const &input, vector<int> const &target, double const learningRate) {
    // ÉTAPE 1 : On fait un Forward Pass pour que chaque neurone
    // ait sa 'value' à jour par rapport à l'entrée
    forwardPass(net, input);

    // ÉTAPE 2 : Calcul des gradients de la couche de sortie
    vector<double> outputGradients;
    for (int i = 0; i < net.outputlayer.size(); i++) {
        double erreur = target[i] - net.outputlayer[i].value;
        double gradient = erreur * sigmoideDerivee(net.outputlayer[i].value);
        outputGradients.push_back(gradient);
    }

    // ÉTAPE 3 : Calcul des gradients de la couche cachée
    // C'est ici que tu interviens !
    vector<double> hiddenGradients;


    for (int j = 0; j < net.hiddenlayer.size(); j++) {
        double errorSomme = 0.0; // remise à 0 pour chaque nouveau
        for (int k = 0; k < net.outputlayer.size(); k++) {
            double gradientSortie = outputGradients[k] * net.outputlayer[k].weights[j];
            errorSomme += gradientSortie;
        }
        double gradient = errorSomme * sigmoideDerivee(net.hiddenlayer[j].value);
        hiddenGradients.push_back(gradient);
    }

    // maj des poids des neurones couche de sortie
    for (int i = 0; i < net.outputlayer.size(); i++) {
        for (int j = 0; j < net.outputlayer[i].weights.size(); j++) {
            net.outputlayer[i].weights[j] += learningRate * outputGradients[i] * net.hiddenlayer[j].value; // formule
        }
        net.outputlayer[i].bias += learningRate * outputGradients[i];
    }

    // maj des poids des neurones couche cachée
    for (int i = 0; i < net.hiddenlayer.size(); i++) {
        for (int j = 0; j < net.hiddenlayer[i].weights.size(); j++) {
            net.hiddenlayer[i].weights[j] += learningRate * hiddenGradients[i] * input[j]; // formule
        }
        net.hiddenlayer[i].bias += learningRate * hiddenGradients[i];
    }
}

// genere le vocabulaire depuis le header
vector<string> genererVocabulaire(const vector<Intent>& intents) {
    set<string> vocabSet;

    for (const auto& intent : intents) {
        for (const string& phrase : intent.inSentence) {
            stringstream flux(phrase); // recuperer les mots sous flux
            string mot;
            while (flux >> mot) {
                vocabSet.insert(mot);   // mettre les mot dans le vocabulaire
            }
        }
    }
    // convetir set -> vector
    return vector<string>(vocabSet.begin(), vocabSet.end());
}


vector<TrainingData> genererTrainingSet(const vector<Intent>& intents, const vector<string>& vocab) {
    vector<TrainingData> set;

    for (const auto& intent : intents) {
        for (const string& phrase : intent.inSentence) {
            TrainingData data;
            // tokenisation
            data.input = getBagOfWords(phrase, vocab);
            // initialisation de la bonne intention
            data.output = getTargetVector(intent.id, intents.size());

            set.push_back(data);
        }
    }
    return set;
}


int main() {
    // init hazard + vocab
    srand(time(0));

    // recuperer vocabulaire depuis le header
    vector<string> finalVocab = genererVocabulaire(globalIntents);
    vector<TrainingData> trainingSet = genererTrainingSet(globalIntents, finalVocab);

    // init cerveau
    NeuralNetwork cerveau = initNetwork(finalVocab.size(), 8, globalIntents.size());

    // entrainements
    cout << "--- entrainement de CHATBOT ---" << endl;
    double lr = 0.1;
    int trainingSize = 1000;
    cout << "combien d'entrainements ? (1000 (mauvais) - 10000 (bon)):" << endl;
    cin >> trainingSize;
    for (int e = 0; e < trainingSize; e++) {
        for (auto& data : trainingSet) {
            train(cerveau, data.input, data.output, lr);
        }
    }
    cout << "pret -> quitter pour arreter." << endl << endl;

    // boucle infinie de conversation
    string userInput;
    while (true) {
        cout << "VOUS : ";
        getline(cin, userInput); // recuperer input

        if (userInput == "quitter") break;

        // partie reponse reflexion

        // Tokenisation
        vector<int> bow = getBagOfWords(userInput, finalVocab);

        // passage dans le réseau de neuronnes
        vector<double> prediction = forwardPass(cerveau, bow);

        // meilleur intention
        int idGagnant = 0;
        for (int i = 1; i < prediction.size(); i++) {
            if (prediction[i] > prediction[idGagnant]) idGagnant = i;
        }

        // d. Répondre
        // reponse si confiance > 50%
        if (prediction[idGagnant] > 0.5) {
            vector<string> reponses = globalIntents[idGagnant].outSentence;
            string choix = reponses[rand() % reponses.size()];
            cout << "CHATBOT  : " << choix << " (Confiance: " << (prediction[idGagnant]*100) << "%)" << endl;
        } else {
            cout << "CHATBOT  : moi pas comprendre" << endl;
        }
        cout << "-------------------------------" << endl;
    }

    return 0;
}

/*
int main() {

    Intent helloIntent = {0, {"hello", "hey", "coucou", "bonjour"}, {"Bienvenue je suis CHATBOT", "Bonjour à toi !", "Bonjour ! Comment vas tu ?"}};
    INTENTSTRUCT.push_back(helloIntent);
    Intent endIntent = {1, {"salut", "a plus tard", "a plus", "a+", "aurevoir", "goodbye"}, {"Aurevoir, à la prochaine !", "A une prochaine fois", "Salut !"}};
    INTENTSTRUCT.push_back(endIntent);
    Intent careIntent = {2, {"comment ca va ?", "ca va ?", "good ?", "sup ?"}, {"je n'ai pas d'émotions", "je suis un chatbot IA"}};
    INTENTSTRUCT.push_back(careIntent);
    Intent askIntent = {3, {"qui est tu ?", "qui est chatbot ?", "c'est qui ?", "tu est qui ?", "qui represente tu ?", "qui tu est ?"}, {"je suis un chatbot IA fonctionnant grâce à un réseau de neuronne", "Un simple chatbot IA !"}};
    INTENTSTRUCT.push_back(askIntent);

    std::set<string> vocabChatbot;
    for (int i = 0; i < INTENTSTRUCT.size(); i++) {
        for (int j = 0; j < INTENTSTRUCT[i].inSentence.size(); j++) {
            //vocabChatbot.insert(INTENTSTRUCT[i].inSentence[j]);
            string phrase = INTENTSTRUCT[i].inSentence[j]; // ce bloc sert à séparer les petites phrases en mots
            stringstream flux(phrase); // init du flux avec la phrase
            string motIndependant;
            while (flux >> motIndependant) {
                vocabChatbot.insert(motIndependant);
            }
        }
    }

    vector<string> finalVocab(vocabChatbot.begin(), vocabChatbot.end());
    vector<TrainingData> trainingSet;

    for (int i = 0; i < INTENTSTRUCT.size(); i++) {
        for (int j = 0; j < INTENTSTRUCT[i].inSentence.size(); j++) {
            vector<int> in = getBagOfWords(INTENTSTRUCT[i].inSentence[j], finalVocab);
            vector<int> out = getTargetVector(INTENTSTRUCT[i].id, INTENTSTRUCT.size());
            trainingSet.push_back({in, out});
        }
    }


    srand(time(0));

    // init cerveau
    int tailleEntree = finalVocab.size();
    int tailleCachee = 8; // On choisit arbitrairement 8 neurones pour réfléchir
    int tailleSortie = INTENTSTRUCT.size();

    NeuralNetwork cerveau = initNetwork(tailleEntree, tailleCachee, tailleSortie);
    cout << "network cerveau init" << endl;

    //printVector(finalVocab);






    // test avant training
    string testPhrase = "bonjour";
    // 2. On la transforme en Bag of Words
    vector<int> testInput = getBagOfWords(testPhrase, finalVocab);
    // 3. On fait passer l'info dans le cerveau
    vector<double> prediction = forwardPass(cerveau, testInput);

    // 4. On affiche les probabilités de sortie
    cout << "Resultats pour '" << testPhrase << "' :" << endl;
    for (int i = 0; i < prediction.size(); i++) {
        cout << "Intention " << i << " : " << (prediction[i] * 100) << "%" << endl;
    }



    // training chatbot
    double learningRate = 0.1;
    int epochs = 100000;

    cout << "Entrainement" << endl;
    for (int e = 0; e < epochs; e++) {
        for (int i = 0; i < trainingSet.size(); i++) {
            train(cerveau, trainingSet[i].input, trainingSet[i].output, learningRate);
        }

        // Optionnel : afficher le progrès tous les 1000 cycles
        if (e % 1000 == 0) cout << "Epoch " << e << " terminee." << endl;
    }
    cout << "Entrainement fini" << endl;


    string test2 = "bonjour";
    vector<int> testInput2 = getBagOfWords(test2, finalVocab);
    vector<double> prediction2 = forwardPass(cerveau, testInput2);
    cout << "Resultats pour '" << testPhrase << "' :" << endl;
    for (int j = 0; j < prediction2.size(); j++) {
        cout << "Intention " << j << " : " << (prediction2[j] * 100) << "%" << endl;

    }



    // meilleur reponse
    int winnerIndex = 0; // indice
    for (int i = 1; i < prediction2.size(); i++) {
        // Si prediction2[i] est plus grand que prediction2[winnerIndex]...
        // alors winnerIndex devient i
        if (prediction2[i] > prediction2[winnerIndex]) winnerIndex = i;
    }

    // 2. Choisir une réponse aléatoire dans l'intention gagnante
    vector<string> reponsesPossibles = INTENTSTRUCT[winnerIndex].outSentence;
    // Crée une variable 'int randIdx' avec le modulo %
    int randIdx = rand() % reponsesPossibles.size();
    // Affiche la phrase finale avec cout !
    cout << reponsesPossibles[randIdx] << endl;



    string userInput;
    cout << "CHATBOT: Bonjour ! ('quitter' pour arreter)" << endl;

    while (true) {
        cout << "VOUS: ";
        getline(cin, userInput); // Pour lire toute la phrase avec les espaces

        if (userInput == "quitter") break;

        // 1. Transformer l'input en Bag of Words
        vector<int> currentInput = getBagOfWords(userInput, finalVocab);

        // 2. Faire passer dans le cerveau
        vector<double> currentPred = forwardPass(cerveau, currentInput);

        // 3. Trouver le gagnant (Argmax)
        int bestIdx = 0;
        for (int i = 1; i < currentPred.size(); i++) {
            if (currentPred[i] > currentPred[bestIdx]) bestIdx = i;
        }

        // 4. Répondre (seulement si le score est assez haut, sinon "je ne comprends pas")
        if (currentPred[bestIdx] > 0.5) {
            vector<string> responses = INTENTSTRUCT[bestIdx].outSentence;
            cout << "CHATBOT: " << responses[rand() % responses.size()] << endl;
        } else {
            cout << "CHATBOT: pas compris" << endl;
        }
    }



    return 0;
}
*/

