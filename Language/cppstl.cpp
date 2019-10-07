#include<vector>
#include<algorithm>

bool f(int x,int y)
{
    return x>y;

}


using namespace std;

int main()
{

    vector <int> A={12,3,4,15};
    cout<<A[1]<<endl;

    sort(A.begin(),A.end());

    bool present=binary_search(A.begin(),A.end(),3);
    present=binary_search(A.begin(),A.end(),5);
    A.push_back(100);
    present=binary_search(A.begin(),A.end(),100);

    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
      A.push_back(123);



      vector<int>::iterator it=lower_bound(A.begin(),A.end(),100);
        vector<int>::iterator it2=upper_bound(A.begin(),A.end(),100);
    cout<<*it<<" "<<*it2<<endl;
     cout<<it2-it<<endl;

     sort(A.begin(),A.end(),f);
     vector<int>::iterator it3;
     for(it3=A.begin(); it3!=A.end();it3++)
     {

         cout<<*it3<<endl;

     }
    for(int &x:A)
     {
        x++;
        // cout<<x<<" ";
     }

     for(int x:A)
     {

         cout<<x<<" ";
     }
     cout<<endl;

     return 0;
}
