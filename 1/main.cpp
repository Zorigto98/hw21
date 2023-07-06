#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

string check_first_latter (string temp_str)
{
    if (temp_str[0]>=97 && temp_str[0]<=122) temp_str[0]-=32;
    return temp_str;
}

string input_temp(const string& what_input)
{
    cout << "enter the " << " " << what_input << " of the recipient of the funds " << endl;
    string temp_str;
    cin >> temp_str;
    return temp_str;
}

bool check_date(const string& date)
{

    bool checkDay = false, checkMonth = false, checkYear=false;

    int point_pos = date.find('.');
    if (point_pos < 0)
    {
        cout << "Invalid date. try again" << endl;
        return false;
    }
    int point_pos2 = date.find('.',point_pos + 1);
    int Day = stoi(date.substr(0,point_pos));
    int Month = stoi(date.substr(point_pos + 1 ,point_pos2 + 1));
    int Year = stoi(date.substr(point_pos2 + 1, date.length()-point_pos2 - 1));


    if (Year <= 2022 && Year >=1950) checkYear = true; // условные ограничения для года

    if (Month>=1 && Month<=12) checkMonth = true;

    if (Month<=7)
    {
        if (Month%2 != 0 && Day<=31) checkDay = true;
        else if (Month%2 == 0 && Day<=30) checkDay = true;
        if (Month == 2 && Day>28) checkDay = false;
    }
    else
    {
        if (Month%2 != 0 && Day<=30) checkDay = true;
        else if (Month%2 == 0 && Day<=31) checkDay = true;
    }

    if (!checkDay || !checkMonth || !checkYear)
    {
        cout << "Invalid date. try again" << endl;
        return false;
    }
    else return true;
}

bool check_money(const string& money)
{
    if (stoi(money)>=0) return true;
    else
    {
        cout << "Incorrect input. Try again" << endl;
        return false;
    }
}

struct payment
{
    string name = "unknown";
    string lastName = "unknown";
    string date = "unknown";
    string pay = "unknown";
};

void input_payment(ofstream& file, payment& person)
{
    file << endl;
    int lenName =  person.name.length();
    file.write(person.name.c_str(), lenName);
    file << " ";

    int lenLastName =  person.lastName.length();
    file.write(person.lastName.c_str(), lenLastName);
    file << " ";

    int lenDate =  person.date.length();
    file.write(person.date.c_str(), lenDate);
    file << " ";

    int lenPay =  person.pay.length();
    file.write(person.pay.c_str(), lenPay);
}

int main() {

    ofstream file ("../payment.txt", ios::app);
    if (file.is_open())
    {
        char ans;
        string name, lastname, date, pay;

        payment person;
        do {
            person.name = check_first_latter(input_temp("name"));
            person.lastName = check_first_latter(input_temp("last name"));

            bool bDate=false;
            while (!bDate)
            {
                date=input_temp("date");
                bDate=check_date(date);
            }
            person.date = date;

            bool bMoney= false;
            while (!bMoney)
            {
                pay=input_temp("money");
                bMoney=check_money(pay);
            }

            person.pay = pay;

            input_payment(file, person);

            cout << "Do you want to input new person?" << endl << "Y/N" << endl;
            cin >> ans;
        }
        while (ans == 'y' || ans == 'Y');
    }
    else cout << "File doesn't open" << endl;
}
