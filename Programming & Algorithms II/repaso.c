#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define MAX_LETTERS 200

typedef struct _Sentence {
    char *sentence;
    int numChars;
} tSentence;

/***** Recursion *****/

// Fibonacci exercise
int fibonacci(int num){
    assert(num >= 0);
    
    if (num <= 1) {
        return num;
    } 
    return fibonacci(num - 1) + fibonacci(num - 2);
}

// Factorial exercise
int factorial(int num){
    if (num == 0) {
        return 1;
    }
    return num * factorial(num - 1);
}

// Palindrome exercise
// verify if a sentence is a palindrome
bool isPalindrome(tSentence sentence, int start, int end){
	 if (start >= end) {
        return true;
    } else {
        return (sentence.sentence[start] == sentence.sentence[end]) && 
				isPalindrome(sentence, start+1, end-1);
    }
}

// Calculate power of a number exercise
int power(int base, int exp){
    int temp;

    if (exp == 1) {
        return base;
    } else if (exp % 2 == 0) {
        temp = power(base, exp / 2);
        return temp * temp;
    } else {
        temp = power(base, (exp - 1) / 2);
        return temp * temp * base;
    }
}

// Find max number exercise
int getMax(int n1, int n2){
    return n1 > n2 ? n1 : n2;
}

int findMax(int nums[], int length){
    assert(length > 0);

    if (length == 1) {
        return nums[0];
    }
    int rest = findMax(nums, length - 1);
    return getMax(rest, nums[length-1]);
}

// Find max number by divide and conquer exercise
int findMaxDC(int nums[], int start, int end){
    assert(start <= end);
    if (start == end) {
        return nums[start];
    }
    int middle = (start + end) / 2;
    int max_left = findMaxDC(nums, start, middle);
    int max_right = findMaxDC(nums, middle+1, end);
    return getMax(max_left, max_right);
}

int mergeSort(int nums[], int length){
	
}


int main(int argc, char **argv){
	
	// Print Fibonacci example
	int num = 6;
    printf("Fibonacci of %d is %d \n", num, fibonacci(num));

	// Print Max example
    int nums[6] = {2, 8, 100, 1, 50, 30};
    int maxNum = findMax(nums, 6);
    printf("The maximum number is: %d \n", maxNum);

	// Print Factorial example
    printf("Factorial of %d is: %d \n", num, factorial(num));
	
	
	// Print Palindrome example
	tSentence sentence;
	int i = 0;
	bool isLetterString = true;
	
	// request string of max. 200 characters
    sentence.sentence = malloc(MAX_LETTERS*sizeof(char));
    printf("Enter a string with no blanks and only letters\n");
    scanf("%[^\n]", sentence.sentence);
    fflush(stdin);
	sentence.numChars = strlen(sentence.sentence);
	
	//printf("%d", isalpha(sentence.sentence[0]));
	
	// verify that all chars are letters
	while(i < sentence.numChars && isLetterString){
		isLetterString = (isalpha(sentence.sentence[i]) != 0) ? true : false;
		i++;
		if (!isLetterString){
			i = 0;
			printf("Sorry, the string is invalid. Please enter a string with no blanks and only letters\n");
			scanf("%[^\n]", sentence.sentence);
			fflush(stdin);
		}
	}
	
    if (isPalindrome(sentence, 0, sentence.numChars-1)){
        printf("It is a palindrome");
    } else {
        printf("It is not a palindrome");
    }
	
	free(sentence.sentence);
	
	// Print power example
	int base;
    int exp;

    scanf("%d", &base);
    scanf("%d", &exp);

    printf("%d\n", power(base, exp));
	
	
	return 0;
}
