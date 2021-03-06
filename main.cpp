#include <iostream>
#include <vector>
#include <random>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::swap;
using std::ostream;
using std::iostream;


vector<int> Merge(vector<int> v1, vector<int> v2, bool b = 0)       // parameter "b = 1": reverse order
{
    unsigned long len = v1.size() + v2.size();
    vector<int> vRes(len);
    int it1 = 0;
    int it2 = 0;
    if (b==1){
        for(int i = 0; i < len; ++i){
            if(v1[it1] >= v2[it2]){
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

vector<int> SwapSort(vector<int> v, bool b) //Sorter for 2-element array
{
    if (b == 1){
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
        //vector<int> v3 = MergeSort(v1, b);
        //SwapSort(v2, b);
        vRes = Merge(SwapSort(v2, b), MergeSort(v1, b), b);
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
/*
ostream& operator<<(ostream& out, const vector<int>& vec){
    unsigned long size = vec.size();
    out << '{';
    for (size_t i = 0; i < size-1; ++i){
        out << vec[i] << ", ";
    }
    out << vec[size-1] << '}';
    return out;
}
*/
ostream& operator<<(ostream& out, const vector<int>& vec){
    out << '{';
    for (int i : vec){
        out << i << ", ";
    }
    out << '}';
    return out;
}

int main(int argc, char* argv[]) {
    
    //TASK_???1
    std::random_device rd;
    cout << "TASK_???1\n" << endl;
    bool b = 0;
    int len;
    cout << "Enter length of array: ";
    cin >> len;
    cout << "Enter '0' to sort array in ascending order or '1' to sort it reversibly: ";
    cin >> b;
    vector<int> vec(len);
    
    for(int i = 0; i < len; ++i){
        cout << "Enter [" << i << "] element: ";        //fill vector by enter each element
        int n;
        cin >> n;
        vec[i] = n;
    }
    /*
    for(int i = 0; i < len; ++i){       //automative filling vector by random elements
        vec[i] = rd() % 2000 - 1000;
    }
     */
    cout << "Vector: " << vec << endl;
    vec = MergeSort(vec, b);
    cout << "Sorted vector: " << vec << endl;
    
    //Examination for MergeSort function
    //(shows is function "MergeSort" working correct,
    //by compairing it with result of working function "std::sort")
    
    vector<int> vecs(vec.begin(), vec.end());
    std::sort(vecs.begin(), vecs.end());
    bool c = 1;
    bool &a = c;
    for (unsigned long i = 0; i < vecs.size(); ++i){
        if (b == 0){
            if (vecs[i] != vec[i]){
                cout << "Examination failed: Merge sort is uncorrect from " << i+1 << " element!" << endl;
                a = 0;
                break;
            }
        }
        else{
            if (vecs[vecs.size() - i - 1] != vec[i]){
                cout << "Examination failed: Merge sort is uncorrect from " << i+1 << " element!" << endl;
                a = 0;
                break;
            }
        }
    }
        if (a == 1){
            cout << "Examination finished successfully: Merge sort is correct!" << endl;
        }
    
    //TASK_???2
    cout << "\nTASK_???2\n" << endl;
    int fac = 0;
    cout << "Enter factor: ";
    cin >> fac;
    cout << "Resultative vector: " << vec*fac;
    cout << endl;
    
    //TASK_???3
    cout << "\nTASK_???3\n" << endl;
    if (*argv[0] == 1){
        cout << "Enter length of array: ";
        cin >> len;
        vector<int> vec3(len);
        /*
        for(int i = 0; i < len; ++i){
            cout << "Enter [" << i << "] element: ";
            int n;
            cin >> n;
            vec3[i] = n;
        }
         */
        for(int i = 0; i < len; ++i){
            vec3[i] = rd() % 2000 - 1000;
        }
        cout << "vector: " << endl;
        cout << vec3 << endl;
        int fac2;
        cout << "Enter factor: ";
        cin >> fac2;
        cout << "Resultative vector: ";
        cout << vec3*fac2 << endl;
    }
    
    else if (*argv[0] == 0){
        cout << "Enter length of array: ";
        cin >> len;
        vector<int> vec2(len);
        for(int i = 0; i < len; ++i){
            vec2[i] = rd() % 2000 - 1000;
        }
        cout << "Your array: " << vec2 << endl;
        cout << "Enter '0' to sort array in ascending order or '1' to sort it reversibly: ";
        cin >> b;
        vec2 = MergeSort(vec2, b);
        cout << "Sorted array: " << vec2 << endl;
    }
    return 0;
}
