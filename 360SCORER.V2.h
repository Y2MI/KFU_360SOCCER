/*
 * Group 15:
 * Abdullah Alahmad
 * Khalid Alyami
 * Adam Almomatan
 */
#ifndef INC_360SOCCER_360SOCCER_FUNCTIONS_H
#define INC_360SOCCER_360SOCCER_FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <fstream>
#include <unistd.h>
using namespace std;

//All functions needed to generate 360Soccer program//
/*****************FUNCTIONS DECLARATION****************|*/
void rate();
void PL_CL(); // SECOND PAGE
void Club_Table(); // Third PAGE .1
void SearchByName(); // Clubs Search
void SCORER_ASSIST(); // Third PAGE .2
void HIS_CUR_A(); // Fourth PAGE .1
void HIS_CUR_S(); // Fourth PAGE .1
void C_SCORERS(); // Fifth PAGE .1
void HIS_SCORERS(); // Fifth PAGE .2
void HIS_SEARCH(); // Historical scorer search
void ReturnF2(string); // Historical scorer Return Function
void CS_SEARCH(); // Current Scorer search
void ReturnF1(string); // Current scorer Return Function
void HIS_ASSIST(); // Sixth PAGE .1 ****************************
void HIS_ASSIST_SEARCH(); // historical assist search          *
void ReturnF3(string); // Historical assist Return Function    *
void CUR_ASSIST(); // Sixth PAGE .2 ****************************
void CUR_ASSIST_SEARCH();
void ReturnF4(string); // **************************************
void Alittihad();
void CLUBRF1(string);
void Al_Hilal();
void CLUBRF2(string);
void Al_Nassr();
void CLUBRF3(string);
void Al_Shabab();
void CLUBRF4(string);
void Damak();
void CLUBRF5(string);
void Abha();
void CLUBRF6(string);
void Al_Fateh();
void CLUBRF7(string);
void Al_Fayha();
void CLUBRF8(string);
void Al_Raed();
void CLUBRF9(string);
void Al_Ahli();
void CLUBRF10(string);
void Al_Faisaly();
void CLUBRF11(string);
void Al_Tai();
void CLUBRF12(string);
void Al_Taawoun();
void CLUBRF13(string);
void Al_Batin();
void CLUBRF14(string);
void Al_Ettifaq();
void CLUBRF15(string);
void Al_Hazem();
void CLUBRF16(string);
void suggestions(string*);
/********************STRUCT********************|*/
struct club {
    string place;
    string squad;
    string Tournaments;
    string stadium;
};
/*****************CLASSES DECLARATION*****************|*/
class HS {
public:
    string SC_NAME;
    int SC_NUMBER;

    HS(string SC_NA, int SC_NU)
    {
        SC_NAME = SC_NA;
        SC_NUMBER = SC_NU;
    }
}; // Public class to organize historical scorers choice table
/********************COLOR FUNCTION********************|*/
void AVT() //font color function
{
    HANDLE handleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD consoleMode;
    GetConsoleMode(handleOut, &consoleMode);
    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    consoleMode |= DISABLE_NEWLINE_AUTO_RETURN;
    SetConsoleMode(handleOut, consoleMode);
}
enum COLORS { //I add color for Program's design
    NC=-1,
    BLACK,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};
const char *color(int font, int back =-1 , int style = -1){ // This is belong COLORS
    static char code[20];
    if(font >= 0)
        font+=30;
    else
        font =0;
    if (back>=0)
        back+=40;
    else
        back =0;
    if(back > 0 && style > 0){
        sprintf(code, "\033[%d;%d;%dm", font, back, style);
    } else if(back > 0){
        sprintf(code, "\033[%d;%dm", font, back);
    } else {
        sprintf(code, "\033[%dm", font);
    }
    return code;
}
/*****************OPERATION FUNCTIONS*****************|*/

/*****************CLUBS FUNCTIONS START*****************|*/
void CLUBRF1(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Alittihad(); // to choose another player
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al ittihad!

void Alittihad(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club Ittihad;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al- ittihad/itti.txt"
            );

    string DC = "AL-ITTIHAD was founded on 1927 (94 years ago).\n"
                "AL-ITTIHAD's Home town is JEDDAH.\n"
                "Chairman: Anmar AL- Haili.\n"
                "The club's nickname: AL NUMUR (The TIGERS)\n"
                "Club manager: Cosmin Contra\n"
                "His nationality: Romanian.\n";
    Ittihad.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    Ittihad.stadium = "King Abdullah Sports City in Jeddah,\nthe main stadium is (Al-Jawhara),\nit contains stands that can accommodate more than 62,000 spectators and divided seats in a professional manner\n";

    Ittihad.Tournaments = "\n            8     Pro League\n            9     King Cup\n            8     Crown Prince Cup \nDomestic    3     Saudi Federation Cup\n            1     Saudi Association Cup\n            1     Prince Majed Cup\n"
                          " ......................................"
                          "\n            2     AFC Champions League\nContinent      \n            1     Asian Cup Winners Cup\n"
                          " ......................................"
                          "\n            1     Arab Champions League\nRegional    1     GCC Champions League\n            2     Saudi-Egyptian Super Cup\n";

    cout
    << color(CYAN,BLACK,1)
    << DC
    << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
    << color(YELLOW, BLACK, 4)
    << "\n\n\t\t\t\t\tWelcome in Al-Ittihad club."
    << color(NC) << endl << endl
    << color(RED, BLACK, 1)
    << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
    << color(NC)
    << endl
    << color(GREEN, BLACK, 1)
    << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
    << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
            << endl
            << color(RED,BLACK,1)
            << "Do you want search by name or by number?"
            << color(NC)
            << endl
            << color(2,BLACK,1)
            << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number:"
            << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                            << color(RED,BLACK,1)
                            << "match played   wins    draws   losses   goals   points\n\n\t"
                            << color(NC)
                            << color(CYAN,BLACK,1)
                            << Ittihad.place
                            << color(NC)
                            << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,Ittihad.squad);
                                cout
                                << color(YELLOW,BLACK, 1)
                                << Ittihad.squad
                                << color(NC)
                                << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                            << color(YELLOW,BLACK,1)
                            <<  " Type     Titles  Competition\n"
                            << color(NC);
                            cout
                            << color(CYAN, BLACK, 1)
                            << Ittihad.Tournaments
                            << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                            << color(BLUE,BLACK, 1)
                            << Ittihad.stadium
                            << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                << color(RED,BLACK,1)
                                << "match played   wins    draws   losses   goals   points\n\n\t"
                                << color(NC)
                                << color(CYAN,BLACK,1)
                                << Ittihad.place
                                << color(NC)
                                << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,Ittihad.squad);
                                    cout
                                    << color(YELLOW,BLACK, 1)
                                    << Ittihad.squad
                                    << color(NC)
                                    << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                << color(YELLOW,BLACK,1)
                                <<  " Type     Titles  Competition\n"
                                << color(NC);
                                cout
                                << color(CYAN, BLACK, 1)
                                << Ittihad.Tournaments
                                << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                << color(BLUE,BLACK, 1)
                                << Ittihad.stadium
                                << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                    << endl
                    << color(RED, BLACK, 1)
                    << "You must choose \'NAME\' or \'NUMBER\': "
                    << color(NC);
                    getline(cin,condition);
                }
            }

            cout
            << endl
            << color(RED, BLACK, 3)
            << "Do you want choose again, or move back to the previous page ?"
            << color(NC)
            << endl
            << color(GREEN, BLACK, 3)
            << "Type \"Back\" to move back to the previous page.\n"
            << "Type \"Resume\" to choose again.\n"
            << "Type \"End\" to end the program.\n"
            << color(NC)
            << endl;

            cout << endl
            << color(BLACK, YELLOW, 7)
            << "Please type here: "
            << color(NC);
            getline(cin, move);
            CLUBRF1(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
            << endl
            << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF2(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Hilal();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al hilal!

void Al_Hilal(){

    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_hilal;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-hilal/hilal.txt"
    );

    string DC = "Al-Hilal was founded on 1957 (65 years ago).\n"
                "Al-Hilal's Home town is Riyadh.\n"
                "Chairman:Fahad Al Otaibi.\n"
                "The club's nickname:Al-Za'eem (The Boss)\n"
                "Club manager:Ram?n D?az.\n"
                "His nationality:Argentina.\n";
    al_hilal.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_hilal.stadium = "King Fahd International Stadium. \nIt is nicknamed \"The Tented Stadium\". \nIt is located in the eastern part of the capital of Saudi Arabia, Riyadh The stadium's stands can accommodate more than 60,000 spectators, \nwith each spectator having its own seat .\n";

    al_hilal.Tournaments = "\n            17    Pro League\n            9     King Cup\n            13    Crown Prince Cup \nDomestic    7     Saudi Federation Cup\n            3     Super Cup\n            1     Saudi Founder's Cup\n"
                           " ......................................"
                           "\n            4     AFC Champions League\nContinent   2     Asian Cup Winners Cup\n            2     Asian Super Cup\n"
                           " ......................................"
                           "\n            2     Arab Champions League\nRegional    2     GCC Champions League\n            1     Saudi-Egyptian Super Cup\n            1     Arab Super Cup\n            1     Arab Cup Winners' Cup\n  ";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Hilal club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number:"
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_hilal.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_hilal.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_hilal.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_hilal.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_hilal.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_hilal.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_hilal.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_hilal.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_hilal.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_hilal.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF2(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF3(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Nassr();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} // For Al nassr

void Al_Nassr(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alnasr;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-nassr/nassar.txt"
    );

    string DC = "Al-Nassr was founded on 1955 (67 years ago).\n"
                "Al-Nassr's Home town is  Riyadh.\n"
                "Chairman:Musalli Al Muammar.\n"
                "The club's nickname:Al-Aalami (The International Club)\n"
                "Club manager:Miguel ngel Russo.\n"
                "His nationality:Argentina.\n";
    alnasr.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alnasr.stadium = "King Saud University Stadium. \nAlso known as Mrsool Park due to sponsorship reasons, is a football stadium located in Riyadh, Saudi Arabia. \nIt contains a football stadium with a capacity of 25,000 spectators \n";

    alnasr.Tournaments = "\n            9     Pro League\n            6     King Cup\n            3     Crown Prince Cup \nDomestic    3     Saudi Federation Cup\n            2     Saudi Super Cup\n            1     Saudi Second League\n            8     Riyadh Region league\n"
                         " ......................................"
                         "\n            1     Asian Super Cup\nContinent      \n            1     Asian Cup Winners Cup\n"
                         " ......................................"
                         "\nRegional    2     GCC Champions League\n      ";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Nassr club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number:"
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << alnasr.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,alnasr.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << alnasr.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << alnasr.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << alnasr.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << alnasr.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,alnasr.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << alnasr.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << alnasr.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << alnasr.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF3(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF4(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Shabab();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al shabab

void Al_Shabab(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alshabab;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-shabab/shabab.txt"
    );

    string DC = "Al-Shabab was founded on 1947 (75 years ago).\n"
                "Al-Shabab's Home town is Riyadh.\n"
                "Chairman:Khalid Al-Baltan.\n"
                "The club's nickname:Al Leith (White Lion).\n"
                "Club manager: Marius Somodica\n"
                "His nationality: Romanianl.\n";
    alshabab.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alshabab.stadium = "Prince Khalid bin Sultan Stadium is the stadium of the Saudi Al Shabab Club, and bears the name of the honorary president of Al Shabab Club Khalid bin Sultan.\nIt was opened in the year 1984 and accommodates 10,000 spectators, including 200 VIP seats. \n";

    alshabab.Tournaments ="\n            6     Pro League\n            3     King Cup\n            3     Crown Prince Cup \nDomestic    4     Saudi Federation Cup\n            1     Saudi First Division\n"
                          " ......................................"
                          "\nContinent   1     Asian Cup Winners Cup\n"
                          " ......................................"
                          "\n            2     Arab Champions League\nRegional    2     GCC Champions League\n            2     Arab Super Cup\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Shabab club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number:"
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << alshabab.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,alshabab.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << alshabab.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << alshabab.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << alshabab.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << alshabab.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,alshabab.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << alshabab.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << alshabab.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << alshabab.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF4(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF5(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Damak();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Damak

void Damak(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club damak;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Damak/damak.txt"
    );

    string DC = "Damak was founded on 1972 (50 years ago).\n"
                "Damak's Home town is From Khamis Mushait Governorate in the southwest of the Kingdom of Saudi Arabia.\n"
                "Chairman: Saleh Abu Nekha'a.\n"
                "The club's nickname:Faris Al-Janub (The Knight of the South)\n"
                "Club manager: 	Kresimir Rezic\n"
                "His nationality: Croatia.\n";
    damak.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    damak.stadium = "Prince Sultan bin Abdulaziz Stadium, and the name of the stadium officially \"Prince Sultan bin Abdulaziz Sports City\", \nis a football stadium located in Abha, in the Asir region, and owned by the General Sports Authority. \nIt can accommodate about 20,000 spectators. .\n";

    damak.Tournaments = "\nDomestic      2    Saudi Second Division\n" ;

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Damak club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << damak.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,damak.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << damak.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << damak.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << damak.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << damak.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,damak.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << damak.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << damak.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << damak.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF5(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF6(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Abha();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Abha

void Abha(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club Abha;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Abha/abha.txt"
    );

    string DC = "Abha club was founded on 1999 (23 years ago).\n"
                "Abha club's Home town is Abha.\n"
                "Chairman: 	Ahmed Al-Hodithy.\n"
                "The club's nickname:Za'eem Al-Janoub (The Leaders of the South)\n"
                "Club manager: Martin Sevilla\n"
                "His nationality: Slovekia.\n";
    Abha.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    Abha.stadium = "Prince Sultan bin Abdulaziz Stadium, and the name of the stadium officially \"Prince Sultan bin Abdulaziz Sports City\", \nis a football stadium located in Abha, in the Asir region, and owned by the General Sports Authority. \nIt can accommodate about 20,000 spectators.\n";

    Abha.Tournaments = "\n            1     Saudi First Division\n            2     King CupSaudi Second Division\nDomestic    1     Saudi Third Division \n            1     Prince Faisal bin Fahd Cup for Division 1 and 2 Teams\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Abha club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << Abha.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,Abha.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << Abha.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << Abha.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    <<Abha.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << Abha.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,Abha.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << Abha.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << Abha.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << Abha.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF6(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF7(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Fateh();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al fateh

void Al_Fateh(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alfath;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-fateh/fateh.txt"
    );

    string DC = "Al-Fath was founded on 1958 (64 years ago).\n"
                "Al-Fath 's Home town is alHassa.\n"
                "Chairman:Saad Al-Afaliq.\n"
                "The club's nickname:faris al'ahsa' (Fares Al-Ahsa)\n"
                "Club manager: Georgios Donis\n"
                "His nationality: Greece.\n";
    alfath.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alfath.stadium = "Prince Abdullah bin Jalawi Sports City Stadium is a football stadium located in Al-Ahsa, Saudi Arabia. \nThis stadium is currently used by all Al-Ahsa clubs, and the stadium has a capacity of 27 thousand spectators.\n";

    alfath.Tournaments = "\n            1     Saudi Professional League \nDomestic    3     Second Division\n            1     Saudi Super Cup \n";


    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Fath club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << alfath.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,alfath.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << alfath.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << alfath.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << alfath.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << alfath.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,alfath.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << alfath.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << alfath.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << alfath.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF7(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF8(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Fayha();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} // For Al fayha

void Al_Fayha(){

    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_fayha;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-fayha/fayha.txt"
    );

    string DC = "Al-Fayha was founded on 1986 (36 years ago).\n"
                "Al-Fayha's Home town is Majma'ah.\n"
                "Chairman: Abdullah Ahmed Abanmi.\n"
                "The club's nickname:Al Burtuqali (The Orange)\n"
                "Club manager: Vuk Rašovic\n"
                "His nationality: Portugal.\n";
    al_fayha.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_fayha.stadium = "Al Majmaah Sports City, is a football stadium located in the city of Majmaah, where the Premier League and First Division clubs play. \nThe stadium was established in 1990 and can accommodate about 12,000 spectators. \nOn Mar 29, 2018 the General Sports Authority issued an official decision to change the name of King Salman bin Abdulaziz Sports City in Al Majmaah to Al Majmaah Sports City.\n";

    al_fayha.Tournaments = "\n            1     Saudi First Division\nDomestic\n            1     Saudi First Division\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Fayha club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_fayha.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_fayha.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_fayha.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_fayha.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_fayha.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_fayha.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_fayha.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_fayha.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_fayha.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_fayha.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF8(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF9(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Raed();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al raed

void Al_Raed(){

    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_raed;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-raed/raed.txt"
    );

    string DC = "Al-Raed was founded on 1954 (68 years ago).\n"
                "Al-Raed's Home town is harmah.\n"
                "Chairman: Fahad Al-Motawa'a.\n"
                "The club's nickname:Raed Al Tahadi\n"
                "Club manager:João Pedro Sousa\n"
                "His nationality: Greece.\n";
    al_raed.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_raed.stadium = "The King Abdullah Sports City Stadium, previously known as the Prince Abdullah bin Abdul Aziz Stadium, is a football stadium in Buraidah, Saudi Arabia.\nThe stadium has a seating capacity of 25,000 spectators. \n";

    al_raed.Tournaments = "\n    none \n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Raed club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_raed.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_raed.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_raed.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_raed.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_raed.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_raed.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_raed.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_raed.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_raed.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_raed.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF9(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back"  || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF10(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Ahli();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al Ahli

void Al_Ahli(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alahli;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-ahli/ahli.txt"
    );

    string DC = "Al-Ahli was founded on 1937 (85 years ago).\n"
                "Al-Ahli's Home town is Jeddah.\n"
                "Chairman:Majed Al-Nefaie.\n"
                "The club's nickname:aqaleat alkuuws (Castle of Cups)\n"
                "Club manager: Robert Siboldi\n"
                "His nationality:Uruguay.\n";
    alahli.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alahli.stadium = "Prince Abdullah Al-Faisal Stadium Its concrete terraces can accommodate 25,000 - 35,000. \nIt was called the Youth Care Stadium in Jeddah before it was changed in 2001 to Prince Abdullah Al-Faisal Stadium. \n";

    alahli.Tournaments ="\n            3     Pro League\n            13    King Cup\n            6     Crown Prince Cup \nDomestic    5     Saudi Federation Cup\n            1     Saudi Super Cup\n"
                        " ......................................"

                        "\n            1     Arab Champions League\nRegional    3     GCC Champions League\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Ahli club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << alahli.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,alahli.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << alahli.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << alahli.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << alahli.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << alahli.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,alahli.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << alahli.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << alahli.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << alahli.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF10(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF11(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Faisaly();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al Faisaly

void Al_Faisaly(){

    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_faisaly;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-faisaly/faisaly.txt"
    );

    string DC = "Al-Faisaly was founded on 1954 (68 years ago).\n"
                "Al-Faisaly's Home town is harmah.\n"
                "Chairman: Fahad Al-Medlej.\n"
                "The club's nickname:Annabi Sudair (The Burgundy of Sudair)\n"
                "Club manager: Marinos Ouzounidis\n"
                "His nationality: Greece.\n";
    al_faisaly.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_faisaly.stadium = "Al Majma'ah Sports City (formerly known as King Salman Bin Abdulaziz Sport City Stadium) is a multi-purpose stadium in Al Majma'ah, \nSaudi Arabia.The stadium has a seating capacity of 7,000.\n";

    al_faisaly.Tournaments = "\n            1     Saudi First Division\n            1     King Cup\nDomestic    1     Saudi Second Division\n            1     Prince Faisal bin Fahd Cup for Division 1 and 2 Teams\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Faisaly club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_faisaly.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_faisaly.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_faisaly.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_faisaly.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_faisaly.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_faisaly.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_faisaly.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_faisaly.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_faisaly.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_faisaly.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF11(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF12(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Tai();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al tai

void Al_Tai(){

    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_tai;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-tai/tai.txt"
    );

    string DC = "Al-Tai was founded on 1961 (61 years ago).\n"
                "Al-Tai's Home town is ha'il.\n"
                "Chairman: Turki Al-Dhabaan.\n"
                "The club's nickname:Faris Al Shamal (Knight of The North)\n"
                "Club manager: Jose Luis Sierra\n"
                "His nationality: chile.\n";
    al_tai.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_tai.stadium = "Prince Abdul Aziz bin Musa'ed Stadium is a multi-purpose stadium in Ha'il, Saudi Arabia. \nIt is currently used mostly for football matches and is the home stadium of Al-Ta'ee. \nThe stadium has a capacity of 12,250 people.\n";

    al_tai.Tournaments = "\n            3     Saudi First Division\nDomestic    1     Saudi Second Division\n            1     Prince Faisal bin Fahd Cup for Division 1 and 2 Teams\n   ";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Tai club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_tai.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_tai.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_tai.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_tai.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_tai.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_tai.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_tai.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_tai.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_tai.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_tai.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF12(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF13(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Taawoun(); // to choose another player
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} // For Al taawoun

void Al_Taawoun(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_taawoun;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-taawoun/taawoun.txt"
    );

    string DC = "Al-Taawoun was founded on 1956 (66 years ago).\n"
                "Al-Taawoun's Home town is Buraidah.\n"
                "Chairman: Mohammed Al-Qasim.\n"
                "The club's nickname:Al Dhiaab (The Wolves)\n"
                "Club manager: 	John van den Brom\n"
                "His nationality: netherlands.\n";
    al_taawoun.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_taawoun.stadium = "Prince Abdullah bin Abdul Aziz Stadium, is a football stadium in Buraidah.\nThe stadium has a seating capacity of 25,000 spectators.\n";

    al_taawoun.Tournaments = "\n            1     Saudi First Division \n            1     King Cup\nDomestic    1     Saudi Second Division  \n            5     Prince Faisal bin Fahd Cup for Division 1 and 2 Teams\n" ;
    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Taawoun club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_taawoun.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_taawoun.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_taawoun.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_taawoun.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_taawoun.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_taawoun.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_taawoun.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_taawoun.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_taawoun.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_taawoun.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF13(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF14(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Batin();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al batin

void Al_Batin(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_batin;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-batin/batin.txt"
    );

    string DC = "Al-Batin was founded on 1979 (41 years ago).\n"
                "Al-Batin's Home town is al batin.\n"
                "Chairman: Abdullah Al-Massar.\n"
                "The club's nickname:al batin (Al ventricle)\n"
                "Club manager: Jose Antonio Rocha Garrido\n"
                "His nationality: Portugal.\n";
    al_batin.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_batin.stadium = "Al-Batin Club Stadium is a football stadium located in Hafr Al-Batin, Saudi Arabia, with a capacity of 6000 spectators. \nIt was opened in 2016. \nIt is the official stadium of Al-Batin Club.\n";

    al_batin.Tournaments = "\n    none \n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Batin club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << al_batin.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_batin.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_batin.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_batin.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_batin.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_batin.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_batin.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_batin.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_batin.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_batin.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF14(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF15(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Ettifaq();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} // For Al Ettifaq!

void Al_Ettifaq(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alaitifaq;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-ettifaq/ettifaq.txt"
    );

    string DC = "Al-Ettifaq was founded on  1945 (77 years ago).\n"
                "Al-Ettifaq's Home town is Dammam.\n"
                "Chairman:Khalid Al-Dabal.\n"
                "The club's nickname:Faris Ad-Dahna (The Knight of Ad-Dahna).\n"
                "Club manager: Patrice Carteron.\n"
                "His nationality: French.\n";
    alaitifaq.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alaitifaq.stadium = "Prince Mohammed bin Fahd Stadium. \nIt is a football stadium located in the city of Dammam in the Eastern Province of the Kingdom of Saudi Arabia. \nIt has a capacity of 36000 thousand spectators.\n";

    alaitifaq.Tournaments = "\n            2     Pro League\n            2     King Cup\nDomestic    1     Crown Prince Cup \n            3     Saudi Federation Cup\n            2     Saudi First Division\n"
                            " ......................................"
                            "\n            2     Arab Champions League\nRegional    3     GCC Champions League\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Ettifaq club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition =="1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    << alaitifaq.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,alaitifaq.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << alaitifaq.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << alaitifaq.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << alaitifaq.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << alaitifaq.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,alaitifaq.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            <<alaitifaq.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << alaitifaq.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << alaitifaq.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF15(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}

void CLUBRF16(string moving_value){
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            Club_Table();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            Al_Hazem();
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} //For Al hazem

void Al_Hazem(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club al_hazem;

    ifstream squad;
    squad.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Al-hazem/hazem.txt"
    );

    string DC = "Al-Hazem was founded on 1957 (65 years ago).\n"
                "Al-Hazem's Home town Al-Rass.\n"
                "Chairman: Sulaiman Al-Malik.\n"
                "The club's nickname:alsafir (Ambassador)\n"
                "Club manager:	Roel Coumans\n"
                "His nationality: Nederlanden.\n";
    al_hazem.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    al_hazem.stadium = "Al-Hazm Club Stadium, is a Saudi sports stadium in which football is played. \nIt was built in 1982 by order of the General Presidency for Youth Welfare (currently the Ministry of Sports). \nIt is located in Al-Rass in the Qassim region, and the capacity does not exceed 7000 spectators.\n";

    al_hazem.Tournaments = "\n            1     Saudi Third Division\nDomestic    9     Al-Qassim Regional League\n            2     Saudi First Division/MS League\n";

    cout
            << color(CYAN,BLACK,1)
            << DC
            << color(NC);

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << " Select one from here to know about: "
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Places in the league\t\t [1]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Club's Squad\t\t\t [2]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t& "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Tournaments\t\t\t [3]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t&"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(GREEN, BLACK, 3)
            << " Stadium\t\t\t [4]"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " \t*"
            << color(NC)
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Al-Hazem club."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"){
            cout
                    << endl
                    << color(RED,BLACK,1)
                    << "Do you want search by name or by number?"
                    << color(NC)
                    << endl
                    << color(2,BLACK,1)
                    << "Type \'NAME\' OR 'N' to search by name; Type \'NUMBER\' OR '1' to search by number: "
                    << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name" || condition == "N" || condition == "n"){
                    cout
                            << color(YELLOW,BLACK,1)
                            << "\'PLACE\' for club's place in the league,\n\'SQUAD\' for club's squad,\n\'TOURNAMENTS\' for club's tournaments,\n\'STADIUM\' for club's stadium\n\nType your choice please: "
                            << color(NC);
                    getline(cin, choice);
                    while(flag){
                        if(choice == "PLACE" || choice == "place" || choice == "Place"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(RED,BLACK,1)
                                    << "match played   wins    draws   losses   goals   points\n\n\t"
                                    << color(NC)
                                    << color(CYAN,BLACK,1)
                                    <<al_hazem.place
                                    << color(NC)
                                    << endl;
                            break;
                        }
                        else if(choice == "SQUAD" || choice == "squad" || choice == "Squad"){
                            system("cls");
                            flag = false;
                            while(!squad.eof())
                            {
                                getline(squad,al_hazem.squad);
                                cout
                                        << color(YELLOW,BLACK, 1)
                                        << al_hazem.squad
                                        << color(NC)
                                        << endl;
                            }
                            break;
                        }
                        else if(choice == "Tournaments" || choice == "tournaments" || choice == "TOURNAMENTS"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(YELLOW,BLACK,1)
                                    <<  " Type     Titles  Competition\n"
                                    << color(NC);
                            cout
                                    << color(CYAN, BLACK, 1)
                                    << al_hazem.Tournaments
                                    << color(NC);
                            break;
                        }
                        else if(choice == "STADIUM" || choice == "stadium" || choice == "Stadium"){
                            system("cls");
                            flag = false;
                            cout
                                    << color(BLUE,BLACK, 1)
                                    << al_hazem.stadium
                                    << color(NC);
                            break;
                        }
                        else{
                            cout
                                    << endl
                                    << color(RED,BLACK,2)
                                    << "WRONG CHOICE TRY AGAIN: "
                                    << color(NC);
                            getline(cin, choice);
                        }
                    }
                }
                else if(condition == "NUMBER" || condition == "number" || condition == "Number" || condition == "1"){
                    cout
                            << color(GREEN,BLACK,1)
                            << "Type your choice number please: "
                            << color(NC);
                    cin >> TP_NUMBER;
                    cin.ignore();
                    while(flag){
                        switch (TP_NUMBER) {
                            case 1:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(RED,BLACK,1)
                                        << "match played   wins    draws   losses   goals   points\n\n\t"
                                        << color(NC)
                                        << color(CYAN,BLACK,1)
                                        << al_hazem.place
                                        << color(NC)
                                        << endl;
                                break;
                            }
                            case 2:{
                                system("cls");
                                flag = false;
                                while(!squad.eof())
                                {
                                    getline(squad,al_hazem.squad);
                                    cout
                                            << color(YELLOW,BLACK, 1)
                                            << al_hazem.squad
                                            << color(NC)
                                            << endl;
                                }
                                break;
                            }
                            case 3:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(YELLOW,BLACK,1)
                                        <<  " Type     Titles  Competition\n"
                                        << color(NC);
                                cout
                                        << color(CYAN, BLACK, 1)
                                        << al_hazem.Tournaments
                                        << color(NC);
                                break;
                            }
                            case 4:{
                                system("cls");
                                flag = false;
                                cout
                                        << color(BLUE,BLACK, 1)
                                        << al_hazem.stadium
                                        << color(NC);
                                break;
                            }
                            default:{
                                cout
                                        << color(RED,BLACK,1)
                                        << "Number you entered is not in the table please try again: "
                                        << color(NC);
                                cin >> TP_NUMBER;
                            }
                        }
                    }
                }

                else {
                    cout
                            << endl
                            << color(RED, BLACK, 1)
                            << "You must choose \'NAME\' or \'NUMBER\': "
                            << color(NC);
                    getline(cin,condition);
                }
            }

            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "Do you want choose again, or move back to the previous page ?"
                    << color(NC)
                    << endl
                    << color(GREEN, BLACK, 3)
                    << "Type \"Back\" to move back to the previous page.\n"
                    << "Type \"Resume\" to choose again.\n"
                    << "Type \"End\" to end the program.\n"
                    << color(NC)
                    << endl;

            cout << endl
                 << color(BLACK, YELLOW, 7)
                 << "Please type here: "
                 << color(NC);
            getline(cin, move);
            CLUBRF16(move);// return f
        }
        else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"){
            system("cls");
            flag = false;
            Club_Table();
            break;
        }
        else{
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    squad.close();
}
/*****************CLUBS FUNCTIONS END*****************|*/
void welcomeMSG() //Welcome Function
{
    AVT();
    string wc;
    ifstream greet;
    greet.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/Greeting.txt");
    while (!greet.eof())
    {
        getline(greet, wc);
        sleep(1);
        cout << color(3,BLACK,1) << wc << color(NC) << endl << flush;
    }
    system("pause"); // system("pause") to freeze the screen
    cout << color(CYAN,BLACK,1) << "\n                    Please wait until loading program pages..." << color(NC) << endl << endl;
        sleep(1);
        cout << color(RED,BLACK,1) << "\r                         [..........] 0%" << "  Loading!" << color(NC) << flush;
        sleep(1);
        cout << color(RED,BLACK,1) << "\r                         [#.........] 10%" << " lOading!" << color(NC) << flush;
        sleep(1);
        cout << color(YELLOW,BLACK,1) << "\r                         [##........] 20%" << " loAding!" << color(NC) <<flush;
        sleep(1);
        cout << color(YELLOW,BLACK,1) << "\r                         [###.......] 30%" << " loaDing!" << color(NC) << flush;
        sleep(1);
        cout << color(YELLOW,BLACK,1) << "\r                         [#####.....] 50%" << " loadIng!" << color(NC) << flush;
        sleep(1);
        cout << color(GREEN,BLACK,1) << "\r                         [########..] 80%" << " loadiNg!" << color(NC) << flush;
        sleep(1);
        cout << color(GREEN,BLACK,1) << "\r                         [##########] 100%" << " loadinG!" << color(NC) << flush;
    sleep(2);


    greet.close();
    PL_CL();
}

void PL_CL()
{
    system("cls"); // system("cls") to clean the screen
    AVT();
    int i=0;
    string cond;

    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t************************************************"
            << color(NC)
            <<endl;

    while(i<2){
        cout
                << color(3, BLACK, 6)
                << "\t\t\t\t\t*"
                << setw(20)
                << "\t*"
                << color(NC)
                << color(3, BLACK, 6)
                << setw(24)
                << right
                << "* "
                << color(NC)
                << endl;
        i++;
    }
    cout
            << setw(50)
            << color(3, BLACK, 6)
            << "*      "
            << color(NC)
            << setw(12)
            << color(YELLOW, BLACK, 1)
            << "Players"
            << color(NC)
            << color(3, BLACK,6)
            << "\t*"
            << color(NC)
            << color(YELLOW, BLACK, 1)
            << setw(16)
            << "Clubs Table"
            << color(NC)
            << color(3, BLACK, 6)
            << "      *"
            << color(NC)
            << endl;
    i=0;
    while(i<2){
        cout
                << color(3, BLACK, 6)
                << "\t\t\t\t\t*"
                << setw(20)
                << "\t*"
                << color(NC)
                << color(3, BLACK, 6)
                << setw(24)
                << right
                << "* "
                << color(NC)
                << endl;
        i++;
    }

    cout
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t************************************************"
            << color(NC)
            <<endl;

    cout
            << endl
            << color(RED, BLACK, 3)
            << "Do you want to go to \"Players\" OR \"CLUBS TABLE\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 3)
            << "Type 'Players' to go to \"Players Table\" ; Type 'CLUBS' to go to \"CLUBS TABLE\": "
            << color(NC);
    getline(cin, cond);
    i=1;
    while(i)
    {
        if(cond == "PLAYERS" || cond == "players" || cond == "Players" || cond == "PLAYER" || cond == "player" || cond == "Player") {
            i=0;
            system("cls");
            SCORER_ASSIST();
            break;
        }
        else if(cond == "CLUBS" || cond == "clubs" || cond == "Clubs" || cond == "CLUB" || cond == "club" || cond == "Club"){
            i=0;
            system("cls");
            Club_Table();
            break;
        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'SCORERS' or 'CLUBS': ";
            getline(cin, cond);
        }
    }
}

void Club_Table() // here we add all MBS PRO LEAGUE Clubs' names to array using Clubs_Table Class
{
    AVT(); // color function
    int TP_Number;
    string condition, CNAME[16];
    int i;

    ifstream CLUBS_NAME;
    CLUBS_NAME.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/PrintClubs.txt"
            );

    //Print clubs' table header
    cout
            << endl
            << endl
            << color(3, BLACK, 6)
            << setw(20)
            << "\t\t\t\t\t*********************************"
            << color(NC)
            <<endl;
    cout
            << color(3, BLACK, 6)
            << left
            << "\t\t\t\t\t* "
            << color(NC)
            << setw(10)
            << color(6, BLACK, 3)
            << "Club Name"
            << right
            << setw(20)
            << "Club Number"
            << color(NC)
            << color(3, BLACK, 6)
            << right
            << " *"
            << color(NC)
            << endl;

    //Print clubs into the table
    for(i=0; i<16 && !CLUBS_NAME.eof();i++)
    {
        getline(CLUBS_NAME, CNAME[i]);
        cout
                << color(3, BLACK, 6)
                << left
                << "\t\t\t\t\t* "
                << color(NC)
                << color(YELLOW, BLACK, 1)
                << setw(22)
                << CNAME[i] // print club's name from array
                << left
                << setw(8)
                << i+1// print club's number from array
                << color(NC)
                << color(3, BLACK, 6)
                << left
                << "* "
                << color(NC)
                << endl;
    }

    // Close the table
    cout
            << color(3, BLACK, 6)
            << "\t\t\t\t\t*********************************"
            << color(NC)
            <<endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Clubs' table."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Player and Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() >= 4 || condition.empty() == 0)
        {
            if((condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"))
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want to search by number or by name? "
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type 'name' to search by name; Type 'number' to search by number: "
                        << color(NC);
                getline(cin, condition); // Number or Name
                i=1;
                while(i)
                {
                    if(condition.empty() == 1 || condition == " ") { // Check whether the user input is empty or just a space
                        cout
                                << endl
                                << "You did not choose please enter again: ";
                        getline(cin, condition);
                    }
                    else
                        i=0;
                }

                i=1;
                while(i)
                {
                    if(condition == "NAME" || condition == "name" || condition == "Name") // check if the choice is a name
                    {
                        cout
                                << endl
                                << color(6, BLACK, 4)
                                << "Choose your club's name: "
                                << color(NC);
                        i=0;
                        SearchByName(); // call search by name function
                    }
                    else if(condition == "NUMBER" || condition == "number" || condition == "Number"){ // check if the choice is a number
                        cout
                                << endl
                                << color(6, BLACK, 4)
                                << "Choose your club's number: "
                                << color(NC);
                        while (i){
                            cin >> TP_Number;
                            cin.ignore();
                            switch (TP_Number) {
                                case 1:{
                                    i=0;
                                    system("cls");
                                    Alittihad();
                                    break;
                                }
                                case 2:{
                                    i=0;
                                    system("cls");
                                    Al_Hilal();
                                    break;
                                }
                                case 3:{
                                    i=0;
                                    system("cls");
                                    Al_Nassr();
                                    break;
                                }
                                case 4:{
                                    i=0;
                                    system("cls");
                                    Al_Shabab();
                                    break;
                                }
                                case 5:{
                                    i=0;
                                    system("cls");
                                    Damak();
                                    break;
                                }
                                case 6:{
                                    i=0;
                                    system("cls");
                                    Abha();
                                    break;
                                }
                                case 7:{
                                    i=0;
                                    system("cls");
                                    Al_Fateh();
                                    break;
                                }
                                case 8:{
                                    i=0;
                                    system("cls");
                                    Al_Fayha();
                                    break;
                                }
                                case 9:{
                                    i=0;
                                    system("cls");
                                    Al_Raed();
                                    break;
                                }
                                case 10:{
                                    i=0;
                                    system("cls");
                                    Al_Ahli();
                                    break;
                                }
                                case 11:{
                                    i=0;
                                    system("cls");
                                    Al_Faisaly();
                                    break;
                                }
                                case 12:{
                                    i=0;
                                    system("cls");
                                    Al_Tai();
                                    break;
                                }
                                case 13:{
                                    i=0;
                                    system("cls");
                                    Al_Taawoun();
                                    break;
                                }
                                case 14:{
                                    i=0;
                                    system("cls");
                                    Al_Batin();
                                    break;
                                }
                                case 15:{
                                    i=0;
                                    system("cls");
                                    Al_Ettifaq();
                                    break;
                                }
                                case 16:{
                                    i=0;
                                    system("cls");
                                    Al_Hazem();
                                    break;
                                }
                                default:
                                {
                                    cout
                                            << "Number is not belong to any club in the table."
                                            << endl
                                            << color(6, BLACK, 4)
                                            << "Choose your club's number: "
                                            << color(NC);
                                }

                            }
                        }
                    }
                    else{ // check if the input is neither name nor number
                        cout
                                << endl
                                << "You wrote something else, Please enter 'name' or 'number': ";
                        getline(cin, condition);
                    }
                }

                i=0;
                break;
            }
            else if((condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"))
            {
                i=0;
                system("cls");
                PL_CL();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }
        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
    CLUBS_NAME.close();
}

void SearchByName()
{
    AVT();
    int i =0;
    string TP_NAME;
    getline(cin, TP_NAME);
    string array[32];

    ifstream ClubsFile; // Declare variable to use fstream header file
    ClubsFile.open(
            "C://ClubsName.txt"  // The path of the file which contain clubs names
    );
    while(!ClubsFile.eof()) // loop won't end before execute all elements in the file
    {
        getline(ClubsFile, array[i]); // get elements from the file and store them in array

        if(TP_NAME != array[i])
        {
            i++;
        }
        else
            break;
    }
    /*****************CHECK THE INPUT HERE*****************|*/

    if(array[i] == "al ittihad" || array[i] == "AL ITTIHAD")
    {
        system("cls");
        Alittihad();
    }
    else if(array[i] == "al hilal" || array[i] == "AL HILAL")
    {
        system("cls");
        Al_Hilal();
    }
    else if(array[i] == "AL NASSR" || array[i] == "al nassr")
    {
        system("cls");
        Al_Nassr();
    }
    else if(array[i] == "AL SHABAB" || array[i] == "al shabab")
    {
        system("cls");
        Al_Shabab();
    }
    else if(array[i] == "DAMAK" || array[i] == "damak")
    {
        system("cls");
        Damak();
    }
    else if(array[i] == "ABHA" || array[i] == "abha")
    {
        system("cls");
        Abha();
    }
    else if(array[i] == "AL FATEH" || array[i] == "al fateh")
    {
        system("cls");
        Al_Fateh();
    }
    else if(array[i] == "AL FAYHA" || array[i] == "al fayha")
    {
        system("cls");
        Al_Fayha();
    }
    else if(array[i] == "AL RAED" || array[i] == "al raed")
    {
        system("cls");
        Al_Raed();
    }
    else if(array[i] == "AL AHLI" || array[i] == "al ahli")
    {
        system("cls");
        Al_Ahli();
    }
    else if(array[i] == "AL FAISALY" || array[i] == "al faisaly")
    {
        system("cls");
        Al_Faisaly();
    }
    else if(array[i] == "AL TAI" || array[i] == "al tai")
    {
        system("cls");
        Al_Tai();
    }
    else if(array[i] == "AL TAAWOUN" || array[i] == "al taawoun")
    {
        system("cls");
        Al_Taawoun();
    }
    else if(array[i] == "AL BATIN" || array[i] == "al batin")
    {
        system("cls");
        Al_Batin();
    }
    else if(array[i] == "AL ETTIFAQ" || array[i] == "al ettifaq")
    {
        system("cls");
        Al_Ettifaq();
    }
    else if(array[i] == "AL HAZEM" || array[i] == "al hazem")
    {
        system("cls");
        Al_Hazem();
    }
    else
    {
        cout
                << endl
                << color(RED, BLACK, 3)
                << "The club's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                << color(NC);
        SearchByName(); // if input does not match any element it will make the user try again
    }
    ClubsFile.close(); // close the file
} // here search by club's name function

void SCORER_ASSIST()
{
    int i=0;
    string move_TO, condition;
    AVT();

    cout
            << endl << endl
            << color(WHITE, BLACK, 6)
            << right
            << setw(50)
            << "\t\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"
            << color(NC)
            << endl;

    while(i < 1)
    {
        cout
                << color(WHITE, BLACK, 6)
                << left
                << "\t\t\t\t\tO "
                << color(NC)
                << color(BLUE, BLACK, 1)
                << setw(34)
                << " SCORERS"
                << left
                << setw(8)
                << "ASSIST "
                << color(NC)
                << color(WHITE, BLACK, 6)
                << left
                << "O "
                << color(NC)
                << endl;
        i++;
    }

    cout
            << color(WHITE, BLACK, 6)
            << right
            << setw(50)
            << "\t\t\t\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"
            << color(NC)
            << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome to Scorer's and Assist's players table."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Player and Club table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() >= 4 || condition.empty() == 0)
        {
            if((condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1"))
            {
                cout
                << endl
                << color(RED, BLACK, 3)
                << "Do you want to go to \"Sorer Players\" OR \"Assist Players\"? "
                << color(NC)
                << endl
                << color(GREEN, BLACK, 3)
                << "Type 'SCORERS' to go to \"Scorer Players\" ; Type 'ASSIST' to go to \"Assist Players\": "
                << color(NC);
                ///
                getline(cin, move_TO);
                i=1;
                while(i)
                {
                    if(move_TO == "SCORERS" || move_TO == "scorers" || move_TO == "Scorers" )
                    {
                        i=0;
                        system("cls");
                        HIS_CUR_S();// current assist players
                    }
                    else if(move_TO == "ASSIST" || move_TO == "assist" || move_TO == "Assist")
                    {
                        i=0;
                        system("cls");
                        HIS_CUR_A();
                    }
                    else
                    {
                        cout
                        << endl
                        << "You wrote something else, Please enter 'SCORERS' or 'ASSIST': ";
                        getline(cin, move_TO);
                    }
                }
                i=0;
                break;
            }
            else if((condition == "BACK" || condition == "back" || condition == "Back" || condition == "0"))
            {
                i=0;
                system("cls");
                PL_CL();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }
        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
} // here where user can choose from player table (scorers, assists)

void HIS_CUR_A()
{
    int i=0;
    string move_TO, condition;
    AVT();

    cout
            << endl << endl
            << color(MAGENTA, BLACK, 5)
            << right
            << setw(50)
            << "\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << color(NC)
            << endl;

    while(i < 1)
    {
        cout
                << color(MAGENTA, BLACK, 5)
                << left
                << "\t\t| "
                << color(NC)
                << color(YELLOW, BLACK, 1)
                << setw(34)
                << " CURRENT"
                << left
                << setw(8)
                << "HISTORICAL "
                << color(NC)
                << color(MAGENTA, BLACK, 5)
                << left
                << "\t| "
                << color(NC)
                << endl;
        i++;
    }

    cout
            << color(MAGENTA, BLACK, 5)
            << right
            << setw(50)
            << "\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << color(NC)
            << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome to Current and Historical Assist players table."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Scorers and Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1")
            {
                cout
                << endl
                << color(RED, BLACK, 3)
                << "Do you want to go to \"Current Assist Players\" OR \"Historical Assist Players\"? "
                << color(NC)
                << endl
                << color(GREEN, BLACK, 3)
                << "Type 'CURRENT' to go to \"Current Assist Players\" ; Type 'HISTORICAL' to go to \"Historical Assist Players\": "
                << color(NC);
                getline(cin, move_TO);
                i=1;
                while(i)
                {
                    if(move_TO.size() >= 4)
                    {
                        if(move_TO == "CURRENT" || move_TO == "current" || move_TO == "Current" )
                        {
                            i=0;
                            system("cls");
                            CUR_ASSIST();// current assist players
                            break;
                        }
                        else if(move_TO == "HISTORICAL" || move_TO == "historical" || move_TO == "Historical")
                        {
                            i=0;
                            system("cls");
                            HIS_ASSIST();
                            break;
                        }
                    }
                    else
                    {
                        cout
                                << endl
                                << "You wrote something else, Please enter 'CURRENT' or 'HISTORICAL': ";
                        getline(cin, move_TO);
                    }
                }
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0")
            {
                i=0;
                system("cls");
                SCORER_ASSIST();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }

        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
} // historical and current assist players table

void HIS_ASSIST(){
    AVT();
    string condition;
    int TP_NUMBER, i;
    HS CURRENT_S[] = {
            HS("Jihad Alhussein", 1),
            HS("Tayseer Aljassim", 2),
            HS("Yahya Alshehri", 3),
            HS("Elton Jose", 4),
            HS("Marcelo Camacho", 5)
    };

    cout
            << endl << endl
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-+"
            << color(NC) << endl;

    cout
            << color(MAGENTA, BLACK, 1)
            << left
            << "\t\t\t|  "
            << color(NC)
            << setw(10)
            << color(RED, BLACK, 1)
            << "Player's Name"
            << right
            << setw(33)
            << "Player's Number"
            << color(NC)
            << color(MAGENTA, BLACK, 1)
            << right
            << "  |"
            << color(NC)
            << endl;

    for (i = 0; (i) < 5; ++(i)) {
        cout
                << color(MAGENTA, BLACK,1)
                << left
                << "\t\t\t|  "
                << color(NC)
                << color(YELLOW, BLACK, 1)
                << setw(38)
                << CURRENT_S[i].SC_NAME
                << setw(10)
                << CURRENT_S[i].SC_NUMBER
                << color(NC)
                << color(MAGENTA, BLACK, 1)
                << left
                << "|"
                << color(NC)
                << endl;
    }
    cout
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-$-+"
            << color(NC) << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Historical Assist players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Historical and current Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1")
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want to search by number or by name? "
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type 'name' to search by name; Type 'number' to search by number: "
                        << color(NC);
                getline(cin, condition);
                i=1;
                while(i)
                {
                    if(condition.empty() == 1 || condition == " ") { // Check whether the user input is empty or just a space
                        cout
                                << endl
                                << "You did not choose please enter again: ";
                        getline(cin, condition);
                    }
                    else
                        i=0;
                }

                i=1;
                while(i)
                {
                    if(condition.size() >= 4){
                        if(condition == "NAME" || condition == "name" || condition == "Name") // check if the choice is a name
                        {
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose Player's name: "
                                    << color(NC);
                            i=0;
                            HIS_ASSIST_SEARCH();
                        }
                        else if(condition == "NUMBER" || condition == "number" || condition == "Number"){ // check if the choice is a number
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose Player's number: "
                                    << color(NC);
                            while (i){
                                cin >> TP_NUMBER;
                                cin.ignore();
                                switch (TP_NUMBER) {
                                    case 1:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Jihad Alhussein \t\t|  (Najran - Al-Taawoun - Al-Raed)\t|\t\t   Syria \t\t|\t\t 45"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 2:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\tPlayer's Country \t\t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Tayseer Aljassim \t|\t(Al-Ahil - Al-Wehdah) \t\t|\t  Saudi Arabia   \t\t|\t\t 36"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 3:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t|\tPlayer's Country \t|\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Yahya Alshehri \t\t| (Al-Ettifaq - Al-Nassr - Al-Raed[Until now]) \t\t|\t  Saudi Arabia   \t|\t\t 35"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 4:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\t Player's Club  \t\t\t|\tPlayer's Country \t|\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Elton Jose \t\t|    (Al-Nassr - Al-Fateh - Al-Qadisiya - Al-Wehdah)    |\t   Brazil   \t\t|\t\t  31"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 5:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t|\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Marcelo Camacho \t|\t\t(Al-Hilal - Al-Ahli - Al-Shabab) \t|\t  Brazil   \t\t|\t\t 26"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    default:
                                    {
                                        cout
                                                << "Number is not belong to any Player in the table."
                                                << endl
                                                << color(6, BLACK, 4)
                                                << "Choose Player's number: "
                                                << color(NC);
                                    }

                                }
                            }
                        }
                        else { // check if the input is neither name nor number
                            cout
                                    << endl
                                    << "You wrote something else, Please enter 'name' or 'number': ";
                            getline(cin, condition);
                        }
                    }
                    else{ // check if the input is neither name nor number
                        cout
                                << endl
                                << "You wrote something else, Please enter 'name' or 'number': ";
                        getline(cin, condition);
                    }
                }

                string move;
                i=1;

                cout
                << endl
                << color(RED, BLACK, 3)
                << "Do you want choose another player, or move back to the previous table ?"
                << color(NC)
                << endl
                << color(GREEN, BLACK, 3)
                << "Type \"Back\" to move back to the previous table.\n"
                << "Type \"Resume\" to choose another player.\n"
                << "Type \"End\" to end the program.\n"
                << color(NC)
                << endl;

                cout << endl
                     << color(BLACK, YELLOW, 7)
                     << "Please type here: "
                     << color(NC);
                getline(cin, move);
                ReturnF3(move);// return f 3
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back"|| condition == "0")
            {
                i=0;
                system("cls");
                HIS_CUR_A();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }

        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
} // historical assist

void HIS_ASSIST_SEARCH()
{
    AVT();
    string HIS_ASSIST_N[30];
    string HIS_NAME;
    int i=0;
    getline(cin, HIS_NAME);

    ifstream HIS_A_Names;
    HIS_A_Names.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/HIS_ASSIST_NAMES.txt"
    );

    /*****************CHECK THE INPUT HERE*****************|*/

    if((HIS_NAME.empty() == 0 || HIS_NAME != " ") && HIS_NAME.size() >= 4){

        while(!HIS_A_Names.eof())
        {
            getline(HIS_A_Names, HIS_ASSIST_N[i]);
            if(HIS_ASSIST_N[i] == HIS_NAME)
                break;
            else
                i++;
        }
        if(HIS_ASSIST_N[i] == HIS_NAME){
            if(HIS_ASSIST_N[i] == "Jihad Alhussein" || HIS_ASSIST_N[i] == "jihad alhussein" || HIS_ASSIST_N[i] == "jihad" || HIS_ASSIST_N[i] == "Jihad" || HIS_ASSIST_N[i] == "Alhussein" || HIS_ASSIST_N[i] == "alhussein")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Jihad Alhussein \t\t|  (Najran - Al-Taawoun - Al-Raed)\t|\t\t   Syria \t\t|\t\t 45"
                        << color(NC)
                        << endl;
            }
            else if(HIS_ASSIST_N[i] == "Tayseer Aljassim" || HIS_ASSIST_N[i] == "tayseer aljassim" || HIS_ASSIST_N[i] == "tayseer" || HIS_ASSIST_N[i] == "Tayseer" || HIS_ASSIST_N[i] == "Aljassim" || HIS_ASSIST_N[i] == "aljassim")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\tPlayer's Country \t\t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Tayseer Aljassim \t|\t(Al-Ahil - Al-Wehdah) \t\t|\t  Saudi Arabia   \t\t|\t\t 36"
                        << color(NC)
                        << endl;
            }
            else if(HIS_ASSIST_N[i] == "Yahya Alshehri" || HIS_ASSIST_N[i] == "yahya alshehri" || HIS_ASSIST_N[i] == "Yahya" || HIS_ASSIST_N[i] == "yahya" || HIS_ASSIST_N[i] == "Alshehri" || HIS_ASSIST_N[i] == "alshehri" )
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t|\tPlayer's Country \t|\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Yahya Alshehri \t\t| (Al-Ettifaq - Al-Nassr - Al-Raed[Until now]) \t\t|\t  Saudi Arabia   \t|\t\t 35"
                        << color(NC)
                        << endl;
            }
            else if(HIS_ASSIST_N[i] == "Elton Jose" || HIS_ASSIST_N[i] == "elton jose" || HIS_ASSIST_N[i] == "elton" || HIS_ASSIST_N[i] == "Elton" || HIS_ASSIST_N[i] == "Jose" || HIS_ASSIST_N[i] == "jose")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\t Player's Club  \t\t\t|\tPlayer's Country \t|\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Elton Jose \t\t|    (Al-Nassr - Al-Fateh - Al-Qadisiya - Al-Wehdah)    |\t   Brazil   \t\t|\t\t  31"
                        << color(NC)
                        << endl;
            }
            else if(HIS_ASSIST_N[i] == "Marcelo Camacho" || HIS_ASSIST_N[i] == "marcelo camacho" || HIS_ASSIST_N[i] == "Marcelo" || HIS_ASSIST_N[i] == "marcelo" || HIS_ASSIST_N[i] == "Camacho" || HIS_ASSIST_N[i] == "camacho")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t|\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Marcelo Camacho \t|\t\t(Al-Hilal - Al-Ahli - Al-Shabab) \t|\t  Brazil   \t\t|\t\t 26"
                        << color(NC)
                        << endl;
            }
            else
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "The Player's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                        << color(NC);
                HIS_ASSIST_SEARCH(); // if input does not match any element it will make the user try again
            }
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "The Player's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                    << color(NC);
            HIS_ASSIST_SEARCH(); // if input does not match any element it will make the user try again
        }
    }
    else
    {
        cout
                << endl
                << color(RED, BLACK, 3)
                << "The Player's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                << color(NC);
        HIS_ASSIST_SEARCH(); // if input does not match any element it will make the user try again
    }
    HIS_A_Names.close();
}

void ReturnF3(string moving_value)
{
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            HIS_CUR_A();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            HIS_ASSIST(); // to choose another player
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
}

void CUR_ASSIST(){
    AVT();
    string condition;
    int TP_NUMBER, i;
    HS CURRENT_S[] = {
            HS("Matheus Pereira", 1),
            HS("Panagiotis Tachtsidis", 2),
            HS("Igor Coronado", 3),
            HS("Ezgjan Alioski", 4),
            HS("Saleh Al-Amri", 5)
    };

    cout
            << endl << endl
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-+"
            << color(NC) << endl;

    cout
            << color(MAGENTA, BLACK, 1)
            << left
            << "\t\t\t|  "
            << color(NC)
            << setw(10)
            << color(RED, BLACK, 1)
            << "Player's Name"
            << right
            << setw(33)
            << "Player's Number"
            << color(NC)
            << color(MAGENTA, BLACK, 1)
            << right
            << "  |"
            << color(NC)
            << endl;

    for (i = 0; (i) < 5; ++(i)) {
        cout
                << color(MAGENTA, BLACK,1)
                << left
                << "\t\t\t|  "
                << color(NC)
                << color(YELLOW, BLACK, 1)
                << setw(38)
                << CURRENT_S[i].SC_NAME
                << setw(10)
                << CURRENT_S[i].SC_NUMBER
                << color(NC)
                << color(MAGENTA, BLACK, 1)
                << left
                << "|"
                << color(NC)
                << endl;
    }
    cout
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-+"
            << color(NC) << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Current Assist players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Historical and current Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1")
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want to search by number or by name? "
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type 'name' to search by name; Type 'number' to search by number: "
                        << color(NC);
                getline(cin, condition);
                i=1;
                while(i)
                {
                    if(condition.empty() == 1 || condition == " ") { // Check whether the user input is empty or just a space
                        cout
                                << endl
                                << "You did not choose please enter again: ";
                        getline(cin, condition);
                    }
                    else
                        i=0;
                }

                i=1;
                while(i)
                {
                    if(condition.size() >= 4){
                        if(condition == "NAME" || condition == "name" || condition == "Name") // check if the choice is a name
                        {
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose Player's name: "
                                    << color(NC);
                            i=0;
                            CUR_ASSIST_SEARCH();
                        }
                        else if(condition == "NUMBER" || condition == "number" || condition == "Number"){ // check if the choice is a number
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose Player's number: "
                                    << color(NC);
                            while (i){
                                cin >> TP_NUMBER;
                                cin.ignore();
                                switch (TP_NUMBER) {
                                    case 1:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Matheus Pereira \t\t|\t\t  Al-Hilal\t\t|\t\t   Brazil \t\t|\t\t 10"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 2:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Panagiotis Tachtsidis \t\t|\t\t  Al-Fayha\t\t|\t\t   Greece \t\t|\t\t 9"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 3:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Igor Coronado \t\t\t|\t\t  Al-Ittihad\t\t|\t\t   Brazil \t\t|\t\t 8"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 4:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Ezgjan Alioski \t\t\t|\t\t  Al-Ahli\t\t|\t    North Macedonia\t\t|\t\t 7"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 5:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Saleh Al-Amri \t\t\t|\t\t  Abha\t\t\t|\t\t  Saudi Arabia  \t|\t\t 7"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    default:
                                    {
                                        cout
                                                << "Number is not belong to any Player in the table."
                                                << endl
                                                << color(6, BLACK, 4)
                                                << "Choose Player's number: "
                                                << color(NC);
                                    }

                                }
                            }
                        }
                        else { // check if the input is neither name nor number
                            cout
                                    << endl
                                    << "You wrote something else, Please enter 'name' or 'number': ";
                            getline(cin, condition);
                        }
                    }
                    else{ // check if the input is neither name nor number
                        cout
                                << endl
                                << "You wrote something else, Please enter 'name' or 'number': ";
                        getline(cin, condition);
                    }
                }

                string move;
                i=1;

                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want choose another player, or move back to the previous table ?"
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type \"Back\" to move back to the previous table.\n"
                        << "Type \"Resume\" to choose another player.\n"
                        << "Type \"End\" to end the program.\n"
                        << color(NC)
                        << endl;

                cout << endl
                     << color(BLACK, YELLOW, 7)
                     << "Please type here: "
                     << color(NC);
                getline(cin, move);

                ReturnF4(move);  // return f 4

                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0")
            {
                i=0;
                system("cls");
                HIS_CUR_A();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }

        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
}

void CUR_ASSIST_SEARCH()
{
    AVT();
    string CA_NAMES[33];
    string PLAYER_NAME;
    int i=0;
    getline(cin, PLAYER_NAME);

    ifstream CurrentNames_A;
    CurrentNames_A.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/CUR_ASSIST_NAME.txt"
    );

    /*****************CHECK THE INPUT HERE*****************|*/

    if((PLAYER_NAME.empty() == 0 || PLAYER_NAME != " ") && PLAYER_NAME.size() >= 4){

        while(!CurrentNames_A.eof())
        {
            getline(CurrentNames_A, CA_NAMES[i]);
            if(CA_NAMES[i].compare(PLAYER_NAME) == 0)
                break;
            else
                i++;
        }
        if(CA_NAMES[i] == PLAYER_NAME){
            if(CA_NAMES[i] == "Matheus Pereira" || CA_NAMES[i] == "matheus pereira" || CA_NAMES[i] == "pereira" || CA_NAMES[i] == "Matheus" || CA_NAMES[i] == "matheus" || CA_NAMES[i] == "Pereira")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Matheus Pereira \t\t|\t\t  Al-Hilal\t\t|\t\t   Brazil \t\t|\t\t 10"
                        << color(NC)
                        << endl;
            }
            else if(CA_NAMES[i] == "Panagiotis Tachtsidis" || CA_NAMES[i] == "panagiotis tachtsidis" || CA_NAMES[i] == "Panagiotis" || CA_NAMES[i] == "panagiotis" || CA_NAMES[i] == "Tachtsidis" || CA_NAMES[i] == "tachtsidis")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Panagiotis Tachtsidis \t\t|\t\t  Al-Fayha\t\t|\t\t   Greece \t\t|\t\t 9"
                        << color(NC)
                        << endl;
            }
            else if(CA_NAMES[i] == "Igor Coronado" || CA_NAMES[i] == "igor coronado" || CA_NAMES[i] == "Igor" || CA_NAMES[i] == "igor" || CA_NAMES[i] == "Coronado" || CA_NAMES[i] == "coronado")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Igor Coronado \t\t\t|\t\t  Al-Ittihad\t\t|\t\t   Brazil \t\t|\t\t 8"
                        << color(NC)
                        << endl;
            }
            else if(CA_NAMES[i] == "Ezgjan Alioski" || CA_NAMES[i] == "ezgjan alioski" || CA_NAMES[i] == "Ezgjan" || CA_NAMES[i] == "ezgjan" || CA_NAMES[i] == "Alioski" || CA_NAMES[i] == "alioski")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Ezgjan Alioski \t\t\t|\t\t  Al-Ahli\t\t|\t    North Macedonia\t\t|\t\t 7"
                        << color(NC)
                        << endl;
            }
            else if(CA_NAMES[i] == "Saleh Al-Amri" || CA_NAMES[i] == "saleh al-amri" || CA_NAMES[i] == "saleh al amri" || CA_NAMES[i] == "Saleh" || CA_NAMES[i] == "saleh" || CA_NAMES[i] == "Al-Amri" || CA_NAMES[i] == "al-amri" || CA_NAMES[i] == "Al Amri" || CA_NAMES[i] == "al amri")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t|\t\tAssist"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Saleh Al-Amri \t\t\t|\t\t  Abha\t\t\t|\t\t  Saudi Arabia  \t|\t\t 7"
                        << color(NC)
                        << endl;
            }
            else
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                        << color(NC);
                CS_SEARCH(); // if input does not match any element it will make the user try again
            }
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                    << color(NC);
            CS_SEARCH(); // if input does not match any element it will make the user try again
        }
    }
    else
    {
        cout
                << endl
                << color(RED, BLACK, 3)
                << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                << color(NC);
        CS_SEARCH(); // if input does not match any element it will make the user try again
    }
    CurrentNames_A.close();
}

void ReturnF4(string moving_value)
{
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            HIS_CUR_A();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            CUR_ASSIST(); // to choose another player
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate();// rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
}

void HIS_CUR_S()
{
    int i=0;
    string move_TO, condition;
    AVT();

    cout
            << endl << endl
            << color(WHITE, BLACK, 3)
            << right
            << setw(50)
            << "\t\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << color(NC)
            << endl;

    while(i < 1)
    {
        cout
                << color(WHITE, BLACK, 1)
                << left
                << "\t\t\t\t\t| "
                << color(NC)
                << color(CYAN, BLACK, 5)
                << setw(34)
                << " CURRENT"
                << left
                << setw(8)
                << "HISTORICAL "
                << color(NC)
                << color(WHITE, BLACK, 1)
                << left
                << "\t| "
                << color(NC)
                << endl;
        i++;
    }

    cout
            << color(WHITE, BLACK, 3)
            << right
            << setw(50)
            << "\t\t\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << color(NC)
            << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome to Current and Historical Scorers' players table."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\t you want \"CONTINUE\" OR go \"BACK\" to \"Scorers and Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() >= 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1")
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want to go to \"Current Scorer Players\" OR \"Historical Scorer Players\"? "
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type 'CURRENT' to go to \"Current Scorer Players\" ; Type 'HISTORICAL' to go to \"Historical Scorer Players\": "
                        << color(NC);
                getline(cin, move_TO);
                i=1;
                while(i)
                {
                    if(move_TO.size() >= 4)
                    {
                        if(move_TO == "CURRENT" || move_TO == "current" || move_TO == "Current" )
                        {
                            i=0;
                            system("cls");
                            C_SCORERS();
                            break;
                        }
                        else if(move_TO == "HISTORICAL" || move_TO == "historical" || move_TO == "Historical")
                        {
                            i=0;
                            system("cls");
                            HIS_SCORERS();
                            break;
                        }
                    }
                    else
                    {
                        cout
                                << endl
                                << "You wrote something else, Please enter 'CURRENT' or 'HISTORICAL': ";
                        getline(cin, move_TO);
                    }
                }

                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0")
            {
                i=0;
                system("cls");
                SCORER_ASSIST();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }
        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
} // historical and current scorers' table

void C_SCORERS()
{
    AVT();
    string condition;
    int TP_NUMBER, i;
    HS CURRENT_S[] = {
            HS("Odion Ighalo", 1),
            HS("Leandre Tawamba", 2),
            HS("Romaarinho", 3),
            HS("Anderson Talisca", 4),
            HS("Abderazak Hamdallah", 5)
    };

    cout
            << endl << endl
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+--------------------------------------------------+"
            << color(NC) << endl;

    cout
            << color(MAGENTA, BLACK, 1)
            << left
            << "\t\t\t|  "
            << color(NC)
            << setw(10)
            << color(RED, BLACK, 1)
            << "Scorer's Name"
            << right
            << setw(33)
            << "Scorer's Number"
            << color(NC)
            << color(MAGENTA, BLACK, 1)
            << right
            << "  |"
            << color(NC)
            << endl;

    for (i = 0; (i) < 5; ++(i)) {
        cout
                << color(MAGENTA, BLACK,1)
                << left
                << "\t\t\t|  "
                << color(NC)
                << color(YELLOW, BLACK, 1)
                << setw(38)
                << CURRENT_S[i].SC_NAME
                << setw(10)
                << CURRENT_S[i].SC_NUMBER
                << color(NC)
                << color(MAGENTA, BLACK, 1)
                << left
                << "|"
                << color(NC)
                << endl;
    }
    cout
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+--------------------------------------------------+"
            << color(NC) << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Current Scorer players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Current and Historical Scorers table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1")
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want to search by number or by name? "
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type 'name' to search by name; Type 'number' to search by number: "
                        << color(NC);
                getline(cin, condition);
                i=1;
                while(i)
                {
                    if(condition.empty() == 1 || condition == " ") { // Check whether the user input is empty or just a space
                        cout
                                << endl
                                << "You did not choose please enter again: ";
                        getline(cin, condition);
                    }
                    else
                        i=0;
                }

                i=1;
                while(i)
                {
                    if(condition.size() >= 4){
                        if(condition == "NAME" || condition == "name" || condition == "Name") // check if the choice is a name
                        {
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose your Scorer's name: "
                                    << color(NC);
                            i=0;
                            CS_SEARCH();
                        }
                        else if(condition == "NUMBER" || condition == "number" || condition == "Number"){ // check if the choice is a number
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose your Scorer's number: "
                                    << color(NC);
                            while (i){
                                cin >> TP_NUMBER;
                                cin.ignore();
                                switch (TP_NUMBER) {
                                    case 1:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Odion Ighalo \t\t|\t\tAl-Hilal \t\t|\t\t    Nigeria \t\t\t|\t\t  19(0)"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 2:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Leandre Tawamba \t|\t\tAl-Taawoun \t\t|\t\t    Cameroon \t\t\t|\t\t  15(3)"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 3:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Romaarinho \t\t|\t\tAl-Ittihad \t\t|\t\t    Brazil \t\t\t|\t\t  15(5)"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 4:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Anderson Talisca \t|\t\tAl-Nassr \t\t|\t\t    Brazil \t\t\t|\t\t  14(0)"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 5:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Abderazak Hamdallah \t|\t\tAl-Ittihad \t\t|\t\t    Morocco \t\t\t|\t\t  13(4)"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    default:
                                    {
                                        cout
                                                << "Number is not belong to any Player in the table."
                                                << endl
                                                << color(6, BLACK, 4)
                                                << "Choose your Scorer's number: "
                                                << color(NC);
                                    }

                                }
                            }
                        }
                        else { // check if the input is neither name nor number
                            cout
                                    << endl
                                    << "You wrote something else, Please enter 'name' or 'number': ";
                            getline(cin, condition);
                        }
                    }
                    else{ // check if the input is neither name nor number
                        cout
                                << endl
                                << "You wrote something else, Please enter 'name' or 'number': ";
                        getline(cin, condition);
                    }
                }

                string move;
                i=1;

                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want choose another player, or move back to the previous table ?"
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type \"Back\" to move back to the previous table.\n"
                        << "Type \"Resume\" to choose another player.\n"
                        << "Type \"End\" to end the program.\n"
                        << color(NC)
                        << endl;

                cout << endl
                     << color(BLACK, YELLOW, 7)
                     << "Please type here: "
                     << color(NC);
                getline(cin, move);

                ReturnF1(move);

                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0")
            {
                i=0;
                system("cls");
                HIS_CUR_S();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }

        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
} // current scorers table names

void CS_SEARCH()
{
    AVT();
    string CSNAMES[26];
    string CS_NAME;
    int i=0;
    getline(cin, CS_NAME);

    ifstream CurrentNames;
    CurrentNames.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/CurrentSN.txt"
    );

    /*****************CHECK THE INPUT HERE*****************|*/

    if((CS_NAME.empty() == 0 || CS_NAME != " ") && CS_NAME.size() > 4){

        while(!CurrentNames.eof())
        {
            getline(CurrentNames, CSNAMES[i]);
            if(CSNAMES[i].compare(CS_NAME) == 0)
                break;
            else
                i++;
        }
        if(CSNAMES[i] == CS_NAME){
            if(CSNAMES[i] == "Odion Ighalo" || CSNAMES[i] == "odion ighalo" || CSNAMES[i] == "odion" || CSNAMES[i] == "ighalo" || CSNAMES[i] == "Odion" || CSNAMES[i] == "Ighalo")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Odion Ighalo \t\t|\t\tAl-Hilal \t\t|\t\t    Nigeria \t\t\t|\t\t  19(0)"
                        << color(NC)
                        << endl;
            }
            else if(CSNAMES[i] == "Leandre Tawamba" || CSNAMES[i] == "leandre tawamba" || CSNAMES[i] == "leandre" || CSNAMES[i] == "tawamba" || CSNAMES[i] == "Leandre" || CSNAMES[i] == "Tawamba")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Leandre Tawamba \t|\t\tAl-Taawoun \t\t|\t\t    Cameroon \t\t\t|\t\t  15(3)"
                        << color(NC)
                        << endl;
            }
            else if(CSNAMES[i] == "Romaarinho" || CSNAMES[i] == "romaarinho")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Romaarinho \t\t|\t\tAl-Ittihad \t\t|\t\t    Brazil \t\t\t|\t\t  15(5)"
                        << color(NC)
                        << endl;
            }
            else if(CSNAMES[i] == "Anderson Talisca" || CSNAMES[i] == "anderson talisca" || CSNAMES[i] == "anderson" || CSNAMES[i] == "talisca" || CSNAMES[i] == "Anderson" || CSNAMES[i] == "Talisca")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Anderson Talisca \t|\t\tAl-Nassr \t\t|\t\t    Brazil \t\t\t|\t\t  14(0)"
                        << color(NC)
                        << endl;
            }
            else if(CSNAMES[i] == "Abderazak Hamdallah" || CSNAMES[i] == "abderazak hamdallah" || CSNAMES[i] == "abderazak" || CSNAMES[i] == "hamdallah" || CSNAMES[i] == "Abderazak" || CSNAMES[i] == "Hamdallah")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals(Penalty)"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Abderazak Hamdallah \t|\t\tAl-Ittihad \t\t|\t\t    Morocco \t\t\t|\t\t  13(4)"
                        << color(NC)
                        << endl;
            }
            else
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                        << color(NC);
                CS_SEARCH(); // if input does not match any element it will make the user try again
            }
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                    << color(NC);
            CS_SEARCH(); // if input does not match any element it will make the user try again
        }
    }
    else
    {
        cout
                << endl
                << color(RED, BLACK, 3)
                << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                << color(NC);
        CS_SEARCH(); // if input does not match any element it will make the user try again
    }
    CurrentNames.close();
} // here search by scorer's name

void ReturnF1(string moving_value)
{
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            HIS_CUR_S(); //historical or current scorer's table function
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            C_SCORERS(); // to choose another player
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} // return function from current scorers table.

void HIS_SCORERS(){
    AVT();
    string condition;
    int TP_NUMBER, i;
    HS CURRENT_S[] = {
            HS("Majed Abdullah", 1),
            HS("Nasser Alshamrani", 2),
            HS("Omar Alsomah", 3),
            HS("Fahad Alhamdan", 4),
            HS("Yasser Alqahtani", 5)
    };

    cout
            << endl << endl
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+--------------------------------------------------+"
            << color(NC) << endl;

    cout
            << color(MAGENTA, BLACK, 1)
            << left
            << "\t\t\t|  "
            << color(NC)
            << setw(10)
            << color(RED, BLACK, 1)
            << "Scorer's Name"
            << right
            << setw(33)
            << "Scorer's Number"
            << color(NC)
            << color(MAGENTA, BLACK, 1)
            << right
            << "  |"
            << color(NC)
            << endl;

    for (i = 0; (i) < 5; ++(i)) {
        cout
                << color(MAGENTA, BLACK,1)
                << left
                << "\t\t\t|  "
                << color(NC)
                << color(YELLOW, BLACK, 1)
                << setw(38)
                << CURRENT_S[i].SC_NAME
                << setw(10)
                << CURRENT_S[i].SC_NUMBER
                << color(NC)
                << color(MAGENTA, BLACK, 1)
                << left
                << "|"
                << color(NC)
                << endl;
    }
    cout
            << color(MAGENTA,BLACK, 1)
            << setw(50)
            << "\t\t\t+--------------------------------------------------+"
            << color(NC) << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\t\t\t\tWelcome in Historical Scorer players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Current and Historical Scorers table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "\t\tType 'CONTINUE' OR '1' to \"continue here\" ; Type 'BACK' OR '0' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue" || condition == "1")
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want to search by number or by name? "
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type 'name' to search by name; Type 'number' to search by number: "
                        << color(NC);
                getline(cin, condition);
                i=1;
                while(i)
                {
                    if(condition.empty() == 1 || condition == " ") { // Check whether the user input is empty or just a space
                        cout
                                << endl
                                << "You did not choose please enter again: ";
                        getline(cin, condition);
                    }
                    else
                        i=0;
                }

                i=1;
                while(i)
                {
                    if(condition.size() >= 4){
                        if(condition == "NAME" || condition == "name" || condition == "Name") // check if the choice is a name
                        {
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose your Scorer's name: "
                                    << color(NC);
                            i=0;
                            HIS_SEARCH();
                        }
                        else if(condition == "NUMBER" || condition == "number" || condition == "Number"){ // check if the choice is a number
                            cout
                                    << endl
                                    << color(6, BLACK, 4)
                                    << "Choose your Scorer's number: "
                                    << color(NC);
                            while (i){
                                cin >> TP_NUMBER;
                                cin.ignore();
                                switch (TP_NUMBER) {
                                    case 1:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Majed Abdullah \t\t|\t\tAl-Nassr \t\t|\t\t   Saudi Arabia \t\t|\t\t 189"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 2:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t\t|\tPlayer's Country \t\t|\t\tGoals"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Nasser Alshamrani \t|\t(Al-Wehdah - Al-Shabab - Al-Hilal - Al-Ittihad) \t|\t    Saudi Arabia \t\t|\t\t 176"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 3:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Omar Alsomah \t\t|\t\tAl-Ahli \t\t|\t\t    Syria \t\t\t|\t\t 137"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 4:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Fahad Alhamdan \t\t|\t\tAl-Riyad \t\t|\t\t    Saudi Arabia \t\t|\t\t  120"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    case 5:{
                                        i=0;
                                        system("cls");
                                        cout
                                                << endl << endl
                                                << color(CYAN, BLACK,1)
                                                << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                                                << color(NC)
                                                << endl
                                                << color(WHITE, BLACK, 1)
                                                << "Yasser Alqahtani \t|\t\t(Al-Qadisiya - Al-Hilal) \t\t|\t\t    Saudi Arabia \t\t|\t\t 112"
                                                << color(NC)
                                                << endl;
                                        break;
                                    }
                                    default:
                                    {
                                        cout
                                                << "Number is not belong to any Player in the table."
                                                << endl
                                                << color(6, BLACK, 4)
                                                << "Choose your Scorer's number: "
                                                << color(NC);
                                    }

                                }
                            }
                        }
                        else { // check if the input is neither name nor number
                            cout
                                    << endl
                                    << "You wrote something else, Please enter 'name' or 'number': ";
                            getline(cin, condition);
                        }
                    }
                    else{ // check if the input is neither name nor number
                        cout
                                << endl
                                << "You wrote something else, Please enter 'name' or 'number': ";
                        getline(cin, condition);
                    }
                }

                string move;
                i=1;

                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "Do you want choose another player, or move back to the previous table ?"
                        << color(NC)
                        << endl
                        << color(GREEN, BLACK, 3)
                        << "Type \"Back\" to move back to the previous table.\n"
                        << "Type \"Resume\" to choose another player.\n"
                        << "Type \"End\" to end the program.\n"
                        << color(NC)
                        << endl;

                cout << endl
                     << color(BLACK, YELLOW, 7)
                     << "Please type here: "
                     << color(NC);
                getline(cin, move);

                ReturnF2(move); // return f2

                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back" || condition == "0")
            {
                i=0;
                system("cls");
                HIS_CUR_S();
                break;
            }

            else
            {
                cout
                        << endl
                        << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
                getline(cin, condition);
            }

        }
        else
        {
            cout
                    << endl
                    << "You wrote something else, Please enter 'CONTINUE' or 'BACK': ";
            getline(cin, condition);
        }
    }
} // historical scorers' table names

void HIS_SEARCH()
{
    AVT();
    string HISNAMES[30];
    string HS_NAME;
    int i=0;
    getline(cin, HS_NAME);

    ifstream HISTORICALNames;
    HISTORICALNames.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/HIS_SCORERSN.txt"
    );

    /*****************CHECK THE INPUT HERE*****************|*/

    if((HS_NAME.empty() == 0 || HS_NAME != " ") && HS_NAME.size() > 3){

        while(!HISTORICALNames.eof())
        {
            getline(HISTORICALNames, HISNAMES[i]);
            if(HISNAMES[i] == HS_NAME)
                break;
            else
                i++;
        }
        if(HISNAMES[i] == HS_NAME){
            if(HISNAMES[i] == "Majed Abdullah" || HISNAMES[i] == "majed abdullah" || HISNAMES[i] == "majed" || HISNAMES[i] == "Majed" || HISNAMES[i] == "Abdullah" || HISNAMES[i] == "abdullah")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Majed Abdullah \t\t|\t\tAl-Nassr \t\t|\t\t   Saudi Arabia \t\t|\t\t 189"
                        << color(NC)
                        << endl;
            }
            else if(HISNAMES[i] == "Nasser Alshamrani" || HISNAMES[i] == "nasser alshamrani" || HISNAMES[i] == "Nasser" || HISNAMES[i] == "nasser" || HISNAMES[i] == "alshamrani" || HISNAMES[i] == "Alshamrani")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t\t|\tPlayer's Country \t\t|\t\tGoals"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Nasser Alshamrani \t|\t(Al-Wehdah - Al-Shabab - Al-Hilal - Al-Ittihad) \t|\t    Saudi Arabia \t\t|\t\t 176"
                        << color(NC)
                        << endl;
            }
            else if(HISNAMES[i] == "Omar Alsomah" || HISNAMES[i] == "omar alsomah" || HISNAMES[i] == "Omar" || HISNAMES[i] == "omar" || HISNAMES[i] == "Alsomah" || HISNAMES[i] == "alsomah")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Omar Alsomah \t\t|\t\tAl-Ahli \t\t|\t\t    Syria \t\t\t|\t\t 137"
                        << color(NC)
                        << endl;
            }
            else if(HISNAMES[i] == "Fahad Alhamdan" || HISNAMES[i] == "fahad alhamdan" || HISNAMES[i] == "Fahad" || HISNAMES[i] == "fahad" || HISNAMES[i] == "Alhamdan" || HISNAMES[i] == "alhamdan")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Fahad Alhamdan \t\t|\t\tAl-Riyad \t\t|\t\t    Saudi Arabia \t\t|\t\t  120"
                        << color(NC)
                        << endl;
            }
            else if(HISNAMES[i] == "Yasser Alqahtani" || HISNAMES[i] == "yasser alqahtani" || HISNAMES[i] == "Yasser" || HISNAMES[i] == "yasser" || HISNAMES[i] == "Alqahtani" || HISNAMES[i] == "alqahtani")
            {
                system("cls");
                cout
                        << endl << endl
                        << color(CYAN, BLACK,1)
                        << "Player's Name \t\t|\t\tPlayer's Club \t\t\t\t|\t\tPlayer's Country \t\t|\t\tGoals"
                        << color(NC)
                        << endl
                        << color(WHITE, BLACK, 1)
                        << "Yasser Alqahtani \t|\t\t(Al-Qadisiya - Al-Hilal) \t\t|\t\t    Saudi Arabia \t\t|\t\t 112"
                        << color(NC)
                        << endl;
            }
            else
            {
                cout
                        << endl
                        << color(RED, BLACK, 3)
                        << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                        << color(NC);
                HIS_SEARCH(); // if input does not match any element it will make the user try again
            }
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 3)
                    << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                    << color(NC);
            HIS_SEARCH(); // if input does not match any element it will make the user try again
        }
    }
    else
    {
        cout
                << endl
                << color(RED, BLACK, 3)
                << "The Scorer's name you entered is not in MBS PRO LEAGUE/ OR you didn't enter name: "
                << color(NC);
        HIS_SEARCH(); // if input does not match any element it will make the user try again
    }
    HISTORICALNames.close();
} // here search by historical scorer's name

void ReturnF2(string moving_value)
{
    AVT();
    bool flag = true;
    while(flag)
    {
        if(moving_value == "Back" || moving_value == "back" || moving_value == "BACK"){
            system("cls");
            flag = false;
            HIS_CUR_S();
        }
        else if(moving_value == "Resume" || moving_value == "resume" || moving_value == "RESUME"){
            system("cls");
            flag = false;
            HIS_SCORERS(); // to choose another player
        }
        else if(moving_value == "End" || moving_value == "end" || moving_value == "END"){
            system("cls");
            flag = false;
            rate(); // rate function
        }
        else
        {
            cout
                    << endl
                    << color(RED, BLACK, 2)
                    << "You entered wrong word OR You did not enter anything.\n"
                    << color(NC)
                    << color(BLACK, YELLOW, 7)
                    << "Please type here: "
                    << color(NC);
            getline(cin, moving_value);

        }
    }
} // return to scorers and assist table

void rate()
{
    string sug;
    int rate;
    AVT();
    cout
            << endl << endl
            << color(YELLOW, BLACK, 1)
            << "\t\t\t Thank you for using our program.\n"
            << "\t\t\t We hope the program was useful for you.\n"
            << color(NC)
            << color(MAGENTA, BLACK, 1)
            << "\nPlease rate our work from 10."
            << color(NC)
            << color(GREEN, BLACK, 1)
            << "\n[10]. Excellent!\n[9]. Good Job!\n[8]. Great!\n[7]. Work Harder!\n[6]. Kill yourselves!\n"
            << color(NC) << endl
            << color(RED,BLACK,1)
            << "Enter here please: "
            << color(NC);
    cin >> rate;
    cout << color(CYAN, BLACK,1)
         << "\n\nThank you for rating our work!\n\n"
         << color(NC);

    cout
    << endl << endl
    << color(MAGENTA,BLACK,0)
    << "Do you have a suggestion?"
    << "\n'Y' if you have, 'N' if you haven't.\n"
    << color(NC)
    << color(GREEN,BLACK,-1)
    << "Type Here: "
    << color(NC);
    cin.ignore();
    getline(cin,sug);
    if(sug == "Y" || sug == "y")
        suggestions(&sug);
}

void suggestions(string *sug){
    ofstream suggestions;
    suggestions.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SCORER.V2/suggestions.txt",
            ios::app
            );
    if(!suggestions.is_open())
        cout << "File can not be reached!\n";
    else {

        cout << endl << endl;

        sleep(1);
        cout << color(RED,BLACK,1) << "\r                    [..........] 0%" << "  Searching for suggestions file." << color(NC) << flush;
        sleep(1);
        cout << color(RED,BLACK,1) << "\r                    [o.........] 10%" << " Searching for suggestions file!" << color(NC) << flush;
        sleep(1);
        cout << color(RED,BLACK,1) << "\r                    [.o........] 20%" << " Searching for suggestions file!!" << color(NC) <<flush;
        sleep(1);
        cout << color(RED,BLACK,1) << "\r                    [..o.......] 30%" << " Searching for suggestions file!!!" << color(NC) << flush;
        sleep(2);
        cout << color(RED,BLACK,1) << "\r                    [....o.....] 50%" << " Opening the file!                " << color(NC) << flush;
        sleep(1);
        cout << color(RED,BLACK,1) << "\r                    [.......o..] 80%" << " Prepare my pen!                  " << color(NC) << flush;
        sleep(2);
        cout << color(RED,BLACK,1) << "\r                    [oooooooooo] 100%" << " Go ahead!         " << color(NC) << flush;


        cout << endl << endl
        << color(RED,BLACK,1)
        << "Type your suggestion: "
        << color(NC);
        getline(cin, *sug);
        suggestions << *sug << endl;
        cout << "\nThank you we add your suggestion.";
    }
}
#endif