#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Calling all functions first
void Registration();			//Nathan - DONE
//User Functions
void Login_U();					//Nathan - DONE
void Portal_U();				//Nathan - DONE
void BookTrip_U();				//Henry - NOT DONE
void CalcTrip_U();				//Henry - NOT DONE
void Complaint_U();				//Henry - NOT DONE
void LostFound_U();				//Henry - NOT DONE
//Admin Functions
void Login_A();					//Nathan - DONE
void Portal_A();				//Nathan - DONE
void RegisteredCustomers_A();	//Michal - NOT DONE
void Drivers_A();				//Michal - NOT DONE
void BookedTrips_A();			//Michal - NOT DONE
void LostFound_A();				//Michal - NOT DONE
void Complaints_A();			//Michal - NOT DONE
//End of function calls

int main() //Nathan
{
	int op;
	cout << "|-\tTAIX SYSTEM\t-|\n\n" << endl;
	cout << "| Press 1 to USER LOGIN" << endl;
	cout << "| Press 2 to ADMIN LOGIN" << endl;
	cout << "| Press 3 to REGISTER" << endl;
	cout << "| Press 4 to EXIT" << endl;
	cout << "\n\t Option: ";
	cin >> op;
	cout << endl;

	switch (op)
	{
	case 1:
		Login_U();
		break;

	case 2:
		Login_A();
		break;

	case 3:
		Registration();
		break;

	case 4:
		cout << "Cloing application...\n";
		system("pause");
		exit(0);

	default:
		cout << "Please pick a valid option." << endl;
		main();
	}
}
void Registration() //Nathan
{
	char New_Name[20];
	char New_Pass[20];
	char Current_Name[20];

	fstream View("Records.txt", ios::app);
	if (!View)		//Checks to see if file did not open
	{
		cout << "\t| Message Feed |\n" << endl;
		cout << "Login data file was not loaded..." << endl;
		main();
	}

	system("cls");
	cout << "\t| Registration Menu |\n\n" << endl;
	cout << "User Name: ";
	cin >> New_Name;

	while (strcmp(New_Name, Current_Name))
	{
		View >> Current_Name;		//If name not taken, allows password to be entered
		if (View.eof())
		{
			cout << "Password: ";
			cin >> New_Pass;
			ofstream Write("Records.txt", ios::app);//Opens Records file and adds a new line with iso::app
			Write << New_Name << " " << New_Pass << endl;
			Write.close();
			system("cls");
			cout << "\t| Message Feed |\n" << endl;
			cout << "   * Registration Successful!\n\n" << endl;
			main();
		}
	}
	//If Name taken show error and goto main menu
	system("cls");
	cout << "\t| Message Feed |\n" << endl;
	cout << "   * Sorry Name Taken\n\n" << endl;
	main();
}


//User Functions:
void Login_U()//Nathan
{
	char Login_Name[20];		//User Input
	char Login_Pass[20];		//User Input
	char User_Name[20];			//Checking Stored
	char User_Pass[20];			//Checking Stored

	fstream View("Records.txt", ios::in);		//Opens Records File
	if (!View)		//Checks to see if file did not open
	{
		cout << "\t| Message Feed |\n" << endl;
		cout << "Login data file was not loaded..." << endl;
		main();
	}

	system("cls");
	cout << "\t| Login Menu |\n\n" << endl;
	cout << "User Name: ";
	cin >> Login_Name;

	while (strcmp(Login_Name, User_Name))		//
	{
		View >> User_Name;
		if (View.eof())		//If end of file & name not found show error
		{
			system("cls");
			cout << "\t| Message Feed |\n" << endl;
			cout << "   * User name not found!\n\n" << endl;
			main();
		}
	}
	View >> User_Pass;
	cout << "Password: ";
	cin >> Login_Pass;
	while (strcmp(User_Pass, Login_Pass))		//If password wrong show error
	{
		system("cls");
		cout << "\t| Message Feed |\n" << endl;
		cout << "   * Incorrect Password!\n\n" << endl;
		main();
	}

	//If name and pass correct then go to user menu
	system("cls");
	cout << "\t| Message Feed |\n" << endl;
	cout << "   * Login successful!\n\n" << endl;
	Portal_U();
}
void Portal_U()
{
	cout << "\t| User Taxi Portal |\n\n" << endl;
	int op;
	cout << "| Press 1 to - Book a trip	" << endl;
	cout << "| Press 2 to - View booked trips" << endl;
	cout << "| Press 3 to - Submit a complaint" << endl;
	cout << "| Press 4 to - See Lost & Found" << endl;
	cout << "| Press 5 to - Logout" << endl;
	cout << "\n\n\t Option: ";
	cin >> op;
	cout << endl;
	switch (op)
	{
	case 1:
		system("cls");
		BookTrip_U();
		break;
	case 2:
		system("cls");
		CalcTrip_U();
		break;
	case 3:
		system("cls");
		Complaint_U();
		break;
	case 4:
		system("cls");
		LostFound_U();
		break;
	case 5:
		system("cls");
		main();
		break;
	default:
		cout << "Please pick a valid option." << endl;
		Portal_A();
	}
}
void BookTrip_U()//Henry
{

}
void CalcTrip_U()//Henry
{

}
void Complaint_U()//Henry
{

}
void LostFound_U()//Henry
{

}

//Admin Functions
void Login_A()//Nathan
{
	string UserID, UserPassword;
	system("cls");
	cout << "\t| Admin Portal Login |\n\n" << endl;
	cout << "User Name: ";
	cin >> UserID;
	cout << "Password: ";
	cin >> UserPassword;

	if (UserID == "ADMIN" && UserPassword == "ADMINPASSWORD")
	{
		system("cls");
		Portal_A();
	}
	else
	{
		system("cls");
		cout << "Incorrect User Name and or Password!\n\n" << endl;
		main();
	}
}
void Portal_A()//Nathan
{
	int op;

	cout << "\t| Admin Portal	|\n\n" << endl;
	cout << "| Press 1 to - See Registered Customers" << endl;
	cout << "| Press 2 to - Add or Remove Drivers" << endl;
	cout << "| Press 3 to - See all Booked Trips" << endl;
	cout << "| Press 4 to - Add to Lost & Found" << endl;
	cout << "| Press 5 to - See Complants" << endl;
	cout << "| Press 6 to - Logout" << endl;
	cout << "\n\t Option: ";
	cin >> op;
	cout << endl;

	switch (op)
	{
	case 1:
		system("cls");
		RegisteredCustomers_A();
	case 2:
		system("cls");
		Drivers_A();
	case 3:
		system("cls");
		BookedTrips_A();
	case 4:
		system("cls");
		LostFound_A();
	case 5:
		system("cls");
		Complaints_A();
	case 6:
		system("cls");
		main();
	default:
		cout << "Please pick a valid option." << endl;
	}
}
void RegisteredCustomers_A()//Michal
{

}
void Drivers_A()//Michal
{

}
void BookedTrips_A()//Michal
{

}
void LostFound_A()//Michal
{

}
void Complaints_A()//Michal
{

}