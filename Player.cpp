#include "Ship.h"
#include "Player.h"
#include "Target.h"
#include "PointClass.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

Point Player::ConvertCoordinate(string s){
    int x,y;
    if(s.size() >= 3){
         x = s[0];
         y = s[1] + s[2] - 87;
         if(y > 10 || y < 0){
             cout << "There was a Problem :" << s << " is Not Within Range" << endl;
             throw ShipPlacementError();
         }
    }
    else {
         x = s[0];
         y = s[1] - 48;
        if(y > 10 || y < 0){
            cout << "There was a Problem :" << s << " is Not Within Range" << endl;
            throw ShipPlacementError();
        }
    }
    if(x>96){
        x-=96;
        if(x>10) {
            cout << "There was a Problem :" << s << " is Not Within Range" << endl;
            throw ShipPlacementError();
        }
        return Point(x,y);
    }
    else {
        x-=64;
        if(x>10) {
            cout << "There was a Problem :" << s << " is Not Within Range" << endl;
            throw ShipPlacementError();
        }
        return Point(x,y);
    }
    //cout<<x-64; subtract 64 from ascii to reach single digits Capital Letters
    //cout<<x-96; subtract 96 from acsii to reach single digits Lower Case Letters

}

void Player::PopulateShipsFromFile() {
    ifstream fin;
    fin.open("in.csv", ios::in);
    string ID;
    string row;
    bool condition = false;
    Point temp;
    bool vertical;
    if(fin.fail()){
        cerr<< "Error In opening File Please make sure file is in Directory/Folder" << endl;
        cerr<< "File Name Should Be Saved as \"in.txt\" "<<endl;
        exit(1);
    }

    while (std::getline(fin, row)) {
        std::istringstream iline(row);
        getline(iline, ID, ',');
        try {
            if (ID == "Carrier" || ID == "carrier") {
                while (iline.good()) {
                    getline(iline, ID, ',');
                    if (!condition) {
                        temp = ConvertCoordinate(ID);
                        //cout<<temp.GetX()<<","<<temp.GetY()<<endl;
                        condition = true;
                    } else {
                        if (ID[0] == 'H' || ID[0] == 'h') {
                            vertical = false;
                        } else if (ID[0] == 'V' || ID[0] == 'v') {
                            vertical = true;
                        } else{throw AlignmentError();}
                    }
                }
                Carrier.Build("Carrier", temp, vertical);
                condition = false;
            } else if (ID == "Battleship" || ID == "battleship") {
                while (iline.good()) {
                    getline(iline, ID, ',');
                    if (!condition) {
                        temp = ConvertCoordinate(ID);
                        // cout<<temp.GetX()<<","<<temp.GetY()<<endl;
                        condition = true;
                    } else {
                        if (ID[0] == 'H' || ID[0] == 'h') {
                            vertical = false;
                        } else if (ID[0] == 'V' || ID[0] == 'v') {
                            vertical = true;
                        }else{ throw AlignmentError();}
                    }
                }
                Battleship.Build("Battleship", temp, vertical);
                condition = false;
            } else if (ID == "Submarine" || ID == "submarine") {
                while (iline.good()) {
                    getline(iline, ID, ',');
                    if (!condition) {
                        temp = ConvertCoordinate(ID);
                        //cout << temp.GetX() << "," << temp.GetY() << endl;
                        condition = true;
                    } else {
                        if (ID[0] == 'H' || ID[0] == 'h') {
                            vertical = false;
                        } else if (ID[0] == 'V' || ID[0] == 'v') {
                            vertical = true;
                        }else{ throw AlignmentError();}
                    }
                }
                Submarine.Build("Submarine", temp, vertical);
                condition = false;
            } else if (ID == "Cruiser" || ID == "cruiser") {
                while (iline.good()) {
                    getline(iline, ID, ',');
                    if (!condition) {
                        temp = ConvertCoordinate(ID);
                        //cout<<temp.GetX()<<","<<temp.GetY()<<endl;
                        condition = true;
                    } else {
                        if (ID[0] == 'H' || ID[0] == 'h') {
                            vertical = false;
                        } else if (ID[0] == 'V' || ID[0] == 'v') {
                            vertical = true;
                        }else{ throw AlignmentError();}
                    }
                }
                Cruiser.Build("Cruiser", temp, vertical);
                condition = false;
            } else if (ID == "Destroyer" || ID == "destroyer") {
                while (iline.good()) {
                    getline(iline, ID, ',');
                    if (!condition) {
                        temp = ConvertCoordinate(ID);
                        //cout<<temp.GetX()<<","<<temp.GetY()<<endl;
                        condition = true;
                    } else {
                        if (ID[0] == 'H' || ID[0] == 'h') {
                            vertical = false;
                        } else if (ID[0] == 'V' || ID[0] == 'v') {
                            vertical = true;
                        }else{ throw AlignmentError();}
                    }
                }
                Destroyer.Build("Destroyer", temp, vertical);
                condition = false;
            }
            else{
                throw ShipNameError();
            }
        }
        catch(ShipNameError){
            cout<<"ERROR IN FINDING APPROPRIATE SHIP NAMES!"<<endl;
            cout<<"Check File and Ensure all Names are CORRECT!"<<endl;
            exit(0);
        }
        catch(ShipPlacementError){
            cout<<"Error in Ship Placement! One or More Ships are not Within Grid! (please correct and try again...)"<<endl;
            exit(0);
        }
        catch(AlignmentError){
            cout<<"Error in Determining Alignment in One or More Ships! (please check alignment is either 'H' or 'V'..."<<endl;
            exit(0);
        }
        }

fin.close();

}

Ship& Player::getShip(string ShipName) {
    if(ShipName == "Carrier"){
        return Carrier;
    }
    else if(ShipName == "Battleship"){
        return Battleship;
    }
    else if(ShipName == "Submarine"){
        return Submarine;
    }
    else if(ShipName == "Cruiser"){
        return Cruiser;
    }
    else if(ShipName == "Destroyer"){
        return Destroyer;
    }

}

Point Player::MakeGuess() {
    try {
            string playerGuess;
            Point temp;
            cout<<endl;
            cout<<"Input Coordinate Guess: ";
            cout<<endl;
            cin>>playerGuess;
            temp = ConvertCoordinate(playerGuess);
            cout<<"Player Guess "<<temp.GetX()<<","<<temp.GetY()<<endl;
            return temp;
    }
    catch(ShipPlacementError){
        cout<<"There Was an Error in Your Guess, Please Try Again"<<endl;

            return MakeGuess();

        }

}







