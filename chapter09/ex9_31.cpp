/*
The program on page 354 to remove even-valued
elements and duplicate odd ones will not work on a list or forward_list.
Why? Revise the program so that it works on these types as well.
*/
#include <list>
#include <iostream>

using namespace std;

int main(){
    list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin(); 
    while (iter != vi.end()) {
        if (*iter % 2) {
            int v=*iter;
            iter++;
            //insert v before iter and return the iterator we added.
            iter =vi.insert(iter,v);
            iter ++; 
        } else
            iter = vi.erase(iter); 
        }
    //testing
    for(int i:vi){
        cout<<i<<" ";
    }
    return 0;
}