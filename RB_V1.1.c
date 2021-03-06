
#include<stdio.h>
#include<math.h>
int date(int day, int month, int year);
void time(int hour, int minute);
void zodiac(int z);
int leapyear(int lp);
void presentconst(int SAVI, int EAVI, int NSVI, int SSVI);    // calculates contellation present in sky
int tminute(int hour, int minute);  // calculate total minute in+degree
void AVI(int month, int day, int tminute, int temp[]);   //calculate present avi, #can be by current date&time, # in current day,
void SVI(int day,int SAVI, int EAVI,int temp[]);         // calculate present svi
int nightlenght(int month);            // to Calculate Night Length, On 30 degree N latitude, india has 28.38'N
void displayconst();                    // To display indivitual constellation
void displayconstchart(int SAVI, int EAVI, int NSVI,int SSVI );               // To display constellation Chart of that day
void location(int SAVI, int EAVI, int NSVI,int SSVI , int temp[]);                      // to update const map accorting to location taking delhi as reference 
void wheretolook(int cx, int cy, int temp[], int nc);                // function to tell where to chase the star      
void compass(int cx, int cy, int nc, int quad);
struct constellation
{   
	char name[30];
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
    char name[100];
    float AVI;
    float SVI;
    int cnum;   // belongs to constelation num
    //int cstar;   // to identify that does this star is a central star of a constellation by using 1 as NOT and 0 as yes
};

    struct constellation C[100]={{"Aquarius",20,50,48.02, -37.88},{"Pisces",51,79,137.01, -46.43},{"Aries",80,110,144.57, -36.2},{"Taurus",111,140,144.57, -36.2},{"Gemini",141,171,192.23, 23.41},{"Cancer",172,203,214.25, 23.05},{"Leo",204,234,226.43,48.94},{"Virgo",235,263,316.11, 50.84},{"Libra",264,295,352.02, 39.23},{"Scorpius",296,326,351.95, 15.06},{"Sagittarius",327,355,359.2, -9.81},{"Capricornus",356,365,37.6, -46.01},{"Capricornus",1,19,376,2}};//,{"Andromeda", , ,},{"Canis Major", , ,},{"Cassiopeia", , ,},{"Orion", , ,},{"Triangulum", , ,}{"Ursa Major", , ,},{"Pegasus", , ,},{"Draco", , ,}};


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

    struct star S[1000]={{"?? Aquarii", 48.02, -37.88,1},{"?? Aquarii", 59.93,-42.07 ,1},{"?? Aquarii", 49.58, -60.671,1},{"88 Aquarii", 41.76, -66.03,1},{"?? Aquarii",62.19 , -55.73,1},{"?? Aquarii",37.68 , -30.1,1},{"?? Aquarii",62.18 ,-45.84 ,1},{"98 Aquarii", 47.35,-68.59 ,1},{"??2 Aquarii", 52.27,-58.52 ,1},{"?? Aquarii", 66.84,-47.61 ,1},{"Ancha",53.51 ,-48.62 ,1},{"??1 Aquarii", 67.07,-61.11 ,1},{"?? Aquarii", 70.94,-58.74 ,1},{"?? Aquarii", 43.51,-49.37 ,1},{"99 Aquarii", 46.74,-69.46 ,1},{"??2 Aquarii", 67.62,-61.54 ,1},{"3 Aquarii", 42.24, -28.09,1},{"zeta2 Aquarii", 65.35,-46.33 ,1},{"86 Aquarii", 35.23, -66.15,1},{"omega2 Aquarii", 67.66, -69.64,1},{"eta Piscium", 137.01,-46.43,2},{"gamma Piscium",82.47 ,-52.02 ,2},{"omega Piscium", 100.69,-53.74,2},{"iota Piscium", 92.46,-52.96,2},{"omicron Piscium", 144.61, -51.43,2},{"epsilon Piscium", 127.89, -54.87,2},{"theta Piscium", 88.81,-50.88 ,2},{"alpha Piscium", 155.35, -55.6,2},{"30 Piscium", 91.58, -65.83,2},{"delta Piscium", 121.73,-55.28 ,2},{"?? Piscium", 145.12, -55.22,2},{"lambda Piscium", 90.15,-56.61 ,2},{"tau Piscium", 128.12, -32.58,2},{"beta Piscium)", 78.79,-49.61 ,2},{"33 Piscium", 93.75, -65.93,2},{"phi Piscium", 129.37, -38.01,2},{"chi Piscium",129.18 , -41.59,2},{"upsilon Piscium", 130.56, -35.19,2},{"mu Piscium", 140.07, -55.43,2},{"alpha Arietis", 144.57, -36.2,3},{"beta Arietis", 142.24, -39.68,3},{"Bharani - 41 Arietis", 152.98, -28.61,3},{"Botein - ?? Arietis (delta Arietis)", 162.6, -32.14,3},{"Lilii Borea - 39 Arietis", 151.42, -27.1,3},{ "?? Arietis (epsilon Arietis)", 158.69,-32.51 ,3},{"35 Arietis", 151.29,-28.93 ,3},{"??2 Arietis", 142.55,-41.2 ,3},{"Aldebaran - ?? Tauri (alpha Tauri)",180.97 ,-20.25 ,4},{"Elnath - ?? Tauri (beta Tauri)", 177.99, -3.74,4},{"Alcyone - ?? Tauri (eta Tauri)", 166.67, -23.45,4},{"Tianguan - ?? Tauri (zeta Tauri)", 185.69, -5.64,4},{"Chamukuy - ??2 Tauri (theta2 Tauri)",180.35 , -22.01,4},{"?? Tauri (lambda Tauri)", 178.37, -29.38,4},{"Ain - ?? Tauri (epsilon Tauri)", 177.6, -19.92,4},{"Atlas - 27 Tauri",167.01 , -23.23,4},{"Prima Hyadum - ?? Tauri (gamma Tauri)", 179.08, -23.82,4},{"-23.82", 166.18,-23.85 ,4},{"Secunda Hyadum - ??1 Tauri", 178.01, -22.01,4},{"Maia - 20 Tauri", 166.17, -23.51,4},{"Merope - 23 Tauri", 166.57,-23.75 ,4},{"Pollux - ?? Geminorum",192.23,23.41,5},{"Alhena - ?? Geminorum",196.77,4.45,5},{"Pollux - ?? Geminorum", 192.23, 23.41, 5},{"Alhena - ?? Geminorum", 196.77, 4.45, 5},{"Castor - ?? Geminorum", 187.44, 22.48, 5},{"Tejat - ?? Geminorum (mu Geminorum)", 189.72, 4.17, 5},{"Mebsuta - ?? Geminorum (epsilon Geminorum)", 189.54, 9.63, 5},{"?? Geminorum (tau Geminorum)", 187.22, 17.2, 5},{"?? Geminorum (nu Geminorum)", 192.42, 4.35, 5},{"Propus - ?? Geminorum (eta Geminorum)", 188.85, 2.52, 5},{"Alzirr - ?? Geminorum (xi Geminorum)", 200.74, 4.5, 5},{"Wasat - ?? Geminorum (delta Geminorum)", 195.98, 15.89, 5},{"Mekbuda - ?? Geminorum (zeta Geminorum)", 195.75, 11.9, 5},{"?? Geminorum (kappa Geminorum)", 195.85, 21.97, 5},{"?? Geminorum (lambda Geminorum)", 200.92, 13.23, 5},{"?? Geminorum (theta Geminorum)", 182.1, 15.02, 5},{"?? Geminorum (upsilon Geminorum)", 192.6, 21.06, 5},{"?? Geminorum (sigma Geminorum)", 191.19, 23.27, 5},{"?? Geminorum (rho Geminorum)", 187.14, 21.34, 5},{"1 Geminorum", 186.99, 0.72, 5},{"Tarf - ?? Cancri (beta Cancri)", 214.25, 23.05, 6},{"Acubens - ?? Cancri (alpha Cancri)", 216.51, 33.52, 6},{"Asellus Borealis - ?? Cancri (gamma Cancri)", 204.17, 33.73, 6},{"Asellus Australis - ?? Cancri (delta Cancri)", 208.02, 32.9, 6},{"?? Cancri (iota Cancri)", 195.88, 36.54, 6},{"Regulus - ?? Leonis (alpha Leonis)", 226.43, 48.94, 7},{"Denebola - ?? Leonis (beta Leonis)", 250.65, 70.81, 7},{"Zosma - ?? Leonis (delta Leonis)", 224.22, 66.83, 7},{"Chertan - ?? Leonis (theta Leonis)", 235.37, 64.59, 7},{"Adhafera - ?? Leonis (zeta Leonis)", 210.23, 54.95, 7},{"Subra - ?? Leonis (omicron Leonis)", 224.6, 42.06, 7},{"Rasalas - ?? Leonis (mu Leonis)", 204.05, 50.25, 7},{"Alterf - ?? Leonis (lambda Leonis)", 206.69, 44.86, 7},{"?? Leonis (epsilon Leonis)", 206.82, 48.21, 7},{"Spica - ?? Virginis (alpha Virginis)", 316.11, 50.84,8},{"Vindemiatrix - ?? Virginis (epsilon Virginis)", 312.34, 73.63,8},{"Heze - ?? Virginis (zeta Virginis)", 325.25, 60.39,8},{"Minelauva - ?? Virginis (delta Virginis)", 305.53, 66.25,8},{"Zavijava - ?? Virginis (beta Virginis)", 270.5, 60.75,8},{"Porrima - ?? Virginis (gamma Virginis)", 297.85, 61.33,8},{"Zaniah - ?? Virginis (eta Virginis)", 286.4, 61.19,8},{"Syrma - ?? Virginis (iota Virginis)", 337.75, 51.07,8},{"Kang - ?? Virginis (kappa Virginis)", 333.51, 47.7,8},{"Khambalia - ?? Virginis (lambda Virginis)", 333.4, 44.25,8},{"?? Virginis (mu Virginis)", 346.55, 47.54,8},{"?? Virginis (tau Virginis)", 339.22, 59.38,8},{"?? Virginis (theta Virginis)", 311.42, 57.03,8},{"Zubeneschamali - ?? Librae (beta Librae)", 352.02, 39.23, 9},{"Zubenelgenubi - ??2 Librae (alpha2 Librae)", 340.33, 38.01, 9},{"Brachium - ?? Librae (sigma Librae)", 337.22, 28.62, 9},{"Zubenelhakrabi - ?? Librae (gamma Librae)", 351.51, 32.2, 9},{"?? Librae (tau Librae)", 341.06, 20.45, 9},{"?? Librae (theta Librae)", 353.54, 27.72, 9},{"?? Librae (upsilon Librae)", 341.89, 21.94, 9},{"Antares - ?? Scorpii (alpha Scorpii)", 351.95, 15.06, 10},{"Shaula - ?? Scorpii (lambda Scorpii)", 351.74, -2.21, 10},{"Sargas - ?? Scorpii (theta Scorpii)", 347.14, -5.98, 10},{"Larawag - ?? Scorpii (epsilon Scorpii)", 348.82, 6.56, 10},{"Dschubba - ?? Scorpii (delta Scorpii)", 350.1, 22.49, 10},{"Acrab - ??1 Scorpii (beta1 Scorpii)", 353.19, 23.6, 10},{"Lesath - ?? Scorpii (upsilon Scorpii)", 351.27, -1.84, 10},{"Paikauhale - ?? Scorpii (tau Scorpii)", 351.54, 12.81, 10},{"Fang - ?? Scorpii (pi Scorpii)", 347.22, 20.23, 10},{"Alniyat - ?? Scorpii (sigma Scorpii)", 351.31, 17, 10},{"Xamidimura - ??1 Scorpii (mu1 Scorpii)", 346.12, 3.91, 10},{"Pipirima - ??2 Scorpii (mu2 Scorpii)", 346.2, 3.86, 10},{"Iklil - ?? Scorpii (rho Scorpii)", 344.63, 18.27, 10},{"Jabbah - ?? Scorpii (nu Scorpii)", 354.61, 22.7, 10},{"?? Scorpii (kappa Scorpii)", 351.04, -4.72, 10},{"??1 Scorpii (iota1 Scorpii)", 350.61, -6.13, 10},{"?? Scorpii (eta Scorpii)", 344.37, -2.3, 10},{"??1 Scorpii (omega1 Scorpii)", 352,57, 22.77, 10},{"Kaus Australis - ?? Sagittarii (epsilon Sagittarii)", 359.2, -9.81, 11},{"Nunki - ?? Sagittarii (sigma Sagittarii)", 9.56, -12.43, 11},{"Ascella - ?? Sagittarii (zeta Sagittarii)", 6.84, -15.35, 11},{"Kaus Media - ?? Sagittarii (delta Sagittarii)", 3, -7.15, 11},{"Kaus Borealis - ?? Sagittarii (lambda Sagittarii)", 7.66, -6.52, 11},{"Albaldah - ?? Sagittarii (pi Sagittarii)", 15.89, -13.29, 11},{"Alnasl - ??2 Sagittarii (gamma2 Sagittarii)", 0.92, -4.54, 11},{"Polis - ?? Sagittarii (mu Sagittarii)", 10, -1.6, 11},{"Rukbat - ?? Sagittarii (alpha Sagittarii)", 357.71, -23.09, 11},{"Arkab Prior - ??1 Sagittarii (beta1 Sagittarii)", 353.61, -23.93, 10},{"Arkab Posterior - ??2 Sagittarii (beta2 Sagittarii)", 353.28, -24.11, 11},{"?? Sagittarii (eta Sagittarii)", 356.44, -9.68, 11},{"?? Sagittarii (phi Sagittarii)", 8, -10.77, 11},{"?? Sagittarii (tau Sagittarii)", 9.34, -15.37, 11},{"?? Sagittarii (omicron Sagittarii)", 14.71, -12.51, 11},{"?? Sagittarii (iota Sagittarii)", 357.97, -29.11, 11},{"??2 Sagittarii (xi2 Sagittarii)", 14.61, -10.78, 11}};//,{"Deneb Algedi - ?? Capricorni (delta Capricorni)", 37.6, -46.01, 12},{"Dabih - ?? Capricorni (beta Capricorni)", 29.15, -26.37, 12},{"Algedi - ??2 Capricorni (alpha2 Capricorni)", 31.1, -24.81, 12},{"Nashira - ?? Capricorni (gamma Capricorni)", 36, -44.67, 12},{"Alshat - ?? Capricorni (nu Capricorni)", 31.17, -25.48, 12},{"?? Capricorni (zeta Capricorni)", 26.98, -43.59, 12},{"?? Capricorni (theta Capricorni)", 31.31, -37.29, 12,{"?? Capricorni (omega Capricorni)", 18.46, -37.18, 12},{"?? Capricorni (psi Capricorni)", 20.01, -35.5, 12},{"?? Capricorni (iota Capricorni)", 33.62, -40.77, 12},{"?? Capricorni (kappa Capricorni)", 33.38, -46.03, 12},{"?? Capricorni (rho Capricorni)", 26.8, -29.27, 12},{"Alpheratz - ?? Andromedae (alpha Andromedae)", 111.73, -32.84, 13},{"Mirach - ?? Andromedae (beta Andromedae)", 127.1, -27.1, 13},{"Almach - ??1 Andromedae (gamma1 Andromedae)", 136.96, -18.56, 13},{"?? Andromedae (delta Andromedae)", 119.87, -31.94, 13},{"Nembus - 51 Andromedae", 130.81, -13.53, 13},{"?? Andromedae (omicron Andromedae)", 102.21, -16.1, 13},{"?? Andromedae (lambda Andromedae)", 109.9, -14.53, 13},{"?? Andromedae (mu Andromedae)",124.07, -24.36, 13},{"?? Andromedae (zeta Andromedae)", 121.74, -38.59, 13},{"Titawin - ?? Andromedae (upsilon Andromedae)", 132, -20.66, 13},{"?? Andromedae (kappa Andromedae)", 109.76, -16.71, 13},{"?? Andromedae (phi Andromedae)", 126.11, -15.52, 13},{"?? Andromedae (iota Andromedae)", 109.03, -17.62, 13},{"?? Andromedae (pi Andromedae)", 119.47, -29.05, 13},{"?? Andromedae (epsilon Andromedae)", 119.57, -33.47, 13},{"Sirius - ?? Canis Majoris (alpha Canis Majoris)", 227.22, -8.88, 14},{"Adhara - ?? Canis Majoris (epsilon Canis Majoris)", 239.83, -11.33, 14},{"Wezen - ?? Canis Majoris (delta Canis Majoris)", 238.42, -8.27, 14},{"Mirzam - ?? Canis Majoris (beta Canis Majoris)", 226.06, -14.27, 14},{"Aludra - ?? Canis Majoris (eta Canis Majoris)", 242.62, -6.49, 14},{"Furud - ?? Canis Majoris (zeta Canis Majoris)", 237.52, -19.43, 14},{"Unurgunite - ?? Canis Majoris (sigma Canis Majoris)", 239.17, -10.27, 14},{"Muliphein - ?? Canis Majoris (gamma Canis Majoris)", 228.25, -4.41, 14},{"?? Canis Majoris (omega Canis Majoris)", 239.41, -7.15, 14},{"?? Canis Majoris (kappa Canis Majoris)", 242.36, -14.49, 14},{"?? Canis Majoris (theta Canis Majoris)", 223.98, -4.85, 14},{"?? Canis Majoris (iota Canis Majoris)", 228.7, -6.68, 14},{"?? Canis Majoris (tau Canis Majoris)", 238.18, -5.54, 14},{"Schedar - ?? Cassiopeiae (alpha Cassiopeiae)", 121.42, -6.3, 15},{"Caph - ?? Cassiopeiae (beta Cassiopeiae)", 117.52, -3.27, 15},{"Ruchbah - ?? Cassiopeiae (delta Cassiopeiae)", 127.19, -2.35, 15},{"Segin - ?? Cassiopeiae (epsilon Cassiopeiae)", 129.84, 1.65, 15},{"Achird - ?? Cassiopeiae (eta Cassiopeiae)", 122.6, -5.05, 15},{"Rigel - ?? Orionis (beta Orionis)", 209.24, -25.25, 16}//;/,{"Beelgeuse - ?? Orionis (alpha Orionis)", 199.79, -8.96, 16},{"Bellatrix - ?? Orionis (gamma Orionis)", 196.93, -15.95, 16},{"Alnilam - ?? Orionis (epsilon Orionis)", 205.21, -17.24, 16},{"Alnitak - ?? Orionis (zeta Orionis)", 206.45, -16.59, 16},{"Saiph - ?? Orionis (kappa Orionis)", 214.51, -18.5, 16},{"Mintaka - ?? Orionis (delta Orionis)", 203.86, -17.74, 16},{"Hatysa - ?? Orionis (iota Orionis)", 209.52, -19.58, 16},{"Tabit - ??3 Orionis (pi3 Orionis)", 191.45, -23.07, 16},{"Meissa - ?? Orionis (lambda Orionis)", 195.05, -12, 16},{"?? Trianguli (beta Trianguli)", 140.55, -25.2, 17},{"Mothallah - ?? Trianguli (alpha Trianguli)", 138.64, -31.4, 17},{"?? Trianguli (gamma Trianguli)", 142.65, -25.71, 17},{"Alioth - ?? Ursae Majoris (epsilon Ursae Majoris)", 122.18, 61.16, 18},{"Dubhe - ?? Ursae Majoris (alpha Ursae Majoris)", 142.85, 51.01, 18},{"Alkaid - ?? Ursae Majoris (eta Ursae Majoris)", 100.69, 65.32, 18},{"Mizar - ?? Ursae Majoris (zeta Ursae Majoris)", 113.11, 61.58, 18},{"Merak - ?? Ursae Majoris (beta Ursae Majoris)", 149.17, 54.8, 18},{"Phecda - ?? Ursae Majoris (gamma Ursae Majoris)", 140.84, 61.38, 18},{"Tania Australis - ?? Ursae Majoris (mu Ursae Majoris)", 177.9, 56.36, 18},{"Talitha - ?? Ursae Majoris (iota Ursae Majoris)", 171.51, 40.84, 18},{"Megrez - ?? Ursae Majoris (delta Ursae Majoris)", 132.57, 59.42, 18},{"Muscida - ?? Ursae Majoris (omicron Ursae Majoris)", 155.97, 35.43, 18},{"Tania Borealis - ?? Ursae Majoris (lambda Ursae Majoris)", 175.87, 55.09, 18},{"Alula Borealis - ?? Ursae Majoris (nu Ursae Majoris)", 190.73, 69.08, 18},{"Alkaphrah - ?? Ursae Majoris (kappa Ursae Majoris)", 172.63, 41.63, 18},{"Taiyangshou - ?? Ursae Majoris (chi Ursae Majoris)", 150.32, 65.72, 18},{"Alcor - 80 Ursae Majoris", 112.77, 61.47, 18},{"?? Ursae Majoris (psi Ursae Majoris)", 165.8, 63.23, 18},{"?? Ursae Majoris (theta Ursae Majoris)", 165.45, 45.66, 18},{"?? Ursae Majoris (upsilon Ursae Majoris)", 154.31, 45.58, 18},{"Enif - ?? Pegasi (epsilon Pegasi)", 65.57, -31.46, 19},{"Scheat - ?? Pegasi (beta Pegasi)", 95.74, -29.05, 19},{"Markab - ?? Pegasi (alpha Pegasi)", 88.28, -40.38, 19},{"Algenib - ?? Pegasi (gamma Pegasi)", 109.43, -46.68, 19},{"Matar - ?? Pegasi (eta Pegasi)", 92.5, -24.95, 19},{"Homam - ?? Pegasi (zeta Pegasi)", 78.86, -40.66, 19},{"Sadalbari - ?? Pegasi (mu Pegasi)", 90.68, -30.56, 19},{"Biham - ?? Pegasi (theta Pegasi)", 67.41, -38.71, 19},{"Alkarab - ?? Pegasi (upsilon Pegasi)", 98.55, -35.36, 19},{"Salm - ?? Pegasi (tau Pegasi)", 97.51, -34.61, 19},{"?? Pegasi (iota Pegasi)", 82.26, -24.26, 19},{"?? Pegasi (lambda Pegasi)", 89.26, -31.02, 19},{"?? Pegasi (kappa Pegasi)", 78.41, -20.67, 19},{"?? Pegasi (xi Pegasi)", 81.28, -40.39, 19},{"Eltanin - ?? Draconis (gamma Draconis)", 79.06, 29.22, 20},{"Athebyne - ?? Draconis (eta Draconis)", 92.58, 40.95, 20},{"Rastaban - ?? Draconis (beta Draconis)", 79.58, 33.31, 20},{"Altais - ?? Draconis (delta Draconis)", 98.65, 23, 20},{"Aldhibah - ?? Draconis (zeta Draconis)", 96.01, 35.04, 20},{"Edasich - ?? Draconis (iota Draconis)", 93.97, 48.63, 20},{"Thuban - ?? Draconis (alpha Draconis)", 110.52, 50.96, 20},{"Grumium - ?? Draconis (xi Draconis)", 85.17, 30.23, 20},{"Giausar - ?? Draconis (lambda Draconis)", 132.98, 46.2, 20},{"Dziban - ??1 Draconis (psi1 Draconis)", 102.97, 31.03, 20},{"?? Draconis (epsilon Draconis)", 102.43, 20.83, 20},{"?? Draconis (chi Draconis)", 103.46, 28.06, 20},{"?? Draconis (kappa Draconis)", 125.21, 47.26, 20}};
    
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
{   
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
        case 1: {   printf("Enter Date of Bith in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    z = date(day, month, year);
                    zodiac(z);
                    break;

                }

      /*  case 2: {   
                    printf("Enter Date in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    printf("\nEnter Time in format hh/mm: ");
                    scanf("%d %d", &hour, &minute);
                    z = date(day, month, year);
                    printf("%d st/nd/rd/th day of the year: ", z);
                    time( hour, minute);
                    t=tminute(hour,minute);
                    AVI(month, z, t, temp);
                    location(temp[0], temp[1],  temp[2], temp[3]);
                    break;
                }   */

        case 2:{
                    printf("Enter Date in format dd/mm/yyyy: ");
	                scanf("%d %d %d", &day, &month, &year);
                    printf("\nEnter Time in format hh/mm: ");
                    scanf("%d %d", &hour, &minute);
                    z = date(day, month, year);
                    printf("%d(st/nd/rd/th) day of the year ", z);
                    time( hour, minute);
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
                        printf("\n%d. %s",i+1,  C[i].name);
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
                    time( hour, minute);
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
        printf("\nSorry, no stars will be available in day\n");
        }
    else
    {
        printf("\nnight time, Enjoy the momment\n");
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
{   printf("\nConstellation Present are");
    if(SAVI<EAVI)
    {
    for(int i=1;i<13;i++)
    {   
        if(C[i].SVI>0)
        {
            if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                printf("\n%d. %s",i,  C[i].name);
            }
        }
        /*else if(C[i].SVI<0)
        {
            if(C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                printf("\n%d. %s",i,  C[i].name);
            }
        }*/

    }
    }
    if(SAVI>EAVI)
    {
    for(int i=1;i<13;i++)
    {   if(C[i].AVI<SAVI)
        {
            if(C[i].AVI<=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                printf("\n%d. %s",i,  C[i].name);
            }
        }
        else if(C[i].AVI>SAVI)
        {
            if(C[i].AVI>=SAVI&&C[i].AVI>=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI)
            {
                printf("\n%d. %s",i,  C[i].name);
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
            for(int k=0;k<300;k++)
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
 
    printf("            %s",C[a-1].name);
    
    
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
            for(int k=0;k<200;k++)
            {   
                int sx = 0; int sy =0; 
                if(S[k].SVI>0)
                {
                    sy=90-S[k].SVI;
                }
                else if(S[k].SVI<0)
                {
                    sy=S[k].SVI*(-1);
                    sy=90+sy;         
                }
                sx=S[k].AVI;
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
            /*if((C[i].AVI>=SAVI&&C[i].AVI<=EAVI&&C[i].SVI<=NSVI&&C[i].SVI>=SSVI))
            {   
                if(S[k].SVI>0)
                {
                    S[k].SVI=90-S[k].SVI;
                    S[k].SVI=(S[k].SVI/3);
                    p=S[k].SVI/3; 
                }
                else if(S[k].SVI<0)
                {
                    S[k].SVI=S[k].SVI*(-1);
                    S[k].SVI=90+S[k].SVI;
                    p=S[k].SVI/3; 
                    
                }
                           // C[i]!=S[i]
                q=S[k].AVI/3;
            if(p==i&&q==j)
            break;
            }*/
            
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

}
void location(int SAVI, int EAVI, int NSVI,int SSVI, int temp[] )
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

        temp[0] = SAVI;
        temp[1] = EAVI;
        temp[2] = NSVI;
        temp[3] = SSVI;

        printf("SAVI is %d, EAVI is %d \nNSVI is %d, SSVI %d",SAVI, EAVI,  NSVI, SSVI);
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
    printf("\nLook in following directions to see %s\n",  C[nc].name);
    printf("\n%d clockwise From East\n%d clockwise From West\n%d clockwise From North\n%d clockwise From South\n%d From Horizon\n ",e,w,n,s,h);

}
