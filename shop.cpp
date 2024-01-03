// Final work
#include<iostream>
#include<fstream>
#include <ctime>
#include <cstdlib>  // Include the header for rand() function

using namespace std;


class shopping
{
private:
    int pcode;
    float price;
    float discount;
    string pname;

public:
    void menu();
    void administrative();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
    void showRandomWishMessage();
};

void shopping :: menu()
{
m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t====================================\n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t          Main Menu of SHOP         \n";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\t\t\t\t====================================\n";
    cout<<"\t\t\t\t____________________________________\n";
    cout<<"\t\t\t\t************************************\n";
    cout<<"\t\t\t\t                        \n";
    cout<<"\t\t\t\t  |     1) Seller           |\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t  |     2) Buyer            |\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t  |     3) Exit             |\n";
    cout<<"\t\t\t\t                       \n";
    cout<<"\t\t\t\t     ! Please select one ! : ";
    cin>> choice;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t =-- Please Login by email & Password --=\n";
        cout<<"\t\t\t\t                                    \n";
        cout<<"\t\t\t Enter Email  : ";
        cin>> email;
        cout<<"\t\t\t Password     : ";
        cin>> password;

        if(email=="email" && password=="password")
        {
            administrative();
        }
        else
        {
            cout<<"Invalid email/password";
        }
        break;

    case 2:
    {
        buyer();
    }

    case 3:
    {
        exit(0);
    }

    default :
    {
        cout<< "Please select from the given options ";
    }
    }
    goto m;
}

void shopping :: administrative()
{
m:
    int choice;
    cout<<"\n\n\n\t\t\t ***** Administrative menu *****";
    cout<<"\t\t\t\t                                    \n";
    cout<<"\n\t\t\t|        1) Add the new product            |";
    cout<<"\n\t\t\t|                                          |";
    cout<<"\n\t\t\t|        2) Modify the existing product    |";
    cout<<"\n\t\t\t|                                          |";
    cout<<"\n\t\t\t|        3) Delete   product               |";
    cout<<"\n\t\t\t|                                          |";
    cout<<"\n\t\t\t|        4) Back to Shop MAIN MENU         |";

    cout<<"\n\n\t            Please enter your choice : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default  :
        cout<<"Invalid choice. Make your choice among 1-4 !";
    }
    goto m;
}

void shopping :: buyer()
{
m:
    int choice;
    cout<<"\t\t\t                                    \n";
    cout<<"\t\t\t                    $$$ Buyer $$$ \n";
    cout<<"\t\t\t                    +++++++++++++\n";
    cout<<"\t\t\t                                    \n";
    cout<<"\t\t\t                    1) Buy Product \n";
    cout<<"\t\t\t                    2) Go to Shop MAIN MENU     \n";
    cout<<"\t\t\t                                    \n";
    cout<<"\t\t\t                   Enter your choice : ";

    cin>>choice;

    switch(choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default :
        cout<<"Invalid choice";
    }

    goto m;
}

void shopping::add()
{
    fstream data;
    char choice;

    do
    {
        cout << "\n\n\t\t\t        ### Add new product ###";
        cout << "\n\t         Product code of the product : ";
        cin >> pcode;
        cout << "\n\t         Name of the product : ";
        cin >> pname;
        cout << "\n\t         Price of the product :  ";
        cin >> price;
        cout << "\n\t         Discount on product : ";
        cin >> discount;

        data.open("database.txt", ios::in);

        if (!data)
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
            data.close();
        }
        else
        {
            int existingCode;
            string existingName;
            float existingPrice, existingDiscount;


            bool codeExists = false;

            while (data >> existingCode >> existingName >> existingPrice >> existingDiscount)
            {
                if (pcode == existingCode)
                {
                    codeExists = true;
                    break;
                }
            }

            data.close();

            if (codeExists)
            {
                cout << "\n\nDuplicate product code. Please try again!";
            }
            else
            {
                data.open("database.txt", ios::app | ios::out);
                data << " " << pcode << " " << pname << " " << price << " " << discount << "\n";
                data.close();
                cout << "\n\n\t\t:) Record Inserted ! :)";
            }
        }

        cout << "\n\n\t\tDo you want to add another product? Press Y for yes and N for no: ";
        cin >> choice;

    }
    while (choice == 'Y');
}


void shopping :: edit()
{
    fstream data, data1;
    int pkey;
    list();
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t+-+-+ Modify the record +-+-+";
    cout<<"\n\t\t\tEnter the Product code : ";
    cin>>pkey;

    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\n\nNo product with the information doesn't exist! ";
    }
    else
    {

        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t New for the Product : ";
                cin>>c;
                cout<<"\n\t\t New Name of the product : ";
                cin>>n;
                cout<<"\n\t\t New Price : ";
                cin>>p;
                cout<<"\n\t\t New Discount : ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t... Record edited Done. Thank you !!! ...";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();


        remove("database.txt");// Database change hobe
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t No product with the information doesn't exist! \n\t\t Sorry! \n\t\t Do it again .";
        }
    }
}

void shopping :: rem()
{
    fstream data,data1;
    list();
    int pkey;
    int token = 0;
    cout<<"\n\n\t\t--- Delete product ---";
    cout<<"\n\n\t\tEnter the Product code you want to remove : ";
    cin>>pkey;
    data.open("database.txt", ios::in);
    if(!data)
    {
        cout<<"\t\tNo product with the information doesn't exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t\tO_O The Entered Product deleted successfully. Thank you .O_O";
                token++;
            }
            else
            {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t+_+ No product with the information doesn't exist! +_+";
        }
    }
}


void shopping :: list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout<<"\n\n\t\t|___________________________________________________\n";
    cout<<"\t\tProNo\t\tName\t\tPrice\n";
    cout<<"\n\n\t\t|___________________________________________________\n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof())
    {
        cout<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>discount;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float discount = 0;
    float total = 0;

    cout << "\n\n\t\t\t $$$$$$--   Available Product   --$$$$$$";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();

        list();

        cout << "\n\t\t                                       \n";
        cout << "\n\t\t\t                                      \n";
        cout << "\n\t\t\t........................................\n";
        cout << "\n\t\t\t       Please Do Your shopping         \n";
        cout << "\n\t\t\t........................................\n";
        cout << "\n\t\t\t[][][][][][][][][][][][][][][][][][][][]\n";

        do
        {
m:
            cout << "\n\nEnter Product code : ";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity : ";
            cin >> arrq[c];

            bool productFound = false;

            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;

            while (!data.eof())
            {
                if (pcode == arrc[c])
                {
                    productFound = true;
                    amount = price * arrq[c];
                    discount = amount - (amount * discount / 100);

                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[c] << "\t\t" << price << "\t" << amount << "\t\t" << discount;
                }
                data >> pcode >> pname >> price >> discount;
            }

            data.close();

            if (!productFound)
            {
                cout << "\n\n Product with code " << arrc[c] << " not found. Please try again!";
                goto m;
            }

            c++;

            cout << "\n\n Do you want to buy another product? Press Y for yes and N for no : ";
            cin >> choice;

        }
        while (choice == 'Y');

        cout << "\n\n\t\t\t+=+=+=        ____ .... RECEIPT .... ____         +=+=+=+\n";

        cout << "\nProduct No\t Product Name\t Product Quantity\tPrice\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> discount;

            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    discount = amount - (amount * discount / 100);
                    total = total + discount;
                    cout << "\n" << pcode << "\t\t " << pname << "\t\t " << arrq[i] << "\t\t\t" << price << "\t" << amount << "\t\t" << discount;
                }
                data >> pcode >> pname >> price >> discount;
            }

            data.close();
        }
    }

    cout << "\n\n_________________________________________________________________________________________";
    cout << "\n\t\t Total Amount : " << total << "\n";

    // Show a random wish message
    showRandomWishMessage();
}
//// Show a random wish message
void shopping::showRandomWishMessage()
{
    // Array of wish messages
    const char* wishMessages[] =
    {
        "Thank you for shopping with us!",
        "Wishing you a great day!",
        "Hope you enjoy your purchases!",
        "Have a wonderful day!",
        // Add more wish messages as needed
    };

    // Calculate the number of messages in the array
    int numMessages = sizeof(wishMessages) / sizeof(wishMessages[0]);

    // Generate a random index to select a wish message
    int randomIndex = rand() % numMessages;

    // Display the randomly selected wish message
    cout << "\n\n" << "\t\t"<<wishMessages[randomIndex] << "\n";
}


int main()
{
    srand(time(0));  // Seed for random number generation
    shopping s;
    s.menu();
}




