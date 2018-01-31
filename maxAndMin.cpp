#include <iostream>

using namespace std;

struct maxAndMin{
int max;
int min;

};

maxAndMin maxMin(int arr[], int low, int high);
int main(){


int arr[]{1,9,6,1,4,3,2,1, 9};
int low = 0;
int high = 8;

maxAndMin mnm = maxMin(arr, 0, 8);

cout << mnm.max << endl;
cout << mnm.min << endl;

return 0;
}

maxAndMin maxMin(int arr[] , int low, int high){
int min;
int max;

if(low == high){
max = min = arr[low];
maxAndMin result ={max, min};
return(result);
}
else if(low == (high-1)){
	if(arr[low] < arr[high]){
		max = arr[high];
		min = arr[low];
		maxAndMin result = {max, min};
		return result;
	}else{
		max = arr[low];
		min = arr[high];
		maxAndMin result = {max, min};	
		return result;
	}

}

else{

	int mid = (low+high)/2;

	maxAndMin result1 = maxMin(arr, low, mid);
	maxAndMin result2 = maxMin(arr, mid+1, high);
	maxAndMin resulted;
	if(result1.min < result2.min){
		 resulted.min = result1.min;
	}else{
		 resulted.min = result2.min;
	}if(result1.max > result2.max){
		resulted.max = result1.max;
	}else
		resulted.max = result2.max;
	return resulted;
}
}

