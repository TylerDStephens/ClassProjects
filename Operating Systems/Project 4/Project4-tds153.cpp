//https://solver.assistedcoding.eu/page_replacement, used as a reference to what the Algoritm should be outputting
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <deque>
#include <algorithm>
//#include <vector>
using namespace std;
bool sortcol(const deque<int>& v1, const deque<int>& v2)
{
    return v1[1] < v2[1];
}
void optimalReplacement(int pages[], int Frames){
    deque<int> f;
    deque<deque<int>> temp( Frames, deque<int> (2));
    for(int i = 0; i < Frames; i++){
        f.push_front(pages[i]);
    }
    int hit = 0;
    int miss = Frames;
    int m = 0, h = 0;
    cout << "OPTIMAL ALGORITHM PROCESSING: " << endl;
    cout << f[0] << " " << f[1] << " " << f[2] << endl;
    ///Assinged numbers to the frame array that can't be in the rand string.
    for (int i = Frames; i < 20; ++i){
        for(int j = 0; j < Frames; j++){
            if(f[j] != pages[i]){
                m = m + 1;
            }
        }
        if(m == Frames){
            ///Goal is to find the Frame that has the longest wait till its next use.
            m=0;miss++;
            for(int n = 0; n < Frames; n++){
                temp[n][0] = f[n];
                temp[n][1] = 0;
                bool check = false;
                for(int k = i; k < 20; k++) {
                    if(f[n] == pages[k] && check == false ){
                        temp[n][1] = k;
                        check = true;
                    }
                    if(check == false){
                        temp[n][1] = k;
                    }
                }
            }
            sort(temp.begin(), temp.end(), sortcol);
            for(int i = 0; i < Frames; i++){
                f[i] = temp[i][0];
            }
            f.pop_back();
            f.push_front(pages[i]);
            sort(f.begin(), f.end());
        }

        else{
            m = 0;
            hit++;
        }
        cout << f[0] << " " << f[1] << " " << f[2] << endl;
    }
    cout << "Optimal Replacement Program Results:" << endl;
    for(int z = 0; z < Frames; ++z){
        cout << f[z] << " ";
    }cout << endl;
    double hrate = (hit*100)/20, mrate = (miss*100)/20;
    cout << "Number of hits: " << hit << endl << "Hit Rate: " << hrate << "%" << endl;
    cout << "Number of misses: " << miss << endl << "Miss Rate: " << mrate << "%" << endl;
}
void LRU_Replacement(int pages[], int Frames){
    deque<int> f;
    for(int i = 0; i < Frames; i++){
        f.push_front(pages[i]);
    }
    int hit = 0;
    int miss = 3;
    int m = 0, h = 0;
    cout << "LRU ALGORITHM PROCESSING: " << endl;
    cout << f[0] << " " << f[1] << " " << f[2] << endl;
    for (int j = Frames; j < 20; ++j){
        for(int k = 0; k < Frames; k++){
            if(f[k] != pages[j]){
                m = m + 1;
            }
            else
                h = k;
        }
        if(m == Frames){
            f.push_front(pages[j]);
            miss = miss + 1;
            m = 0;
            h = 0;
        }
        else{
            deque<int>::iterator it;
            it = f.begin()+h;
            f.push_front(pages[j]);
            f.erase(it);
            hit = hit + 1;
            h = 0;
            m = 0;
        }
        cout << f[0] << " " << f[1] << " " << f[2] << endl;
     }
    cout << "LRU Replacement Program:" << endl;
    for(int z = 0; z < Frames; ++z){
        cout << f[z] << " ";
    }cout << endl;
    double hrate = (hit*100)/20, mrate = (miss*100)/20;
    cout << "Number of hits: " << hit << endl << "Hit Rate: " << hrate << "%" << endl;
    cout << "Number of misses: " << miss << endl << "Miss Rate: " << mrate << "%" << endl;

}

int main() {
    int Frames;
    cout << "Enter in the number of frames: ";
    cin >> Frames;
    cout << endl;
    int pages[20];
    for(int i = 0; i < 20; i++){
        pages[i] = 1 + (rand() % 5);
    }
    //int pages[20] = { 1, 2, 3, 4, 5, 1, 2, 3, 2, 1, 4, 3, 2, 1, 5, 4, 3, 1, 3, 2};
    cout<< "Randomly Generated String: ";
    for(int i = 0; i < 20; i++){
        cout << pages[i] << " ";
    }cout << endl;
    LRU_Replacement(pages, Frames);
    cout << endl;
    optimalReplacement(pages,Frames);
    return 0;
}
