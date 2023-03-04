#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <chrono>
#include <random>
#include <string> 
using namespace std;
//---Determines what party members are Alive and if all family members will survive a attack
bool momAlive = true;
bool dadAlive = true;
bool sisterAlive = true;
bool brotherAlive = true;
bool familySurvive = true;
bool wheelBreak =  true;
//---Determines what party members have a disease
bool diseaseDad = false;
bool diseaseMom = false;
bool diseaseBrother = false;
bool diseaseSister = false;
//---Stores the disease of each family member
string dadDiseaseStore;
string momDiseaseStore;
string brotherDiseaseStore;
string sisterDiseaseStore;
//---Determines what game state the game will be
int gamestate = 0;
//---Stores the value if the player will continue or repair a broken wheel
int choiceWheel = 0;
//---Stores the Chance of a Animal Attack
int animalChanceStorage;
//---Stores the Chance of a Ambush while traveling forward
int travelForwardChanceStorage;
//---Start speed of the wagon
int startSpeed = 25;
//---Tmp
int p1;
//---Runs the Timer for all events
long int timer = 0;
//---is a returning value for TrailSwitch to determine if the switch was defaulted
bool cont = true;
//---Total Distance To be traveled
int startDistance = 2000;
//---Starting Day for trail
int day = 1;
//---Starting Currency of the Game
int currencyStart = 1000;
//---Stores Event Choices
int eventChoice;
//---stores the choice from menu (1,2,3,4)
int menuChoice;
//---Stores Party Members Names
string pmChoiceDad,pmChoiceMom,pmChoiceBrother,pmChoiceSister;
//---Determines if game moves onto second part
char continueTrail;
//---Set Start Amount of Party Members
int partyMembersStart = 4;
//---Start Set Amount of All Items
int spareTire,food,bullets,gun,oxen = 0;
//---Function that displays Menu
void menuStart(); //---Line 93
//---Runs a timer to keep text displayed then runs the random event Generator
int universalTimer(); //---Line 303
//---Controls the random set of events that can occur while camping out
void randomEventControllerCampOut(); //---Line 197
//---Determines what is lost from a attack
void consequenceCampOut(); //---Line 239
//---Stores what death phrase is used when someone is killed by the bear
enum deathQuoteBear {D,D2,D3,D4,D5,D6,D7,D8};
//---Function that DETERMINES what death phrase is chosen from the storage
string getDeathBear(deathQuoteBear);
//---Controls the random set of events that can occur while traveling forward
void randomEventControllerTravelForward();
//---Determines what is lost from a attack while traveling forward
void consequenceTravelForward();
//---Stores what death phrase is used when someone is killed while travling forward
enum deathQuoteCampOut {C,C2,C3,C4,C5,C6,C7,C8};
//---Function that DETERMINES what death phrase will be used from the storage
string getDeathQuoteCampOut(deathQuoteCampOut);
//---Stores possible diseases a player can catch
enum diseaseQuote {A,A2,A3,A4,A5,A6,A7};
//---Function that grabs which disease the player will catch;
string getDiseaseQuote(diseaseQuote);
//---Stores the possible items lost from a thief attack
enum thiefRansackConsequence {T,T1,T2,T3,T4,T5,T6,T7,T8,T9,T10};
//---Function that grabs what item will be lost
string thiefRansack(thiefRansackConsequence);
//---Stores the possible fear quotes from something approaching
enum travelForwardFearApproachingQuote {X,X1,X2,X3,X4,X5,X6,X7,X8};
//---Checks if someone has a disease
void diseaseCheck();
//---Function that calls the possible fear quotes from something approaching and uses them
string travelForwardFearApproaching(travelForwardFearApproachingQuote);
//---Function that displays Party Member names Menu
void partyMembersName(); //---Line 149
//---Controls Trails Options (ex Campout vs Push forward)
void trailEvents(); //---Line 163
//---Function that allows a spare part to be used
void functionChoiceWheel();
//---Opens introduction text with rules on how to to play the game
void introduction();//---Line 292
//---Runs a Random Number Generator to determine what events will occur
int trailSwitch();//---Line 171
//---Control the events from what is chosen on the Menu
int menuSwitch(); //---Line 101
int main(){
        introduction();
        partyMembersName();
        do {
                system("cls");
                menuStart();
                while(!(cin>>menuChoice)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menuStart();
                }
                menuSwitch();
        } while(currencyStart>0);
        //---Second Part of Game
        cout<<"Out of Cash"<<endl;
        cout<<"Do you want to continue on the trail? (y/n) "<<endl;
        cin>>continueTrail;
        if(continueTrail=='y' || continueTrail=='Y') {
                system("cls");
                cout<<"Creating Trail..."<<endl;
                universalTimer();
                //---Checks input for trailevents and makes sure its a valid answer
                do {
                        do {
                                cont = true;
                                trailEvents();
                                while(!(cin>>eventChoice)) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        system("cls");
                                        trailEvents();
                                }
                        } while(cont==false);
                        trailSwitch();
                } while(startDistance>0 && partyMembersStart>0);
                if(partyMembersStart==0) {
                        cout<<"All Party Members Dead You Lost ! "<<endl;
                        return 0;
                }
                else if(startDistance<=0) {
                        cout<<"You Made it! You Won! "<<endl;
                }
        }
}
void menuStart(){
        cout<<"Total Party Members "<<partyMembersStart<<endl;
        cout<<"Chose one of the Following Options "<<"$"<<currencyStart<<endl;
        cout<<"1. Spare Tire $450 "<<" Amount: "<<spareTire<<"x"<<endl;
        cout<<"2. Food $100       "<<" Amount: "<<food<<"x"<<endl;
        cout<<"3. Bullets $50     "<<" Amount: "<<bullets<<"x"<<endl;
        cout<<"4. Gun $500        "<<" Amount: "<<gun<<"x"<<endl;
        cout<<"5. Oxen $100       "<<" Amount: "<<oxen<<"x"<<endl;
}
int menuSwitch(){
        switch(menuChoice) {
        //---Spare Tire
        case 1:
                if(currencyStart>=450) {
                        currencyStart=currencyStart-450;
                        spareTire++;
                }
                else{
                        cout<<"Not Enough Money"<<endl;
                }
                break;
        case 2:
                //---Food
                if(currencyStart>=100) {
                        currencyStart=currencyStart-100;
                        food++;
                }
                else{
                        cout<<"Not Enough Money"<<endl;
                }
                break;
        //---Bullets
        case 3:
                if(currencyStart>=50) {
                        currencyStart=currencyStart-50;
                        bullets++;
                }
                else{
                        cout<<"Not Enough Money"<<endl;
                }
                break;
        //---Gun
        case 4:
                if(currencyStart>=500) {
                        currencyStart=currencyStart-500;
                        gun++;
                }
                else{
                        cout<<"Not Enough Money"<<endl;
                }
                break;
        case 5:
                if(currencyStart>=100) {
                        currencyStart=currencyStart-100;
                        oxen++;
                }
                break;
        default:
                system("cls");
                cout<<"Failure 1 (Bad option)"<<endl;
        }
        return currencyStart;
}
void partyMembersName(){
        cout<<"Chose Party Member Name (Dad)"<<endl;
        cin>>pmChoiceDad;
        system("cls");
        cout<<"Chose Party Member Name (Mother)"<<endl;
        cin>>pmChoiceMom;
        system("cls");
        cout<<"Chose Party Member Name (Brother)"<<endl;
        cin>>pmChoiceBrother;
        system("cls");
        cout<<"Chose Party Member Name (Sister)"<<endl;
        cin>>pmChoiceSister;
        system("cls");
}
void trailEvents(){
        cout<<"Day "<<day<<" Party Members Alive: "<<partyMembersStart<<endl;
        cout<<"Distance to Destination: "<<startDistance <<" Miles"<<endl;
        cout<<"Choose a option"<<endl;
        cout<<"1. Camp out "<<endl;
        cout<<"2. Travel Forward "<<endl;
        cout<<"3. Hunt and Gather Food"<<endl;
}
int trailSwitch(){
        startSpeed=25;
        int distanceTraveled = 25;
        int tmpOxen=oxen;
        switch(eventChoice) {
        case 1:
                system ("cls");
                cout<<"Camping Out... "<<endl;
                universalTimer();
                cont = true;
                randomEventControllerCampOut();
                consequenceCampOut();
                diseaseCheck();
                day++;
                break;
        case 2:
                system("cls");
                cout<<"The Wagon is Traveling Forward..."<<endl;
                universalTimer();
                cont = true;
                randomEventControllerTravelForward();
                consequenceTravelForward();
                diseaseCheck();
                while(tmpOxen>=1) {
                        distanceTraveled=distanceTraveled+25;
                        startSpeed=startSpeed+25;
                        tmpOxen--;
                }
                startDistance=startDistance-startSpeed;
                cout<<"Distance Traveled: "<<distanceTraveled<<" miles"<<endl;
                day++;
                break;
        case 3:
                system("cls");
                cout<<"Hunting..."<<endl;
                universalTimer();
                cont = true;
                day++;
                break;
        default:
                cont=false;
                system("cls");
                break;
        }
        return true;
}
void randomEventControllerCampOut(){
        //---Random Number Generator that Determines chances of defeating a Attack 50% chance with gun
        bool ChanceWin;
        int animalChance=50;
        //---Stores Food in a Tmp so it can run in a chance generator
        int tmpFood = food;
        srand((unsigned)time(0));
        p1=rand() % 100;
        animalChanceStorage=animalChance;
        //---Each pound of Food Gains a 20% chance of a Animal Attack
        while(tmpFood>0) {
                animalChance=animalChance*1.2;
                tmpFood--;
        }
        //---If the random number is less than the chance of a animal attack then bear attacks
        if(p1<animalChanceStorage) {
                system("cls");
                cout<<"You were attacked by a bear and ";
                if(gun>0 && bullets>0) {
                        //---50% chance to win if a gun is present with ammo
                        srand((unsigned)time(0));
                        ChanceWin=rand()%2;
                        if(ChanceWin==1) {
                                cout<<" succesfully defended the attack! "<<endl;
                                bullets--;
                                cout<<bullets<<endl;
                        }
                        else{
                                cout<<" missed your shot! "<<endl;
                                bullets--;
                                gamestate = 5;
                        }
                }
                else{
                        cout<<"lost the attack! "<<endl;
                        gamestate = 5;
                }
        }
        if(p1>=animalChanceStorage) {
                cout<<animalChanceStorage<<endl;
                cout<<p1<<endl;
                cout<<"You Successfully Camped Out! "<<endl;
        }
}
void consequenceCampOut(){
        if(gamestate==5) {
                //---Randomly Determines what member dies and resets gamestate
                srand((unsigned)time(0));
                unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                default_random_engine generator(seed);
                uniform_int_distribution<int> distributionInteger(0, 4); // Set the numbers for int.
                for (int i = 0; i < 2; ++i)
                {
                }
                // int deathDetermine = rand()%5;
                int p2 = rand()%8;
                if(distributionInteger(generator)==0 && dadAlive==true) {
                        cout<<pmChoiceDad<<getDeathBear(deathQuoteBear(p2))<<endl;
                        universalTimer();
                        partyMembersStart--;
                        dadAlive=false;
                }
                else if(distributionInteger(generator)==1 && momAlive==true) {
                        cout<<pmChoiceMom<<getDeathBear(deathQuoteBear(p2))<<endl;
                        universalTimer();
                        partyMembersStart--;
                        momAlive=false;
                }
                else if(distributionInteger(generator)==2 && brotherAlive==true) {
                        cout<<pmChoiceBrother<<getDeathBear(deathQuoteBear(p2))<<endl;
                        universalTimer();
                        partyMembersStart--;
                        brotherAlive=false;
                }
                else if(distributionInteger(generator)==3 && sisterAlive==true) {
                        cout<<pmChoiceSister<<getDeathBear(deathQuoteBear(p2))<<endl;
                        universalTimer();
                        partyMembersStart--;
                        sisterAlive=false;
                }
                //---Family lives but food a days worth of food is lost
                else if(distributionInteger(generator)==4 && familySurvive==true) {
                        cout<<"The family survives but looses a days worth of food to the bear! "<<endl;
                        universalTimer();
                        familySurvive=false;
                        food--;
                }
                else{
                        distributionInteger(generator);
                        consequenceCampOut();
                }
        }
        //---Randomly Determines what member dies and resets gamestate
        gamestate = 0;
}
string getDeathBear(deathQuoteBear(p2)){
        switch(p2) {
        case D:
                return " was brutally clawed to death ";
        case D2:
                return " was mercilessly stomped to death ";
        case D3:
                return " was dragged away into the night ";
        case D4:
                return " was butchered while defending the family from the attack";
        case D5:
                return " was ferociously pounded to death ";
        case D6:
                return " was visciously clawed to death ";
        case D7:
                return " was ruthlessly murdered in the mist of sleep ";
        case D8:
                return " was savagely clawed to death ";
        default:
                cout<<"Error switch p2 did not generate a number "<<endl;

        }
        return 0;
}
void introduction(){
        cout<<"*****************************************************************"<<endl;
        cout<<"* Welcome to cross country adventure!                           *"<<endl;
        cout<<"* The objective of the game is to make it                       *"<<endl;
        cout<<"* towards your desitination. You start off with four            *"<<endl;
        cout<<"* party members and the goal is to keep them all alive          *"<<endl;
        cout<<"* while you travel towards your destination You will be         *"<<endl;
        cout<<"* faced with enemies and other unpredicted occurances so        *"<<endl;
        cout<<"* be prepared for the worst.                                    *"<<endl;
        cout<<"*****************************************************************"<<endl;
}
int universalTimer(){
        long int i;
        if(timer<=15) {
                for(i=0; i<=100000000; i++) {
                        while(i==99999999) {
                                timer++;
                                i=0;
                        }
                        if(timer==15) {
                                break;
                        }
                }
        }
        timer = 0;
        return timer;
}
void randomEventControllerTravelForward(){
        int travelForwardChance=75;
        bool chanceWin;
        srand((unsigned)time(0));
        p1=rand() % 100;
        if(p1<=travelForwardChance) {
                if(gun>0 && bullets>0) {
                        //---50% chance to win if a gun is present with ammo
                        srand((unsigned)time(0));
                        chanceWin=rand()%2;
                        if(chanceWin==1) {
                                cout<<" but succesfully defended from the attack! "<<endl;
                                bullets--;
                        }
                        else{
                                cout<<"but was defeated while attempting to defend! "<<endl;
                                gamestate = 4;
                        }
                }
                else{
                        gamestate = 4;
                }
        }else{
                cout<<"Successfully traveled forward! "<<endl;
        }
}
void consequenceTravelForward(){
        if(gamestate==4) {
                srand((unsigned)time(0));
                //---Determines if someone is killed , something is stolen , exc
                unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                default_random_engine generator(seed);
                uniform_int_distribution<int> distributionInteger(0, 9);         // Set the numbers for int.
                for (int i = 0; i < 5; ++i)
                {
                }
                cout<<distributionInteger(generator)<<endl;
                // ---Determines the 8 possible death quotes
                int p3 = rand()%8;
                //---Determines the 7 possible diseases
                int p4 = rand()%7;
                //---Determines the 10 possible thief outcomes
                int p5 = rand()%10;
                //---Determines the 8 possible quotes for bandits approaching
                int p6 = rand()%8;
                if(distributionInteger(generator)==0 && dadAlive==true) {
                        cout<<"The Wagon has been stopped!.. "<<endl;
                        universalTimer();
                        cout<<"You see a group approaching rapidly..."<<travelForwardFearApproaching(travelForwardFearApproachingQuote(p6))<<endl;
                        universalTimer();
                        universalTimer();
                        cout<<pmChoiceDad<<getDeathQuoteCampOut(deathQuoteCampOut(p3))<< endl;
                        universalTimer();
                        dadAlive=false;
                        partyMembersStart--;
                }
                else if(distributionInteger(generator)==1 && momAlive==true ) {
                        cout<<"The Wagon has been stopped!.. "<<endl;
                        universalTimer();
                        cout<<"You see something approaching rapidly..."<<travelForwardFearApproaching(travelForwardFearApproachingQuote(p6))<<endl;
                        universalTimer();
                        universalTimer();
                        cout<<pmChoiceMom<<getDeathQuoteCampOut(deathQuoteCampOut(p3))<<endl;
                        universalTimer();
                        momAlive=false;
                        partyMembersStart--;
                }
                else if(distributionInteger(generator)==2 && sisterAlive==true ) {
                        cout<<"The Wagon has been stopped!.. "<<endl;
                        universalTimer();
                        cout<<"You see something approaching rapidly..."<<travelForwardFearApproaching(travelForwardFearApproachingQuote(p6))<<endl;
                        universalTimer();
                        universalTimer();
                        cout<<pmChoiceSister<<getDeathQuoteCampOut(deathQuoteCampOut(p3))<<endl;
                        universalTimer();
                        sisterAlive=false;
                        partyMembersStart--;
                }
                else if(distributionInteger(generator)==3 && brotherAlive==true ) {
                        cout<<"The Wagon has been stopped!.. "<<endl;
                        universalTimer();
                        cout<<"You something approaching rapidly..."<<travelForwardFearApproaching(travelForwardFearApproachingQuote(p6))<<endl;
                        universalTimer();
                        universalTimer();
                        cout<<pmChoiceBrother<<getDeathQuoteCampOut(deathQuoteCampOut(p3))<<endl;
                        universalTimer();
                        brotherAlive=false;
                        partyMembersStart--;
                }
                else if(distributionInteger(generator)==4) {
                        cout<<"you hear rustling in the wagon... "<<endl;
                        universalTimer();
                        cout<<"A thief ransacked the wagon! " <<endl;
                        cout<<p5<<endl;
                        cout<<thiefRansack(thiefRansackConsequence(p5))<<endl;
                }
                else if(distributionInteger(generator)==5) {
                        cout<<"The clouds begin to cover the sky and darkness takes over "<<endl;
                        universalTimer();
                        cout<< "A severe thunderstorm rains the roads out!  " <<endl;
                        cout<<" You lose a day! "<<endl;
                        //---Bug of distance  traveled still counting
                        day++;
                }
                else if(distributionInteger(generator)==6 && wheelBreak==true) {
                        cout<<"A cracking sound startles everyone... "<<endl;
                        universalTimer();
                        cout<<"A wheel broke! "  <<endl;
                        wheelBreak = false;
                        functionChoiceWheel();
                }
                else if(distributionInteger(generator)==7) {
                        cout<<"running disease "<<endl;
                        srand((unsigned)time(0));
                        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
                        default_random_engine generator(seed);
                        uniform_int_distribution<int> distributionInteger(0, 4);                                     // Set the numbers for int.
                        for (int i = 0; i < 2; ++i)
                        {
                        }
                        if(distributionInteger(generator)==0 && dadAlive==true) {
                                cout<<pmChoiceDad<<getDiseaseQuote(diseaseQuote(p4))<<endl;
                                dadDiseaseStore = getDiseaseQuote(diseaseQuote(p4));
                                cout<<dadDiseaseStore<<endl;
                        }
                        else if(distributionInteger(generator)==1 && momAlive==true) {
                                cout<<pmChoiceMom<<getDiseaseQuote(diseaseQuote(p4))<<endl;
                                momDiseaseStore = getDiseaseQuote(diseaseQuote(p4));
                                cout<<momDiseaseStore<<endl;
                        }
                        else if(distributionInteger(generator)==2 && brotherAlive==true) {
                                cout<<brotherAlive<<getDiseaseQuote(diseaseQuote(p4))<<endl;
                                brotherDiseaseStore = getDiseaseQuote(diseaseQuote(p4));
                                cout<<brotherDiseaseStore<<endl;
                        }
                        else if(distributionInteger(generator)==3 && sisterAlive==true) {
                                cout<<pmChoiceSister<<getDiseaseQuote(diseaseQuote(p4))<<endl;
                                sisterDiseaseStore = getDiseaseQuote(diseaseQuote(p4));
                                cout<<sisterDiseaseStore<<endl;
                        }
                }
                else if(distributionInteger(generator)==8) {
                        cout<<"You see something up ahead... "<<endl;
                        universalTimer();
                        cout<< "a Fallen tree blocks your way! " <<endl;
                        cout<<" You lose a day! "<<endl;
                        day++;
                }
                else if(distributionInteger(generator)==9) {
                        cout<<"You see something up ahead... "<<endl;
                        universalTimer();
                        cout<<"a river blocks the path! "  <<endl;
                        //---FunctionChoiceRiver();
                }
                //---If a consequence generated goes to a dead member it reruns function
                else {
                        distributionInteger(generator);
                        consequenceTravelForward();
                }
        }
        gamestate = 0;
}
string getDeathQuoteCampOut(deathQuoteCampOut(p3)){
        switch(p3) {
        case C:
                return " was brutally murdered by the appache tribe!";
        case C2:
                return " was kidnapped and executed by bandits!  ";
        case C3:
                return " was ruthlessly cut to shreds by wild dogs! ";
        case C4:
                return " was visciously beaten to death by a raging animal! ";
        case C5:
                return " was brutally stabbed while defending the Wagon from thiefs ";
        case C6:
                return " was brutally stomped to death by a rogue Indian! ";
        case C7:
                return " was savagely cut to shreds by a barbaric tribe! ";
        case C8:
                return " was barbarically executed in front of the family by a group of bandits ";
        default:
                return "Error_msg no number generated campout";
        }
        return 0;
}
string getDiseaseQuote(diseaseQuote(p4)){
        switch(p4) {
        case A:
                return " has cholera ";
        case A2:
                return " has exhaustion ";
        case A3:
                return " has dysentery ";
        case A4:
                return " has typhiod ";
        case A5:
                return " has measles ";
        case A6:
                return " has diphtheria ";
        case A7:
                return " has anthrax ";
        }
        return 0;
}
//---Potential Overhaul
string thiefRansack(thiefRansackConsequence(p5)){
        switch(p5) {
        case T:
                if(food>=3) {
                        food=food-3;
                        return "You lost 3 days of food! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T1:
                if(spareTire>=1) {
                        spareTire--;
                        return "You lost a spare tire! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T2:
                if(bullets>=4) {
                        bullets=bullets-4;
                        return "You lost 4 packs of bullets! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T3:
                if(oxen>=1) {
                        oxen--;
                        return "You lost a oxen! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T4:
                if(gun>=1) {
                        gun--;
                        return "You lost a gun! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T5:
                if(food>=2) {
                        food=food-2;
                        return "You lost 2 days of food! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T6:
                if(food>=1) {
                        food--;
                        return "You lost a days worth of food! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T7:
                if(bullets>=1) {
                        bullets--;
                        return "You lost a pack of bullets! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T8:
                if(bullets>=2) {
                        bullets=bullets-2;
                        return "You lost 2 packs of bullets! ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T9:
                if(bullets>=3) {
                        bullets=bullets-3;
                        return "You lost 3 packs of bullets!  ";
                }
                else{
                        return " The thief came away empty handed! ";
                }
                break;
        case T10:
                return "but got nothing! ";
        default:
                return "but got n0thing! ";
        }
        return 0;
}
string travelForwardFearApproaching(travelForwardFearApproachingQuote(p6)){
        switch (p6) {
        case X:
                return "you begin to shake in fear... ";
        case X1:
                return "you feel the burning surge of adrenaline begin to course withen...";
        case X2:
                return "you sense danger is approaching... ";
        case X3:
                return "you begin to shake violently as you sense the end is near... ";
        case X4:
                return "your fear locks your ability to move... ";
        case X5:
                return "you feel scared and vulnerable... ";
        case X6:
                return "you suddenly feel cold and afraid... ";
        case X7:
                return "you begin to tremble in fear... ";
        case X8:
                return "the light is drained slowly out of you... ";
        default:
                cout<<"default triggered "<<endl;
        }
        return 0;
}
void functionChoiceWheel(){
        cout<<"What will you like to do? "<<endl;
        cout<<"1. Repair Wheel "<<endl;
        cout<<"2. Travel with broken wheel (50% Slower)"<<endl;
        cin>>choiceWheel;
        switch(choiceWheel) {
        case 1:
                if(spareTire>=1) {
                        system("cls");
                        cout<<"Repairing wheel..."<<endl;
                        universalTimer();
                        cout<<"Successfully repaired wheel! "<<endl;
                        spareTire--;
                }else if (spareTire==0) {
                        cout<<"You do not have a spare wheel! "<<endl;
                        functionChoiceWheel();
                }
                break;
        case 2:
                startSpeed=startSpeed/2;
                cout<<"move speed: "<<startSpeed<<endl;
                break;
        }

}
void diseaseCheck(){
        int a= 0;
        int b= 0;
        int c =0;
        int d =0;
        srand((unsigned)time(0));
        p1=rand() % 100;
        if(diseaseDad==true && dadAlive==true) {

                if(a>=p1) {
                        cout<<pmChoiceDad<<"died from "<<dadDiseaseStore<<endl;
                }
                a=a+20;
        }
        if(diseaseMom==true && momAlive==true) {

                if(a>=p1) {
                        cout<<pmChoiceMom<<"died from "<<momDiseaseStore<<endl;
                }
                b=b+20;
        }
        if(diseaseBrother==true && brotherAlive==true) {

                if(a>=p1) {
                        cout<<pmChoiceBrother<<"died from "<<brotherDiseaseStore<<endl;
                }
                c=c+20;
        }
        if(diseaseMom==true && momAlive==true) {

                if(a>=p1) {
                        cout<<pmChoiceMom<<"died from "<<momDiseaseStore<<endl;
                }
                d=d+20;
        }
        else {
                cout<<"else triggered"<<endl;
        }
}
/*---WORK LOG
   1. Completed! Add a Successful Night and Day Counter
   2. Completed! Add a distance calculator that knows if you traveled forward or camped out
   3. Completed! Cleaning up code and adding what line each function is on
   4. Add Chance System to rest of Game Options
   5. Set up scenario for why each option is viable
   6. Setup random chance events such as wagon break and storms
   7. Add food deducter per day from family
   8. Add disease and Starvation
   9. Completed! Add Gun Requires bullets
   10.Completed! Add System for Determining what party members are alive
   11.Completed! Add Oxen Feature
   12.OverHaul robbing system
 */
