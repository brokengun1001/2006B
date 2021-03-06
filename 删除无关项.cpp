#include<iostream>
#include<fstream>
using namespace std;
#define E 100000

class patient{
	public:
		patient(){};
		void setID(int id){
			ID = id;
		}
		void setCD4date(int i,int n){
			CD4date[i] = n;
		}
		void setHIVdate(int i,int n){
			HIVdate[i] = n;
		}
		void setCD4(int i,int n){
			CD4[i] = n;
		}
		void setHIV(int i,double n){
			HIV[i] = n;
		}
		int getCD4date(int i){
			return CD4date[i];
		}
		int getCD4(int i){
			return CD4[i];
		}
		double getHIV(int i){
			return HIV[i];
		}
		int getHIVdate(int i){
			return HIVdate[i];
		}
		int getID(){
			return ID;
		}
		void setTime(int t){
			time = t;
		}
		int getTime(){
			return time;
		}
		~patient(){};
	private:
		int ID;
		int CD4date[8];
		int CD4[8];
		int HIVdate[8];
		double HIV[8];
		int time;
};

int main(){
	patient pt[10000];
	int PresID,n = 0,i = 0,num = 0;;
	char c;
	int CD4Date,CD4Count,HIVDate;
	double HIVCount;
	ifstream file;
	file.open("data//1.txt");
	while(!file.eof()){
		file>>PresID;
		if(PresID != pt[n].getID()){
			pt[n].setTime(i-1);
			pt[n].setCD4(i,E);
			pt[n].setCD4date(i,E);
			pt[n].setHIV(i,E);
			pt[n].setHIVdate(i,E);
			n++;
			num+=(i-1);
			i = 0;
		}
//		file.get(c);
//		if(c=='\n')break;
		file>>CD4Date;
//		file.get(c);
//		if(c=='\n')break;
		file>>CD4Count;
//		file.get(c);
//		if(c=='\n')break;
		file>>HIVDate;
//		file.get(c);
//		if(c=='\n')break;
		file>>HIVCount;
		pt[n].setID(PresID);
		pt[n].setCD4date(i,CD4Date);
		pt[n].setCD4(i,CD4Count);
		pt[n].setHIVdate(i,HIVDate);
		pt[n].setHIV(i,HIVCount);
		cout<<pt[n].getID()<<"\t"<<pt[n].getCD4date(i)<<"\t"<<pt[n].getCD4(i)<<"\t"<<"\t"<<pt[n].getHIVdate(i)<<"\t"<<pt[n].getHIV(i)<<endl;
		i++;
	}
	file.close();

	int m=0,n1=0,n2=0,n3=0,n4=0,a=0,
		x1=0,x2=0,x3=0,x4=0;
    ofstream fp;
    fp.open("data//new//附件1数据（CD4大于300）.txt");
    for(int i = 0;i < num;i++){
    if(pt[i].getID()){
		a++;
		if(pt[i].getTime()<2){
			m++;
			continue;
		}
		if(pt[i].getCD4(0)>=300){n1++;}
		if(pt[i].getCD4(0)<300&&pt[i].getCD4(0)>=200){n2++;continue;}
		if(pt[i].getCD4(0)<200&&pt[i].getCD4(0)>=100){n3++;continue;}
		if(pt[i].getCD4(0)<100){n4++;continue;}
		for(int j = 0;j<=pt[i].getTime();j++){
			fp<<pt[i].getID()<<"\t"<<pt[i].getCD4date(j)<<"\t"<<pt[i].getCD4(j)<<"\t"<<
			pt[i].getHIVdate(j)<<"\t"<<pt[i].getHIV(j)<<endl;
		}
	}
    }
    fp.close();
	return 0;
}
