- 从右上角开始查，右上角小于target，右上角是当前行的最后一行，根据每行递增，也即是当前行最大值小于target，则当前行不可能；若右上角大于target，右上角是当前列的第一列，根据每列递增，也即是当前列最小值大于target，则当前列不可能。

```c++
bool Find(int target, vector<vector<int> > array) {
    	if(array.empty())
    		return false;
    	int rows = array.size();
    	int cols = array[0].size();
    	int i=0,j =cols-1 ;
    	bool find = false;
    	while(i<rows&&j>=0){
    		if(array[i][j]>target){
    			j--;
    		}else if(array[i][j]<target){
    			i++;
    		}else{
    			find = true;
    			break;
    		}
    	}
    	return find;
```

- 从尾到头，原地替换。`length`为最多可容纳的字符个数（不带`\0`）；注意数组中不能有`a[2]=a[2]`形式赋值

  ```c++
  void replaceSpace(char *str,int length) {//char str[] is also ok
              if(str==NULL||length==0)
              	return ;
              int strLen =0;
              int blank =0;
              int i =0;
              while(str[i]!='\0'){
              	strLen++;
              	char temp = str[i];
              	if(str[i]==' ')
              		blank++;
              	i++;
              }
              int newLen = strLen + 2*blank;
              if(newLen>length)
              	return;
              while(strLen>=0&&newLen>strLen){//second condition must
              	if(str[strLen]==' '){
              		str[newLen--]='0';
              		str[newLen--]='2';
              		str[newLen--]='%';
  
  
              	}else
              		str[newLen--]=str[strLen];
                  
              	strLen--;
              }
              return ;
  
      	}
  ```
  
  

  ```c++
  vector<int> printListFromTailToHead(ListNode* head) {
      	vector<int> res;
      	if(head==NULL)
      		return res;
      	if(head->next==NULL){//not necessary
      		res.push_back(head->val);
      	    return res;
  
          }else{
          res = printListFromTailToHead(head->next);
      }
  
  		res.push_back(head->val);
  		return res;
      }
  ```


- 重建二叉树。先找到根节点（前序序列第一个）在中序序列中的下标。以此下标求前序序列中左右子树的范围（中序的左右子树范围分别为下标的左右部分）。递归对左右子树的前中序列用此过程。

```c++
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    	if(pre.empty()||(pre.size()!=vin.size()))
    		return NULL;//?
    	if(pre.size()==1 && pre[0]==vin[0])
    		return  new TreeNode(pre[0]);
    	TreeNode* root = new TreeNode(pre[0]);
    	auto ind = find(vin.begin(),vin.end(),pre[0]);//algorithm
    	int pos = distance(vin.begin(),ind);
    	vector<int> l_pre,l_vin,r_pre,r_vin;
    	l_pre.insert(l_pre.begin(),pre.begin()+1,pre.begin()+1+pos);//pre[1:1+ind]
    	l_vin.insert(l_vin.begin(),vin.begin(),vin.begin()+pos);//tin[0:ind])

    	root->left = reConstructBinaryTree(l_pre,l_vin);
    	r_pre.insert(r_pre.begin(),pre.begin()+1+pos,pre.end());
    	r_vin.insert(r_vin.begin(),vin.begin()+pos+1,vin.end());
    	root->right = reConstructBinaryTree(r_pre,r_vin);
    	return root;
```

后面复制前中序左右子序列的过程用Python切片其实很简单：

```python
        ind = tin.index(pre[0]) #-1?
        root.left = self.reConstructBinaryTree(pre[1:1+ind],tin[0:ind]) #ind=len
        root.right = self.reConstructBinaryTree(pre[1+ind:],tin[ind+1:])
```

