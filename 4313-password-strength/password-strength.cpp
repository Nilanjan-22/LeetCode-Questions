class Solution {
public:
    int passwordStrength(string password) {
        int strength=0;
        unordered_set<char>alreadyFound;
        for(int i=0;i<password.size();i++){
            if(alreadyFound.find(password[i])!=alreadyFound.end())continue;
            if(password[i]-'a'>=0 && password[i]-'a'<26)strength++;
            else if(password[i]-'A'>=0 && password[i]-'A'<26)strength+=2;
            else if(password[i]-'0'>=0 && password[i]-'0'<10)strength+=3;
            else strength+=5;
            alreadyFound.insert(password[i]);
        }
        return strength;
    }
};