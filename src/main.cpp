#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdlib>

int welcomeScreen();
int repeatScreen();
void endScreen();
void helpScreen(bool&);
void MasterCalc();
void MasterCalcWithN(float&,float&,float&,int&);
void MasterNandMasterCalcWithN();
void MasterEOA();
void PreMasterN();
void MasterN(float&,float&,float&,int&);
double RHM(float,float,float,int);
double LHM(float,float,float,int);
double findEOA(float,float,float);
int findN(float,float,float);
int nEval(float);

using namespace std;

int main()
{	int repeatVar=1;
    int mainVar=5;
    bool bypass=false;

    cout<<"\nWelcome To The Calc Estimation Calculator\n";

    while(repeatVar==1)
    {   mainVar=welcomeScreen();
        if(mainVar==1){MasterCalc();}
        if(mainVar==2){MasterEOA();}
        if(mainVar==3){PreMasterN();}
        if(mainVar==4){MasterNandMasterCalcWithN();}
        if(mainVar==5){helpScreen(bypass);}
        if(bypass==false) {repeatVar=repeatScreen();}
        else if(bypass==true) {repeatVar=1;}
    }

    endScreen();

	return (0);
}

int welcomeScreen()
{   cout<<"\nWhat Would You Like To Do? :";
    cout<<"\n\nCalculate RHM & LHM For A Function \t\t\t(Input 1)\n\t-(Requires A & B Bound And N-value Input)";
    cout<<"\n\nCalculate Error of Approximation (EOA) For A Function   (Input 2)\n\t-(Requires A & B Bound And N-value Input)";
    cout<<"\n\nCalculate N-Value For A Function  \t\t\t(Input 3)\n\t-(Requires A & B Bound And EOA Input)";
    cout<<"\n\nCalculate N-Value Then Calculate RHM & LHM \t\t(Input 4)\n\t-(Requires A & B Bound And EOA Input)"<<endl;
    cout<<"\n\n\t\tHelp/About Screen \t(Input 5)"<<endl;
    int welcomeVar;
    cout<<"\nPlease Input Selection: "; cin>>welcomeVar;
    while((welcomeVar!=1)&&(welcomeVar!=2)&&(welcomeVar!=3)&&(welcomeVar!=4)&&(welcomeVar!=5))
    {   cout<<"\nIncorrect Value, Please Insert A 1, 2, 3, 4, or 5 Number: "; cin>>welcomeVar;
    }
    cout<<endl;
    return welcomeVar;
}

int repeatScreen()
{   int temp;
    cout<<"\nWould You Like To Run Another Calculation?\nNote:Choosing No Ends Program (1 for Yes, 2 for No): "; cin>>temp;
    while(temp!=1&&temp!=2)
    {   cout<<"\nIncorrect Value, Please Insert A 1 Or 2: "; cin>>temp;}
    return temp;
}

void helpScreen(bool &bypass)
{   int helpVar=1;
    int selectVar=3;
    while((helpVar==1))
    {   cout<<"\n\n\t\tWelcome To Help!\n\tInput The Numbers Below To Get Help With Each Section.\n\n";
        cout<<"\t1-\tProgram Function/Purpose\n";
        cout<<"\t2-\tUser-Entered Variables\n";
        cout<<"\t3-\tMath Terminology 'Math Speak'\n";
        cout<<"\t4-\tI Don't Need Help/Hit This By Accident\n\n";
        cout<<"\tPlease Input Selection: "; cin>>selectVar; cout<<"\n"<<endl;
        while((selectVar!=1)&&(selectVar!=2)&&(selectVar!=3)&&(selectVar!=4))
        {   cout<<"\nIncorrect Value, Please Insert A 1, 2, Or 3 "; cin>>selectVar; cout<<endl;
        }
        if((selectVar==1))
        {   cout<<"This program was designed to be used for entry-level calculus students \nto perform";
            cout<<" area under the curve estimations of monotone (continious)\nfunctions using both the";
            cout<<" right hand method (RHM) and left hand method (LHM) \nwhich produce the greatest over";
            cout<<" and underestimates and are averaged in \nthis program to give an accurate estimation\n\n";
            cout<<"This program is not designed to help a student cheat to obtain \nbetter scores in what";
            cout<<" should be just a mere couple weeks of introductory\ncalculus that won't be used much";
            cout<<" going forward in the subject, but \nmerely to help in areas where the N-value or EOA";
            cout<<" (see Option 2)\nare too large nor small to do by manual work.\n\n\n";
            cout<<"\n\nStay Or Go Back To Main Screen? (0 - Main, 1 - Stay): "; cin>>helpVar; cout<<endl;
            while((helpVar!=0)&&(helpVar!=1))
            {   cout<<"\n\n\tIncorrect Value. Please Enter A 0 Or 1: "; cin>>helpVar; cout<<endl;
            }
            if(helpVar==0)
            {   selectVar=4;
            }
        }
        else if((selectVar==2))
        {   cout<<"This section explains what variables a user \nof this program might be required to input.\n\n";
            cout<<"A & B bounds-\tThese are the start and end x-axis values for the curve \n\t\tto start and stop.\n\n";
            cout<<"EOA-\t\tError of Approximation measures how off the estimation can \n\t\tbe from the real answer.\n";
            cout<<"    \t\t\tEX: If my EOA is in the hundredth's place (0.0X) \n\t\tI know the tenths place is";
            cout<<" completely accurate and is the \n\t\tcorrect number. Continue ad infinitum.\n\n";
            cout<<"LHM-\t\tLeft Hand Method is a method of approximation that uses the\n\t\tfunction result from the";
            cout<<" input of the left bound of a section\n\t\tto measure the area in that rectangular section.\n\n";
            cout<<"N-value-\tThe N-value is the amount of sections to break the A & B bounds\n\t        up by to estimate";
            cout<<" the area under the curve of the bounds.\n\t        A higher N value is more accurate to the";
            cout<<" actual non-estimated\n\t        value, with a N-value of infinity giving a perfect value.\n";
            cout<<"        \tNOTE: DO -NOT- PUT IN FREAKISHLY LARGE NUMBERS OVER 5000!\n";
            cout<<"        \t      IT IS UNNEEDED AND CAN STRESS OUT YOUR COMPUTER!\n\n";
            cout<<"RHM-\t\tRight Hand Method is a method of approximation that uses the\n\t\tfunction result from the";
            cout<<" input of the right bound of a section\n\t\tto measure the area in that rectangular section.\n\n";
            cout<<"X-value-\tThe X-value is entered indirectly and calculated for you\n\t        automatically when you enter";
            cout<<"the A & B bounds with the N value\n\t        (and sometimes with EOA). It measures the distance";
            cout<<"spanning each\n\t        section. Math terminology: 'delta (greek triangle) x'.\n\n\n";
            cout<<"\n\nStay Or Go Back To Main Screen? (0 - Main, 1 - Stay): "; cin>>helpVar; cout<<endl;
            while((helpVar!=0)&&(helpVar!=1))
            {   cout<<"\n\n\tIncorrect Value. Please Enter A 0 Or 1: "; cin>>helpVar; cout<<endl;
            }
            if(helpVar==0)
            {   selectVar=4;
            }
        }
        else if((selectVar==3))
        {   cout<<"This section defines the more 'mathy'\nway to refer to the parts of the variables.\n\n";
            cout<<"What's Being Solved: The 'Area Problem'\nWhich is the problem of area with curves.\n\n";
            cout<<"What's Being Bounded: Definite Integral\nWhich is a set integral of a curve.\n\n";
            cout<<"What's The X-value: delta x or dx which \nrepresents the change of the x variable.\n\n";
            cout<<"RHM/LHM: Rectangular approximation ways\nthat use Riemann sums to estimate area.\n\n";
            cout<<"Huh? Riemann Sum?: Rectangle summing on\ndefinite integrals to estimate area.\n\n";
            cout<<"\n\nStay Or Go Back To Main Screen? (0 - Main, 1 - Stay): "; cin>>helpVar; cout<<endl;
            while((helpVar!=0)&&(helpVar!=1))
            {   cout<<"\n\n\tIncorrect Value. Please Enter A 0 Or 1: "; cin>>helpVar; cout<<endl;
            }
            if(helpVar==0)
            {   selectVar=4;
            }        }
        if ((selectVar==4))
        {   cout<<"\n\nPlease Wait While You're Returned To The Main Screen"<<endl;
            helpVar=0;
            cout<<"\n\n\n\n"<<endl;
        }
    }
bypass=true;
}

void endScreen()
{   cout<<"\n\n\tThank You For Using!"<<"\n\tPublic Domain. Released 2013\n\n";
}

void MasterCalc()
{   double RHMoutput,LHMoutput,totalAverage;
    float a=0;	float b=0;	float x=0;	int n=0;
    cout<<"Input A bound: "; cin>>a; cout<<endl;
	cout<<"Input B bound: "; cin>>b; cout<<endl;
	cout<<"Input N number: "; cin>>n; cout<<endl;
	while(n<1)
	{   cout<<"\tInvalid Entry. Insert A N-value Of 1 Or Greater: "; cin>>n; cout<<endl;
	}
	x=((b-a)/n);
    RHMoutput=RHM(a,b,x,n);
	LHMoutput=LHM(a,b,x,n);
    totalAverage=((RHMoutput+LHMoutput)/2);
    double distbetween= abs (LHMoutput-RHMoutput);
    cout<<fixed;
	cout<<"LHM estimate: "<<setprecision(5)<<LHMoutput<<endl;
	cout<<"RHM estimate: "<<setprecision(5)<<RHMoutput<<endl;
	cout<<"LHM + RHM average: "<<setprecision(5)<<totalAverage<<endl;
	cout<<"\nDistance Between Estimates: "<<setprecision(5)<<distbetween<<endl;
}

void MasterCalcWithN(float &a,float &b, float &EOA,int &n)
{   double RHMoutput,LHMoutput,totalAverage;
    float x=0;
	x=((b-a)/n);
    RHMoutput=RHM(a,b,x,n);
	LHMoutput=LHM(a,b,x,n);
    totalAverage=((RHMoutput+LHMoutput)/2);
    double distbetween= abs (LHMoutput-RHMoutput);
    cout<<fixed;
	cout<<"LHM estimate: "<<setprecision(7)<<LHMoutput<<endl;
	cout<<"RHM estimate: "<<setprecision(7)<<RHMoutput<<endl;
	cout<<"LHM + RHM average: "<<setprecision(7)<<totalAverage<<endl;
	cout<<"\nDistance Between Estimates: "<<setprecision(7)<<distbetween<<endl;
}

void MasterEOA()
{   float a,b;  int n;
    cout<<"Input A bound: "; cin>>a; cout<<endl;
	cout<<"Input B bound: "; cin>>b; cout<<endl;
    cout<<"Input N number: "; cin>>n; cout<<endl;
    while(n<1)
	{   cout<<"\tInvalid Entry. Insert A N-value Of 1 Or Greater: "; cin>>n; cout<<endl;
	}
    float EOA=findEOA(a,b,n);
    cout<<"\nEOA is: "<<EOA<<endl;
}

void PreMasterN()
{   float a,b,EOA; int n;
    MasterN(a,b,EOA,n);
}

void MasterN(float &a, float &b, float &EOA, int &n)
{   cout<<"Input A bound: "; cin>>a; cout<<endl;
	cout<<"Input B bound: "; cin>>b; cout<<endl;
    cout<<"Input EOA value: "; cin>>EOA; cout<<endl;
    n=findN(a,b,EOA);
    cout<<"\nCalculated N-value: "<<n<<endl;
}

void MasterNandMasterCalcWithN()
{   float a,b,EOA; int n;
    MasterN(a,b,EOA,n);
    cout<<endl;
    MasterCalcWithN(a,b,EOA,n);

}

double LHM(float a,float b, float x,int n)
{	double value=0;
	double tempvalue=0;
	double tempfun=0;

	for(int i=0; i<n; i++)
	{	double z=0;
		z=a+(x*i);
		tempfun=sin(z); //Insert Function Here using variable 'z' for x
		tempvalue=x*tempfun;
		value=tempvalue+value;
	}

	return value;
}

double RHM(float a,float b, float x,int n)
{	double value=0;
	double tempvalue=0;
	double tempfun=0;

	for(int i=1; i<=n; i++)
	{	double z=0;
		z=a+(x*i);
		tempfun=sin(z); //Insert Function Here using variable 'z' for x
		tempvalue=x*tempfun;
		value=tempvalue+value;
	}

	return value;
}

double findEOA(float a,float b,float n)
{   double EOA,p1,p2;
    p1=(b-a)/n;
    p2=abs(/*Insert Function For B*/ sin(b)-sin(a) /*Insert Function For A*/);
    EOA=(p1*p2);
    return EOA;
}

int findN(float a, float b, float EOA)
{   float function; int n;
    function=((b-a)*abs(sin(b)-sin(a)))/EOA;
    n=nEval(function);
    return n;
}

int nEval(float n)
{   int tempN=n;
    int finalN=0;
    if((n>tempN)&&((n-tempN)>0))
    {   finalN=tempN+1;
    }
    if(n<tempN)
    {   finalN=tempN;
    }
    return finalN;
}
