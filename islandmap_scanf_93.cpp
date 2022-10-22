#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int num=m*n/80;
    string bit;
    vector<int> imap(n*m);
    char* fin="-1";
    int p;

    for(int i=0;i<2+num;i++){
        if(n*m>80) p=80;
        else p=n*m;
        char tmp[p];
        scanf("%s", tmp);
        if(!strcmp(tmp, fin)) break;
        bit+=tmp;
    }
    for(int i=0;i<bit.size();i++){
        int tmp;
        tmp = bit[i];
        if(bit[i]=='\n' || bit[i]=='\0'){
            continue;
        }
        imap[i]=tmp-'0';
    }
    if(m<=2){
        cout << 0;
    }
    else{
    imap[0]=imap[m-1]=imap[m*(n-1)]=imap[n*m-1]=9;
    for(int i=1; i<m-1;i++){
        for(int j=0;j<m;j++){
            if(imap[i+(m*j)]==0 || imap[i+(m*j)]==9){
                imap[i+(m*j)]=9;
            }
            else break;
        }
        for(int t=m-1;t>0;t--){
            if(imap[i+(m*t)]==0 || imap[i+(m*t)]==9){
                imap[i+(m*t)]=9;
            }
            else break;
        }
        for(int l=0;l<m;l++){
            if(imap[m*i+l]==0 || imap[m*i+l]==9){
                imap[m*i+l]=9;
            }
            else break;
        }
        for(int r=0;r<m;r++){
            if(imap[m*(m-i)-1-r]==0 || imap[m*(m-i)-1-r]==9){
                imap[m*(m-i)-1-r]=9;
            }
            else break;
        }
    }
    bool change=true;
    while(change){
        change=false;
        for(int i=1+m;i<n*(m-1);i++) {
            if(imap[i]==9){
                if(imap[i+1]==0) {
                    imap[i+1]=9;
                    change=true;
                }
                if(imap[i-1]==0) {
                    imap[i-1]=9;
                    change=true;
                }
                if(imap[i+m]==0) {
                    imap[i+m]=9;
                    change=true;
                }
                if(imap[i-m]==0) {
                    imap[i-m]=9;
                    change=true;
                }
            }
        }
    }
    int o_cnt=0;
    for(int i=0;i<n*m;i++) {
        if(imap[i]==9) o_cnt++;
    }
    cout << n*m-o_cnt;
    }
    return 0;
}
