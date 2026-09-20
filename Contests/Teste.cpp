#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,resp=0,cont=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int aux;
        cin>>aux;
        if(aux==1){
            resp++;
            cont++;
            if(cont>=3) resp++;
        }
        else{
            resp--;
            cont=0;
        }
    }
    cout<<resp<<endl;
    return 0;
}


