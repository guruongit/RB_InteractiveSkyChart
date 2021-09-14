
#include<stdio.h>
int date(int day, int month, int year);
void time(int hour, int minute);
void zodiac(int z);
int leapyear(int lp);
void presentconst(int SAVI, int EAVI, int NSVI, int SSVI );    // calculates contellation present in sky
int tminute(int hour, int minute);  // calculate total minute in+degree
void AVI(int month, int day, int tminute, int temp[]);   //calculate present avi, #can be by current date&time, # in current day,
void SVI(int day,int SAVI, int EAVI,int temp[]);         // calculate present svi
int nightlenght(int month);            // to Calculate Night Length, On 30 degree N latitude, india has 28.38'N
void displayconst();                    // To display indivitual constellation
void displayconstchart(int SAVI, int EAVI, int NSVI,int SSVI );               // To display constellation Chart of that day
void location(int SAVI, int EAVI, int NSVI,int SSVI );                      // to update const map accorting to location taking delhi as reference 
//void wheretolook();                // function to tell where to chase the star      

struct constellation
{   
	char name[12];
    int startd;
    int endd;
	float AVI;  //Apperence_View_Index (values of this index lie in range from 0 to 360), Values are in minute degree*10, of Centeral star
    float SVI;  //Side_View_Index (values of this index lie in range from -90 to +90), of central star.
	int stari;    //have assigned No. of stars from which it consitutute of.
    //float LI;   // Luminious_Index
	//char DIVX;  // Direction of view Index(S,T,N)
   // int snum;     //Include No. of Stars belong to that constellation
   // int cstar;       // to identify the central star
};


struct star
{
    char name[20];
    float AVI;
    float SVI;
    int cnum;   // belongs to constelation num
    int cstar;   // to identify that does this star is a central star of a constellation by using 1 as NOT and 0 as yes
};

    struct constellation C[100]={{"Aquarius",20,50,48.02, -37.88},{"Pisces",51,79,137.01, -46.43},{"Aries",80,110,144.57, -36.2},{"Taurus",111,140,144.57, -36.2},{"Gemini",141,171,192.23, 23.41},{"Cancer",172,203,214.25, 23.05},{"Leo",204,234,226.43,48.94},{"Virgo",235,263,316.11, 50.84},{"Libra",264,295,352.02, 39.23},{"Scorpius",296,326,351.95, 15.06},{"Sagittarius",327,355,359.2, -9.81},{"Capricornus",356,365,37.6, -46.01},{"Capricornus",1,19,376,2} };


     /*struct constellation C[1] ={"Aquarius",20,50}; 
     struct constellation C[2]={"Pisces",51,79};
    struct constellation C[3]={"Aries",80,110};
    struct constellation C[4]={"Taurus",111,140};
    struct constellation C[5]={"Gemini",141,171};
    struct constellation C[6]={"Cancer",172,203};
    struct constellation C[7]={"Leo",204,234};
    struct constellation C[8]={"Virgo",235,263};
    struct constellation C[9]={"Libra",264,295};
    struct constellation C[10]={"Scorpio",296,326};
    struct constellation C[11]={"Sagittarius",327,355};
    struct constellation C[12]={"Capricorn",356,365};
    struct constellation C[13]={"Capricorn",1,19,7200,-16};*/

   struct star S[1000]={{"41 C Ari",208368.000000, 50.400002,2},{"Alp Ari", 184368.000000, 50.400002,2}, {"Bet Ari" ,223812.000000, 52.330002,2}, {"GAM01 Ari", 225156.000000, 52.130001,2}};
    
struct planet
{
    char name[20];
    float AVI;
    float SVI;
    int cnum;   // belongs to constelation num
    //int cstar;   // to identify that does this star is a central star of a constellation by using 1 as NOT and 0 as yes
};

struct sattelite
{
    char name[20];              // include moon
    float AVI;
    float SVI;
    int cnum;   // belongs to constelation num
    //int cstar;   // to identify that does this star is a central star of a constellation by using 1 as NOT and 0 as yes
};




int main()
{   int day; int month; int year; int hour; int minute; int q; int z; int t;  
    int temp[10];
    printf("Hi, What are you looking for?\nEnter the task no. you want to perform\n");
    printf("1. Wanted to know my Zodiac Sign \n2. Tell me something about todays night sky \n3. Display Todays night sky chart \n4. Display constellation x \n5. Where to look for - search \n");
    printf("Enter the task no. you want to perform: ");
    scanf("%d",&q);
    switch(q)
    {
        case 1: {   printf("Enter Date in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    z = date(day, month, year);
                    zodiac(z);
                    break;

                }

        case 2: {   
                    printf("Enter Date in format dd/mm/yyyy");
	                scanf("%d %d %d", &day, &month, &year);
                    printf("\nEnter Time in format hh/mm");
                    scanf("%d %d", &hour, &minute);
                    z = date(day, month, year);
                    printf("%d st/nd/rd/th day of the year", z);
                    time( hour, minute);
                    t=tminute(hour,minute);
                    AVI(month, z, t, temp);
                    location(temp[0], temp[1],  temp[2], temp[3]);
                    break;
                }

        case 3:{
                    printf("Enter Date in format dd/mm/yyyy");
	                scanf("%d %d %d", &day, &month, &year);
                    printf("\nEnter Time in format hh/mm");
                    scanf("%d %d", &hour, &minute);
                    z = date(day, month, year);
                    printf("%d st/nd/rd/th day of the year", z);
                    time( hour, minute);
                    t=tminute(hour,minute);
                    AVI(month, z, t, temp);
                    location(temp[0], temp[1],  temp[2], temp[3]);
                     char c; char ec ;
                    printf("Wanted to see present sky chart y/n ");
                    scanf("%c",&ec); 
                    scanf("%c",&c);
                    if(c=='y')
                    //printf("working");
                    displayconstchart( temp[0], temp[1],  temp[2], temp[3] );
                    printf("Wanted to see any specific constellation y/n "); 
                    scanf("%c",&ec);
                    scanf("%c", &c); 
                    if(c=='y')
                    displayconst();
                    break;
                    
                    break;

                }
        case 4:{
                    displayconst();
                    break;
                }
        case 5:
                {
                    //wheretolook();
                    break;
                }
    }

	/*printf("Enter Date in format dd/mm/yyyy");
	scanf("%d %d %d", &day, &month, &year);
    printf("\nEnter Time in format hh/mm");
    scanf("%d %d", &hour, &minute);
	
    z = date(day, month, year);
    zodiac(z);
    
    t=tminute(hour,minute);
    time( hour, minute);  
    displayconst();
	printf("Day is %d\n", z);
    AVI(month, z, t);*/
    
    
    
    
    


	return 0;
}
int date(int a, int b, int c)
{ 	
    //printf("Date is");
	//printf("%d %d %d", a, b, c);
    /*int p=1; int q=1; int r=1; int s=0;
    for(p;p<b;p++)
    {   s++;
        
    }
    for(q;q<a;q++)
        {
            r++;
        }
    int t,m;
    t =  s*30;
    m= t+r;
    printf("Day is %d\n", m);
    printf("%d is not a leap year.", year);*/
    int mdur[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int w;
    w=leapyear(c);
    
    if(w==1)
    {
    mdur[2]=mdur[2]+1;
    //printf("%d is a leap year.\n", c);
    }
    else
    {  
        
     //printf("\n %d is not a leap year.\n", c);
    }
    int x=0;
    int y;
    for(int u=0;u<b;u++)
    {    
        x = x + mdur[u]; 
        // printf("%d",x);

    }
    y=(x+a);
   // printf("%d rd/th day of the year", y);
    return y;
    
}
void time(int h, int m)
{
    //int segment; int alpa;
    //segment= 2*h;
    printf("\n");
    if(h>7&&h<18)
    {
        printf("Sorry, no stars will be available in day\n");
        }
    else
    {
        printf("Enjoy the momment\n");
    }
    
}
void zodiac(int q)
{   
    
   /* if(C1.startd<=q&&C1.endd>=q)
    printf("\nYour Zodiac Sign is %s",C1.name);
    else if(C2.startd<=q&&C2.endd>=q)
    printf("\nYour Zodiac Sign is %s",C2.name);
    else if(C3.startd<=q&&C3.endd>=q)
    printf("\nYour Zodiac Sign is %s",C3.name);
    else if(C4.startd<=q&&C4.endd>=q)
    printf("\nYour Zodiac Sign is %s",C1.name);
    else if(C5.startd<=q&&C5.endd>=q)
    printf("\nYour Zodiac Sign is %s",C5.name);
    else if(C6.startd<=q&&C6.endd>=q)
    printf("\nYour Zodiac Sign is %s",C6.name);
    else if(C7.startd<=q&&C7.endd>=q)
    printf("\nYour Zodiac Sign is %s",C7.name);
    else if(C8.startd<=q&&C8.endd>=q)
    printf("\nYour Zodiac Sign is %s",C8.name);
    else if(C9.startd<=q&&C9.endd>=q)
    printf("\nYour Zodiac Sign is %s",C9.name);
    else if(C10.startd<=q&&C10.endd>=q)
    printf("\nYour Zodiac Sign is %s",C10.name);
    else if(C11.startd<=q&&C11.endd>=q)
    printf("\nYour Zodiac Sign is %s",C11.name);
    else if(C12.startd<=q&&C12.endd>=q)
    printf("\nYour Zodiac Sign is %s",C12.name);
    else if(C13.startd<=q&&C13.endd>=q)
    printf("\nYour Zodiac Sign is %s",C13.name);
    else
    printf("\nYou are not born on earth");*/

    for(int i=1;i<14;i++)
    {
        if(C[i].startd<=q&&C[i].endd>=q)
         {printf("\nYour Zodiac Sign is %s",C[i].name);}
    }

}
/* void presentconst()
{
   if(C1.AVIs<=q&&C1.AVIe>=q)
    printf("\nConstellation %s is present",C1.name);
   if(C2.startd<=q&&C2.endd>=q)
    printf("\nConstellation %s is present",C2.name);
  
}*/
int leapyear(int lp)
{  int x;
   if (lp % 400 == 0) {
      x=1;
   }
   else if (lp % 100 == 0) {
      x=0;
   }
   else if (lp % 4 == 0) {
     x=1;
   }
   else {
      x=0;
   }
   return x;
}
int tminute(int a, int b)
{
    int c;
    int d;
    c= a*60;
    d= c+b;
    printf("\n%d\n",d);
    return d;
  //  return d;
}
void AVI(int month, int day, int tminute, int temp[])
{
    float CAVIM=0;  // Current Avi index in minute, intiating from 0 coresponds to 00:00 AM of 1st jan  // update, doing day update only
    float CAVID=0;  // Current Avi index in degree minute, intiating from 0 coresponds to 00:00 AM of 1st jan
    //CAVIM=((day-1)*1440)+tminute;
    CAVID= tminute*0.25;     // 10 is used to convert decimal into int type and in degree minutes
    CAVIM=(CAVID+((day-1)*0.98));
    if(CAVIM>360)
    CAVIM=(CAVIM-360);
    printf("AVI is %d\n",CAVIM);
    int SAVI=0;                  // SAVI is Starting AVI, indicates star present near east or starting range of visible stars.
    int EAVI=0;
    int a,b;
    a=nightlenght(month);  // EAVI is Ending AVI, indicates star present near west or ending range of visible stars.
    b =a/2;
    SAVI= CAVIM - (b*60*0.25);   // b is the value of N/2, where N is the value of night length.
    if(SAVI<0)
    SAVI=(360+SAVI);
    EAVI= CAVIM + (b*60*0.25);
    printf("\nSAVI is %d  EAVI is %d",SAVI,EAVI);
    SVI(day, SAVI, EAVI, temp);
    


}
void SVI(int day,int SAVI, int EAVI, int temp[])
{     
    int a[37]={0,0,-3,-6,-9,-12,-15,-18,-21,-23,-23,-21,-18,-15,-12,-9,-6,-3,0,0,3,6,9,12,15,18,21,23,23,21,18,15,12,9,6,3,0};
    int t=day/10;   //9.6
    
    int NSVI=0;      //Northern SVI
    int SSVI=0;      //Southern SVI
    NSVI=66+a[t];    //starting from 90 because it does not cross the limit of 90
    SSVI=(-(66-a[t]));
    
    printf("\nNSVI is %d  SSVI is %d",NSVI,SSVI);
    //int teama[5];
    temp[0]=SAVI;
    temp[1]=EAVI;
    temp[2]=NSVI;
    temp[3]=SSVI;


    //location(SAVI, EAVI,  NSVI, SSVI );
    //return teama[];
    //presentconst(SAVI, EAVI,  NSVI, SSVI );
    

}
int nightlenght(int month)   
{  
    int sunr[13]= {0,416,411,388,349,317,300,302,318,344,353,373,398};   // in Minutes
    int suns[13]= {0,1032,1057,1078,1099,1117,1136,1145,1135,1102,1065,1034,1020};  
    int dayl,daylm;
    daylm= suns[month]-sunr[month];
    dayl=daylm/60;

    int nightl;
    nightl=24-dayl;
    printf("\nNight is of %d hours ",nightl);
    return nightl;

}

void presentconst(int SAVI, int EAVI, int NSVI,int SSVI )
{   printf("\nConstellation Present are");
   
    for(int i=1;i<100;i++)
    {   
        if(SAVI>EAVI)
        {   
            if(C[i].SVI>0)
            {   
                if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
                else if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
            }
            else if(C[i].SVI<0)
            {
                if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
                else if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
            }

        }
        else if(EAVI>SAVI)
        {
            if(C[i].SVI>0)
            {   
                if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
                else if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
            }
            else if(C[i].SVI<0)
            {
                if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
                else if(C[i].AVI>0)
                {
                    if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
                    {
                        printf("\n%d. %s",i,  C[i].name);
                    }
                    
                }
            }
            
        }

  
   
    }
    /*char c;
    printf("Wanted to see present sky chart y/n ");
    char ec ;
    scanf("%c",&ec); 
    scanf("%c",&c);
    if(c=='y')
    //printf("working");
    displayconstchart( SAVI,  EAVI,  NSVI, SSVI );*/

}

void displayconst()
{   int a;  
    printf("Which Constellation do you wants to see type its no from the above list.");
    scanf("%d",&a);
    for(int i=0;i<100;i++)            //76/3=25
    {
        for(int j=0;j<100;j++)            // 361/6=60
        {   int p,q;
            for(int k=0;((k<100)&&(S[k].cnum==a));k++)
            {
            q=S[k].AVI/4000;             // C[i]!=S[i]  //2160
            p=S[k].SVI;
            //if(p==i&&q==j&&S[k].cstar==0)
            //break;
            //else 
            if(p==i&&q==j)
            break;
            }
            if(i==0||i==99)
            printf("-");
            else if((i>0||i<98)&&(j==0||j==99))
            printf("|");
            else if(p==i&&q==j)
            printf("*");
            else
            {
                printf(" ");
            }   
        }
        printf("\n");
    }
    printf("                          %s",C[a].name);
    
    
     /*int l = C[a].AVI;
    int m = C[b].SVI;
    int i =0,j=0;
    while(i<200||j<200)
    {
        if(i==m)
        {    if(j==l)
            { 
                printf("*");
                break;
            }
            else
            {
                i++
            }

        }


    }*/


}
void displayconstchart(int SAVI, int EAVI, int NSVI,int SSVI )
{   
    printf("The Sky\n");
    int p,q;
    for(int i=0;i<27;i++)            //76/3=25
    {
        for(int j=0;j<61;j++)            // 361/6=60
        {   
            for(int k=0;k<100;k++)
            {
            if((C[k].AVI<=SAVI&&C[k].AVI>=EAVI&&C[k].SVI<=NSVI&&C[k].SVI<=SSVI))
            {
                p=S[k].SVI/4000;             // C[i]!=S[i]
            q=S[k].AVI/60;
            if(p==i&&q==j)
            break;
            }
            }
            if(i==0||i==26)
            printf("-");
            else if((i>0||i<55)&&(j==0||j==60))
            printf("|");
            else if(p==i&&q==j)
            printf("*");
            else
            printf(" ");              
            
            /*if(p=i&&q==j&&S[].cstar==1)
            {
                print("%s",S[].name);
                int a = S[].name;  //count of alphabet used
                j=j+a;
            }*/     // Central star of a constellation ke side me uska nam
            
            
        }
        printf("\n");
    }
    /*char c; char ec ;
    printf("Wanted to see any specific constellation y/n "); 
    scanf("%c",&ec);
    scanf("%c", &c); 
    if(c=='y')
    displayconst(); */

}
void location(int SAVI, int EAVI, int NSVI,int SSVI )
{   float la,lo,rla,rlo; char ec ;
    printf("\nEnter your location Latitude: ");
    //scanf("%c",&ec);
    scanf("%f",&la);
  
    printf("\nEnter your location Longutide: ");
    scanf("%f",&lo);
    // printf("%f %f",la , lo);
     

    /*if(la ==28.70&& lo ==77.10)            // For to Reduce program Running Time
    {  
        presentconst(SAVI, EAVI,  NSVI, SSVI );
    }
    else
    {*/
    
        int tavi,tsvi;    // tavi is a temprary variable that holds the difference b/w tavi and tsvi
        rla =28.7041; rlo =77.1025;
        tavi= (rla-la)*0.25;    // in degree minutes 
        tsvi= rlo-lo;           //in minutes
        if(tavi<0)
        tavi=tavi*(-1);
        if(tsvi<0)
        tsvi=tsvi*(-1);
        if(tsvi>24)
        tsvi=23;
        
        SAVI=SAVI+tavi;
        EAVI=EAVI+tavi;
        NSVI=NSVI+tsvi;
        SSVI=SSVI+tsvi;
        printf("%d %d %d %d",SAVI, EAVI,  NSVI, SSVI);
        // displayconstchart( SAVI,  EAVI,  NSVI, SSVI );
        presentconst(SAVI, EAVI,  NSVI, SSVI );           // New AVI,SVI confrigation as per new location
    //} 
    

}
