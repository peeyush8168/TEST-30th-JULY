/*Problem statement
You are given a string 'STR'. The string contains [a-z] [A-Z] [0-9] [special characters]. You have to find the reverse of the string.
For example:
 If the given string is: STR = "abcde". You have to print the string "edcba".
*/

#include <bits/stdc++.h>
string reverseString(string str)
{
	int n=str.size()-1;
        for(int s=0;s<n;s++){
          char temp=str[s];
          str[s]=str[n];
          str[n]=temp;
          n--;
        }
        return str;
}
