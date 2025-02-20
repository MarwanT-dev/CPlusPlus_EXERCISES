#include <iostream>
#include<cstring>
using namespace std;

bool diagonal(int idx ,int n, int(&arr)[82]){
    int cnt= 0;
    int temp = idx;
    for(int i=0;i<n-1;i++){
        if(arr[idx]==arr[idx+n+1]&&arr[idx]!=-1)
            cnt++;

        idx+=(n+1);
    }

    if(cnt==n-1)
        return 1;
    cnt = 0 ,idx = temp;

    for(int i=0;i<2;i++){
        if(arr[idx]==arr[idx+n-1]&&arr[idx]!=-1)
            cnt++;

        idx+=(n-1);
    }

    if(cnt==n-1)
        return 1;
    return 0;

}

bool side(int idx,int n , int (&arr)[82]){
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(arr[idx]==arr[idx+1]&&arr[idx]!=-1)
            cnt++;
        idx++;
    }

    if(cnt==n-1)
        return 1;
    return 0;

}

bool down(int idx,int n , int (&arr)[82]){
    int cnt = 0;
    for(int i=0;i<n-1;i++){
        if(arr[idx]==arr[idx+n]&&arr[idx]!=-1)
            cnt++;
        idx+=n;
    }

    if(cnt==n-1)
        return 1;
    return 0;

}


int transform_idx(int n , int r ,int c){
    return (r-1)*n+(c-1);
}

void print_mat(int n , int (&arr)[82]){
    for(int i =1;i<=n*n;i++){
        if(arr[i-1]==0)
            cout<<'X'<<' ';
        else if(arr[i-1]==1)
            cout<<'O'<<' ';
        else
            cout<<'.'<<' ';
        if(i%n==0)
            cout<<endl;
    }

}
int main(){
    int arr[82];
    memset(arr,-1,82);

    int N;cin>>N;

    int actual_size = 0;
    int turn = 1;
    bool stop = 0;
    while(!stop){
        int r,c,idx;
        if(turn ==1){//player O
            cout<<"Player O turn. Enter empty location (r,c): ";
            cin>>r>>c;
            idx = transform_idx(N,r,c);

            if(idx>N*N||arr[idx]!=-1){
                cout<<"try again "<<endl;
                turn*=-1;
            }
            else{
                arr[idx] = 1;
                for(int i=0;i<N*N;i++){
                    if(diagonal(i,N,arr)||down(i,N,arr)||side(i,N,arr)){
                        cout<<"Player O WON!!"<<endl;
                        stop =1;
                        break;
                    }
                }
            }
        }

        else{
            cout<<"Player X turn< Enter empty location (r,c): ";
            cin>>r>>c;
            idx = transform_idx(N,r,c);
            if(idx>N*N||arr[idx]!=-1){
                cout<<"try again "<<endl;
                turn*=-1;
            }
            else{
                arr[idx] = 0;
                for(int i=0;i<N*N;i++){
                    if(diagonal(i,N,arr)||down(i,N,arr)||side(i,N,arr)){
                        cout<<"Player X WON!!"<<endl;
                        stop =1;
                        break;
                    }
                }
            }

        }
        print_mat(N,arr);
        turn*=-1;
    }

return 0;
}
