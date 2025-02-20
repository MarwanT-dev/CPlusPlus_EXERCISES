#include <iostream>
using namespace std;

int main(){
int n,m;
int arr[100][100]  = {0};
cin>>n>>m;
for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++)
        cin>>arr[i][j];


               //D,R,L,U,upper left ,down right , up right , down left
    int di[8] = {1,0-1,0,-1,1,-1,1};
    int dj[8] = {0,1,0,-1,-1,1,1,-1};

    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
        {
            bool montain = 1;
            for(int d = 0;d<8;d++)
            {
                int ni = i+di[d];//this neighbour i
                int nj = j+dj[d];//this neighbour j

                if(ni<n&&nj<m&&ni>0&&nj>0)
                    if(arr[i][j]<arr[ni][nj])
                    {
                       montain = 0;
                       break;
                    }
            }
            if(montain)
                cout<<i<<' '<<j<<endl;
        }









return 0;

}
