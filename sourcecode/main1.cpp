
#include "sinhtest1.h"
#include "sort1.h"
 ll a[N];
vector<double> ketqua(void(*ff)(ll arr[], int l, int r)){
    fstream fi;
    vector<double> kq; 
    for(int i=1;i<=10;i++){
        fi.open("C:\\Users\\Dell\\Desktop\\data\\test"+to_string(i)+".txt",ios::in);
        for(int j=0;j<N;j++)
            fi >>a[j];
        clock_t start,en; 
        start=clock();
        ff(a,0,N-1);
        en=clock();
        kq.push_back(1000.0*(en-start)/CLOCKS_PER_SEC);
    }
    return kq; 
}
int main (){
    gene();
    vector<vector<double> >kq(4);
    kq[0]=ketqua(SortCpp);
    kq[1]=ketqua(QuickSort);
    kq[2]=ketqua(MergeSort);
    kq[3]=ketqua(HeapSort);
    cout<<"       Ket qua so sanh cac thuat toan sap xep          \n";
    vector<string> s{"SortCpp","QuickSort","MergeSort","HeapSort"};
    for(int i=0;i<4;i++){
        cout<<s[i]<<": ";
        for(auto x:kq[i])   cout<<x<<' ';
        cout<<'\n';
    }
    return 0;
}
