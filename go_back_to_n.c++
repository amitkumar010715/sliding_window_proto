
                       /*go back to n*/

#include <bits/stdc++.h>
using namespace std;

typedef struct goback
{
    string ack;
    int data;
} go;
go fram[100];

void resend(int r,int n)   // resend all frame from where ack drop
{
    cout << "resending processing: " << endl;
  for (int i = r; i <=n; i++)
  {
      
 _sleep(2);
    fram[r].ack = "yes";
    cout << "now recived frame is: " << fram[i].data << endl;
  }
  
   
}

void receive_Ack(int n)
{
    rand();
    int r = rand() % n;
    fram[r].ack = "no";
    for (int i = 1; i <= n; i++)
    {
        if (fram[i].ack == "no")
        {
            cout << "frame number: " << r << " has not received." << endl;
        }
    }

    resend(r,n);
}

void sender(int n)
{

    cout << "entet data which will be send:" << endl;
    for (int i = 1; i <=n; i++)
    {
        cin >> fram[i].data;
        fram[i].ack = "yes";
    }
    cout << endl;
}

void go_back()
{
    int n;
    cout << "enter the number of frame to be send:";
    cin >> n;
    cout << endl;
    sender(n);

    receive_Ack(n);
}

int main(int argc, char const *argv[])
{

    cout << "*****************this is goback to N ARQ*************" << endl;
    go_back();
    return 0;
}