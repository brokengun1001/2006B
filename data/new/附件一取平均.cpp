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
	int CD4Date,CD4Count,HIVDate,
	CD4CountSum0=0,CD4CountSum4=0,CD4CountSum8=0,CD4CountSum24=0,CD4CountSum40=0,CD4CountSum50=0;
	double HIVCount,HIVCountSum0=0,HIVCountSum4=0,HIVCountSum8=0,HIVCountSum24=0,HIVCountSum40=40,HIVCountSum50=0;
	ifstream file;
	file.open("附件1数据（CD4大于300）.txt");
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
		if(CD4Date>=0&&CD4Date<=2){CD4CountSum0+=CD4Count;HIVCountSum0+=HIVCount;}
		if(CD4Date>=3&&CD4Date<=6){CD4CountSum4+=CD4Count;HIVCountSum4+=HIVCount;}
		if(CD4Date>=7&&CD4Date<=16){CD4CountSum8+=CD4Count;HIVCountSum8+=HIVCount;}
		if(CD4Date>=17&&CD4Date<=32){CD4CountSum24+=CD4Count;HIVCountSum24+=HIVCount;} 
		if(CD4Date>=33&&CD4Date<=45){CD4CountSum40+=CD4Count;HIVCountSum40+=HIVCount;} 
		if(CD4Date>=46){CD4CountSum50+=CD4Count;HIVCountSum50+=HIVCount;} 
		pt[n].setID(PresID);
		pt[n].setCD4date(i,CD4Date);
		pt[n].setCD4(i,CD4Count);
		pt[n].setHIVdate(i,HIVDate);
		pt[n].setHIV(i,HIVCount);
		cout<<pt[n].getID()<<"\t"<<pt[n].getCD4date(i)<<"\t"<<pt[n].getCD4(i)<<"\t"<<"\t"<<pt[n].getHIVdate(i)<<"\t"<<pt[n].getHIV(i)<<endl;
		i++;
	}
	file.close();

	int m=0,n1=0,n2=0,n3=0,n4=0,a=0;
    ofstream fp;
    fp.open("附件1数据（CD4大于300取平均）.txt");
    
    for(int i = 0;i < num;i++){
    if(pt[i].getID()){
		a++;
		if(pt[i].getTime()<2){
			m++;
			continue;
		}
		if(pt[i].getCD4(0)>=300){n1++;continue;}
		if(pt[i].getCD4(0)<300&&pt[i].getCD4(0)>=200){n2++;continue;}
		if(pt[i].getCD4(0)<200&&pt[i].getCD4(0)>=100){n3++;continue;}
		if(pt[i].getCD4(0)<100){n4++;}
//		for(int j = 0;j<=pt[i].getTime();j++){
//			fp<<pt[i].getID()<<"\t"<<pt[i].getCD4date(j)<<"\t"<<pt[i].getCD4(j)<<"\t"<<
//			pt[i].getHIVdate(j)<<"\t"<<pt[i].getHIV(j)<<endl;
//		}
	}
    }
    cout<<"共有"<<a<<"个病人CD4小于100"<<endl;
	fp<<0<<"\t"<<CD4CountSum0/a<<"\t"<<0<<"\t"<<HIVCountSum0/a<<endl;
	fp<<4<<"\t"<<CD4CountSum4/a<<"\t"<<4<<"\t"<<HIVCountSum4/a<<endl;
	fp<<8<<"\t"<<CD4CountSum8/a<<"\t"<<8<<"\t"<<HIVCountSum8/a<<endl;
	fp<<24<<"\t"<<CD4CountSum24/a<<"\t"<<24<<"\t"<<HIVCountSum24/a<<endl;
	fp<<40<<"\t"<<CD4CountSum40/a<<"\t"<<40<<"\t"<<HIVCountSum40/a<<endl;
//	fp<<50<<"\t"<<CD4CountSum50/a<<"\t"<<50<<"\t"<<HIVCountSum50/a<<endl;
    fp.close();
	return 0;
}
