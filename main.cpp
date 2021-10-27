#include <iostream>
#include <string>

using namespace std;

void Out_Rez(string choice, double Y, double S, double YS);

int main() {
  string choice;
  
  cout << "Choose what function's result you want to see: 'Y', 'S' or 'YS'" << endl;
  getline(cin, choice);
  if (choice != "Y" && choice != "S" && choice != "YS") {
    cout << "Error: you've chosen incorrect value for function's result. Exiting the program...";
    return 1;
  }
  
  int n;
  double a, b, h, ak, S, Y;

  cout << "Enter a,b,h,n:\n";

  cout << "a=", cin >> a;
  cout << "b=", cin >> b;
  cout << "h=", cin >> h;
  cout << "n=", cin >> n;

  cout <<" x     Y(x)       S(x)       |Y(x)-S(x)|\n";
  for (double x=a; x<=b+h/2.; x+=h)
  {
    ak=x; S=x; Y=sin(x);
    for (int k=1; k<=n; k++)
    {
      ak*=-x*x/(2*k*(2*k+1));
      S+=ak;
    }
  }

  Out_Rez(choice, Y, S, fabs(Y-S));

  return 0;
}


void Out_Rez(string choice, double Y, double S, double YS) {
  double result;

  if (choice == "Y") {
    result = Y;
  } else if (choice == "S") {
    result = S;
  } else if (choice == "YS") {
    result = YS;
  } else {
    result = -123456789;
  }

  cout << choice << ": " << result;
}