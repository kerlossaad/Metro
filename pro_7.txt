
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

ifstream in_file ("in.7", ios::in);
ofstream out_file ("out.7", ios::out);

using namespace std;

class CCNY_TRANSPORT_GEN_1{
   public:   
	CCNY_TRANSPORT_GEN_1(string); // constructor
	void USER_INPUT_HANDLER(); // a method
	//public utility func:
	int read_system_input();
	void print_welcome();
	void print_menu(); 
	void get_schedule(); 
	void purchase_ticket();
	void print_ticket(int, int, int);


private:
	void print_zones();
	int check_station(int);
	string KIOSK_NAME; 
	string USER_NAME; 
	int NOOF_STATIONS;
	int NOOF_TRIPS;
	string STATION_NAMES[10]; // 10 max
	int STATION_CODES[10]; // 10 max
	float SOUTH_BOUND_DEPARTURES[10][25]; // 10 max, each with 25 max
	float NORTH_BOUND_DEPARTURES[10][25]; // 10 max, each with 25 max
};

CCNY_TRANSPORT_GEN_1::CCNY_TRANSPORT_GEN_1(string s)
{
	int RET_VAL;

	KIOSK_NAME = s;
	RET_VAL = read_system_input();
	if(RET_VAL == 1)
	{
		print_welcome();
	}
	else
	{
		cout << " INPUT ERROR IN SYSTEM INPUT DATA. EXITING!" << endl;
		out_file << " INPUT ERROR IN SYSTEM INPUT DATA. EXITING!" << endl;
	}
	
}

int 
CCNY_TRANSPORT_GEN_1::read_system_input()
{
	//YOUR CODE GOES HERE
	int i, j;
	string DIRECTION;	
		
		in_file >> NOOF_STATIONS >> NOOF_TRIPS;

		for ( i=0; i<NOOF_STATIONS; i++)
		{
				in_file >> STATION_NAMES[i] >> STATION_CODES[i];
				
				in_file >> DIRECTION;

				if(DIRECTION == "SOUTH-BOUND")
				{
						for(j=0; j<NOOF_TRIPS; j++)
						{
								in_file >> SOUTH_BOUND_DEPARTURES[i][j];
						}
				}

				in_file >> DIRECTION;
		
				if(DIRECTION == "NORTH-BOUND")
				{
						for(j=0; j<NOOF_TRIPS; j++)
						{
								in_file >> NORTH_BOUND_DEPARTURES[i][j];
						}
				}
		}
		return 1;
}
void
CCNY_TRANSPORT_GEN_1::print_menu()
{
	//YOUR CODE GOES HERE
			 
		cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
		cout<<"/*\\                           /*\\"<<endl; 
		cout<<"\\*/	 PRESS 1 TO GET SCHEDULE         \\*/"<<endl; 
		cout<<"/*\\	 PRESS 2 TO PURCHASE A TICKET    /*\\"<<endl;
		cout<<"\\*/                           \\*/"<<endl; 
		cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 

		out_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		out_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
		out_file<<"/*\\                           /*\\"<<endl; 
		out_file<<"\\*/	 PRESS 1 TO GET SCHEDULE         \\*/"<<endl; 
		out_file<<"/*\\	 PRESS 2 TO PURCHASE A TICKET    /*\\"<<endl;
		out_file<<"\\*/                           \\*/"<<endl; 
		out_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		out_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 

}
void 
CCNY_TRANSPORT_GEN_1::USER_INPUT_HANDLER()
{
	//YOUR CODE GOES HERE
int CHOICE;

		cout<<"WHAT IS YOUR NAME? "<<endl;
		out_file<<"WHAT IS YOUR NAME? "<<endl;
			
		cin >> USER_NAME;

		cout<<"HELLO "<< USER_NAME <<", HERE IS THE MENU: "<<endl;
		out_file<<"HELLO "<< USER_NAME <<", HERE IS THE MENU: "<<endl;

		print_menu();
	
		cout<<"ENTER YOUR SELECTION, "<< USER_NAME <<endl; 
		out_file<<"ENTER YOUR SELECTION, "<< USER_NAME <<endl; 

		cin >> CHOICE;
		
		if(CHOICE == 1)
		{
				get_schedule();

		}
		else if (CHOICE ==2 )
		{
		
				purchase_ticket();
		
		}
		else{
			  cout<< CHOICE <<" IS AN ILLEGAL ENTRY "<<endl;
			  out_file<< CHOICE <<" IS AN ILLEGAL ENTRY "<<endl;

		}





}
void
CCNY_TRANSPORT_GEN_1::print_welcome()
{
	// YOUR CODE GOES BELOW:
		cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
		cout<<"/*\\                                     /*\\"<<endl; 
		cout<<"\\*/	 WELCOME TO CCNY TRANSIT BUS    \\*/"<<endl; 
		cout<<"/*\\	 THE CHEAPEST WAY TO COMMUTE    /*\\"<<endl; 
		cout<<"\\*/                                     \\*/"<<endl; 
		cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 

		out_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		out_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
		out_file<<"/*\\                           /*\\"<<endl; 
		out_file<<"\\*/	 WELCOME TO CCNY TRANSIT BUS     \\*/"<<endl; 
		out_file<<"/*\\	 THE CHEAPEST WAY TO COMMUTE     /*\\"<<endl; 
		out_file<<"\\*/                           \\*/"<<endl; 
		out_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		out_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
}
void
CCNY_TRANSPORT_GEN_1::get_schedule()
{

	// YOUR CODE GOES BELOW:
int ORIGIN;	
int STATION_INDEX;	
int i, j;

	print_zones();

	cout<<"ENTER ORIGIN CODE: "<<endl;
	out_file<<"ENTER ORIGIN CODE: "<<endl;
	
	cin >> ORIGIN;

	STATION_INDEX = check_station(ORIGIN);
	
	if( STATION_INDEX != -1)
	{
				cout<<"STARTING FROM "<< STATION_NAMES[STATION_INDEX] <<", SOUTH-BOUND DEPARTURES: "<<endl;
				out_file<<"STARTING FROM "<< STATION_NAMES[STATION_INDEX] <<", SOUTH-BOUND DEPARTURES: "<<endl;

				for( j=0; j<NOOF_TRIPS; j++)
				{
						cout<<setprecision(2)<<fixed<<SOUTH_BOUND_DEPARTURES[STATION_INDEX][j]<<" ";
						out_file<<setprecision(2)<<fixed<<SOUTH_BOUND_DEPARTURES[STATION_INDEX][j]<<" ";
				}

				cout<<" "<<endl;
				out_file<<" "<<endl;
				cout<<"STARTING FROM "<< STATION_NAMES[STATION_INDEX] <<", NORTH-BOUND DEPARTURES: "<<endl;
				out_file<<"STARTING FROM "<< STATION_NAMES[STATION_INDEX] <<", NORTH-BOUND DEPARTURES: "<<endl;

				for( i=0; i<NOOF_TRIPS; i++)
				{
						cout<<setprecision(2)<<fixed<<NORTH_BOUND_DEPARTURES[STATION_INDEX][i]<<" ";
						out_file<<setprecision(2)<<fixed<<NORTH_BOUND_DEPARTURES[STATION_INDEX][i]<<" ";
				}
				cout<<" "<<endl;
				out_file<<" "<<endl;
	
	}
	else {
				cout<< ORIGIN <<"IS AN ILLEGAL ENTRY "<<endl;
				out_file<< ORIGIN <<"IS AN ILLEGAL ENTRY "<<endl;
	
	}






}
void
CCNY_TRANSPORT_GEN_1::purchase_ticket()
{
	// YOUR CODE GOES BELOW:
int CHANGE, FARE;
int MONEY; 
int origin, destination ;
int index_1, index_2;

		print_zones();

		cout<<"ENTER ORIGIN CODE: "<<endl;
		out_file<<"ENTER ORIGIN CODE: "<<endl;
	
		cin >> origin;

		index_1 = check_station(origin);

		cout<<"ENTER DESTINATION CODE: "<<endl;
		out_file<<"ENTER DESTINATION CODE: "<<endl;

		cin >> destination;

		index_2 = check_station(destination);

		if(index_1 != -1 && index_2 != -1 && index_1 != index_2)
		{
				FARE = index_1 - index_2;
				
				if (FARE > 0)
				{}
				else{
					FARE = FARE * -1;
				}
				
				cout<<"YOUR FARE IS "<< FARE <<" USD "<<endl;
				cout<<"PLEASE ENTER YOUR MONEY (MAX 20 USD) "<<endl;
				out_file<<"YOUR FARE IS "<< FARE <<" USD "<<endl;
				out_file<<"PLEASE ENTER YOUR MONEY (MAX 20 USD) "<<endl;
		
				cin >> MONEY; 

						if(MONEY > FARE)
						{
									CHANGE = MONEY -FARE;
							
									cout<<"YOUR CHANGE IS "<< CHANGE <<" USD "<<endl;
									cout<<"YOUR TICKET IS PRINTING "<<endl;
									cout<<"HAVE A NICE TRIP, "<<USER_NAME <<endl;
									out_file<<"YOUR CHANGE IS "<< CHANGE <<" USD "<<endl;
									out_file<<"YOUR TICKET IS PRINTING "<<endl;
									out_file<<"HAVE A NICE TRIP, "<<USER_NAME <<endl;
									
									print_ticket(FARE, index_1, index_2);

						
						}
						else {
								 cout<<" INSUFFICIENT MONEY. RETURNING YOUR "<< MONEY <<" USD "<<endl;
								 out_file<<" INSUFFICIENT MONEY. RETURNING YOUR "<< MONEY <<" USD "<<endl;
						}
		}
		else if( index_1 == index_2 )
		{
			cout<<"ORIGIN AND DESTINATION CANNOT BE THE SAME "<<endl; 
			out_file<<"ORIGIN AND DESTINATION CANNOT BE THE SAME "<<endl; 

		}
		else{
				cout<< origin <<" OR "<< destination <<" OR BOTH ARE ILLEGAL ENTRIES "<<endl;
				out_file<< origin <<" OR "<< destination <<" OR BOTH ARE ILLEGAL ENTRIES "<<endl;
		}


}									
								
void
CCNY_TRANSPORT_GEN_1::print_zones()
{
	// YOUR CODE GOES BELOW:

		cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
		cout<<"/*\\                        /*\\"<<endl; 
		cout<<"\\*/  TRAVEL ZONES:         \\*/"<<endl;
		cout<<"/*\\	 BRONX (111)          /*\\"<<endl;
		cout<<"\\*/  MANHATTAN (222)      \\*/"<<endl;
		cout<<"/*\\  QUEENS (333)         /*\\"<<endl;
 		cout<<"\\*/	 BROOKLYN (444)       \\*/"<<endl; 
        cout<<"/*\\	 STATEN ISLAND (555)   /*\\"<<endl;
		cout<<"\\*/                        \\*/"<<endl; 
		cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 

		out_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		out_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
		out_file<<"/*\\                        /*\\"<<endl; 
		out_file<<"\\*/  TRAVEL ZONES:         \\*/"<<endl;
		out_file<<"/*\\	 BRONX (111)          /*\\"<<endl;
		out_file<<"\\*/  MANHATTAN (222)      \\*/"<<endl;
		out_file<<"/*\\  QUEENS (333)         /*\\"<<endl;
 		out_file<<"\\*/	 BROOKLYN (444)       \\*/"<<endl; 
        out_file<<"/*\\	 STATEN ISLAND (555)   /*\\"<<endl; 
		out_file<<"\\*/                        \\*/"<<endl; 
		out_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
		out_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
}
int
CCNY_TRANSPORT_GEN_1::check_station(int origin)
{
	// YOUR CODE GOES BELOW:
int i;
int FOUND = 0;
int FOUND_POS = -1;

			for( i=0; i<NOOF_STATIONS && FOUND == 0; i++)
			{
						if( STATION_CODES[i] == origin )
						{
								FOUND = 1;
								FOUND_POS = i;
						}
						else {}
			}
			if( FOUND == 1)
			{
				return FOUND_POS;
			}
			else{
				return -1;
			}


}
void
CCNY_TRANSPORT_GEN_1::print_ticket(int price, int start_index, int stop_index)
{

	//YOUR CODE GOES HERE

					

	 cout<<"T*I*C*K*E*T*T*I*C*K*E*T*T*I*C*K*E*T"<<endl;
 	 cout<<"* FROM: "<< STATION_NAMES[start_index] <<endl;
	 cout<<"* TO: "<< STATION_NAMES[stop_index] <<endl;
	 cout<<"* FEE: "<< price <<" USD "<<endl;
	 cout<<"* PURCHASED AT: "<< KIOSK_NAME <<endl;
	 cout<<"T*I*C*K*E*T*T*I*C*K*E*T*T*I*C*K*E*T"<<endl;

	 out_file<<"T*I*C*K*E*T*T*I*C*K*E*T*T*I*C*K*E*T"<<endl;
 	 out_file<<"* FROM: "<< STATION_NAMES[start_index] <<endl;
	 out_file<<"* TO: "<< STATION_NAMES[stop_index] <<endl;
	 out_file<<"* FEE: "<< price <<" USD "<<endl;
	 out_file<<"* PURCHASED AT: "<< KIOSK_NAME <<endl;
	 out_file<<"T*I*C*K*E*T*T*I*C*K*E*T*T*I*C*K*E*T"<<endl;



}
