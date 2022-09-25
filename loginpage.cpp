/*
REGISTER AND LOGIN PROJECT ON C++
    this is the explanation of the way the first page of the programe will look like
        ____________________________________
        |                Menu              |
        |                                  |        |
        | 1.  login                        |
        | 2. registration                  |
        | 3. forgot password               |
        | 4. exit                          |
        |                                  |
        |__________________________________|
*/
/*
 */
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

// in this the forgot pass vala section is not necessary .... ps remove it coz it wont work . 


int main()
{
    int c; // choice
    cout << "\t\t\t__________________________________________________\n\n\n";
    cout << "\t\t\t            welcome to the login page             \n\n\n";
    cout << "\t\t\t____________________   MENU   ____________________\n\n\n";
    cout << "                                                          \n\n";
    cout << "\t | press 1 to login                                 | " << endl;
    cout << "\t | press 2 to register                              | " << endl;
    cout << "\t | press 3 for  forgot password                     | " << endl;
    cout << "\t | press 4 to exit                                  | " << endl;
    cout << "\n \t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;

    switch (c) //  this step is prettey simple nothing here is too complex
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t thank you \n"
             << endl;
        break;

    default:
        system("cls");
        cout << "\t\t\t please select the option given above \n\n\n"
             << endl;
        main();
    }
}

void login()
{              // this is the part of the code which handles the login part
    int count; // count is the variable that count if the same user name is registered or not

    /*
    int count here us used becoz
        if the user is registered in the data base then the count will change to one as we will se in the programme further
            the value of count will not exceed one coz the the user namewill not repeat
    */

    string user_id, password, id, pass;
    system("cls"); // this is used to clear the page (help in making the programe look more clear)
    cout << " \t\t\t please enter the username and password :" << endl;
    cout << " \t\t\t USERNAME : ";
    cin >> user_id;
    cout << "\t\t\t PASSWORD : " << endl;
    cin >> password;

    // here now we will check if the user name or password already exists or not

    ifstream input("records.txt"); // input is the object name

    // here we have used the file handling operation of the ifstream class
    // IFSTREAM  is used to read the data

    while (input >> id >> pass) // this is a way to read in file handling operations
    /*
    here what we are doing is
        we are reading the id and password in the " records "
    */
    {
        if (id == user_id && pass == password) // if the read password is equal to the userid and the pass entered by the user
        {
            count = 1;     //  then the count will increment and will be equal to one
            system("cls"); //  system will get clear
        }
    }
    input.close(); //  the input will close that means that we are not reading the file " records "

    if (count == 1) // if count = 1 this will mean that the username is already registered and login will be successfull
    {
        cout << user_id << " your login is successful \n thanks for logging in ! \n " << endl;
    }
    else //  this the the fuction will return to the main funtion which means that the start again
    {
        cout << " \n LOGGING ERROR \n Please check your username and password \n "; // shoting the error in the funtion
        main();
    }
}

void registration() // here we are making the registration function
{
    string ruser_id, rpassword, rid, rpass; // we take in 4 variable out which 2 are input by the user
    system("cls");
    cout << " \t\t\t Enter the username : ";
    cin >> ruser_id;
    cout << "\t\t\t enter the password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    // this ios::app is
    // ios is an input and output stream while app is that the function will append in the end ( meaing of apped is that it will add the information input by the user in the end
    // of stream is used as to take in the data ina recorded file

    f1 << ruser_id << ' ' << rpassword << endl; // this is a way to write in ofstream
    system("cls");
    cout << "\n \t\t\t registration is successful " << endl;
    main();
}

void forgot()
{ // this funtion will be called whent eh user forgots the password or the user name
    int option;
    system("cls");
    //  then we will ask the user to press 1 or 2 so that he is redirected to
    // 1 is to search his id and 2 is to go back to the main menu
    cout << "\t\t\t yoou forgot the password ? no worries \n";

    cout << "press 1 to search your id by user name " << endl;
    cout << "press 2 to to go back to the main menu " << endl;
    cout << " \t\t\t enter your choice " << endl;

    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count = 0;
        string suserid, sid, spass;
        cout << "\n \t\t\t enter the username which you remembered " << endl;
        cin >> suserid;

        ifstream f2("records.txt");
        while (f2 >> sid >> spass)
            ;
        {
            if (sid == suserid)
            {
                count = 1;
            }
        }
        f2.close();

        if (count = 1)
        {
            cout << "\n\n your account is found \n your password is " << spass;
            main();
        }
        else
        {
            cout << "\n\n sorry your account is not found \n"
                 << endl;
        }

        break;
    }

    case 2:
    {
        {
            main();
        }
        break;
    }

    default:
        cout << "wrong choice pls try again";
        forgot();

        break;
    }
}