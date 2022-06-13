#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include <signal.h>

//int ve float olan verileri bit olarak tutuyor ve adresleri ogrenmek için kullanılmaktadır
#define MASK_BITS(x) ((x) & (unsigned int)0x0000FFFF)

unsigned long long int MapAddress(unsigned long long int address){
    address = MASK_BITS(address);

    printf("\nEslenen %llu adresi sunlari icerir:\n", address);

    unsigned long long int page = address >> 8;
    printf("Sayfa Numarasi : %llu\n", page);

    unsigned long long int offset = address & 0xFF;

    printf("Offset = %llu\n\n", offset);
    return 0;
}

void myFunction()
{
    FILE *fp = fopen("C:/Users/LENOVA/Downloads/OperatingSystem/OperatingSystem/isletimsistemi/sayfaTablosu.txt", "r");
    char buffer[32];
    unsigned long long int x;
    int cnt = 1;
    while(!feof(fp)){
        fscanf(fp, "%s", buffer);
        x = atol(buffer);
        MapAddress(x);
        cnt++;
    }

    fclose(fp);
    return;
}

int main(){

    const __UINT32_TYPE__ OLAY_SAYISI = 5;
    const __UINT32_TYPE__ OLAY_TIPI_SAYISI = 6;
    char ad [20];
    enum olayTipi {
        SUREC_BASLADI,
        SISTEM_CAGRISI,
        SUREC_BITTI,
        KULLANICI,
        GIRIS,
        CIKIS
    };
    char *olayAdlari [OLAY_TIPI_SAYISI];
    olayAdlari[SUREC_BASLADI] = "SUREC basladi";
    olayAdlari[SISTEM_CAGRISI] = "Sistem Cagrisi geldi";
    olayAdlari[SUREC_BITTI] = "Surec bitti";
    olayAdlari[GIRIS] ="Giris yapildi";
    olayAdlari[KULLANICI] ="Hosgeldin" ;
    olayAdlari[CIKIS]="Cikis yapildi";

    // Olaylar dizisi
    enum olayTipi olaylar[OLAY_SAYISI];

    // Rastgele tipte olaylar üretme
    srand(time(0));
    int sayac=0;
    void Sayac( int sayac)
    {
        
        
            printf("%d. tane olay gerceklesti \n",sayac); 
    }

    for(int i=0; i<OLAY_SAYISI; i++)
    {
        //
        olaylar[i] = rand() % OLAY_TIPI_SAYISI;
      
    } 
    
    for(int i=0; i<OLAY_SAYISI; i++)
    {   
        printf("olay: %d\n",olaylar[i]);
        printf("olay: %s\n",olayAdlari[olaylar[i]]);    
        sayac=sayac+1;
        Sayac(sayac);   
    }
    void cizelgeleme_baglama_adres(const __UINT32_TYPE__ OLAY_SAYISI)
    {
        int wt[20],tat[20],avwt=0,avtat=0, j,n,bt[20];
        int i;
        printf("Olay sayisi toplam %d tanedir:",OLAY_SAYISI);
       
        printf("\nEnter Process Burst Time\n");
        for (i=0;i<OLAY_SAYISI;i++) {
            printf("P[%d]:",(i+1));
            scanf("%d",&bt[i]);
             int *ptr;
             ptr=i;
             ptr= malloc(40*sizeof(int));
             sleep(1);
             printf("%d. bellek adresine kaydedildi\n",ptr);
             
             signal(SIGINT,SIG_IGN);//kernel moduna geçiş
             printf("%x fiziksel  addresi \n", ptr);
             
          
        }
        wt[0]=0;
        
        for (i=1;i<OLAY_SAYISI;i++) {
            wt[i]=0;
            for (j=0;j<i;j++)
            {
                        wt[i]+=bt[j];
            }
                
        }
        printf("\nProcess\t Burst\t TimeWaiting TimetTurnaround Time");
        //geri dönüş süresinin hesaplanması
        for (i=0;i<OLAY_SAYISI;i++) {
            tat[i]=bt[i]+wt[i];
            avwt+=wt[i];
            avtat+=tat[i];

            printf("\nP[%d]\tbt[%d]\twt[%d]\ttat[%d]",i+1,bt[i],wt[i],tat[i]);
        }
        avwt=avwt/i;
        avtat=avtat/i;
        printf("\nOrtalama Bekleme Suresi: %d",avwt);
        printf("\nOrtalama Geri Donus Suresi:%d\n",avtat);
	
    }
    
 cizelgeleme_baglama_adres(OLAY_SAYISI);       
 myFunction();
    
}