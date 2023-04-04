#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(vector<int> arr, int start, int end, int key){
    if (end <= start) return (key > arr[start]) ? (start + 1) : start; 
    int mid = (start + end) / 2;
    
    if (key == arr[mid]) return mid + 1; 
    if (key > arr[mid]) return binary_search(arr, mid + 1, end, key);
    
    return binary_search(arr, start, mid - 1, key);
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int len;
    
    for(int i=0; i<operations.size(); i++){
        len = answer.size();
        if(operations[i] == "D 1"){
            if(len) answer.pop_back();
            else continue;
        }
        else if(operations[i] == "D -1"){
           if(len) answer.erase(answer.begin());
           else continue;
        }
        else{
            int number = stoi(operations[i].substr(2));
            if(len){
               int index = binary_search(answer, 0, len-1, number);
               answer.insert(answer.begin() + index, number);
            }
            else{
                answer.push_back(number);
            }
            
        }
    }
    len = answer.size();
    if(len){
        return {answer[len-1], answer[0]};
    }
    else{
        return {0, 0};
    }
}