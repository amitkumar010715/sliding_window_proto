
          /**************selective repeat ARQ***************/



#include <bits/stdc++.h>
using namespace std;

typedef struct selective
{
    string ack;
    int data;
} select;
select fram[100];

void resend(int r)   // only one data can be resend 
{
    cout << "resending processing: " << endl;

    _sleep(2);
    fram[r].ack = "yes";
    cout << "now recived frame is: " << fram[r].data << endl;
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

    resend(r);
}

void sender(int n)
{

    cout << "entet data which will be send:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> fram[i].data;
        fram[i].ack = "yes";
    }
    cout << endl;
}

void selective()
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

    cout << "*****************this is selective repeat ARQ*************" << endl;
    selective();
    return 0;
}