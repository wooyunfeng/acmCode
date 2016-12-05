#include <iostream>
#include <cstring>
#include <cstring>
using namespace std;
const int maxn=1000+5;
char s[maxn],p[maxn];
int lens,lenp;
int Next[maxn];
void getNext()
{
    int i=0,j=-1;
    Next[0]=-1;
    while(i<lenp)
    {
        if(j==-1||p[i]==p[j])
        {
            i++,j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}
int KMP()
{
    int i=0,j=0;
    int cnt=0;
    while(i<lens)
    {
        if(j==-1||s[i]==p[j])
        {
            i++,j++;
        }
        else
            j=Next[j];
        if(j==lenp)
        {
            cnt++;
            j=0;
        }
    }
    return cnt;
}
int main()
{
    while(cin>>s)
    {
        if(s[0]=='#') break;
        cin>>p;
        lens=strlen(s);
        lenp=strlen(p);
        getNext();
        cout<<KMP()<<endl;
    }
    return 0;
}
