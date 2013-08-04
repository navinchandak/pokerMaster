// coding for poker 
#include<iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include"copy.cpp"

using namespace std;
int mini(int a,int b){
	int value;
	if (a>b){
		value=b;
		}
	else if (a<=b){
		value=a;
		}
	return value;
	}
int firstbet(int card[],int money,int callmoney,int usermoney,int initialmoney){
    FILE *z;int a,b,i,j,k,l,g,h,value,m=53,min,q,o,u,pos,flag=0,temp1=-1,ran;double raise,pro_sum,temp=1,factor,p,n;char pro[1000];
    z=fopen("output.txt","r");
    if(z==0){
             //"could not read input file"<<endl;
             return -1;
             }
     if (card[0]%13==card[1]%13){
     	 for (i=0;i<((card[0]-1)%13)+2;i++){
        fgets(pro,100,z);
        }
      
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[10+i]-48)/temp;
            }
          
         //system("PAUSE");
         ////pro_sum;
        
       }        
       for (i=1;i<15;i++){
        fgets(pro,100,z);
        }
       a=(card[0]-1)/13;b=(card[1]-1)/13;
       
       if (a==b && card[0]%13!=card[1]%13){
       	 a=(card[0]-1)%13+1;b=(card[1]-1)%13+1;	
       	if (a>b){
       	temp=a;
       	a=b;
       b=temp;temp=1;
       }
       		 for (i=0;i<78-(13-a)*(14-a)/2+b-a;i++){
        fgets(pro,100,z);
        }
      
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[11+i]-48)/temp;
            }
          
         //system("PAUSE");
         ////pro_sum;
         
       }        
       
       for (i=1;i<79;i++){
        fgets(pro,100,z);
        }
       
        if (a!=b && card[0]%13!=card[1]%13){
       	
       	a=(card[0]-1)%13+1;b=(card[1]-1)%13+1;	
       	if (a>b){
       	temp=a;
       	a=b;
       b=temp;temp=1;
       }
       	for (i=0;i<78-(13-a)*(14-a)/2+b-a;i++){
        fgets(pro,100,z);
        }
      
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[11+i]-48)/temp;
            }
          
         //system("PAUSE");
         ////pro_sum;
        
       }
     
       	/*//"\n give the money in hand"<<endl;
		cin>>money;
		//endl;
		//"give the money called by the user";
		cin>>callmoney;
		//endl;
		//"give the money in  the user's hand";
		cin>>usermoney;
		//endl;
		*/
		srand(time(0));
		ran=(rand()%2)+1;
		for (i=1;i<=ran;i++){
			temp1=-1*temp1;
			}
		factor=pro_sum-(1-pro_sum)*(initialmoney-money+callmoney)/(10*initialmoney);
			//factor<<endl;//"hi";
			if (factor >0.62){
			   	factor=factor+temp1*((rand()%7)+1)*0.2/7;
			   	if (factor >0.65){
			   			raise=mini(money,(usermoney+callmoney));			   				
			   			//"Raise by "<<(raise-callmoney)<<endl;
			   			return (raise-callmoney);
			   			}
			   	
				else if (factor<0.55){
					//"call"<<endl;
					return 0;
					
				}
			
				else {
					raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.1*0.1*0.1))+(usermoney/10)*((rand()%5)+1);
					a=raise/10;
					raise=a*10;
					if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
			}
		}
			if (factor<0.48){
				if (rand()%7==0) u=0.7;
				else u=0;
			   	factor=factor+temp1*u;
			   	if (factor >0.65){
			   		
			   		raise=mini(money,(usermoney+callmoney));			   				
			   			//"Raise by "<<(raise-callmoney)<<endl;
			   			return (raise-callmoney);
			   			}
				
			
					
			   		
			   		
			   	else if (factor<0.18){
					//"fold"<<endl;
					return -1;
				}
				else if (factor<0.55){
					//"call"<<endl;
					return 0;
				}
			
				else {
					raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.1*0.1*0.1))+(usermoney/10)*((rand()%5)+1);
					a=raise/10;
					raise=a*10;
					if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
				}
			
			}
			
			factor=factor+ temp1*((rand()%40)+1)*0.4/40;
			//factor<<endl;
			if (factor>0.65){
				raise=mini(money,(usermoney+callmoney));
				//"raise by "<<raise-callmoney<<endl;
				return (raise-callmoney);
				}
			else if (factor<0.18){
				//"fold"<<endl;
				return -1;
				
			}
			else if (factor<0.55){
				//"call"<<endl;
				return 0;
			}
			else {
				raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.1*0.1*0.1))+(usermoney/50)*((rand()%5)+1);
				
			   	a=raise/10;
				raise=a*10;
				if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
			}
			
		
	return 0;
}		
				



int secondbet(int card[],int money,int callmoney,int usermoney,int initialmoney){
	int a,b,i,j,k,l,g,h,value,m=53,min,q,o,u,cards[7],pos,flag=0,temp1=-1,ran;double raise,pro_sum,temp=1,factor,p,n;char pro[1000];
	 
	for (l=1;l<53;l++){
    							if(l==card[0] || l==card[1] || l==card[2] || l==card[3] || l==card[4]){continue;}
    							else {
    								card[5]=l;
    								for (m=m-52+l;m<53;m=m+1){
    									if(m==card[0] || m==card[1] || m==card[2] || m==card[3] || m==card[4]){continue;}
    									else {card[6]=m;
    									for (a=0;a<7;a++){
    										cards[a]=card[a];
    										}
    									for (o=0;o<6;o++){
        									min=cards[o];     
        										for (q=o+1;q<7;q++){
            										if (cards[q]<min){
            											min=cards[q];
           												pos=q;
                 										}
            										}
    									         if (min<cards[o]){
        											cards[pos]=cards[o];cards[o]=min;                
       												 }
      											}
    									
    								n=probability(cards);
    								////u[0]<<" "<<u[1]<<" "<<u[2]<<" "<<u[3]<<" "<<u[4]<<" "<<u[5]<<" "<<u[6]<<" "<<n<<"\n";
    								p=p+n;
								}
							}
						}
						}
						pro_sum=p/1081;
						////pro_sum;					

		srand(time(0));
		ran=(rand()%2)+1;
		for (i=1;i<=ran;i++){
			temp1=-1*temp1;
			}
		factor=pro_sum-(1-pro_sum)*(initialmoney-money+callmoney)/(10*initialmoney);
			//factor<<endl;
			if (factor >0.7){
			   	factor=factor+temp1*((rand()%7)+1)*0.5/7;
			   	if (factor >0.75){
			   			raise=mini(money,usermoney+callmoney);			   				
			   			//"Raise by "<<(raise-callmoney)<<endl;
			   			return (raise-callmoney);
			   			}
			   	
				else if (factor<0.55){
					//"call"<<endl;
					return 0;
					
				}
			
				else {
					raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.2*0.2*0.2))+(usermoney/10)*((rand()%5)+1);
					a=raise/10;
					raise=a*10;
					if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
			}
		}
			if (factor<0.35){
				if (rand()%7==0) u=0.7;
				else u=0;
			   	factor=factor+temp1*u;
			   	if (factor >0.75){
			   	raise=mini(money,usermoney+callmoney);			   				
			   			//"Raise by "<<(raise-callmoney)<<endl;
			   			return (raise-callmoney);
			}
					
			   		
			   		
			   	else if (factor<0.35){
					//"fold"<<endl;
					return -1;
				}
				else if (factor<0.55){
					//"call"<<endl;
					return 0;
				}
			
				else {
					raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.2*0.2*0.2))+(usermoney/10)*((rand()%5)+1);
					a=raise/10;
					raise=a*10;
					if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
				}
			
			}
			
			factor=factor+ temp1*((rand()%40)+1)*0.1/40;
			//factor<<endl;
			if (factor>0.75){
				raise=mini(money,(usermoney+callmoney));
				//"raise by "<<raise<<endl;
				return (raise-callmoney);
				}
			else if (factor<0.35){
				//"fold"<<endl;
				return -1;
				
			}
			else if (factor<0.55){
				//"call"<<endl;
				return 0;
			}
			else {
				raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.2*0.2*0.2))+(usermoney/50)*((rand()%5)+1);
				
			   	a=raise/10;
				raise=a*10;
				if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
			}
			
		
	return 0;
}		
				


int thirdbet(int card[],int money,int callmoney,int usermoney,int initialmoney){
	int a,b,i,j,k,l,g,h,value,m=53,min,q,o,u,cards[7],pos,flag=0,temp1=-1,ran;double raise,pro_sum,temp=1,factor,p,n;char pro[1000];
	
for (m=1;m<53;m=m+1){
    									if(m==card[0] || m==card[1] || m==card[2] || m==card[3] || m==card[4]){continue;}
    									else {card[6]=m;
    									for (a=0;a<7;a++){
    										cards[a]=card[a];
    										}
    									for (o=0;o<6;o++){
        									min=cards[o];     
        										for (q=o+1;q<7;q++){
            										if (cards[q]<min){
            											min=cards[q];
           												pos=q;
                 										}
            										}
    									         if (min<cards[o]){
        											cards[pos]=cards[o];cards[o]=min;                
       												 }
      											}
    									
    								n=probability(cards);
    							//	//cards[0]<<" "<<cards[1]<<" "<<cards[2]<<" "<<cards[3]<<" "<<cards[4]<<" "<<cards[5]<<" "<<cards[6]<<" "<<n<<"\n";
    								p=p+n;
								}
							}
						
						pro_sum=p/46;
						
				//pro_sum<<endl;		
						
		srand(time(0));
		ran=(rand()%2)+1;
		for (i=1;i<=ran;i++){
			temp1=-1*temp1;
			}
		factor=pro_sum-(1-pro_sum)*(initialmoney-money+callmoney)/(10*initialmoney);
			//factor<<endl;
			if (factor >0.7){
			   	factor=factor+temp1*((rand()%7)+1)*0.5/7;
			   	if (factor >0.75){
			   			raise=mini(money,usermoney+callmoney);			   				
			   			//"Raise by "<<(raise-callmoney)<<endl;
			   			return (raise-callmoney);
			   			}
			   	
				else if (factor<0.55){
					//"call"<<endl;
					return 0;
					
				}
			
				else {
					raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.2*0.2*0.2))+(usermoney/10)*((rand()%5)+1);
					a=raise/10;
					raise=a*10;
					if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
			}
		}
			if (factor<0.35){
				if (rand()%7==0) u=0.7;
				else u=0;
			   	factor=factor+temp1*u;
			   	if (factor >0.75){
			   		raise=mini(money,usermoney+callmoney);			   				
			   			//"Raise by "<<(raise-callmoney)<<endl;
			   			return (raise-callmoney);
			}
					
			   		
			   		
			   	else if (factor<0.35){
					//"fold"<<endl;
					return -1;
				}
				else if (factor<0.55){
					//"call"<<endl;
					return 0;
				}
			
				else {
					raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.2*0.2*0.2))+(usermoney/10)*((rand()%5)+1);
					a=raise/10;
					raise=a*10;
					if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
				}
			
			}
			
			factor=factor+ temp1*((rand()%40)+1)*0.1/40;
			//factor<<endl;
			if (factor>0.75){
				raise=mini(money,(usermoney+callmoney));
				//"raise by "<<raise<<endl;
				return (raise-callmoney);
				}
			else if (factor<0.35){
				//"fold"<<endl;
				return -1;
				
			}
			else if (factor<0.55){
				//"call"<<endl;
				return 0;
			}
			else {
				raise=((usermoney/10)*(factor-0.55)*(factor-0.55)*(factor-0.55)/(0.2*0.2*0.2))+(usermoney/50)*((rand()%5)+1);
				
			   	a=raise/10;
				raise=a*10;
				if (money>raise){
						if ((raise-callmoney)>usermoney){
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						}
						if ((raise-callmoney)<usermoney){
							//"raise by "<<(raise-callmoney)<<endl;
			   				return (raise-callmoney);
						}
						
					}
						
					else if ((money-callmoney)<usermoney){
							//"raise by "<<(money-callmoney)<<endl;
			   				return (money-callmoney);
						}
					else {
							//"raise by "<<usermoney<<endl;
			   				return usermoney;
						
						}
			}
			
		
	return 0;
}		
				


int lastbet(int card[],int money,int callmoney,int usermoney,int initialmoney){
int a,b,i,j,k,l,g,h,value,m=53,min,q,o,u,cards[7],pos,flag=0,temp1=-1,ran;double comp_pro,raise,pro_sum,temp=1,factor,p,n;char pro[1000];
	 
	for (l=1;l<53;l++){
    							if(l==card[5] || l==card[6] || l==card[2] || l==card[3] || l==card[4]){continue;}
    							else {
    								card[0]=l;
    								for (m=m-52+l;m<53;m=m+1){
    									if(m==card[5] || m==card[6] || m==card[2] || m==card[3] || m==card[4]){continue;}
    									else {card[1]=m;
    									for (a=0;a<7;a++){
    										cards[a]=card[a];
    										}
    									for (o=0;o<6;o++){
        									min=cards[o];     
        										for (q=o+1;q<7;q++){
            										if (cards[q]<min){
            											min=cards[q];
           												pos=q;
                 										}
            										}
    									         if (min<cards[o]){
        											cards[pos]=cards[o];cards[o]=min;                
       												 }
      											}
    									
    								n=probability(cards);
    								////u[0]<<" "<<u[1]<<" "<<u[2]<<" "<<u[3]<<" "<<u[4]<<" "<<u[5]<<" "<<u[6]<<" "<<n<<"\n";
    								p=p+n;
								}
							}
						}
						}
			srand(time(0));
			pro_sum=p/1081;
			comp_pro=probability(card);
			if (comp_pro>pro_sum+0.1){
				raise=money;
				//"raise by "<<(money-callmoney)<<endl;
				return (money-callmoney);
			}
			if (pro_sum-comp_pro<0.1){
				comp_pro=comp_pro+((rand()%7)+1)*0.2/7;
				if (comp_pro>pro_sum){
				raise=money;
				//"raise by "<<(money-callmoney)<<endl;
				return (money-callmoney);
				}
			
				else {
					//"fold"<<endl;
					return -1;
				}
			}
			else {
				raise=callmoney+(pro_sum-comp_pro)*10*usermoney;
				a=raise/10;
				raise=raise*10;
				if (raise<money){
					//"raise by "<<(raise-callmoney)<<endl;
					return (raise-callmoney);
					}
				else {
					//"raise by "<<(money-callmoney)<<endl;
					return (money-callmoney);
					}
			}
return 0;
}


