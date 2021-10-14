#include <iostream>
#include <vector>

//using namespace std;


using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::swap;




vector<int> Merge(vector<int> v1, vector<int> v2, bool b)       // parameter "b" reverse order
{
    unsigned long len = v1.size() + v2.size();
    vector<int> vRes(len);
    int it1 = 0;
    int it2 = 0;
    if (b==1){
        for(int i = 0; i < len; ++i){
            if(v1[it1] >= v2[it2]){         // vRes[i] = v1[it1] <= v2[it2]? v1[it1] : v2[it2];
                vRes[i] = v1[it1];          // it1 = v1[it1] <= v2[it2]? it1++ :{};
                it1++;
                if (it1 > (v1.size()-1)){
                    while(v2.size()>=it2){
                        vRes[it1+it2] = v2[it2];
                        it2++;
                    }
                    break;
                }
            }
            else{
                vRes[i] = v2[it2];
                it2++;
                if (it2 > (v2.size()-1)){
                    while(v1.size()>=it1){
                        vRes[it1+it2] = v1[it1];
                        it1++;
                    }
                    break;
                }
            }
        }
    }
    else{
        for(int i = 0; i < len; ++i){
            if(v1[it1] <= v2[it2]){
                vRes[i] = v1[it1];
                it1++;
                if (it1 > (v1.size()-1)){
                    while(v2.size()>=it2){
                        vRes[it1+it2] = v2[it2];
                        it2++;
                    }
                    break;
                }
            }
            else{
                vRes[i] = v2[it2];
                it2++;
                if (it2 > (v2.size()-1)){
                    while(v1.size()>=it1){
                        vRes[it1+it2] = v1[it1];
                        it1++;
                    }
                    break;
                }
            }
        }
    
    }
    return vRes;
}



void VecOut(vector<int> v){
    for (unsigned int i = 0; i < v.size(); ++i){
        cout << v[i] << ' ';
    }
        cout << endl;
}



vector<int> SwapSort(vector<int> v, bool b) //Sorter for 2-element array
{
    if (b==1){
        if ((v.size() == 2) and (v[0] < v[1])){
            swap(v[0], v[1]);
        }
    }
    else{
        if ((v.size() == 2) and (v[0] > v[1])){
            swap(v[0], v[1]);
        }
    }
    return v;
}



vector<int> MergeSort(vector<int> v, bool b) //Main sorting function
{
    vector<int> vRes;
    
    unsigned long half;
    
    if(v.size() == 1){
        return v;
    }
    
    if(v.size() == 2){
        return SwapSort(v, b);
    }
    
    if((v.size() % 2) == 0){
        half = v.size()/2;
    }
    
    else{
        half = v.size()/2 + 1;
    }
    
    vector<int> v1(half);
    for(int i = 0; i < half; ++i){
        v1[i] = v[i];
    }
    
    vector<int> v2(v.size() - half);
    for(int i = 0; i < (v.size() - half); ++i){
        v2[i] = v[i + half];
    }
     
    if(v1.size() > 2 && v2.size() > 2){
        vRes = Merge(MergeSort(v1, b), MergeSort(v2, b), b);
        
    }
    
    else if(v1.size() > 2 && v2.size() <= 2){
        vector<int> v3 = MergeSort(v1, b);
        vRes = Merge(v2, v3, b);
    }
   
    else{
        vRes = Merge(SwapSort(v1, b), SwapSort(v2, b), b);
    }

    return vRes;
}

vector<int> operator*(vector<int> vec, int fac){
    
    /*
    for (unsigned int i = 0; i < vec.size(); ++i){
        vec[i] *= fac;
    }
    */
    
    for (int &i : vec){
        i *= fac;
    }
   
    return vec;
}



    
int main() {
    
    //TASK_№1
    cout << "TASK_№1\n" << endl;
    bool b = 0;
    int len;
    cout << "Enter length of array: ";
    cin >> len;
    cout << "Enter '0' to sort array in ascending order or '1' to sort it reversibly: ";
    cin >> b;
    vector<int> vec(len);
    for(int i = 0; i < len; ++i){
        cout << "Enter [" << i << "] element: ";
        int n;
        cin >> n;
        vec[i] = n;
    }
    vec = MergeSort(vec, b);
    VecOut(vec);
    
    //TASK_№2
    cout << "TASK_№2\n" << endl;
    int fac = 0;
    cout << "Enter factor: ";
    cin >> fac;
    cout << "Resultative vector: ";
    VecOut(vec*fac);
    cout << endl;
    
    //TASK_№3
    cout << "TASK_№3\n" << endl;
    bool par = 0;
    cout << "Enter '0' to sort array, \nEnter '1' to to multiply array by number: ";
    cin >> par;
    /*
    switch(par)
    {
        case 0:
            cout << "Enter length of array: ";
            cin >> len;
            cout << "Enter '0' to sort array in ascending order or '1' to sort it reversibly: ";
            cin >> b;
            vector<int> vec2(len);
            for(int i = 0; i < len; ++i){
                cout << "Enter [" << i << "] element: ";
                int n;
                cin >> n;
                vec2[i] = n;
            }
            VecOut(vec2);
            vec2 = MergeSort(vec2, b);
            cout << "Sorted array: ";
            VecOut(vec2);
            break;
        case 1:
            cout << "Enter length of array: ";
            cin >> len;
            vector<int> vec3(len);
            for(int i = 0; i < len; ++i){
                cout << "Enter [" << i << "] element: ";
                int n;
                cin >> n;
                vec3[i] = n;
            }
            int fac2;
            cout << "Enter factor: ";
            cin >> fac2;
            cout << "Resultative vector: ";
            VecOut(vec3*fac2);
            break;
        default:
            cout<<"! UNKNOWN COMMAND !";
            break;
     }
    */
    
    if (par==1){
        cout << "Enter length of array: ";
        cin >> len;
        vector<int> vec3(len);
        for(int i = 0; i < len; ++i){
            cout << "Enter [" << i << "] element: ";
            int n;
            cin >> n;
            vec3[i] = n;
        }
        int fac2;
        cout << "Enter factor: ";
        cin >> fac2;
        cout << "Resultative vector: ";
        VecOut(vec3*fac2);
    }
    
    else if (par==0){
        cout << "Enter length of array: ";
        cin >> len;
        vector<int> vec2(len);
        for(int i = 0; i < len; ++i){
            cout << "Enter [" << i << "] element: ";
            int n;
            cin >> n;
            vec2[i] = n;
        }
        cout << "Your array: ";
        VecOut(vec2);
        cout << "Enter '0' to sort array in ascending order or '1' to sort it reversibly: ";
        cin >> b;
        vec2 = MergeSort(vec2, b);
        cout << "Sorted array: ";
        VecOut(vec2);
    }
    else{
        cout<<"ERROR: UNKNOWN COMMAND!";
    }
    
    return 0;
}
