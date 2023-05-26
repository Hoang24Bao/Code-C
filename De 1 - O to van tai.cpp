#include<stdio.h>
#include<stdlib.h>

typedef struct OtoVanTai{
	char BKS[10],CT;  //BKS: biển kiểm soát, CT: công ty chủ quản
	float TT;        //TT: trọng tải
};

void docfile(struct OtoVanTai oto[],int *n) {
	FILE*f=fopen("inputotvt.txt","r");
	if(f==NULL) {
		printf("Loi doc tep");
		exit(1);
	}
	fscanf(f,"%d\n",n);
	for(int i=0;i<*n;i++) {
		fscanf(f,"%s %f %c",&oto[i].BKS,&oto[i].TT,&oto[i].CT);
	}
	fclose(f);
}

int demOtoCTA(struct OtoVanTai oto[],int n) {
	int dem=0;
	for(int i=0;i<n;i++) {
		if(oto[i].TT==12 && oto[i].CT=='A') dem++;
	}
	return dem;
}

float TrongTaiTB(struct OtoVanTai oto[],int n, char CT) {
	float tongTrongTai=0.0;
	int dem=0;
	for(int i=0;i<n;i++) {
		if(oto[i].CT==CT) {
			tongTrongTai+=oto[i].TT;
			dem++;
		}
	}
	if(dem==0) return 0.0;
	return tongTrongTai/dem;
}

void xuatfile(struct OtoVanTai oto[],int n,int k) {
	FILE*fout=fopen("outputotvt.txt","w");
	if(fout==NULL) {
		printf("Khong the mo file");
		exit(1);
	}
	if(k>n) k=n;
	for(int i=0;i<n-1;i++) {
		for(int j=i+1;j<n;j++) {
			if(oto[i].TT>oto[j].TT) {
				struct OtoVanTai temp = oto[i];
                oto[i] = oto[j];
                oto[j] = temp;
			}
		}
	}
	for(int i=0;i<k;i++) {
		fprintf(fout,"%s %.2f %c\n",oto[i].BKS,oto[i].TT,oto[i].CT);
		printf("%s %.2f %c\n",oto[i].BKS,oto[i].TT,oto[i].CT);
	}
	fclose(fout);
}

int main() {
	struct OtoVanTai oto[100];
	int n;
	docfile(oto,&n);
	int demCTA=demOtoCTA(oto,n);
	printf("So xe CT A co TT 12 tan: %d\n",demCTA);
	for(char CT='A';CT<='D';CT++) {
		float TrongTaitb=TrongTaiTB(oto,n,CT);
		printf("Trong tai TB cua CT %c: %.2f\n",CT,TrongTaitb);
	}
	int k;
	printf("Nhap k: "); scanf("%d",&k);
	printf("Danh sach %d oto co trong tai nho nhat:\n",k);
	xuatfile(oto,n,k);
}