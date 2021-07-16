result=[]
        nums.sort()
        
        for i in range(len(nums)-3):
            if i>0 and nums[i]==nums[i-1]:
                continue
                
            for j in range(i+1,len(nums)-2):
                
                if j>i+1 and nums[j] == nums[j-1]:
                    continue
                sum=target-nums[i]-nums[j]
                
                l=j+1
                r=len(nums)-1
                while l<r:
                    if nums[l]+nums[r]==sum:
                        result.append([nums[i],nums[j],nums[l],nums[r]])
                        while l<r and nums[l]==nums[l+1]:
                            l+=1
                        while l<r and nums[r]==nums[r-1]:
                            r-=1
                        l+=1
                        r-=1
                    elif nums[l]+nums[r]<sum:
                        l+=1
                    else:
                        r-=1
                while j < len(nums)-3 and nums[j] == nums[j+1]:
                    j+=1
                j+=1       
        return result
