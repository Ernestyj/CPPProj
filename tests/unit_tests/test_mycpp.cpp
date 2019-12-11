#include "gtest/gtest.h"
#include <iostream>

using namespace std;


struct QuickSort{
    void quickSort(vector<int>& nums){
        quickSort(nums, 0, nums.size() - 1);
    }
    void quickSort(vector<int>& arr, int left, int right) {
        int l = left, r = right, pivot = arr[(left+right)/2];
        while (l<=r) {
            while (arr[l]<pivot) l++;
            while (arr[r]>pivot) r--;
            if (l<=r) {
                swap(arr[l], arr[r]);
                l++; r--;
            }
        };// 最后退出的情况应该是右指针在左指针左边一格
        if (left <= r) quickSort(arr, left, r);  //TODO 注意边界
        if (l <= right) quickSort(arr, l, right);
    }
};

struct ReverseWords{
    static string reverseWords(string s) {
        stringstream ss(s);
        string token, res;
        while(getline(ss, token, ' ')){
            cout<<token<<"|";
            if(token!="") res = token+" "+res;
        }
        cout<<res.size();
        res.pop_back();
        return res;
    }
};


namespace {
    // Normal Test case
//    TEST(Example, E) {
//      EXPECT_EQ(1, 1);
//      cout<<"Test finished."<<endl;
//    }

//    TEST(QuickSort, 1) {
//        QuickSort ins;
//        vector<int> nums = {5,4,3,2,1,0,100};
//        ins.quickSort(nums);
//        for(auto a: nums){
//            cout<<a<<" ";
//        }
//        cout<<endl;
//    }

    TEST(ReverseWords, 2){
        ReverseWords::reverseWords("   ");
    }

    // The fixture for testing class Foo.
    class MyCppTest : public ::testing::Test {
    protected:
        // You can remove any or all of the following functions if its body is empty.

        MyCppTest() {
          // You can do set-up work for each test here.
        }

        virtual ~MyCppTest() {
          // You can do clean-up work that doesn't throw exceptions here.
        }

        // If the constructor and destructor are not enough for setting up and cleaning up each test, you can define the following methods:
        virtual void SetUp() {
          // Code here will be called immediately after the constructor (right before each test).
        }

        virtual void TearDown() {
          // Code here will be called immediately after each test (right before the destructor).
        }

        // Objects declared here can be used by all tests in the test case for Foo.
    };

//    TEST_F(MyCppTest, DoesXyz) {
//      // Exercises the Xyz feature of Foo.
//    }
}

//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();
//}
