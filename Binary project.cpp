#include<iostream>
using namespace std;

class Binary
{
  int data[1000];
  int num ;

  public:

  Binary(int n)
  {
    num = 0;
    while(n != 0)
    {
        data[num] = n%2;
        n = n /2;
        num++;
    }
  }

  void get_data()
  {
    cout<<"Enter number of digits: ";
    cin>>num;
    
    for(int i=0 ; i<num ; i++)
    {
        cin>>data[i];
    }
  }

  int* fst_complement()
  {
    for(int i=0 ; i<num ; i++)
    {
        if(data[i] == 0)
        data[i] = 1;

        else if(data[i] == 1)
        data[i] = 0;
    }

    return data;
  }

 int to_dicimal()
  {
    int dec = 0;
    int pow = 1;
    for(int i=0 ; i<num ; i++)
    {
      dec = dec+ data[i]*pow;
      pow *= 2;
    }
    //cout<<"Decimal: "<<dec<<endl;
    return dec;
  }

  void to_octal()
  {
    int oct = 0;
   
    int i =0;
    while(i < num)
    { 
      int val = 0;

      if(i<num)
      val = val + data[i]*1;

      if(i+1 < num)
      val = val + data[i+1]*2;

      if(i+2 < num)
      val = val + data[i+2]*4;

      oct = (oct*10) + val;

      i += 3;
    }
    cout<<"Octal: "<<oct<<endl;
  }

  bool operator >(Binary b)
  {
    int dec1 = to_dicimal();
    int dec2 = b.to_dicimal();

    if(dec1 > dec2)
    return true;
    else
    return false;
  }


  void print()
  {
    for(int i=num-1 ; i>=0 ; i--)
    {
      cout<<data[i];
    }
    cout<<endl;
  }




};

int main()
{
  Binary bn1(425) , bn2(5526) , bn3(63);
  
  bn1.print();
  bn1.fst_complement();
  bn1.print();

  bn2.to_octal();

  cout<<"Decimal for bn3: " <<bn3.to_dicimal()<<endl;

  if(bn1 > bn3)
  cout<<"The first binary is greater than the second\n";
  else if(!(bn1 > bn3))
  cout<<"The first binary is less than the second\n";

    

}