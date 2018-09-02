
//https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
#include<iostream>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
		int *A=new int[length]();//动态数组初始化为0
		
		for(int i=0;i<length;i++)
			{
				A[numbers[i]]++;
				if(A[numbers[i]]>=2){
				* duplication=numbers[i];
				 return true;
				}
		}
		delete []A;
	  return false;
	}
};

class Solution2 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
     if(length<=0||numbers==NULL)
		 if(length<=0||numbers==nullptr)
            return false;
        //判断每一个元素是否非法
        for(int i=0;i<length;++i)
        {
            if(numbers[i]<=0||numbers[i]>length-1)
                return false;
        }
        for(int i=0;i<length;++i)
        {
            while(numbers[i]!=i)
            {
                if(numbers[i]==numbers[numbers[i]])
                {
                    *duplication = numbers[i];
                    return true;
                }
                //不等时，交换numbers[i]和numbers[numbers[i]]
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
        }
        return false;
         
    }
};

	int main(){
	
	int n;
	cin>>n;
	int a[1000]={0};
	for(int i=0;i<n;i++)
		cin>>a[i];
	int *p=new int(0);//赋初值0

	class Solution solution;  
	solution.duplicate(a,n,p);
	cout<<*p<<endl;


	class Solution solution2;  
	solution2.duplicate(a,n,p);
	cout<<*p<<endl;

	system("pause");
 }