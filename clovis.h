#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <array>

#include "Card.h"

using namespace std;


vector<Card> GenerJeuxCarte(){
    vector<Card> JeuxCarte;//on cr�e le vecteur o� seront stocker les cartes
    int carte;
    int tmp = 0;
    for(int a = 1; a<5; a++){//on cr�er toutes les cartes
        for(int i = 2 ; i < 15; i++){
            if (a==1){
                carte = 67;
               // cout << carte << endl;
            }else if (a==2){
             carte = 75;
                       //      cout << carte << endl;
            }else if (a==3){
             carte = 80;
                      //       cout << carte << endl;
            }else if (a==4){
             carte = 84;
                           //  cout << carte << endl;
            }
            JeuxCarte.push_back(Card(carte,i));  //on stocke la carte cr��
            cout << JeuxCarte[tmp] <<endl;
            tmp = tmp+1;
    }
}
return JeuxCarte;//on revoie tout le deck
}

vector<int> carteDejaPrise;//on cr�er une variable global pour toutes les cartes prise
vector<Card> JeuxCarte= GenerJeuxCarte();//on stoke le jeux de cartes

vector<Card> handGeneration(){
    cout<<"Cr�ation d'une main...\n";
    srand(time(NULL));//on initiallise l'al�atoire
    vector<Card> handJ1;//on cr�er la variable main
    if(carteDejaPrise.size()<46){//on regarde s'il y a suffisament de cartes
    while (handJ1.size()<5){//on sort de la boucle lorsque l'on a 5 cartes
            //on choisi un index de carte
            int indexCarte;
            indexCarte = rand() % 52;//on choisit al�atoirement une carte

                if (!count(carteDejaPrise.begin(), carteDejaPrise.end(), indexCarte)) {//on v�rifie si la carte n'est pas d�j� prise
                    handJ1.push_back(JeuxCarte[indexCarte]);//on stocke la carte dans la main
                    carteDejaPrise.push_back(indexCarte);//on retient que la cartes est prise
                }
            }

    }else{cout<<"Nombre de joueur limite atteint";}
    for(int j = 0; j<handJ1.size();j++){
            cout<<"la carte n "<<j<<" est : "<<handJ1[j]<<endl;//on regarde une main g�n�nrer
    }
    return handJ1;//on revoie la main
}
