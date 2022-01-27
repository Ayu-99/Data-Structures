struct trie{
    trie* next[2];
    trie()
    {
        next[0]=NULL;
        next[1]=NULL;
    }
};
class TrieNode{
    private:
        trie* root;
    public:
        TrieNode()
        {
            root=new trie();
        }
    
    void insert(int num)
    {
        trie* curr=root;
        
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1;
            if(curr->next[bit]==NULL)
            {
                curr->next[bit]=new trie();
            }
            curr=curr->next[bit];
        }
    }
    
    int max_xor(int num)
    {
        trie* curr=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int bit=(num>>i)&1; //0
            
            if(curr->next[!bit]) //1
            {
                ans+=(1<<i);
                curr=curr->next[!bit];
            }
            else
            {
                curr=curr->next[bit];
            }
        }
        return ans;
    }   
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max_ans=0;
        int n=nums.size();
        
        TrieNode* t=new TrieNode();
        
        for(int i=0;i<n;i++)
        {
            t->insert(nums[i]);
            max_ans=max(max_ans,t->max_xor(nums[i]));
        }
        return max_ans;
    }
};
