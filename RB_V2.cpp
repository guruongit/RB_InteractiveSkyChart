// Libraries
#include<iostream>
#include<math.h>
#include<cstring>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

//Functions
int date(int day, int month, int year);
void timeq(int hour, int minute);
int leapyear(int lp);
void presentconst(int SAVI, int EAVI, int NSVI, int SSVI);    // calculates contellation present in sky
void location(int SAVI, int EAVI, int NSVI,int SSVI , int temp[]);                      // to update const map accorting to location taking delhi as reference 
int tminute(int hour, int minute);  // calculate total minute in+degree
void AVI(int month, int day, int tminute, int temp[]);   //calculate present avi, #can be by current date&time, # in current day,
void SVI(int day,int SAVI, int EAVI,int temp[]);         // calculate present svi
int nightlenght(int month);            // to Calculate Night Length, On 30 degree N latitude, india has 28.38'N
void displayconst();                    // To display indivitual constellation
void displayconstchart(int SAVI, int EAVI, int NSVI,int SSVI );               // To display constellation Chart of that day
void wheretolook(int cx, int cy, int temp[], int nc);                // function to tell where to chase the star      
void compass(int cx, int cy, int nc, int quad);
void read(string file_name);

class spot
{
    public:
    string name;
    float AVI;
    float SVI;
};


// Classes
class constellation: public spot
{   
    
    
    private:
    int startd;
    int endd;
    
    public:
	  //Apperence_View_Index (values of this index lie in range from 0 to 360), Values are in minute degree*10, of Centeral star
      //Side_View_Index (values of this index lie in range from -90 to +90), of central star.
	//int stari;
    
    constellation( string a, int b, int c, float d, float e)
    {
        name = a ; startd =b; endd = c; AVI = d; SVI =e; 
    }
    void zodiac(int q);
  
};



class star: public spot
{   
    public:
    
    
    int cnum;   // belongs to constelation num
    //int cstar;   // to identify that does this star is a central star of a constellation by using 1 as NOT and 0 as yes
    star( string a, float b, float c, int d)
    {
        name = a ; AVI =b; SVI = c; cnum = d; 
    }
};

class star1: public spot
{   
    public:
    
       // belongs to constelation num
    //int cstar;   // to identify that does this star is a central star of a constellation by using 1 as NOT and 0 as yes
 
    star1( string a, float b, float c)
    {
        name = a ; AVI =b; SVI = c; 
    }
    
    
};

vector <star1> S1;


//Objects
constellation C[] = {constellation("Aquarius",20,50,48.02, -37.88),constellation("Pisces",51,79,137.01, -46.43),constellation("Aries",80,110,144.57, -36.2),constellation("Taurus",111,140,144.57, -36.2),constellation("Gemini",141,171,192.23, 23.41),constellation("Cancer",172,203,214.25, 23.05),constellation("Leo",204,234,226.43,48.94),constellation("Virgo",235,263,316.11, 50.84),constellation("Libra",264,295,352.02, 39.23),constellation("Scorpius",296,326,351.95, 15.06),constellation("Sagittarius",327,355,359.2, -9.81),constellation("Capricornus",356,365,37.6, -46.01),constellation("Capricornus",1,19,376,2)};

star S[] = {star("β Aquarii", 48.02, -37.88,1),star("α Aquarii", 59.93,-42.07 ,1),star("δ Aquarii", 49.58, -60.671,1),star("88 Aquarii", 41.76, -66.03,1),star("λ Aquarii",62.19 , -55.73,1),star("ε Aquarii",37.68 , -30.1,1),star("γ Aquarii",62.18 ,-45.84 ,1),star("98 Aquarii", 47.35,-68.59 ,1),star("τ2 Aquarii", 52.27,-58.52 ,1),star("η Aquarii", 66.84,-47.61 ,1),star("Ancha",53.51 ,-48.62 ,1),star("ψ1 Aquarii", 67.07,-61.11 ,1),star("φ Aquarii", 70.94,-58.74 ,1),star("ι Aquarii", 43.51,-49.37 ,1),star("99 Aquarii", 46.74,-69.46 ,1),star("ψ2 Aquarii", 67.62,-61.54 ,1),star("3 Aquarii", 42.24, -28.09,1),star("zeta2 Aquarii", 65.35,-46.33 ,1),star("86 Aquarii", 35.23, -66.15,1),star("omega2 Aquarii", 67.66, -69.64,1),star("eta Piscium", 137.01,-46.43,2),star("gamma Piscium",82.47 ,-52.02 ,2),star("omega Piscium", 100.69,-53.74,2),star("iota Piscium", 92.46,-52.96,2),star("omicron Piscium", 144.61, -51.43,2),star("epsilon Piscium", 127.89, -54.87,2),star("theta Piscium", 88.81,-50.88 ,2),star("alpha Piscium", 155.35, -55.6,2),star("30 Piscium", 91.58, -65.83,2),star("delta Piscium", 121.73,-55.28 ,2),star("ν Piscium", 145.12, -55.22,2),star("lambda Piscium", 90.15,-56.61 ,2),star("tau Piscium", 128.12, -32.58,2),star("beta Piscium)", 78.79,-49.61 ,2),star("33 Piscium", 93.75, -65.93,2),star("phi Piscium", 129.37, -38.01,2),star("chi Piscium",129.18 , -41.59,2),star("upsilon Piscium", 130.56, -35.19,2),star("mu Piscium", 140.07, -55.43,2),star("alpha Arietis", 144.57, -36.2,3),star("beta Arietis", 142.24, -39.68,3),star("Bharani - 41 Arietis", 152.98, -28.61,3),star("Botein - δ Arietis (delta Arietis)", 162.6, -32.14,3),star("Lilii Borea - 39 Arietis", 151.42, -27.1,3),star( "ε Arietis (epsilon Arietis)", 158.69,-32.51 ,3),star("35 Arietis", 151.29,-28.93 ,3),star("γ2 Arietis", 142.55,-41.2 ,3),star("Aldebaran - α Tauri (alpha Tauri)",180.97 ,-20.25 ,4),star("Elnath - β Tauri (beta Tauri)", 177.99, -3.74,4),star("Alcyone - η Tauri (eta Tauri)", 166.67, -23.45,4),star("Tianguan - ζ Tauri (zeta Tauri)", 185.69, -5.64,4),star("Chamukuy - θ2 Tauri (theta2 Tauri)",180.35 , -22.01,4),star("λ Tauri (lambda Tauri)", 178.37, -29.38,4),star("Ain - ε Tauri (epsilon Tauri)", 177.6, -19.92,4),star("Atlas - 27 Tauri",167.01 , -23.23,4),star("Prima Hyadum - γ Tauri (gamma Tauri)", 179.08, -23.82,4),star("-23.82", 166.18,-23.85 ,4),star("Secunda Hyadum - δ1 Tauri", 178.01, -22.01,4),star("Maia - 20 Tauri", 166.17, -23.51,4),star("Merope - 23 Tauri", 166.57,-23.75 ,4),star("Pollux - β Geminorum",192.23,23.41,5),star("Alhena - γ Geminorum",196.77,4.45,5),star("Pollux - β Geminorum", 192.23, 23.41, 5),star("Alhena - γ Geminorum", 196.77, 4.45, 5),star("Castor - α Geminorum", 187.44, 22.48, 5),star("Tejat - μ Geminorum (mu Geminorum)", 189.72, 4.17, 5),star("Mebsuta - ε Geminorum (epsilon Geminorum)", 189.54, 9.63, 5),star("τ Geminorum (tau Geminorum)", 187.22, 17.2, 5),star("ν Geminorum (nu Geminorum)", 192.42, 4.35, 5),star("Propus - η Geminorum (eta Geminorum)", 188.85, 2.52, 5),star("Alzirr - ξ Geminorum (xi Geminorum)", 200.74, 4.5, 5),star("Wasat - δ Geminorum (delta Geminorum)", 195.98, 15.89, 5),star("Mekbuda - ζ Geminorum (zeta Geminorum)", 195.75, 11.9, 5),star("κ Geminorum (kappa Geminorum)", 195.85, 21.97, 5),star("λ Geminorum (lambda Geminorum)", 200.92, 13.23, 5),star("θ Geminorum (theta Geminorum)", 182.1, 15.02, 5),star("υ Geminorum (upsilon Geminorum)", 192.6, 21.06, 5),star("σ Geminorum (sigma Geminorum)", 191.19, 23.27, 5),star("ρ Geminorum (rho Geminorum)", 187.14, 21.34, 5),star("1 Geminorum", 186.99, 0.72, 5),star("Tarf - β Cancri (beta Cancri)", 214.25, 23.05, 6),star("Acubens - α Cancri (alpha Cancri)", 216.51, 33.52, 6),star("Asellus Borealis - γ Cancri (gamma Cancri)", 204.17, 33.73, 6),star("Asellus Australis - δ Cancri (delta Cancri)", 208.02, 32.9, 6),star("ι Cancri (iota Cancri)", 195.88, 36.54, 6),star("Regulus - α Leonis (alpha Leonis)", 226.43, 48.94, 7),star("Denebola - β Leonis (beta Leonis)", 250.65, 70.81, 7),star("Zosma - δ Leonis (delta Leonis)", 224.22, 66.83, 7),star("Chertan - θ Leonis (theta Leonis)", 235.37, 64.59, 7),star("Adhafera - ζ Leonis (zeta Leonis)", 210.23, 54.95, 7),star("Subra - ο Leonis (omicron Leonis)", 224.6, 42.06, 7),star("Rasalas - μ Leonis (mu Leonis)", 204.05, 50.25, 7),star("Alterf - λ Leonis (lambda Leonis)", 206.69, 44.86, 7),star("ε Leonis (epsilon Leonis)", 206.82, 48.21, 7),star("Spica - α Virginis (alpha Virginis)", 316.11, 50.84,8),star("Vindemiatrix - ε Virginis (epsilon Virginis)", 312.34, 73.63,8),star("Heze - ζ Virginis (zeta Virginis)", 325.25, 60.39,8),star("Minelauva - δ Virginis (delta Virginis)", 305.53, 66.25,8),star("Zavijava - β Virginis (beta Virginis)", 270.5, 60.75,8),star("Porrima - γ Virginis (gamma Virginis)", 297.85, 61.33,8),star("Zaniah - η Virginis (eta Virginis)", 286.4, 61.19,8),star("Syrma - ι Virginis (iota Virginis)", 337.75, 51.07,8),star("Kang - κ Virginis (kappa Virginis)", 333.51, 47.7,8),star("Khambalia - λ Virginis (lambda Virginis)", 333.4, 44.25,8),star("μ Virginis (mu Virginis)", 346.55, 47.54,8),star("τ Virginis (tau Virginis)", 339.22, 59.38,8),star("θ Virginis (theta Virginis)", 311.42, 57.03,8),star("Zubeneschamali - β Librae (beta Librae)", 352.02, 39.23, 9),star("Zubenelgenubi - α2 Librae (alpha2 Librae)", 340.33, 38.01, 9),star("Brachium - σ Librae (sigma Librae)", 337.22, 28.62, 9),star("Zubenelhakrabi - γ Librae (gamma Librae)", 351.51, 32.2, 9),star("τ Librae (tau Librae)", 341.06, 20.45, 9),star("θ Librae (theta Librae)", 353.54, 27.72, 9),star("υ Librae (upsilon Librae)", 341.89, 21.94, 9),star("Antares - α Scorpii (alpha Scorpii)", 351.95, 15.06, 10),star("Shaula - λ Scorpii (lambda Scorpii)", 351.74, -2.21, 10),star("Sargas - θ Scorpii (theta Scorpii)", 347.14, -5.98, 10),star("Larawag - ε Scorpii (epsilon Scorpii)", 348.82, 6.56, 10),star("Dschubba - δ Scorpii (delta Scorpii)", 350.1, 22.49, 10),star("Acrab - β1 Scorpii (beta1 Scorpii)", 353.19, 23.6, 10),star("Lesath - υ Scorpii (upsilon Scorpii)", 351.27, -1.84, 10),star("Paikauhale - τ Scorpii (tau Scorpii)", 351.54, 12.81, 10),star("Fang - π Scorpii (pi Scorpii)", 347.22, 20.23, 10),star("Alniyat - σ Scorpii (sigma Scorpii)", 351.31, 17, 10),star("Xamidimura - μ1 Scorpii (mu1 Scorpii)", 346.12, 3.91, 10),star("Pipirima - μ2 Scorpii (mu2 Scorpii)", 346.2, 3.86, 10),star("Iklil - ρ Scorpii (rho Scorpii)", 344.63, 18.27, 10),star("Jabbah - ν Scorpii (nu Scorpii)", 354.61, 22.7, 10),star("κ Scorpii (kappa Scorpii)", 351.04, -4.72, 10),star("ι1 Scorpii (iota1 Scorpii)", 350.61, -6.13, 10),star("η Scorpii (eta Scorpii)", 344.37, -2.3, 10),star("ω1 Scorpii (omega1 Scorpii)", 352,57, 10),star("Kaus Australis - ε Sagittarii (epsilon Sagittarii)", 359.2, -9.81, 11),star("Nunki - σ Sagittarii (sigma Sagittarii)", 9.56, -12.43, 11),star("Ascella - ζ Sagittarii (zeta Sagittarii)", 6.84, -15.35, 11),star("Kaus Media - δ Sagittarii (delta Sagittarii)", 3, -7.15, 11),star("Kaus Borealis - λ Sagittarii (lambda Sagittarii)", 7.66, -6.52, 11),star("Albaldah - π Sagittarii (pi Sagittarii)", 15.89, -13.29, 11),star("Alnasl - γ2 Sagittarii (gamma2 Sagittarii)", 0.92, -4.54, 11),star("Polis - μ Sagittarii (mu Sagittarii)", 10, -1.6, 11),star("Rukbat - α Sagittarii (alpha Sagittarii)", 357.71, -23.09, 11),star("Arkab Prior - β1 Sagittarii (beta1 Sagittarii)", 353.61, -23.93, 10),star("Arkab Posterior - β2 Sagittarii (beta2 Sagittarii)", 353.28, -24.11, 11),star("η Sagittarii (eta Sagittarii)", 356.44, -9.68, 11),star("φ Sagittarii (phi Sagittarii)", 8, -10.77, 11),star("τ Sagittarii (tau Sagittarii)", 9.34, -15.37, 11),star("ο Sagittarii (omicron Sagittarii)", 14.71, -12.51, 11),star("ι Sagittarii (iota Sagittarii)", 357.97, -29.11, 11),star("ξ2 Sagittarii (xi2 Sagittarii)", 14.61, -10.78, 11)};

void constellation::zodiac(int q)
    {   

    for(int i=1;i<14;i++)
    {
        if(C[i].startd<=q&&C[i].endd>=q)
        {  cout<<"\nYour Zodiac Sign is ";
        cout<<C[i].name;}
    }
    }


// Main Function

int main()
{   

    read("Meta_data.csv");
    int day; int month; int year; int hour; int minute; int q=0; int z; int t;  
    int temp[10];
    while(q!=6)
    {
    printf("\n\nHi, What are you looking for?\nWhat you want to perform\n");
    printf("1. I wanted to know my Zodiac Sign \n");
    //printf("2. Tell me something about todays night sky");
    // \n3. 
    printf("2. Display Todays night sky chart \n3. Display constellation x \n4. I Wanna know where to look for constellation x \n5. Exit from the program \n");
    printf("Enter the task no. you want to perform: ");
    scanf("%d",&q);
    switch(q)
    {
        case 1: {   printf("Enter Date of Birth in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    z = date(day, month, year);
                    constellation ab = constellation("a",1,2,3,4);
                    ab.zodiac(z);
                    break;

                }

        case 2:{
                    printf("Enter Date in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    printf("\nEnter Time in format hh/mm: ");
                    scanf("%d %d", &hour, &minute);
                    z = date(day, month, year);
                    printf("%d(st/nd/rd/th) day of the year ", z);
                    timeq( hour, minute);
                    t=tminute(hour,minute);
                    AVI(month, z, t, temp);
                    location(temp[0], temp[1],  temp[2], temp[3], temp);  //
                    presentconst(temp[0], temp[1],  temp[2], temp[3]);           // New AVI,SVI confrigation as per new location
                     char c; char ec ;
                    printf("\nWanted to see present sky chart y/n: ");
                    scanf("%c",&ec); 
                    scanf("%c",&c);
                    if(c=='y')
                    //printf("working");
                    displayconstchart( temp[0], temp[1],  temp[2], temp[3] );
                   // printf("Wanted to see any specific constellation y/n: "); 
                   /* scanf("%c",&ec);
                    scanf("%c", &c); 
                    if(c=='y')
                    displayconst();
                    break;  */
                    break;
                }
        case 3:{    
                    char c; char ec ;
                    printf("Wanted to see any specific constellation y/n: "); 
                    scanf("%c",&ec);
                    scanf("%c", &c); 
                    for(int i=0;i<11;i++)
                    {
                        cout<<"\n"<<i+1<<". "<<C[i].name;
                    }
                    if(c=='y')
                    displayconst();
                    break;
                    break;
                }
        case 4:
                {   
                    printf("Enter Date in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    printf("\nEnter Time in format hh/mm: ");
                    scanf("%d %d", &hour, &minute);
                    z = date(day, month, year);
                    printf("%d(st/nd/rd/th) day of the year ", z);
                    timeq( hour, minute);
                    t=tminute(hour,minute);
                    AVI(month, z, t, temp);
                    location(temp[0], temp[1],  temp[2], temp[3], temp);  //

                    int nc;
                    presentconst(temp[0], temp[1],  temp[2], temp[3]); 
                    int cy = temp[2]-65;    // cy is zenith y cordinate
                    int cx =  (temp[0]+temp[1])/2;
                    char c; char ec ;
                    printf("\nDo you wanna know where to look for constellation x y/n: ");
                    scanf("%c",&ec); 
                    scanf("%c",&c);
                    if(c=='y')
                    {
                    printf("\nEnter number for Which Constellation you wanna gaze for: ");
                    scanf("%d",&nc);
                    //printf("%d",nc);
                    wheretolook(cx, cy, temp, nc);
                    }
                    break;
                }
        case 5:
            {   printf("\nBye, See you next time :) ");
                break;
            }
    }
    if(q==5)
    break;
    }

	return 0;
}


void read(string file_name)
{
    
    ifstream file;
    file.open(file_name);

    bool found_record = false;

    string f1; //f1 is field 1
    string f2;
    string f3;
    int i = 0;
    while(getline(file,f1,',') && !found_record)
    {
        getline(file,f2,',');
        getline(file,f3,'\n');
        if(i==127)
        {
         found_record = true;
            
        }
        
        S1.push_back(star1(f1, stof(f2) , stof(f3)));
       
        
        i++;
        
    }
    i=0;
   
    
    file.close();
   
}




int date(int a, int b, int c)
{ 	
    int mdur[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int w;
    w=leapyear(c);
    
    if(w==1)
    {
    mdur[2]=mdur[2]+1;
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
void timeq(int h, int m)
{
    printf("\n");
    if(h>7&&h<18)
    {
        printf("\nSorry, no stars will be available in day\n");
        }
    else
    {
        printf("\nnight time, Enjoy the momment\n");
    }
    
}

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
   // printf("\n%d\n",d);
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
    //printf("AVI is %d\n",CAVIM);
    int SAVI=0;                  // SAVI is Starting AVI, indicates star present near east or starting range of visible stars.
    int EAVI=0;
    int a,b;
    a=nightlenght(month);  // EAVI is Ending AVI, indicates star present near west or ending range of visible stars.
    b =a/2;
    SAVI= CAVIM - (b*60*0.25);   // b is the value of N/2, where N is the value of night length.
    if(SAVI<0)
    SAVI=(360+SAVI);
    EAVI= CAVIM + (b*60*0.25);
    //printf("\nSAVI is %d  EAVI is %d",SAVI,EAVI);
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
    
   //printf("\nNSVI is %d  SSVI is %d",NSVI,SSVI);
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
{   printf("\nConstellation Present are\n");
    if(SAVI<EAVI)
    {
    for(int i=1;i<13;i++)
    {   
        if(C[i].SVI>0)
        {
            if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                cout<<i<<" "<<C[i].name<<"\n";
            }
        }

    }
    }
    if(SAVI>EAVI)
    {
    for(int i=1;i<13;i++)
    {   if(C[i].AVI<SAVI)
        {
            if(C[i].AVI<=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                cout<<i<<" "<<C[i].name<<"\n";
            }
        }
        else if(C[i].AVI>SAVI)
        {
            if(C[i].AVI>=SAVI&&C[i].AVI>=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                cout<<i<<" "<<C[i].name<<"\n";
            }
        }
    }
    }
}

void displayconst()
{   int a=0;   //int count = 0;
    printf("\nWhich Constellation do you wants to see type its no from the above list: ");
    scanf("%d",&a);
    //printf("a is %d",a);
    int cx; int cy; int sx; int ex; int sy; int ey; //cx central long, sx starting long, sy ending long.
    cx = C[a-1].AVI/3;
    if(C[a-1].SVI>0){ cy = 90 - C[a-1].SVI; cy=cy/3;}
    else if(C[a-1].SVI<0){ cy=C[a-1].SVI*(-1); cy=90+cy; cy=cy/3;} 
    sx = cx - 20; ex = cx + 20;
    sy = cy - 15; ey = cy + 15;
    for(int i=sy;i<ey;i++)            //76/3=25
    {
        for(int j=sx;j<ex;j++)            // 361/6=60
        {   int p=0;int q=0;int temp = 0; //  int m =0;
            for(int k=0;k<149;k++)
            { 
            if(S[k].cnum==a){
                if(S[k].SVI>0)
                {
                    temp=90-S[k].SVI;
                    
                    p=temp/3; 
                }
                else if(S[k].SVI<0)
                {
                    temp=S[k].SVI*(-1);
                    temp=90+temp;
                    p=temp/3;
                    
                }
                           // C[i]!=S[i]
                q=S[k].AVI/3;
            }
            //m++;
            //if(p==i&&q==j&&S[k].cstar==0)
            //break;
            //else 
            if(p==i&&q==j)
            {break;}
            }
            if(i==sy||i==(ey-1))
            printf("-");
            else if((i>sy||i<(ey-1))&&(j==sx||j==(ex-1)))
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
 
    cout<<"            "<<C[a-1].name;
    
    
}
void displayconstchart(int SAVI, int EAVI, int NSVI,int SSVI )
{   
    double time_spent = 0.0;
 
    //clock_t begin = clock();
    printf("\nThe Sky\n");                                                        
    int p,q,temp; int mny = 0; int msy = 0; int ynl =0; int ysl =0; 
    mny = 90-NSVI;
    msy = SSVI*(-1); msy = 90 + msy;
    ynl = (mny-1)/3;
    ysl = (msy+4)/3;
    //printf("%d   %d\n",mny,msy);
    for(int i=ynl;i<ysl;i++)            //76/3=25
    {
        for(int j=0;j<120;j++)            // 361/6=60
        {   
            for(int k=0;k<125;k++)
            {   
                int sx = 0; int sy =0; 
                if(S1[k].SVI>0)
                {
                    sy=90-S1[k].SVI;
                }
                else if(S1[k].SVI<0)
                {
                    sy=S1[k].SVI*(-1);
                    sy=90+sy;         
                }
                sx=S1[k].AVI;
                //printf("%d   %d\n",sx,sy);
                if(SAVI<EAVI)
                {
                    if(sx>=SAVI&&sx<=EAVI&&sy>=mny&&sy<=msy)
                        {  // printf("1\n");
                            p = sy/3;
                            q=sx/3;
                            if(p==i&&q==j)
                            break;
                        }
                }
                if(SAVI>EAVI)
                {   
                    if(sx<=SAVI&&sx<=EAVI&&sy>=mny&&sy<=msy)
                        {  // printf("2\n");
                            p = sy/3;
                            q=sx/3;
                            if(p==i&&q==j)
                            break;
                        }
                    else if(sx>=SAVI&&sx>=EAVI&&sy>=mny&&sy<=msy)
                        {   //printf("3\n");
                            p = sy/3;
                            q=sx/3;
                            if(p==i&&q==j)
                            break;
                        }
                }
            }
            
            
            if(i==ynl||i==(ysl-1))
            printf("-");
            else if((i>ynl||i<(ysl-2))&&(j==0||j==119))
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
    printf("Enjoy the Moment :)\n");
    //clock_t end = clock();
 
    // calculate elapsed time by finding difference (end - begin) and
    // dividing the difference by CLOCKS_PER_SEC to convert to seconds
    //time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("The elapsed time is %f seconds", time_spent);

}
void location(int SAVI, int EAVI, int NSVI,int SSVI, int temp[] )
{   float la,lo,rla,rlo; char ec ;
    printf("\nEnter your location Latitude: ");
    //scanf("%c",&ec);
    scanf("%f",&la);
  
    printf("\nEnter your location Longutide: ");
    scanf("%f",&lo);
    // printf("%f %f",la , lo);
     

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

        temp[0] = SAVI;
        temp[1] = EAVI;
        temp[2] = NSVI;
        temp[3] = SSVI;

       // printf("SAVI is %d, EAVI is %d \nNSVI is %d, SSVI %d",SAVI, EAVI,  NSVI, SSVI);
        // displayconstchart( SAVI,  EAVI,  NSVI, SSVI );
 
    //} 
    

}

void wheretolook(int cx, int cy, int temp[], int nc)
{   
    int quad = 1 ;       //nth qudrant of cartisean system
    if(temp[0]<temp[1])
    {
        if(C[nc].SVI>cy)
        {
            if(C[nc].AVI>=cx)
            {   
                quad =2;
                compass(cx, cy, nc, quad);
            }
            else
            {
                quad = 1;
                compass(cx, cy, nc, quad);
            }
        }
        else if(C[nc].SVI<cy)
        {
            if(C[nc].AVI>=cx)
            {   
                quad =3;
                compass(cx, cy, nc, quad);
            }
            else
            {
                quad = 4;
                compass(cx, cy, nc, quad);
            }
        }
    }
    if(temp[0]>temp[1])
    {
        if(C[nc].SVI>cy)
        {
            if(C[nc].AVI<=cx)
            {   
                quad =2;
                compass(cx, cy, nc, quad);
            }
            else
            {
                quad = 1;
                compass(cx, cy, nc, quad);
            }
        }
        else if(C[nc].SVI<cy)
        {
            if(C[nc].AVI<=cx)
            {   
                quad =3;
                compass(cx, cy, nc, quad);
            }
            else
            {
                quad = 4;
                compass(cx, cy, nc, quad);
            }
        }
    }
    
}

void compass(int cx, int cy, int nc, int quad)
{   
    unsigned int e = 0, w = 0, n = 0, s =0,h =0;
    int x,y, trig, angle;  ///from y =0;
    y = (2*3.14*6400*C[nc].SVI/360);       //radius of earth
    x = (2*3.14*6400*C[nc].AVI/360);
    trig = ((x*0)+(y*1))/((sqrt((x*x)+(y*y)))*sqrt(1));
    angle = acos(trig);
    h = 90 - C[nc].SVI;
    switch (quad)
    {
    case 1:
        {
            n = angle;
            e = angle + 90;
            s = angle + 180;
            w = angle + 270;
        
        break;
        }
    case 2:
        {
            n = 360-angle;
            e = 270 - angle ;
            s = 180 - angle ;
            w = 90 - angle ;
        
        break;
        }
    case 3:
        {
            n = 180 + angle;
            e = 90+ angle ;
            s = angle ;
            w = 90 - angle ;
        
        break;
        }
    case 4:
        {
            n = 180 - angle;
            e = 90 - angle ;
            s = 360 - angle ;
            w = 270 - angle;
        
        break;
        }
    default:
        {
        printf("Not Found");
        break;
        }
    }
    cout<<"\nLook in following directions to see \n"<<C[nc].name;
    printf("\n%d clockwise From East\n%d clockwise From West\n%d clockwise From North\n%d clockwise From South\n%d From Horizon\n ",e,w,n,s,h);

}



