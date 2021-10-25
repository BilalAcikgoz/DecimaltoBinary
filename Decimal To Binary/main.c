/*
   PROJE ISMI   : DECÝMAL TO BÝNARY
   OGRENCI NO   : b201200022
   ADI SOYADI   : BILAL ACIKGOZ
   YOUTUBE LINK : https://www.youtube.com/watch?v=_xs1mvik82c 
*/

#include <stdio.h>
#include <stdlib.h>

void IntToBinary(int);   // Fonksiyon imzalarini burada tanimladik. Kodlar yukaridan okunmaya basladigi icin fonksiyon prototipleri yukarida tanimlamak gerekir.
void FloatToBinary(float);

int main(int argc, char *argv[]) 
{
	int sayi1;
	float sayi2, kalanSayi;
    	
	printf("Cevirmek istediginiz sayi degerini giriniz: ");  
	scanf("%f", &sayi2);
	
	sayi1 = sayi2;   // Bu donusumu yaparak sayi2 nin virgullu kismi atilarak tam kismini tutmus olduk
	
	IntToBinary(sayi1);      
	printf(". ");

    kalanSayi = sayi2 - sayi1;  // Bu islem sayesinde virgulden sonraki kismi bir degiskende tuttuk
	FloatToBinary(kalanSayi); 

	return 0;
}

void IntToBinary(int sayi1)
{
    int sayi2, i, j;
	sayi2 = sayi1;	
		
	for(i = 0; sayi1 >= 2; i++)
		sayi1 /= 2;        // Bu donguyle bir sayac tutarak dizimizin kac indisli oldugunu bulduk

	int dizi[i];
	
	for(j =0;;j++)
	{
		if(sayi2 < 2)
		{
			dizi[j] = sayi2 % 2;   // Bu kosulla beraber sayimiz 2 den kucuk oldugu an son elemani yazdirip donguyu kirdik
			break;
		}
	
		dizi[j] = sayi2 % 2;   // Dizi elemanlarinin atamasi yapildi
		sayi2 /= 2;
	} 
	
	for(int k=j; k>=0;k--)
	   printf("%d ", dizi[k]);      // Dizi elemanlari console ekranina yazdirildi
	   	    	
}

void FloatToBinary(float kalanSayi)
{
	int *dizi;
	dizi = (int *)(malloc(sizeof(int) * 23));  // Burada bir pointer tutularak dinamik bir dizi olusturduk
	
	for(int i = 0;; i++)
	{
		kalanSayi *= 2;  // Burada her seferinde sayimiz 2 yle carpilarak 1'den kucuk, buyuk veya esit olma durumuna gore asagida if else kosullarini sunduk
		
		
		if(kalanSayi > 1)
		{
			dizi[i] = 1;
			kalanSayi -= 1;  // Eger 1 den buyukse sayi 1 azaltilir ve o indise 1 yazilir
		}
		else if(kalanSayi < 1)
		{
			dizi[i] = 0;  // 1 den kucukse o indise 0 yazilir
		}
		else if(kalanSayi == 1)
		{
		    dizi[i] = 1;  // 1 e esit ise indis 1 degerini alir
		}  
		
		if(i == 23)
		   break;    // Sayet i degeri 23 olursa dongu kirilir.
	}		  
	
	
	for(int j = 0; j < 23; j++)
	{   	
	    if (dizi[j] != 0 && dizi[j] != 1)
            break;   
	   
	    printf("%d ", dizi[j]);   // Dizi elemanlarini yazdirdik
    }		
} 
