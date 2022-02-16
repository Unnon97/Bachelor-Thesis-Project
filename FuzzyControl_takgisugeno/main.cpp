#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

string var1names[] = {"LW", "M", "H"};
string var2names[] = {"NR", "FR", "VFR"};

struct VarChar
{
	double mname;
	double mvalue;
};


class CFuzzyFunction
{
	double dLeft, dRight, dMiddle;
	string  sName;

 public:
	CFuzzyFunction(){};
	~CFuzzyFunction(){ }

	void setInterval(double l, double r)	{dLeft=l; dRight=r;}

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



	void setMiddle(double m)
	{
		dMiddle=m;
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


int main(void)
{
	VarChar EChar[3], CEChar[3], VarE[2],VarCE[2];
	CFuzzyFunction *Error[3];
	double EValue, CEValue;
	CFuzzyFunction *ChnError[3];
	int j=0;

	for(int l = 0 ; l <3 ; l++)
		Error[l] = new CFuzzyFunction;
	for(int k = 0; k <3; k++)
		ChnError[k] = new CFuzzyFunction;


	cout<<"\nAll intervals for membership of \"Error\" variable: (in,mid,out)";
	double in[3] = {5.0,5.0,10.0};																////Defining Input1 Range
	double out[3] = {10.0,15.0,15.0};
	double mid[3] = {5.0,10.0,15.0};
	for (int i =0;i<3; i++)
		cout<<"\nTriangle Hills : (Var 1) "<<in[i]<<" "<<mid[i]<<" "<<out[i]<<endl;
	for ( int i =0; i < 3 ; i++)
	{
		Error[i]->setInterval(in[i],out[i]);
		Error[i]->setMiddle(mid[i]);
		if(i==0)
			Error[i]->setName("LW");
		else if (i==1)
			Error[i]->setName("M");
		else
			Error[i]->setName("H");

	}

	cout<<"\nAll intervals for membership of \"Change in Error\" variable: (in,mid,out)";
	double in2[3] = {1.0,1.0,2.0};														////Defining Input2 Range
	double out2[3] = {2.0,3.0,3.0};
	double mid2[3] = {1.0,2.0,3.0};
	for (int i =0;i<3; i++)
		cout<<"\nTriangle Hills : (Var 2) "<<in2[i]<<" "<<mid2[i]<<" "<<out2[i]<<endl;
	for ( int i =0; i < 3 ; i++)
	{
		ChnError[i]->setInterval(in2[i],out2[i]);
		ChnError[i]->setMiddle(mid2[i]);
		if(i==0)
			ChnError[i]->setName("NR");
		else if (i==1)
			ChnError[i]->setName("FR");
		else
			ChnError[i]->setName("VFR");

	}

	cout<<"\nInput(Error, Change in Error): "; cin>>EValue>>CEValue;
    for(int i=0; i<3; i++)
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

	for(int i=0; i<3; i++)
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

	for( int i =0;i<3; i ++)
	{
		EChar[i].mname = i;
		EChar[i].mvalue = Error[i]->getValue(EValue);
	}
	for( int i =0;i<3; i ++)
	{
		CEChar[i].mname = i;
		CEChar[i].mvalue = ChnError[i]->getValue(CEValue);
	}
/*
	cout<<"\nVariable 1(Error) Fuzzy sets: ";
	for(int i =0;i<3;i++)
	{
		cout<<EChar[i].mname<<" "<<EChar[i].mvalue<<endl;
	}
	cout<<"\nVariable 2(Change in Error) Fuzzy sets: ";
	for(int i =0;i<3;i++)
	{
		cout<<CEChar[i].mname<<" "<<CEChar[i].mvalue<<endl;
	}
*/
	j=0;
	for(int i =0;i<3;i++)
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
	for(int i =0;i<3;i++)
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
	cout<<"\nVariable 1  Called Fuzzy sets: ";
	for(int i =0;i<2;i++)
	{
		cout<<VarE[i].mname<<" "<<EChar[i].mvalue<<endl;
	}
	cout<<"\nVariable 2 Called Fuzzy sets: ";
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
	cout<<"\n The Considered: ";                            //Considered pair of terms
	for(int i =0;i<4;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
*/
    double weights[] = {1,1,1,1};
    int num=0;
    for(int i =0;i<2;i++)
    {
        for(int j=0;j<2;j++)
        {
          weights[num] *= VarE[i].mvalue * VarCE[j].mvalue;
          num++;
        }
    }

	double y[4];
	int a[sizeof(var1names)];
	int b[sizeof(var2names)];
	for(int i=0;i<sizeof(var1names);i++)
    {
        a[i]=i+1;
    }
    for(int i=0;i<sizeof(var2names);i++)
    {
        b[i]=i+1;
    }
	for(int i=0;i<4;i++)
    {
        y[i] = (a[matrix[i][0]]*EValue)+(b[matrix[i][1]]*CEValue);

    }
    for(int i =0;i<4;i++)
	{
		cout<<"\nWeights: "<<weights[i];
		cout<<"\nY: "<<y[i]<<endl;
	}
    double sumnum=0,sumden=0;
    for(int i =0;i<4;i++)
    {
        sumnum += (weights[i]*y[i]);
        sumden += (weights[i]);
    }
    double Result;

    Result = sumnum/sumden;

    cout<<"\nOutput Y of controller is: "<<Result<<endl;

}

