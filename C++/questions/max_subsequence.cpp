#include <iostream>
#include <string>
#include <utility>
#include <array>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

void print_array(const int* arr, int len) {
    cout << "array: ";
    for( int i=0; i < len; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

class Solution{
public:
    pair<pair<int, int>, int>
    find_max_subsequence(const int *a, int len){
        pair<pair<int, int>, int> max_subsequence;
        int i=0, last_positive=0, start=0, end=0, sum=0, psum=0, max_sum=0;
        while (i < len){
            if (a[i] > 0) last_positive = i;
            sum += a[i];
            if (sum > psum){
                psum = sum;
            }
            if (sum <= 0) {
                end = last_positive;
                if (psum > max_sum){
                    max_sum = psum;
                    max_subsequence = make_pair(make_pair(start, end), psum);
                }
                while(a[i] <= 0){
                    i++;
                }
                start = i;
                end = i;
                psum = sum = 0;
            } else {
                i++;
            }
        }
        if (psum > max_sum){
            max_subsequence = make_pair(make_pair(start, last_positive), psum);
        }
        return max_subsequence;
    }
};

class Solution2{
    public:
    unordered_map<int, int> sum_cache;

    int max_subsequence(const int* A, int max_index) {
        if (! sum_cache[max_index]) {
            if (max_index <= 0) {
                sum_cache[max_index] = A[max_index];
            } else {
                sum_cache[max_index] = ((max_subsequence(A, max_index -1)) > 0 ? max_subsequence(A, max_index -1): 0) + A[max_index];
            }
            cout << "max_subseq[" << max_index << "] : " << sum_cache[max_index]<< endl;
        }
        return sum_cache[max_index];
    }

    int
    find_max_subsequence(const int *a, int len){
        print_array(a, len);
        int max_sum = 0;
        for (int i= 0; i < len; i++){
            int sum = max_subsequence(a, i);
            if (sum > max_sum){
                max_sum = sum;
            }
        }
        return max_sum;
    }
};

class Solution3{
    public:
        int max_subsequence(vector<int> nums) {
            int max_sum = nums.front();
            int tmp_sum = max_sum;
            for (size_t i = 0; i < nums.size(); i++) {
                int num = nums[i];
                tmp_sum += num;
                tmp_sum = max(tmp_sum, num);
                max_sum = max(tmp_sum, max_sum); 
            }
            return max_sum;
        }
};

int main(){
    Solution s;
    int arr[]{2, 3, -4, -1, 3, 3, -5, 10, 1};
    print_array(arr, sizeof(arr)/sizeof(int)) ;
    auto start = std::chrono::high_resolution_clock::now();
    auto p = s.find_max_subsequence(arr, sizeof(arr)/sizeof(int)) ;
    auto end = std::chrono::high_resolution_clock::now();
    cout << "range: " << p.first.first << " : " << p.first.second << " = " << p.second << endl;
    double timeTakenInSeconds = (end - start).count() * ((double) chrono::high_resolution_clock::period::num / chrono::high_resolution_clock::period::den);
    cout << "Time taken: " << timeTakenInSeconds << endl;
    Solution2 s2;
    start = std::chrono::high_resolution_clock::now();
    cout << "max sum: " << s2.find_max_subsequence(arr, sizeof(arr)/sizeof(int)) << endl;
    end = std::chrono::high_resolution_clock::now();
    timeTakenInSeconds = (end - start).count() * ((double) chrono::high_resolution_clock::period::num / chrono::high_resolution_clock::period::den);
    cout << "Time taken: " << timeTakenInSeconds << endl;

    Solution3 s3;
    start = std::chrono::high_resolution_clock::now();
    vector<int> v;
    for (int i =0; i < (sizeof(arr)/sizeof(int)); i++){
        v.push_back(arr[i]);
    }
    cout << "max sum: " << s3.max_subsequence(v);
    end = std::chrono::high_resolution_clock::now();
    timeTakenInSeconds = (end - start).count() * ((double) chrono::high_resolution_clock::period::num / chrono::high_resolution_clock::period::den);
    cout << "Time taken: " << timeTakenInSeconds << endl;

    return 0;
}

