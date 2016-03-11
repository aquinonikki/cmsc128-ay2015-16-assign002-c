/*
Nikki M. Aquino
CMSC 128 AB-3L
Programming Asssignment 002
*/

#include <stdio.h>
#include <string.h>
#define MAX 80


//function definition
int getHammingDistance(char *str1, char *str2);
int countSubstrPattern(char *original, char *pattern);
int isValidString(char *str, char *alphabet);
int getSkew(char *str, int n);
int getMaxSkewN(char *str, int n);
int getMinSkewN(char *str, int n);

//function 1
int getHammingDistance(char *str1, char *str2){
	int ans = 0;
	int i;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	if(len1 <= 0 || len2 <= 0){
		printf("Error! String length must not be less than or equal to 0!\n");
		return -1; //error found
	}else if(len1 != len2){
		printf("Error! Strings are not equal!\n");
		return -1; //error found
	}else{
		for(i=0; i<len1; i++){
			if(str1[i] != str2[i]){ //compare all the character in str1 and str2
				ans++; //count the different characters
			}
		}	
		return ans;
	}
}

//function 2
int countSubstrPattern(char *original, char *pattern){
	int ans = 0;
	int i, j;
	int len1 = strlen(original);
	int len2 = strlen(pattern);
	int min = 0;
	char a[len2]; //subset
	
	while(len1-min > 0){ 
		for(i=min, j= 0; i<(min+len2), j<len2; i++, j++){ //get the sub set
			a[j] = original[i];
		}
			
		if(strcmp(a,pattern) == 0){ //compare to the pattern
			ans++;
		}
			
		min = min+1; //move the min(start of subset)
	}
	return ans;
	
	
}

//function 3
int isValidString(char *str, char *alphabet){
	int ans;
	int len1 = strlen(str);
	int len2 = strlen(alphabet);
	int i, j;
	int same = 0;
	
	for(i=0; i<len1; i++){ //compare all str to the pattern
		for(j=0; j<len2; j++){
			if(str[i] == alphabet[j]){ //str has a match in pattern
				same = 1;
			}
		}
		if(same == 0){ //str has no match in pattern
			return 0; //false
		}
		same = 0; //reset
	}
	
	return 1; //true
}

//function 4
int getSkew(char *str, int n){
	int ans;
	int noOfG = 0;
	int noOfC = 0;
	int i;
	
	if(strlen(str) <= 0){
		printf("Error!\n"); //error message
		return -1; //error found
	}else if(strlen(str) < n){
		printf("Error!\n"); //error message
		return -1; //error found
	}else{	
		for(i=1; i<= n; i++){
			if(str[i-1] == 'G'){ //get the number of G from 1 to n
				noOfG++;
			}else if(str[i-1] == 'C'){ //get the number of C from 1 to n
				noOfC++;
			}
		}
		ans = noOfG - noOfC; // skew = #G - #C
		return ans;
	}
	
}

//function 5
int getMaxSkewN(char *str, int n){
	int ans;
	int anss;
	int i;
	
	/*
	Get all the skew from 1 to n, then get the max
	*/
	
	for(i=1; i<=n; i++){
		if(i == 1){
			ans = getSkew(str, i); //first skew
		}
		
		anss = getSkew(str, i);
		if(anss > ans){ //compare every skew to previous skew
			ans = anss;
		}
	}
	return ans; //max skew
}

//function 6
int getMinSkewN(char *str, int n){
	int ans;
	int anss;
	int i;
	
	/*
	Get all the skew from 1 to n, then get the min
	*/
	
	for(i=1; i<=n; i++){
		if(i == 1){
			ans = getSkew(str, i); //first skew
		}
		
		anss = getSkew(str, i);
		if(anss < ans){ //compare every skew to previous skew
			ans = anss;
		}
	}
	return ans; //min skew
}
