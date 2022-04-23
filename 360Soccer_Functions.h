/*
 * This Program founded and developed by:
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
/*****************CLASSES DECLARATION*****************|*/
class Clubs_Table // Public class to organize clubs choice table
{
public:
    string club;
    int number;
    Clubs_Table(string clubName, int oPnum)
    {
        club = clubName;
        number = oPnum;
    }
};

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
void welcomeMSG() //Welcome Function
{
    AVT();
    cout << endl << endl;
    cout << setw(50)
    << color(GREEN , BLACK, 5 )
    << "Welcome to 360Soccer"
    << color(NC)
    << endl;
    cout
    << color(BLACK, WHITE, 2)
    << setw(100)
    << "THIS PROGRAM PROVIDE TO YOU THE ABILITY TO KNOW EVERY THING ABOUT MBS PRO. LEAGUE."
    << color(NC)
    << endl
    << endl
    << endl;
    (system("pause"), system("cls")); // system("cls") to clean the screen
    PL_CL();
}

void PL_CL()
{
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

    system("pause");
}

void Club_Table() // here we add all MBS PRO LEAGUE Clubs' names to array using Clubs_Table Class
{
    AVT(); // color function
    int TP_Number;
    string condition;
    int i;
    Clubs_Table ClubsArray[] = { // Declare Clubs names with their numbers
            Clubs_Table("AL ITTIHAD", 1),
            Clubs_Table("AL HILAL", 2),
            Clubs_Table("AL NASSR", 3),
            Clubs_Table("AL SHABAB", 4),
            Clubs_Table("DAMAK", 5),
            Clubs_Table("ABHA", 6),
            Clubs_Table("AL FATEH", 7),
            Clubs_Table("AL FAYHA", 8),
            Clubs_Table("AL RAED", 9),
            Clubs_Table("AL AHLI", 10),
            Clubs_Table("AL FAISALY", 11),
            Clubs_Table("AL TAI", 12),
            Clubs_Table("AL TAAWOUN", 13),
            Clubs_Table("AL BATIN", 14),
            Clubs_Table("AL ETTIFAQ", 15),
            Clubs_Table("AL HAZEM", 16)

    };

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
    for(i=0; i<16;i++)
    {
        cout
        << color(3, BLACK, 6)
        << left
        << "\t\t\t\t\t* "
        << color(NC)
        << color(YELLOW, BLACK, 1)
        << setw(22)
        << ClubsArray[i].club // print club's name from array
        << color(NC)
        << left
        << setw(8)
        << ClubsArray[i].number // print club's number from array
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
    << "\n\n\t\tWelcome to Clubs' table."
    << color(NC) << endl << endl
    << color(RED, BLACK, 1)
    << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Player and Club table\"? "
    << color(NC)
    << endl
    << color(GREEN, BLACK, 1)
    << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
    << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() >= 4 || condition.empty() == 0)
        {
            if((condition == "CONTINUE" || condition == "continue" || condition == "Continue"))
            {
                i=0;
                break;
            }
            else if((condition == "BACK" || condition == "back" || condition == "Back"))
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
                switch (TP_Number) {
                    case 1:{
                        i=0;
                        break;
                    }
                    case 2:{
                        i=0;
                        break;
                    }
                    case 3:{
                        i=0;
                        break;
                    }
                    case 4:{
                        i=0;
                        break;
                    }
                    case 5:{
                        i=0;
                        break;
                    }
                    case 6:{
                        i=0;
                        break;
                    }
                    case 7:{
                        i=0;
                        break;
                    }
                    case 8:{
                        i=0;
                        break;
                    }
                    case 9:{
                        i=0;
                        break;
                    }
                    case 10:{
                        i=0;
                        break;
                    }
                    case 11:{
                        i=0;
                        break;
                    }
                    case 12:{
                        i=0;
                        break;
                    }
                    case 13:{
                        i=0;
                        break;
                    }
                    case 14:{
                        i=0;
                        break;
                    }
                    case 15:{
                        i=0;
                        break;
                    }
                    case 16:{
                        i=0;
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
            << "You wrote something else, Please enter 'name' or 'number'";
            getline(cin, condition);
        }
    }

    system("pause"); // to freeze the output console
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
        cout << "Welcome to AL ITTIHAD" << endl;
    }
    else if(array[i] == "al hilal" || array[i] == "AL HILAL")
    {
        system("cls");
        cout << "Welcome to AL HILAL" << endl;
    }
    else if(array[i] == "AL NASSR" || array[i] == "al nassr")
    {
        system("cls");
        cout << "Welcome to AL NASSR" << endl;
    }
    else if(array[i] == "AL SHABAB" || array[i] == "al shabab")
    {
        system("cls");
        cout << "Welcome to AL SHABAB" << endl;
    }
    else if(array[i] == "DAMAK" || array[i] == "damak")
    {
        system("cls");
        cout << "Welcome to DAMAK" << endl;
    }
    else if(array[i] == "ABHA" || array[i] == "abha")
    {
        system("cls");
        cout << "Welcome to ABHA" << endl;
    }
    else if(array[i] == "AL FATEH" || array[i] == "al fateh")
    {
        system("cls");
        cout << "Welcome to AL FATEH" << endl;
    }
    else if(array[i] == "AL FAYHA" || array[i] == "al fayha")
    {
        system("cls");
        cout << "Welcome to AL FAYHA" << endl;
    }
    else if(array[i] == "AL RAED" || array[i] == "al raed")
    {
        system("cls");
        cout << "Welcome to AL RAED" << endl;
    }
    else if(array[i] == "AL AHLI" || array[i] == "al ahli")
    {
        system("cls");
        cout << "Welcome to AL AHLI" << endl;
    }
    else if(array[i] == "AL FAISALY" || array[i] == "al faisaly")
    {
        system("cls");
        cout << "Welcome to AL FAISALY" << endl;
    }
    else if(array[i] == "AL TAI" || array[i] == "al tai")
    {
        system("cls");
        cout << "Welcome to AL TAI" << endl;
    }
    else if(array[i] == "AL TAAWOUN" || array[i] == "al taawoun")
    {
        system("cls");
        cout << "Welcome to AL TAAWOUN" << endl;
    }
    else if(array[i] == "AL BATIN" || array[i] == "al batin")
    {
        system("cls");
        cout << "Welcome to AL BATIN" << endl;
    }
    else if(array[i] == "AL ETTIFAQ" || array[i] == "al ettifaq")
    {
        system("cls");
        cout << "Welcome to AL ETTIFAQ" << endl;
    }
    else if(array[i] == "AL HAZEM" || array[i] == "al hazem")
    {
        system("cls");
        cout << "Welcome to AL HAZEM" << endl;
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
    system("pause");
} // here search by club's name function

void SCORER_ASSIST()
{
    int i=0;
    string move_TO, condition;
    AVT();

    cout
    << endl << endl
    << color(WHITE, BLACK, 3)
    << right
    << setw(50)
    << "\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"
    << color(NC)
    << endl;

    while(i < 1)
    {
        cout
        << color(WHITE, BLACK, 3)
        << left
        << "\t\tO "
        << color(NC)
        << color(BLUE, BLACK, 5)
        << setw(34)
        << " SCORERS"
        << left
        << setw(8)
        << "ASSIST "
        << color(NC)
        << color(WHITE, BLACK, 3)
        << left
        << "O "
        << color(NC)
        << endl;
        i++;
    }

    cout
    << color(WHITE, BLACK, 3)
    << right
    << setw(50)
    << "\t\tOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"
    << color(NC)
    << endl;

    cout
    << color(YELLOW, BLACK, 4)
    << "\n\n\t\tWelcome to Scorer's and Assist's players table."
    << color(NC) << endl << endl
    << color(RED, BLACK, 1)
    << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Player and Club table\"? "
    << color(NC)
    << endl
    << color(GREEN, BLACK, 1)
    << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
    << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() >= 4 || condition.empty() == 0)
        {
            if((condition == "CONTINUE" || condition == "continue" || condition == "Continue"))
            {
                i=0;
                break;
            }
            else if((condition == "BACK" || condition == "back" || condition == "Back"))
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

    cout
    << endl
    << color(RED, BLACK, 3)
    << "Do you want to go to \"Sorer Players\" OR \"Assist Players\"? "
    << color(NC)
    << endl
    << color(GREEN, BLACK, 3)
    << "Type 'SCORERS' to go to \"Scorer Players\" ; Type 'ASSIST' to go to \"Assist Players\": "
    << color(NC);
    getline(cin, move_TO);
    i=1;
    while(i)
    {
        if(move_TO.size() >= 4)
        {
            if(move_TO == "SCORERS" || move_TO == "scorers" || move_TO == "Scorers")
            {
                i=0;
                system("cls");
                HIS_CUR_S();
                break;
            }
            else if(move_TO == "ASSIST" || move_TO == "assist" || move_TO == "Assist")
            {
                i=0;
                system("cls");
                HIS_CUR_A();
                break;
            }
        }
        else
        {
            cout
            << endl
            << "You wrote something else, Please enter 'SCORERS' or 'ASSIST': ";
            getline(cin, move_TO);
        }
    }

    system("pause");
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
            << "\n\n\t\tWelcome to Current and Historical Assist players table."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Scorers and Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue")
            {
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back")
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

    system("pause");
} // historical and current assist players tabel

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
            << "\n\n\t\tWelcome in Historical Assist players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Historical and current Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue")
            {
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back")
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
    system("Pause");
} // historical assist // done 1st Q *********

void HIS_ASSIST_SEARCH()
{
    AVT();
    string HIS_ASSIST_N[30];
    string HIS_NAME;
    int i=0;
    getline(cin, HIS_NAME);

    ifstream HIS_A_Names;
    HIS_A_Names.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SOCCER.V1/HIS_ASSIST_NAMES.txt"
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
            << "\n\n\t\tWelcome in Current Assist players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Historical and current Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue")
            {
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back")
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
    system("Pause");
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
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SOCCER.V1/CUR_ASSIST_NAME.txt"
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
            << "\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << color(NC)
            << endl;

    while(i < 1)
    {
        cout
                << color(WHITE, BLACK, 1)
                << left
                << "\t\t| "
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
            << "\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
            << color(NC)
            << endl;

    cout
            << color(YELLOW, BLACK, 4)
            << "\n\n\t\tWelcome to Current and Historical Scorers' players table."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Scorers and Assist table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() >= 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue")
            {
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back")
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

    system("pause");
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
            << "\n\n\t\tWelcome in Current Scorer players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Current and Historical Scorers table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue")
            {
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back")
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
    system("Pause");
} // current scorers table names // done 1st Q *******

void CS_SEARCH()
{
    AVT();
    string CSNAMES[26];
    string CS_NAME;
    int i=0;
    getline(cin, CS_NAME);

    ifstream CurrentNames;
    CurrentNames.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SOCCER.V1/CurrentSN.txt"
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
            << "\n\n\t\tWelcome in Historical Scorer players page."
            << color(NC) << endl << endl
            << color(RED, BLACK, 1)
            << "Do you want \"CONTINUE\" OR go \"BACK\" to \"Current and Historical Scorers table\"? "
            << color(NC)
            << endl
            << color(GREEN, BLACK, 1)
            << "Type 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
            << color(NC);
    getline(cin, condition);

    i=1;
    while(i)
    {
        if(condition.size() > 4 || condition.empty() == 0)
        {
            if(condition == "CONTINUE" || condition == "continue" || condition == "Continue")
            {
                i=0;
                break;
            }
            else if(condition == "BACK" || condition == "back" || condition == "Back")
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
    system("Pause");
} // historical scorers' table names // done 1st Q *****

void HIS_SEARCH()
{
    AVT();
    string HISNAMES[30];
    string HS_NAME;
    int i=0;
    getline(cin, HS_NAME);

    ifstream HISTORICALNames;
    HISTORICALNames.open(
            "C:/Users/user/OneDrive/Desktop/F.O.P/360Soccer project/360SOCCER.V1/HIS_SCORERSN.txt"
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
    << "\n\nThank you for rate our work!\n\n"
    << color(NC);
}

#endif