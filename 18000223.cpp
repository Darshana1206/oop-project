#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;
int flag_f1_f3;

class planes{
	private:
		string fnum;
		string date_time;
		string dep;
		string arrival;
		int b,e;
		
	public:
		
		int flightArry[60][7];
		planes(){}
		planes(string name,string dt,string dept,string arrive,int seatArr[60][7]){
			fnum=name;
			date_time=dt;
			dep=dept;
			arrival=arrive;
			
			for(int i=0;i<60;i++){
				for(int j=0;j<7;j++){
					flightArry[i][j]='\0'; // reset the array
				}
			}
			
			for(int i=0;i<60;i++){
				for(int j=0;j<7;j++){
					if(seatArr[i][6]!=0){
						flightArry[i][j]=seatArr[i][j];
					}
				}
			}
			
				
		}
		void display();
		string get_fnum();
		string get_date_time();
		string get_dep();
		string get_arrival();
		void search();
		void available(int q);	
};

void planes::display(){
	
	int count_B=0,count_E=0;
		for(int i=0; i<60; i++)
	{   
		if(flightArry[i][6]!=0){
			for(int j=0; j<6; j++)
		   { 
				if(flightArry[i][j]==1){
					
						if(flightArry[i][6]==1)
							count_E++;
						
						if(flightArry[i][6]==2)
							count_B++;	  
				}
		   }
		
		} 
	}
	e=count_E;
	b=count_B;
	
	if(flag_f1_f3==0){
			cout<<fnum<<endl<<date_time<<endl<<dep<<endl<<arrival<<endl;
			cout<<"Number of seats available in Economy class : "<<count_E<<endl;
			cout<<"Number of seats available in bussines class : "<<count_B<<endl;
				cout<<"*****************************\n";
		
	}
}

	string planes::get_fnum(){
		return fnum;
}
	string planes::get_dep(){
		return dep;
	}
	string planes::get_date_time(){
		return date_time;
	}
	string planes::get_arrival(){
		return arrival;
	}

	void planes::search(){
		for(int i=0;i<60;i++)
		{
			if(flightArry[i][6]!=0){
				cout<<i<<" ";
				if(flightArry[i][6]==1)
					cout<<"E ";
				
				if(flightArry[i][6]==2)
					cout<<"B ";	
				
				
					for(int j=0;j<6;j++){
						if(flightArry[i][j]==1 && j==0){
							cout<<"A";
						}
						else if(flightArry[i][j]==1 && j==1){
							cout<<"B";
						}
						else if(flightArry[i][j]==1 && j==2){
							cout<<"C";
						}
						else if(flightArry[i][j]==1 && j==3){
							cout<<"D";
						}
						else if(flightArry[i][j]==1 && j==4){
							cout<<"E";
						}
						else if(flightArry[i][j]==1 && j==5){
							cout<<"F";
						}
						
						if(j==5)
							cout<<endl;
					}
				
			}
			
		}
		
		cout<<"all seat count: "<<(e+b)<<endl;
		
}

void planes::available(int q){
	flag_f1_f3=1;
	display();
	int z=(e+b);
	if(q<=z)
	{
		cout<<q<<'\t'<<"-----seats are avalable!-----"<<endl<<endl;
	}
	else
	cout<<'\t'<<"------seats are not available!------"<<endl<<endl;
	
	flag_f1_f3=0;
}

int main()
{
	int count =0;
	ifstream assignment;
	assignment.open("flights.txt",ios::in);
	string lines;
	while(!assignment.eof())
	{
		getline(assignment,lines);
		if(lines.empty())
			count++;
	}
	assignment.close();
	
	planes objArr[count];
	int seatArr[60][7];
	string name,dt,dept,arrive;
	assignment.open("flights.txt",ios::in);
	
	for(int x=0;x<count;x++)
{   
	for(int i=0;i<60;i++){
		for(int j=0;j<7;j++){
			seatArr[i][j]='\0';
		}
	}

		getline(assignment,name);
		getline(assignment,dt);
		getline(assignment,dept);
		getline(assignment,arrive);
		
		while(!assignment.eof())
		{
			getline(assignment,lines);
			
			if(lines.empty()){
				planes a(name,dt,dept,arrive,seatArr);
				objArr[x]=a;
				break;
			}
			else
			{
				istringstream buf(lines);//split lines
				string row,level,seat;
				int index=0;  //convert string to int
				buf>>row>>level>>seat;
				stringstream convert(row);
				convert>>index;
				//cout<<index<<endl;
				string b=seat; //convert string to char array
				int n =b.length();
				char seat_arr[n+1];
				strcpy(seat_arr,b.c_str());
				
				
					if(level=="E")
						seatArr[index][6]=1;
						
					else
						seatArr[index][6]=2	;
					
						for(int y=0;y<n;y++){
							if(seat_arr[y]=='A'){
								seatArr[index][0]=1;
									
							}
							else if(seat_arr[y]=='B'){
								seatArr[index][1]=1;
							}
							else if(seat_arr[y]=='C'){
								seatArr[index][2]=1;
							}
							else if(seat_arr[y]=='D'){
								seatArr[index][3]=1;
							}
							else if(seat_arr[y]=='E'){
								seatArr[index][4]=1;
							}
							else if(seat_arr[y]=='F'){
								seatArr[index][5]=1;
							}
							
						}
						
					}				
			}
				
					
		}
		int instructions=5;
		do{
			cout<<'\t'<<"---------------------------------------"<<endl;
			cout<<'\t'<<"|"<<"     "<<"*******Main Menu*******"<<"         |"<<endl;
			cout<<'\t'<<"| "<<"1- Display Available Flights"<<"        |"<<endl;
			cout<<'\t'<<"| "<<"2- View Flight"<<"                      |"<<endl;
			cout<<'\t'<<"| "<<"3- Seat Availability"<<"                |"<<endl;
			cout<<'\t'<<"| "<<"4- Seat Booking"<<"                     |"<<endl;
			cout<<'\t'<<"| "<<"5- Exit"<<"                             |"<<endl;
			cout<<'\t'<<"---------------------------------------"<<endl<<endl;
			cout<<"Choose Your Option : ";
			cin>>instructions;
			
			if(instructions>5)
				cout<<'\t'<<"-----Wrong Input!------"<<endl<<endl;
			
			switch(instructions)
			{
				case 1:
					cout<<"Instructions of Available flights:"<<endl<<endl;
					for(int x=0;x<count;x++){
						objArr[x].display();
					}
						break;
				case 2:
					{
					string search;
					int f2_flag=0;
					cout<<"Enter the flight number: ";
					cin>>search;
					for(int x=0;x<count;x++){
					if(search==objArr[x].get_fnum())
					{ 
						f2_flag=1;
						objArr[x].display();
						objArr[x].search();		
					}
				}
					if(f2_flag==0)
						cout<<'\t'<<"------wrong input!------"<<endl;
						break;
					}
					
				case 3:
					{
					int q;
					int f3_flag=0;
					string d;
					cout<<"Enter the flight number: ";
					cin>>d;
					for(int x=0;x<count;x++){
					if(d==objArr[x].get_fnum()){
						f3_flag=1;
						cout<<"How Many seats do you want : ";
						cin>>q;
						objArr[x].available(q);
					}
					
								
			}
			if(f3_flag==0)
			cout<<'\t'<<'\t'<<"-------Wrong input!-------"<<endl<<endl;
			break;
		}
				case 4:
				{
					string t;
					int m;
					char p;
					int c;
					int h;
					bool flag = false;
					cout<<"Enter the flight number: ";
					cin>>t;
					for(int x=0;x<count;x++){
						if(t==objArr[x].get_fnum()){
							cout<<"Enter the row number : ";
							cin>>m;
							if(m<0||m>60)
								cout<<'\t'<<"--------Invalid Input!-------"<<endl<<endl;
								
							for(int i=0;i<60;i++){
								if(objArr[x].flightArry[i][6]!=0 && i==m){
										cout<<"Enter the seat character: ";
										cin>>p;
											if(p=='A'){
												h=0;
												if(objArr[x].flightArry[m][h]==1){
													objArr[x].flightArry[m][h]=0;
													cout<<'\t'<<"-------seat booking success!-------"<<endl;
													flag = true;
													break;	
												}
												else
													cout<<'\t'<<"------seat has already booked!-------"<<endl;flag = true;		
											}
										
											if(p=='B'){
												h=1;
												if(objArr[x].flightArry[m][h]==1){
													objArr[x].flightArry[m][h]=0;
													cout<<'\t'<<"-------seat booking success!-------"<<endl;
													flag = true;
													break;	
												}
												else
													cout<<'t'<<"--------seat has already booked!-------"<<endl;flag = true;	
											}
											if(p=='C'){
												h=2;
												if(objArr[x].flightArry[m][h]==1){
													objArr[x].flightArry[m][h]=0;
													cout<<'\t'<<"--------seat booking success!--------"<<endl;flag = true;
													break;	
												}
												else
													cout<<'\t'<<"-------seat has already booked!-------"<<endl;flag = true;
											}
											if(p=='D'){
												h=3;
												if(objArr[x].flightArry[m][h]==1){
													objArr[x].flightArry[m][h]=0;
													cout<<'\t'<<"-------seat booking success!--------"<<endl;flag = true;
													break;	
												}
												else
													cout<<'\t'<<"--------seat has already booked!--------"<<endl;flag = true;
											}
											if(p=='E'){
												h=4;
												if(objArr[x].flightArry[m][h]==1){
													objArr[x].flightArry[m][h]=0;
													cout<<"seat booking success!"<<endl;flag = true;
													break;
												}
												else
													cout<<'\t'<<"-------seat has already booked!-------"<<endl;flag = true;
											}
											if(p=='F'){
												h=5;
												if(objArr[x].flightArry[m][h]==1){
													objArr[x].flightArry[m][h]=0;
													cout<<'\t'<<"--------seat booking success!--------"<<endl;flag = true;
													break;
												}
												else
													cout<<'t'<<"--------seat has already booked!--------"<<endl;flag = true;
											}
											
							    }
														
						   }
										
				    }
									
				}
				if(!flag){
				
				cout<<'\t'<<"-------Wrong Detail!--------"<<endl<<endl;
				
				}
				
			}break;
				case 5:
				{
				




                    ofstream outfile;
                    outfile.open ("flights.dat");
                    
 				for(int x=0;x<count;x++){
 					outfile<<objArr[x].get_fnum()<<endl;
 					outfile<<objArr[x].get_date_time()<<endl;
					outfile<<objArr[x].get_dep()<<endl;
					outfile<<objArr[x].get_arrival()<<endl;
 					
				 for(int i=0;i<60;i++){
				 

				if(objArr[x].flightArry[i][6]!=0){
				
				    outfile<<i<<" ";
				if(objArr[x].flightArry[i][6]==1)
					outfile<<"E ";
				
				if(objArr[x].flightArry[i][6]==2)
					outfile<<"B ";	
				
				
					for(int j=0;j<6;j++){
						if(objArr[x].flightArry[i][j]==1 && j==0){
							outfile<<"A";
						}
						else if(objArr[x].flightArry[i][j]==1 && j==1){
							outfile<<"B";
						}
						else if(objArr[x].flightArry[i][j]==1 && j==2){
							outfile<<"C";
						}
						else if(objArr[x].flightArry[i][j]==1 && j==3){
							outfile<<"D";
						}
						else if(objArr[x].flightArry[i][j]==1 && j==4){
							outfile<<"E";
						}
						else if(objArr[x].flightArry[i][j]==1 && j==5){
							outfile<<"F";
						}
						
					
					}	
					outfile<<endl;
								
		}
	}
		outfile<<endl;
	}
						
		return 0;					
	 }

}
					
}
	while(1);
}

						 
			
			
							
		
		
		
	




