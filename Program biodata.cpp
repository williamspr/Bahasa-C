#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>
#include<time.h>

#define MAXDATA 100
struct date{
	int tanggal[MAXDATA], tahun[MAXDATA];
	char bulan[MAXDATA][10];
};

time_t local;

struct biodata{
	char nama[MAXDATA][40], agama[MAXDATA][10], Makanan_favorit[MAXDATA][20], Minuman_favorit[MAXDATA][18], alamat[MAXDATA][14];
	float berat_badan[MAXDATA], tinggi_badan[MAXDATA];
	struct date tgl_lahir[MAXDATA];
	int banyak_anak[MAXDATA];
};

struct biodata bio[MAXDATA];
char no_bio[MAXDATA][12] = {"0811406199", "1452344897", "4327544897", "6557895324", "7455234116",
                            "0812657499", "3221673981", "4356801245", "3494095423", "5892117787"};
char password[MAXDATA][17];
char pin_pet[7] = {"151002"};
int total = 0;
int khusus = 10;

void insert(){
	if(total==MAXDATA){
		printf("\nData penuh. Anda tidak dapat mengisi biodata anda lagi kecuali ada orang yang ingin menghapus biodatanya\n\n");
		return;
	}
	
	do{
		printf("\nMasukkan password untuk membuka biodata anda nanti [Max length 15]: ");
		scanf("%s", &password[total]);
	}while(strlen(password[total]) > 15);
	
	do{
		printf("\nNama lengkap [MAX 30]: ");
		fflush(stdin);
		scanf("%[^\n]s", &bio[total].nama[total]);
	}while(strlen(bio[total].nama[total])>30 );
	
	do{
	    printf("Tanggal lahir        : ");
		scanf("%d %s %d", &bio[total].tgl_lahir[total].tanggal[total], &bio[total].tgl_lahir[total].bulan[total], &bio[total].tgl_lahir[total].tahun[total]);
	}while(bio[total].tgl_lahir[total].tanggal[total] > 31 || bio[total].tgl_lahir[total].tahun[total] > 2021);
	
	printf("Agama                : ");
	scanf("%s", &bio[total].agama[total]);
	
	printf("Makanan favorit      : ");
	fflush(stdin);
	scanf("%[^\n]s", &bio[total].Makanan_favorit[total]);
	
	printf("Minuman favorit      : ");
	fflush(stdin);
	scanf("%[^\n]s", &bio[total].Minuman_favorit[total]);
	
	printf("Alamat [Kota tempat tinggal] : ");
	fflush(stdin);
	scanf("%[^\n]s", &bio[total].alamat[total]);
	
	do{
	   printf("Berat badan [dalam kg dan sertakan desimal maks 2 angka di belakang koma kalau perlu] : ");
	   scanf("%f", &bio[total].berat_badan[total]);
    }while(bio[total].berat_badan[total] < 0);
    
	do{
	   printf("Tinggi badan [dalam meter dan sertakan 2 angka dibelakang koma] : ");
	   scanf("%f", &bio[total].tinggi_badan[total]);
    }while(bio[total].tinggi_badan[total] < 0 || bio[total].tinggi_badan[total] > 3 );
    
    do{
    	printf("Banyak anak          : ");
    	scanf("%d", &bio[total].banyak_anak[total]);
	}while(bio[total].banyak_anak[total] < 0);
	
	printf("\nData telah ditambahkan\n\n");  
	total++;
	
	printf("Nomor biodata anda akan dikirim ke email. Nomor biodata dapat digunakan sewaktu-waktu\n\n");
}

void tampilkan_data(){
	if(total==0){
		printf("\nData kosong.\n\n");
		return;
	}
	printf("\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("No  Nama Lengkap                    Tanggal Lahir      Agama       Makanan Favorit       Minuman Favorit     Alamat          BB       TB     Banyak anak\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0; i<total; i++){
	printf("%-2d  %-30s  %-2d %-9s %d  %-10s  %-20s  %-18s  %-14s  %.1f kg  %.2f m     %1d\n", i+1, bio[i].nama[i], bio[i].tgl_lahir[i].tanggal[i], bio[i].tgl_lahir[i].bulan[i], bio[i].tgl_lahir[i].tahun[i], bio[i].agama[i], bio[i].Makanan_favorit[i], bio[i].Minuman_favorit[i], bio[i].alamat[i], bio[i].berat_badan[i], bio[i].tinggi_badan[i], bio[i].banyak_anak[i]);	
	}
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
void hapus_data(){
	int percobaan = 0;
	
	if(total==0){
		printf("\nData kosong. Tidak ada yang bisa dihapus\n\n");
		return;
	}
	tampilkan_data();
	int target;
	char masukan[MAXDATA][17];
	do{
	printf("Data nomor berapa yang ingin dihapus? "); scanf("%d", &target);
    }while(target<0 || target>total);
	ulang:
	printf("\nMasukkan password anda : "); scanf("%s", &masukan[target-1]);
	
	if(strcmp(password[target-1], masukan[target-1])!=0){
		printf("Password yang anda masukkan salah\n");
		percobaan++;
		if(percobaan==3){
			printf("\nAnda telah salah sebanyak 3 kali. Sadar diri lah\n\n");
			return;
		}
		goto ulang;
		return;
	}
	
	for(int i=target-1; i<total; i++){
		strcpy(bio[i].nama[i], bio[i+1].nama[i+1]);
		bio[i].tgl_lahir[i].tanggal[i] = bio[i+1].tgl_lahir[i+1].tanggal[i+1];
		strcpy(bio[i].tgl_lahir[i].bulan[i], bio[i+1].tgl_lahir[i+1].bulan[i+1]);
		bio[i].tgl_lahir[i].tahun[i] = bio[i+1].tgl_lahir[i+1].tahun[i+1];
		strcpy(bio[i].agama[i], bio[i+1].agama[i+1]);
		strcpy(bio[i].Makanan_favorit[i], bio[i+1].Makanan_favorit[i+1]);
		strcpy(bio[i].Minuman_favorit[i], bio[i+1].Minuman_favorit[i+1]);
		strcpy(bio[i].alamat[i], bio[i+1].alamat[i+1]);
		bio[i].berat_badan[i] = bio[i+1].berat_badan[i+1];
		bio[i].tinggi_badan[i] = bio[i+1].tinggi_badan[i+1];
		bio[i].banyak_anak[i] = bio[i+1].banyak_anak[i+1];
		strcpy(password[i], password[i+1]);
		strcpy(no_bio[i], no_bio[i+1]);
	}
	total--;
	khusus--;
	printf("\nData telah dihapus\n\n");
}

void ubahdata(){
	int target, what;
	char masukan[MAXDATA][17];
	int percobaan = 0;
	
	if(total==0){
		printf("\nData kosong\n\n");
		return;
	}
	tampilkan_data();
	do{
	    printf("\nData nomor berapa yang ingin diubah [1.2.3...%d]? ", total);
	    scanf("%d", &target);
    }while(target<0 || target>total);
    
    ulang:
    printf("Masukkan password anda: "); scanf("%s", &masukan[target-1]);
    if(strcmp(password[target-1], masukan[target-1])!=0){
    	printf("Password yang anda masukkan salah\n\n");
    	percobaan++;
    	if(percobaan==3){
    		printf("Anda telah salah 3 kali. Sadar diri lah!\n\n");
    		return;
		}
    	goto ulang;
    	return;
	}
	
    do{
    	printf("\n1. Nama lengkap\n");
    	printf("2. Tanggal lahir\n");
    	printf("3. Agama\n");
    	printf("4. Makanan favorit\n");
    	printf("5. Minuman favorit\n");
    	printf("6. Alamat\n");
    	printf("7. Berat badan\n");
    	printf("8. Tinggi badan\n");
    	printf("9. Banyak anak\n");
    	printf("Yang ingin diubah : "); scanf("%d", &what);
	}while(what<0 || what>9);
	
   switch(what){
   	    case 1:
   	    do{
   	    	printf("Masukkan nama : ");
   	    	fflush(stdin);
   	    	scanf("%[^\n]s", &bio[target-1].nama[target-1]);
		   }while(strlen (bio[target-1].nama[target-1])>30);
		printf("\nNama telah diubah\n");
		break;
		
		case 2:
			do{
				printf("Masukkan tanggal lahir : ");
				scanf("%d %s %d", &bio[target-1].tgl_lahir[target-1].tanggal[target-1], &bio[target-1].tgl_lahir[target-1].bulan[target-1], &bio[target-1].tgl_lahir[target-1].tahun[target-1]);
			}while(bio[target-1].tgl_lahir[target-1].tanggal[target-1] > 31 || bio[target-1].tgl_lahir[target-1].tahun[target-1] > 2021);
		printf("Tanggal lahir %s telah diubah\n", bio[target-1].nama[target-1]);
		break;
		
		case 3:
			printf("Masukkan agama baru : ");
			scanf("%s", &bio[target-1].agama[target-1]);
			printf("Agama telah diubah\n");
		break;
		
		case 4:
			printf("Masukkan makanan favorit: ");
			fflush(stdin);
			scanf("%[^\n]s", &bio[target-1].Makanan_favorit[target-1]);
			printf("Makanan favorit telah diubah\n");
		break;
		
		case 5:
			printf("Masukkan minuman favorit: ");
			fflush(stdin);
			scanf("%[^\n]s", &bio[target-1].Minuman_favorit[target-1]);
			printf("\nMinuman favorit telah diubah\n");
		break;
		
		case 6:
			printf("Masukkan alamat: ");
			fflush(stdin);
			scanf("%[^\n]s", &bio[target-1].alamat[target-1]);
			printf("\nAlamat telah diubah\n");
		break;
		
		case 7:
			do{
	            printf("Berat badan [dalam kg dan sertakan desimal 1 angka di belakang koma kalau perlu] : ");
	            scanf("%f", &bio[target-1].berat_badan[target-1]);
            }while(bio[target-1].berat_badan[target-1] < 0);
            printf("\nBerat badan telah diubah\n");
        break;
		
		case 8:
		   	do{
	            printf("Tinggi badan [dalam meter dan sertakan 2 angka dibelakang koma] : ");
	            scanf("%f", &bio[target-1].tinggi_badan[target-1]);
            }while(bio[target-1].tinggi_badan[target-1] < 0 || bio[target-1].tinggi_badan[target-1] > 3 );
            printf("\nTinggi badan telah diubah\n");
        break;
        
        case 9:
        	do{
    	        printf("Banyak anak          : ");
    	        scanf("%d", &bio[target-1].banyak_anak[target-1]);
	        }while(bio[target-1].banyak_anak[target-1] < 0);
	        printf("\nBanyak anak telah diubah\n");
	    break;
   }
}

void ubahpassword(){
	if(total==0){
		printf("Data masih kosong. Silahkan buat password dulu\n");
		return;
	}
	tampilkan_data();
	int urutan;
	do{
		printf("Anda user nomor berapa? "); scanf("%d", &urutan);
	}while(urutan<0 || urutan>total);
	
	char nobio[12];
	printf("\nMasukkan nomor biodata anda: "); scanf("%s", &nobio);
	if(strcmp(no_bio[urutan-1], nobio)!=0){
		printf("\nNomor biodata anda salah\n\n");
		return;
	}
	else{
		printf("\nMasukkan password baru anda: "); scanf("%s", &password[urutan-1]);
		printf("\nPassword anda telah diubah\n\n");
	}
}

void tambahkan_nobio(){
	char pin[7];
	printf("\nMasukkan pin anda: "); scanf("%s", &pin);
	if(strcmp(pin_pet, pin)!=0){
	   printf("\nPin anda salah\n\n");
	   return;	
	}
	else{
		do{
			printf("\nMasukkan nomor biodata user ke-%d : ", khusus+1); scanf("%s", &no_bio[khusus]);
		}while(strlen(no_bio[khusus])!=10);
		
		khusus++;
		printf("\nOk. Sip.\n\n");
	}
} 
int main(){
	int pilihan;  
	time(&local);
	while(1){
	printf("-------------------------------------------------\n");
	printf("   SELAMAT DATANG DI TEMPAT PENYIMPANAN BIODATA  \n");
	printf("-------------------------------------------------\n");
	printf("Kapasitas         : %d\n", MAXDATA);
	printf("Kapasitas tersisa : %d\n\n", MAXDATA - total);
	printf("%s\n", ctime(&local));
	printf("1. Masukkan biodata\n");
	printf("2. Lihat Biodata yang ada\n");
	printf("3. Hapus biodata\n");
	printf("4. Ubah biodata\n");
	printf("5. Ubah password\n");
	printf("6. Khusus petugas\n");
	printf("7. Exit\n");
	printf("Masukkan pilihan anda: "); scanf("%d", &pilihan);
	
	switch(pilihan){
		case 1:
			insert();
			system("pause");
			system("cls");
			break;
			
		case 2:
			tampilkan_data();
			system("pause");
			system("cls");
			break;
			
		case 3:
			hapus_data();
			system("pause");
			system("cls");
			break;
			
		case 4:
			ubahdata();
			system("pause");
			system("cls");
			break;
		
		case 5:
			ubahpassword();
			system("pause");
			system("cls");
			break;
		
		case 6:
		    tambahkan_nobio();
			system("pause");
			system("cls");
			break;
				
		case 7:
		   exit(1);
		   	
		default:
			printf("\nPilihan anda tidak valid\n\n");
			system("pause");
			system("cls");
	}
	}
}
