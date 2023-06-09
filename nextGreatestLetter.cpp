class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int a[26] =  { } ;

        for(int i = 0 ; i<letters.size();i++){
            a[letters[i]-'a'] = 1;
        }
        for(int i = target - 'a' ; i<25;i++){
            if(a[i+1]==1){
                return i+1+'a';
            }
        }
        return letters[0];
    }
};
