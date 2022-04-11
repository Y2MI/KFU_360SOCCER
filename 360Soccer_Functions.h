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
void Club_Table();
void SearchByName();
void Players_Tables();
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
void Players_Tabels()
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
        << color(NC)
        << color(3, BLACK, 6)
        << setw(48)
        << right
        << "* "
        << color(NC)
        << endl;
        i++;
    }
    cout
    << setw(50)
    << color(3, BLACK, 6)
    << "*   "
    << color(NC)
    << color(YELLOW, BLACK, 1)
    << "Scorers List"
    << setw(27)
    << "Clubs Table"
    << color(NC)
    << color(3, BLACK, 6)
    << "    *"
    << color(NC)
    << endl;
    i=0;
    while(i<2){
        cout
                << color(3, BLACK, 6)
                << "\t\t\t\t\t*"
                << color(NC)
                << color(3, BLACK, 6)
                << setw(48)
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
    << "Do you want to go to \"SCORERS LIST\" OR \"CLUBS TABLE\"? "
    << color(NC)
    << endl
    << color(GREEN, BLACK, 3)
    << "Type 'SCORERS' to go to \"SCORERS LIST\" ; Type 'CLUBS' to go to \"CLUBS TABLE\": "
    << color(NC);
    getline(cin, cond);
    i=1;
    while(i)
    {
        if((cond.at(0) == 'S' || cond.at(0) == 's') && (cond.at(3) == 'r' || cond.at(3) == 'R')) {
            i=0;
            system("cls");
            cout << "SCORERS";
            break;
        }
        else if((cond.at(0) == 'c' || cond.at(0) == 'C') && (cond.at(3) == 'B' || cond.at(3) == 'b')){
            i=0;
            system("cls");
            Club_Table();
            break;
        }
        else
        {
            cout
            << endl
            << "You wrote something else, Please enter 'SOCCER' or 'CLUBS': ";
            getline(cin, cond);
        }
    }

    system("pause");
}


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
    Club_Table();
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
            Clubs_Table("AL FATH", 7),
            Clubs_Table("AL FAIHA", 8),
            Clubs_Table("AL RAED", 9),
            Clubs_Table("AL AHLI", 10),
            Clubs_Table("AL FAISALY", 11),
            Clubs_Table("AL TAEE", 12),
            Clubs_Table("AL TAAWOUN", 13),
            Clubs_Table("AL BATIN", 14),
            Clubs_Table("AL ITTIFAQ", 15),
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
        if(condition.at(1) == 'a' || condition.at(1) == 'A') // check if the choice is a name
        {
            cout
            << endl
            << color(6, BLACK, 4)
            << "Choose your club's name: "
            << color(NC);
            i=0;
            SearchByName(); // call search by name function
        }
        else if(condition.at(1) == 'u' || condition.at(1) == 'U'){ // check if the choice is a number
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
    /*string Clubs_Array[16][2] = {
            "AL ITTIHAD", "al ittihad",
            "AL HILAL", "al hilal",
            "AL NASSR",  "al nassr",
            "AL SHABAB", "al shabab",
            "DAMAK", "damak",
            "ABHA", "abha",
            "AL FATH", "al fath",
            "AL FAIHA", "al faiha",
            "AL RAED", "al raed",
            "AL AHLI", "al ahli",
            "AL FAISALY", "al faisaly",
            "AL TAEE", "al taee",
            "AL TAAWOUN", "al taawoun",
            "AL BATIN", "al batin",
            "AL ITTIFAQ","al ittifaq",
            "AL HAZEM", "al hazem"
    };*/
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
    else if(array[i] == "AL FATH" || array[i] == "al fath")
    {
        system("cls");
        cout << "Welcome to AL FATH" << endl;
    }
    else if(array[i] == "AL FAIHA" || array[i] == "al faiha")
    {
        system("cls");
        cout << "Welcome to AL FAIHA" << endl;
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
    else if(array[i] == "AL TAEE" || array[i] == "al taee")
    {
        system("cls");
        cout << "Welcome to AL TAEE" << endl;
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
    else if(array[i] == "AL ITTIFAQ" || array[i] == "al ittifaq")
    {
        system("cls");
        cout << "Welcome to AL ITTIFAQ" << endl;
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
}

/*void rate()
{
    cout
    << "Thank you for using our program"
    << right
    << setw(15)
    << "Please rate us by enter 1-10"
    << endl
    << left
    << "10- "
    << "Exicelent"<< endl;
    system("pause");
}
*/
#endif