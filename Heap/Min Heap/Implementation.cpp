//Min Priority Queue(Min Heap)
#include<bits/stdc++.h>
class PriorityQueue{
	vector<int> pq;
	public:
		bool isEmpty(){
			return pq.size()==0;
		}
		
		int getMin(){
			return pq[0];
		}
		
		int getSize(){
			return pq.size();
		}
		
		void insert(int element){
			pq.push_back(element);
			int childIndex=pq.size()-1;
			while(childIndex>0){
				int parentIndex=(childIndex-1)/2;
				if(pq[childIndex]<pq[parentIndex]){
					int temp;
					temp=pq[childIndex];
					pq[childIndex]=pq[parentIndex];
					pq[parentIndex]=temp;
				}
				else{
					break;
				}
				childIndex=parentIndex;
				
				
			}
		}
		
		 
    int removeMin() {
        // Complete this function
        int size=pq.size();
        int ans=pq[0];
        pq[0]=pq[size-1];
        pq.pop_back();
        int parentIndex=0;
        while((2*(parentIndex)+1) <size && (2*(parentIndex)+2)< size){
            int childIndex1=2*(parentIndex)+1;
            int childIndex2=2*(parentIndex)+2;
            int minIndex;
            
            if(pq[childIndex1]<pq[childIndex2]){
                minIndex=childIndex1;
            }else{
                minIndex=childIndex2;
            }
            
            if(pq[parentIndex]>pq[minIndex]){
                int temp=pq[minIndex];
                pq[minIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }else{
                break;
            }
            
            parentIndex=minIndex;
        
            
        }
        
        return ans;
        
    }
};
