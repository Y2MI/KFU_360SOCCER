void Al_Shabab(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alshabab;

    ifstream squad;
    squad.open(
            ""
            );

    string DC = "Al-Shabab was founded on 1947 (75 years ago).\n"
                "Al-Shabab's Home town is Riyadh.\n"
                "Chairman:Khalid Al-Baltan.\n"
                "The club's nickname:Al Leith (White Lion).\n"
                "Club manager: Marius Somodica\n"
                "His nationality: Romanianl.\n";
   alshabab.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alshabab.stadium = "Prince Khalid bin Sultan Stadium is the stadium of the Saudi Al Shabab Club, and bears the name of the honorary president of Al Shabab Club Khalid bin Sultan. It was opened in the year 1984 and accommodates 10,000 spectators, including 200 VIP seats..” \n";

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
    << "\n\n\t\t\t\t\tWelcome Al-Shabab club."
    << color(NC) << endl << endl
    << color(RED, BLACK, 1)
    << "\t\t\tDo you want \"CONTINUE\" OR go \"BACK\" to \"Club table\"? "
    << color(NC)
    << endl
    << color(GREEN, BLACK, 1)
    << "\t\tType 'CONTINUE' to \"continue here\" ; Type 'BACK' to go back to \"Previous Page\": "
    << color(NC);
    getline(cin, condition);
    while(flag){
        if(condition == "CONTINUE" || condition == "continue" || condition == "Continue"){
            cout
            << endl
            << color(RED,BLACK,1)
            << "Do you want search by name or by number?"
            << color(NC)
            << endl
            << color(2,BLACK,1)
            << "Type \'NAME\' to search by name; Type \'NUMBER\' to search by number: "
            << color(NC);
            getline(cin, condition);
            while(flag){
                if(condition == "NAME" || condition == "Name" || condition == "name"){
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
                                getline(squad,al_hilal.squad);
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
                else if(condition == "NUMBER" || condition == "number" || condition == "Number"){
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
        else if(condition == "BACK" || condition == "back" || condition == "Back"){
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
            Al_Shabab(); // to choose another player
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
