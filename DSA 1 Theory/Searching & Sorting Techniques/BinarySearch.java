// https://www.geeksforgeeks.org/dsa/find-position-element-sorted-array-infinite-numbers/

class BinarySearch{
	public static void main(String[] argos){
		int[] arr = {3, 5, 7, 9, 10, 90, 100, 130, 140, 160, 170};
		int k = 10;

		int low = 0;
		int high = 1;
		if(arr[high] < k){
			int newLow = high + 1;
			high = high + (high - low + 1)*2;
			low = newLow;
		}
		int ans = binarySearch(low, high, arr, k);
		System.out.println(ans);
	}

	static int binarySearch(int low, int high, int[] arr, int k){
		while(low <= high){
			int mid = low + (high - low)/2;
			if(k < arr[mid]){
				high = mid - 1;
			} else if(k > arr[mid]){
				low = mid + 1;
			} else {
				return mid;
			}
		}
		return -1;
	}
}
