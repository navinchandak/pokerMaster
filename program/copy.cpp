// coding for poker 
#include<iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cstdio>
using namespace std;

      
double probability(int card[]){
    FILE *z;int a,b,c,d=0,j,min,i,k,position=-1,pos,p[3],count,dis[7],highest_card,cardnumber[10000];char pro[10000];double temp=1.0,pro_sum=0.0;
    z=fopen("pokerdatabase.txt","r");
    if(z==0){
             cout<<"could not read input file"<<endl;
             return -1;
             }
    
   
    
    						
    					
    				
    		
    for (i=0;i<3;i++){
    	
    	if ((card[i]-1)/13==(card[i+4]-1)/13){
    		d=d+1;
    		if (position==-1){
    			position=i;
    			}
    		}
    	}
    for (i=0;i<7;i++){
        cardnumber[i]=(card[i]+11)%13+2;
        }
    for (i=0;i<6;i++){
        min=cardnumber[i];     
        for (j=i+1;j<7;j++){
            if (cardnumber[j]<min){
            min=cardnumber[j];
            pos=j;
                 }
            }
            if (min<cardnumber[i]){
        cardnumber[pos]=cardnumber[i];cardnumber[i]=min;                
        }
      }
    dis[0]=cardnumber[0];j=1;count=0;k=0;
     	for (i=1;i<7;i++){
     		if (cardnumber[i-1]!=cardnumber[i]){
     			dis[j++]=cardnumber[i];
     		}
     		else {count++;
     		p[k++]=cardnumber[i];
     		}	
     			}
    for (i=1;i<=count;i++){
     		dis[7-i]=0;
     		}
     	
    //  for ROYAL FLUSH 
    //  for confirmation of cards are of same suit 
        if (d==3 && dis[6]==14 && dis[2]==10){
          pro_sum=1;
           
          //system("PAUSE");
           fclose(z);return pro_sum;
          }
       else if (d==2 && card[position]%13==1 && (card[position+1]%13==10 || card[position+2]%13==10) && (card[position+2]%13==11 || card[position+3]%13==11) && (card[position+3]%13==12 || card[position+4]%13==12) && card[position+5]%13==0 ){
           pro_sum=1;
           
          //system("PAUSE");
           fclose(z);return pro_sum;
          }
       else if(d==1 && card[position]%13==1 && card[position+1]%13==10 && card[position+2]%13==11 && card[position+3]%13==12 && card[position+4]%13==0){
           pro_sum=1;
            
          //system("PAUSE");
           fclose(z);return pro_sum;
           }
       
    // resulted combination will be royal flush 
    //for straight flush 
     for (i=1;i<8;i++){
        fgets(pro,100,z);
        }
                             
     if (d>0){
         if ((card[position+2]+4)==card[position+6]){
         	highest_card=(card[position+6]-1)%13+1; 
         	for (i=0;i<=(13-highest_card);i++){
             	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
            	}
         	 
         	//system("PAUSE");
         	 fclose(z);return pro_sum;
         	}
     	else if ((card[position+1]+4)==card[position+5]){
          	highest_card=((card[position+5]-1)%13)+1;
         	for (i=0;i<=(13-highest_card);i++){
             	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
            	}
             
            //system("PAUSE");
             fclose(z);return pro_sum;
         	}
         else if ((card[position]+4)==card[pos+4]){
            highest_card=((card[position+4]-1)%13)+1;
         	for (i=0;i<=(13-highest_card);i++){
             	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
            	}
             
            //system("PAUSE");
             fclose(z);return pro_sum;
            }
   		}
      
     for (i=1;i<11;i++){
        fgets(pro,100,z);
        }
                                
     if (cardnumber[3]==cardnumber[6]){
        for (i=0;i<=(14-cardnumber[6])*12+13-cardnumber[2];i++){
        fgets(pro,100,z);
        }
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
            }
         
         //system("PAUSE");
          fclose(z);return pro_sum;
       }
     else if (cardnumber[2]==cardnumber[5]){
        for (i=0;i<=(14-cardnumber[5])*12+14-cardnumber[6];i++){
        fgets(pro,100,z);
        }
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
            }
          
         //system("PAUSE");
          fclose(z);return pro_sum;
        }                                         
     else if (cardnumber[1]==cardnumber[4]){
        for (i=0;i<=(14-cardnumber[4])*12+14-cardnumber[6];i++){
        fgets(pro,100,z);
        }
      
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
            }
          
         //system("PAUSE");
          fclose(z);return pro_sum;
       }                                          
                                               
     else if (cardnumber[0]==cardnumber[3]){
        for (i=0;i<=(14-cardnumber[3])*12+13-cardnumber[6];i++){
        fgets(pro,100,z);
        }
        
        for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
            }
          
         //system("PAUSE");
          fclose(z);return pro_sum;
       } 
      for (i=0;i<157;i++){
        fgets(pro,100,z);
        }
     if ((cardnumber[4]==cardnumber[6]) && ((cardnumber[1]==cardnumber[2]) || (cardnumber[0]==cardnumber[1]) || (cardnumber[2]==cardnumber[3]))){
         if (cardnumber[2]==cardnumber[3]){
            a=cardnumber[4];b=cardnumber[3];
            }
         else if (cardnumber[1]==cardnumber[2]){
            a=cardnumber[4];
            b=cardnumber[2];
            }
         else if (cardnumber[0]==cardnumber[1]){
            a=cardnumber[4];
            b=cardnumber[1];
            }
         if (a==1){
            for (i=0;i<((14-a)*12+(14-b));i++){
                fgets(pro,100,z);
                }
             for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }
         	 
         //system("PAUSE");
          fclose(z);return pro_sum;
         }
         else {
             for (i=0;i<((14-a)*12+(16-b));i++){
             if (i==(14-a)){continue;}
             fgets(pro,100,z);
             }
             for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
            }
            
         } 
         //system("PAUSE");
          fclose(z);return pro_sum;
           

     }
      if ((cardnumber[3]==cardnumber[5]) && ((cardnumber[1]==cardnumber[2]) || (cardnumber[0]==cardnumber[1]))){
         if (cardnumber[2]==cardnumber[1]){
            a=cardnumber[5];
            b=cardnumber[2];
            }
         else if (cardnumber[0]==cardnumber[1]){
            a=cardnumber[5];
            b=cardnumber[1];
            }
         for (i=0;i<((14-a)*12+(16-b));i++){
             if (i==(14-a)){continue;}
             fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
       }
        
         //system("PAUSE");
          fclose(z);return pro_sum;
            
     }    
      if ((cardnumber[2]==cardnumber[4]) && ((cardnumber[0]==cardnumber[1]) || (cardnumber[6]==cardnumber[5]))){
         if (cardnumber[5]==cardnumber[6]){
            a=cardnumber[4];
            b=cardnumber[5];
            }
         else if (cardnumber[0]==cardnumber[1]){
            a=cardnumber[4];
            b=cardnumber[0];
            }
         for (i=0;i<((14-a)*12+(16-b));i++){
             if (i==(14-a)){continue;}
             fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
       }
        
         //system("PAUSE");
          fclose(z);return pro_sum;
            
         }    
      if ((cardnumber[1]==cardnumber[3]) && ((cardnumber[5]==cardnumber[6]) || ((cardnumber[3]==cardnumber[4])))){
         if (cardnumber[5]==cardnumber[6]){
            a=cardnumber[3];
            b=cardnumber[6];
            }
         else if (cardnumber[3]==cardnumber[4]){
            a=cardnumber[3];
            b=cardnumber[4];
         }
         for (i=0;i<((14-a)*12+(15-b));i++){
             if (i==(14-a)){continue;}
             fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
            
            }
        
         //system("PAUSE");
          fclose(z);return pro_sum;
         }    
      if ((cardnumber[0]==cardnumber[2]) && ((cardnumber[3]==cardnumber[4]) || (cardnumber[4]==cardnumber[5]) || (cardnumber[5]=cardnumber[6]))){
         if (cardnumber[5]==cardnumber[6]){
            a=cardnumber[2];
            b=cardnumber[6];
            }
         else if (cardnumber[4]==cardnumber[5]){
            a=cardnumber[2];
            b=cardnumber[5];
            }
         else if (cardnumber[3]==cardnumber[4]){
            a=cardnumber[2];
            b=cardnumber[4];
            }
         for (i=0;i<((14-a)*12+(16-b));i++){
             if (i==(14-a)){continue;}
             fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
             }
       	 
        //system("PAUSE");
         fclose(z);return pro_sum;
            
     }
     
      for (i=0;i<157;i++){
        fgets(pro,100,z);
        }
     if (((card[0]-1)/13==(card[4]-1)/13) || ((card[1]-1)/13==(card[5]-1)/13) || ((card[2]-1)/13==(card[6]-1)/13)){
        if  ((card[2]-1)/13==(card[6]-1)/13){
        	if ((((card[1]-1)/13==(card[2]-1)/13) && (card[1]%13==1)) || (((card[0]-1)/13==(card[2]-1)/13) && (card[0]%13==1)) || card[2]%13==1){
        		for (i=0;i<((45-((((card[6]-1)%13+1)-4)*(((card[6]-1)%13+1)-3))/2)+((card[6]-1)%13+1)-(card[5]%13));i++){
                fgets(pro,100,z);
                }
             	for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }                   
              	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
           else {
           		a=(card[6]+11)%13+2;b=(card[5]+11)%13+2;c=(card[4]+11)%13+2;
           		for (i=0;i<(164-(((a-5)*(a-4)*(2*a-9))/6+(a-4)*(a-5)/2)/2+(a-5)*(a-4)/2-(b-3)*(b-4)/2+b-c);i++){
                fgets(pro,100,z);
                }
             	for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }                   
              	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
           
           
           
           
           
           
           }
           if  ((card[1]-1)/13==(card[5]-1)/13){
        	if ((((card[0]-1)/13==(card[1]-1)/13) && (card[0]%13==1)) || card[1]%13==1){
        		for (i=0;i<((45-((((card[5]-1)%13+1)-4)*(((card[5]-1)%13+1)-3))/2)+((card[5]-1)%13+1)-(card[4]%13));i++){
                fgets(pro,100,z);
                }
             	for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }                   
              	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
           else {
           		a=(card[5]+11)%13+2;b=(card[4]+11)%13+2;c=(card[3]+11)%13+2;
           		for (i=0;i<(164-(((a-5)*(a-4)*(2*a-9))/6+(a-4)*(a-5)/2)/2+(a-5)*(a-4)/2-(b-3)*(b-4)/2+b-c);i++){
                fgets(pro,100,z);
                }
             	for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }                   
              	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
           
            }
           if  ((card[0]-1)/13==(card[4]-1)/13){
        	if (card[0]%13==1){
        		for (i=0;i<((45-((((card[4]-1)%13+1)-4)*(((card[4]-1)%13+1)-3))/2)+((card[4]-1)%13+1)-(card[3]%13));i++){
                fgets(pro,100,z);
                }
             	for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }                   
              	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
            else {
           		a=(card[4]+11)%13+2;b=(card[3]+11)%13+2;c=(card[2]+11)%13+2;
           		for (i=0;i<(164-(((a-5)*(a-4)*(2*a-9))/6+(a-4)*(a-5)/2)/2+(a-5)*(a-4)/2-(b-3)*(b-4)/2+b-c);i++){
                fgets(pro,100,z);
                }
             	for (i=1;i<7;i++){
                 temp=temp*10;
                 pro_sum=pro_sum+(pro[20+i]-48)/temp;
                 }                   
              	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
           
            
            }
           
           
            }
            
            for (i=0;i<164;i++){
        	fgets(pro,100,z);
        	}
     	
     	if (dis[6]==dis[5]+1 && dis[6]==dis[4]+2 && dis[6]==dis[3]+3 && dis[6]==dis[2]+4){
     		for (i=0;i<15-dis[6];i++){
            fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
       }
         	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
 
 	if (dis[5]==dis[4]+1 && dis[5]==dis[3]+2 && dis[5]==dis[2]+3 && dis[5]==dis[1]+4){
     		for (i=0;i<15-dis[5];i++){
            fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
       }
         	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
        		
        		if (dis[4]==dis[3]+1 && dis[4]==dis[2]+2 && dis[4]==dis[1]+3 && dis[4]==dis[0]+4){
     		for (i=0;i<15-dis[4];i++){
            fgets(pro,100,z);
             }
         for (i=1;i<7;i++){
             temp=temp*10;
             pro_sum=pro_sum+(pro[20+i]-48)/temp;
       }
         	 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
 
		if (dis[6-count]==14 && dis[0]==2 && dis[0]==dis[1]-1 && dis[0]==dis[2]-2 && dis[0]==dis[3]-3){
			pro_sum=0.900129;
			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
 
 
 		for (i=0;i<11;i++){
        	fgets(pro,100,z);
        	}
     	
 		if (cardnumber[4]==cardnumber[6]){
 			if (cardnumber[4]==14){
 				for (i=0;i<14-cardnumber[3];i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 			}
 			else {
 				for (i=0;i<8+(13-cardnumber[6])*9+14-cardnumber[3];i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 			}
 			}
 
			if (cardnumber[3]==cardnumber[5]){ 
 				for (i=0;i<8+(13-cardnumber[5])*9+15-cardnumber[6];i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 				}
 			if (cardnumber[2]==cardnumber[4]){ 
 				for (i=0;i<8+(13-cardnumber[4])*9+15-cardnumber[6];i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
       		 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
       			}
 			if (cardnumber[1]==cardnumber[3]){ 
 				for (i=0;i<8+(13-cardnumber[1])*9+15-cardnumber[6];i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
       		 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
       			}
 			if (cardnumber[0]==cardnumber[2]){ 
 				for (i=0;i<8+(13-cardnumber[2])*9+15-cardnumber[6];i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 				}
 
 			for (i=0;i<120;i++){
        	fgets(pro,100,z);
        	}
     	
     	if (count==2 || count==3){
     		a=p[1];b=p[0];
     		for (i=6;i>=0;i--){
     			if (cardnumber[i]==p[1] || cardnumber[i]==p[0]){
     				continue;
     				}
     			else {
     				c=cardnumber[i];pos=i;break;
     				}
     			}
     		if (a<c){
     			for (i=0;i<780-(5*(a-1)*(a-2))+14-a+(a-b-1)*10+15-c;i++){
            		fgets(pro,100,z);
             		}
         		for (i=1;i<7;i++){
             		temp=temp*10;
             		pro_sum=pro_sum+(pro[20+i]-48)/temp;
       				}
 				 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        		}
 			if (c>b && c<a){
 				for (i=0;i<780-(5*(a-1)*(a-2))+14-a+(a-b-1)*10+14-c;i++){
            		fgets(pro,100,z);
             		}
         		for (i=1;i<7;i++){
             		temp=temp*10;
             		pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 				}
 			
 			if (c<b){
 				for (i=0;i<780-(5*(a-1)*(a-2))+14-a+(a-b-1)*10+13-c;i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        	//system("PAUSE");
        	 fclose(z);return pro_sum;
        	
 			}
 			
 		}
 			for (i=0;i<793;i++){
        	fgets(pro,100,z);
        	}
 			if (count==1){
 				a=p[0];
 				for (i=6;i>=0;i--){
 					if (cardnumber[i]==a){continue;}
 					else {b=cardnumber[i];break;}
 					}
 				for (j=i-1;j>=0;j--){
 					if (cardnumber[j]==a){continue;}
 					else {c=cardnumber[j];break;}
 					}
 				
 				if (p[0]==14){
 					for (i=0;i<13-(b*b-11*b)/2+b-c;i++){
            			fgets(pro,100,z);
             			}
         			for (i=1;i<7;i++){
             			temp=temp*10;
             			pro_sum=pro_sum+(pro[20+i]-48)/temp;
       					}
 					 
        			//system("PAUSE");
        			 fclose(z);return pro_sum;
        			}
 				else if(p[0]>5) {
 					if (b==14){
 						for (i=0;i<28+34*(13-a)+14-c;i++){
            				fgets(pro,100,z);
             				}
         				for (i=1;i<7;i++){
             				temp=temp*10;
             				pro_sum=pro_sum+(pro[20+i]-48)/temp;
       						}
 						 
        				//system("PAUSE");
        				 fclose(z);return pro_sum;
        				}
 				
 					else if (b>a){
 						for (i=0;i<28+34*(13-a)+7+28-(b-6)*(b-5)/2+b-c;i++){
            				if (i-(28+34*(13-a)+7+28-(b-6)*(b-5)/2+b-a)==0 && b>a){
            					continue;
            					}
            				fgets(pro,100,z);
             				}
         				for (i=1;i<7;i++){
             				temp=temp*10;
             				pro_sum=pro_sum+(pro[20+i]-48)/temp;
       						}
 						 
        				//system("PAUSE");
        				 fclose(z);return pro_sum;
        				}
 			
 					else if (b<a){
 						for (i=0;i<28+34*(13-a)+7+28-(b-5)*(b-4)/2+b-c;i++){
     						fgets(pro,100,z);
             				}
         				for (i=1;i<7;i++){
             				temp=temp*10;
             				pro_sum=pro_sum+(pro[20+i]-48)/temp;
       						}
 						 
        				//system("PAUSE");
        				 fclose(z);return pro_sum;
        				}
 					}
 				for (i=0;i<301;i++){
        			fgets(pro,100,z);
        			}
 				if(p[0]==5){
 					for (i=0;i<36-(b-6)*(b-5)/2+b-c;i++){
            	      	fgets(pro,100,z);
             		}
         		for (i=1;i<7;i++){
             		temp=temp*10;
             		pro_sum=pro_sum+(pro[20+i]-48)/temp;
       				}
 				 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 				}
 
 			for (i=0;i<36;i++){
        	fgets(pro,100,z);
        	}
 			if(p[0]<5){
 				
 				
 			for (i=0;i<43*(4-a)+45-(b-5)*(b-4)/2+b-c;i++){
            	if (i-43*(4-a)==8){continue;}
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 				}
 }
 	
 		for (i=0;i<467;i++){
        	fgets(pro,100,z);
        	}
 			if (count==0){
 				a=cardnumber[6];
 				b=cardnumber[5];
 				c=cardnumber[4];
 				for (i=0;i<(112-(a*(a+1)*(2*a+1)/6-15*a*(a+1)/2+56*a)/2+(a-8)*(a-7)/2-(b-7)*(b-6)/2+b-c);i++){
            	fgets(pro,100,z);
             	}
         	for (i=1;i<7;i++){
             	temp=temp*10;
             	pro_sum=pro_sum+(pro[20+i]-48)/temp;
       			}
 			 
        		//system("PAUSE");
        		 fclose(z);return pro_sum;
        	
 				}
 
            
            //system("PAUSE");
             fclose(z);return pro_sum;
            
    }
