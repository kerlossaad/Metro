
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "sample_pro_7.h"

using namespace std;

ofstream o_file ("out.8", ios::app);

using namespace std;

class CCNY_TRANSPORT_GEN_2:public CCNY_TRANSPORT_GEN_1{
   public:   
	CCNY_TRANSPORT_GEN_2(string); // constructor
	void USER_INPUT_HANDLER_2(); // a method
	//public utility func:
	void print_menu_2(); 
	void purchase_metrocard();
	void refill_metrocard();

private:
	void print_card(int, string, int);
	string KIOSK_NAME; 
	string USER_NAME; 
	int SERIAL_NUMBER;
	int NOOF_CARDS;
	string CARD_INFO_NAME[20];
	int CARD_INFO_SERIAL_NUMBER[20];
	int CHECK_METROCARD(int, string);
	int CARD_INFO_MONEY[20];
	int update_metrocard(int, int, string);
};

CCNY_TRANSPORT_GEN_2::CCNY_TRANSPORT_GEN_2(string k)
	:CCNY_TRANSPORT_GEN_1(k) // call to base class constructor
{
	KIOSK_NAME = k;

	// the contents of in.7 file are read in sample_pro_7.h by the call
	// to base constructor above; 
	// here, we do not have to read in.7 again since we do not need to access 
	// private data directly;

	// initialize the serial number, which is incremented by one for each 
	// new card purchased in purchase_metrocard() function:
	SERIAL_NUMBER = 1234; 
	NOOF_CARDS = 0;
}

void 
CCNY_TRANSPORT_GEN_2::USER_INPUT_HANDLER_2()
{

	// YOUR CODE GOES BELOW
int USER_CHOICE;

				cout<<" WHAT IS YOUR NAME? "<<endl;
				o_file<<" WHAT IS YOUR NAME? "<<endl;

				cin >> USER_NAME;
				
				cout<<"HELLO "<< USER_NAME <<", HERE IS THE MENU: "<<endl;
				o_file<<"HELLO "<< USER_NAME <<", HERE IS THE MENU: "<<endl;

				print_menu_2();

				cout<<" ENTER YOUR SELECTION "<<endl;
				o_file<<" ENTER YOUR SELECTION "<<endl;
				
				cin >> USER_CHOICE;

				if (USER_CHOICE == 1)
				{
						get_schedule();
				}
				else if( USER_CHOICE == 2)
				{
						purchase_ticket();
				}
				else if( USER_CHOICE == 3)
				{
						purchase_metrocard();
				}
				else if (USER_CHOICE == 4)
				{
						refill_metrocard();
				}
				else {
						cout<< USER_CHOICE <<" IS AN ILLEGAL ENTRY "<<endl;
						out_file<< USER_CHOICE <<" IS AN ILLEGAL ENTRY "<<endl;
				}
						
	
}
void
CCNY_TRANSPORT_GEN_2::print_menu_2()
{
	// YOUR CODE GOES BELOW
     cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
     cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
	   cout<<"/*\\                     /*\\"<<endl; 
		 cout<<"\\*/	 PRESS 1 TO GET SCHEDULE        \\*/"<<endl; 
		 cout<<"/*\\	 PRESS 2 TO PURCHASE A TICKET   /*\\"<<endl;
	   cout<<"\\*/      PRESS 3 FOR NEW METROCARD      \\*/"<<endl; 
     cout<<"/*\\      PRESS 4 FOR REFILL METROCARD   /*\\"<<endl;
		 cout<<"\\*/	                  \\*/"<<endl;
		 cout<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
     cout<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 

     o_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
     o_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
	   o_file<<"/*\\                                     /*\\"<<endl; 
		 o_file<<"\\*/	 PRESS 1 TO GET SCHEDULE         \\*/"<<endl; 
		 o_file<<"/*\\	 PRESS 2 TO PURCHASE A TICKET    /*\\"<<endl;
	   o_file<<"\\*/   PRESS 3 FOR NEW METROCARD       \\*/"<<endl; 
     o_file<<"/*\\   PRESS 4 FOR REFILL METROCARD    /*\\"<<endl;
	   o_file<<"\\*/                                     \\*/"<<endl; 
     o_file<<"/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\"<<endl; 
     o_file<<"\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/*\\*/"<<endl; 
	

}

void
CCNY_TRANSPORT_GEN_2::purchase_metrocard()
{
	
	// YOUR CODE GOES BELOW
int LOAD;
int MONEY;
int CHANGE;



		cout<<"HOW MUCH YOU WANT TO LOAD (MAX 20 USD)"<<endl; 
		cout<<"(THERE IS A ONE-TIME 5 USD FEE FOR NEW CARDS)"<<endl; 
		o_file<<"HOW MUCH YOU WANT TO LOAD (MAX 20 USD)"<<endl; 
		o_file<<"(THERE IS A ONE-TIME 5 USD FEE FOR NEW CARDS)"<<endl; 

		cin >>  LOAD;
	
		if ( LOAD > 20 || LOAD < 1 )
		{
			cout<< LOAD <<" IS AN ILLEGAL ENTRY "<<endl;
			o_file<< LOAD <<" IS AN ILLEGAL ENTRY "<<endl;
		}
		else {
				
				cout<<" PLEASE ENTER YOUR MONEY (MAX 20 USD) "<<endl; 
				o_file<<" PLEASE ENTER YOUR MONEY (MAX 20 USD) "<<endl; 
			
				cin >> MONEY;

				if ( MONEY < 1)
				{

							cout<< MONEY <<" IS AN ILLEGAL ENTRY "<<endl;
							o_file<< MONEY <<" IS AN ILLEGAL ENTRY "<<endl;
				}
				else {

							if ( MONEY >= (LOAD + 5) )
							{
								
								CHANGE = MONEY - ( LOAD + 5 );

								cout<<"YOUR CHANGE IS "<< CHANGE <<" USD "<<endl;
								cout<<"YOUR METROCARD IS PRINTING "<<endl;
								cout<<"HERE IS YOUR METROCARD: "<<endl;
								o_file<<"YOUR CHANGE IS "<< CHANGE <<" USD "<<endl;
								o_file<<"YOUR METROCARD IS PRINTING "<<endl;
								o_file<<"HERE IS YOUR METROCARD: "<<endl;

								CARD_INFO_NAME[NOOF_CARDS] = USER_NAME;
								CARD_INFO_MONEY[NOOF_CARDS] = LOAD;
								CARD_INFO_SERIAL_NUMBER[NOOF_CARDS] =SERIAL_NUMBER;

								print_card(CARD_INFO_SERIAL_NUMBER[NOOF_CARDS], CARD_INFO_NAME[NOOF_CARDS], CARD_INFO_MONEY[NOOF_CARDS]);
								
								SERIAL_NUMBER++;
								NOOF_CARDS++;
							}
							else {
								cout<<" INSUFFICIENT MONEY. RETURNING YOUR "<< MONEY <<" USD "<<endl;
								o_file<<" INSUFFICIENT MONEY. RETURNING YOUR "<< MONEY <<" USD "<<endl;
							}
				}
		}
}
void
CCNY_TRANSPORT_GEN_2::refill_metrocard()
{
	// YOUR CODE GOES BELOW
int i;
int LOAD, MONEY, CHANGE;
int SERIAL, CARD_CHECKUP;

				cout<<" ENTER YOUR METROCARD SERIAL NUMBER "<<endl;
				o_file<<" ENTER YOUR METROCARD SERIAL NUMBER "<<endl;

				cin >> SERIAL;

				CARD_CHECKUP = CHECK_METROCARD(SERIAL, USER_NAME);

				if(CARD_CHECKUP != -1)
				{
							cout<<" HOW MUCH DO YOU WANT TO LOAD (MAX 20 USD) "<<endl; 
							o_file<<" HOW MUCH DO YOU WANT TO LOAD (MAX 20 USD) "<<endl; 

							cin >> LOAD;

							if( LOAD <= 20 || LOAD > 0)
							{
									
										cout<<" PLEASE ENTER YOUR MONEY (MAX 20 USD) "<<endl; 
										o_file<<" PLEASE ENTER YOUR MONEY (MAX 20 USD) "<<endl; 
						
										cin >> MONEY;

										if ( MONEY >= LOAD )
										{
														cout<<"YOUR CHANGE IS "<< CHANGE <<" USD "<<endl;
														cout<<"YOUR METROCARD IS PRINTING "<<endl;
														cout<<"HERE IS YOUR METROCARD: "<<endl;
														o_file<<"YOUR CHANGE IS "<< CHANGE <<" USD "<<endl;
														o_file<<"YOUR METROCARD IS PRINTING "<<endl;
														o_file<<"HERE IS YOUR METROCARD: "<<endl;

														CARD_INFO_NAME[NOOF_CARDS] = CARD_INFO_NAME[CARD_CHECKUP];
														CARD_INFO_MONEY[NOOF_CARDS] =LOAD + CARD_INFO_MONEY[CARD_CHECKUP];
														CARD_INFO_SERIAL_NUMBER[NOOF_CARDS] =CARD_INFO_SERIAL_NUMBER[CARD_CHECKUP];
													
														print_card(CARD_INFO_SERIAL_NUMBER[NOOF_CARDS], CARD_INFO_NAME[NOOF_CARDS], CARD_INFO_MONEY[NOOF_CARDS]);

										
										}
										else {
													cout<<" INSUFFICIENT MONEY. RETURNING YOUR "<< MONEY <<" USD "<<endl;
													o_file<<" INSUFFICIENT MONEY. RETURNING YOUR "<< MONEY <<" USD "<<endl;
										}
							}
							else {
										cout<< LOAD <<" IS AN ILLEGAL ENTRY "<<endl;
										o_file<< LOAD <<" IS AN ILLEGAL ENTRY "<<endl;
							}
				
				}
				else {
					   cout<<" NO SUCH CARD " <<endl;
					 	 o_file<<" NO SUCH CARD " <<endl;
				}
				

								





}
void
CCNY_TRANSPORT_GEN_2::print_card(int x, string y, int z)
{
	// YOUR CODE GOES BELOW
		cout<<"*M*E*T*R*O*C*A*R*D*M*E*T*R*O*C*A*R*D"<<endl;
	 	cout<<"*"<<endl;
		cout<<"* CARD SERIAL NUMBER: "<< CARD_INFO_SERIAL_NUMBER[NOOF_CARDS] <<endl;
		cout<<"* CARD HOLDER: "<< CARD_INFO_NAME[NOOF_CARDS] <<endl;
		cout<<"* CARD FUNDS TOTAL: "<< CARD_INFO_MONEY[NOOF_CARDS]<<"USD"<<endl;
		cout<<"*"<<endl;     
		cout<<"*M*E*T*R*O*C*A*R*D*M*E*T*R*O*C*A*R*D"<<endl;

		o_file<<"*M*E*T*R*O*C*A*R*D*M*E*T*R*O*C*A*R*D"<<endl;
	 	o_file<<"*"<<endl;
		o_file<<"* CARD SERIAL NUMBER: "<< CARD_INFO_SERIAL_NUMBER[NOOF_CARDS] <<endl;
		o_file<<"* CARD HOLDER: "<< CARD_INFO_NAME[NOOF_CARDS] <<endl;
		o_file<<"* CARD FUNDS TOTAL: "<< CARD_INFO_MONEY[NOOF_CARDS]<<"USD"<<endl;
		o_file<<"*"<<endl;     
		o_file<<"*M*E*T*R*O*C*A*R*D*M*E*T*R*O*C*A*R*D"<<endl;

}





int
CCNY_TRANSPORT_GEN_2::CHECK_METROCARD(int INPUT, string S)
{
int i;
int FOUND = 0;
int FOUND_POS = -1;

				for(i = 0; i < NOOF_CARDS && FOUND == 0; i++)
				{
					
					    if(CARD_INFO_SERIAL_NUMBER[i] == INPUT  && CARD_INFO_NAME[i] == S)
					    {
						       FOUND = 1;
						       FOUND_POS = i;
					    }
					    else {}
				}
				if ( FOUND == 1)
				{
					return FOUND_POS;
				}
				else {
					return -1;
				}


}
