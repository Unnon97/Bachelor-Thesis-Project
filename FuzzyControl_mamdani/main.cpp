#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

string var1names[] = {"VN", "NR", "FR", "VFR"};
string var2names[] = {"LT", "AL", "A", "ART","RT"};
string rulenames[] = {"LT", "AL", "A", "ART","RT"};
string output[] = {"A","ART","AL","AL","A","A","A","RT","A", "A", "A","A","ART","A","A","A","A","A","A","A"};
int outputt[]={2,3,1,1,2,2,2,4,2,2,2,2,3,2,2,2,2,2,2,2};
double area[4],center[4];
double Sumnum=0,Sumden=0;
double OUTPUTVALUE;
struct VarChar
{
	double mname;
	double mvalue;
};


struct rlbase
{
	int var1;
	int var2;
	int orule;
}rb[20];

class CFuzzyFunction
{
	double dLeft, dRight, dMiddle;
	string  sName;

 public:
	CFuzzyFunction(){};
	~CFuzzyFunction(){ }

	void setInterval(double l, double m,double r)	{dLeft=l; dRight=r;dMiddle=m;}

	void setName(string s)
	{
	  // sName = new char[strlen(s)+1];
	  sName = s;
	}

	bool isvalIn(double t)
	{
		if((t>=dLeft)&&(t<=dRight))
			return true;
		else
			return false;
	}

    void getName()
	{
		cout<<sName;
	}


	double getValue(double t)
	{
		if(t<=dLeft)
			return 0;
		else if(t<dMiddle)
			return (t-dLeft)/(dMiddle-dLeft);
		else if(t==dMiddle)
			return 1.0;
		else if(t<dRight)
		    return (dRight-t)/(dRight-dMiddle);
		else
			return 0;
	}

	double getinval()
	{
		return dLeft;
	}

	double getoutval()
	{
		return dRight;
	}
	double getmidval()
	{
		return dMiddle;
	}
};


void rulebase()				//Table storing the rulebaseb
{
	int num=0;
	for(int i =0;i<4;i++)
	{
		for(int j = 0;j<5;j++)
		{
			rb[num].var1 = i;
			rb[num].var2 = j;

			rb[num].orule = num;
			num++;
		}
	}
}

int RBase(int m, int n)
{
    for(int i =0;i<20;i++)
    {
        if((m==rb[i].var1)&&(n==rb[i].var2))
            return rb[i].orule;
        else
            continue;
    }

}


int main(void)
{
	VarChar EChar[4], CEChar[5], VarE[2],VarCE[2];
	CFuzzyFunction *Error[4];
	double EValue, CEValue;
	CFuzzyFunction *OPgraph[5];
	CFuzzyFunction *ChnError[5];
	int j=0;

	for(int l = 0 ; l <4 ; l++)
		Error[l] = new CFuzzyFunction;
	for(int k = 0; k <5; k++)
		ChnError[k] = new CFuzzyFunction;
    for(int m = 0; m <5; m++)
		OPgraph[m] = new CFuzzyFunction;

	cout<<"\nAll intervals for membership of \"Error\" variable: (in,mid,out)";
	double in[4] = {0.1,0.1,0.8,1.5};																////Defining Input1 Range
	double out[4] = {0.8,1.5,2.2,2.2};
	double mid[4] = {0.1,0.8,1.5,2.2};
	for (int i =0;i<4; i++)
		cout<<"\nTriangle Hills : (Var 1) "<<in[i]<<" "<<mid[i]<<" "<<out[i]<<endl;
	for ( int i =0; i < 4 ; i++)
	{
		Error[i]->setInterval(in[i],mid[i],out[i]);
		if(i==0)
			Error[i]->setName("VN");
		else if (i==1)
			Error[i]->setName("NR");
		else if (i==2)
			Error[i]->setName("FR");
        else
            Error[i]->setName("VFR");
	}

	cout<<"\nAll intervals for membership of \"Change in Error\" variable: (in,mid,out)";
	double in2[5] = {-90,-90,-45,0,45};														////Defining Input2 Range
	double out2[5] = {-45,0,45,90,90};
	double mid2[5] = {-90,-45,0,45,90};
	for (int i =0;i<5; i++)
		cout<<"\nTriangle Hills : (Var 2) "<<in2[i]<<" "<<mid2[i]<<" "<<out2[i]<<endl;
	for ( int i =0; i < 5 ; i++)
	{
		ChnError[i]->setInterval(in2[i],mid2[i],out2[i]);
		if(i==0)
			ChnError[i]->setName("LT");
		else if (i==1)
			ChnError[i]->setName("AL");
		else if(i==2)
			ChnError[i]->setName("A");
		else if(i==3)
			ChnError[i]->setName("ART");
        else
			ChnError[i]->setName("RT");

	}

	cout<<"\nAll intervals for membership of \"OUTPUT\" variable: (in,mid,out)";
	double Opin[5] = {-90,-90,-45,0,45};											////Defining output variable range
	double Opout[5] = {-45,0,45,90,90};
	double Opmid[5] = {-90,-45,0,45,90};
	for (int i =0;i<5; i++)
		cout<<"\nTriangle Hills : (Output) "<<Opin[i]<<" "<<Opmid[i]<<" "<<Opout[i]<<endl;
	for (int i =0; i < 5 ; i++)
	{
	    OPgraph[i]->setInterval(Opin[i],Opmid[i],Opout[i]);
        OPgraph[i]->setName(rulenames[i]);
	}

	cout<<"\nInput(Error, Change in Error): "; cin>>EValue>>CEValue;
    for(int i=0; i<4; i++)
	{
		cout<<"\nThe value: "<<EValue;
		if(Error[i]->isvalIn(EValue))
			cout<<" is in the interval ";
		else
			cout<<" is not in the interval ";

        cout<<"of the function: ";
		Error[i]->getName();
		cout<<" with membership: ";
		cout<<Error[i]->getValue(EValue);
		cout<<endl;

	}

	for(int i=0; i<5; i++)
	{
		cout<<"\nThe value: "<<CEValue;
		if(ChnError[i]->isvalIn(CEValue))
			cout<<" is in the interval ";
		else
			cout<<" is not in the interval ";

        cout<<"of the function: ";
		ChnError[i]->getName();
		cout<<" with membership: ";
		cout<<ChnError[i]->getValue(CEValue);
		cout<<endl;

	}

	for( int i =0;i<4; i ++)
	{
		EChar[i].mname = i;
		EChar[i].mvalue = Error[i]->getValue(EValue);
	}
	for( int i =0;i<5; i ++)
	{
		CEChar[i].mname = i;
		CEChar[i].mvalue = ChnError[i]->getValue(CEValue);
	}

/*
	cout<<"\nVariable 1(Error) Fuzzy sets: ";
	for(int i =0;i<4;i++)
	{
		cout<<EChar[i].mname<<" "<<EChar[i].mvalue<<endl;
	}
	cout<<"\nVariable 2(Change in Error) Fuzzy sets: ";
	for(int i =0;i<5;i++)
	{
		cout<<CEChar[i].mname<<" "<<CEChar[i].mvalue<<endl;
	}
*/
	j=0;
	for(int i =0;i<4;i++)
	{
		if(EChar[i].mvalue==0)
			continue;
		else
		{
			VarE[j].mvalue = EChar[i].mvalue;
			VarE[j].mname = EChar[i].mname;
			j++;
		}

	}
	j=0;
	for(int i =0;i<4;i++)
	{
		if(CEChar[i].mvalue==0)
			continue;
		else
		{
			VarCE[j].mvalue = CEChar[i].mvalue;
			VarCE[j].mname = CEChar[i].mname;
			j++;
		}

	}
/*
	cout<<"\nVariable 1  Value Fuzzy sets: ";
	for(int i =0;i<2;i++)
	{
		cout<<VarE[i].mname<<" "<<EChar[i].mvalue<<endl;
	}
	cout<<"\nVariable 2 value Fuzzy sets: ";
	for(int i =0;i<2;i++)
	{
		cout<<VarCE[i].mname<<" "<<VarCE[i].mvalue<<endl;
	}
*/
	int matrix[4][2];

	matrix[0][0]=VarE[0].mname;
	matrix[0][1]=VarCE[0].mname;
	matrix[1][0]=VarE[0].mname;
	matrix[1][1]=VarCE[1].mname;
	matrix[2][0]=VarE[1].mname;
	matrix[2][1]=VarCE[0].mname;
	matrix[3][0]=VarE[1].mname;
	matrix[3][1]=VarCE[1].mname;
/*
	cout<<"\n The Considered: ";
	for(int i =0;i< 4;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	rulebase();

	int calledrule[4];
	for(int i=0;i<4;i++)
    {
        calledrule[i]=RBase(matrix[i][0],matrix[i][1]);
    }

    cout<<"\nCalled Rule: ";
    for(int i=0;i<4;i++)
    {
        cout<<outputt[calledrule[i]]<<" : "<<rulenames[outputt[calledrule[i]]]<<endl;
    }

    double alpha[4];
    int num=0;
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
            alpha[num]=min(VarE[i].mvalue,VarCE[j].mvalue);
            cout<<"\nAlpha "<<num+1<<": "<<alpha[num];
            cout<<"\nAmong "<<VarE[i].mvalue<<" : "<<VarCE[j].mvalue<<endl;
            num++;
        }
    }

    for(int i=0;i<4;i++)                                                                //AREAS of outputs
    {
    	double x0,x1,xm,xbar;
    	double upbase;
    	x0 = OPgraph[outputt[calledrule[i]]]->getinval();
    	x1 = OPgraph[outputt[calledrule[i]]]->getoutval();
    	xm = OPgraph[outputt[calledrule[i]]]->getmidval();
    	area[i]= ((x1-x0)/2)*(2*alpha[i]-pow(alpha[i],2));
    	if(xm==x1)
        {
            upbase=((x1-x0))*(1-alpha[i]);
            xbar = ( pow((x1-x0),2) + pow(upbase,2) + upbase*(x1-x0)) / ( 3*(x1-x0+upbase) );
            center[i]= x1-xbar;
        }
        else if (xm==x0)
        {
            upbase=((x1-x0))*(1-alpha[i]);
            xbar = ( pow((x1-x0),2) + pow(upbase,2) + upbase*(x1-x0)) / ( 3*(x1-x0+upbase) );
            center[i]= x0+xbar;
        }
        else
            center[i] = x0+(x1-x0)/2;
        Sumnum += area[i]*center[i];
        Sumden += area[i];
        cout<<"\nAREAS: "<<area[i];
    	cout<<"\ncenters: "<<center[i]<<endl;
    }

   OUTPUTVALUE = Sumnum/Sumden;

   cout<<"\nModify the value of KP as : "<<OUTPUTVALUE<<endl;
}

