#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>

using namespace std;

// 421	Maximum XOR of Two Numbers in an Array
class P421 {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            set<int> s;
            for (int num : nums) {
                s.insert(num & mask);
            }
            int t = res | (1 << i);
            for (int prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
  
  void test() {
    vector<int> nums{10,23,20,18,28};
    cout << "Test 421" << endl;
    cout << "Ans: " << findMaximumXOR(nums) << endl;
  }
};

// 520 Detect Capital
class P520 {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        for(int i = 0; i < word.size(); i++) {
            if(word[i] <= 'Z') count++;
        }
        
        return count == 0 || count == word.size() || (count == 1 && word[0] < 'Z');
    }
    
  void test() {
    string str("ZheNg");
    cout << "Test 520" << endl;
    cout << "Ans: " << detectCapitalUse(str) << endl;
  }

private:
    int isCapital(char c) {
        return (c >= 'A' && c <= 'Z') ? 1 : 0;
    }
};

// 246. Strobogrammatic Number
class P246 {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> numMap {
            {'0', '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'},
        };

        for (int i = 0; i <= num.size() / 2; i++) {

            if (num[i] != numMap[num[num.size() - 1 - i]]) return false;
        }
        
        return true;
    }

  void test() {
    string str("1");
    cout << "Test 246" << endl;
    cout << "Ans: " << isStrobogrammatic(str) << endl;

  }
};

// 734. Sentence Similarity
class P734 {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        
        unordered_map<string, unordered_set<string>> wordMap;
        
        for (auto pair : pairs) {
            if (wordMap.count(pair.first)) {
                wordMap[pair.first].insert(pair.second);
            }
            else {
                //wordMap[pair.first];
                wordMap[pair.first].insert(pair.second);
            }
        }
    }
    
    void test() {
      unordered_map<string, unordered_set<string>> wordMap;
      wordMap["a"].insert("b");
      wordMap["a"].insert("b");
      
      cout << wordMap.size() << endl;
    }
};

// 418. Sentence Screen Fitting
class P418_me {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int count = 0, row = 1, cap = cols, n = sentence.size();
        
        int i = 0;
        int t = 0;
        while (row <= rows) {
            i = 0;
            while (i < n) {
                cout << "i: " << i << endl;
                cout << "row: " << row << endl;
                cout << "cap: " << cap << endl;
                cout << "count: " << count << endl;
                if (sentence[i].size() > cols) return 0;
                
                if (sentence[i].size() == cap) {
                    i++;
                    row++;
                    cap = cols;
                    if (i == n) {
                      count++;
                    }
                    if (row > rows) return count;
                }
                else if (sentence[i].size() > cap) {
                    row++;
                    cap = cols;
                    if (row > rows) return count;
                }
                else {
                    cap = cap - sentence[i].size() - 1;
                    i++;
                    if (i == n) {
                      count++;
                    }
                }
            }
        }
        
        cout << "Res:" << count << endl;
        return count;
    }
    
    void test() {
      //vector<string> sentence {"a", "b", "c"};
      //wordsTyping(sentence, 3, 1);
      
      vector<string> sentence {"hello", "world"};
      wordsTyping(sentence, 2, 8);
      
      //cout << "Res: " << wordsTyping(sentence, 2, 8) << endl;
    }
};

class P418 {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string all = "";
        for (string word : sentence) all += (word + " ");
        int start = 0, len = all.size();
        for (int i = 0; i < rows; ++i) {
            start += cols;
            if (all[start % len] == ' ') {
                ++start;
            } else {
                while (start > 0 && all[(start - 1) % len] != ' ') {
                    --start;
                }
            }
            cout << "Start: " << start << endl;
        }
        return start / len;
    }
    
    void test() {
      //vector<string> sentence {"a", "b", "c"};
      //wordsTyping(sentence, 3, 1);
      
      vector<string> sentence {"hello", "world"};
      //wordsTyping(sentence, 2, 8);
      
      cout << wordsTyping(sentence, 2, 8) << endl;
    }
};

// 394. Decode String
class P394 {
public:
    string decodeString(string s) {
        string str;
        string res;
        stack<char> stk;
        
        for (auto c : s) {
            if (c != ']') {
                stk.push(c);
            }
            else {
                while(!stk.empty() && !isdigit(stk.top()) && stk.top() != '[') {
                    str = stk.top() + str;
                    stk.pop();
                }
                stk.pop();
                string count;
                while(!stk.empty() && isdigit(stk.top())) {
                    count = stk.top() + count;
                    stk.pop();
                }
                cout << count << endl;
                string temp(str);
                for (int i = 1; i < stoi(count); i++) {
                    str += temp;
                }
                if (stk.empty()) {
                  res += str;
                  str = "";
                }
            }
        }     
        while (!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
    
    void test() {
      string s("2[2[b]]");
      cout << decodeString(s) << endl;
    }
};

int main() {
  P394 p394;
  p394.test();
}
