#include<iostream> 
#include<vector> 
#include<queue> 
#include<unordered_map> 

using namespace std; 

class Solution{
public: 
     vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp; 
       for(int num:nums){
         mp[num]++; 
       }
       priority_queue<pair<int,int> , vector<pair<int,int>> , greater<>> minHeap; 
       for(auto [num, count]:mp){
         minHeap.emplace(count,num); 
         if(minHeap.size()>k){
           minHeap.pop(); 
         }
       }
       vector<int> res; 
       while(!minHeap.empty()){
         res.push_back(minHeap.top().second); 
         minHeap.pop(); 
       }
       return res; 
     }
};
int main(){
  vector<int> nums={1,1,1,2,2,3};
  int k=2; 
  Solution sol; 
  vector<int> res= sol.topKFrequent(nums,k); 
  cout << "The top " << k << " element [" ; 
  for(int n:res){
    cout << n << " , " ; 
  }
  cout << " ]" <<endl; 
  return 0; 
}
