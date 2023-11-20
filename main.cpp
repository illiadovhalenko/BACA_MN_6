//Illia Dovhalenko
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int N, M, L;
    cin>>N>>M;
    int a;
    auto tab=new vector<double>[M+1];
    double y[N], x[N];
    double w;
    for(int i=0; i<=M; i++){
        for(int j=0; j<N-M+i; j++) {
            cin>>a;
            tab[i].push_back(a);
        }
    }
    for(int i=0; i<N; i++)
        cin>>y[i];
    for(int i=0; i<N; i++)
        cin>>x[i];
    cin>>w>>L;
    for(int iter=0; iter<L; iter++){
        for(int i=0; i<N; i++) {
            auto s = y[i];
            for(int m=0; m<M; m++){
                if(i-M+m>=0)
                s-=tab[m][i-M+m]*x[i-M+m];
            }
            for(int m=0; m<M; m++){
                if(i+m+1<N)
                    s-=tab[M-1-m][i]*x[i+m+1];
            }
            x[i]=(1-w) * x[i] + w* s / tab[M][i];
        }
    }
    cout<<setprecision(15);
    for(int i=0;i<N; i++){
        cout<<x[i]<<endl;
    }
    delete[] tab;
    return 0;
}
