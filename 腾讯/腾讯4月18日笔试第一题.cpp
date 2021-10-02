vector<int> nums;
        ListNode* head = S;
        int i = 0;
        while(head != NULL){
            nums[i++] = S->val;
            head = S->next;
        }
        
        vector<vector<int>> dic;
        for(int i = 0; i < nums.size() - 1; i++){
            dic[i] = sort(nums);
        }
        
        int minVal = INT_MAX;
        int index = -1;
        for(int i = 0; i < nums.size() - 1; i++){
            if(minVal > dic[i][0]) {
                minVal = dic[i][0];
                index = i;
        }
        }
        
        ListNode* ans = new ListNode(dic[index][0]);
        ListNode* p =head;
        for(int i = 1; i <= nums.size() - 1; i++){
            ans->val = dic[index][i];
            p = ans->next; 
        }
        return ans;
    }
    
    vector<int> sort(vector<int> nums){
        int len = nums.size() - 1;
        int temp = nums[len];
        for(int i = len; i > 0; i--){
            nums[i] = nums[i - 1];            
        }
        nums[0] = temp;
        return nums;
    }