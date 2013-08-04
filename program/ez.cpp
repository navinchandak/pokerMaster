//cs101 project
#include<iostream>  
#include<ctime>     
#include<cstdlib>   
#include "ezwin.h"
#include "bitmap.h"
#include <cassert>
#include "cards.h"
#include "nums.h"
#include "2_cardfunction.cpp"

//#include "decision.cpp"
using namespace std;
int timepass=0;

cards card[53];
nums num[17];


//function prototypes 
//void display(int bet,int getback,int *ma,int *mb,int *spent,int *pot,int *game);
int allot(int [],int);
int round(string user,int cardsa[],int n,int ma,int mb,int spent,int probability,int *getback);
float givepro(int a[],int n);
void copy(int a[],int b[],int n);
int alldiff(int a[],int n);
void rendernumber(char s[],int a);
void displaycards();
int decision();
void sort(int a[],int n);



////////////ez windows
SimpleWindow W("Poker Game",23.10,13.62,Position(7.0,5.0));
SimpleWindow Raiseopt("          Raise Options        ",20,8,Position(7.0,5.0));
////ez functions for displaying
void displaypreflop(int a,int b){
//"EZWINDOWS WILL DISPLAY THE PREFLOP";
card[a].B.SetPosition(Position(8.5,7.0));
card[a].B.Draw();
card[b].B.SetPosition(Position(10.1,7.0));
card[b].B.Draw();
}

void displayflop(int a,int b,int c)
{int A[3]={a,b,c};
for(int i=0;i<3;i++) 
{ card[A[i]].B.SetPosition(Position(5.6+1.6*i,4.6));
  card[A[i]].B.Draw();
}
}

void displayturn(int a)
{
card[a].B.SetPosition(Position(10.4,4.6));
card[a].B.Draw();
}
void displayriver(int a)
{
card[a].B.SetPosition(Position(12.0,4.6));
card[a].B.Draw();
}

void displaycomputer(int a,int b)
{
card[a].B.SetPosition(Position(8.5,2.2));
card[a].B.Draw();
card[b].B.SetPosition(Position(10.1,2.2));
card[b].B.Draw();
}

void displayraise()
{
for(int i=0;i<=12;i++) 
{ num[i].setwi(Raiseopt);}
// Load all the numbers
num[0].D.Load("0.xpm");
num[1].D.Load("1.xpm");
num[2].D.Load("2.xpm");
num[3].D.Load("3.xpm");
num[4].D.Load("4.xpm");
num[5].D.Load("5.xpm");
num[6].D.Load("6.xpm");
num[7].D.Load("7.xpm");
num[8].D.Load("8.xpm");
num[9].D.Load("9.xpm");
num[10].D.Load("ok.xpm");
num[11].D.Load("money.xpm");
num[12].D.Load("change.xpm");

// set the position of the number bitmaps
for(int i=0;i<=9;i++) 
{
//Set Position of all the cards from 1 to 9
num[i].D.SetPosition(Position( (1.5*i+2),4 ) );
}
// Set Position of ok money and change bitmap
num[10].D.SetPosition(Position(6.5,5));
num[11].D.SetPosition(Position(3.5,6.7));
num[12].D.SetPosition(Position(14.5,6.7));
// Now draw all the bitmaps

for(int i=0;i<13;i++)
{
num[i].D.Draw();
}

}


void displayback()
{
BitMap Bkgrnd(W);
Bkgrnd.Load("poker3.xpm");
assert(Bkgrnd.GetStatus()==BitMapOkay);
Bkgrnd.SetPosition(Position(0.0,0.0));
Bkgrnd.Draw();
BitMap Order(W);
Order.Load("order.xpm");
assert(Order.GetStatus()==BitMapOkay);
Order.SetPosition(Position(19,0.0));
Order.Draw();

W.RenderText(Position(8.3,9.3),Position(9.8,9.7),"Call/check",Blue);
W.RenderText(Position(10.3,9.3),Position(11.5,9.7),"Raise",Blue);
W.RenderText(Position(12.0,9.3),Position(13.0,9.7),"Fold",Blue);
}


/////////////////ez mouseclick
/////////////////ez mouseclick
int raiseuser,warning,stage;
int inputuser,n,inputcomp,cards[9],cardsa[7],cardsb[7],cardssenda[7];
int ma=10000,mb=10000,calla,callb;     char copyhere2[100],copyhere3[100];   int pot=0; 
int a=0;
void display1(char s[])
{
W.RenderText(Position(5,11.5),Position(15,12.5),s,Blue);
}

void display2(char s[])
{strcpy(copyhere2,s);
W.RenderText(Position(5,12),Position(15,13),s,Blue);
}

void display3(char s[])
{strcpy(copyhere3,s);
W.RenderText(Position(5,12.5),Position(15,13.5),s,Blue);
}

void displayinfo(char s[])
{
char copyhere[100];
strcpy(copyhere,copyhere2);
display1(copyhere);
strcpy(copyhere,copyhere3);
display2(copyhere);
strcpy(copyhere,s);
display3(s);
}
void clear1()
{
char s[]="                                                     ";
W.RenderText(Position(5,11.5),Position(15,12.5),s,Blue);
}
void clear2()
{
char s[]="                                                     ";
W.RenderText(Position(5,19),Position(28,20),s,Blue);
}

void addchars(char c[],char d[])
{int i=0,j=0;
	while(c[i]!='\0')
		{i++;}
	while(d[j]!='\0')
		{c[i]=d[j]; i++; j++;}
	c[i]='\0';
}
void displaydecision(int a)
{
if(a==0)
	{//"Comp decided to call \n";
	char s[]="            Comp decided to call                 ";
	displayinfo(s);
	calla=callb;
	pot+=callb-calla;
	n++;
	displaycards();
	}
else if(a<0)
	{
	//"computer drops\n";
	 ma-=calla;
	 mb+=calla;
	 }
else if(a>0)
	{
	char s[]="                Comp decided to raise by ";
	char p[20];
	rendernumber(p,a);
	addchars(s,p);
	char q[]="                    ";
	addchars(s,q)    ;        
	displayinfo(s);
	//"computer raises by"<<a<<"\n";
	pot+=a+callb-calla;
	calla+=a+callb-calla;
	
	}
}

int raiseclick(const Position &P) 
{stage=1;
char s[40]="0";
char w1[]="User you dont have enough money to make this call";
char w2[]="Invalid because computer doesnt have sufficient funds";
char w0[]="                                                     ";
//////raise window
for(int k=0;k<=12;k++)
{
	  
	   if(num[k].D.IsInside(P))  
	   {
	   		if(warning==1)
	  		{
	   			warning=0;
	  			Raiseopt.RenderText(Position(2,1.5),Position(10,2.5),w0,Black);
	  		}
	  		
			if(k<=9) { //Restore itz'; value as k  
						raiseuser*=10;
						raiseuser+=k;
						rendernumber(s,raiseuser);
						Raiseopt.RenderText(Position(4.8,8),Position(7.5,6),s,Black);
						
						//k<<"\n";
				 	 }
			
		      else if(k==12){
		      raiseuser/=10; 
		      rendernumber(s,raiseuser);
			  Raiseopt.RenderText(Position(4.8,8),Position(7.5,6),s,Black);
		      warning=2;
		      				}
		      else if(k==10)
		      {
		      	  if(raiseuser+callb-calla>=mb-callb)
		      		{Raiseopt.RenderText(Position(2,1.5),Position(10,2.5),w1,Black);
		      		//"User doesnot have enough money\n"; warning=1
		      		}
		     	  else if(raiseuser>=ma-calla)
		     	 		{Raiseopt.RenderText(Position(2,8),Position(10,6),w2,Black); warning=1;
		     	 		}
		     	  else{
		  	 	    //raiseuser<<"is the input raise\n";
		  	 	    pot+=raiseuser+calla-callb;
		  	 	    callb+=(calla-callb+raiseuser);
		  	 	    
		  	 	    char s[]="               User decided to raise by ";
					char p[20];
					rendernumber(p,raiseuser);
					addchars(s,p);
					char q[]="                    ";
					addchars(s,q)    ;        
					displayinfo(s);
		  	 	    Raiseopt.Close(); // Now ok is clicked Take the sum and call the raise functio
		 	 	    inputcomp=decision();
		 	 	    displaydecision(inputcomp);
		 	 	    }
		 	 	  
			 }
	}
}
if(warning==2)
	  		{   num[11].D.Draw();
	  			rendernumber(s,raiseuser);
				Raiseopt.RenderText(Position(4.8,8),Position(7.5,6),s,Black);
	  	 		warning=0;
	  	 	}
}
void rendernumber(char s[],int a)
{int i=0,j; char temp;
if(a==0)
	{s[i++]='0'; }
else
{ 
while(a!=0){
	s[i]=a%10+48;
	a/=10;
	i++;
	}
	
for(j=0;j<=((i-1)/2);j++)
{
temp=s[j];
s[j]=s[i-1-j];
s[i-1-j]=temp;
}
}
s[i]='\0';
}
void rendernumbers(string s,int a)
{int i=0,j; char temp;
if(a==0)
	{s[i++]='0'; }
else
{ 
while(a!=0){
	s[i]=a%10+48;
	a/=10;
	i++;
	}
	
for(j=0;j<=((i-1)/2);j++)
{
temp=s[j];
s[j]=s[i-1-j];
s[i-1-j]=temp;
}
}
s[i]='\0';
}
///////////////main screen/////////////////////////////
///////////////main screen/////////////////////////////



int cuteclick(const Position &P) 



{float x,y; 
//"MOUSECLICK EXECUTED FOR THE FIRST TIME\n"; 
x=P.GetXDistance();
y=P.GetYDistance();
//"Just before displaying in call, the cards are..............in stage.:"<<n<<" "<<cardsa[0]<<" "<<cardsa[1]<<"\n";
if ((8.3<x)&&(9.8>x)&&(9.3<y)&&(9.7>y))
{//call function
if(stage==0)
	{
	char s[]="              User decided to check               ";
	displayinfo(s);
	callb=0;
	stage=1;
	inputcomp=decision();
	displaydecision(inputcomp);
	pot+=0;
	}
else if(stage!=0)
	{char s[]="              User decided to call               ";
	displayinfo(s);
	callb=calla;
	ma-=calla;
	mb-=callb;
	

	


	n++;
	pot+=calla-callb;
	displaycards();
	stage=0;
	calla=callb=0;
	}

}

else if ((10.3<x)&&(11.5>x)&&(9.3<y)&&(9.7>y))
{raiseuser=0; warning=0;
Raiseopt.Open();
displayraise();
Raiseopt.SetMouseClickCallback(raiseclick);
}
else if((12.0<x)&&(13.0>x)&&(9.3<y)&&(9.7>y)) 
{// Write the Functions name that should be called "Fold function"
char c[]="     The user has dropped.Computer wins the match    ";
displayinfo(c);
inputuser=-2;
n=0;
ma+=callb;
mb-=callb;
displayback();
}
}
//////considering various stages of the game
void displaycards(){
 
if(n==0)
{		
	calla=callb=0;	
	//endl<<"User,you have "<<mb<<" rupees in hand.All the best for your game. ";                                   
	//"I have "<<ma<<" rupees in hand. ";     
	cards[0]=cardsa[0]=allot(cards,0); 
	cards[1]=cardsa[1]=allot(cards,1);
	//"Cards[0] and cards[1]//////////////"<<cardsa[0]<<" "<<cardsa[1];
	cards[2]=cardsb[0]=allot(cards,2);
	cards[3]=cardsb[1]=allot(cards,3);
	displaypreflop(cardsb[0],cardsb[1]);
	//"COmputer ,your cards are "<<cardsa[0]<<" and "<<cardsa[1]<<endl;
	//"user,your cards are "<<cardsb[0]<<" and "<<cardsb[1]<<endl;
	//"Welcome to \"preflop\" round of betting."<<endl;
	n++;
	stage=0;
	int a;
}
else if(n==2)
{	
calla=callb=0;	
	cards[4]=cardsa[2]=cardsb[2]=allot(cards,4); 
	cards[5]=cardsa[3]=cardsb[3]=allot(cards,5);
	cards[6]=cardsa[4]=cardsb[4]=allot(cards,6);
	displayflop(cards[4],cards[5],cards[6]);

	//"Community cards are "<<cards[4]<<" "<<cards[5]<<" "<<cards[6]<<endl;
	//"Welcome to \"flop\" round of betting"<<endl;
	n++;
	stage=0;
	}
else if(n==4)
{
calla=callb=0;	
cards[7]=cardsa[5]=cardsb[5]=allot(cards,7);
displayturn(cards[7]);
//"Community cards are "<<cards[7]<<endl;
//"Welcome to \"turn\" round of betting"<<endl;
n++;
stage=0;
}
else if(n==6)
{//"Just before displaying, the cards are...............:\n"<<cardsa[0]<<" "<<cardsa[1]<<"\n";
calla=callb=0;	
cards[8]=cardsa[6]=cardsb[6]=allot(cards,8);
displayriver(cards[8]);
//"Community cards are "<<cards[8]<<endl;
//"Welcome to \"river\" round of betting"<<endl;
n++;
stage=0;
}
else if(n==8)
{int a[7];
double pro1,pro2;
//"Just before displaying, the cards are...............:\n"<<cardsa[0]<<" "<<cardsa[1]<<"\n";
displaycomputer(cardsa[0],cardsa[1]);
copy(a,cardsa,7);
sort(a,7);
pro1=probability(a);
copy(a,cardsb,7);
sort(a,7);
pro2=probability(a);
if(pro1>pro2)
	{char s[]= "            Computer wins the match            ";
	displayinfo(s);
	}
else if(pro2>pro1)
	{char s[]= "            User wins the match            ";
	displayinfo(s);
	}
else {char s[]="    Unbelievably,Game ends in a draw      ";
		displayinfo(s);
		}

n=0;
 

	

}

}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////
int ApiMain()                         
{  //random
srand(time(0)); 
///////////ez.////////////////////
W.Open();
//Load the background 1st
displayback();

//set the window and load cards in which the cards should appear
for(int i=1;i<54;i++) 
{ card[i].setw(W);}
card[1].B.Load("SpadeA.xpm");	
card[2].B.Load("Spade2.xpm");
card[3].B.Load("Spade3.xpm");
card[4].B.Load("Spade4.xpm");
card[5].B.Load("Spade5.xpm");
card[6].B.Load("Spade6.xpm");
card[7].B.Load("Spade7.xpm");
card[8].B.Load("Spade8.xpm");
card[9].B.Load("Spade9.xpm");
card[10].B.Load("Spade10.xpm");
card[11].B.Load("SpadeJ.xpm");
card[12].B.Load("SpadeQ.xpm");
card[13].B.Load("SpadeK.xpm");
card[14].B.Load("DiamondA.xpm");
card[15].B.Load("Diamond2.xpm");
card[16].B.Load("Diamond3.xpm");
card[17].B.Load("Diamond4.xpm");
card[18].B.Load("Diamond5.xpm");
card[19].B.Load("Diamond6.xpm");
card[20].B.Load("Diamond7.xpm");
card[21].B.Load("Diamond8.xpm");
card[22].B.Load("Diamond9.xpm");
card[23].B.Load("Diamond10.xpm");
card[24].B.Load("DiamondJ.xpm");
card[25].B.Load("DiamondQ.xpm");
card[26].B.Load("DiamondK.xpm");
card[27].B.Load("HeartA.xpm");
card[28].B.Load("Heart2.xpm");
card[29].B.Load("Heart3.xpm");
card[30].B.Load("Heart4.xpm");
card[31].B.Load("Heart5.xpm");
card[32].B.Load("Heart6.xpm");
card[33].B.Load("Heart7.xpm");
card[34].B.Load("Heart8.xpm");
card[35].B.Load("Heart9.xpm");
card[36].B.Load("Heart10.xpm");
card[37].B.Load("HeartJ.xpm");
card[38].B.Load("HeartQ.xpm");
card[39].B.Load("HeartK.xpm");
card[40].B.Load("ClubA.xpm");
card[41].B.Load("Club2.xpm");
card[42].B.Load("Club3.xpm");
card[43].B.Load("Club4.xpm");
card[44].B.Load("Club5.xpm");
card[45].B.Load("Club6.xpm");
card[46].B.Load("Club7.xpm");
card[47].B.Load("Club8.xpm");
card[48].B.Load("Club9.xpm");
card[49].B.Load("Club10.xpm");
card[50].B.Load("ClubJ.xpm");
card[51].B.Load("ClubQ.xpm");
card[52].B.Load("ClubK.xpm");
n=0;
pot=0;
displaycards();
W.SetMouseClickCallback(cuteclick);
return (0);
}

/////////////////////////////////////////////**************FUNCTION DEFINITIONS**********************/////////////////////////////////////////////
//function to allot a card
int allot(int cards[],int n)
{int i,a;int flag=1;
while(flag)
	{flag=0;
	a=rand()%52+1;
	for(i=0;i<n;i++)
		{if(cards[i]==a)
			flag=1;
		}
	}
return a;
}

//copy functon for arrays
void copy(int a[],int b[],int n)
{
int i;
for(int i=0;i<n;i++)
{a[i]=b[i];}
}

//function which finds out the probability of winning as decided by our database
//
int total;
void display(int a[]);
void setbyi(int a[],int start,int curr,int k);
float probe(int a[],int start,int curr,int index);
void sort(int a[],int n);



float givepro(int cards[],int n)
{total=0;
int cardssend[7];
copy(cardssend,cards,n);
sort(cardssend,n);

float num=probe(cards,n,n,1);
float probability=num/(float)total;

return probability;
}




float probe(int a[],int start,int curr,int index  )
{float pro=0;
int k,sortedcards[7];
if(curr==7)
		{copy(sortedcards,a,7);
		sort(sortedcards,7);
		pro+=0.45;
		total+=1;
		}
else
{for(k=index;k<=46+curr-start;k++)
	{setbyi(a,start,curr,k);
	pro+=probe(a,start,curr+1,k+1);
	}
}
return pro;
}


void setbyi(int a[],int start,int curr,int k)
{int i;
a[curr]=k;
for(i=0;i<start;i++)
{if(a[i]<=a[curr]) 
	{a[curr]++;}
}
}

void sort(int a[],int n)
{int i,j,pos,temp;
for(i=0;i<n;i++)
{	pos=i;
	for(j=i+1;j<n;j++)
		{
		if(a[j]<a[pos])
			pos=j;
		}
	temp=a[i];	a[i]=a[pos];  a[pos]=temp;
}
}

int decision()
{int a=0;
if(n==1)
	{//" cards[0] "<<cardsa[0];
	//" cards[1] "<<cardsa[1];
	//" ma-calla "<<ma-calla;
	//" callb-calla "<<callb-calla;
	//" mb-callb "<<mb-callb;
	//" ma+pot "<<ma+pot;
	//"\n";
	a=firstbet(cardsa,(ma-calla),(callb-calla),(mb-callb),(ma+pot));
	return a;}
else if(n==3)
	{//" cards[0] "<<cardsa[0];
	//" cards[1] "<<cardsa[1];
	//" ma-calla "<<ma-calla;
	//" callb-calla "<<callb-calla;
	//" mb-callb "<<mb-callb;
	//" ma+pot "<<ma+pot;
	//"\n";
	a=secondbet(cardsa,(ma-calla),(callb-calla),(mb-callb),(ma+pot));
	return a;
	}
else if(n==5)
	{//" cards[0] "<<cardsa[0];
	//" cards[1] "<<cardsa[1];
	//" ma-calla "<<ma-calla;
	//" callb-calla "<<callb-calla;
	//" mb-callb "<<mb-callb;
	//" ma+pot "<<ma+pot;
	//"\n";
	a=thirdbet(cardsa,(ma-calla),(callb-calla),(mb-callb),(ma+pot));
	return a;
	}
else if(n==7)
{//" cards[0] "<<cardsa[0];
	//" cards[1] "<<cardsa[1];
	//" ma-calla "<<ma-calla;
	//" callb-calla "<<callb-calla;
	//" mb-callb "<<mb-callb;
	//" ma+pot "<<ma+pot;
	//"\n";
	int cardsforsend[7];
	copy(cardsforsend,cardsa,7);
	a=lastbet(cardsforsend,(ma-calla),(callb-calla),(mb-callb),(ma+pot));
	return a;
	}
//"Enter value for comp\n";
if(timepass==0)
	{timepass=1; return 110;}
else {timepass=0; return 0;}

}


