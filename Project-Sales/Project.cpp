#include<bits/stdc++.h>

struct salesperson{
	char number[10];
	char name[80];
	char sex[10];
	char edu[40];
	double SUM;
};
struct commodity{
	char number[5];
	char name[40];
	int count;
	double prize;
};
struct Sell_Record{
	char NoS[5];
	char NoC[5];
	int Rec;
};
struct Charge_Record{
	char NoC[5];
	int Rec;
};

void mainmenu();
void salesperson();
void S_search();
void S_change();
void S_delete();
void S_add();
void S_rank();
void C_search();
void C_change();
void C_delete();
void C_add();
void C_rank();
void commodity();
void record();
void R_add();
void cls(){
	system("cls");
};

int main(){
	mainmenu();
	return 0;
}
void mainmenu(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#             �����ʹ洢���۹���ϵͳ            #\n");
	printf("#                                               #\n");
	printf("#       1������Ա��ز˵�                       #\n");
	printf("#       2����Ʒ�����ز˵�                     #\n");
	printf("#       3�����ۼ�¼��ز˵�                     #\n");
	printf("#       0���˳�ϵͳ                             #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("������ָ��ǰ�����:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();salesperson(); break;
		case 2:cls();commodity(); break;
		case 3:cls();record(); break;
		case 0:exit(0); break;
		default:cls();printf("����ĺ��񲻶���...��������һ�鿴���ɡ�\n");mainmenu();
	}
}
void salesperson(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   ����Ա�˵�                  #\n");
	printf("#                                               #\n");
	printf("#       1����ѯ����Ա��Ϣ                       #\n");
	printf("#       2���޸�����Ա��Ϣ                       #\n");
	printf("#       3��ɾ������Ա��Ϣ                       #\n");
	printf("#       4����������Ա��Ϣ                       #\n");
	printf("#       5������Ա�������                     #\n");
	printf("#       0�������ϼ��˵�                         #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("������ָ��ǰ�����:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();S_search(); break;
		case 2:cls();S_change(); break;
		case 3:cls();S_delete(); break;
		case 4:cls();S_add(); break;
		case 5:cls();S_rank();break; 
		case 0:cls();mainmenu(); break;
		default:cls();printf("����ĺ��񲻶���...��������һ�鿴���ɡ�\n");salesperson();
	}
}
void S_search(){
	FILE *fp;
	int Persons,i;
	char temp;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("�ܹ���%dλԱ�������������ǵ���Ϣ��\n",Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	system("pause");
	cls();
	salesperson();
}
void S_change(){
	FILE *fp;
	int Persons,i,t=-1;
	char temp;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("�ܹ���%dλԱ�������������ǵ���Ϣ��\n",Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	struct salesperson change;
	printf("�밴 ��� ���� �Ա� ѧ�� �����۶� �ĸ�ʽ������Ҫ�޸ĵ�����Ա��Ϣ��\n");
	scanf("%s %s %s %s %lf",change.number,change.name,change.sex,change.edu,&change.SUM);
	for (i=0;i<Persons;i++){
		if ((S[i].number[3]==change.number[3]) && (S[i].number[2]==change.number[2])){
			t=i;
		}
	}
	if (t==-1){
		printf("û���ҵ��������Ա��...�����������Կ���\n");
		S_change(); 
	}
	fp=fopen("Salespersons.txt","w");
	fprintf(fp,"%d",Persons);
	for(i=0;i<Persons;i++){
		if (t==i){
			fprintf(fp,"\n%s %s %s %s %.1lf",change.number,change.name,change.sex,change.edu,change.SUM);
		}else {
			fprintf(fp,"\n%s %s %s %s %.1lf",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
		}
	}
	fclose(fp); 
	printf("�޸���ϣ������ϼ��˵�\n");
	system("pause");
	cls();
	salesperson(); 
}
void S_delete(){
	FILE *fp;
	int Persons,i,t=-1;
	char del[5];
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("�ܹ���%dλԱ�������������ǵ���Ϣ��\n",Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	printf("������Ҫɾ��������Ա��ţ�\n");
	scanf("%s",del);
		for (i=0;i<Persons;i++){
		if ((S[i].number[2]==del[2]) && (S[i].number[3]==del[3])){
			t=i;
			break;
		}
	}
	if (t==-1){
		printf("û���ҵ��������Ա��...�����������Կ���\n");
		S_delete(); 
	}
	fp=fopen("Salespersons.txt","w");
	fprintf(fp,"%d",Persons-1);
	for(i=0;i<Persons;i++){
		if (t==i) {
			continue;
		}
		fprintf(fp,"\n%s %s %s %s %.1lf",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp); 
	printf("ɾ����ϣ������ϼ��˵�\n");
	system("pause");
	cls();
	salesperson();
}
void S_add(){
	FILE *fp;
	int Salesperson,i;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Salesperson);
	struct salesperson S[Salesperson];
	for (i=0;i<Salesperson;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);	}
	fclose(fp);
	struct salesperson add;
	printf("�밴 ��� ���� �Ա� ѧ�� �����۶� �ĸ�ʽ��������Ա��Ϣ��\n");
	scanf("%s %s %d %lf",add.number,add.name,add.sex,add.edu,add.SUM);
	for (i=0;i<Salesperson;i++){
		if ((S[i].number[2]==add.number[2]) && (S[i].number[3]==add.number[3])){
			cls();
			printf("���󣡺ͱ��Ϊ%s������Ա�����ͬ������������\n",S[i].number);
			S_add(); 
		} 
		else if (add.number[0] != 'E'){
			printf("��Ÿ�ʽ��������������\n");
			C_add(); 
		}
	}
	fp=fopen("Salespersons.txt","a+");
	fprintf(fp,"\n%s %s %s %s %.1lf",add.number,add.name,add.sex,add.edu,add.SUM);
	fclose(fp);
	fp=fopen("Salespersons.txt","r+");
	Salesperson++;
	fprintf(fp,"%d\n",Salesperson);
	fclose(fp);
	printf("д�����,�����ϼ��˵�");
	system("pause");
	cls();
	salesperson(); 
}
void S_rank(){
	FILE *fp;
	int Persons,i,j;
	if ((fp=fopen("Salespersons.txt","r+"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		salesperson(); 
	}
	fscanf (fp,"%d",&Persons);
	printf("�ܹ���%dλԱ�������������ǵ���Ϣ��\n",Persons);
	struct salesperson S[Persons],temp;
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	fclose(fp);
	printf("�����ǰ������۶�����Ľ��\n");
	for (i=0;i<Persons-1;i++){
	for (j=i+1;j<Persons;j++){
		if (S[i].SUM<S[j].SUM){
			temp=S[i];S[i]=S[j];S[j]=temp;
		}
	}
	}
	for (i=0;i<Persons;i++){
		printf("%s %s %s %s %.1lf\n",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);
	}
	printf("�������\n");
	system("pause");
	cls();
	salesperson();
} 
void commodity(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   ��Ʒ�˵�                    #\n");
	printf("#                                               #\n");
	printf("#       1����ѯ��Ʒ��Ϣ                         #\n");
	printf("#       2���޸���Ʒ��Ϣ                         #\n");
	printf("#       3��ɾ����Ʒ��Ϣ                         #\n");
	printf("#       4��������Ʒ��Ϣ                         #\n");
	printf("#       5����Ʒ�������                       #\n");
	printf("#       0�������ϼ��˵�                         #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("������ָ��ǰ�����:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();C_search(); break;
		case 2:cls();C_change(); break;
		case 3:cls();C_delete(); break;
		case 4:cls();C_add(); break;
		case 5:cls();C_rank();break;
		case 0:cls();mainmenu(); break;
		default:cls();printf("����ĺ��񲻶���...��������һ�鿴���ɡ�\n");commodity();
	}
}
void C_search(){
	FILE *fp;
	int Commodity,i;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("�ܹ���%d����Ʒ�����������ǵ���Ϣ��\n",Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	system("pause");
	cls(); 
	commodity();
}
void C_change(){
	FILE *fp;
	int Commodity,i,t=-1;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("�ܹ���%d����Ʒ�����������ǵ���Ϣ��\n",Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	struct commodity change;
	printf("�밴 ��� ���� ���� �۸� �ĸ�ʽ����Ҫ�޸ĵ���Ʒ��Ϣ��\n");
	scanf("%s %s %d %lf",change.number,change.name,&change.count,&change.prize);
		for (i=0;i<Commodity;i++){
		if ((S[i].number[2]==change.number[2]) && (S[i].number[3]==change.number[3])){
			t=i;
		}
	}
	if (t==-1){
		printf("û���ҵ������Ʒ��...�����������Կ���\n");
		C_change(); 
	}
	fp=fopen("Commodity.txt","w");
	fprintf(fp,"%d",Commodity);
	for(i=0;i<Commodity;i++){
		if (t==i){
			fprintf(fp,"\n%s %s %d %lf",change.number,change.name,change.count,change.prize);
		}
		else {
			fprintf(fp,"\n%s %s %d %.1lf",S[i].number,S[i].name,S[i].count,S[i].prize);
		}
		
	}
	fclose(fp); 
	printf("�޸���ϣ������ϼ��˵�\n");
	system("pause");
	cls();
	commodity(); 
}
void C_delete(){
		FILE *fp;
	int Commodity,i,t=-1;
	char del[5];
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("�ܹ���%d����Ʒ�����������ǵ���Ϣ��\n",Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	printf("������Ҫɾ������Ʒ��ţ�\n");
	scanf("%s",del);
		for (i=0;i<Commodity;i++){
		if ((S[i].number[2]==del[2]) && (S[i].number[3]==del[3])){
			t=i;
			break;
		}
	}
	if (t==-1){
		printf("û���ҵ������Ʒ��...�����������Կ���\n");
		C_delete(); 
	}
	fp=fopen("Commodity.txt","w");
	fprintf(fp,"%d",Commodity-1);
	for(i=0;i<Commodity;i++){
		if (t==i) {
			continue;
		}
		fprintf(fp,"\n%s %s %d %.1lf",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp); 
	printf("ɾ����ϣ������ϼ��˵�\n");
	system("pause");
	cls();
	commodity();
}
void C_add(){
	FILE *fp;
	int Commodity,i;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	struct commodity S[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
	}
	fclose(fp);
	struct commodity add;
	printf("�밴 ��� ���� ���� �۸� �ĸ�ʽ������Ʒ��Ϣ��\n");
	scanf("%s %s %d %lf",add.number,add.name,&add.count,&add.prize);
	for (i=0;i<Commodity;i++){
		if ((S[i].number[2]==add.number[2]) && (S[i].number[3]==add.number[3])){
			cls();
			printf("���󣡺ͱ��Ϊ%s����Ʒ�����ͬ������������\n",S[i].number);
			C_add(); 
		} 
		else if (add.number[0] != 'P'){
			printf("��Ÿ�ʽ��������������\n");
			C_add(); 
		}
	}
	fp=fopen("Commodity.txt","a+");
	fprintf(fp,"\n%s %s %d %lf",add.number,add.name,add.count,add.prize);
	fclose(fp);
	fp=fopen("Commodity.txt","r+");
	Commodity++;
	fprintf(fp,"%d\n",Commodity);
	fclose(fp);
	printf("д�����");
	system("pause");
	cls();
	commodity(); 
}
void C_rank(){
	FILE *fp;
	int Commodity,i,j;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		commodity(); 
	}
	fscanf (fp,"%d",&Commodity);
	printf("�ܹ���%d����Ʒ�����������ǵ���Ϣ��\n",Commodity);
	struct commodity S[Commodity],temp;
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",S[i].number,S[i].name,&S[i].count,&S[i].prize);
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	fclose(fp);
	printf("�����ǰ������۶�����Ľ��\n");
	for (i=0;i<Commodity-1;i++){
	for (j=i+1;j<Commodity;j++){
		if ((S[i].count*S[i].prize)<(S[j].count*S[j].prize)){
			temp=S[i];S[i]=S[j];S[j]=temp;
		}
	}
	}
	for (i=0;i<Commodity;i++){
		printf("%s %s %d %.1lf\n",S[i].number,S[i].name,S[i].count,S[i].prize);
	}
	printf("�������\n");
	system("pause");
	cls(); 
	commodity(); 
}
void record(){
	int i;
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   ���ۼ�¼�˵�                #\n");
	printf("#                                               #\n");
	printf("#       1���������ۼ�¼                         #\n");
	printf("#       0�������ϼ��˵�                         #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("������ָ��ǰ�����:");
	scanf ("%d",&i);
	switch (i){
		case 1:cls();R_add(); break;
		case 0:cls();mainmenu(); break;
		default:cls();printf("����ĺ��񲻶���...��������һ�鿴���ɡ�\n");record();
	}
}
void R_add(){
	int i,j,t1,t2,N;
	char NoC[5],NoS[5];
	printf("#################################################\n");
	printf("#                                               #\n"); 
	printf("#                   �������ۼ�¼                #\n");
	printf("#                                               #\n");
	printf("#       �밴 ����Ա��� ��Ʒ��� ��������       #\n");
	printf("#       �ĸ�ʽ�������ۼ�¼                      #\n");
	printf("#                                               #\n");
	printf("#################################################\n");
	printf("������:\n");
	scanf("%s %s %d",NoS,NoC,&N);
	
	FILE *fp;
	int Commodity,tc=-1;
	double temp;
	if ((fp=fopen("Commodity.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		record(); 
	}
	fscanf (fp,"%d",&Commodity);
	struct commodity C[Commodity];
	for (i=0;i<Commodity;i++){
		fscanf(fp,"%s %s %d %lf",C[i].number,C[i].name,&C[i].count,&C[i].prize);
	}
	fclose(fp);
	for (i=0;i<Commodity;i++){
		if ((C[i].number[2]==NoC[2]) && (C[i].number[3]==NoC[3])){
			tc=i;
			if (N>C[i].count){
				printf("���������ڿ���ˣ����������롣\n");
				R_add(); 
			}else {
				C[i].count=C[i].count-N;
				temp=N*C[i].prize;
			}
			break;
		}
	}
	if (tc==-1){
		printf("û���ҵ������Ʒ��...�����������Կ���\n");
		R_add(); 
	}
	fp=fopen("Commodity.txt","w");
	fprintf(fp,"%d",Commodity);
	for(i=0;i<Commodity;i++){
		fprintf(fp,"\n%s %s %d %.1lf",C[i].number,C[i].name,C[i].count,C[i].prize);
	}
	fclose(fp);

	
	int Persons,ts=-1;
	if ((fp=fopen("Salespersons.txt","r"))==NULL){
		cls();
		printf("���������...�ص��ϼ��˵���\n");
		record(); 
	}
	fscanf (fp,"%d",&Persons);
	struct salesperson S[Persons];
	for (i=0;i<Persons;i++){
		fscanf(fp,"%s %s %s %s %lf",S[i].number,S[i].name,S[i].sex,S[i].edu,&S[i].SUM);
	}
	fclose(fp);
	for (i=0;i<Persons;i++){
		if ((S[i].number[2]==NoS[2]) && (S[i].number[3]==NoS[3])){
			S[i].SUM=S[i].SUM+temp;
			ts=i;
		}
	}
	if (ts==-1){
		printf("û���ҵ��������Ա��...�����������Կ���\n");
		R_add(); 
	}
	fp=fopen("Salespersons.txt","w");
	fprintf(fp,"%d",Persons-1);
	for(i=0;i<Persons;i++){
		fprintf(fp,"\n%s %s %s %s %.1lf",S[i].number,S[i].name,S[i].sex,S[i].edu,S[i].SUM);

	}
	fclose(fp);
	
	fp=fopen("Records.txt","a+");
	fprintf(fp,"\n%s %s %d",NoS,NoC,N);
	fclose(fp);
	
	printf("д�����,�����ϼ��˵�\n");
	system("pause");
	cls();
	record(); 
}
