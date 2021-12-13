#include "BattleShipGame.h"

void BattleShipGame::InitializePlayerStates() {

//Clears Any Previous Data Collected

Player *previousPlayer = playerOne;
Enemy *PreviousEnemy = enemy;
BattleshipGrid *PreviousBoard1 = PG;
BattleshipGrid *PreviousBoard2 = EG;

    delete previousPlayer;
    delete PreviousEnemy;
    delete PreviousBoard1;
    delete PreviousBoard2;

    PlayerData.clear();

//Initializes New Players For a New Game

         PG = new BattleshipGrid;
         EG = new BattleshipGrid;
         playerOne = new Player;
         enemy = new Enemy;

//Populates New Game with Data

    enemy->PopulateShips();
    playerOne->PopulateShipsFromFile();
    if(testMode) {
        EG->PopulateGrid(enemy->getShip("Carrier"), enemy->getShip("Battleship"), enemy->getShip("Submarine"),
                        enemy->getShip("Cruiser"), enemy->getShip("Destroyer"));
    }
    PG->PopulateGrid(playerOne->getShip("Carrier"),playerOne->getShip("Battleship"),playerOne->getShip("Submarine"),playerOne->getShip("Cruiser"),playerOne->getShip("Destroyer"));
}

void BattleShipGame::Menu() {
    try {
        int selection;
        cout << "Welcome To BattleShip! " << endl << "(Input Number from Menu Selection)" << endl;
        cout << "1.) PLAY GAME (Difficult)" << endl;
        cout << "2.) PLAY GAME (Easy)"<<endl;
        cout << "3.) TEST MODE (Difficult Version) " << endl;
        cout << "4.) TEST MODE (Easy Version) "<<endl;
        cout << "5.) QUIT GAME " << endl;
        cout << ": ";
        cin >> selection;
        cout<<selection<<endl;
        if(selection != 1 && selection != 2 && selection != 3 && selection != 4 && selection != 5){
            throw int();
        }
        else if(selection == 1){ testMode = false; simpleVersion = false; PlayGame();}
        else if(selection == 2){ testMode = false; simpleVersion = true; PlayGame();}
        else if(selection == 3){ testMode = true; simpleVersion = false; PlayGame();}
        else if(selection == 4){ testMode = true; simpleVersion = true; PlayGame();}
        else if(selection == 5) exit(0);
    }
    catch(int){
        cout<<"Error In Menu Selection, Please Try Again..."<<endl;
        return Menu();
    }
}

void BattleShipGame::PlayGame()  {
    InitializePlayerStates();
    PG->DisplayGrid();
    cout<<endl;
    EG->DisplayGrid();
    do{
        PlayersTurn();
        EnemyTurn();
        PG->DisplayGrid();
        cout<<endl;
        EG->DisplayGrid();

    }
    while(!checkForWinners());
    cout<<endl;
    Menu();

}

bool BattleShipGame::checkForWinners() {

    if(playerOne->getShip("Carrier").Destroyed() && playerOne->getShip("Battleship").Destroyed() && playerOne->getShip("Cruiser").Destroyed() && playerOne->getShip("Submarine").Destroyed() && playerOne->getShip("Destroyer").Destroyed()){
        cout<<"THE ENEMY HAS DESTROYED ALL OF YOUR SHIPS :( :( :(  YOU LOSE!"<<endl;
        return true;
    }
    else if(enemy->getShip("Carrier").Destroyed() && enemy->getShip("Battleship").Destroyed() && enemy->getShip("Cruiser").Destroyed() && enemy->getShip("Submarine").Destroyed() && enemy->getShip("Destroyer").Destroyed()){
        cout<<"YOU HAVE DESTROYED ALL ENEMY SHIPS!!! YOU ARE THE WINNER!!!"<<endl;
        return true;
    }
    else return false;
}


void BattleShipGame::PlayersTurn() {
    Point temp;
    temp = playerOne->MakeGuess();
    for(int i=0;i<PlayerData.size();i++){
        if(temp.GetX() == PlayerData[i].GetX() && temp.GetY() == PlayerData[i].GetY()){
            cout<<"YOU HAVE ALREADY GUESSED THAT LOCATION! Please Guess Again"<<endl;
            return PlayersTurn();
        }
    }
    for(int i = 0; i < enemy->getShip("Carrier").RetrieveTargets().size();i++){
        if(temp.GetX() == enemy->getShip("Carrier").RetrieveTargets()[i].GetX() && temp.GetY() == enemy->getShip("Carrier").RetrieveTargets()[i].GetY()){
            enemy->getShip("Carrier").hitTarget(enemy->getShip("Carrier").RetrieveTargets()[i]);
            cout<<"YOU MADE A HIT!"<<endl;
            if(simpleVersion){
                enemy->getShip("Carrier").checkStatus_2();
                if (enemy->getShip("Carrier").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S CARRIER" << endl;
                    for(int j = 0;j<enemy->getShip("Carrier").RetrieveTargets().size();j++){
                        temp.SetX(enemy->getShip("Carrier").RetrieveTargets()[j].GetX());
                        temp.SetY(enemy->getShip("Carrier").RetrieveTargets()[j].GetY());
                        EG->setData(temp.GetY(), temp.GetX(), 'X');
                        PlayerData.push_back(temp);
                    }
                }
                return;
            }
            else {
                enemy->getShip("Carrier").checkStatus_1();
                if (enemy->getShip("Carrier").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S CARRIER" << endl;
                }
                EG->setData(temp.GetY(), temp.GetX(), 'X');
                PlayerData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < enemy->getShip("Battleship").RetrieveTargets().size();i++){
        if(temp.GetX() == enemy->getShip("Battleship").RetrieveTargets()[i].GetX() && temp.GetY() == enemy->getShip("Battleship").RetrieveTargets()[i].GetY()){
            enemy->getShip("Battleship").hitTarget(enemy->getShip("Battleship").RetrieveTargets()[i]);
            cout<<"YOU MADE A HIT!"<<endl;
            if(simpleVersion){
                enemy->getShip("Battleship").checkStatus_2();
                if (enemy->getShip("Battleship").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Battleship" << endl;
                    for(int j = 0;j<enemy->getShip("Battleship").RetrieveTargets().size();j++){
                        temp.SetX(enemy->getShip("Battleship").RetrieveTargets()[j].GetX());
                        temp.SetY(enemy->getShip("Battleship").RetrieveTargets()[j].GetY());
                        EG->setData(temp.GetY(), temp.GetX(), 'X');
                        PlayerData.push_back(temp);
                    }
                }
                return;
            }
            else {
                enemy->getShip("Battleship").checkStatus_1();
                if (enemy->getShip("Battleship").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Battleship" << endl;
                }
                EG->setData(temp.GetY(), temp.GetX(), 'X');
                PlayerData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < enemy->getShip("Cruiser").RetrieveTargets().size();i++){
        if(temp.GetX() == enemy->getShip("Cruiser").RetrieveTargets()[i].GetX() && temp.GetY() == enemy->getShip("Cruiser").RetrieveTargets()[i].GetY()){
            enemy->getShip("Cruiser").hitTarget(enemy->getShip("Cruiser").RetrieveTargets()[i]);
            cout<<"YOU MADE A HIT!"<<endl;
            if(simpleVersion){
                enemy->getShip("Cruiser").checkStatus_2();
                if (enemy->getShip("Cruiser").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Cruiser" << endl;
                    for(int j = 0;j<enemy->getShip("Cruiser").RetrieveTargets().size();j++){
                        temp.SetX(enemy->getShip("Cruiser").RetrieveTargets()[j].GetX());
                        temp.SetY(enemy->getShip("Cruiser").RetrieveTargets()[j].GetY());
                        EG->setData(temp.GetY(), temp.GetX(), 'X');
                        PlayerData.push_back(temp);
                    }
                }
                return;
            }
            else {
                enemy->getShip("Cruiser").checkStatus_1();
                if (enemy->getShip("Cruiser").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Cruiser" << endl;
                }
                EG->setData(temp.GetY(), temp.GetX(), 'X');
                PlayerData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < enemy->getShip("Submarine").RetrieveTargets().size();i++){
        if(temp.GetX() == enemy->getShip("Submarine").RetrieveTargets()[i].GetX() && temp.GetY() == enemy->getShip("Submarine").RetrieveTargets()[i].GetY()){
            enemy->getShip("Submarine").hitTarget(enemy->getShip("Submarine").RetrieveTargets()[i]);
            cout<<"YOU MADE A HIT!"<<endl;
            if(simpleVersion){
                enemy->getShip("Submarine").checkStatus_2();
                if (enemy->getShip("Submarine").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Cruiser" << endl;
                    for(int j = 0;j<enemy->getShip("Submarine").RetrieveTargets().size();j++){
                        temp.SetX(enemy->getShip("Submarine").RetrieveTargets()[j].GetX());
                        temp.SetY(enemy->getShip("Submarine").RetrieveTargets()[j].GetY());
                        EG->setData(temp.GetY(), temp.GetX(), 'X');
                        PlayerData.push_back(temp);
                    }
                }
                return;
            }
            else {
                enemy->getShip("Submarine").checkStatus_1();
                if (enemy->getShip("Submarine").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Submarine" << endl;
                }
                EG->setData(temp.GetY(), temp.GetX(), 'X');
                PlayerData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < enemy->getShip("Destroyer").RetrieveTargets().size();i++){
        if(temp.GetX() == enemy->getShip("Destroyer").RetrieveTargets()[i].GetX() && temp.GetY() == enemy->getShip("Destroyer").RetrieveTargets()[i].GetY()){
            enemy->getShip("Destroyer").hitTarget(enemy->getShip("Destroyer").RetrieveTargets()[i]);
            cout<<"YOU MADE A HIT!"<<endl;
            if(simpleVersion){
                enemy->getShip("Destroyer").checkStatus_2();
                if (enemy->getShip("Destroyer").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Destroyer" << endl;
                    for(int j = 0;j<enemy->getShip("Destroyer").RetrieveTargets().size();j++){
                        temp.SetX(enemy->getShip("Destroyer").RetrieveTargets()[j].GetX());
                        temp.SetY(enemy->getShip("Destroyer").RetrieveTargets()[j].GetY());
                        EG->setData(temp.GetY(), temp.GetX(), 'X');
                        PlayerData.push_back(temp);
                    }
                }
                return;
            }
            else {
                enemy->getShip("Destroyer").checkStatus_1();
                if (enemy->getShip("Destroyer").Destroyed()) {
                    cout << "YOU SUNK THE ENEMY'S Destroyer" << endl;
                }
                EG->setData(temp.GetY(), temp.GetX(), 'X');
                PlayerData.push_back(temp);
                return;
            }
        }
    }
    cout<<"MISS!"<<endl;
    EG->setData(temp.GetY(),temp.GetX(),'o');
    PlayerData.push_back(temp);
}

void BattleShipGame::EnemyTurn() {
    Point temp;
    temp = enemy->MakeGuessSimple();
    for(int i = 0; i < playerOne->getShip("Carrier").RetrieveTargets().size();i++){
        if(temp.GetX() == playerOne->getShip("Carrier").RetrieveTargets()[i].GetX() && temp.GetY() == playerOne->getShip("Carrier").RetrieveTargets()[i].GetY()){
            playerOne->getShip("Carrier").hitTarget(playerOne->getShip("Carrier").RetrieveTargets()[i]);
            cout<<"THE ENEMY HAS HIT YOUR CARRIER!"<<endl;
            if(simpleVersion){
                playerOne->getShip("Carrier").checkStatus_2();
                if (playerOne->getShip("Carrier").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Carrier" << endl;
                    for(int j = 0;j<playerOne->getShip("Carrier").RetrieveTargets().size();j++){
                        temp.SetX(playerOne->getShip("Carrier").RetrieveTargets()[j].GetX());
                        temp.SetY(playerOne->getShip("Carrier").RetrieveTargets()[j].GetY());
                        PG->setData(temp.GetY(), temp.GetX(), 'X');
                        enemy->BoardData.push_back(temp);
                    }
                }
                return;
            }
            else {
                playerOne->getShip("Carrier").checkStatus_1();
                if (playerOne->getShip("Carrier").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR CARRIER!!!" << endl;
                }
                PG->setData(temp.GetY(), temp.GetX(), 'X');
                enemy->BoardData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < playerOne->getShip("Battleship").RetrieveTargets().size();i++){
        if(temp.GetX() == playerOne->getShip("Battleship").RetrieveTargets()[i].GetX() && temp.GetY() == playerOne->getShip("Battleship").RetrieveTargets()[i].GetY()){
            playerOne->getShip("Battleship").hitTarget(playerOne->getShip("Battleship").RetrieveTargets()[i]);
            cout<<"THE ENEMY HAS HIT YOUR Battleship!"<<endl;
            if(simpleVersion){
                playerOne->getShip("Battleship").checkStatus_2();
                if (playerOne->getShip("Battleship").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Battleship" << endl;
                    for(int j = 0;j<playerOne->getShip("Battleship").RetrieveTargets().size();j++){
                        temp.SetX(playerOne->getShip("Battleship").RetrieveTargets()[j].GetX());
                        temp.SetY(playerOne->getShip("Battleship").RetrieveTargets()[j].GetY());
                        PG->setData(temp.GetY(), temp.GetX(), 'X');
                        enemy->BoardData.push_back(temp);
                    }
                }
                return;
            }
            else {
                playerOne->getShip("Battleship").checkStatus_1();
                if (playerOne->getShip("Battleship").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Battleship!!!" << endl;
                }
                PG->setData(temp.GetY(), temp.GetX(), 'X');
                enemy->BoardData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < playerOne->getShip("Cruiser").RetrieveTargets().size();i++){
        if(temp.GetX() == playerOne->getShip("Cruiser").RetrieveTargets()[i].GetX() && temp.GetY() == playerOne->getShip("Cruiser").RetrieveTargets()[i].GetY()){
            playerOne->getShip("Cruiser").hitTarget(playerOne->getShip("Cruiser").RetrieveTargets()[i]);
            cout<<"THE ENEMY HAS HIT YOUR Cruiser!"<<endl;
            if(simpleVersion){
                playerOne->getShip("Cruiser").checkStatus_2();
                if (playerOne->getShip("Cruiser").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Cruiser" << endl;
                    for(int j = 0;j<playerOne->getShip("Cruiser").RetrieveTargets().size();j++){
                        temp.SetX(playerOne->getShip("Cruiser").RetrieveTargets()[j].GetX());
                        temp.SetY(playerOne->getShip("Cruiser").RetrieveTargets()[j].GetY());
                        PG->setData(temp.GetY(), temp.GetX(), 'X');
                        enemy->BoardData.push_back(temp);
                    }
                }
                return;
            }
            else {
                playerOne->getShip("Cruiser").checkStatus_1();
                if (playerOne->getShip("Cruiser").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Cruiser!!!" << endl;
                }
                PG->setData(temp.GetY(), temp.GetX(), 'X');
                enemy->BoardData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < playerOne->getShip("Submarine").RetrieveTargets().size();i++){
        if(temp.GetX() == playerOne->getShip("Submarine").RetrieveTargets()[i].GetX() && temp.GetY() == playerOne->getShip("Submarine").RetrieveTargets()[i].GetY()){
            playerOne->getShip("Submarine").hitTarget(playerOne->getShip("Submarine").RetrieveTargets()[i]);
            cout<<"THE ENEMY HAS HIT YOUR Submarine!"<<endl;
            if(simpleVersion){
                playerOne->getShip("Submarine").checkStatus_2();
                if (playerOne->getShip("Submarine").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Submarine" << endl;
                    for(int j = 0;j<playerOne->getShip("Submarine").RetrieveTargets().size();j++){
                        temp.SetX(playerOne->getShip("Submarine").RetrieveTargets()[j].GetX());
                        temp.SetY(playerOne->getShip("Submarine").RetrieveTargets()[j].GetY());
                        PG->setData(temp.GetY(), temp.GetX(), 'X');
                        enemy->BoardData.push_back(temp);
                    }
                }
                return;
            }
            else {
                playerOne->getShip("Submarine").checkStatus_1();
                if (playerOne->getShip("Submarine").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Submarine!!!" << endl;
                }
                PG->setData(temp.GetY(), temp.GetX(), 'X');
                enemy->BoardData.push_back(temp);
                return;
            }
        }
    }
    for(int i = 0; i < playerOne->getShip("Destroyer").RetrieveTargets().size();i++){
        if(temp.GetX() == playerOne->getShip("Destroyer").RetrieveTargets()[i].GetX() && temp.GetY() == playerOne->getShip("Destroyer").RetrieveTargets()[i].GetY()){
            playerOne->getShip("Destroyer").hitTarget(playerOne->getShip("Destroyer").RetrieveTargets()[i]);
            cout<<"THE ENEMY HAS HIT YOUR Destroyer!"<<endl;
            if(simpleVersion){
                playerOne->getShip("Destroyer").checkStatus_2();
                if (playerOne->getShip("Destroyer").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Destroyer" << endl;
                    for(int j = 0;j<playerOne->getShip("Destroyer").RetrieveTargets().size();j++){
                        temp.SetX(playerOne->getShip("Destroyer").RetrieveTargets()[j].GetX());
                        temp.SetY(playerOne->getShip("Destroyer").RetrieveTargets()[j].GetY());
                        PG->setData(temp.GetY(), temp.GetX(), 'X');
                        enemy->BoardData.push_back(temp);
                    }
                }
                return;
            }
            else {
                playerOne->getShip("Destroyer").checkStatus_1();
                if (playerOne->getShip("Destroyer").Destroyed()) {
                    cout << "THE ENEMY HAS SUNK YOUR Destroyer!!!" << endl;
                }
                PG->setData(temp.GetY(), temp.GetX(), 'X');
                enemy->BoardData.push_back(temp);
                return;
            }
        }
    }
    cout<<"ENEMEY HAS MISSED!"<<endl;
    PG->setData(temp.GetY(),temp.GetX(),'o');
    enemy->BoardData.push_back(temp);

}

