#include <bits/stdc++.h>

using namespace std;

struct Account
{
    string name;
    int id;
    int amount=0;
    string number;
    string address;
    string type;
};

class BankManagement
{
private:
    queue<Account> person;

public:
    void openAccount()
    {
        Account s;

        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, s.name);

        cout << "Enter Address: ";
        getline(cin, s.address);

        cout << "Enter your mobile number : ";
        cin >> s.number;

        cout << "What type of account you want to open saving(S) or current(C): ";
        cin >> s.type;

        cout << "Enter Account Number : ";
        cin >> s.id;

        cout << "Enter Amount for deposite: ";
        cin >> s.amount;

        cout<<"Your Account is created..."<<endl<<endl;

        person.push(s);
    }

    void showAll()
    {
        queue<Account> temp = person;

        while (!temp.empty())
        {
            Account s = temp.front();
            temp.pop();

            cout << "Name: " << s.name << endl;
            cout << "Address: " << s.address << endl;
            cout << "Mobile Number: " << s.number << endl;
            cout << "Account Number: " << s.id << endl;
            cout << "Types of account: " << s.type << endl;
            cout << "Current balance: " << s.amount << endl;
            cout << endl;
        }
    }

    bool search(int id)
    {
        queue<Account> temp = person;
        bool found = false;

        while (!temp.empty())
        {
            Account s = temp.front();
            temp.pop();

            if (s.id == id)
            {
                cout << "Name: " << s.name << endl;
                cout << "Address: " << s.address << endl;
                cout << "Mobile Number: " << s.number << endl;
                cout << "Account Number: " << s.id << endl;
                cout << "Types of account: " << s.type << endl;
                cout << "Current balance: " << s.amount << endl;
                cout << endl;
                found = true;
            }
        }
        return found;
    }

    void depositeMoney(int id)
    {
        queue<Account> temp;
        int sz=person.size();
        int cnt=0;
        while (!person.empty())
        {
            Account s = person.front();
            person.pop();
            if (s.id == id)
            {
                Account depoData;
                int a;
                cout<<"Enter how much money you want to deposite : ";
                cin>>a;
                s.amount+=a;
                cout<<"Total amount you deposite : "<<a<<endl<<endl;

                depoData.name=s.name;
                depoData.address=s.address;
                depoData.number=s.number;
                depoData.amount=s.amount;
                depoData.id=s.id;
                depoData.type=s.type;

                s = depoData;
                cnt++;
            }
            temp.push(s);
        }
        if(cnt==0)
        {
            cout << "Sorry!....The account number is wrong." << endl<<endl;
        }
        person = temp;
    }

    void withdrawMoney(int id)
    {
        queue<Account> temp;
        int sz=person.size();
        int cnt=0;
        while (!person.empty())
        {
            Account s = person.front();
            person.pop();

            if (s.id == id)
            {
                Account depoData;
                int a;
                cout<<"Enter how much money you want to withdraw : ";
                cin>>a;
                if(s.amount<a)
                {
                    cout<<"Sorry..your balance is insufficiant"<<endl<<endl;
                    cnt++;
                }
                else
                {
                    s.amount-=a;
                    cout<<"Total amount you withdraw : "<<a<<" from account num : "<<id<<endl<<endl;
                    depoData.name=s.name;
                    depoData.address=s.address;
                    depoData.number=s.number;
                    depoData.amount=s.amount;
                    depoData.id=s.id;
                    depoData.type=s.type;

                    s = depoData;
                    cnt++;
                }
            }
            temp.push(s);
        }
        if(cnt==0)
        {
            cout << "Sorry!....The account number is wrong." << endl<<endl;
        }
        person = temp;
    }

    void deleteAccount(int id)
    {
        queue<Account> temp;
        int sz=person.size();
        while (!person.empty())
        {
            Account s = person.front();
            person.pop();

            if (s.id != id)
            {
                temp.push(s);
            }
        }

        if (sz == temp.size())
        {
            person = temp;
            cout << "Account Number " << id << " not found." << endl<<endl;
        }
        else
        {
            person = temp;
            cout << "Account deleted." << endl<<endl;
        }
    }

    void updateAccount(int id)
    {
        queue<Account> temp;
        int cnt=0;
        while (!person.empty())
        {
            Account s = person.front();
            person.pop();

            if (s.id == id)
            {
                Account newData;
                cout << "Enter new data....." << endl;

                cout << "Enter Account name: ";
                cin.ignore();
                getline(cin, newData.name);

                cout << "Enter Address: ";
                getline(cin, newData.address);

                cout << "Enter your mobile number : ";
                cin >> newData.number;

                newData.amount=s.amount;
                newData.id=s.id;
                newData.type=s.type;

                s = newData;
                cnt++;

                cout << "Account updated." << endl<<endl;
            }
            temp.push(s);
        }
        if(cnt==0)
        {
            cout << "Sorry!....The account number is wrong." << endl<<endl;
        }
        person = temp;
    }
};

int main()
{
    BankManagement db;

    cout<<"\t\t****************************************************************\n";
    cout<<"\t\t **                 Bank Management Project                  **\n";
    cout<<"\t\t****************************************************************\n\n";

    while (true)
    {
        cout << "                Control Panel\n\n";
        cout << "                1. Open Account" << endl;
        cout << "                2. Show All Accounts" << endl;
        cout << "                3. Search Accounts" << endl;
        cout << "                4. Deposite Money" << endl;
        cout << "                5. Withdraw Money" << endl;
        cout << "                6. Update Accounts" << endl;
        cout << "                7. Delete Accounts" << endl;
        cout << "                8. Exit" << endl<<endl;

        int choice;
        cout<<"Press the key your choice : ";
        cin >> choice;
        cout<<endl;

        if (choice == 1)
        {
            db.openAccount();
        }
        else if (choice == 2)
        {
            db.showAll();
        }
        else if (choice == 3)
        {
            int id;
            cout << "Enter Account Number to search: ";
            cin >> id;
            if (db.search(id))
            {
                cout << "Account found." << endl<<endl;
            }
            else
            {
                cout << "Account not found." << endl<<endl;
            }
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter Account Number to deposite: ";
            cin >> id;
            db.depositeMoney(id);
        }
        else if (choice == 5)
        {
            int id;
            cout << "Enter Account Number to Withdraw: ";
            cin >> id;
            db.withdrawMoney(id);
        }
        else if (choice == 6)
        {
            int id;
            cout << "Enter Account Number for update: ";
            cin >> id;
            db.updateAccount(id);
        }
        else if (choice == 7)
        {
            int id;
            cout << "Enter account number to delete: ";
            cin >> id;
            db.deleteAccount(id);
        }
        else if (choice == 8)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl<<endl;
        }
    }
    return 0;
}

