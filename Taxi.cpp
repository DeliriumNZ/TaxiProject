#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Calling all functions first
void Registration();			//Nathan - DONE

//User Functions
void Login_U();					//Nathan - DONE
void Portal_U();				//Nathan - DONE
void BookTrip_U();				//Henry	 - DONE
void ViewTrip_U();				//Nathan - NOT DONE
void CalcTrip_U();				//Henry - NOT DONE
void Complaint_U();				//Henry - DONE
void LostFound_U();				//Henry - NOT DONE

//Admin Functions
void Login_A();					//Nathan - DONE
void Portal_A();				//Nathan - DONE
void RegisteredCustomers_A();	//Michal - DONE
void DriversMenu_A();			//Michal - DONE
void See_Drivers();				//Michal - DONE
void Add_Driver();				//Michal - DONE
void Delete_Driver();			//Michal - DONE
void BookedTrips_A();			//Michal - DONE
void LostFound_A();				//Michal - DONE
void See_LostFound();			//Michal - DONE
void Add_Item();				//Michal - DONE
void Delete_Item();				//Michal - DONE
void Complaints_A();			//Michal - DONE

//End of function calls

int main() //Nathan
{
	int Option;
	cout << "|-\tTAIX SYSTEM\t-|\n\n" << endl;
	cout << "| Press 1 to USER LOGIN" << endl;
	cout << "| Press 2 to ADMIN LOGIN" << endl;
	cout << "| Press 3 to REGISTER" << endl;
	cout << "| Press 4 to EXIT" << endl;
	cout << "\n\t Option: ";
	cin >> Option;
	cout << endl;

	switch (Option)
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
		cout << "Closing application...\n";
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

	while (strcmp (New_Name, Current_Name))
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

	while (strcmp(Login_Name,User_Name))		//
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
	int Option;
	cout << "| Press 1 to - Book a trip	" << endl;
	cout << "| Press 2 to - View booked trips" << endl;
	cout << "| Press 3 to - Cal Trip" << endl; //WIP
	cout << "| Press 4 to - Submit a complaint" << endl;
	cout << "| Press 5 to - See Lost & Found" << endl;
	cout << "| Press 6 to - Logout" << endl;
	cout << "\n\n\t Option: ";
	cin >> Option;
	cout << endl;
	switch (Option)
	{
	case 1:
		system("cls");
		BookTrip_U();
		break;
	case 2:
		system("cls");
		ViewTrip_U();
		break;
	case 3:
		system("cls");
		Portal_A();
	case 4:
		system("cls");
		Complaint_U();
		break;
	case 5:
		system("cls");
		LostFound_U();
		break;
	case 6:
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
string Name, PickUp, DropOff, Date;
	int Time, Day, Month, Year;

	cout << "\t| User Taxi Portal - Book a Trip |\n\n" << endl;
	cout << "| Please enter the follow details...\n";
	cout << "| Customer Name: ";
	cin >> Name;
	cout << "| Date (ddmmyyyy): " << endl;
	cout << "| Day: ";
	cin >> Day;
	cout << "| Month: ";
	cin >> Month;
	cout << "| Year: ";
	cin >> Year;
	cout << "| Time (1530): ";
	cin >> Time;
	cin.ignore();
	cout << "| Pick up location: ";
	getline(cin, PickUp);
	cout << "| Drop off location: ";
	getline(cin, DropOff);
	cout << "\n| Is this information correct?\n| Enter Y to confirm or N to re enter: ";
	char info;
	cin >> info;
	if (info == 'y' || info == 'Y')
	{
		ofstream BookedTrips("BookedTrips.txt", ios::app);
		BookedTrips << "=======" << endl;
		BookedTrips << " NAME: " << Name << endl;
		BookedTrips << " DATE: " << Day << "/" << Month << "/" << Year << endl;
		BookedTrips << " TIME: " << Time << endl;
		BookedTrips << " Pick up Location: " << PickUp << endl;
		BookedTrips << " Drop off Location: " << DropOff << endl;
		BookedTrips << "=======" << endl;
		BookedTrips.close();
		system("cls");
		cout << "Trip Booked";
		Portal_U();
	}
	else
	{
		system("cls");
		BookTrip_U();
	}

}
void ViewTrip_U()
{
	//WIP Nathan doing (badly hahaha)
	char Line[1000];
	int i = 0;
	char Input_Name[20];
	char Find_Name[20];
	string Test;

	ifstream Open("BookedTrips.txt", ios::in);
	if (!Open)
	{
		system("cls");
		cout << "\t| Message Feed |\n\n" << endl;
		cout << "Input file failed to open\n";
		Portal_A();
	}

	system("cls");
	cout << "\t| View Booked Trips |\n\n" << endl;
	cout << "Enter your user name: ";
	cin >> Input_Name;

	while (strcmp (Input_Name, Find_Name))
	{
		Open >> Find_Name;
		if (Open.eof())
		{
			system("cls");
			cout << "\t| Message Feed |\n\n" << endl;
			cout << "	* User name not found!\n\n";
			Portal_U();
		}
		
	}

	if (Open.is_open())
	{

		Open >> Test;
		cout << Test << endl;
		system("pause");
	}


	
}
void CalcTrip_U()//Henry
{

}
void Complaint_U()//Henry
{
string NameUser, NameDriver;
	string Complaint;
	int Day, Month, Year;

	cout << "\t| User Taxi Portal - Submit a Complaint |\n\n" << endl;
	cout << "| Please enter the follow details...\n";
	cout << "| Customer Name: ";
	cin >> NameUser;
	cout << "| Driver Name: ";
	cin >> NameDriver;
	cout << "| Date (ddmmyyyy): " << endl;
	cout << "| Day: ";
	cin >> Day;
	cout << "| Month: ";
	cin >> Month;
	cout << "| Year: ";
	cin >> Year;
	cin.ignore();
	cout << "|Complaint: " << endl;
	getline(cin, Complaint);

	cout << "\n| Is this information correct?\n| Enter Y to confirm or N to re enter: ";
	char info;
	cin >> info;
	if (info == 'y' || info == 'Y')
	{
		ofstream Complaints("Complaints.txt", ios::app);
		Complaints << "=======" << endl;
		Complaints << " Customer Name: " << NameUser << endl;
		Complaints << " Driver Name: " << NameDriver << endl;
		Complaints << " Date: " << Day << "/" << Month << "/" << Year << endl;
		Complaints << " Complaint: " << Complaint << endl;
		Complaints << "=======" << endl;
		system("cls");
		cout << "Complaint Sent";
		Portal_U();
	}
	else
	{
		system("cls");
		Complaint_U();
	}

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
	int Option;

	cout << "\t| Admin Portal	|\n\n" << endl;
	cout << "| Press 1 to - See Registered Customers" << endl;
	cout << "| Press 2 to - Add or Remove Drivers" << endl;
	cout << "| Press 3 to - See all Booked Trips" << endl;
	cout << "| Press 4 to - Add to Lost & Found" << endl;
	cout << "| Press 5 to - See Complaints" << endl;
	cout << "| Press 6 to - Logout" << endl;
	cout << "\n\t Option: ";
	cin >> Option;
	cout << endl;

	switch (Option)
	{
	case 1:
		system("cls");
		RegisteredCustomers_A();
	case 2:
		system("cls");
		DriversMenu_A();
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
fstream myFile;
		myFile.open ("Records.txt", ios::in); 
		cout << "All registered customers:\n\n";
		if (myFile.is_open()) 
		{
			string Line;
			while (getline(myFile, Line))
			{
				cout << Line << endl;
			}
			myFile.close();
			system("pause");
			system("cls");
			Portal_A();
		}
}
void DriversMenu_A()//Michal
{
	int Option;

	cout << "\t| Drivers Portal|\n\n" << endl;
	cout << "| Press 1 to - View Registered Drivers" << endl;
	cout << "| Press 2 to - Add Drivers" << endl;
	cout << "| Press 3 to - Remove Drivers" << endl;
	cout << "| Press 4 to - Main Menu" << endl;
	cout << "\n\t Option: ";
	cin >> Option;
	cout << endl;

	switch (Option)
	{
	case 1:
		system("cls");
		See_Drivers();

	case 2:
		system("cls");
		Add_Driver();

	case 3:
		system("cls");
		Delete_Driver();

	case 4:
		system("cls");
		Portal_A();

	default:
		system("cls");
		cout << "Please pick a valid option." << endl;
	}
}
void See_Drivers() 
{
	fstream myFile;
		myFile.open ("Drivers.txt", ios::in); 
		cout << "\t| Drivers Portal|\n\n" << endl;
		cout << "Avaliable Drivers:\n\n";
		if (myFile.is_open()) 
		{
			string Line;
			while (getline(myFile, Line))
			{
				cout << Line << endl;
			}
			myFile.close();
			system("pause");
			system("cls");
			DriversMenu_A();
		}
}
void Add_Driver() 
{
	fstream myFile;
		string Line;
		cout << "\t| Drivers Portal|\n\n" << endl;
		cout << "Driver name: ";
		cin.ignore(); 
		getline(cin, Line);
		myFile.open ("Drivers.txt", ios::app); 
		if (myFile.is_open())
		{
			myFile << Line << endl;
		}
		myFile.close();
		system("cls");
		cout << "\t| Message Feed |\n" << endl;
		cout << "New driver added\n\n";
		DriversMenu_A();
}
void Delete_Driver()
{
	string Delete_Line, Line;

	ifstream In ("Drivers.txt");
	if (!In.is_open())
	{
		system("cls");
		cout << "\t| Message Feed |\n\n" << endl;
		cout << "Input file failed to open\n";
		DriversMenu_A();
	}

	ofstream Out("outfile.txt");
	cout << "\t| Drivers Portal|\n" << endl;
	cout << "Enter the drivers name: ";
	cin.ignore(); 
	getline(cin, Delete_Line);
	while (getline(In, Line))
	{
		if (Line != Delete_Line)
		Out << Line << endl;
	}
	In.close();
	Out.close();
	remove("Drivers.txt");
	rename ("outfile.txt", "Drivers.txt");
	system("cls");
	cout << "\t| Message Feed |\n" << endl;
	cout << "Selected driver has been deleted.\n\n" << endl;
	DriversMenu_A();
}

void BookedTrips_A()//Michal
{
fstream myFile;
		myFile.open ("BookedTrips.txt", ios::in); 
		cout << "All booked trips:\n\n";

		cout << "\t| View the booked trips |\n\n" << endl;
		cout << "Booked Trips:\n\n";
		if (myFile.is_open()) 
		{
			string Line;
			while (getline(myFile, Line))
			{
				cout << Line << endl;
			}
			myFile.close();
			system("pause");
			system("cls");
			Portal_A();
		}
}
void LostFound_A()//Michal
{
int Option;

	cout << "\t|LOST AND FOUND PORTAL|\n\n" << endl;
	cout << "| Press 1 to - View all Lost&Found items" << endl;
	cout << "| Press 2 to - Add item" << endl;
	cout << "| Press 3 to - Remove item" << endl;
	cout << "| Press 4 to - Back to Admin Portal" << endl;
	cout << "\n\t Option: ";
	cin >> Option;
	cout << endl;

	switch (Option)
	{
	case 1:
		system("cls");
		See_LostFound();

	case 2:
		system("cls");
		Add_Item();

	case 3:
		system("cls");
		Delete_Item();

	case 4:
		system("cls");
		Portal_A();

	default:
		system("cls");
		cout << "Please pick a valid option." << endl;
	}
}
void See_LostFound()
{
	fstream myFile;
		myFile.open ("LostAndFound.txt", ios::in); 
		cout << "\t| LostAndFound Portal|\n\n" << endl;
		cout << "Lost and Found Items:\n\n";
		if (myFile.is_open()) 
		{
			string Line;
			while (getline(myFile, Line))
			{
				cout << Line << endl;
			}
			myFile.close();
			system("pause");
			system("cls");
			LostFound_A();
		}
}

void Add_Item()
{
fstream myFile;
		string Line, Dname, LostItem;
		cout << "\t| Lost and Found Portal|\n\n" << endl;
		cout << "Item name: ";
		cin >> LostItem;
		LostItem = LostItem + " ";
		cout << "Driver name: ";
		cin >> Dname;
		Line = LostItem + Dname;
		myFile.open ("LostAndFound.txt", ios::app); 
		if (myFile.is_open())
		{
			myFile << Line << endl;
		}
		myFile.close();
		system("cls");
		cout << "\t| Message Feed |\n" << endl;
		cout << "New Item Added to Lost And Found\n\n";
		LostFound_A();
}

void Delete_Item()
{
string Delete_Line, Line, LostItem, Dname;

	ifstream In ("LostAndFound.txt");
	if (!In.is_open())
	{
		system("cls");
		cout << "\t| Message Feed |\n\n" << endl;
		cout << "Input file failed to open\n";
		DriversMenu_A();
	}

	ofstream Out("outfile.txt");
	cout << "\t| Lost and Found Portal|\n" << endl;
	cout << "Item name: ";
	cin >> LostItem;
	LostItem = LostItem + " ";
	cout << "Driver name: ";
	cin >> Dname;
	Delete_Line = LostItem + Dname;
	while (getline(In, Line))
	{
		if (Line != Delete_Line)
		Out << Line << endl;
	}
	In.close();
	Out.close();
	remove("LostAndFound.txt");
	rename ("outfile.txt", "LostAndFound.txt");
	system("cls");
	cout << "\t| Message Feed |\n" << endl;
	cout << "Selected item has been deleted.\n\n" << endl;
	LostFound_A();
}

void Complaints_A()//Michal
{
fstream myFile;
		myFile.open ("Complaints.txt", ios::in); 
		cout << "All customer complaints:\n\n";
		if (myFile.is_open()) 
		{
			string Line;
			while (getline(myFile, Line))
			{
				cout << Line << endl;
			}
			myFile.close();
			system("pause");
			system("cls");
			Portal_A();
		}
}