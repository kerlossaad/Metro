#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "sample_pro_8.h"

using namespace std;

ofstream o_f ("out.9", ios::app);

class CCNY_TRANSPORT_GEN_3:public CCNY_TRANSPORT_GEN_2{
   public:   
	CCNY_TRANSPORT_GEN_3(string); // constructor
	void USER_INPUT_HANDLER_3(); // a method
	void TAP_IN(string, int, int); // a method
	void TAP_OUT(string, int, int); // a method

   private:
	string KIOSK_NAME; 
	string USER_NAME; 
	int CARD_TRIP_STATUS[20];
	int CARD_TRIP_START[20];
	int CARD_TRIP_END[20];
};

CCNY_TRANSPORT_GEN_3::CCNY_TRANSPORT_GEN_3(string k)
	:CCNY_TRANSPORT_GEN_2(k)
{
	int i;

	KIOSK_NAME = k;

	for (i=0; i < 20; i++)
	{
		CARD_TRIP_STATUS[i] = 0;
		CARD_TRIP_START[i] = 0;
		CARD_TRIP_END[i] = 0;
	}
}

void 
CCNY_TRANSPORT_GEN_3::TAP_IN(string name, int serial, int start_station)
{
	int ITEM_INDEX;
	int START_STATION_INDEX;
	
	ITEM_INDEX = check_metrocard(serial, name); // this is in project 8
	
	if (ITEM_INDEX != -1)
	{
		// update card trip status as active;
		// update trip start by using check_station function from project 7; 
		CARD_TRIP_STATUS[ITEM_INDEX] = 1;
		
		START_STATION_INDEX= check_station(start_station);

					if( START_STATION_INDEX != -1)
					{
		   						CARD_TRIP_START[ITEM_INDEX] = START_STATION_INDEX ;
			 						cout<<" CARD "<< serial  <<" STARTING TRIP IN STATION "<< start_station <<endl;
			 						o_f<<" CARD "<< serial  <<" STARTING TRIP IN STATION "<< start_station <<endl;
					}
		
					else{
 									cout<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 									cout<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
									o_f<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 									o_f<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
					}		
	}
	else
	{
		// complain that there is no such card:
			cout<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 			cout<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
			o_f<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 			o_f<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
	}
}

void 
CCNY_TRANSPORT_GEN_3::TAP_OUT(string name, int serial, int end_station)
{
	int ITEM_INDEX;
	int END_STATION_INDEX;
	int UPDATE_RET_VAL;
	double FARE;
	
	ITEM_INDEX = check_metrocard(serial, name); // this is in project 8
	if (ITEM_INDEX != -1)
	{
		// update card trip status as inactive (which is 0);

		// update trip end by using check_station function from project 7; 

		// calculate fare;

		// update card money by using update_metrocard with "CHARGE"
		CARD_TRIP_STATUS[ITEM_INDEX] = 0;		
	
		END_STATION_INDEX = check_station(end_station); 
	 	        
		
						if( END_STATION_INDEX != -1)
		        {
									CARD_TRIP_END[ITEM_INDEX] = END_STATION_INDEX;	
									FARE = CARD_TRIP_START[ITEM_INDEX] - CARD_TRIP_END[ITEM_INDEX]; 
										
									if ( FARE >= 0)
									{}
									else if( FARE < 0)
									{
										FARE = FARE * (-1);
									}
									
												UPDATE_RET_VAL = update_metrocard(ITEM_INDEX, FARE, "CHARGE"); 
                				
												if ( FARE > (UPDATE_RET_VAL+FARE) )
												{
														cout<<" CARD "<< serial <<" ENDING TRIP IN STATION "<< end_station <<endl;
														cout<<" CHARGING "<< FARE <<" USD TO "<< serial <<endl;
												
														o_f<<" CARD "<< serial <<" ENDING TRIP IN STATION "<< end_station <<endl;
						    						o_f<<" CHARGING "<< FARE <<" USD TO "<< serial <<endl;
												
														
														cout<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
														cout<<">>>>> OH, NO! CARD "<< serial <<" HAS INSUFFICIENT FUNDS. SEE THE ATTENDANT."<<endl;
														o_f<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
														o_f<<">>>>> OH, NO! CARD "<< serial <<" HAS INSUFFICIENT FUNDS. SEE THE ATTENDANT."<<endl;
						
												}
												else if (FARE <= (UPDATE_RET_VAL+FARE))
												{
														cout<<" CARD "<< serial <<" ENDING TRIP IN STATION "<< end_station <<endl;
														cout<<" CHARGING "<< FARE <<" USD TO "<< serial <<endl;
												
														o_f<<" CARD "<< serial <<" ENDING TRIP IN STATION "<< end_station <<endl;
						    						o_f<<" CHARGING "<< FARE <<" USD TO "<< serial <<endl;
												 		
														cout<<"CARD "<< serial <<" NOW HAS "<< UPDATE_RET_VAL <<" USD "<<endl;
												 		o_f<<"CARD "<< serial <<" NOW HAS "<< UPDATE_RET_VAL<<" USD "<<endl;
												}	
												else{}
						
						}

						else
						{
									// complain that there is no such card:
 									cout<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 									cout<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
									o_f<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 									o_f<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
						
						
						}
	}
	else {
 									cout<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 									cout<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
									o_f<<">>>>> BEEP >>>>> BEEP >>>>> BEEP >>>>>"<<endl;
 									o_f<<">>>>> NO SUCH CARD. SEE THE ATTENDANT."<<endl;
	}
}
