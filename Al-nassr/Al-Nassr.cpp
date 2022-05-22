void Al_Nassr(){
    AVT();
    int TP_NUMBER, i=0;
    string condition, choice, move;
    bool flag = true;
    club alnasr;

    ifstream squad;
    squad.open(
            ""
            );

    string DC = "Al-Nassr was founded on 1955 (67 years ago).\n"
                "Al-Nassr's Home town is  Riyadh.\n"
                "Chairman:Musalli Al Muammar.\n"
                "The club's nickname:Al-Aalami (The International Club)\n"
                "Club manager:Miguel ngel Russo.\n"
                "His nationality:Argentina.\n";
    alnasr.place = "25,\t 19,\t 3,\t 3,\t 54,\t 60";

    alnasr.stadium = "King Saud University Stadium, also known as Mrsool Park due to sponsorship reasons, is a football stadium located in Riyadh, Saudi Arabia. It contains a football stadium with a capacity of 25,000 spectators \n";

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
            alnasr(); // to choose another player
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
