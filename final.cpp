#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h>
#include <string.h>

struct urun{ 
    int 	urunkod; 
    char 	urunad[20];
    int 	fiyat;
    int		stok;
};
    struct  musteri{ 
    int 	hesapno; 
    char 	ad[10]; 
    char 	soyad[20]; 
    char 	telno[11];
    char	adres[250];
    int 	bakiye;
};
    void musteriekle(){
		FILE *d1;
   		d1 = fopen ("musteri.dat", "ab+"); 
   		if (d1 == NULL){
			printf("Musteri dosyasi acilamadi! Programdan cikiliyor.");
			exit(1);
		}
    	musteri mus1;
    	while(fread(&mus1, sizeof(struct musteri), 1, d1)){ 		
		} 
        printf("Yeni Musteri Ekleniyor...");
		musteri mus;
        int hno;
        bool valid;
		do{
			valid = true;
	        printf("\nMusteri No : ");
	        scanf("%d", &hno);
		    if (fread(&mus, sizeof(struct musteri), 1, d1)==1){
		    	if (mus.hesapno==hno){
		    		printf ("\nBu numarali musteri mevcut. Lutfen yeni bir numara giriniz.");
		    		valid = false;
				}
		        
			}
        }
        while (not valid);   
        mus.hesapno = hno;
		     
        printf("\nAdi : ");
        scanf("%s", &mus.ad);
        printf("\nSoyadi : ");
        scanf("%s", &mus.soyad);
        printf("\nAdresi : ");
        scanf("%s", &mus.adres);
        
        valid = false;
		do{
	        printf("\nCep Telefonu (5XXXXXXXXX) : ");
	        scanf("%s", &mus.telno);
	        if ((mus.telno[0] == '0') || (strlen(mus.telno) != 10)){
	        	printf("\nTelefon numarasi basinda '0' olmadan 10 hane olarak yazilmalidir!"); 
			} else {
				valid = true;
			}
        }
        while (not valid);   
        
        int bakiye;
        valid = false;
		do{
	        printf("\nBakiye : ");
	        scanf("%d", &bakiye);
	        if (bakiye <0){
	        	printf("\nBakiye 0'dan buyuk olmalidir!"); 
			} else {
				valid = true;
			}
        }
        while (not valid);   
        mus.bakiye = bakiye;

		int hata;
        hata = fwrite (&mus, sizeof(struct musteri), 1, d1);
     
        if (hata = 0) {
           printf("\nDosyaya yazma hatasý!");
    	} else {
		   printf("\nMusteri olusturuldu.");  
		}
    	
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
        
    	
	}
	void musterilistele(){
    	FILE *d1;
        musteri mus;
        
        if ( (d1 = fopen("musteri.dat", "rb") ) == NULL ){
     		printf ("Dosya acilamadi...");
            //break;
     	}
        
        
	    while(fread(&mus, sizeof(struct musteri), 1, d1)){
	    
			printf ("Musteri No : %10d Adi : %-10s Soyadi : %-20s Telefon : %-10s Bakiye : %7d TL Adres : %-100s\n", mus.hesapno, mus.ad, mus.soyad, mus.telno, mus.bakiye, mus.adres); 
    		
		} 
	    
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    }
	
	void musterinoara(){
    	FILE *d1;
        musteri mus;
        int hno;
        
        if ( (d1 = fopen("musteri.dat", "rb") ) == NULL ){
     		printf ("Dosya acilamadi...");
            //break;
     	}
        
        printf("\nMusteri No : ");
	    scanf("%d", &hno);
	    bool bulundu = false;
		while (fread(&mus, sizeof(struct musteri), 1, d1)){
		    if (mus.hesapno==hno){
		    	printf ("\nMusteri No : %10d Adi : %-10s Soyadi : %-20s Telefon : %-10s Bakiye : %7d TL Adres : %-100s\n", mus.hesapno, mus.ad, mus.soyad, mus.telno, mus.bakiye, mus.adres); 
		    	bulundu = true;
			}
		        
		}
	    if (!bulundu){
	    	printf ("\nMusteri bulunamadi.");
		}
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    }
    
	void musteriisimara(){
    	FILE *d1;
        musteri mus;
        char adsoyad[100] = "";
        char instr[100];
        
        if ( (d1 = fopen("musteri.dat", "rb") ) == NULL ){
     		printf ("Dosya acilamadi...");
            //break;
     	}
        
        printf("\nAranilan : ");
	    scanf("%s", &instr);
	    bool bulundu = false;
		while (fread(&mus, sizeof(struct musteri), 1, d1)){
			*adsoyad = NULL;
			strcat (adsoyad, mus.ad);
			strcat (adsoyad, " ");
			strcat (adsoyad, mus.soyad); 
		    if (strstr(adsoyad, instr) != NULL){
		    	printf ("\nMusteri No : %10d Adi : %-10s Soyadi : %-20s Telefon : %-10s Bakiye : %7d TL Adres : %-100s\n", mus.hesapno, mus.ad, mus.soyad, mus.telno, mus.bakiye, mus.adres); 
		    	bulundu = true;
			}
		        
		}
	    if (!bulundu){
	    	printf ("\nMusteri bulunamadi.");
		}
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    }
	
	void musteritelnoguncelle(){
    	FILE *d1;
        musteri mus;
        
        if ( (d1 = fopen("musteri.dat", "r+b") ) == NULL ){
     		printf ("Musteri dosyasi acilamadi...");
            //break;
            
     	}
 
        printf("Telefon Numarasi Guncelleme");

        int hno;
        int kayitno = 0;
        printf("\nMusteri No : ");
	    scanf("%d", &hno);
	    bool valid;
	    int hata;
	    int bulundu = 0;
		while (fread(&mus, sizeof(struct musteri), 1, d1)){
			kayitno = kayitno+1;
		    if (mus.hesapno==hno){
		    	bulundu = kayitno;
		    	break;
			}
		        
		}
	    if (bulundu == 0){
	    	printf ("\nMusteri bulunamadi.");
		} else{
			valid = false;
			do{
		        printf("\nCep Telefonu (5XXXXXXXXX) : ");
		        scanf("%s", &mus.telno);
		        if ((mus.telno[0] == '0') || (strlen(mus.telno) != 10)){
		        	printf("\nTelefon numarasi basinda '0' olmadan 10 hane olarak yazilmalidir!"); 
				} else {
					valid = true;
				}
			}
			while (not valid); 
			fseek(d1, (bulundu-1) * sizeof(struct musteri), SEEK_SET);
        	hata = fwrite (&mus, sizeof(struct musteri), 1, d1); 
			if (hata = 0) {
          		printf("\nDosyaya yazma hatasý!");
    		} else {
		  		printf("\nHesap guncellendi.");  	
	        }
	        
		}
        
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
        
    }
	
	void musteriadresguncelle(){
    	FILE *d1;
        musteri mus;
        
        if ( (d1 = fopen("musteri.dat", "r+b") ) == NULL ){
     		printf ("Musteri dosyasi acilamadi...");
            //break;
            
     	}
 
        printf("Adres Guncelleme");

        int hno;
        int kayitno = 0;
        printf("\nMusteri No : ");
	    scanf("%d", &hno);
	    bool valid;
	    int hata;
	    int bulundu = 0;
		while (fread(&mus, sizeof(struct musteri), 1, d1)){
			kayitno = kayitno+1;
		    if (mus.hesapno==hno){
		    	bulundu = kayitno;
		    	break;
			}
		        
		}
	    if (bulundu == 0){
	    	printf ("\nMusteri bulunamadi.");
		} else{
			printf("\nYeni Adres : ");
		    scanf("%s", &mus.adres);
			fseek(d1, (bulundu-1) * sizeof(struct musteri), SEEK_SET);
        	hata = fwrite (&mus, sizeof(struct musteri), 1, d1); 
			if (hata = 0) {
          		printf("\nDosyaya yazma hatasý!");
    		} else {
		  		printf("\nHesap guncellendi.");  	
	        }
	        
		}
        
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
        
    }
	
	void musteribakiyeekle(){
    	FILE *d1;
        musteri mus;
        
        if ( (d1 = fopen("musteri.dat", "r+b") ) == NULL ){
     		printf ("Musteri dosyasi acilamadi...");
            //break;
            
     	}
 
        printf("Bakiye Ekle");

        int hno;
        int kayitno = 0;
        int eklenecektutar;
        printf("\nMusteri No : ");
	    scanf("%d", &hno);
	    bool valid;
	    int hata;
	    int bulundu = 0;
		while (fread(&mus, sizeof(struct musteri), 1, d1)){
			kayitno = kayitno+1;
		    if (mus.hesapno==hno){
		    	printf ("\nMusteri Bakiyesi : %d", mus.bakiye);
		    	bulundu = kayitno;
		    	break;
			}
		        
		}
	    if (bulundu == 0){
	    	printf ("\nMusteri bulunamadi.");
		} else{
			valid = false;
			do{
		        printf("\n Eklenecek tutar : ");
		        scanf("%d", &eklenecektutar);
		        if (eklenecektutar < 0){
		        	printf("\n Ekleyeceginiz tutar 0'dan buyuk olmalidir!"); 
				} else {
					valid = true;
				}
			}
			while (not valid); 
			mus.bakiye = mus.bakiye + eklenecektutar;
			fseek(d1, (bulundu-1) * sizeof(struct musteri), SEEK_SET);
        	hata = fwrite (&mus, sizeof(struct musteri), 1, d1); 
			if (hata = 0) {
          		printf("\nDosyaya yazma hatasý!");
    		} else {
		  		printf("\nBakiye guncellendi.");  	
	        }
	        
		}
        
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
        
    }
	
	
	void urunekle(){
		FILE *d1;
   		d1 = fopen ("urun.dat", "ab+"); 
   		if (d1 == NULL){
			printf("Urun dosyasi acilamadi! Programdan cikiliyor.");
			exit(1);
		}
    	urun urn;
        printf("Yeni Urun Ekleniyor...");
		
        int ukod;
        bool valid;
		do{
			valid = true;
	        printf("\nUrun Kodu : ");
	        scanf("%d", &ukod);
		    while (fread(&urn, sizeof(struct urun), 1, d1)==1){
		    	if (urn.urunkod==ukod){
		    		printf ("\nBu kodlu urun mevcut. Lutfen yeni bir kod giriniz.");
		    		valid = false;
				}
		        
			}
        }
        while (not valid);   
        urn.urunkod = ukod;
		     
        printf("\nUrun Adi : ");
        scanf("%s", &urn.urunad);
        printf("\nUrun Fiyati : ");
        scanf("%d", &urn.fiyat);
        printf("\nUrun Stok : ");
        scanf("%d", &urn.stok);
        
        int hata;
        hata = fwrite (&urn, sizeof(struct urun), 1, d1);
     
        if (hata = 0) {
           printf("\nDosyaya yazma hatasý!");
    	} else {
		   printf("\nUrun olusturuldu.");  
		}
    	
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
    }
    
    void urunlistele(){
    	FILE *d1;
        urun urn;
        
        if ( (d1 = fopen("urun.dat", "rb") ) == NULL ){
     		printf ("Dosya acilamadi...");
            //break;
     	}
        
        
	    while(fread(&urn, sizeof(struct urun), 1, d1)){
	    
			printf ("\nUrun Kodu : %-10d Urun Adi : %-10s Urun Fiyati : %-10d TL Urun Stok : %-10d\n", urn.urunkod, urn.urunad, urn.fiyat, urn.stok); 
    		
		} 
	    
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    }
	
		
    
    
    
    
    void urunkodara(){
    	FILE *d1;
        urun urn;
        int ukod;
        
        if ( (d1 = fopen("urun.dat", "rb") ) == NULL ){
     		printf ("Dosya acilamadi...");
            //break;
     	}
        
        printf("\nUrun Kodu : ");
	    scanf("%d", &ukod);
	    bool bulundu = false;
		while (fread(&urn, sizeof(struct urun), 1, d1)){
		    if (urn.urunkod==ukod){
		    	printf ("\nUrun Kodu : %-10d Urun Adi : %-10s Urun Fiyati : %-10d TL Urun Stok : %-10d\n", urn.urunkod, urn.urunad, urn.fiyat, urn.stok); 
		    	bulundu = true;
			}
		        
		}
	    if (!bulundu){
	    	printf ("\nUrun bulunamadi.");
		}
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    }
    
    
    void urunadara(){
    	FILE *d1;
        urun urn;
        char uad[20];
        
        
        if ( (d1 = fopen("urun.dat", "rb") ) == NULL ){
     		printf ("Dosya acilamadi...");
            //break;
     	}
        
        printf("\nAranilan : ");
	    scanf("%s", &uad);
	    bool bulundu = false;
		while (fread(&urn, sizeof(struct urun), 1, d1)){
		    if (strstr(urn.urunad, uad)!= NULL){
		    	printf ("\nUrun Kodu : %-10d Urun Adi : %-10s Urun Fiyati : %-10d TL Urun Stok : %-10d\n", urn.urunkod, urn.urunad, urn.fiyat, urn.stok); 
		    	bulundu = true;
			}
		        
		}
	    if (!bulundu){
	    	printf ("\nUrun bulunamadi.");
		}
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    }
    
    
    void urunfiyatguncelle(){
    	FILE *d1;
        urun urn;
        
        if ( (d1 = fopen("urun.dat", "r+b") ) == NULL ){
     		printf ("Urun dosyasi acilamadi...");
            //break;
            
     	}
 
        printf("Urun Fiyat Guncelleme");

        int ukod;
        int kayitno = 0;
        printf("\nUrun Kodu : ");
	    scanf("%d", &ukod);
	    bool valid;
	    int hata;
	    int bulundu = 0;
		while (fread(&urn, sizeof(struct urun), 1, d1)){
			kayitno = kayitno+1;
		    if (urn.urunkod==ukod){
		    	bulundu = kayitno;
		    	break;
			}
		        
		}
	    if (bulundu == 0){
	    	printf ("\nUrun bulunamadi.");
		} else{
			valid = false;
			do{
		        printf("\nYeni Fiyat : ");
		        scanf("%d", &urn.fiyat);
		        if (urn.fiyat <= 0 ){
		        	printf("\nFiyat 0 olamaz! Lutfen yeni bir fiyat belirleyiniz!"); 
				} else {
					valid = true;
				}
			}
			while (not valid); 
			fseek(d1, (bulundu-1) * sizeof(struct urun), SEEK_SET);
        	hata = fwrite (&urn, sizeof(struct urun), 1, d1); 
			if (hata = 0) {
          		printf("\nDosyaya yazma hatasý!");
    		} else {
		  		printf("\nFiyat guncellendi.");  	
	        }
	        
		}
        
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
        
    }
    
    void urunstokguncelle(){
    	FILE *d1;
        urun urn;
        
        if ( (d1 = fopen("urun.dat", "r+b") ) == NULL ){
     		printf ("Urun dosyasi acilamadi...");
            //break;
            
     	}
 
        printf("Urun Stok Guncelleme");

        int ukod;
        int kayitno = 0;
        printf("\nUrun Kodu : ");
	    scanf("%d", &ukod);
	    bool valid;
	    int hata;
	    int bulundu = 0;
		while (fread(&urn, sizeof(struct urun), 1, d1)){
			kayitno = kayitno+1;
		    if (urn.urunkod==ukod){
		    	bulundu = kayitno;
		    	break;
			}
		        
		}
	    if (bulundu == 0){
	    	printf ("\nUrun bulunamadi.");
		} else{
			valid = false;
			do{
		        printf("\nYeni Stok : ");
		        scanf("%d", &urn.stok);
		        if (urn.stok < 0 ){
		        	printf("\nStok 0'dan kucuk olamaz! Yeni bir stok giriniz!"); 
				} else {
					valid = true;
				}
			}
			while (not valid); 
			fseek(d1, (bulundu-1) * sizeof(struct urun), SEEK_SET);
        	hata = fwrite (&urn, sizeof(struct urun), 1, d1); 
			if (hata = 0) {
          		printf("\nDosyaya yazma hatasý!");
    		} else {
		  		printf("\nStok guncellendi.");  	
	        }
	        
		}
        
	    
        fclose(d1);
        
        printf("\nDevam etmek icin herhangi bir tusa basiniz...");  
		getch();
        
    }
    
    
    void urunsatis(){
    	FILE *d1;
        musteri mus;
        int hno;
        FILE *d2;
        urun urn;
        int ukod;
        
        if ( (d1 = fopen("musteri.dat", "rb+") ) == NULL ){
     		printf ("Dosya acilamadi...");
            return;
     	}
        if ( (d2 = fopen("urun.dat", "rb+") ) == NULL ){
     		printf ("Dosya acilamadi...");
            return;
     	}
     	
        printf("\nMusteri No : ");
	    scanf("%d", &hno);
	    int bulundu = 0;
	    int kayitno = 0;
		while (fread(&mus, sizeof(struct musteri), 1, d1)){
			kayitno = kayitno+1;
		    if (mus.hesapno==hno){
		    	printf ("\nMusteri No : %10d Adi : %-10s Soyadi : %-20s Telefon : %-10s Bakiye : %7d TL Adres : %-100s\n", mus.hesapno, mus.ad, mus.soyad, mus.telno, mus.bakiye, mus.adres); 
		    	bulundu = kayitno;
		    	break;
			}
		        
		}
	    if (bulundu == 0){
	    	printf ("\nMusteri bulunamadi.");
	    	return;
		}
		
		FILE *d3;
		char dosyaadi[100] = "";
		strcat (dosyaadi, mus.ad);
		strcat (dosyaadi, "_");
		strcat (dosyaadi, mus.soyad);
		strcat (dosyaadi, ".txt");
		
		if ( (d3 = fopen(dosyaadi, "w+") ) == NULL ){
     		printf ("Dosya acilamadi...");
            return;
     	}
     	fprintf (d3, "\nSATIS FATURASI");
		fprintf (d3, "\nMusteri No : %10d Adi : %-10s Soyadi : %-20s Telefon : %-10s Adres : %-100s\n", mus.hesapno, mus.ad, mus.soyad, mus.telno, mus.adres);
		fprintf (d3, "\nURUNLER :");
		int toplamsatis = 0;
		
		do {
			printf ("\nSatilacak urun kodu (bitirmek icin -1 giriniz) : ");
			scanf ("%d", &ukod);
			bool urunbulundu = false;
			fseek (d2, 0, SEEK_SET);
			int urunkayitno = 0;
			while (fread(&urn, sizeof(struct urun), 1, d2)){
				urunkayitno = urunkayitno+1;
			    if (urn.urunkod==ukod){
			    	printf ("\nUrun Kodu : %-10d Urun Adi : %-10s Urun Fiyati : %-10d TL Urun Stok : %-10d\n", urn.urunkod, urn.urunad, urn.fiyat, urn.stok); 
			    	if (urn.stok > 0 ){
			    		if(urn.fiyat < mus.bakiye){
			    			printf ("\nSatis gerceklesti.");
			    			urn.stok = urn.stok-1;
			    			mus.bakiye = mus.bakiye - urn.fiyat;
			    			fseek (d2, (urunkayitno-1) * sizeof(struct urun), SEEK_SET);
        					fwrite (&urn, sizeof(struct urun), 1, d2); 
        					urunbulundu = true;
        					toplamsatis = toplamsatis + urn.fiyat;
        					fprintf (d3, "\nUrun Kodu : %-10d Urun Adi : %-10s Urun Fiyati : %-10d TL", urn.urunkod, urn.urunad, urn.fiyat);
        					break;
						} else{
							printf ("\nMusteri bakiyesi yetersiz.");
						}
					} else{
						printf ("\nUrun stokta yok.");
					}
					
			    	urunbulundu = true;
				}
			        
			}
		    if (!urunbulundu){
		    	printf ("\nUrun bulunamadi.");
			}
		}
		while(ukod != -1);
		fseek (d1, (bulundu-1) * sizeof(struct musteri), SEEK_SET);
        fwrite (&mus, sizeof(struct musteri), 1, d1); 
        fprintf (d3, "\nTOPLAM SATIS TUTARI : %d", toplamsatis);
        
		fclose (d3);
		
		
        printf("\nDevam etmek icin herhangi bir tusa basiniz");  
		getch();

        fclose(d1);
    	fclose(d2);
    	
    	
	}
    
    int main()
    {
        
        int secim;
        do{
        	system("cls"); 
            
            printf("\nMusteri Islemleri");
            printf("\n==================");
            printf("\n1-  Musteri Ekle");
            printf("\n2-  Musteri Listele");
            printf("\n3-  Musteri Ara(musteri no'ya gore)");
            printf("\n4-  Musteri Ara (musteri ismine gore)");
            printf("\n5-  Musteri Telefon Numarasi Guncelle");
            printf("\n6-  Musteri Adres Guncelle");
            printf("\n7-  Musteri Bakiye Ekle");
            printf("\n\nUrun Islemleri");
            printf("\n================");
            printf("\n8-  Urun Ekle");
            printf("\n9-  Urun Listele");
            printf("\n10- Urun Ara (urun koduna gore)");
            printf("\n11- Urun Ara (urun adina gore)");
            printf("\n12- Urun Fiyat Guncelle");
            printf("\n13- Urun Stok Guncelle");
            printf("\n\nSatis Islemleri");
            printf("\n================");
            printf("\n14- Urun Satis");
            printf("\n\n15- Cikis");
            
            printf("\nSeciminiz : ");
			scanf("%d", &secim);
			system("cls"); 
        	if(secim==1) musteriekle();
            if(secim==2) musterilistele();
            if(secim==3) musterinoara();
            if(secim==4) musteriisimara();
            if(secim==5) musteritelnoguncelle();
            if(secim==6) musteriadresguncelle();
			if(secim==7) musteribakiyeekle();
			if(secim==8) urunekle();
			if(secim==9) urunlistele();
			if(secim==10) urunkodara();
			if(secim==11) urunadara();
			if(secim==12) urunfiyatguncelle();
			if(secim==13) urunstokguncelle();
			if(secim==14) urunsatis();
			
        }
        while (secim!=15);
    }
