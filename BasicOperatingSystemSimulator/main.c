#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
//#include "scheduling.h"

    
int main(){
time_t s, val = 1;
struct tm* current_time;
s = time(NULL);
current_time = localtime(&s);

//parametreler
const __UINT32_TYPE__ OLAY_SAYISI= 10;
const __UINT32_TYPE__ OLAY_TIPI_SAYISI=5;

enum olayTipi{

SUREC_BASLA,
SISTEM_CAGRISI,
SISTEM_BELIRLILIK,
SUREC_BIT,
};
char *olayAdlari [OLAY_TIPI_SAYISI];
olayAdlari [SUREC_BASLA] = "Surec Basladi";
olayAdlari [SISTEM_CAGRISI] = "Sistem Cagrisi Geldi";
olayAdlari [SISTEM_BELIRLILIK] = "Sistem Cagrisi Geldi";
olayAdlari [SUREC_BIT] = "Surec Bitti";



//olaylar dizisi
enum olayTipi olaylar[OLAY_SAYISI];

//rastgele olaylar üret
srand(time(0));
for (int i = 0; i < OLAY_SAYISI; i++)
{
    olaylar[i] = rand()%OLAY_TIPI_SAYISI;
}


for (int i = 0; i < OLAY_SAYISI; i++)
{
   printf("Olay: %d\n",olaylar[i]);
   printf("Olay: %s\n\n",olayAdlari[olaylar[i]]);
   printf("Sistem Suresi:\n");

    printf("Saat:%02d:%02d:%02d\n",
           current_time->tm_hour,
           current_time->tm_min,
           current_time->tm_sec);
}

//scheduling schedulings;

//schedulings.findWaitingTime();
//schedulings.findTurnAroundTime();
//schedulings.findavgTime();

//bu kısımın yorum satırı olma nedeni:
//visual studio code includePath hatası vermesidir 
//projeyi riske atmamak için yorum satırına aldık
//yukarda bulunan in #include "scheduling.h" yorum satırından çıkararak deneyebilirsiniz



//Olay belleği
printf("Tum olaylar(Bellek):");
return (0);
}


