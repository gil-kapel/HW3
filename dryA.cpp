#include <iostream>
#include <vector>

// std::vector<T> slice(std::vector<T> vec, int start, int step, int stop);
template <class T>
std::vector<T> slice(std::vector<T> vec, int start, int step, int stop){
    if((start < 0) || start >= len(vec)){
        throw BadInput;
    }
    if ((stop < 0) || start >= len(vec)){
         throw BadInput;
    }
    if(step <= 0){
        throw BadInput;
    }
    if(start >= stop)
    {
    return vector<string>();// empty vec?
    }
    // vector = new vector[(stop - start) / step];
    new_start = vec.begin() + start;
    new_end = vec.begin + stop + 1; // why do we need +1
    //copy function in vector
    vector<string> vec2;
    for (int i = 0; i < vec.zize();){
        vec2.push_back(vec[i]);
        i += step;
    }
    // remove steps
    return vec2;


}
