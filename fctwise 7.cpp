#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int score(vector<int>& cardPoints,int k){
int n=cardPoints.size();
int total=0;
for(int i=0;i<n;i++){
total+=cardPoints[i];
}
int windowSize=n-k;
int minPoints=INT_MAX;
int WindowPoints=0;
for(int i=0;i<windowSize;i++){
 WindowPoints+=cardPoints[i];
}
minPoints=min(minPoints,WindowPoints);

for(int i=windowSize;i<n;i++){
WindowPoints=WindowPoints-cardPoints[i-windowSize]+cardPoints[i];
minPoints=min(minPoints,WindowPoints);
}

return total-minPoints;
}
int main(){
vector<int>cardPoints={1,2,3,4,5,6,1};

int k=3;

int res=score(cardPoints,k);
cout<<"Maximum score:"<<res<<endl;
return 0;
}